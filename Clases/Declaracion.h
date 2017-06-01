#ifndef DECLARACION_H
#define DECLARACION_H
#include "Instruccion.h"
#include "map"
#include "string"
#include "Token.h"

using namespace std;
class Declaracion : Instruccion
{
    public:
        Declaracion();
        virtual ~Declaracion();
        Declaracion(Token,Token);
        void TablaDeSimbolos(string,string);
        void imprimir();
        void ejecutar();
        Token identificador;
        Token tipo;
    protected:

    private:
};

#endif // DECLARACION_H
