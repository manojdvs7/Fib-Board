#include<stdio.h>

/*Shift up the board*/
void shiftUp(int size,int board[][size])
{
int row,column,times,eachRow;
    for(column=0;column<size;column++) /* outer loop for each column to shift up*/
    {
        for(row=0;row<size;row++) /* Fill the gaps of 0 if there are any numbers below it*/
        {
            for(eachRow=0;eachRow<size-1;eachRow++) 
            {
                if(board[eachRow][column]==0 && board[eachRow+1][column]!=0)
                {
                        board[eachRow][column]=board[eachRow+1][column];
                        board[eachRow+1][column]=0;
                }
            }
        }
    }
}

void shiftDown(int size,int board[][size])
{
    int row,column,eachRow;
    for(column=0;column<size;column++) /* outer loop for each column to shift down*/
    {
        for(row=size-1;row>=0;row--)  /* Fill the gaps of 0 if there are any numbers above it*/
        {
            for(eachRow=size-1;eachRow>=1;eachRow--)
            {
                if(board[eachRow][column]==0 && board[eachRow-1][column]!=0)
                {
                        board[eachRow][column]=board[eachRow-1][column];
                        board[eachRow-1][column]=0;
                }
            }
        }
    }
}

void shiftLeft(int size,int board[][size])
{
    int row,column,eachCol;

    for(row=0;row<size;row++) /* outer loop for each row to shift left*/
    {
        for(column=0;column<size;column++) /* Fill the gaps of 0 if there are any numbers right to it */
        {
            for(eachCol=0;eachCol<size-1;eachCol++)
            {
                if(board[row][eachCol]==0 && board[row][eachCol+1]!=0)
                {
                    board[row][eachCol]=board[row][eachCol+1];
                    board[row][eachCol+1]=0;
                }
            }
        }
    }
}

void shiftRight(int size,int board[][size])
{
    int row,column,eachCol;
    for(row=0;row<size;row++)  /* outer loop for each row to shift left*/
    {
        for(column=size-1;column>=0;column--) /* Fill the gaps of 0 if there are any numbers left to it */
        {
            for(eachCol=size-1;eachCol>=1;eachCol--)
            {
                if(board[row][eachCol]==0 && board[row][eachCol-1]!=0)
                {
                    board[row][eachCol]=board[row][eachCol-1];
                    board[row][eachCol-1]=0;
                }

            }
        }
    }
}