#include "hangman.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_word_guessed(const char secret[], const char letters_guessed[]) {

    if (secret == NULL) return 0;
    if (letters_guessed == NULL) return 0;
    if (strlen(secret) < 1) return 0;

    for (int i = 0; secret[i] != '\0'; i++) {

        char current_letter = tolower(secret[i]);
        int letter_guessed = 0;

        for (int j = 0; letters_guessed[j] != '\0'; j++) {
            if (tolower(letters_guessed[j]) == current_letter) {
                letter_guessed = 1;
                break;
            }
        }

        if (letter_guessed == 0) return 0;

    }

    return 1;

}

void update_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]) {

    int i, j, secret_length = 0;

    if (guessed_word != NULL) {

        while (secret[secret_length] != '\0') secret_length++;

        for (i = 0; i < secret_length; i++) guessed_word[i] = '_';
        guessed_word[secret_length] = '\0';

        for (i = 0; i < secret_length; i++) {

            int found = 0;

            for (j = 0; letters_guessed[j] != '\0'; j++) {
                if (tolower(secret[i]) == tolower(letters_guessed[j])) {
                    guessed_word[i] = secret[i];
                    found = 1;
                    break;
                }
            }

            if (!found && guessed_word[i] == '_') guessed_word[i] = '_';

        }
    }
}

void get_available_letters(const char letters_guessed[], char available_letters[]) {

    int i, j;

    if (available_letters != NULL) {
        if (letters_guessed != NULL) {

            char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
            int alphabet_lenght = strlen(alphabet);
            int guessed_lenght = strlen(letters_guessed), k = 0;

            for(i = 0; i < alphabet_lenght ; i++) {

                char current_alphabet_letter = tolower(alphabet[i]);
                int letter_guessed = 0;

                for(int j = 0; j < guessed_lenght; j++) {

                    char current_guessed_letter = tolower(letters_guessed[j]);

                    if(current_alphabet_letter == current_guessed_letter) {
                        letter_guessed = 1;
                        break;
                    }
                }

                if(!letter_guessed) {
                    if(k < 26) available_letters[k++] = alphabet[i];
                }

            }
            available_letters[k] = '\0';
        }
    }
}

// function 4
void hangman(const char secret[])
{
    int nc = MAXSTEPS, i, c;
    char letters_guessed[100];
    char available_letters[30];
    char guessed_word[strlen(secret)+1];

    strcpy(available_letters,"abcdefghijklmnopqrstuvwxyz");
    for(i=0; i<strlen(secret); i++)
        guessed_word[i] = '_';
    guessed_word[i] = '\0';

    printf("welcome to HANGMAN!\n");
    printf("I think a word is %d characters long\n",strlen(secret));
    printf("------------------------------------------------------------\n");
    while(!is_word_guessed(secret,letters_guessed) && nc>0){
        printf("You have %d attempts to guess the password\n", nc);
        printf("Useful letters: %s\n",available_letters);
        printf("Enter the guess in writing: ");
        c = getchar();getchar();
        if(strchr(letters_guessed,c) == NULL){
            letters_guessed[strlen(letters_guessed)] = c;
            letters_guessed[strlen(letters_guessed)+1] = '\0';
            get_available_letters(letters_guessed, available_letters);
            if(strchr(secret,c) == NULL){
                printf("Bad choice, this letter is found in the word:");
                nc--;
            }
            else {
                update_guessed_word(secret, letters_guessed, guessed_word);
                printf("Good choice: ");
            }
            for(i=0; i<strlen(guessed_word); i++)
                printf("%c ",guessed_word[i]);
            printf("\n");

        }
        else {
            printf("This letter has already been guessed: ");
            for(i=0; i<strlen(guessed_word); i++)
                printf("%c ",guessed_word[i]);
            printf("\n");
        }

        printf("------------------------------------------------------------\n");
    }
    if(!is_word_guessed(secret,guessed_word))
        printf("\nYou didn't guess.\nThe guessed word was: %s\n",secret);
    else
        printf("\nYou Win!\n");

}

// function 5
int get_word(char secret[]){
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "Folder did not hurry: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        long int random = (rand() % size) + 1;
        fseek(fp, random, SEEK_SET);
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}
