#ifndef DECLARACION_H
#define DECLARACION_H
#include <bits/stdc++.h>
#include "Instruccion.h"
#include "Token.h"
#include "Variable.h"

class Declaracion : public Instruccion
{
    public:
        Declaracion();
        virtual ~Declaracion();
        Declaracion(Token,Token);
        void imprimir();
        void ejecutar();
        map<string,Variable>::iterator it;
        bool evaluar(map<string,Token>&,map<string,Variable>&,vector<Token>&,int&);
        Token variable;
        Token tipo;
    protected:

    private:
};

#endif
