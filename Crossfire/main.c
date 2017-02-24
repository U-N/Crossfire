#include <stdio.h>
#include "header.h"
#include <stdlib.h>

//Declare arrays, allows them to be used across multiple arrays
//Originally used structs, but led to many problems, including creating random  symbols
//Once I changed to this system all of these problems were fixed
char playerArr[plrow][column];
char temp[plrow][column];
char plsort[plrow][column];
char pshuffle[plrow][column];
char slotArr[slotsrow][column];
char stemp[slotsrow][column];
char ssort[slotsrow][column];

int main(void)
{
	int num=0;
	//Ask the user which action they wish to perform
	printf("Do you want to sort and shuffle the list of players or sort the list of slots: \n");
	printf("ENTER 1 to sort and shuffle the list of players: \n");
	printf("ENTER 2 to sort the list of slots: \n");
	while(!(num==1 || num==2)){
		scanf("%d", &num);
	}
	if(num==1){
		//Call all the functions needed to print, shuffle and sort the players
		fileInput();
		shufflep();
		sortp();
	}
	else if(num==2){
		//Call the functions to print and sort the slots
		slotsInput();
		sortslots();
	}
	return 0;
}
