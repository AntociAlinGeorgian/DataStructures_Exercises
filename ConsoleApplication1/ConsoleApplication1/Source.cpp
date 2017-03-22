#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student {
	char* nume;
	int id;
};

struct Nod {
	Student* infoUtil;
	Nod* next;
	Nod* prev;
};

struct Lista {
	Nod* ultim;
	Nod* prim;
};

Nod* creareNod(Student* stud) {
	Nod* nou = (Nod*)malloc(sizeof(Nod));
	nou->infoUtil = stud;
	nou->next = NULL;
	nou->prev = NULL;

	return nou;
}

Lista* initializareLista() {
	Lista* lista = (Lista*)malloc(sizeof(Lista));
	lista->prim = NULL;
	lista->ultim = NULL;

	return lista;
}

void inserareInceput(Lista*& lista, Nod* nod) {
	if (lista->prim == NULL) {
		lista->prim = lista->ultim = nod;
	}
	else {
		nod->next = lista->prim;
		lista->prim->prev = nod;
		lista->prim = nod;

		lista->ultim->next = lista->prim;
		lista->prim->prev = lista->ultim;
	}
}


void inserareSfarsit(Lista*& lista, Nod* nod) {
	if (lista->ultim == NULL) {
		lista->prim = lista->ultim = nod;
	}
	else {
		nod->prev = lista->ultim;
		lista->ultim->next = nod;
		lista->ultim = nod;

		lista->ultim->next = lista->prim;
		lista->prim->prev = lista->ultim;

	}
}

void parcurgereLista(Lista* lista) {
	if (lista) {
		Nod* primulNod = lista->prim;

		printf("%d - %s \n", primulNod->infoUtil->id, primulNod->infoUtil->nume);
		primulNod = primulNod->next;

		while (primulNod != NULL && primulNod != lista->prim) {
			printf("%d - %s\n", primulNod->infoUtil->id, primulNod->infoUtil->nume);
			primulNod = primulNod->next;
		}
	}
}

void citireFisier(Lista*& lista) {
	FILE* f = fopen("Text.txt", "r");
	if (f) {
		while (!feof(f)) {
			Student* s = (Student*)malloc(sizeof(Student));
			fscanf(f, "%d", &s->id);
			char buffer[100];
			fscanf(f, "%s", &buffer);
			s->nume = (char*)malloc(strlen(buffer) + 1);
			strcpy(s->nume, buffer);

			Nod* nod = creareNod(s);
			//inserareInceput(lista, nod);

			inserareSfarsit(lista, nod);
		}
	}
}


void main() {
	Lista* lista = initializareLista();
	citireFisier(lista);
	parcurgereLista(lista);
	printf("%d. %s", lista->prim->infoUtil->id, lista->prim->infoUtil->nume);
	printf("%d. %s", lista->ultim->infoUtil->id, lista->ultim->infoUtil->nume);
}