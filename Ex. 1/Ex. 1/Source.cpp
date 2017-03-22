/*
1. a) O funcție pentru inserarea unei date într-o listă liniară dublu înlănțuită care să nu permită valori
duplicate (dacă valoarea nu există, inserarea se realizează la începutul listei). Informația utilă a
elementelor listei este de tip întreg.
b) O funcție care să determine distanța dintre elementele care conțin valoarea maximă și minimă din listă.
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

void insertNode(Nod*& lst, Nod* nou) { //at the beginning
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

void printList(Nod* lst) {
	Nod* tmp = lst;
	if (tmp) {
		while (tmp != NULL) {
			printf("%d \n", tmp->info);
			tmp = tmp->next;
		}
	}
}

/*Finding poz_min*/
int dist_min(Nod* lst, int min) {
	int i = 1;
	while (lst != NULL) {
		if (lst->info == min) {
			return i;
		}
		else {
			i++;
		}
		lst = lst->next;
	}
}

/*Finding poz_max*/
int dist_max(Nod* lst, int max) {
	int i = 1;
	while (lst != NULL) {
		if (lst->info == max) {
			return i;
		}
		else {
			i++;
		}
		lst = lst->next;
	}
}

void distance(Nod* lst) {
	if (lst) {
		/*Finding min and max*/
		Nod* tmp = lst;
		Nod* tmp1 = lst;
		int min = lst->info;
		int max = lst->info;

		while (tmp != NULL) {
			if (tmp->info < min) {
				min = tmp->info;
			}
			if (tmp->info > max) {
				max = tmp->info;
			}

			tmp = tmp->next;
		}

		/*Finding positions*/
		int poz_min = dist_min(lst,min);
		int poz_max = dist_max(lst,max);
		
		
		int dist = poz_min - poz_max;

		if (dist < 0) {
			dist = dist * (-1);
		}

		printf("\n Min: %d [poz: %d] , Max: %d [poz: %d], Distance: %d. \n ", min, poz_min, max, poz_max, dist);


		
	}
	else {
		printf("Null list.\n");
	}
}

void main() {
	Nod* lst = nullptr;
	Nod* nou = createNode(5);
	insertNode(lst, nou);

	nou = createNode(1);
	insertNode(lst, nou);

	nou = createNode(3);
	insertNode(lst, nou);

	nou = createNode(2);
	insertNode(lst, nou);

	printList(lst);

	distance(lst);

}