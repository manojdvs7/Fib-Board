#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<dos.h>
#include<time.h> 
#include "./lib/play.h"
#include<string.h>

void getDateAndTime(player *p)
{
    time_t t;
	time(&t);
	strcpy(p->date,(char*)ctime(&t));
    p->date[strlen(p->date)-1]='\0';
    p->noOfMoves=0; 
    printf("Date and time:%s",p->date);
}

void makeMoreChoices(player *p)
{
    int choice;
    getDateAndTime(p);

    printf("\nEnter name:");
    scanf("%s",(p->name));

    printf("\n1) 2 X 2 \n2) 4 X 4\nEnter Your Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            p->size=2;
            playGame(p);
            break;
        case 2:
            p->size=4;
            playGame(p);
            break;
        default:
            printf("\nInavlid choice");
    }

}

void makeChoices(player *p)
{
    int choice;
    printf("\n1) Play \n2) Replay Last Saved Game \n3) View LeaderBoard\nEnter Your Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            makeMoreChoices(p);
            break;
        case 2:
            getState(p);
            printf("\nSuccess");
            resumeGame(p);
            break;
        case 3:
            printLeaderBoard();
            exit(0);
            break;
        default:
            printf("\nInavlid choice");
    }
}
int main()
{
    system("cls");
    player *p = (player *)calloc(1,sizeof(player));
    makeChoices(p);
    return 0;
}