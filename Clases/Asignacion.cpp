#include "Asignacion.h"
#include "iostream"
#include <bits/stdc++.h>

using namespace std;
Asignacion::Asignacion()
{
    //ctor
}

Asignacion::~Asignacion()
{
    //dtor
}

void Asignacion::asignar(pair<bool,double>& inst,map<string,pair<int,string> >& tV,vector<Token>& Tokens,int& voy)
{
    it=tV.find(variable.Nombre);
    bool checar = true;
    if(checar){
        if(inst.first==false){
            checar = false;
            cout << "Error" << endl;
        }
        else{
            if (tV[variable.Nombre].first==30) {
                tV[variable.Nombre].second=static_cast<int>(inst.second);
            }
            else if(tV[variable.Nombre].first==31){ //float
                tV[variable.Nombre].second=static_cast<float>(inst.second);
            }
            else if(tV[variable.Nombre].first==32){ //true
                tV[variable.Nombre].second=static_cast<bool>(inst.second);
            }
            else if(tV[variable.Nombre].first==33){ //false
                tV[variable.Nombre].second=static_cast<bool>(inst.second);
            }
            else{
                cout << "Error, formato inválido" << endl;
                checar = false;
            }
        }
        cout << "Error" << endl;
        checar = false;
    }
}

void Asignacion::ejecutar(){

}
