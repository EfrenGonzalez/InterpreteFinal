#ifndef ASIGNACION_H
#define ASIGNACION_H
#include "Instruccion.h"
#include "Token.h"
#include "Expresion.h"

class Asignacion :public Instruccion {
    public:
        Asignacion();
        virtual ~Asignacion();
        Token identificador;
        Expresion exp;
        void imprimir();
        void ejecutar();
    protected:

    private:
};

#endif // ASIGNACION_H
