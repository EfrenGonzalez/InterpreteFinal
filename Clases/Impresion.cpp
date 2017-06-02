#include "Impresion.h"
#include "Expresion.h"
#include <bits/stdc++.h>

using namespace std;
Impresion::Impresion()
{
    //ctor
}

Impresion::~Impresion()
{
    //dtor
}

void Impresion::ejecutar() {

}

void Impresion::imprimir(map<string,Token>& mapa,map<string,Variable>& tV,vector<Token>& Tokens,int& voy){
    pair<bool,double> valor = exp.Evaluar(mapa,tV,Tokens,voy);
    it = tV.find(variable.Nombre);
    if (it != tV.end())
    {
        if (Tokens[voy]="impresion"  && Tokens[voy+2]=";")
        {
            it=tV.find(variable.Nombre);
            if (it!=tV.end()) { cout << "Error en la Impresion" << endl; break; }
            if (tipo.Valor==20) cout << variable.Nombre << " " << valor.second;
            else if (tipo.Valor==21) cout << variable.Nombre << " " << valor.second;
            else if (tipo.Valor==22) cout << variable.Nombre << " " << valor.second;
            else if (tipo.Valor==23) cout << variable.Nombre << " " << valor.second;
            voy+=3;
        }
    }else{
        cout << "Error la variable no se encuentra" << endl;
    }
}
