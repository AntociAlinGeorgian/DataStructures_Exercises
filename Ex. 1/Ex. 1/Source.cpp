/*
O funcție pentru inserarea unei date într-o listă liniară dublu înlănțuită care să nu permită valori
duplicate (dacă valoarea nu există, inserarea se realizează la începutul listei). Informația utilă a
elementelor listei este de tip întreg
*/

#include<iostream>
#include<stdio.h>


struct Node {
	int info;
	Node* next;
	Node* prev;
};

struct List{
	Node* first;
	Node* last;
};

Node* createNode(int nr) {
	Node* node = new Node;
	node->info = nr;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

List* initializeList() {
	List* lst = new List;
	lst->first = NULL;
	lst->last = NULL;
	
	return lst;
}

bool hasDuplicates(List* lst,int nr) {
	while (lst != NULL) {
		if (lst->first->info == nr)
			return true;
		else
			return false;
	}
}

void insertFirst(List*& lst, Node* node) {
	if (lst->first == NULL) {
		lst->first = lst->last = node;
	}
	else {
		if (hasDuplicates(lst, node->info) == false) {
			node->next = lst->first;
			lst->first->prev = node;
			lst->first = node;
		}
		else {
			printf("The list already contains this value (%d). \n\n", node->info);
		}
	}
}

void printList(List* lst) {
	if (lst == NULL) {
		printf("The list does not exit!\n");
	}
	else {
		printf("Printing the list: \n");
		Node* tmp = lst->first;
		while (tmp != NULL) {
			printf("%d \n", tmp->info);
			tmp = tmp->next;
		}
	}
}



void main() {
	List* lst = initializeList();

	Node* n = createNode(1);
	insertFirst(lst, n);

	n = createNode(2);
	insertFirst(lst, n);

	n = createNode(3);
	insertFirst(lst, n);

	n = createNode(3);
	insertFirst(lst, n);

	printList(lst);
}