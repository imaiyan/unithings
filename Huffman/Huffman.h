#ifndef HUFFMAN_H_INCLUDED
#define HUFFMAN_H_INCLUDED
#include "TNoHuffman.h"
#include "ListaHuffman.h"

using namespace std;

class Huffman {
    private: TNoHuff* raizHuffman;
    public: ListaHuffman* lista;
    private: string huffmanText;

    public:
        Huffman(string texto) {
            lista = listaLetras(texto);
            bubbleSort(lista);
            raizHuffman = transformaArvore(lista);
            generateTable(raizHuffman);
            generateHuffText(texto);
        }

        void print() {
            print(raizHuffman);
        }

        void printTable() {
            printTable(raizHuffman);
        }

        string getHuffText() {
            return huffmanText;
        }

        int getBytes() {
            return huffmanText.size()/8;
        }

    private:
        ListaHuffman* listaLetras(string texto) {
            ListaHuffman* lista = new ListaHuffman();
            ListaEncadeada<char>* listaChar = new ListaEncadeada<char>;

            for (unsigned int i = 0; i < texto.size();i++) {

                if (!listaChar->verificaExistencia(texto[i])) {
                    listaChar->inserirListaEnd(texto[i]);
                    int freq = 0;
                    for (unsigned int j = 0; j < texto.size();j++) {
                        if (texto[i] == texto[j]) freq++;
                    }

                    TNoHuff* letra = new TNoHuff(texto[i], freq);
                    lista->inserirListaEnd(letra);
                }
            }
            return lista;
        }

        TNoHuff* transformaArvore(ListaHuffman* lista) {
            TNoHuff* pai = new TNoHuff();
            while (lista->start != nullptr) {
                if (lista->quantidade == 1) return pai;
                TNoHuff* node1 = lista->removerListaStart();
                TNoHuff* node2 = lista->removerListaStart();



                TNoHuff* novoNo = new TNoHuff('0', node1->frequencia+node2->frequencia,node1, node2);
                lista->inserirListaEnd(novoNo);
                bubbleSort(lista);
                pai = novoNo;
            }
        }

        void print(TNoHuff* no) {
            if (no != nullptr) {
                cout << "Dado: " << no->dado << " Frequencia: " << no->frequencia << endl;
                print(no->esquerda);
                print(no->direita);
            }
        }

        void printTable(TNoHuff* no) {
            if (no != nullptr) {
                if (no->dado != '0') cout << no->dado << " | " << no->frequencia << " | " << no->codificacao << endl;
                printTable(no->esquerda);
                printTable(no->direita);
            }
        }

        void generateTable(TNoHuff* no, string t = "") {
            if (no != nullptr) {
                generateTable(no->esquerda, t+"0");
                generateTable(no->direita, t+"1");
                no->codificacao = t;
            }
        }

        void findHuffCoding(TNoHuff* &no, char caractere) {
            if (no != nullptr)
            {
                if (no->dado == caractere) {
                    huffmanText += no->codificacao;
                }
                else {
                    findHuffCoding(no->esquerda, caractere);
                    findHuffCoding(no->direita, caractere);
                }
            }
            huffmanText += "";
        }

        void generateHuffText(string texto) {
            for (int i = 0;i < texto.size();i++)
            {
                findHuffCoding(raizHuffman, texto[i]);
            }
        }

        void bubbleSort(ListaHuffman* lista)
        {
           int i, j;
           bool swapped;
           for (i = 0; i < lista->quantidade-1; i++)
           {
             swapped = false;
             for (j = 0; j < lista->quantidade-1; j++)
             {
                if (lista->retornaItem(j)->frequencia > lista->retornaItem(j+1)->frequencia)
                {
                   lista->switchNext(j, j+1);
                   swapped = true;
                }
             }

             if (swapped == false)
                break;
           }
        }
};

#endif // HUFFMAN_H_INCLUDED
