#ifndef SI_H
#define SI_H
#include "Expresion.h"

class Si
{
    public:
        Si();
        virtual ~Si();
        void ejecutar();
        void imprimir();
        bool ejecutarSi(map<string,Token>&,map<string,Variable>&,vector<Token>&,int&);
        Expresion exp;
    protected:

    private:
};

#endif // SI_H
