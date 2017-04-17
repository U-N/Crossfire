#include <stdio.h>
#include "crossfireOperations.h"
#include "struct.h"

//This function returns the board size provided as input by the user
void playerStats(int i, int Opt_class){
    //Assign temps for later use in ensure capabilities outside boundaries are not reached.
    players[i].dextemp=0;
    players[i].strtemp=0;
    players[i].magtemp=0;
    Opt_class=0;
    printf("Player %d Please enter your name: ", i+1); /* as the number of players is being incremented to the user's max number, the names of the players are being assigned to each number and stored within an array*/
    fflush(stdout);
    scanf("%s", &players[i].playername);
    
    printf("1 = Elf\n");
    printf("2 = Human\n"); /* Options for the player's class are clearly printed with a corresponding integer value which will be inputed by the user and compared to the player class enumeration in struct.h*/
    printf("3 = Ogre\n");
    printf("4 = Wizard\n");
    printf("Enter a number to choose your class: ");
    fflush(stdout);
    while(Opt_class<1 || Opt_class>4){ //Make sure the player chooses a valid number in order to select a class
        scanf("%d", &Opt_class);
    }
    
    players[i].class = --Opt_class; //Assign each player the correct class, using their input, and the enum from struct.h
    players[i].lifepts = 100; /* each player is being given 100% health at the start of the game*/
    puts("");
				printf("Player %d -> %s \n", i+1, players[i].playername);
    
				if(players[i].class == Elf){
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
}
