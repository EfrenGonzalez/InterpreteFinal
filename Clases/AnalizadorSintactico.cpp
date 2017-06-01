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
    //dtor
}

void AnalizadorSintactico::declarar() {
    mapa["repetir"]=Token(44,"Estructura de control","repetir");
    mapa["mientras"]=Token(45,"Estructura de control","mientras");
    mapa["si"]=Token(41,"Estructura de control","si");
    mapa["sino"]=Token(42,"Estructura de control","sino");
    mapa["trastrueco"]=Token(43,"Estructura de control","transtrueco");

    mapa["verdadero"]=Token(32,"Verdadero","verdadero");
    mapa["falso"]=Token(33,"Falso","falso");

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
    mapa["<="]=Token(8,"Operador Relacional","<=);
    mapa["!="]=Token(8,"Operador Relacional","!=");
    mapa[":"]=Token(8,"Operador Relacional",":");
    mapa[";"]=Token(5,"Agrupación",";");
    mapa["("] = Token(5,"Agrupacion"."(");
    mapa[")"] = Token(5,"Agrupacion",")");
    mapa["{"] = Token(5,"Agrupacion","{");
    mapa["}"] = Token(5,"Agrupacion","}");
}
void AnalizadorSintactico::AnalizadorLexico(){
    string s; int err = 0; string pal;
    while (cin>>s)
    {
        it=mapa.find(s);
        if (it!=mapa.end()) cout << s << " - " << mapa[s].Nombre << " "<<mapa[s].Valor<<endl;
        else
        {
            if (s[0]=='"')
            {
                bool wii=true;
                for(int i=1;i<s.length()-1;i++)
                    if (s[i]=='"') wii=false;
                if (s[s.size()-1]!='"') wii=false;
                cout<< pal << " - "<< "String"<<endl;
            }
            else if(s[0]=='_' || (s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z'))
            {
                bool wii=true;
                for(int i=1;i<s.length();i++)
                    if (!(s[i]=='_' || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))) wii=false;
                if (wii) cout << s << " - "<< "Nombre de variable"<<endl;
                else cout<<s<<"- Hubo un error"<<endl;
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
                    if(err==0){
                        cout << s << " - "<<"Numero"<<endl;
                    }
                    else if(err==1){
                        cout << s << " - " <<"Doble"<<endl;
                    }
                    else{
                        cout << "Error"<<endl;
                    }
                    err = 0;
                }
                else cout << "Error"<<endl;
            }
        }
    }
}
