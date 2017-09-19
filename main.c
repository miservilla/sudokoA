/******************************************************************************
 *Michael Servilla
 *
 *This file is to read sudoku input from the standard input stream, echo the
 *input, verify that it is valid, and calculate and print out a solution if it
 *exist or state "no solution" if it does not exist.
 *****************************************************************************/

#include <stdio.h>

void cleanPuzz(int puzz[9][9]);
void displayPuzz(int puzz[9][9]);

int puzz[9][9];
int puzzChar; 
int charCount = 0;
int row = 0;
int col = 0;


int main()
{
  while((puzzChar = getchar()) != EOF)
  {
    putchar(puzzChar);
    charCount++;
    if (puzzChar == '\n')
    {
      printf("\n");
      displayPuzz(puzz);
    }
    else
    {
      puzz[row][col++] = puzzChar;
      if (charCount % 9 == 0)
      {
        row++;
        printf("%d\n", row);
      }
    }
  }
  return 0;
}
void cleanPuzz(int puzz[9][9])
{
  for (row = 0; row < 9; ++row)
  {
    for (col = 0; col < 9; ++col)
    {
      puzz[row][col] = ' ';
    }
  }
}
void displayPuzz(int puzz[9][9])
{
  for (row = 0; row < 9; row++)
  {
    for (col = 0; col < 9; col++)
    {
      printf("%c ", puzz[row][col]);
    }
    printf("\n");
  }
}