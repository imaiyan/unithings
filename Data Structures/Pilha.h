#ifndef PILHA_H
#define PILHA_H

template <class TIPO>
struct TElemento
{
    TIPO dado;
    TElemento<TIPO>* proximo = nullptr;
};

template <class TIPO>
class Pilha
{
    public:



        TElemento<TIPO>* push(TIPO dado)
        {
            TElemento<TIPO>* elemento = new TElemento<TIPO>;
            elemento->dado = dado;

            if (topo != nullptr)
            {
                elemento->proximo = topo;
            }
            topo = elemento;
        }

        TIPO pop()
        {
            TIPO dado = topo->dado;
            TElemento<TIPO>* copiaEndereco;

            copiaEndereco = topo;

            if (topo->proximo != nullptr) topo = topo->proximo;
            else topo = nullptr;

            delete copiaEndereco;
            return dado;

        }

        TIPO top()
        {
            return topo->dado;
        }

        TElemento<TIPO>* topAddress()
        {
            return topo;
        }

        void print()
        {
            TElemento<TIPO>* aux;
            aux = topo;
            while (aux->proximo != nullptr)
            {
                std::cout << aux->dado << " ";
                aux = aux->proximo;
            }
            std::cout << aux->dado << " ";
        }

        bool isEmpty()
        {
            return (topo == nullptr);
        }

        int size()
        {
            return quantidade;
        }

    protected:

    private:

        int quantidade;
        TElemento<TIPO>* topo = nullptr;

};

#endif // PILHA_H
