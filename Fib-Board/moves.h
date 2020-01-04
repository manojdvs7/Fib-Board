#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h> 
#include "shift.h"
#include "conditions.h"

void generateAOne(int size,int board[][size])
{
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

void moveUp(int size,int board[][size])
{
    int row,column,times,eachRow;
    shiftUp(size,board);
    for(column=0;column<size;column++)
    {
        for(eachRow=0;eachRow<size-1;eachRow++)
        {
            if(board[eachRow][column]!=0 && board[eachRow+1][column]!=0)
            {
                if(areAdjacentNumbers(board[eachRow][column],board[eachRow+1][column]) )
                {
                    board[eachRow][column]+=board[eachRow+1][column];
                    board[eachRow+1][column]=0;
                    break;
                }
            }    
        }
    }
    shiftUp(size,board);
    generateAOne(size,board);
}

void moveDown(int size,int board[][size])
{
    int row,column,eachRow;
    shiftDown(size,board);
    for(column=0;column<size;column++)
    {

        for(eachRow=size-1;eachRow>=1;eachRow--)
        {
            if(board[eachRow][column]!=0 && board[eachRow-1][column]!=0)
            {
                if(areAdjacentNumbers(board[eachRow][column],board[eachRow-1][column]))
                {
                    board[eachRow][column]+=board[eachRow-1][column];
                    board[eachRow-1][column]=0;
                    break;
                }
            }
        }
    }
    shiftDown(size,board);
    generateAOne(size,board);
}

void moveLeft(int size,int board[][size])
{
    int row,column,eachCol;
    shiftLeft(size,board);
    for(row=0;row<size;row++)
    {
        for(eachCol=0;eachCol<size-1;eachCol++)
        {
            if(board[row][eachCol]!=0 && board[row][eachCol+1]!=0)
            {
                if(areAdjacentNumbers(board[row][eachCol],board[row][eachCol+1]))
                {
                    board[row][eachCol]+=board[row][eachCol+1];
                    board[row][eachCol+1]=0;
                    break;
                }
            }
        }
    }
    shiftLeft(size,board);
    generateAOne(size,board);
}

void moveRight(int size,int board[][size])
{
    int row,column,eachCol;
    shiftRight(size,board);
    for(row=0;row<size;row++)
    {
        for(eachCol=size-1;eachCol>=1;eachCol--)
        {
            if(board[row][eachCol]!=0 && board[row][eachCol-1]!=0)
            {
                if(areAdjacentNumbers(board[row][eachCol],board[row][eachCol-1]))
                {
                    board[row][eachCol]+=board[row][eachCol-1];
                    board[row][eachCol-1]=0;
                    break;
                }            
            }       
        }
    }
    shiftRight(size,board);
    generateAOne(size,board);
}
