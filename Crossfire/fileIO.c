#include <stdio.h>
#include <string.h>
#include "header.h"

const char *PLAYER_FILE_PATH = "./players.txt"; //location of player file

char playerArr[plrow][column]; // stores player data (limited to twenty rows)
char temp[plrow][column];
char plsort[plrow][column];
char pshuffle[plrow][column];

void fileInput() {
	int lineNum = 0;
	int count=0;

	FILE *fp = fopen(PLAYER_FILE_PATH, "r+");       /* open for reading */
	// This will take each row in the file and store it in playerArr.
	//Store each row in the file into playerArr
	if(fp==NULL)
	{ //check does the file exist
		perror("Error opening player file");
	}
	else
	{
	    printf("-------Initial List of Players-------\n");

		//fgets returns null at the end of the file
		while(fgets(playerArr[lineNum], sizeof(playerArr[lineNum]), fp) != NULL)
		{
			//Get the info from the text file
			printf("%s",playerArr[lineNum]);
			lineNum++;
		}

	    while(count < 20)
	    {
	    	//Moved the values into the other arrays for sorting and storing
	        strcpy(temp[count], playerArr[count]);
	        strcpy(plsort[count], playerArr[count]);
	        strcpy(pshuffle[count], playerArr[count]);
	        count++;
	    }
		fclose(fp);
	}
}
