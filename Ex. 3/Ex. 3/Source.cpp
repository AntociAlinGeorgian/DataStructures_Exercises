/*
a) O funcție pentru inserarea unei date într-o listă liniară dublu înlănțuită după ultima apariție a unei valori y primită ca parametru 
(dacă y nu există inserarea se realizează la sfârșit). Informația utilă a elementelor listei este de tip întreg.
b) O funcție care să determine ponderea unei valori primită ca parametru în cadrul listei.
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

void insertNode(Node*& lst, Node* nod, int val) {
	if (lst == NULL) {
		lst = nod;
	}
	else {
		int exist = 0;
		Node* tmp = lst;
		Node* tmp1 = lst;
		while (tmp1->next != NULL) {
			if (tmp1->info == val) {
				exist = 1;
			}
			tmp1 = tmp1->next;
		}
		if (exist == 0) {
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			tmp->next = nod;
			nod->prev = tmp;
		}
		else {
			while (tmp->next != NULL && tmp->info != val) {
				tmp = tmp->prev;
			}
			nod->next = tmp->next;
			nod->prev = tmp;
			tmp->next->prev = nod;
			tmp->next = nod;
		}
	}
}

void printList(Node* lst) {
	if (lst) {
		Node* tmp = lst;
		while (tmp->next != NULL) {
			printf("%d ", tmp->info);
			tmp = tmp->next;
		}
		printf("%d ", tmp->info);
	}
	else {
		printf("NULL list.");
	}
}

void weight(Node* lst, int val) {
	if (lst) {
		int countNr = 0;
		int countElements = 0;
		float weight;
		while (lst->next != NULL) {
			if (lst->info == val) {
				countNr++;
			}
			countElements++;
			lst = lst->next;
		}
		countElements = countElements + 1;
		weight = (countNr * 100 )/ countElements;
		printf("Ponderea nr. %d este de %5.0f procente.\n", val, weight);
	}
	else {
		printf("NULL list.");
	}
}


void main() {
	Node* lst = nullptr;
	int nr;
	int poz;
	printf("Numar: ");
	scanf("%d", &nr);
	printf("Inserat dupa pozitia: ");
	scanf("%d", &poz);
	Node* nod = createNode(nr);
	insertNode(lst, nod, poz);

	for (int i = 0; i < 3; i++) {
		printf("Numar: ");
		scanf("%d", &nr);
		printf("Inserat dupa valoarea: ");
		scanf("%d", &poz);
		nod = createNode(nr);
		insertNode(lst, nod, poz);
	}

	printList(lst);
	weight(lst, 1);
}