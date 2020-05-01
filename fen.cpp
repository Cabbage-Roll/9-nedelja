#include <iostream>
#include "dinstring.hpp"

using namespace std;

using namespace DinString;

class Abs{
public:
    int getTemperaturu()const;
    void setTemperaturu(int);
};

class Grejac: public Abs{
private:
    int temperatura;

public:
    Grejac(){
        temperatura=0;
    }

    Grejac(int a){
        if(a<0){
            temperatura=0;
        }else if(a>100){
            temperatura=100;
        }else{
            temperatura=a;
        }
    }

    Grejac(const Grejac &p){
        temperatura=p.temperatura;
    }

    int getTemperaturu()const{
        return temperatura;
    }

    void setTemperaturu(int a){
        if(a<0 && 100<a){
            temperatura=a;
        }
    }
};

enum Modovi{HLADNO,TOPLO};

class Fen{
private:
    DinString marka;
    Modovi mod;
    Grejac grejac;

public:
    Fen(DinString a, Modovi b){
        marka=a;
        mod=b;
        grejac.setTemperaturu(0);
        if(mod==TOPLO){
            grejac.setTemperaturu(1);
        }
    }

    Fen(const Fen &p): grejac(p.grejac){
        marka=p.marka;
        mod=p.mod;
    }

    DinString getMarka()const{
        return marka;
    }

    Modovi getMod()const{
        return mod;
    }

    Grejac getGrejac()const{
        return grejac;
    }

    void setMod(Modovi a){
        if(mod==TOPLO && a==HLADNO){
            grejac.setTemperaturu(0);
        }else if(mod==HLADNO && a==TOPLO){
            grejac.setTemperaturu(1);
        }
    }

    void setTemperaturu(int a){
        if(0<a && mod==TOPLO){
            grejac.setTemperaturu(a);
        }
    }

    int getTemperaturu()const{
        return grejac.getTemperaturu();
    };
};

int main()
{
    ///spamuje undefined reference ne znam kako da popravim
    Fen abc("Beko",TOPLO);
    Fen def(abc);

    cout<<abc.getTemperaturu()<<endl;
    cout<<def.getTemperaturu()<<endl;

    abc.setMod(HLADNO);
    cout<<abc.getMod()<<endl;
    cout<<def.getMod()<<endl;

    cout<<def.getMarka()<<endl;

    def.setTemperaturu(40);
    cout<<def.getTemperaturu()<<endl;

    return 0;
}
