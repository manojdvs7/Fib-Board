#include<stdio.h>
#include "moves.h"


void printBoardAndMoves(int size,int moves,int board[][size])
{

    system("cls");
    for(int i=0;i<size;i++)
    {
        printf("\n");
        for(int j=0;j<size;j++)
            printf("\t%d",board[i][j]);
    }
    printf("\n\n\t\tMoves:%d",moves);
}

void InitializeBoard(int size,int board[][size])
{
    int count=2;
    int row,col;
    for(row=0;row<size;row++)
    {
        for(col=0;col<size;col++)
        {
            board[row][col]=0;
        }
    }
    srand(time(0));
    while(count)
    {
        row=rand() % size;
        col=rand() % size;
        if(board[row][col]==0 )
        {
            board[row][col]=1;
            count--;
        }
    }
}

int getWinNumber(int n)
{
   int a = 1, b = 1, c, i; 
  if( n == 0) 
    return a; 
  for (i = 2; i <= n; i++) 
  { 
     c = a + b; 
     a = b; 
     b = c; 
  } 
  return b; 
}

void playGame(int size)
{
    int board[size][size];
    InitializeBoard(size,board);
    int moves = 0;
    int win = getWinNumber(2*size*size);
    printBoardAndMoves(size,moves,board);
    while(1)
    {
        if(winCondition(win,size,board)==1 || cannotHaveMoves(size,board)==1)
            break;

        char move=getch();
        switch(move)
        {
            case 'w':
                moveUp(size,board);
                moves++;
                printBoardAndMoves(size,moves,board);
                break;
            case 's':
                moveDown(size,board);
                moves++;
                printBoardAndMoves(size,moves,board);
                break;
            case 'a':
                moveLeft(size,board);
                moves++;
                printBoardAndMoves(size,moves,board);
                break;
            case 'd':
                moveRight(size,board);
                moves++;
                printBoardAndMoves(size,moves,board);
                break;
        }
    }
    if(winCondition(win,size,board)==1)
        printf("\nYou won the game by %d moves",moves);
    else
        printf("\nyou lost the game by %d moves",moves);
}