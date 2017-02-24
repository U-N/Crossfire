#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

//redeclare the arrays to be used in this function
char temp[plrow][column];
char pshuffle[plrow][column];

void shufflep(){
    int i, j;
    int result=1, result1=1, result2=1, result3=1;
    int count=0;

    srand(time(NULL));

    i = plrow-1;
    while(i > 0) {
    	//Find a random position between i and 0 to swap with
    	//Using i means we can't swap j with itself
        j = (rand() % i);
        result=1, result1=1, result2=1, result3=1;
        //Check to see if the positions that they are being swapped are not the same race as the ones beside
        result = strncmp(pshuffle[j], pshuffle[i+1], 2);
        result1 = strncmp(pshuffle[j], pshuffle[i-1], 2);
        result2 = strncmp(pshuffle[i], pshuffle[j+1], 2);
        result3 = strncmp(pshuffle[i], pshuffle[j-1], 2);
        //Ran into problem if at end there was no available position to put a player without being next to another of the same type the loop would run forever
        //Added count to stop the loop looping forever, if  it runs over 100 which is more than enough to go through each possible position
        //Due to the amount of Ogres there is usually one in the first position due to the loop counting downwards
        //If any of the results come back as 0 meaning it is equal to the once beside the code doesn't run
        if(!(result==0) && !(result1==0) && !(result2==0) && !(result3==0)){
        	//swap the array elements
            strcpy(temp, pshuffle[j]);
            strcpy(pshuffle[j], pshuffle[i]);
            strcpy(pshuffle[i], temp);
            i--;
        }
        //Failsafe metioned earlier, almost never runs anymore due to code improvements
        else if(count>100){
        	i--;
			count=0;
        }
        count++;
   }

    //Print the shuffled list
    printf("\n-------Shuffled List of Players-------\n");
    count=0;
    while(count < plrow)
    {
        printf("%s", pshuffle[count]);
        count++;
    }
}
