#ifndef SLOT_H
#define SLOT_H /* ifndef and endif pre-processors checks the functions condition - "if the following is not defined"*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "struct.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "capabilities.h"


void slot_type(int slot_cnt);
void slot_assign(int slot_cnt, int player_cnt);

void slot_type(int boardsize){

	srand(time(NULL)); /* a function to create a list of randomly generated values*/
	int i;
    int j;
	int random;

	/* the int value random is assigned a random number from 0 to 2 (length 3) whilst the number of slots is incremented...*/
	for(i=1;i<=boardsize;i++){
        for(j=1;j<=boardsize;j++){
            random = rand() % 3;
            
            //Each value 0 to 2 correlates to a slot type
            if(random == 0){
                slots[i].board[j] = 0;
            }
            else if(random == 1){
                slots[i].board[j] = 1;
            }
            else{
                slots[i].board[j] = 2;
            }
		}
		/*...which corresponds to the enum slottype (in other words - LevelGround, Hill or City)*/
	}
}

//Need to produce two random number for x and y and ensure not on same square
void slot_assign(int boardsize, int player_cnt){

	srand(time(NULL));
    int i, j;
    
    i=j=0;
    
    //Fill the x and y with 0's to ensure junk values don't interfere when comparing values
    while(i<player_cnt){
        players[i].x = 0;
        players[i].y = 0;
        i++;
    }
    
    i=j=0;
    
    while(i<player_cnt){
        //Produce two random integers for the x and y of the player
        players[i].x = rand() % boardsize + 1;
        players[i].y = rand() % boardsize + 1;
        while(j<player_cnt){
            //Make sure it isn't comparing the same player's x and y or else the loop would run forever
            if(i != j){
                //Make sure two players aren't put in the same slot
                if(players[i].x == players[j].x && players[i].y == players[j].y){
                    i--;
                    j=player_cnt;
                }
                j++;
            }
            
            else{
                j++;
            }
        }
        j=0;;
        i++;
        
    }
}

#endif /* relates to SLOT_H */
