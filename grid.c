#include <stdio.h>

#include "grid.h"

void print_start_board();
void print_board(char board[ROWS][COLUMNS]);
void print_end_board();
void print_tab();
void print_line(char line[COLUMNS]);
void print_divider();

void print_stage(char board[ROWS][COLUMNS])
{
    print_start_board();
    print_board(board);
    print_end_board();
}

void print_start_board()
{
  printf("\n\n");
  print_tab();
  printf("==================================\n");
  print_tab();
  printf("\tTicTacToe\n");
  print_tab();
  printf("__________________________________\n\n");
}

void print_tab()
{
  printf("\t\t\t");
}

void print_board(char board[ROWS][COLUMNS])
{
  print_line(board[0]);
  print_divider();
  print_line(board[1]);
  print_divider();
  print_line(board[2]);
}

void print_line(char line[COLUMNS])
{
  print_tab();
  printf("\t  %c  |  %c  |  %c  \n", line[0], line[1], line[2]);
}

void print_divider()
{
  print_tab();
  printf("\t-----------------\n");
}

void print_end_board()
{
  printf("\n");
  print_tab();
  printf("==================================\n");
}

void print_invalid_move()
{
  print_tab();
  printf(RED "Invalid move!\n" RESET);
}

void print_ask_for_move(char player)
{
  print_tab();
  printf("Player \"%c\", choose your move: ", player);
}

void print_winner(char board[ROWS][COLUMNS], char player)
{
  print_stage(board);
  print_tab();
  printf("We have a winner! Congratulations player \"%c\".\n", player);
}

void print_draw(char board[ROWS][COLUMNS])
{
  print_stage(board);
  print_tab();
  printf("Oh noo DRAW!\n");
}
