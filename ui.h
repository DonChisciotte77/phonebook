/*
 * Interfaccia della libreria ui.h
 * che si occupa dell'UI del programma.
 * Questa libreria rende il main più pulito, breve
 * e semplice.
 * */
#ifndef PHONEBOOK_UI_H
#define PHONEBOOK_UI_H
#include "phonebook.h"

// ------------------ Prototipi
void title();                       // Titolo del programma
void menu();                        // Menu delle possibili operazioni
int choose_option();                // Scelta operazione da eseguire
void header_table();                // Header della "tabella" lista contatti
void *create_new_contact();         // Input dei nuovi valori e creazione struttura
char *get_key_cmp();                // Input della key (numero di telefono) per la ricerca
                                    // del contatto da eliminare
char *get_string_value(char *);
void *errchecked_calloc(size_t, size_t);
#endif //PHONEBOOK_UI_H