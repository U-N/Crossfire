/*
 * userInteraction.c

 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */

#include <stdio.h>
#include "crossfireOperations.h"
#include "struct.h"

//This function returns the board size provided as input by the user
int getBoardSize(int player_cnt){
    //Get the size of the board
    //Decided to make the board square to maintain simplicity
    //Made sure to allow for different group sizes, 2 players should play on a smaller board than 6
    int boardsize=0;
    
    printf("Enter the desired size of the board between %d-%d: ", player_cnt+2, player_cnt+4);
    
    while(boardsize<(player_cnt+2) || boardsize>(player_cnt+4)){
        scanf("%d", &boardsize);
    }
    
    return boardsize;
}


//THis function takes as input the size of the board and the pointers
// to the integers representing the row and the column of the slot that
// the user want to retrieve
void getDesiredElement(int boardSize, int * row, int * col){
	printf("Please enter the column and the Row of the desired slot \n");
	printf("Note that size of the board is %d\n", boardSize);

		//it will cycle asking the user to insert the row
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			printf("Row: ");
			scanf("%d", row);
			if(row < 0 && *row >= boardSize)
				printf("Error: Incorrect row dimension\n");
		} while(*row < 0 && *row >= boardSize);

		//it will cycle asking the user to insert the column
		//until the value of the desired row is >= 0 or < of the
		// size of the board
		do {
			printf("Column: ");
			scanf("%d", col);
			if(*col < 0 && *col >= boardSize)
				printf("Error: Incorrect column dimension\n");
		} while(*col < 0 && *col >= boardSize);
}

