// ----------------------------- Direttive
// ------------ Include
#include "ui.h"

// ----------------------------- Procedure e funzioni
void title() {
    printf("<------------[ PHONEBOOK ]------------>\n");
}

void menu() {
    printf("\n<-------- [MENU'] -------->\n");
    printf("1) View all contacts;\n");              // Visualizzazione contatti
    printf("2) Add new contact;\n");                // Aggiungi contatto
    printf("3) Delete contact;\n");                 // Rimuovi contatto
    printf("4) Exit.\n");                           // Termina programma
}

/* Funzione che ritorna il valore dell'operazione scelta. Si controlla
 * che il valore sia compreso tra 1 e 4. In input si riceve una stringa poi
 * convertita in long (casting a int) attraverso strtol. Si è deciso di usare
 * questo metodo per un maggior controllo dell'input. CHUNK è definito in phonebook.h
 * e vale 256. Per il controllo della calloc si è creata una funzione a parte che verifica
 * se si son verificati errori durante la chiamata della calloc.
 * */
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

// Stampa a video del titolo e header della lista dei contatti
void header_table() {
    printf("\n<------ [LIST] ------>\n");
    printf("N. | Surname | Name | Tel. number");
}

/* Lettura in input dei valori da inserire nella nuova struttura da aggiungere
 * alla lista. La lettura viene eseguita da una funzione che non si limita a chiamare la
 * fgets ma eliminare pure '\n' alla fine della stringa inserita. Questa istruzione è
 * necessaria al fine di ottenere valori coerenti (la fgets memorizza nel buffer anche il
 * carattere new line). Per l'eliminazione della new line si è usato strcspn per trovare
 * la posizione del carattere '\n' (strcspn ritorna il numero di caratteri letti fino
 * alla prima occorrenza di quello indicato).*/
void *create_new_contact() {
    Contact *temp = (Contact *) errchecked_calloc(1, sizeof(Contact));

    printf("\n<------ [NEW CONTACT] ------>\n");

    //temp -> name = get_string_value("Name");
    set_name(temp, get_string_value("Name"));
    //temp -> surname = get_string_value("Surname");
    set_surname(temp, get_string_value("Surname"));
    //temp -> number = get_string_value("Telephone number");
    set_number(temp, get_string_value("Telephone number"));
    //temp -> next = NULL;    // La struttura verrà aggiunta alla fine della lista.
                            // Per questo è posto a NULL il puntatore alla prossima struct.
    set_next(temp, NULL);

    return (void *) temp;
}

// Input del numero di telefono da ricercare e stampa del titolo del sottomenù.
char *get_key_cmp() {
    printf("\n<------ [REMOVE CONTACT] ------>\n");

    return get_string_value("Insert tel. number");
}

// Lettura della stringa in input
char *get_string_value(char *what) {
    char *buffer = (char *) errchecked_calloc(CHUNK, sizeof(char));

    do {
        printf("%s:", what);
    } while (!fgets(buffer, CHUNK, stdin));

    // Rimozione '\n'
    buffer[strcspn(buffer, "\n")] = 0;
    return buffer;
}

// Controllo che la calloc non ritorni un puntatore a null
void *errchecked_calloc(size_t size, size_t type) {
    void *ptr;

    ptr = calloc(size, type);

    if (ptr == NULL) {
        perror("Calloc failed");
        exit(-1);
    }

    return ptr;
}
