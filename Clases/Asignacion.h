#ifndef ASIGNACION_H
#define ASIGNACION_H
#include "Instruccion.h"
#include "Token.h"
#include "Expresion.h"
#include "Variable.h"
#include <bits/stdc++.h>

class Asignacion : public Instruccion
{
    public:
        map<string,Variable>::iterator it;
        Asignacion();
        virtual ~Asignacion();
        bool asignar(map<string,Token>&,map<string,Variable>&,vector<Token>&,int&);
        void ejecutar();
    protected:

    private:
};

#endif // ASIGNACION_H
