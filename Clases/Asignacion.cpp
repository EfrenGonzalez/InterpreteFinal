#include "Asignacion.h"
#include "iostream"
#include <bits/stdc++.h>
#include "Variable.h"
#include "Expresion.h"

using namespace std;
Asignacion::Asignacion()
{
    //ctor
}

Asignacion::~Asignacion()
{
    //dtor
}

bool Asignacion::asignar(map<string,Token>& mapa,map<string,Variable>& tV,vector<Token>& Tokens,int& voy)
{
    int aux=voy;
    it=tV.find(Tokens[voy].Nombre);
    if (it==tV.end()) return false;
    if (Tokens[voy+1].Nombre!="=") return false;
    //Caso de string
    if (tV[Tokens[voy].Nombre].Tipo==4 && Tokens[voy+2].Valor==34 && Tokens[voy+3].Nombre==";")
    {
        tV[Tokens[voy].Nombre].ValorStr=Tokens[voy+2].Nombre;
        voy+=4;
        return true;
    }
    //Caso de expresion
    voy+=2;
    Expresion exp = Expresion();
    pair<bool,double> expR = exp.Evaluar(mapa,tV,Tokens,voy);
    if (expR.first==false) return false;
    else
    {
        if (tV[Tokens[aux].Nombre].Tipo==1)
        {
            if (expR.second>0.000001 || expR.second<-0.000001) tV[Tokens[aux].Nombre].ValorNum=1.0;
            else tV[Tokens[aux].Nombre].ValorNum=0.0;
        }
        else if (tV[Tokens[aux].Nombre].Tipo==2) tV[Tokens[aux].Nombre].ValorNum=expR.second;
        else if (tV[Tokens[aux].Nombre].Tipo==3) tV[Tokens[aux].Nombre].ValorNum=round(expR.second);
    }
    return true;
}

void Asignacion::ejecutar(){

}
