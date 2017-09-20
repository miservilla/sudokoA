/******************************************************************************
 *Michael Servilla
 *
 *This file is to read sudoku input from the standard input stream, echo the
 *input, verify that it is valid, and calculate and print out a solution if it
 *exist or state "no solution" if it does not exist.
 *****************************************************************************/

#include <stdio.h>
#include <ctype.h>

void cleanPuzz(char puzzLine[], char puzz[9][9]);
void displayPuzz(char puzz[9][9]);
void buildpuzz(char puzzLine[]);
void inputErrorTest(int charCount);

char puzzLine[81];
char puzz[9][9];
int charCount;
int puzzChar;
int charCount = 0;
int row = 0;
int col = 0;
int errorFlag = 0;


int main()
{
  while((puzzChar = getchar()) != EOF)
  {
    putchar(puzzChar);
    if (charCount < 81)
    {
      puzzLine[charCount] = (char) puzzChar;
      if (!(isdigit(puzzChar) || puzzChar == '.'))
      {
        errorFlag = 1;
      }
    }
    charCount++;
    if (puzzChar == '\n')
    {
      inputErrorTest(charCount);
      buildpuzz(puzzLine);
      displayPuzz(puzz);
      cleanPuzz(puzzLine, puzz);
      charCount = 0;
    }
  }
  return 0;
}
void cleanPuzz(char puzzLine[], char puzz[9][9])
{
  int i;
  for (i = 0; i < 81; ++i)
  {
    puzzLine[i] = ' ';
  }
  for (row = 0; row < 9; ++row)
  {
    for (col = 0; col < 9; ++col)
    {
      puzz[row][col] = ' ';
    }
  }
}
void displayPuzz(char puzz[9][9])
{
  printf("\n");
  for (row = 0; row < 9; row++)
  {
    for (col = 0; col < 9; col++)
    {
      printf("%c ", puzz[row][col]);
    }
    printf("\n");
  }
  printf("\n");
}
void inputErrorTest(int charCount)
{
  if (charCount != 82 || errorFlag == 1)
  {
    printf("Error\n");
    errorFlag = 0;
  }
}
void buildpuzz(char puzzLine[])
{
  int i = 0;
  for (row = 0; row < 9; row++)
  {
    for (col = 0; col < 9; col++)
    {
      puzz[row][col] = puzzLine[i++];
    }
  }
}