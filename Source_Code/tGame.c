#include "tGame.h"
#include <stdio.h>
#include <stdlib.h>

tGame SetGameValues(tGame game){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            game.board[i][j] = ' ';
        }
    }
    game.player = 1;
    return game;
}

int IsValidCell(tGame game, int x, int y){
    if(game.board[x][y] == ' '){
        return 1;
    }
    return 0;
}

void PlayGame(tGame game){
    int x, y, winner = 0;

    while(winner==0){
        printf("Player %d turn\n", game.player);
        scanf("%d %d", &x, &y);
        if(IsValidCell(game, x, y)){

            if(game.player == 1){
                game.board[x][y] = 'X';
                PrintGame(game);
                game.player = 2;
            }else if(game.player == 2){
                game.board[x][y] = 'O';
                PrintGame(game);
                game.player = 1;
            }

        }else{
            printf("Invalid cell, try agin.\n\n");
            continue;
        }
        winner = CheckWinner(game);
    }
    
}

int CheckWinner(tGame game){
    int i, j, winner = 0, endgame = 1;
    for(i = 0; i < 3; i++){
        if(game.board[i][0] == game.board[i][1] && game.board[i][1] == game.board[i][2] && game.board[i][0] != ' '){
            winner = 1;
            break;
        }
    }
    for(j = 0; j < 3; j++){
        if(game.board[0][j] == game.board[1][j] && game.board[1][j] == game.board[2][j] && game.board[0][j] != ' '){
            winner = 1;
            break;
        }
    }
    if(game.board[0][0] == game.board[1][1] && game.board[1][1] == game.board[2][2] && game.board[0][0] != ' '){
        winner = 1;
    }
    if(game.board[0][2] == game.board[1][1] && game.board[1][1] == game.board[2][0] && game.board[0][2] != ' '){
        winner = 1;
    }

    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(game.board[i][j] == ' '){
                endgame = 0;
                break;
            }
        }
    }

    if(winner == 1){
        printf("Player %d wins!\n", game.player);
    }else if(winner == 0 && endgame == 1){
        printf("Draw!\n");
        exit(0);
    }
    return winner;
}

void PrintGame(tGame game){
    int i, j;
    for(i=0; i<3; i++){
        printf("|");
        for(j=0; j<3; j++){
            printf("%c", game.board[i][j]);
            if(j<2)
                printf("|");
            }
        printf("|\n");
    }
    printf("\n");
}