#ifndef LISTAHUFFMAN_H_INCLUDED
#define LISTAHUFFMAN_H_INCLUDED
#include <iostream>
#include "TNoHuffman.h"

struct TElementoHuff {
	TNoHuff* dado;
	TElementoHuff* prox = nullptr;
};

class ListaHuffman {
public:
	TElementoHuff* start;
	int quantidade = 0;

	void inserirListaStart(TNoHuff* entrada) {
		TElementoHuff* novoElemento = new TElementoHuff();
		novoElemento->dado = entrada;
		if (this->quantidade == 0) {
			this->start = novoElemento;
			quantidade++;
			return;
		}

		novoElemento->prox = start;
		start = novoElemento;
		quantidade++;
	}

	void inserirListaEnd(TNoHuff* entrada) {
		TElementoHuff* novoElemento = new TElementoHuff();
		novoElemento->dado = entrada;
		if (this->quantidade == 0) {
			return inserirListaStart(entrada);
		}

		TElementoHuff* elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			if (elementoAtual->prox == nullptr) {
				elementoAtual->prox = novoElemento;
				quantidade++;
				return;
			}
			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}
	}

	TNoHuff* removerListaEnd() {
		if (quantidade <= 1) {
			return removerListaStart();
		}
		TElementoHuff* elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			if (i == quantidade - 2) {
				TElementoHuff* aux = elementoAtual->prox;
				elementoAtual->prox = nullptr;
				quantidade--;
				return aux->dado;
			}
			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}

	}

	void inserirListaIndex(TNoHuff* entrada, int index) {
		TElementoHuff* novoElemento = new TElementoHuff();
		novoElemento->dado = entrada;

		if (index >= quantidade - 1) return inserirListaEnd(entrada);
		if (this->quantidade == 0 || index == 0) return inserirListaStart(entrada);

		TElementoHuff* elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			if (i == index - 1) {
				novoElemento->prox = elementoAtual->prox;
				elementoAtual->prox = novoElemento;
				quantidade++;
				return;
			}
			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}
	}

	TNoHuff* removerListaStart() {
		if (quantidade == 0) return NULL;
		TElementoHuff* aux = start;
		start = aux->prox;
		quantidade--;
		return aux->dado;
	}

	TNoHuff* removerListaIndex(int index) {
		if (this->quantidade == 0) return NULL;

		if (index == 0) return removerListaStart();

		if (index == quantidade - 1) return removerListaEnd();

		TElementoHuff* elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			if (i == index - 1) {
				TElementoHuff* aux = elementoAtual->prox;
				elementoAtual->prox = aux->prox;
				quantidade--;
				return aux->dado;
			}
			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}
	}

	bool verificaExistencia(TNoHuff* dado) {
		TElementoHuff* elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			if (dado == elementoAtual->dado) {
				return true;
			}
			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}
		return false;
	}

	TNoHuff* retornaItem(int pos) {
        TElementoHuff* elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			if (i == pos) {
				return elementoAtual->dado;
			}
			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}
		return nullptr;
	}

	void exibeLista() {
		if (quantidade == 0) return;
		TElementoHuff* elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			std::cout << elementoAtual->dado->dado << " " << elementoAtual->dado->frequencia << std::endl;

			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}
	}


	void switchNext(int pos1, int pos2) {
        inserirListaIndex(removerListaIndex(pos1), pos2);
	}
};

#endif // LISTAHUFFMAN_H_INCLUDED
