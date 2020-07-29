#include "filehandling.h"

void swap(player *p1,player *p2)
{
    player *temp;
    *temp=*p1;
    *p1=*p2;
    *p2=*temp;
}
/*Sorts leaderboard based on their moves*/
void sortLeaderBoard(int n,player *players) 
{
    int i, j;  
    for (i = 0; i < n-1; i++)      
    { 
        for (j = 0; j < n-i-1; j++)  
            if ((players[j].noOfMoves) > (players[j+1].noOfMoves))
            {
                swap(&players[j], &players[j+1]);
            }
    } 
}

/* returns leaderboard */
void getLeaderBoard(player players[])
{
    FILE *infile;
    infile = fopen ("../data/LeaderBoard.dat", "r"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }
    int index=0;
    while(fread(&players[index], sizeof(player), 1, infile)!=0)
    {
       //printf("\nname:%s",players[index].name);
        index++;
    } 
}
/* returns number of entries in leaderboard file already there */
int getCountOfLeaderBoard()
{
    player players;
    FILE *infile;
    infile = fopen ("../data/LeaderBoard.dat", "r"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }
    int index=0;
    while(fread(&players, sizeof(player), 1, infile)!=0)
    {
       //printf("\nname:%s",players[index].name);
        index++;
    } 
    return index;
}

/*Writes into leaderboard*/
void writeIntoLeadeBoard(int n,player *players)
{
    FILE *infile;
    infile = fopen ("../data/LeaderBoard.dat", "w"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    }
    for(int i=0;i<n;i++)
    {
        if(i>19)
            return;
        fwrite (&players[i], sizeof(player), 1, infile);
    }
    return;
}

/*Update the leaderboard*/
void updateLeaderBoard(int no,player* players)
{
    sortLeaderBoard(no,players);
    writeIntoLeadeBoard(no,players);
}

/*Checks if current player is elgible to get intlo leaderboard*/
void checkLeaderBoard(player *p)
{
    int index = getCountOfLeaderBoard();
    player *players=(player *)calloc(index+1,sizeof(player));
    getLeaderBoard(players);
    if(index==0)
    {
        writeIntoLeadeBoard(1,p);
    }
    else
    {
        if(index<20)
        {
            copy(p,&players[index]);
            updateLeaderBoard(index+1,players);
        }
        else if(index==20)
        {
            if(p->noOfMoves < players[19].noOfMoves)
            {
                copy(p,&players[20]);
                updateLeaderBoard(21,players);
            }
        }
        
    }
    
    return;
}

/*Prints leaderboard*/
void printLeaderBoard()
{
    int i;
    printf("\nSno\t\tDate\t\t\t\tName\t\t\tSize\t\t\tMoves");
    int index = getCountOfLeaderBoard();
    player *players=(player *)calloc(index,sizeof(player));
    getLeaderBoard(players);
    if(index>0)
    {
        for(i=0;i<index;i++)
        {
            printf("\n%d\t%s\t\t%s\t\t\t %d\t\t\t %d",i+1,players[i].date,players[i].name,players[i].size,players[i].noOfMoves);
        }
    }
    else
        printf("\n\t\t\tNo records Found");
}
