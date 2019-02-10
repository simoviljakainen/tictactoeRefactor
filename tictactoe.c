#include <stdio.h>

#include "tictactoe.h"

#include "grid.h"
#include "rules.h"
#include "players.h"

int main()
{
  char board[ROWS][COLUMNS] =
  {
    {' ', ' ', ' '},
    {' ', ' ', ' '},
    {' ', ' ', ' '}
  };
  char players[PLAYERS] = {'x', 'o'};

  int i;
  for (i = 0; i < 9; i++)
  {
    print_stage(board);

    char current_player = players[(i % 2)];

    print_ask_for_move(current_player);
    int input = player_input();

    int valid_move = make_move(board, current_player, input);
    if (valid_move)
    {
      char winner_player = get_winner(board, i);
      if (winner_player)
      {
        print_winner(board, winner_player);
        return 1;
      }
    }
    else
    {
      print_invalid_move();
      i--;
    }
  }

  print_draw(board);
  return 1;
}
