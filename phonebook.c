// ----------------------------- Direttive
// ------------ Include
#include "phonebook.h"

// ----------------------------- Procedure e funzioni
/*
 * Aggiunta nuovo contatto alla lista.
 * Riceve come parametro un puntatore a puntatore e un puntatore, entrambi di tipo void.
 * Il primo parametro serve per modificare la struttura passata dal main (side effect), mentre il secondo
 * è il nuovo contatto da aggiungere.
 * */
void add_contact(void **head, void *this) {
    Contact *last = (Contact *) *head;
    Contact *new_contact = (Contact *) this;

    if (*head == NULL) {                        // Se non esistono elementi, allora il nuovo contatto sarà il primo
        *head = this;
        return;
    }

    if (last->next == NULL) {                   // Se è il secondo elemento si aggiunge direttamente
        last->next = new_contact;               // Una volta
        return;
    }

    while (last->next != NULL)                  // Altrimenti si itera la lista fino a raggiungere l'ultimo elemento
        last = last->next;

    last->next = new_contact;                   // Aggiunta alla lista
}

/*
 * Rimozione contatto dalla lista. Come parametro un puntatore a puntatore che si riferisce alla struttura
 * passata dal main. Come nell'aggiunta contatto, il puntatore a puntatore serve come rifermento alla struttura iniziale.
 * Il secondo parametro è una stringa letta da console che verrà confrontata con i numeri di telefono contenuti nelle
 * strutture. La funzione restituisce 1 se la struttura è stata trovata ed eliminata, 0 se non è stata trovata.
 * */
int remove_contact(void **this, char *key) {
    Contact *head = (Contact *) *this, *temp;

    if (head != NULL && (strcmp(head->number, key) == 0)) {             // Se è il primo elemento della lista allora
        *this = head->next;                                             // associa la struttura successiva come la prima
        free(head);                                                     // della lista ed elimina la prima.
        return 1;
    }

    // temp è un puntatore indirizzato alla struttura precedente
    if (head != NULL) {
        while (head->next != NULL &&
               (strcmp(head->number, key) != 0)) {                      // In caso contrario si itera la lista fino a trovare
            temp = head;                                                // la struttura.
            head = head->next;
        }
    }

    if (head == NULL) return 0;                                         // Se non è stata trovata head è NULL e ritorna 0.

    temp -> next = head -> next;                                        // Altrimenti si associa alla struttura precedente
    free(head);                                                         // l'indirizzo di quella successiva.
    return 1;
}

/*
 * Stampa a video della lista. Il puntatore void è riferito alla prima struttura della lista.
 * Se la lista è vuota ritorna direttamente alla chiamante.
 * */
void print_phonebook(void *this) {
    Contact *contact = (Contact *) this;
    int i = 1;

    while (contact != NULL) {                                           // Iterazione fino alla fine
        char *str = to_string(contact);

        if (str == NULL) {
            printf("Unable to print contact information.\n");
            exit(-1);
        } else
            printf("\n%d) %s.", i, str);

        i++;
        contact = contact->next;
    }
    printf("\n");
}

/*
 * Funzione che ritorna come un'unica stringa la concatenazione dei campi (tutti di tipo stringa) della struttura puntata
 * dal puntatore. La funzione ritorna NULL in caso di errori della sprintf.
 * */
char *to_string(void *this) {
    Contact *contact = (Contact *) this;
    char *buffer = (char *) malloc(CHUNK);

    // sprintf facilita molto la concatenazione
    int n = sprintf(buffer, "%s %s: %s", contact->surname, contact->name, contact->number);

    return n > 0 ? buffer : NULL;
}

// Getter e setter per "incapsulamento"
char *get_name(void *this) {
    Contact *contact = (Contact *) this;
    return contact->name;
}

char *get_surname(void *this) {
    Contact *contact = (Contact *) this;
    return contact->surname;
}

char *get_number(void *this) {
    Contact *contact = (Contact *) this;
    return contact->number;
}

Contact *get_next(void *this) {
    Contact *contact = (Contact *) this;
    return contact->next;
}

void *set_name(void *this, char *value) {
    Contact *contact = (Contact *) this;
    contact->name = value;
}

void *set_surname(void *this, char *value) {
    Contact *contact = (Contact *) this;
    contact->surname = value;
}

void *set_number(void *this, char *value) {
    Contact *contact = (Contact *) this;
    contact->number = value;
}

void *set_next(void *this, Contact *value) {
    Contact *contact = (Contact *) this;
    contact->next = value;
}

