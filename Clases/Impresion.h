#ifndef IMPRESION_H
#define IMPRESION_H
#include "Instruccion.h"
#include "Expresion.h"

class Impresion : Instruccion
{
    public:
        Impresion();
        virtual ~Impresion();
        void ejecutar();
        Expresion exp;
    protected:

    private:
};

#endif // IMPRESION_H
