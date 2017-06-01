#include "Declaracion.h"
#include <bits/stdc++.h>

Declaracion::Declaracion()
{
    //ctor
}

Declaracion::~Declaracion()
{
    //dtor
}

void Declaracion::imprimir()
{

}

bool Declaracion::evaluar(map<string,Token>& mapa,map<string,pair<int,string> >& tV,vector<Token>& Tokens,int& voy)
{
    Tokens[voy]=tipo;
    Tokens[voy+1]=variable;
    if (Tokens[voy+2].Nombre==";")
    {
        if (variable.Valor==1)
        {
            it=tV.find(variable.Nombre);
            if (it!=tV.end()) return false;
            tV[variable.Nombre]=make_pair(variable.Valor,"");
            voy+=3;
            return true;
        }
        else return false;
    }
    else return false;
}
