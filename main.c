#include "ui.h"

int main() {
    title();                                    // Titolo.
    int ch;                                     // Variabile contenente la scelta.
    /*
     * L'astrazione dei dati permette in C un basso livello di information hiding. Infatti, il tipo del puntatore non viene
     * specificato ma viene posto a void. Non si ha invece un livello di incapsulamento tale da non permettere al main o
     * altre funzioni di accedere direttamente ai dati della struttura.
     * */
    void *head = NULL;              // Head della lista posto a NULL (lista vuota).

    do {
        ch = choose_option();                   // Scelta operazione da eseguire.
        // Switch per l'esecuzione delle funzioni associate
        switch (ch) {
            case 1:
                header_table();
                print_phonebook(head);
                break;

            case 2:
                add_contact(&head, create_new_contact());
                break;

            case 3:
                if (remove_contact(&head, get_key_cmp()))               // Controllo e feedback eliminazione
                    printf("Contact eliminated from list.\n");
                else
                    printf("Contact not found.\n");
                break;

            default:    // Default non necessario. Messo per eliminare un warning.
                printf("Option not included.\n");
        }
    } while (ch != 4);  // Ripetizione menu fino a quando non si esce dal programma.

    return EXIT_SUCCESS;
}

