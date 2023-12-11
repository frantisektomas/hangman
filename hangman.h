#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>

#define WORDLIST_FILENAME "words.txt"
#define MAXSTEPS 8

int is_word_guessed(const char secret[], const char letters_guessed[]);
void update_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]);
void get_available_letters(const char letters_guessed[], char available_letters[]);

void hangman(const char secret[]);
int get_word(char secret[]);
