#ifndef EXPRESION_H
#define EXPRESION_H
#include <bits/stdc++.h>
#include "Token.h"
#include "Instruccion.h"
#include "Variable.h"

class Expresion : public Instruccion
{
    public:
        Expresion();
        virtual ~Expresion();
        void imprimir();
        void ejecutar(vector<Token>&,int&);
        vector<Token> tE;
        map<string,Variable>::iterator it;
        pair<bool,double> Evaluar(map<string,Token>&,map<string,Variable>&,vector<Token>&,int&);
    protected:
    private:
};

#endif // EXPRESION_H
