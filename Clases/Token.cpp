#include "Token.h"

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
