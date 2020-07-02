#include "filehandling.h"

void swap(player *p1,player *p2)
{
    player *temp;
    *temp=*p1;
    *p1=*p2;
    *p2=*temp;
}

void sortLeaderBoard(int n,player players[n])
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

int getLeaderBoard(player players[])
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
    return index;
}

void writeIntoLeadeBoard(int n,player players[n])
{
    FILE *outfile; 
    outfile = fopen ("../data/LeaderBoard.dat", "w");
    if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError opend file\n"); 
        exit (1); 
    } 
    int i=0;
    for(i=0;i<n-i;i++)
    { 
        printf("\nLopp");
        fwrite (&players[i], sizeof(player), 1, outfile);
    }
    fclose(outfile);
    outfile=NULL;
}

void updateLeaderBoard(int no,player players[no])
{
    sortLeaderBoard(no,players);
    writeIntoLeadeBoard(no,players);
}

void checkLeaderBoard(player *p)
{
    int no;
    player players[21];
    int index=getLeaderBoard(players);
    /*printf("\nindex:%d",index);
    printf("\nmy moves:%d\nleast moves:%d",p->noOfMoves,players[index].noOfMoves);*/
    if(index>0)
    {
        if((p->noOfMoves) < (players[index]).noOfMoves || ((p->noOfMoves) == (players[index]).noOfMoves) && (index<20))
        {
            index++;
            copyToStructure(&players[index],p);
            updateLeaderBoard(index+1,players);
        }
    }
    else if(index==0)
    {
        copyToStructure(&players[0],p);
        writeIntoLeadeBoard(1,p);
    }

}

void printLeaderBoard()
{
    int i;
    player players[21];
    printf("\nSno\t\tDate\t\t\t\tName\t\t\tSize\t\t\tMoves");
    int index = getLeaderBoard(players);
    if(index>0)
    {
        for(i=0;i<=index;i++)
        {
            printf("\n%d\t%s\t\t%s\t\t\t %d\t\t\t %d",i+1,players[i].date,players[i].name,players[i].size,players[i].noOfMoves);
        }
    }
    else
        printf("\n\t\t\tNo records Found");
}
