#include <stdio.h>
#include "players.h"

int player_input() {
    char input;

    if (fgets(&input, 2, stdin) == NULL) {
        printf("No input was given.\n");
        return -1;
    }

    avoid_reading_more_chars();

    return index_of_input(input);
}

void avoid_reading_more_chars() {
    while (getchar() != EOF);
}

int index_of_input(char input) {

    switch (input) {
        case 'q':
            return 0;
        case 'w':
            return 1;
        case 'e':
            return 2;
        case 'a':
            return 3;
        case 's':
            return 4;
        case 'd':
            return 5;
        case 'z':
            return 6;
        case 'x':
            return 7;
        case 'c':
            return 8;
    }

    return -1;
}

int make_move(char board[][COLUMNS], char player, int player_input) {
    int row = player_input / COLUMNS;
    int column = player_input % COLUMNS;

    if (player_input >= 0 && board[row][column] == ' ') {
        board[row][column] = player;
        return 1;

    } else {
        return 0;
    }
}
