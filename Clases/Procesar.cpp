#include "Procesar.h"
#include "Token.h"
#include "Asignacion.h"
#include "Declaracion.h"
#include "Instruccion.h"
#include "Impresion.h"
#include "Expresion.h"
#include "Variable.h"
#include "Lecture.h"
#include <bits/stdc++.h>

using namespace std;

Procesar::Procesar()
{
}

bool Procesar::Procesamiento(map<string,Token>& mapa,map<string,Variable>& tV,vector<Token>& Tokens,int& voy)
{
    while (voy<Tokens.size())
    {
        if (Tokens[voy].Valor==20 || Tokens[voy].Valor==21 || Tokens[voy].Valor==22 || Tokens[voy].Valor==23)
        {
            Declaracion a = Declaracion();
            a.evaluar(mapa,tV,Tokens,voy);
        }
        else if (Tokens[voy].Valor==1)
        {
            Asignacion a = Asignacion();
            a.asignar(mapa,tV,Tokens,voy);
        }
        else if (Tokens[voy].Valor==2)
        {
            Impresion a = Impresion();
            a.imprimir(mapa,tV,Tokens,voy);
        }
        else if (Tokens[voy].Valor==3)
        {
            Lecture a = Lecture();
            a.leer(mapa,tV,Tokens,voy);
        }
        else if (Tokens[voy].Valor==41)
        {
        }
        else if (Tokens[voy].Valor==42)
        {
        }
        else if (Tokens[voy].Valor==43)
        {
        }
        else if (Tokens[voy].Valor==44)
        {
        }
        else if (Tokens[voy].Valor==45)
        {
        }
        else return false;
    }
    return true;
}

Procesar::~Procesar()
{
}
