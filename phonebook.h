#ifndef PHONEBOOK_PHONEBOOK_H
#define PHONEBOOK_PHONEBOOK_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define CHUNK 256

struct contact {
    char *name;
    char *surname;
    char *number;
    struct contact *next;
};

typedef struct contact Contact;

void add_contact(void **, void *);
int remove_contact(void **, char *);
void print_phonebook(void *);
char *to_string(void *);

#endif //PHONEBOOK_PHONEBOOK_H
