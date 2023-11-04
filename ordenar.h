#ifndef ORDENAR_H
#define ORDENAR_H
#include <QString>
#include <fila.h>
#include <ctime>
#include <cstdlib>

namespace bry
{
    class Ordenar
    {
    private:
        int tamanho;
        int *array;

    public:
        Ordenar(int tamanho);
        ~Ordenar();

        QString getDesordenado()const;
        QString ordenarFila()const;

    };
}

#endif // ORDENAR_H
