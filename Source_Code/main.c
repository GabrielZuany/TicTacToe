/**
 * @file main.c
 * @author Gabriel Zuany Duarte Vargas (https://github.com/GabrielZuany)
 * @brief Tic-Tac-Toe Game
 * @version 1.1
 * @date 2022-10-10 (last update)
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <stdio.h>
#include "tGame.h"

int main(){
    tGame game;
    game = SetGameValues(game);
    printf("\nWelcome to Tic Tac Toe:\n\nPlayer 1 is X and Player 2 is O\n\nEnjoy it!\n\n");
    PrintGame(game);
    PlayGame(game);
    return 0;
}