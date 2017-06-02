#ifndef VARIABLE_H
#define VARIABLE_H
#include <bits/stdc++.h>

using namespace std;

class Variable
{
    public:
        int Tipo;
        double ValorNum;
        string ValorStr;
        Variable();
        Variable(int,double,string);
        virtual ~Variable();
    protected:
    private:
};

#endif // VARIABLE_H
