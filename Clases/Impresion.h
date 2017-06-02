#ifndef IMPRESION_H
#define IMPRESION_H
#include "Instruccion.h"
#include "Expresion.h"
#include <bits/stdc++.h>

class Impresion : public Instruccion
{
    public:
        Impresion();
        virtual ~Impresion();
        void ejecutar();
        void imprimir(map<string,Token>& mapa,map<string,Variable>& tV,vector<Token>& Tokens,int& voy);
        map<string,Variable>::iterator it;
        Expresion exp;
    protected:

    private:
};

#endif // IMPRESION_H
