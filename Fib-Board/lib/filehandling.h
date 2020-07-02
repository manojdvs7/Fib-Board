#include<stdio.h>
#include<stdlib.h>
#include "structure.h"
#include <string.h>
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

void copyToPointer(player *p1,player *p)
{
    strcpy(p->date,p1->date);
    strcpy(p->name,p1->name);
    p->size=p1->size;
    copyBoard(p1->size,p1->board,p->board);
    p->noOfMoves=p1->noOfMoves;
}

void copyToStructure(player *p1,player *p)
{
    strcpy(p1->date,p->date);
    strcpy(p1->name,p->name);
    copyBoard(p->size,p->board,p1->board);
    p1->size=p->size;
    p1->noOfMoves=p->noOfMoves;

}

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
    copyToStructure(&p1,p);
    fwrite (&p1, sizeof(player), 1, outfile);
    fclose(outfile);
    outfile=NULL;
}


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
    copyToPointer(&p1,p);
    fclose (infile);
    infile=NULL; 
}
