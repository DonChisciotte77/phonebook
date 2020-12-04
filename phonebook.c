#include "phonebook.h"

void add_contact(void **head, void *this) {
    Contact *last = (Contact *) *head;
    Contact *new_contact = (Contact *) this;

    if (*head == NULL) {
        *head = this;
        return;
    }

    if (last->next == NULL) {
        last->next = new_contact;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_contact;
}

int remove_contact(void **this, char *key) {
    Contact *head = (Contact *) *this, *temp;

    if (head != NULL && (strcmp(head->number, key) == 0)) {
        *this = head->next;
        free(head);
        return 1;
    }

    while (head->next != NULL && (strcmp(head->number, key) != 0)) {
        temp = head;
        head = head->next;
    }

    if (head == NULL) return 0;

    temp -> next = head -> next;
    free(head);
    return 1;
}

void print_phonebook(void *this) {
    Contact *contact = (Contact *) this;
    int i = 1;

    while (contact != NULL) {
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

char *to_string(void *this) {
    Contact *contact = (Contact *) this;
    char *buffer = (char *) malloc(CHUNK);

    int n = sprintf(buffer, "%s %s: %s", contact->surname, contact->name, contact->number);

    return n > 0 ? buffer : NULL;
}

