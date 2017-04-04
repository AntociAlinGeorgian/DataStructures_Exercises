/*
a) O funcție pentru inserarea unei date într-o listă liniară simplu înlănțuită astfel încât lista să rămână sortată descrescător.
Informația utilă a elementelor listei este de tip întreg.

b) O funcție care să determine numărul de elemente din intervalul [x,y] divizibile cu k.
*/
#include<iostream>
#include<stdio.h>

struct Nod {
	int info;
	Nod* next;
};

Nod* creareNod(int nr) {
	Nod* nod = new Nod;
	nod->info = nr;
	nod->next = NULL;
	return nod;
}

void insertNode(Nod*& lst, Nod* nod) {
	if (lst == NULL || lst->info<=nod->info) {
		nod->next = lst;
		lst = nod;
	}
	else {
		Nod* tmp = lst;
		while (tmp->next != NULL && tmp->next->info > nod->info) {
			tmp = tmp->next;
		}
		nod->next = tmp->next;
		tmp->next = nod;
	}
}

void parcurgere(Nod* lst) {
	if (lst == NULL) {
		printf("Lista null");
	}
	else {
		Nod* tmp = lst;
		while (tmp->next != NULL) {
			printf("%d \n", tmp->info);
			tmp = tmp->next;
		}
		printf("%d \n", tmp->info);
	}
}

void main() {
	Nod* lst = nullptr;
	Nod* n = creareNod(1);
	insertNode(lst, n);

	n = creareNod(2);
	insertNode(lst, n);

	n = creareNod(4);
	insertNode(lst, n);

	n = creareNod(3);
	insertNode(lst, n);

	n = creareNod(0);
	insertNode(lst, n);

	parcurgere(lst);


}