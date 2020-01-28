#ifndef TEXTREADER_H_INCLUDED
#define TEXTREADER_H_INCLUDED

#include <iostream>
#include "ListaEncadeada.h"
#include <fstream>

using namespace std;

string readText()
{
    ifstream texto("text.txt");
    string linha;
    string tString;

    if (texto.is_open())
    {
        while (!texto.eof())
        {
            getline(texto, linha);
            tString.append(linha);
        }
    }

    return tString;
}

ListaEncadeada<string>* catchWords(string tString)
{
    ListaEncadeada<string>* listaPalavra = new ListaEncadeada<string>;
    string aux = "";
    for (unsigned int i = 0;i < tString.size();i++)
    {
        if ((tString[i] > 64 && tString[i] < 91) || (tString[i] > 96 && tString[i] < 123) || tString[i] == 45) {
            aux += tString[i];
        }

        else {
            if (aux != ""){
                listaPalavra->inserirListaEnd(aux);
                aux = "";
            }
        }

    }
    return listaPalavra;
}

#endif // TEXTREADER_H_INCLUDED
