#include <iostream>
#include "AnalizadorSintactico.h"
#include "Token.h"

using namespace std;

int main()  {
    string ruta = "";
    AnalizadorSintactico as;
    vector<Token> tokens = as.VectorSintatico(ruta);
    map<string, pair<string,Token> > tablavalor;

    if(tokens.size()!=0) {
        for(int i=0;i<tokens.size();i++) {
          // tablavalor[tokens[i].Nombre] = make_pair(,);
        }
    }
    else{
        cout << "Error." << endl;
        return 1;
    }

}
