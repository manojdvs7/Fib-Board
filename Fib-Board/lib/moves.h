#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h> 
#include "shift.h"
#include "conditions.h"

/*Generate a 1 for every move*/
void generateAOne(int size,int board[][size]) 
{
    if(atLeastOneZero(size,board)==0)
        return;
    int count=1;
    int row,col;
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
/*Player chooses to move up*/
void moveUp(int size,int board[][size])
{
    int row,column,times,eachRow;
    int validMove=0;
    shiftUp(size,board);                            /* Fills the gaps of 0's upwards */
    for(column=0;column<size;column++)              /*For each column to move up*/
    {
        for(eachRow=0;eachRow<size-1;eachRow++)     /* Checks each row if they are adjecent or not if yes they are added only once per row else checks next*/
        {
            if(board[eachRow][column]!=0 && board[eachRow+1][column]!=0)
            {
                if(areAdjacentNumbers(board[eachRow][column],board[eachRow+1][column]) )
                {
                    board[eachRow][column]+=board[eachRow+1][column];
                    board[eachRow+1][column]=0;
                    break;
                }
                else
                    continue;
            }    
        }
    }
    shiftUp(size,board); /* Fills the gaps of 0's upwards */
    generateAOne(size,board);
}

/*Player chooses to move down*/
void moveDown(int size,int board[][size])
{
    int row,column,eachRow;
    shiftDown(size,board);                           /* Fills the gaps of 0's downwards */
    for(column=0;column<size;column++)              /*For each column to move down*/
    {

        for(eachRow=size-1;eachRow>=1;eachRow--)    /* Checks each row if they are adjecent or not if yes they are added only once per row else checks next*/
        {
            if(board[eachRow][column]!=0 && board[eachRow-1][column]!=0)
            {
                if(areAdjacentNumbers(board[eachRow][column],board[eachRow-1][column]))
                {
                    board[eachRow][column]+=board[eachRow-1][column];
                    board[eachRow-1][column]=0;
                    break;
                }
                else
                    continue;
            }
        }
    }
    shiftDown(size,board); /* Fills the gaps of 0's downwards */
    generateAOne(size,board);
}

/*Player chooses to move left*/
void moveLeft(int size,int board[][size])
{
    int row,column,eachCol;
    shiftLeft(size,board);                           /* Fills the gaps of 0's leftside */
    for(row=0;row<size;row++)                        /*For each row to move left*/
    {
        for(eachCol=0;eachCol<size-1;eachCol++)      /* Checks each column if they are adjecent or not if yes they are added only once per column else checks next*/
        {
            if(board[row][eachCol]!=0 && board[row][eachCol+1]!=0)
            {
                if(areAdjacentNumbers(board[row][eachCol],board[row][eachCol+1]))
                {
                    board[row][eachCol]+=board[row][eachCol+1];
                    board[row][eachCol+1]=0;
                    break;
                }
                else
                    continue;
            }
        }
    }
    shiftLeft(size,board);     /* Fills the gaps of 0's leftside */
    generateAOne(size,board);
}

/*Player chooses to move right*/
void moveRight(int size,int board[][size])
{
    int row,column,eachCol;
    shiftRight(size,board);                             /* Fills the gaps of 0's rightside */
    for(row=0;row<size;row++)                           /*For each row to move right*/
    {
        for(eachCol=size-1;eachCol>=1;eachCol--)       /* Checks each column if they are adjecent or not if yes they are added only once per column else checks next*/
        {
            if(board[row][eachCol]!=0 && board[row][eachCol-1]!=0)
            {
                if(areAdjacentNumbers(board[row][eachCol],board[row][eachCol-1]))
                {
                    board[row][eachCol]+=board[row][eachCol-1];
                    board[row][eachCol-1]=0;
                    break;
                }
                else
                    continue;            
            }       
        }
    }
    shiftRight(size,board);       /* Fills the gaps of 0's rightside */
    generateAOne(size,board);
}
