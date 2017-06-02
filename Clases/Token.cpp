#include <bits/stdc++.h>
#include "Token.h"
#include "Variable.h"

Token::Token()
{
    //ctor
}

Token::~Token()
{
    //dtor
}

Token::Token(int n, string tipo, string nombre)
{
    Valor=n;
    Tipo=tipo;
    Nombre=nombre;
}
