#include <stdio.h>
#include <string.h>
#include "header.h"

//redeclare the arrays to be used in this function
char playerArr[plrow][column]; // stores player data (limited to twenty rows)
char temp[plrow][column];
char plsort[plrow][column];
char pshuffle[plrow][column];

void sortp()
{
	int count=0, count1=0;

    count=0;
    while(count < plrow - 1){
        for(count1 = count+1; count1 < plrow; count1++){
        	//Check with the row below to see which one come first
        	if (strcmp(plsort[count], plsort[count1]) > 0){
            	//swap the elements
                strcpy(temp, plsort[count]);
                strcpy(plsort[count], plsort[count1]);
                strcpy(plsort[count1], temp);
            }
        }
        count++;
    }

    //Print the sorted list
    printf("\n-------Sorted List of Players-------\n");

    count=0;
    while(count < plrow)
    {
        printf("%s", plsort[count]);
        count++;
    }
}
