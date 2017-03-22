/*
O funcție pentru inserarea unei date într-o listă liniară dublu înlănțuită care să nu permită valori
duplicate (dacă valoarea nu există, inserarea se realizează la începutul listei). Informația utilă a
elementelor listei este de tip întreg
*/

#include<iostream>
#include<stdio.h>


struct Nod {
	int info;
	Nod* next;
	Nod* prev;
};


Nod* createNode(int nr) {
	Nod* nod = new Nod;
	nod->info = nr;
	nod->next = NULL;
	nod->prev = NULL;

	return nod;
}


bool checkDuplicates(Nod* lst, int nr) {
	Nod* tmp = lst;
	while (tmp != NULL) {
		if (tmp->info == nr) {
			return true;
		}
		tmp = tmp->next;
	}
	return false;
}

void inserareNodInceput(Nod*& lst, Nod* nou) {
	if (lst == NULL) {
		lst = nou;
	}
	else {
		if (checkDuplicates(lst, nou->info) == false) {
			nou->next = lst;
			lst->prev = nou;
			lst = nou;
		}
		else {
			printf("Valoarea (%d) exista deja! \n", nou->info);
		}
		
	}
}

void parcurgereLista(Nod* lst) {
	Nod* tmp = lst;
	if (tmp) {
		while (tmp != NULL) {
			printf("%d \n", tmp->info);
			tmp = tmp->next;
		}
	}
}


void main() {
	Nod* lst = nullptr;
	Nod* nou = createNode(1);
	inserareNodInceput(lst, nou);

	nou = createNode(2);
	inserareNodInceput(lst, nou);

	nou = createNode(1);
	inserareNodInceput(lst, nou);

	parcurgereLista(lst);

}