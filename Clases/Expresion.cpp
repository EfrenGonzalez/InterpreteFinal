#include "Expresion.h"
#include "Token.h"
#include "Instruccion.h"
#include <bits/stdc++.h>

using namespace std;

Expresion::Expresion()
{
    //ctor
}

Expresion::~Expresion()
{
    //dtor
}

pair<bool,int> Error()
{
    return make_pair(false,0.0);
}

pair<bool,double> Expresion::Evaluar(map<string,Token>& mapa,map<string,pair<int,string> >& tV,vector<Token>& Tokens,int& voy)
{
    map<string,int> pri;
    pri["||"]=1;
    pri["&&"]=2;
    pri["!"]=3;
    pri["=="]=pri[">="]=pri["<="]=pri[">"]=pri["<"]=pri["!="]=4;
    pri["-"]=pri["+"]=5;
    pri["*"]=pri["/"]=6;
    pri["("]=pri[")"]=7;


    while (Tokens[voy].Nombre!=";" && Tokens[voy].Nombre!=":") tE.push_back(Tokens[voy++]);
    voy++;

    stack<pair<double, string> > st;
    queue<pair<double, string> > qu;
    queue<double> sa;
    double a,b;

    //Posfija
    for (int i=0;i<tE.size();i++)
    {
        if (tE[i].Valor==30 || tE[i].Valor==31) qu.push(make_pair(tE[i].Valor,"_"));
        else if (tE[i].Valor==32) qu.push(make_pair(0.0,"_"));
        else if (tE[i].Valor==33) qu.push(make_pair(1.0,"_"));
        else if (tE[i].Valor==6 || tE[i].Valor==7 || tE[i].Valor==8)
        {
            while (!st.empty() && pri[st.top().second]>tE[i].Valor)
            {
                qu.push(make_pair(0.0,st.top().second));
                st.pop();
            }
            st.push(make_pair(0.0,tE[i].Nombre));
        }
        else if (tE[i].Nombre=="(") st.push(make_pair(0.0,tE[i].Nombre));
        else if (tE[i].Nombre==")")
        {
            while (!st.empty() && st.top().second!="(")
            {
                qu.push(make_pair(0.0,st.top().second));
                st.pop();
            }
            if (st.top().second!="(") return Error();
            else st.pop();
        }
        else return Error();
    }
    while (!st.empty())
    {
        if (st.top().second=="(") return Error();
        qu.push(make_pair(0.0,st.top().second));
        st.pop();
    }

    //Evaluar
    while (!qu.empty())
    {
        if (qu.front().second=="_")
        {
            sa.push(qu.front().first);
            qu.pop();
        }
        else if (qu.front().second=="!")
        {
            if (sa.size()<1) return Error();
            else if (sa.front()>=0.000001 || sa.front()<=0.000001)
            {
                sa.pop();
                sa.push(1.0);
            }
            else
            {
                sa.pop();
                sa.push(0.0);
            }
            qu.pop();
        }
        else
        {
            if (sa.size()<2) return Error();
            else
            {
                if (qu.front().second=="+")
                {
                    b=sa.front();
                    sa.pop();
                    a=sa.front();
                    sa.pop();
                    sa.push(a+b);
                }
                else if (qu.front().second=="-")
                {
                    b=sa.front();
                    sa.pop();
                    a=sa.front();
                    sa.pop();
                    sa.push(a-b);
                }
                else if (qu.front().second=="/")
                {
                    b=sa.front();
                    sa.pop();
                    a=sa.front();
                    sa.pop();
                    sa.push(a/b);
                }
                else if (qu.front().second=="*")
                {
                    b=sa.front();
                    sa.pop();
                    a=sa.front();
                    sa.pop();
                    sa.push(a*b);
                }
                else if (qu.front().second==">")
                {
                    b=sa.front();
                    sa.pop();
                    a=sa.front();
                    sa.pop();
                    if (a-b>0.000001) sa.push(1.0);
                    else sa.push(0.0);
                }
                else if (qu.front().second=="<")
                {
                    b=sa.front();
                    sa.pop();
                    a=sa.front();
                    sa.pop();
                    if (a-b<0.000001) sa.push(1.0);
                    else sa.push(0.0);
                }
                else if (qu.front().second==">=")
                {
                    b=sa.front();
                    sa.pop();
                    a=sa.front();
                    sa.pop();
                    if (a-b>=0.000001) sa.push(1.0);
                    else sa.push(0.0);
                }
                else if (qu.front().second=="<=")
                {
                    b=sa.front();
                    sa.pop();
                    a=sa.front();
                    sa.pop();
                    if (a-b<=0.000001) sa.push(1.0);
                    else sa.push(0.0);
                }
                else if (qu.front().second=="!=")
                {
                    b=sa.front();
                    sa.pop();
                    a=sa.front();
                    sa.pop();
                    if (a-b>0.000001 && a-b<-0.000001) sa.push(1.0);
                    else sa.push(0.0);
                }
                else if (qu.front().second=="==")
                {
                    b=sa.front();
                    sa.pop();
                    a=sa.front();
                    sa.pop();
                    if (a-b<0.000001 && a-b>-0.000001) sa.push(1.0);
                    else sa.push(0.0);
                }
                else return Error();
                qu.pop();
            }
        }
    }
    if (sa.size()!=1) return Error();
    else return make_pair(true,sa.front());
}
