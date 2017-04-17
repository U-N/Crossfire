/*
 * main.c

 *
 *  Created on: 29 Mar 2017
 *      Author: liliana
 */


#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "crossfireOperations.h"
#include "struct.h"
#include "slot.h"
#include "capabilities.h"

int main(){
    int player_cnt=0, slot_cnt=0, i;
    int Opt_class = 0;
    int row, column;
    struct slot *currSlot = NULL;
    struct slot *foundSlots;
    
    printf("Please enter the number of players between 2-6: "); /* program is asking the user the name of players he/she wants in the game*/
    fflush(stdout);
    while(player_cnt<2 || player_cnt>6){ //Make sure the player chooses a valid number of players
        scanf("%d", &player_cnt);
    }
    
    int BOARD_SIZE = getBoardSize(player_cnt);
    
    bool explored[BOARD_SIZE][BOARD_SIZE];
    int count =0;
    
    //pointer to slot (0,0)
    struct slot *upLeft;
    //pointer to slot (0, boardSize -1)
    struct slot *upRight;
    //pointer to slot (boardSize - 1, 0)
    struct slot *downLeft;
    //pointer to slot (boardSize - 1, boardSize -1)
    struct slot *downRight;
    
    //Create the board
    createBoard(BOARD_SIZE,&upLeft, &upRight, &downLeft, &downRight);
    
    for(i=0;i<player_cnt;i++){
        playerStats(i, Opt_class);
        capabilities(Opt_class, i); /* Calling the capabilities function to print out each player's abilities*/
    }
    
    /*This section of code allows me to assign a specific starting slot to each player and change their abilities depending on which slot they move to next*/
    slot_assign(BOARD_SIZE, player_cnt);
    
    for(i=0;i<player_cnt;++i){
        puts("");
        printf("Player %d -> %s \n", i+1, players[i].playername);
        
        if(players[i].class == Elf){ /* I have manually printed out the class type by going through, with if statements, the types of enum playerclass values*/
            printf("(Elf , %0.0f)\n", players[i].lifepts);
            fflush(stdout);
        }
        else if(players[i].class == Human){
            printf("(Human , %0.0f)\n", players[i].lifepts);
            fflush(stdout);
        }
        else if(players[i].class == Ogre){
            printf("(Ogre , %0.0f)\n", players[i].lifepts);
            fflush(stdout);
        }
        else if(players[i].class == Wizard){
            printf("(Wizard , %0.0f)\n", players[i].lifepts);
            fflush(stdout);
        }
        
        printf("%s is at %d, %d ->", players[i].playername, players[i].x, players[i].y);
        
        if(slots[players[i].x].slot[players[i].y] == LevelGround){ /* prints the type of slot according to the slottype enumeration in struct.h*/
            printf("  Level Ground\n");
        }
        
        if(slots[players[i].x].slot[players[i].y] == Hill){
            printf("  Hill\n");
        }
        
        if(slots[players[i].x].slot[players[i].y] == City){
            printf("  City\n");
        }
        
        puts("");
    }
    
    printboard(BOARD_SIZE, player_cnt);
    
    //Game Mechanics
    /*	Asks the user the row and the column of the slot
     s/he wants to retrieve from the board.
     Note that the user needs to know the size of the board to input
     the correct row and column of the slot s/he wants to retrieve */
    getDesiredElement(BOARD_SIZE, &row,&column);
    
    //Finds the slot
    
    /*If the the required slot is closer to the down-right
     * corner of the board the search starts from downRight,
     * which points to slot at position (boardSize-1, boarSize -1)*/
    if(row >= BOARD_SIZE/2){
        if(column >= BOARD_SIZE/2){
            currSlot = reachDesiredElement(row,column,downRight);
        }
        else{
            currSlot = reachDesiredElement(row,column,downLeft);
        }
        /*If the the required slot is closer to the down-left
         * corner of the board the search starts from downLeft,
         * which points to slot at position (boardSize-1, 0)*/
    }
    else{
        /*If the the required slot is closer to the up-right
         * corner of the board the search starts from upRight,
         * which points to slot at position (0, boarSize -1)*/
        if(column >= BOARD_SIZE/2){
            currSlot = reachDesiredElement(row,column,upRight);
        }
        /*If the the required slot is closer to the up-left
         * corner of the board the search starts from upLeft,
         * which points to slot at position (0, 0)*/
        else{
            currSlot = reachDesiredElement(row,column,upLeft);
        }
    }
    
    for(int i=0; i<BOARD_SIZE; i++){
        for(int j=0; j<BOARD_SIZE;j++){
            explored[i][j] = false;
        }
    }
    
    foundSlots = malloc(BOARD_SIZE * BOARD_SIZE * sizeof(struct slot ));
    printf("\n\nFunction findSlotsinvoked:\n");
    
    if(currSlot!= NULL){
        //invokes function findSlots. The required distance is a constant
        //However you can reuse this function providing as input any arbitrary distance
        findSlots(REQ_DISTANCE, 0, currSlot, foundSlots, &count, explored);
        for(int i=0; i<count; i++){
            printf("(%d, %d)-> ",foundSlots[i].row, foundSlots[i].column);
        }
    }
  /*
    int remainingplayers = player_cnt;
    int action = 0;
    i=0;
    //Loop until only one remains
    while(remainingplayers != 1){
        //Loop through all the players, letting each one take a turn
        while(i<player_cnt){
            //Check if the player is still alive
            if(players[i].lifepts > 0){
                printf("%s, Please choose an action: \n", players[i].playername);
                //All possible actions
                printf("1 = Attack \n2 = Move Left \n3 = Move Right \n");
                scanf("%d", &action);
                //Using a do while loop as needs to be edited while in the loop
                //If the player has reach the end of the slots, we need to tell them and give them another choice
                do{
                    if(action == 1){
                        //Call the attack function and check if anyone died
                        //remainingplayers = attack(i, player_cnt, remainingplayers);
                    }
                    else if(action == 2){
                        //If the player can't move any further left, notify them and give them another chance
                        if(players[i].slotNum <= 1){
                            printf("You cannot move any further left, Please choose a different action:\n");
                            i--;
                            action=0;
                        }
                        else{
                            //Call the movement function
                            movement(i, action);
                        }
                    }
                    else if(action == 3){
                        if(players[i].slotNum >= slot_cnt){
                            printf("You cannot move any further right, Please choose a different action:\n");
                            i--;
                            action=0;
                        }
                        else{
                            movement(i, action);
                        }
                    }
                    else{
                        scanf("%d", &action);
                    }
                }while(action<1 && action>3);
                
            }
            i++;
        }
        //reset i to go through the loop again
        i=0;
    }
    
    i=0;
    while(i<player_cnt){
        //Find which player is still alive, at this point there should only be one
        if(players[i].lifepts > 0){
            //Print who won
            printf("Game Over! %s Wins", players[i].playername);
        }
        i++;
    }
*/
	return 0;
}
