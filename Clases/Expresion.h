#ifndef EXPRESION_H
#define EXPRESION_H
#include <bits/stdc++.h>
#include "Token.h"
#include "Instruccion.h"

class Expresion : public Instruccion
{
    public:
        Expresion();
        virtual ~Expresion();
        vector<Token> tE;
        pair<bool,double> Evaluar(map<string,Token>&,map<string,pair<int,string> >&,vector<Token>&,int&);
    protected:
    private:
};

#endif // EXPRESION_H
