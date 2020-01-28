#pragma once
#include <iostream>
#include "TNoHuffman.h"


template<class T>
struct TelementoE {
	T dado;
	TelementoE<T>* prox = nullptr;
};


template<class T>
class ListaEncadeada {
public:
	TelementoE<T>* start;
	int quantidade = 0;

	void inserirListaStart(T entrada) {
		TelementoE<T>* novoElemento = new TelementoE<T>;
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

	void inserirListaEnd(T entrada) {
		TelementoE<T>* novoElemento = new TelementoE<T>;
		novoElemento->dado = entrada;
		if (this->quantidade == 0) {
			return inserirListaStart(entrada);
		}

		TelementoE<T>* elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			if (elementoAtual->prox == nullptr) {
				elementoAtual->prox = novoElemento;
				quantidade++;
				return;
			}
			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}
	}

	void inserirListaIndex(T entrada, int index) {
		TelementoE<T>* novoElemento = new TelementoE<T>;
		novoElemento->dado = entrada;

		if (index >= quantidade - 1) return inserirListaEnd(entrada);
		if (this->quantidade == 0 || index == 0) return inserirListaStart(entrada);

		TelementoE<T> * elementoAtual = start;
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

	T removerListaStart() {
		if (quantidade == 0) return NULL;
		TelementoE<T> * aux = start;
		start = aux->prox;
		quantidade--;
		return aux->dado;
	}

	T removerListaEnd() {
		if (quantidade <= 1) {
			return removerListaStart();
		}
		TelementoE<T>* elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			if (i == quantidade - 2) {
				TelementoE<T>* aux = elementoAtual->prox;
				elementoAtual->prox = nullptr;
				quantidade--;
				return aux->dado;
			}
			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}

	}

	T removerListaIndex(int index) {
		if (this->quantidade == 0) return NULL;

		if (index == 0) return removerListaStart();

		if (index == quantidade - 1) return removerListaEnd();

		TelementoE<T>* elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			if (i == index - 1) {
				TelementoE<T>* aux = elementoAtual->prox;
				elementoAtual->prox = aux->prox;
				quantidade--;
				return aux->dado;
			}
			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}
	}

	bool verificaExistencia(T dado) {
		TelementoE<T>* elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			if (dado == elementoAtual->dado) {
				return true;
			}
			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}
		return false;
	}

	T retornaDado(int index) {
		if (quantidade == 0 || quantidade - 1 < index) return NULL;
		TelementoE<T> * elementoAtual = start;
		for (int i = 0; i < quantidade; i++) {
			if (i == index) {
				return elementoAtual->dado;
			}
			if (elementoAtual->prox != nullptr) elementoAtual = elementoAtual->prox;
		}
		return false;
	}

	void exibeLista() {
		if (quantidade == 0) return;
		TelementoE<T> elementoAtual = *start;
		for (int i = 0; i < quantidade; i++) {
			std::cout << elementoAtual.dado << std::endl;
			if (elementoAtual.prox != nullptr) elementoAtual = *elementoAtual.prox;
		}
	}


};
