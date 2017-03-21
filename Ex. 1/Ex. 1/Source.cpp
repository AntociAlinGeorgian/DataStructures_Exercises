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


/*
1. b) O funcție care să determine distanța dintre elementele care conțin valoarea maximă și minimă din listă.
*/
void min_max(List* lst, int&min, int&max) {
	List* tmp = lst;

	min = INT_MAX;
	max = INT_MIN;
	bool bool_min = false;
	bool bool_max = false;

	int d = 0;

	while (tmp->first != NULL) {
		if (tmp->first->info < min) {
			min = tmp->first->info;
			bool_min = true;
			if(bool_max==true)
			{
				d++;
			}
			else d = 0;
		}
		
		if (tmp->first->info > max) {
			max = tmp->first->info;
			bool_max = true;
			if (bool_min == true)
			{
				d++;
			}
			else d = 0;
		}
		
		tmp->first = tmp->first->next;
	}
	d--;
	printf("min: %d, max: %d \n", min, max);
	printf("distanta:  %d. \n", d);

	
}

//int distance(List* lst, int min, int max)
//{
//	int i = 0;
//	
//	while (lst->first != NULL) {
//		if (lst->first->info == min) {
//			while (lst->first->info != max) {
//				i=i+1;
//				lst->first = lst->first->next;
//			}
//		}
//		lst->first = lst->first->next;
//	}
//
//	return i;
//}

void main() {
	int min, max;
	List* lst = initializeList();

	Node* n = createNode(11);
	insertFirst(lst, n);

	n = createNode(2);
	insertFirst(lst, n);

	n = createNode(10);
	insertFirst(lst, n);

	n = createNode(3);
	insertFirst(lst, n);

	//n = createNode(3);
	//insertFirst(lst, n);

	printList(lst);

	min_max(lst, min, max);

	//int distanta = distance(lst, min, max);
	
}