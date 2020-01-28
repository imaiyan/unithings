#ifndef HASH_H
#define HASH_H
#define hashTam 70


using namespace std;


class TDado {
    private:
        int chave;
        int frequencia;


    public:
        string dado;

        TDado(int chave, string dado){
            this->chave = chave;
            this->dado = dado;
            frequencia = 0;
        }

        int getFrequencia() {
            return frequencia;
        }

        void updateFrequencia()
        {
            frequencia++;
        }
};

class Hash
{
    public:
        Hash()
        {
            for (unsigned int i = 0; i < hashTam; i++)
            {
                table[i] = nullptr;
            }
            totalUtilizado = 0;
            colisaoCounter = 0;
            totalColisoes = 0;
        }

        void add(string dado)
        {
            if (!exists(dado, keyGenerator(dado)) && isEmpty(dado))
            {
                TDado* elemento = new TDado(keyGenerator(dado), dado);
                table[keyGenerator(dado)] = elemento;
                table[keyGenerator(dado)]->updateFrequencia();
                totalUtilizado++;
            }

            else if (!exists(dado, keyGenerator(dado)) && !isEmpty(dado))
            {
                recursiveAdd(keyGenerator(dado)+1, dado);
            }
            else if (exists(dado, keyGenerator(dado))) {
                table[keyGenerator(dado)]->updateFrequencia();
            }
            colisaoCounter = 0;
        }

        void print()
        {
            for (unsigned int i = 0;i < hashTam;i++)
            {
                if (table[i] != nullptr)
                {
                    cout << "Posicao " << i << ": " << table[i]->dado << ", frequencia: " << table[i]->getFrequencia() << endl;
                }
            }
        }

        int getTotalUtilizado(){
            return totalUtilizado;
        }

        int getColisaoCounter()
        {
            return colisaoCounter;
        }

        int getTotalColisoes()
        {
            return totalColisoes;
        }

    protected:

    private:
        TDado* table[hashTam];
        int totalUtilizado;
        int colisaoCounter;
        int totalColisoes;

        int keyGenerator(string dado)
        {
            unsigned int key = 0;
            for (unsigned int i = 0;i < dado.size();i++)
            {
                key += dado[i];
            }

            return (key*dado[dado.size()-1])%hashTam;
        }

        bool exists(string dado, int key)
        {
            if (key < 70)
            {
                if (table[key] != nullptr)
                {
                    if (table[key]->dado == dado){
                        return true;
                    }
                    else {
                        exists(dado, key+1);
                    }
                }
            }
            else exists(dado, 0);
            return false;
        }

        bool isEmpty(string dado)
        {
            if (table[keyGenerator(dado)] == nullptr) return true;
            else return false;
        }

        int recursiveAdd(int key, string dado)
        {
            colisaoCounter++;
            totalColisoes++;
            if (key < hashTam)
            {
                if (table[key] == nullptr)
                {
                    cout << "Ocorreram " << colisaoCounter << " colisoes ao inserir a palavra " << dado << endl;
                    table[key] = new TDado(key, dado);
                    table[key]->updateFrequencia();
                    totalUtilizado++;
                }

                else if (table[key]->dado == dado)
                {
                    table[key]->updateFrequencia();
                    return key;
                }

                else return recursiveAdd(key+1, dado);
            }
            else return recursiveAdd(0, dado);
        }
};

#endif // HASH_H
