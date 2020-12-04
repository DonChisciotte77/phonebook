#ifndef PHONEBOOK_PHONEBOOK_H
#define PHONEBOOK_PHONEBOOK_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNK 256

// ADT
struct contact {                // Contatto con puntatore a prossima struttura
    char *name;
    char *surname;
    char *number;
    struct contact *next;
};

typedef struct contact Contact;

// ------------------ Prototipi
void add_contact(void **, void *);      // Nuovo contatto aggiunto alla lista
int remove_contact(void **, char *);    // Rimozione nuovo contatto
void print_phonebook(void *);           // Stampa lista
char *to_string(void *);                // Concatenzazione dei campi della struttura (sorta di toString di Java)
// Getter e setter dei campi della struttura. Livello basso di incapsulamento perché le restanti funzioni possono comunque
// accedere direttamente ai dati.
char *get_name(void *);
char *get_surname(void *);
char *get_number(void *);
Contact *get_next(void *);
void *set_name(void *, char *);
void *set_surname(void *, char *);
void *set_number(void *, char *);
void *set_next(void *, Contact *);

#endif //PHONEBOOK_PHONEBOOK_H
