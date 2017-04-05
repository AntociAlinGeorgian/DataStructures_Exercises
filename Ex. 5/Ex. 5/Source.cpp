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

void countInterval(Nod* lst, int x, int y, int k) {
	if (lst == NULL) {
		printf("lista null.");
	}
	else {
		Nod* tmp = lst;
		Nod* tmp1 = lst;
		int count=0;
		int x_found = 0;
		int y_found = 0;
		/* verificam daca exista capetele intervalelor */
		while (tmp != NULL) {
			if (tmp->info == x) {
				x_found = 1;
			}
			else if (tmp->info == y) {
				y_found = 1;
			}
			tmp = tmp->next;
		}
		if (x_found == 1 && y_found == 1 && x>y) {
			while (tmp1->next != NULL) {
				if (tmp1->info%k == 0) {
					count++;
				}
				tmp1 = tmp1->next;
			}
			printf("Exista %d numere divizibile cu %d in intervalul [%d,%d].\n", count, k, x, y);
		}
		else {
			printf("Selectati intervalul corect!\n");
		}
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

	countInterval(lst, 4, 0, 3);
}