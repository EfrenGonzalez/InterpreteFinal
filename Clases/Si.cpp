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
    condicion = exp.Evaluar(mapa,tV,Tokens,aux);
    if(condicion.first!=false) {
        if(tV[Tokens[voy].Nombre].Tipo==41 && Tokens[voy+2].Nombre==";" && Tokens[voy+3].Nombre == "{") {
            while(expR.first!=false){
                if(Tokens[voy].Nombre!="}") {
                    numTok.push_back(tV[Tokens[voy].Nombre].Tipo);
                    expR = exp.Evaluar(mapa,tV,Tokens,voy);
                    voy++;
                }else voy = voy+numTok.size();
            }
            return true;
        }
        else{
            cout << "Error con la condición del Si" << endl;
            return false;
        }
    }
    else    return false;
}
