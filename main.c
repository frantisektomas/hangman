#include "hangman.h"

void main()
{
    char secret[50];

    if (get_word(secret) == 1) {
	    printf("It is not possible to generate a secret word. Game over.\n");
    } else
        hangman(secret);
    return;
}
