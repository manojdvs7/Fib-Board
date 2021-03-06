#include<stdio.h>

/* Checks if the 2 numbers are adjacent fibonacci numbers so that thay can be added */
int areAdjacentNumbers(int num1,int num2)
{
    if(num1==num2 && num1!=1 )
        return 0;
    int min = (num1<num2) ? num1:num2;
    int diff=num1-num2;
    if(diff<0)
        diff=diff*(-1);
    if(diff <= min)
        return 1;
    return 0;
}

/* Checks if player won*/
int winCondition(int win,int size,int board[][size])
{
    int row,col;
    for(row=0;row<size;row++)
    {
        for(col=0;col<size;col++)
        {
            if(board[row][col]==win)
                return 1;
        }

    }
    return 0;
}

/* Checks of the player cannot have further moves */
int cannotHaveMoves(int size,int board[][size])
{
    int row,col;
    for(row=0;row<size;row++)
    {
        for(col=0;col<size;col++)
        {
            if(board[row][col]==0)
                return 0;

            //up
            if(row!=0 && areAdjacentNumbers(board[row][col],board[row-1][col])==1)
                return 0;
            //down
            if(row!=size-1 && areAdjacentNumbers(board[row][col],board[row+1][col])==1)
                return 0;
            //left
            if(col!=0 && areAdjacentNumbers(board[row][col],board[row][col-1])==1)
                return 0;
            //right
            if(col!=size-1 && areAdjacentNumbers(board[row][col],board[row][col+1])==1)
                return 0;
        }
    }
    return 1;
}
/* Checks if the board has atlast one zero */
int atLeastOneZero(int size,int board[][size])
{
    int row,col;
    for(row=0;row<size;row++)
    {
        for(col=0;col<size;col++)
        {
            if(board[row][col]==0)
                return 1;
        }
    }
    return 0;
}