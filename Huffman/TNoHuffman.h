#ifndef TNOHUFFMAN_H_INCLUDED
#define TNOHUFFMAN_H_INCLUDED

class TNoHuff {
public:
    int frequencia;
    char dado;
    TNoHuff* esquerda;
    TNoHuff* direita;
    string codificacao;

    TNoHuff() {
        this->frequencia = 0;
        this->dado = ' ';
        this->esquerda = nullptr;
        this->direita = nullptr;
        this->codificacao = "";
    }

    TNoHuff(char dado, int frequencia) {
        this->dado = dado;
        this->frequencia = frequencia;
        this->esquerda = nullptr;
        this->direita = nullptr;
        this->codificacao = "";
    }

    TNoHuff(char dado, int frequencia, TNoHuff* esquerda, TNoHuff* direita) {
        this->dado = dado;
        this->frequencia = frequencia;
        this->esquerda = esquerda;
        this->direita = direita;
        this->codificacao = "";
    }
};

#endif // TNOHUFFMAN_H_INCLUDED
