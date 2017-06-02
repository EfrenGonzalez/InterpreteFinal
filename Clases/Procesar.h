#ifndef PROCESAR_H
#define PROCESAR_H
#include "Instruccion.h"
#include "Token.h"
#include "Impresion.h"
#include "Expresion.h"
#include "Variable.h"
#include <bits/stdc++.h>

using namespace std;

class Procesar
{
    public:
        Procesar();
        bool Procesamiento(map<string,Token>&,map<string,Variable>&,vector<Token>&,int&);
        virtual ~Procesar();
    protected:
    private:
};

#endif // PROCESAR_H
