#include<stdio.h>
#include<stdlib.h>
#include "structure.h"
#include <string.h>

/*Copy the board */
void copyBoard(int size,int board[][size],int board1[][size]) 
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            board1[i][j]=board[i][j];
        }
    }
}

/*Copy player details from p1 to p*/
void copy(player *p1,player *p)
{
    strcpy(p->date,p1->date);
    strcpy(p->name,p1->name);
    p->size=p1->size;
    copyBoard(p1->size,p1->board,p->board);
    p->noOfMoves=p1->noOfMoves;
}

/*void copyToStructure(player *p1,player *p)
{
    strcpy(p1->date,p->date);
    strcpy(p1->name,p->name);
    copyBoard(p->size,p->board,p1->board);
    p1->size=p->size;
    p1->noOfMoves=p->noOfMoves;

}*/


/* Save player state to file, to save game */
void saveState(player *p)
{
    FILE *outfile; 
    outfile = fopen ("../data/State.dat", "w");
        if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        exit (1); 
    }  
    player p1;
   // copyToStructure(&p1,p);
    copy(p,&p1);
    fwrite (&p1, sizeof(player), 1, outfile);
    fclose(outfile);
    outfile=NULL;
}

/*get saved game to resume game*/
void getState(player *p)
{
    FILE *infile;
    infile = fopen ("../data/State.dat", "r"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }
    player p1; 
    fread(&p1, sizeof(player), 1, infile);
    copy(&p1,p);
    fclose (infile);
    infile=NULL; 
}
