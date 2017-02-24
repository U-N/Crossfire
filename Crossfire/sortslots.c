#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

//redeclare the arrays to be used in this function
char ssort[slotsrow][column];
char stemp[slotsrow][column];

void sortslots()
{
    int count=1;
    int count1=1;
    int count2=0;
    int temprow=slotsrow-1;

    printf("\n-------Sorted List of Slots-------\n");
    //declare x to find in slots.txt
    char ch = 'x';

    //Tried using memcpy, memcpr, strstr, strcmp, strncmp none of which I could get to do what I wanted
    //I included a text document with unsuccessful test functions
    //This loop resets count1 in order to run through the loop again
    while(count<slotsrow){
    	//This loop moves the program onto the next row
        while(count1<slotsrow){
        	//This loop runs through the columns to find ch
            while(count2<column){
                if(stemp[count1][count2] == ch){
                	//temprow starts from the end of ssort and fills it from the bottom
                	//This is because we find x first
                    strcpy(ssort[temprow--], stemp[count1]);
                    ch = stemp[count1][0];
                }
                count2++;
            }
            count2=0;
            count1++;
        }
        count1=0;
        count++;
    }
    //print out the results
    count=0;
    while(count<slotsrow){
        printf("%s", ssort[count]);
        count++;
    }
}
