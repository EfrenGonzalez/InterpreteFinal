#ifndef DECLARACION_H
#define DECLARACION_H
#include "Instruccion.h"
#include "Token.h"

class Declaracion : public Instruccion
{
    public:
        Declaracion();
        virtual ~Declaracion();
        Declaracion(Token,Token);
        void imprimir();
        void ejecutar();
        Token identificador;
        Token tipo;
    protected:

    private:
};

#endif // DECLARACION_H
