#include "Variable.h"
#include <bits/stdc++.h>

using namespace std;

Variable::Variable()
{
    Tipo=0;
    ValorNum=0;
    ValorStr="";
}

Variable::Variable(int tipo,double valornum,string valorstr)
{
    Tipo=tipo;
    ValorNum=valornum;
    ValorStr=valorstr;
}

Variable::~Variable()
{
    //dtor
}
