#ifndef FILA_H
#define FILA_H

template <class TIPO>
struct TElementoF
{
    TIPO dado;
    TElementoF<TIPO>* proximo = nullptr;
};

template <class TIPO>
class Fila
{
    public:


        void queue (TIPO dado)
        {
            TElementoF<TIPO>* elemento = new TElementoF<TIPO>;
            elemento->dado = dado;

            if (primeiro == nullptr)
            {
                primeiro = elemento;
                quantidade++;
            }

            else
            {
                TElementoF<TIPO>* aux = new TElementoF<TIPO>;
                aux = primeiro;

                for (int i = 0;i < quantidade-1;i++)
                {
                    aux = aux->proximo;
                }

                aux->proximo = elemento;
                quantidade++;
            }
        }

        TIPO dequeue()
        {
            TElementoF<TIPO>* auxAd;
            TIPO toReturn;

            auxAd = primeiro;
            toReturn = primeiro->dado;
            primeiro = primeiro->proximo;
            quantidade--;
            delete auxAd;
            return toReturn;
        }

        void print()
        {
            TElementoF<TIPO>* aux;
            aux = primeiro;
            for (int i = 0; i < quantidade; i++)
            {
                std::cout << aux->dado << " ";
                aux = aux->proximo;
            }
        }

        TIPO first()
        {
            if (primeiro != nullptr) return primeiro->dado;
        }

        bool isEmpty()
        {
            if (primeiro == nullptr) return true;
            else return false;
        }

        int size()
        {
            return quantidade;
        }

    protected:

    private:
        TElementoF<TIPO>* primeiro = nullptr;
        int quantidade = 0;
};

#endif // FILA_H
