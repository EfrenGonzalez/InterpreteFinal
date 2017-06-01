#ifndef ANALIZADORSINTACTICO_H
#define ANALIZADORSINTACTICO_H
#include <algorithm>
#include <map>
#include "Token.h"
#include "Declaracion.h"
#include "vector"

using namespace std;
class AnalizadorSintactico
{
    public:
        static map<string,Token> mapa;
        map<string,Token> tokens;
        map<string,Token>::iterator it;
        AnalizadorSintactico();
        virtual ~AnalizadorSintactico();
        void AnalizadorLexico();
        void declarar();
    protected:

    private:

};

#endif // ANALIZADORSINTACTICO_H
