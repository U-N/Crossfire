#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include "struct.h"

int createboard(int player_cnt){
    //Get the size of the board
    //Decided to make the board square to maintain simplicity
    //Made sure to allow for different group sizes, 2 players should play on a smaller board than 6
    int boardsize=0;
    printf("Enter the desired size of the board between %d-%d: ", player_cnt+2, player_cnt+4);
    fflush(stdout);
    while(boardsize<(player_cnt+2) || boardsize>(player_cnt+4)){
        scanf("%d", &boardsize);
    }
    
    int i=0;
    int j=0;
    
    //Fill the board using 0 as a null value
    //Filling to 10 to ensure junk values do not come into play
    while(i<10){
        while(j<10){
            slots[i].board[j] = 0;
            j++;
        }
        i++;
        j=0;
    }
    
    //Call slot_type to assign slot types to each board slot
    slot_type(boardsize);
    
    return boardsize;
}

void printboard(int boardsize, int player_cnt){
    int i=0;
    int j=0;
    int print=0;
    int player_num=0;
    
    
    //Refill the board using 0 as a null value
    //No need to fill to 10 again as shouldn't be modified since
    while(i<boardsize){
        while(j<boardsize){
            slots[i].board[j] = 0;
            j++;
        }
        i++;
        j=0;
    }
    i=j=0;

    //Set the players positions
    //Change to do in movement.h, where write over slot[players[i].x].board[players[i].y] with a 0, move position then rewrite with new player num
    //More efficient
    while(i<player_cnt){
        slots[players[i].x].board[players[i].y] = i+1;
        i++;
    }
    
    i=j=0;

    while(i<boardsize){
        while(j<boardsize){
            while (player_num <= player_cnt) {
                //Print player postion on board
                if(i+1 == players[player_num].x && j+1 == players[player_num].y){
                    printf("_%d_", player_num+1);
                    //Tell the next if statement something has already been printed
                    print=1;
                    //Can only be one person per square so setting player_num to player_cnt to end the loop
                    player_num = player_cnt;
                }
                player_num++;
            }
            
            //Checks whether something has been printed
            if(print == 0){
                //Print horizontal lines for board
                printf("___");
            }
            //Reset print
            else{
                print=0;
            }
            //Print vertical lines for baord
            printf("|");
            player_num=0;
            j++;
        }
        printf("\n");
        i++;
        j=0;
    }
}

#endif
