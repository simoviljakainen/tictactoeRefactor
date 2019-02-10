#include "tictactoe.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"

void print_stage(char board[ROWS][COLUMNS]);
void print_invalid_move();
void print_ask_for_move(char player);
void print_winner(char board[ROWS][COLUMNS], char player);
void print_draw(char board[ROWS][COLUMNS]);
