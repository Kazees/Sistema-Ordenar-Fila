#ifndef FILA_H
#define FILA_H
#include <QString>

namespace bry
{
    class Fila
    {
    private:
        int inicio;
        int fim;
        int *array;
        int tamanho;
        int quantelementos;

    public:
        Fila(int tamanho);
        ~Fila();

        bool estaVazia()const {return (quantelementos==0);}
        bool estaCheia()const {return (quantelementos==tamanho);}

        void inserir(int elemento);
        void retirar();
        int acessar()const;
    };
}



#endif // FILA_H
