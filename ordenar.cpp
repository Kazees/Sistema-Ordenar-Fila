#include "ordenar.h"

namespace bry
{
    Ordenar::Ordenar(int tamanho):tamanho(0),array(0)
    {
        try
        {
            array=new int[tamanho];
            this->tamanho=tamanho;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Não foi possível criar.");
        }

        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        for(int i=0;i<tamanho;i++)
        {
            int random=std::rand()%101;

            *(array+i)=random;
        }
    }

    Ordenar::~Ordenar()
    {
        if(array)
        {
            delete []array;
        }
    }

    QString Ordenar::ordenarFila()const
    {
        bry::Fila n1(tamanho);
        QString saida="";

        for(int i=0;i<tamanho;i++)
        {
           n1.inserir(*(array+i));
        }

        for(int i=0;i<tamanho-1;i++)
        {
            int menor=n1.acessar();
            n1.retirar();

            for(int j=0;j<tamanho-1;j++)
            {
                int atual=n1.acessar();
                n1.retirar();

                if(atual>menor)
                {
                    int aux=menor;
                    menor=atual;
                    atual=aux;
                }

                n1.inserir(atual);
            }
            n1.inserir(menor);
        }


        while(!n1.estaVazia())
        {
            saida+=QString::number(n1.acessar())+"|";
            n1.retirar();
        }

        return saida;
    }

    QString Ordenar::getDesordenado()const
    {
        QString saida="";

        for(int i=0;i<tamanho;i++)
        {
            saida+=QString::number(*(array+i))+"|";
        }

        return saida;
    }
}


