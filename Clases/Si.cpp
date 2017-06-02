#include "Si.h"

Si::Si()
{
    //ctor
}

Si::~Si()
{
    //dtor
}

bool Si::ejecutarSi(map<string,Token>& mapa,map<string,Variable>& tV,vector<Token>& Tokens,int& voy)
{
    int aux = voy+1;
    vector<int> numTok;
    pair<bool,double> expR;
    pair<bool,double> condicion;
    voy++;
    condicion = exp.Evaluar(mapa,tV,Tokens,voy);
    voy++;
    if(Tokens[voy].Nombre=="{")
    {
        voy++;
        while (voy<Tokens.size() && Tokens[voy].Nombre!="}")
        {
            numTok.push_back(voy);
            voy++;
        }
        if (voy>=Tokens.size()) return false;
    }
    voy++;
    while (condicion.first==true)
    {
        //procesar
        int aux2=aux;
        condicion=exp.Evaluar(mapa,tV,Tokens,aux2);
    }
    if (condicion.first==true)
    {
        //Procesar
    }
    return true;
}
