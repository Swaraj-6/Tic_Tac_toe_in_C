#include <stdio.h>

void printBoard();
int checkWin();
void system();

char board[]={'0','1','2','3','4','5','6','7','8','9'};
void main(){
    int player = 1, input, status = 1;
    char mark;
    printBoard();
    

    while(status == 1){
        if(player%2 == 0){
            player = 2;
        }
        else{
            player = 1;
        }

        if (player == 1){
        mark = 'X';
        }else{
            mark = 'O';
        }
        printf("Please enter the number for player %d\n", player);
        scanf("%d", &input);
        if(input < 1 || input > 9){
            printf("Invalid Input.\n");
        }

        if(board[input] == 'X' || board[input] == 'O'){
            printf("Invalid input.\n");
        }
        else{
            board[input] = mark;
            printBoard();

            int result=checkWin();

            if(result==1){
                printf("Player %d is the Winner\n",player);
                return;
            }else if(result==0){
                printf("draw\n");
                return;
            }
            player++;
        }
    }

    

    
}

void printBoard(){
    system("clear");
    printf("=== TIC TAC TOE ===\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[1],board[2],board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[4],board[5],board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n",board[7],board[8],board[9]);
    printf("     |     |     \n");
    printf("\n\n");
}


int checkWin(){

    if(board[1]==board[2] && board[2]==board[3]){
        return 1;
    }
    if(board[1]==board[4] && board[4]==board[7]){
        return 1;
    }
    if(board[7]==board[8] && board[8]==board[9]){
        return 1;
    }
    if(board[3]==board[6] && board[6]==board[9]){
        return 1;
    }
    if(board[1]==board[5] && board[5]==board[9]){
        return 1;
    }
    if(board[3]==board[5] && board[5]==board[7]){
        return 1;
    }
    if(board[2]==board[5] && board[5]==board[8]){
        return 1;
    }
    if(board[4]==board[5] && board[5]==board[6]){
        return 1;
    }

    int count=0;
    for (int i = 1; i <=9; i++)
    {
        if(board[i]=='X' || board[i]=='O'){
            count++;
        }
    }
    
    if(count==9){
        return 0;
    }
    return -1;
}