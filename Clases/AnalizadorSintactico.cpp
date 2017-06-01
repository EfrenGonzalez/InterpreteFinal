#include "AnalizadorSintactico.h"
#include "Token.h"

//vector<Token> tokens;
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
    mapa["repetir"]=Token(44,"Estructura de control");
    mapa["mientras"]=Token(45,"Estructura de control");
    mapa["si"]=Token(41,"Estructura de control");
    mapa["sino"]=Token(42,"Estructura de control");
    mapa["trastrueco"]=Token(43,"Estructura de control");

    mapa["true"]=Token(32,"Verdadero");
    mapa["false"]=Token(33,"Falso");

    mapa["entero"]=Token(20,"Tipo de dato");
    mapa["boleano"]=Token(22,"Tipo de dato");
    mapa["flotante"]=Token(21,"Tipo de dato");
    mapa["cadena"]=Token(23,"Tipo de dato");

    mapa["imprimir"]=Token(1,"Identificador");
    mapa["leer"]=Token(2,"Identificador");

    mapa["+"]=Token(7,"Operador Aritmetico");
    mapa["-"]=Token(7,"Operador Aritmetico");
    mapa["*"]=Token(7,"Operador Aritmetico");
    mapa["/"]=Token(7,"Operador Aritmetico");
    mapa["="]=Token(6,"Operador Logico");
    mapa["<"]=Token(6,"Operador Logico");
    mapa[">"]=Token(6,"Operador Logico");
    mapa["!"]=Token(6,"Operador Logico");
    mapa["&"]=Token(7,"Operador Aritmetico");
    mapa["|"]=Token(7,"Operador Aritmetico");
    mapa["^"]=Token(7,"Operador Aritmetico");
    mapa["&&"]=Token(6,"Operador Logico");
    mapa["||"]=Token(6,"Operador Logico");
    mapa["=="]=Token(8,"Operador Relacional");
    mapa[">="]=Token(8,"Operador Relacional");
    mapa["<="]=Token(8,"Operador Relacional");
    mapa["!="]=Token(8,"Operador Relacional");
    mapa[":"]=Token(8,"Operador Relacional");

    mapa[";"]=Token(5,"Agrupacion");

    mapa["("] = Token(5,"Agrupacion");
    mapa[")"] = Token(5,"Agrupacion");
    mapa["{"] = Token(5,"Agrupacion");
    mapa["}"] = Token(5,"Agrupacion");
}

void AnalizadorSintactico::AnalizadorLexico(){
    string s; int err = 0; string pal;
    while (cin>>s){
        it=mapa.find(s);
        if (it!=mapa.end()){
            //cout << s << " - " << mapa[s].Tipo << " "<<mapa[s].Valor<<endl;
            tokens[s] = Token(mapa[s].Valor,mapa[s].Tipo);
        }
        else
        {
            if (s[0]=='"')
            {
                for(int i=1;i<s.length();i++){
                    if(s.at(i)!='"'){
                        pal = pal+s.at(i);
                    }
                }
                //cout<< pal << " - "<< "String"<<endl;
                tokens[s] = Token(23,"Tipo de dato");
                pal = "";
            }
            else if(s[0]=='_' || (s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z'))
            {
                bool wii=true;
                for(int i=1;i<s.length();i++)
                    if (!(s[i]=='_' || (s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9'))) wii=false;
                if (wii) {
                    //cout << s << " - "<< "Identificador" <<endl;
                    tokens[s] = Token(1,"Identificador");
                }
                else {
                    cout<<"Error"<<endl;
                    break;
                }
            }
            else if(s[0]>='0' && s[0]<='9')
            {
                bool wii=true;
                for(int i=1;i<s.length();i++)
                    if (!((s[i]>='0' && s[i]<='9'))) wii=false;
                for(int i=0;i<s.length();i++)
                    if(s.at(i)=='.') err++;
                if (wii)
                {
                    if(err==0){
                        //cout << s << " - "<<"Numero"<<endl;
                        tokens[s] = Token(20,"Tipo de dato");
                    }
                    else if(err==1){
                        //cout << s << " - " <<"Doble"<< endl;
                        tokens[s] = Token(21,"Tipo de dato");
                    }
                    else{
                        cout << "Error"<<endl;
                        break;
                    }
                    err = 0;
                }
                else {
                    cout << "Error"<<endl;
                    break;
                }
            }
        }
        cout << s << " "<<tokens[s].Valor << " " << tokens[s].Tipo << endl;
    }
}
