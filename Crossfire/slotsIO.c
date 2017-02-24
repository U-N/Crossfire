#include <stdio.h>
#include <string.h>
#include "header.h"

const char *SLOT_FILE_PATH = "./slots.txt"; //location of slot file

//redeclare the arrays to be used in this function
char slotArr[slotsrow][column];
char stemp[slotsrow][column];

void slotsInput() {
	int lineNum = 0;
	int count=0;

	FILE *fs = fopen(SLOT_FILE_PATH, "r+");       /* open for reading */
	// This will take each row in the file and store it in slotArr.
	//Store each row in the file into slotArr
	if(fs==NULL)
	{ //check does the file exist
		perror("Error opening slots file");
	}
	else
	{
	    printf("-------Initial List of Slots-------\n");

		while(fgets(slotArr[lineNum], sizeof(slotArr[lineNum]), fs) != NULL)
		{
			//Get the info from the text file
			printf("%s",slotArr[lineNum]);
			lineNum++;
		}

	    while(count < slotsrow)
	    {
	        strcpy(stemp[count], slotArr[count]);
	        count++;
	    }
		fclose(fs);
	}
}
