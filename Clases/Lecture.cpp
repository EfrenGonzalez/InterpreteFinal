#include "Lecture.h"
#include "Impresion.h"
#include "Expresion.h"
#include "Variable.h"
#include "Token.h"
#include <bits/stdc++.h>

using namespace std;

int Lecture::voyLecture;

Lecture::Lecture()
{
    //ctor
}

Lecture::~Lecture()
{
    //dtor
}

Lecture::Lecture(string s)
{
    strcpy(a, s.c_str());
    voyLecture=0;
}

bool Lecture::leer(map<string,Token>& mapa,map<string,Variable>& tV,vector<Token>& Tokens,int& voy)
{
    string aux;
    freopen(a,"r",stdin);
    for (int i=0;i<voyLecture;i++) cin>>aux;
    it=tV.find(Tokens[voy+1].Nombre);
    if (it==tV.end())
    {
        fclose(stdin);
        return false;
    }
    if (Tokens[voy+2].Nombre!=";")
    {
        fclose(stdin);
        return false;
    }
    try
    {
        if (tV[Tokens[voy+1].Nombre].Tipo<=3)
        {
            if (cin>>tV[Tokens[voy+1].Nombre].ValorNum);
            else
            {
                fclose(stdin);
                return false;
            }
        }
        else if (cin>>tV[Tokens[voy+1].Nombre].ValorStr);
        else
        {
            fclose(stdin);
            return false;
        }
    }
    catch (int e)
    {
        fclose(stdin);
        return false;
    }
    voyLecture++;
    voy+=3;
    fclose(stdin);
    return true;
}

void Lecture::ejecutar()
{

}
