// Write a method Boolean isKingSafe(int[][]chessBoard) Returns true if king in the given chess board is safe from the given enemies otherwise false;
//NOTE: Enemies are- Horse, Camel, Queen, Elephant only Do not consider the colour case of the chess board for traversal of camel and all.





#include <bits/stdc++.h>
using namespace std;

// Check if the players are on board
bool onBoard(int i, int j){
   // Ckecking the limits of the board
    return i >= 0 && i < 8 &&
        j >= 0 && j < 8;
}

bool checkKing(char chessBoard[][8], char c, int i, int j)
{
  // Moves possible by King < ^ v >
  int moveX[] = {-1, -1, -1, 0,
        0, 1, 1, 1};
  int moveY[] = {-1, 0, 1, -1,
        1, -1, 0, 1};

  for (int k = 0; k < 8; k++)
  {
    // increasing the positions
    
    int newX = i + moveX[k];
    int  newY = j + moveY[k];

    // checking positions and conditions on board 
    if (onBoard(newX, newY) &&
      chessBoard[newX][newY] == c)
    return true;
  }
  return false;
}

// Function to check if camel can attack the king
// using C for the player name
bool checkCamel(char chessBoard[][8], char c, int i, int j)
{
  // Check the lower right diagonal
  int k = 0;
  while (onBoard(i + ++k, j + k))
  {
    if (chessBoard[i + k][j + k] == c)
    return true;
    if (chessBoard[i + k][j + k] != '-')
    break;
  }

  // Check the lower left diagonal
  k = 0;
  while (onBoard(i + ++k, j - k))
  {

    if (chessBoard[i + k][j - k] == c)
    return true;
    if (chessBoard[i + k][j - k] != '-')
    break;
  }

  // Check the upper right diagonal
  k = 0;
  while (onBoard(i - ++k, j + k))
  {
    if (chessBoard[i - k][j + k] == c)
    return true;
    if (chessBoard[i - k][j + k] != '-')
    break;
  }

  // Check the upper left diagonal
  k = 0;
  while (onBoard(i - ++k, j - k))
  {
    if (chessBoard[i - k][j - k] == c)
    return true;
    if (chessBoard[i - k][j - k] != '-')
    break;
  }

  return false;
}

// Check if Elephant can attack king 
bool checkElephant(char chessBoard[][8], char c, int i, int j)
{
  // Check downwards
  int k = 0;
  while (onBoard(i + ++k, j))
  {
    if (chessBoard[i + k][j] == c)
    return true;
    if (chessBoard[i + k][j] != '-')
    break;
  }

  // Check upwards
  k = 0;
  while (onBoard(i + --k, j))
  {
    if (chessBoard[i + k][j] == c)
    return true;
    if (chessBoard[i + k][j] != '-')
    break;
  }

  // Check right
  k = 0;
  while (onBoard(i, j + ++k))
  {
    if (chessBoard[i][j + k] == c)
    return true;
    if (chessBoard[i][j + k] != '-')
    break;
  }

  // Check left
  k = 0;
  while (onBoard(i, j + --k))
  {
    if (chessBoard[i][j + k] == c)
    return true;
    if (chessBoard[i][j + k] != '-')
    break;
  }
  return false;
}

//check if Queen can attack the King
bool checkQueen(char chessBoard[][8], char c, int i, int j)
{
  // Queen's moves are a combination of both the camel and the Elephant
  if (checkCamel(chessBoard, c, i, j) || 	checkElephant(chessBoard, c, i, j))
    return true;

  return false;
}

// Check if the horse can attack the king
bool checkHorse(char chessBoard[][8], char c, int i, int j)
{
  // All possible moves of the horse
  int moveX[] = {2, 2, -2, -2,
        1, 1, -1, -1};
  int moveY[] = {1, -1, 1, -1,
        2, -2, 2, -2};

  for (int k = 0; k < 8; k++)
  {
    // increasing the positions
    int newX = i + moveX[k];
    int newY = j + moveY[k];

    // checking positions and conditions on board 
    if (onBoard(newX, newY) &&
      chessBoard[newX][newY] == c)
    return true;
  }
  return false;
}



// Function to check if the king is safe or not
int isKingSafe(char chessBoard[][8])
{
// Find the position of the king
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      // Check for all pieces which can attack KING
      if (chessBoard[i][j] == 'K')
      {
        // Check for horse
        if (checkHorse(chessBoard,
              'H', i, j))
        return 1;

          // Check for elephant
        if (checkElephant(chessBoard,
              'E', i, j))
        return 1;

        // Check for Camel
        if (checkCamel(chessBoard,
              'C', i, j))
        return 1;

        // Check for Queen
        if (checkQueen(chessBoard,
              'Q', i, j))
        return 1;

        
      }


	
  	}
  }
  return 0;
}


int main()
{
  // ChesschessBoard instance
  char chessBoard[][8] = {
            {'-', '-', '-', 'K', '-', '-', '-', '-'},
            {'-', '-', '-', '-', '-', '-', '-', '-'},
            {'-', '-', '-', '-', '-', '-', '-', '-'},
            { '-', '-', '-','-', '-', '-', 'E', '-'},
            {'-', '-', 'H', '-', '-', '-', '-', '-'},
            {'-', '-', '-', '-', '-', '-', '-', '-'},
            {'Q', '-', '-', '-', '-', '-', '-', '-'},
            {'C', '-', '-', '-', '-', '-', '-', '-'}
            };

  if (isKingSafe(chessBoard) == 0){
    cout << ("King is safe");
  }
  else if (isKingSafe(chessBoard) == 1){
      cout << ("king is unsafe");
  }
  
  return 0;
   
}


