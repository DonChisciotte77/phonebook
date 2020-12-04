#include "ui.h"

int main() {
    title();
    int ch;
    void *head = (Contact *) NULL;

    do {
        ch = choose_option();

        switch (ch) {
            case 1:
                header_table();
                print_phonebook(head);
                break;

            case 2:
                add_contact(&head, create_new_contact());
                break;

            case 3:
                if (remove_contact(&head, get_key_cmp()))
                    printf("Contact eliminated from list.\n");
                break;

            default:
                printf("Option not included.\n");
        }

    } while (ch != 4);

    return EXIT_SUCCESS;
}

