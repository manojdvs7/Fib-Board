#include<stdio.h>
#include "moves.h"
#include<conio.h>
#include "leaderboard.h"
#include<time.h>

/* Prints the board on screen*/
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

/* Initialize the board with 2 zeros at random positions*/
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

/* gets win number for win condition different for different board*/
int getWinNumber(int n)
{
   int a = 1, b = 1, c, i; 
  if( n == 0) 
    return a; 
    for (i = 3; i < n; i++) 
    {  
        c = a + b; 
        a = b; 
        b = c; 
    } 
  return b; 
}
/* Start Game*/
void playGame(player *p)
{
    InitializeBoard(p->size,p->board);
    int moves = 0;
    int win = getWinNumber(2*(p->size)*(p->size));
    printBoardAndMoves(p->size,moves,p->board);
    int won=0;
    while(1)
    {
        if(winCondition(win,p->size,p->board)==1)                       /*if already won*/
        {
            won=1;
            break;
        }
        if(cannotHaveMoves(p->size,p->board)==1)                        /* cannot have furthur moves*/
            break;

        char move=getch();                                              /* get the key pressed 'w','s','a','d','v','q'*/
        switch(move)
        {
            case 'w':                                                  /*move up*/
                moveUp(p->size,p->board);
                moves++;
                p->noOfMoves=moves;
                printBoardAndMoves(p->size,moves,p->board);
                saveState(p);
                break;
            case 's':                                                /*move down*/
                moveDown(p->size,p->board);
                moves++;
                p->noOfMoves=moves;
                printBoardAndMoves(p->size,moves,p->board);
                saveState(p);
                break;
            case 'a':                                               /*move left*/
                moveLeft(p->size,p->board);
                moves++;
                p->noOfMoves=moves;
                printBoardAndMoves(p->size,moves,p->board);
                saveState(p);
                break;
            case 'd':                                               /* move right */
                moveRight(p->size,p->board);
                moves++;
                p->noOfMoves=moves;
                printBoardAndMoves(p->size,moves,p->board);
                saveState(p);
                break;
            case 'v':                                              /* Save game */
                saveState(p);
                break;
            case 'q':                                              /* Quit game */
                saveState(p);
                exit(0);
        }
    }
    p->noOfMoves=moves;
    saveState(p);
    if(won==1)                                                     /* if won */
    {
        printf("\nYou won the game by %d moves",moves);
        checkLeaderBoard(p);
    }
    else                                                            /* if cannot have furthur moves*/
        printf("\nyou lost the game by %d moves",moves);
}

/* Resume the last game */
void resumeGame(player *p)
{
    printf("\nplayer:%s\nmoves:%d\nLast game played on %s\nEnter any key to continue.......",p->name,p->noOfMoves,p->date);
    getch();
    int moves=p->noOfMoves;
    int win = getWinNumber(2*(p->size)*(p->size));
    int won=0;
    int moreMoves=0;
    printBoardAndMoves(p->size,moves,p->board);
    while(1)
    {
        if(winCondition(win,p->size,p->board)==1)                       /*if already won*/
        {
            won=1;
            break;
        }
        if(cannotHaveMoves(p->size,p->board)==1)                   /* cannot have furthur moves*/
            break;


        char move=getch();                                       /* get the key pressed 'w','s','a','d','v','q'*/
        switch(move)
        {
            case 'w':
                moveUp(p->size,p->board);                       /*move down*/
                moves++;
                p->noOfMoves=moves;
                printBoardAndMoves(p->size,moves,p->board);
                moreMoves++;
                saveState(p);
                break;
            case 's':                                           /*move down*/
                moveDown(p->size,p->board);
                moves++;
                p->noOfMoves=moves;
                printBoardAndMoves(p->size,moves,p->board);
                moreMoves++;
                saveState(p);
                break;
            case 'a':                                           /*move left*/
                moveLeft(p->size,p->board);
                moves++;
                p->noOfMoves=moves;
                printBoardAndMoves(p->size,moves,p->board);
                moreMoves++;
                saveState(p);
                break;
            case 'd':                                           /*move right*/
                moveRight(p->size,p->board);
                moves++;
                p->noOfMoves=moves;
                printBoardAndMoves(p->size,moves,p->board);
                moreMoves++;
                saveState(p);
                break;
            case 'v':                                              /*Save game*/
                saveState(p);
                break;
            case 'q':                                              /*Quit game*/ 
                saveState(p);
                exit(0);
        }
    }
    p->noOfMoves=moves;
    saveState(p);
    if(won==1)                                                  /* if won */
    {
        if(moreMoves>0)
        {
            printf("\nYou won the game by %d moves",moves);
            checkLeaderBoard(p);
        }
        else
        {
            printf("\nYou already won the game by %d moves,you can start the new game\nEnter enter to start",moves);
            getch();
            p->noOfMoves=0;
            playGame(p);
        }
        
    }
    else                                                        /* if cannot have furthur moves*/
        printf("\nyou lost the game by %d moves",moves);
}