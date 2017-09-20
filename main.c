/******************************************************************************
 *Michael Servilla
 *
 *This file is to read sudoku input from the standard input stream, echo the
 *input, verify that it is valid, and calculate and print out a solution if it
 *exist or state "no solution" if it does not exist.
 *****************************************************************************/

#include <stdio.h>
#include <ctype.h>

void cleanPuzz(char puzz[9][9]);
void displayPuzz(char puzz[9][9]);
void printLine(char puzzLine[]);
void buildpuzzLine(int charCount, char puzzChar);
void buildpuzz(char puzzLine[]);
void inputErrorTest(char puzzLine[], int charCount);

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
    if (charCount < 81 && (isdigit(puzzChar) || puzzChar == '.'))
    {
      puzzLine[charCount] = puzzChar;
      charCount++;
    }
    else if (puzzChar == '\n')
    {
      inputErrorTest(puzzLine, charCount);
      buildpuzz(puzzLine);
      displayPuzz(puzz);
      charCount = 0;
    }
    else
    {
      errorFlag = 1;
    }
  }
  return 0;
}
void printLine(char puzzLine[])
{
  int i;
  for (i = 0; i < 81; ++i)
  {
    printf("%c\n", puzzLine[i]);
  }
}
void cleanPuzz(char puzz[9][9])
{
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
void buildpuzzLine(int charCount, char puzzChar)
{
}
void inputErrorTest(char puzzLine[], int charCount)
{
  if (charCount != 81 || errorFlag == 1)
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