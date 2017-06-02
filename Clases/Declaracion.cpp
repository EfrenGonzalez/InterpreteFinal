#include "Variable.h"
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

void Declaracion::ejecutar()
{

}

bool Declaracion::evaluar(map<string,Token>& mapa,map<string,Variable>& tV,vector<Token>& Tokens,int& voy)
{
    Tokens[voy]=tipo;
    Tokens[voy+1]=variable;
    if (Tokens[voy+2].Nombre==";")
    {
        if (variable.Valor==1)
        {
            it=tV.find(variable.Nombre);
            if (it!=tV.end()) return false;
            if (tipo.Valor==20) tV[variable.Nombre]=Variable(1,0.0,"");
            else if (tipo.Valor==21) tV[variable.Nombre]=Variable(2,0.0,"");
            else if (tipo.Valor==22) tV[variable.Nombre]=Variable(3,0.0,"");
            else if (tipo.Valor==23) tV[variable.Nombre]=Variable(4,0.0,"");
            voy+=3;
            return true;
        }
        else return false;
    }
    else return false;
}
