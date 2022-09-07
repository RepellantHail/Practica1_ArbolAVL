#pragma once
#include <stdio.h>
#include <iostream>
#include<algorithm>

template <typename itemType>
class Nodo
{
private:
	itemType value= NULL;
	Nodo* left=nullptr;
	Nodo* right=nullptr;
public:
	Nodo* root=nullptr;

	Nodo() {
		this->root = NULL;
	}

	Nodo(const itemType& v) {
		value = v;
		left = nullptr;
		right = nullptr;
	}

	
	Nodo* push(Nodo* nodo,const itemType& dato) {
		if (nodo == NULL) {
			Nodo* aux = new Nodo;
			aux->value = dato;
			aux->left = nullptr;
			aux->right = nullptr;
			nodo = aux;
			return nodo;
		}
		else {
			if (dato < nodo->value) {
				nodo->left = push(nodo->left, dato);
				nodo = balanceo(nodo);
			}
			else {
				nodo->right = push(nodo->right, dato);
				nodo = balanceo(nodo);
			}
		}
		return nodo;
	}

	/*
		void push(const itemType& dato) {
		if (dato == value)
			std::cout << "Dato repetido\n" << dato << "\nIngrese otro\n" << std::endl;
		else {
			if (dato > value) {
				if (right == nullptr) {
					right = new Nodo(dato);
					balanceo(this);
				}
				else {
					right->push(dato);
				}
			}
			else {
				if (left == nullptr) {
					left = new Nodo(dato);
					balanceo(this);
				}
				else {
					left->push(dato);
				}
			}
		}
	}
	*/

	
	void postOrder(Nodo* nodo) {
		//izq, der, root
		if (nodo == NULL)
			return;
		postOrder(left);
		postOrder(right);
		std::cout << nodo->value << " ";
	}

	
	void preOrder(Nodo* nodo) {
		//raiz, izq, der
		if (nodo == NULL)
			return;
		std::cout << nodo->value << " ";
		preOrder(nodo->left);
		preOrder(nodo->right);
	}

	
	void inOrder(Nodo* nodo) {
		// izq, raiz, derecha
		if (nodo == NULL)
			return;
		inOrder(nodo->left);
		std::cout << nodo->value << " ";
		inOrder(nodo->right);
	}

	
	const itemType& buscador(bool& flag, const itemType& dato) {
		if (flag != true && this != root) {
			if (dato == root->value)
				flag = true;
			if (root->value > dato)
				root->left->buscador(flag, dato);
			root->right->buscador(flag, dato);
		}
		return value;
	}

	
	void buscar(const itemType& dato) {
		bool flag = false;
		buscador(flag, dato);
		if (flag)
			std::cout << "Dato encontrado :" << dato << std::endl;
		else
			std::cout << "Dato no encontrado :" << dato << std::endl;
	}

	
	Nodo* imprimir(Nodo* nodo,int longitud) {
		if (nodo != NULL) {
			imprimir(nodo->right,longitud + 2);
			for (int i = 0; i < longitud; i++)
				std::cout << " ";
			std::cout << nodo->value << std::endl;
			imprimir(nodo->left, longitud + 2);
		}
		return nodo;
	}

	

	//AVL

	int altura(Nodo* nodo) {
		int alt = 0;
		if (nodo != NULL) {
			int altIzq = altura(nodo->left);
			int altDer = altura(nodo->right);
			int altMax = std::max(altIzq, altDer);
			alt = altMax + 1;
		}
		return alt;
	}

	int diferencia(Nodo* nodo) {
		int altIzq = altura(nodo->left);
		int altDer = altura(nodo->right);
		int factorBalanceo = altIzq - altDer;
		return factorBalanceo;
	}

	
	Nodo* balanceo(Nodo* nodo) {
		int factorBalanceo = diferencia(nodo);
		if (factorBalanceo > 1) {
			if (diferencia(nodo->left) > 0)
				nodo = rotacionLL(nodo);
			else
				nodo = rotacionLR(nodo);
		}
		else if (factorBalanceo < -1) {
			if (diferencia(nodo->right) > 0)
				nodo = rotacionRL(nodo);
			else
				nodo = rotacionRR(nodo);
		}
		return nodo;
	}

	
	Nodo* rotacionLL(Nodo* nodo) {
		Nodo* aux;
		aux = nodo->left;
		nodo->left = aux->right;
		aux->right = nodo;
		return aux;
	}

	
	Nodo* rotacionLR(Nodo* nodo) {
		Nodo* aux;
		aux = nodo->left;
		nodo->left = rotacionRR(aux);
		return rotacionLL(nodo);
	}

	
	Nodo* rotacionRR(Nodo* nodo) {
		Nodo* aux;
		aux = nodo->right;
		nodo->right = aux->left;
		aux->left = nodo;
		return aux;
	}

	
	Nodo* rotacionRL(Nodo* nodo) {
		Nodo* aux;
		aux = nodo->right;
		nodo->right = rotacionLL(aux);
		return rotacionRR(nodo);
	}

};
