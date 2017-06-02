#ifndef INSTRUCCION_H
#define INSTRUCCION_H
#include <bits/stdc++.h>
#include "Token.h"
#include "Variable.h"

class Instruccion
{
    public:
        Instruccion();
        virtual ~Instruccion();

        void virtual ejecutar(vector<Token>&,int&) = 0;
        void virtual imprimir() = 0;

    protected:

    private:
};

#endif // INSTRUCCION_H
