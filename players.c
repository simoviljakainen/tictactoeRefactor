#include <stdio.h>

#include "players.h"

int player_input()
{
  char input;
  scanf(" %c2", &input);

  avoid_reading_more_chars();
  return index_of_input(input);
}

void avoid_reading_more_chars()
{
  while ('\n'!=getchar());
}

int index_of_input(char input)
{
  switch ((int)input)
  {
    case 113:
      return 0;
    case 119:
      return 1;
    case 101:
      return 2;
    case 97:
      return 3;
    case 115:
      return 4;
    case 100:
      return 5;
    case 122:
      return 6;
    case 120:
      return 7;
    case 99:
      return 8;
  }
  return -1;
}

int make_move(char board[ROWS][COLUMNS], char player, int player_input)
{
    int row = player_input / COLUMNS;
    int column = player_input % COLUMNS;
    int valid_move = player_input >= 0 && board[row][column] == ' ';
    if (valid_move)
    {
      board[row][column] = player;
      return 1;
    }
    else
    {
      return 0;
    }
}
