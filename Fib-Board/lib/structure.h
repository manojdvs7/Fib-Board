#include<time.h>

/*Structure for storing player details*/

typedef struct
{
    char date[25];
    char name[10];
    int size;
    int board[4][4];
    int noOfMoves;
}player;
