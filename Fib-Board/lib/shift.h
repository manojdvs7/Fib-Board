#include<stdio.h>

void shiftUp(int size,int board[][size])
{
int row,column,times,eachRow;
    for(column=0;column<size;column++)
    {
        for(row=0;row<size;row++)
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
    for(column=0;column<size;column++)
    {
        for(row=size-1;row>=0;row--)
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

    for(row=0;row<size;row++)
    {
        for(column=0;column<size;column++)
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
    for(row=0;row<size;row++)
    {
        for(column=size-1;column>=0;column--)
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