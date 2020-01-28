#include <iostream>
#include "Hash.h"
#include "TextReader.h"
#include "Huffman.h"


using namespace std;

void testarHashPalavras() {
    ListaEncadeada<string>* teste = new ListaEncadeada<string>;
    Hash* hashTeste = new Hash;

    teste = catchWords(readText());



    for (unsigned int i = 0; i < 61;i++) {
        hashTeste->add(teste->removerListaStart());
    }

    hashTeste->print();

    cout << "No total, ocorreram " << hashTeste->getTotalColisoes() << " colisoes.";

    cout << " Foram utilizados " << hashTeste->getTotalUtilizado() << " espacos da hash." << endl;
}


void testarHuffman() {
    Huffman* huffman = new Huffman(readText());

    cout << "Arvore: " << endl;
    huffman->print();
    cout << endl;

    cout << "Tabela: " << endl;
    huffman->printTable();
    cout << endl;

    cout << "Texto codificado: " << endl;
    cout << huffman->getHuffText();
    cout << endl;

    cout << "Tamanho do texto original: 448 bytes" << endl;
    cout << "Tamanho do texto codificado: " << huffman->getBytes() << " bytes" << endl;
    cout << "Houve uma diferenca de " << 448-huffman->getBytes() << " bytes." << endl;
}

int main()
{
    testarHashPalavras();
    cout << endl;
    testarHuffman();

    return 0;
}
