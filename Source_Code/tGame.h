#ifndef _TGAME_H_
#define _TGAME_H_

typedef struct{
    int player;
    int row;
    int column;
    char board[3][3];
}tGame;


/**
 * @brief Build a empty board.
 * 
 * @param game struct to be set.
 * @return tGame: updated struct with a empty board.
 */
tGame SetGameValues(tGame game);



/**
 * @brief Responsible for game logic.
 * 
 * @param game struct with current values.
 */
void PlayGame(tGame game);



/**
 * @brief Display the current boad on screen.
 * 
 * @param game struct with current values.
 */
void PrintGame(tGame game);



/**
 * @brief Check if after last turn the player wins. 
 * 
 * @param game struct with current values.
 * @return int 1 = True or 0 = False.
 */
int CheckWinner(tGame game);



/**
 * @brief Verify if the selected cell is available.
 * 
 * @param game struct with current values.
 * @param row selected row.
 * @param column selected column.
 * @return int 1 = True (is valid) or 0 = False (is invalid).
 */
int IsValidCell(tGame game, int row, int column);

#endif