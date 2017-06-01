#ifndef ASIGNACION_H
#define ASIGNACION_H
#include "Instruccion.h"
#include "Token.h"
#include "Expresion.h"
#include <bits/stdc++.h>

class Asignacion : public Instruccion
{
    public:
        map<string,pair<int,string> >::iterator it;
        Asignacion();
        virtual ~Asignacion();
        Token variable;
        Expresion exp;
        void asignar(pair<bool,double>& inst,map<string,pair<int,string> >& tV,vector<Token>& Tokens,int& voy);
        void ejecutar();
    protected:

    private:
};

#endif // ASIGNACION_H
