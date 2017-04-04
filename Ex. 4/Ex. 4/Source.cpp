/*
a) O funcție pentru inserarea unei date într-o listă liniară dublu înlănțuită astfel încât lista să rămână sortată crescător.
Informația utilă a elementelor listei este de tip întreg.

b) O funcție recursivă care să determine numărul de elemente mai mici decât o valoare primită ca parametru.
*/

#include<iostream>
#include<stdio.h>

struct Node {
	int info;
	Node* next;
	Node* prev;
};

Node* createNode(int nr) {
	Node* nod = new Node;
	nod->info = nr;
 	nod->next = NULL;
	nod->prev = NULL;
	return nod;
}

void inserareNod(Node*& lst, Node* nod) {
	if (lst == NULL || lst->info >= nod->info) {
		nod->next = lst;
		lst = nod;
	}
	else {
		Node* tmp = lst;

		while (tmp->next != NULL && tmp->next->info < nod->info) {
			tmp = tmp->next;
		}
		nod->next = tmp->next;
		tmp->next = nod;
		nod->prev = tmp;
	}
}

void parcurgere(Node* lst) {
	Node* tmp = lst;
	while (tmp->next != NULL) {
		printf("%d \n", tmp->info);
		tmp = tmp->next;
	}
	printf("%d \n", tmp->info);
}

void countNr(Node* lst, int nr) {
	if (lst == NULL) {
		printf("Lista NULL.");
	}
	else {
		int count = 0;
		while (lst->next != NULL && lst->info < nr) {
			count++;
			lst = lst->next;
		}
		if (lst->info < nr) {
			count++;
		}
		
		printf("Exista %d numere mai mici decat %d in lista. \n",count,nr);
	}
}

void main() {

	Node* lst = nullptr;

	Node* n = createNode(1);
	inserareNod(lst, n);

	n = createNode(2);
	inserareNod(lst, n);

	n = createNode(3);
	inserareNod(lst, n);

	n = createNode(5);
	inserareNod(lst, n);

	n = createNode(4);
	inserareNod(lst, n);

	n = createNode(0);
	inserareNod(lst, n);

	n = createNode(2);
	inserareNod(lst, n);

	n = createNode(1);
	inserareNod(lst, n);

	

	parcurgere(lst);

	countNr(lst,6);
}