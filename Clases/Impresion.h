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
        void imprimir();
        void imprimir(map<string,Token>&,map<string,Variable>&,vector<Token>&,int&);
        map<string,Variable>::iterator it;
        Token variable;
        Token tipo;
    protected:

    private:
};

#endif // IMPRESION_H
