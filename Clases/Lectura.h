#ifndef LECTURA_H
#define LECTURA_H
#include "Instruccion.h"
#include "Token.h"

class Lectura: Instruccion
{
    public:
        Lectura();
        virtual ~Lectura();
        Token identificador;
        void ejecutar();
    protected:

    private:
};

#endif // LECTURA_H
