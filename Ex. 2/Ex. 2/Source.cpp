/*
a) O funcție pentru inserarea unei date într-o listă liniară simplu înlănțuită care să permită gruparea
valorilor impare și pare. Valorile pare sunt inserate în prima jumătate la începutul liste iar cele impare
în a doua jumătate la sfârșitul listei. Informația utilă a elementelor listei este de tip întreg.
b) O funcție care să determine numărul de elemente pare și impare din listă.
*/

#include<iostream>
#include<stdio.h>

struct Node {
	int info;
	Node* next;
};

Node* createNode(int nr) {
	Node* nod = new Node;
	nod->info = nr;
	nod->next = NULL;
	return nod;
}

void insertNode(Node*& lst, Node* nod) {
	if (lst==NULL) {
		lst = nod;
	}
	else {
		if (nod->info % 2 == 0) {
			nod->next = lst;
			lst = nod;
		}
		else if (nod->info % 2 == 1) {
			Node* tmp = lst;
			while (tmp->next != NULL) {
				tmp = tmp->next;
			}
			tmp->next = nod;
		}
	}
}

void printList(Node* lst) {
	if (lst) {
		Node* tmp = lst;
		while (tmp != NULL) {
			printf(" %d ", tmp->info);
			tmp = tmp->next;
		}
		printf("\n");
	}
}


void readFromFile(Node*& lst) {
	FILE* f = fopen("Text.txt", "r");
	if (f) {
		while (!feof(f)) {
			int nr;
			fscanf(f, "%d", &nr);
			Node* n = createNode(nr);
			insertNode(lst, n);
		}
	}
}

void countEvenOdd(Node* lst) {
	if (lst) {
		int odd = 0;
		int even = 0;
		Node* tmp = lst;

		while (tmp != NULL) {
			if (tmp->info % 2 == 0) {
				even++;
			}
			else if (tmp->info % 2 == 1) {
				odd++;
			}
			tmp = tmp->next;
		}
		printf("Even nr: %d \n", even);
		printf("Odd nr: %d \n", odd);
	}
}

void main() {
	Node* lst = nullptr;
	readFromFile(lst);
	printList(lst);
	countEvenOdd(lst);
}