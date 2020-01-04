#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h> 

#include "play.h"


void makeMoreChoices()
{
    int choice;
    printf("\n1) 2 X 2 \n2) 4 X 4\nEnter Your Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            playGame(2);
            break;
        case 2:
            playGame(4);
            break;
        default:
            printf("\nInavlid choice");
    }

}

void makeChoices()
{
    int choice;
    printf("\n1) Play \n2) Exit\nEnter Your Choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            makeMoreChoices();
            break;
        case 2:
            printf("Thanks for trying");
            exit(0);
            break;
        default:
            printf("\nInavlid choice");
    }
}
int main()
{
    makeChoices();
}