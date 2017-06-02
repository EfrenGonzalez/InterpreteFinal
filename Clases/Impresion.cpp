#include "Impresion.h"
#include "Expresion.h"
#include "Variable.h"
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

void Impresion::ejecutar()
{

}

bool Impresion::imprimir(map<string,Token>& mapa,map<string,Variable>& tV,vector<Token>& Tokens,int& voy)
{
    if (tV[Tokens[voy+1].Nombre].Tipo==4 && Tokens[voy+2].Nombre==";")
    {
        cout<<tV[Tokens[voy+1].Nombre].ValorStr<<endl;
        voy+=3;
        return true;
    }
    if (Tokens[voy+1].Valor==34 && Tokens[voy+2].Nombre==";")
    {
        cout<<Tokens[voy+1].Nombre<<endl;
        voy+=3;
        return true;
    }
    voy+=1;
    pair<bool,double> expR = exp.Evaluar(mapa,tV,Tokens,voy);
    if (expR.first==false) return false;
    cout<<expR.second<<endl;
    voy++;
    return true;
}
