#ifndef INSTRUCCION_H
#define INSTRUCCION_H


class Instruccion
{
    public:
        Instruccion();
        virtual ~Instruccion();

        void virtual ejecutar() = 0;
        void virtual imprimir() = 0;

    protected:

    private:
};

#endif // INSTRUCCION_H

