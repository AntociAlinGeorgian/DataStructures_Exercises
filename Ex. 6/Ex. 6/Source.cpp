/*
a) O funcție pentru inserarea unei date într-o listă liniară simplu înlănțuită între primele două noduri din cadrul listei 
(dacă acestea nu există se va insera la sfârșit).
Informația utilă a elementelor listei este de tip întreg.

b) O funcție care să determine dacă o valoare primită ca parametru se regăsește în listă în mai mult de 30% din noduri.
*/

#include<iostream>
#include<stdio.h>

struct Nod {
	int info;
	Nod* next;
};

Nod* createNode(int nr) {
	Nod* nod = new Nod;
	nod->info = nr;
	nod->next = NULL;
	return nod;
}

void insertNode(Nod*& lst, Nod* nod) {
	if (lst == NULL) {
		lst = nod;
	}
	else {
		if (lst->next == NULL) {
			lst->next = nod;
		}
		else {
			Nod* tmp = lst;
			nod->next = tmp->next;
			tmp->next = nod;
		}
	}
}

void parcurgere(Nod* lst) {
	if (lst == NULL) {
		printf("lst null.");
	}
	else {
		while (lst->next != NULL) {
			printf("%d \n", lst->info);
			lst = lst->next;
		}
		printf("%d \n", lst->info);
	}
}

void main() {
	Nod* lst = nullptr;
	Nod* n = createNode(1);
	insertNode(lst, n);

	n = createNode(2);
	insertNode(lst, n);

	n = createNode(3);
	insertNode(lst, n);

	n = createNode(4);
	insertNode(lst, n);

	parcurgere(lst);
}