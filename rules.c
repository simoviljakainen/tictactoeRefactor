#include "tictactoe.h"

int const MIN_PLAYS_FOR_WIN = 4;

typedef char (*Handler)(char board[ROWS][COLUMNS]);

char check_for_winner(char board[ROWS][COLUMNS]);
char check_for_winner_on_lines(char board[ROWS][COLUMNS]);
char check_for_winner_on_columns(char board[ROWS][COLUMNS]);
char check_for_winner_on_diagonals(char board[ROWS][COLUMNS]);

char get_winner(char board[ROWS][COLUMNS], int plays)
{
  if (plays >= MIN_PLAYS_FOR_WIN)
  {
    return check_for_winner(board);
  }

  return 0;
}

char check_for_winner(char board[ROWS][COLUMNS])
{
  Handler check_for_winner[3] =
  {
    check_for_winner_on_lines,
    check_for_winner_on_columns,
    check_for_winner_on_diagonals
  };

  int i;
  for (i = 0; i < 3; i++)
  {
    char winner = check_for_winner[i](board);
    if (winner)
    {
      return winner;
    }
  }

  return 0;
}

char check_for_winner_on_lines(char board[ROWS][COLUMNS])
{
  int i;
  for(i = 0; i < ROWS; i++)
  {
    char winner = board[i][0];
    if (board[i][0] == board[i][1] &&
        board[i][0] == board[i][2] &&
        board[i][1] == board[i][2] &&
        board[i][0] != ' ')
    {
      return winner;
    }
  }

  return 0;
}

char check_for_winner_on_columns(char board[ROWS][COLUMNS])
{
  int i;
  for(i = 0; i < COLUMNS; i++)
  {
    char winner = board[0][i];
    if (board[0][i] == board[1][i] &&
        board[0][i] == board[2][i] &&
        board[1][i] == board[2][i] &&
        board[0][i] != ' ')
    {
      return winner;
    }
  }

  return 0;
}

char check_for_winner_on_diagonals(char board[ROWS][COLUMNS])
{
  char winner;
  winner = board[0][0];
  if (board[0][0] == board[1][1] &&
      board[0][0] == board[2][2] &&
      board[1][1] == board[2][2] &&
      board[0][0] != ' ')
  {
    return winner;
  }
  winner = board[0][2];
  if (board[0][2] == board[1][1] &&
      board[0][2] == board[2][0] &&
      board[1][1] == board[2][0] &&
      board[0][2] != ' ')
  {
    return winner;
  }

  return 0;
}

