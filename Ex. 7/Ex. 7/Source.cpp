/*
a) O funcție pentru inserarea unei date într-o listă liniară simplu înlănțuită după primele n elemente a căror sumă este mai mare decât valoarea inserată
(dacă nu există cele n elemente, inserarea se realizează la sfârșit).
Informația utilă a elementelor listei este de tip întreg.

b) O funcție recursivă care să determine numărul de elemente mai mici decât o valoare primită ca parametru.
*/

#include<iostream>
#include<stdio.h>

struct Nod {
	int info;
	Nod* next;
};

Nod* createNode(int nr) {
	Nod* n = new Nod;
	n->info = nr;
	n->next = NULL;
	return n;
}

void insertNode(Nod*& lst, Nod* n) {
	if (lst == NULL) {
		lst = n;
	}
	else {
		Nod* tmp = lst;
		int sum = 0;
		while (tmp->next != NULL && (sum <= n->info)) {
			sum = sum + tmp->info;
			tmp = tmp->next;
 		}
		n->next = tmp->next;
		tmp->next = n;
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

void main(){
	Nod* lst = nullptr;
	Nod* n = createNode(1);
	insertNode(lst, n);

	n = createNode(3);
	insertNode(lst, n);

	n = createNode(5);
	insertNode(lst, n);

	n = createNode(7);
	insertNode(lst, n);

	n = createNode(4);
	insertNode(lst, n);


	parcurgere(lst);
}