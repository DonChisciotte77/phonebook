#include "ui.h"

char *get_string_value(char *);
void *errchecked_calloc(size_t, size_t);

void title() {
    printf("<------------[ PHONEBOOK ]------------>\n");
}

void menu() {
    printf("\n<-------- [MENU'] -------->\n");
    printf("1) View all contacts;\n");
    printf("2) Add new contact;\n");
    printf("3) Delete contact;\n");
    printf("4) Exit.\n");
}

int choose_option() {
    int ch, is_valid = 1;
    char *buffer = (char *) errchecked_calloc(CHUNK, sizeof(char));
    char *text;

    if (buffer == NULL) {
        perror("Calloc failed");
        exit(-1);
    }

    do {
        if (is_valid)
            menu();
        else
            printf("Option does not exist.\n");

        printf("Choose an option:");
        if (fgets(buffer, CHUNK, stdin))
            ch = (int) strtol(buffer, &text, 10);

        if (ch < 1 || ch > 4)
            is_valid = 0;
    } while (ch < 1 || ch > 4);

    free(buffer);

    return ch;
}

void header_table() {
    printf("\n<------ [LIST] ------>\n");
}

void *create_new_contact() {
    Contact *temp = (Contact *) errchecked_calloc(1, sizeof(Contact));

    printf("\n<------ [NEW CONTACT] ------>\n");

    temp -> name = get_string_value("Name");
    temp -> surname = get_string_value("Surname");
    temp -> number = get_string_value("Telephone number");
    temp -> next = NULL;

    return (void *) temp;
}

char *get_key_cmp() {
    printf("\n<------ [REMOVE CONTACT] ------>\n");

    return get_string_value("Insert tel. number");
}

char *get_string_value(char *what) {
    char *buffer = (char *) errchecked_calloc(CHUNK, sizeof(char));

    do {
        printf("%s:", what);
    } while (!fgets(buffer, CHUNK, stdin));

    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}

void *errchecked_calloc(size_t size, size_t type) {
    void *ptr;

    ptr = calloc(size, type);

    if (ptr == NULL) {
        perror("Calloc failed");
        exit(-1);
    }

    return ptr;
}
