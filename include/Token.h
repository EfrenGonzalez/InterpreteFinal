#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>

using namespace std;
class Token
{
    public:
        int Valor;
        string Nombre;
        Token(int,string);
        Token();
        virtual ~Token();
    protected:
    private:
};
#endif // TOKEN_H
