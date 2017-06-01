#include <bits/stdc++.h>
#include "AnalizadorSintactico.h"
#include "Token.h"

map<string,Token> AnalizadorSintactico::mapa;
AnalizadorSintactico::AnalizadorSintactico() {
    if(mapa.size()==0){
        declarar();
    }
}

AnalizadorSintactico::~AnalizadorSintactico()
{
    mapa.clear();
}

void AnalizadorSintactico::declarar() {
    mapa["repetir"]=Token(44,"Estructura de control","repetir");
    mapa["mientras"]=Token(45,"Estructura de control","mientras");
    mapa["si"]=Token(41,"Estructura de control","si");
    mapa["sino"]=Token(42,"Estructura de control","sino");
    mapa["trastrueco"]=Token(43,"Estructura de control","transtrueco");

    mapa["verdadero"]=Token(32,"Valor","verdadero");
    mapa["falso"]=Token(33,"Valor","falso");

    mapa["entero"]=Token(20,"Tipo de dato","entero");
    mapa["boleano"]=Token(22,"Tipo de dato","boleano");
    mapa["flotante"]=Token(21,"Tipo de dato","flotante");
    mapa["cadena"]=Token(23,"Tipo de dato","cadena");

    mapa["imprimir"]=Token(1,"Identificador","imprimir");
    mapa["leer"]=Token(2,"Identificador","leer");

    mapa["+"]=Token(7,"Operador Aritmetico","+");
    mapa["-"]=Token(7,"Operador Aritmetico","-");
    mapa["*"]=Token(7,"Operador Aritmetico","*");
    mapa["/"]=Token(7,"Operador Aritmetico","/");
    mapa["="]=Token(6,"Operador Logico","=");
    mapa["<"]=Token(6,"Operador Logico","<");
    mapa[">"]=Token(6,"Operador Logico",">");
    mapa["!"]=Token(6,"Operador Logico","!");
    mapa["&"]=Token(7,"Operador Aritmetico","&");
    mapa["|"]=Token(7,"Operador Aritmetico","|");
    mapa["^"]=Token(7,"Operador Aritmetico","^");
    mapa["&&"]=Token(6,"Operador Logico","&&");
    mapa["||"]=Token(6,"Operador Logico","||");
    mapa["=="]=Token(8,"Operador Relacional","==");
    mapa[">="]=Token(8,"Operador Relacional",">=");
    mapa["<="]=Token(8,"Operador Relacional","<=");
    mapa["!="]=Token(8,"Operador Relacional","!=");
    mapa[":"]=Token(8,"Operador Relacional",":");

    mapa[";"]=Token(5,"Agrupación",";");

    mapa["("] = Token(5,"Agrupacion","(");
    mapa[")"] = Token(5,"Agrupacion",")");
    mapa["{"] = Token(5,"Agrupacion","{");
    mapa["}"] = Token(5,"Agrupacion","}");
}

vector<Token> AnalizadorSintactico::VectorSintatico(string archivo)
{
    vector<Token> Tokens;
    char archivo1[100];
    strcpy(archivo1, archivo.c_str());
    freopen(archivo1,"r",stdin);
    string s; int err = 0; string pal;
    while (cin>>s)
    {
        it=mapa.find(s);
        if (it!=mapa.end()) Tokens.push_back(mapa[s]);
        else
        {
            if (s[0]=='"')
            {
                bool wii=true;
                for(int i=1;i<s.length()-1;i++) if (s[i]=='"') wii=false;
                if (s[s.size()-1]!='"') wii=false;
                if (wii)
                {
                    mapa[s]=Token(Token(33,"Valor",s));
                    Tokens.push_back(mapa[s]);
                }
                else
                {
                    fclose(stdin);
                    Tokens.clear();
                    return Tokens;
                }
            }
            else if(s[0]=='_' || (s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z'))
            {
                bool wii=true;
                for(int i=1;i<s.length();i++)
                    if (!(s[i]=='_' || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))) wii=false;
                if (wii)
                {
                    mapa[s]=Token(1,"Identificador",s);
                    Tokens.push_back(mapa[s]);
                }
                else
                {
                    fclose(stdin);
                    Tokens.clear();
                    return Tokens;
                }
            }
            else if(s[0]>='0' && s[0]<='9')
            {
                bool wii=true;
                for(int i=1;i<s.length();i++)
                    if (!((s[i]>='0' && s[i]<='9') || s[i]!='.')) wii=false;
                for(int i=0;i<s.length();i++)
                    if(s[i]=='.') err++;
                if (wii)
                {
                    if(err==0)
                    {
                        mapa[s]=Token(30,"Valor",s);
                        Tokens.push_back(mapa[s]);
                    }
                    else if(err==1)
                    {
                        mapa[s]=Token(31,"Valor",s);
                        Tokens.push_back(mapa[s]);
                    }
                    else
                    {
                        fclose(stdin);
                        Tokens.clear();
                        return Tokens;
                    }
                    err = 0;
                }
                else
                {
                    fclose(stdin);
                    Tokens.clear();
                    return Tokens;
                }
            }
        }
    }
    fclose(stdin);
    return Tokens;
}
