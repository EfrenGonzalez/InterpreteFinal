#include "string"
#include "iostream"
#include "Declaracion.h"
#include <stdlib.h>

using namespace std;
Declaracion::Declaracion()
{
    //ctor
}

Declaracion::~Declaracion()
{
    //dtor
}

void Declaracion::imprimir()
{

}

void Declaracion::ejecutar(){

}

Declaracion::Declaracion(Token ti,Token ide){
    this->tipo = ti;
    identificador = ide;
}
