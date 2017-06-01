#ifndef ANALIZADORSINTACTICO_H
#define ANALIZADORSINTACTICO_H
#include <algorithm>
#include <map>
#include "Token.h"

using namespace std;
class AnalizadorSintactico
{
    public:
        static map<string,Token> mapa;
        map<string,Token>::iterator it;
        AnalizadorSintactico();
        virtual ~AnalizadorSintactico();
        void AnalizadorLexico();
    protected:

    private:
        void declarar();
};

#endif // ANALIZADORSINTACTICO_H
