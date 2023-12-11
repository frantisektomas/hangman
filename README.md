# pro3zad2

## Introduction
This is a simple implementation of the classic Hangman game in C. The game is designed to run in a console environment and provides a fun way to practice your vocabulary.

## How to Play
1. Compile the source code using a C compiler.
2. Run the executable in the console.
3. Follow the on-screen instructions to guess the hidden word.

## Features
- Randomly selects a word from a predefined list
- Displays the current state of the word with blanks for each unguessed letter
- Keeps track of incorrect guesses and updates the hangman figure accordingly
- Provides feedback on whether a guessed letter is correct or not
- Ends the game when the word is guessed correctly or the hangman figure is complete

## Files
- `hangman.c`: The main source code file.
- `words.txt`: A text file containing a list of words that the game can randomly select.

## Compilation
Use a C compiler to compile the source code. For example:
```bash
gcc hangman.c -o hangman
