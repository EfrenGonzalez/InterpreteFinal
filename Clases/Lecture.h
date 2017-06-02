#ifndef LECTURE_H
#define LECTURE_H
#include "Instruccion.h"
#include "Token.h"
#include "Impresion.h"
#include "Expresion.h"
#include "Variable.h"
#include <bits/stdc++.h>

using namespace std;

class Lecture: Instruccion
{
    public:
        Lecture();
        Lecture(string);
        static int voyLecture;
        char a[100];
        map<string,Variable>::iterator it;
        virtual ~Lecture();
        Token identificador;
        void ejecutar();
        bool leer(map<string,Token>&,map<string,Variable>&,vector<Token>&,int&);
    protected:

    private:
};

#endif // LECTURA_H
