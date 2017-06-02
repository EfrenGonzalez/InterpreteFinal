#include "Si.h"

Si::Si()
{
    //ctor
}

Si::~Si()
{
    //dtor
}

void Si::ejecutarSi(map<string,Token>& mapa,map<string,Variable>& tV,vector<Token>& Tokens,int& voy)
{
    vector<int> numTok;
    pair<bool,double> expR;
    if(tV[Tokens[voy].Nombre].Tipo==41 && Tokens[voy+2].Nombre==";" && Tokens[voy+3].Nombre == "{"){
        while(expR.first!=false){
            if(Tokens[voy].Nombre!="}") {
                numTok.push_back(tV[Tokens[voy].Nombre].Tipo);
                expR = exp.Evaluar(mapa,tV,Tokens,voy);
                voy++;
            }else voy = voy+numTok.size();
        }
    }
}
