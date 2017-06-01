#ifndef ANALIZADORSINTACTICO_H
#define ANALIZADORSINTACTICO_H
#include "Token.h"
#include <bits/stdc++.h>

using namespace std;
class AnalizadorSintactico
{
    public:
        static map<string,Token> mapa;
        map<string,Token>::iterator it;
        AnalizadorSintactico();
        virtual ~AnalizadorSintactico();
        vector<Token> VectorSintatico(string);
    protected:

    private:
        void declarar();
};

#endif // ANALIZADORSINTACTICO_H
