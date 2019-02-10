#include "tictactoe.h"

int player_input();
void avoid_reading_more_chars();
int index_of_input(char input);
int make_move(char board[ROWS][COLUMNS], char player, int player_input);
