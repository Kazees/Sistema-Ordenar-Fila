#include "fila.h"

namespace bry
{
Fila::Fila(int tamanho):inicio(-1),fim(-1),array(0),tamanho(0),quantelementos(0)
    {
        if(tamanho<=0)
        {
            throw QString("Tamanho inválido.");
        }

        try
        {
            array=new int[tamanho];
            this->tamanho=tamanho;

        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Não foi possível criar a fila.");
        }
    }

    Fila::~Fila()
    {
        if(array)
        {
            delete []array;
        }
    }

    void  Fila::inserir(int elemento)
    {
        if(estaCheia())
        {
            throw QString("Fila está cheia.");
        }

        if(estaVazia())
        {
            inicio=0;
            fim++;

            *(array+fim)=elemento;
            quantelementos++;
            return;
        }

        fim++;

        if(fim==tamanho)
        {
            fim=0;
        }

        *(array+fim)=elemento;
        quantelementos++;
    }

    void Fila::retirar()
    {
        if(estaVazia())
        {
            throw QString("Fila está vazia.");
        }

        if(quantelementos==1)
        {
            fim=inicio=-1;
            quantelementos=0;
            return;
        }

        inicio++;

        if(inicio==tamanho)
        {
            inicio=0;
        }

        quantelementos--;
    }

    int Fila::acessar()const
    {
        if(estaVazia())
        {
            throw QString("Fila está vazia.");
        }

        return *(array+inicio);
    }
}
