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
void inputErrorTest();
void dupTestRow(char puzz[9][9]);
void dupTestCol(char puzz[9][9]);

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
      buildpuzz(puzzLine);
      dupTestRow(puzz);
      dupTestCol(puzz);
      inputErrorTest();
      displayPuzz(puzz); /*This needs to come out in prod.*/
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
void displayPuzz(char puzz[9][9]) /*This needs to come out in prod.*/
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
void inputErrorTest()
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
void dupTestRow(char puzz[9][9])
{
  int i;
  int cmpInt;
  int loc;
  for (loc = 0; loc < 9; ++loc) /*1st loop to advance down rows.*/
  {
    for (i = 0; i < 8; ++i) /*2nd loop to test across row.*/
    {
      if (puzz[loc][i] == '.')
      {
        break;
      }
      for (cmpInt = i + 1; cmpInt < 9; ++cmpInt) /*3rd loop to compare chars.*/
      {
        if (puzz[loc][i] == puzz[loc][cmpInt])
        {
          errorFlag = 1;
          return;
        }
      }
    }
  }
}
void dupTestCol(char puzz[9][9])
{
  int i;
  int cmpInt;
  int loc;
  for (loc = 0; loc < 9; ++loc) /*1st loop to advance down cols.*/
  {
    for (i = 0; i < 8; ++i) /*2nd loop to test across col.*/
    {
      if (puzz[i][loc] == '.')
      {
        break;
      }
      for (cmpInt = i + 1; cmpInt < 9; ++cmpInt) /*3rd loop to compare chars.*/
      {
        if (puzz[i][loc] == puzz[cmpInt][loc])
        {
          errorFlag = 1;
          return;
        }
      }
    }
  }
}