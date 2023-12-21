#include "GUI.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"

void memWrite(int addr, int32_t data);
int memRead(int addr);
int memTest(int addr, int returnArray[], int *currAddr);
void memTestStart(int address, int segments);
//https://stackoverflow.com/questions/5130978/passing-and-returning-variables-in-c
int getRandomNumber(int steps, int limit);
void memTestSimple(int addr);
#define LIMIT 100 //maximum array limit 13000
#define LIMIT2 100000 //for simple memtest

void MainTask(void) {
    while (1) {
    	GUI_Clear();
    	GUI_SetFont(GUI_DEFAULT_FONT);
    	GUI_DispStringAt("Hello world!", (LCD_GetXSize()-100)/2, (LCD_GetYSize()-20)/2);

		//char prompt[] = "[root@uartconsole]:~$ ";
    	printf("\r\nType 'help' to see what you can do.\r\n");

    	//for the editor so it is visible while in the main program loop but clears the file when softresetting or clearing
    	char file[100][100] = { "\0" };
    	while(1){


    		char command[1000] = "\0"; //limit of 1000 chars in a command otherwise it leads so unexpected behaviour
        	printf("[root@uartconsole]:~$ ");


    		scanf("%[^\r\n]%*c",command); //https://www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/

    		//printf("this is what you typed: %s",command);
    		if(strcmp(command,"hello") == 0){
    			printf("hello from the uart console!\r\n");

    		}
    		else if(strcmp(command,"help") == 0){
    		    printf("available commands:\r\n"
    		    		"hello                     -> says hello\r\n"
    		    		"reset                     -> soft reset the microcontroller/program\r\n"
    		    		"                             and clears the FILE-buffer\r\n"
    		    		"help  	                  -> shows this\r\n"
    		    		"echo <string>             -> prints the given string\r\n"
    		    		"display clear             -> clears the display\r\n"
    		    		"display set <string>      -> displays a string on the LCD\r\n"
    		    		"memtest <addr> <segments> -> does an error checking memtest in 100s\r\n"
    		    		"edit                      -> opens the text editor, type '::quit' to close it\r\n"
    		    		"                             (saves automatically, has 100chars per 100lines)\r\n"
    		    		"							  (i think)\r\n"
    		    		"read                      -> (editor command) reads/displays the contents\r\n"
    		    		"                             of the file\r\n"
    		    		"clear                     -> (editor command) clears the FILE-buffer\r\n");

    		}

    		//echo command

    		else if(strcmp(command,"echo") == 0){
    			printf("No arguments given!\r\n");
    		}
    		else if(strncmp(command,"echo ",5) == 0){
    		    char text[sizeof(command)] = "\0";
    		    strcpy(text, command);
    		    for(int i = 5; i < sizeof(text)-5; i++){ // i starts at 4 because of e c h o < TEXT > so it doesnt print "echo "
    		    	printf("%c",text[i]);
    		    }
    		    printf("\r\n"); // add return and newline after completed word

    		}

    		//display command
    		else if((strcmp(command,"display") == 0) || (strcmp(command, "display set") == 0)){
    			printf("No arguments given!\r\n");
    		}
    		else if(strcmp(command, "display clear") == 0){
    			GUI_Clear();
    			printf("Display cleared.\r\n");
    		}
    		else if(strncmp(command, "display set ",12) == 0){
    			char text[sizeof(command)] = "\0";
    			strcpy(text, command);

    			int posX = (LCD_GetXSize()-100)/2; // default value for posX
    			int posY = (LCD_GetYSize()-20)/2; // default value for posY

    			char temp[sizeof(command)] = "\0";
    			int temp_i = 0;
    			for(int i = 12; i < sizeof(text)-12; i++){ // i starts at 12 to filter out the user input string
    				//temp = for constructing the string from text[] to be displayed in the GUI_Disp() func
    				temp[temp_i] = text[i]; //start copying chars from text[] "i" place into temp[] at the temp_i place (0)
    				temp_i++;
    			}
    			GUI_DispStringAt(temp, posX,posY);
    			printf("Displayed string.\r\n");
    		}


    		//memtest stuff

    		else if(strcmp(command, "memtest") == 0){
    			printf("No arguments given!\r\n");

    		}
    		else if(strncmp(command, "memtest ", 8) == 0){


    			//char addressval[sizeof(command)] = "\0";
    			char text[sizeof(command)] = "\0";
    			char getAddr[sizeof(text)] = "\0";
    			char getSeg[sizeof(text)] = "\0";
    			strcpy(text,command+8);
    			int i; //save the sate of i after the for loop because thats where the second arg is
    			for(i = 0; i < sizeof(text); i++){

    				if(text[i] == ' '){
    					//got the address
    					break;
    				}
    				else{
    					getAddr[i] = text[i];
    				}
    			}
    			i++; //get away from the previous space
    			int segmentCounter = 0;
    			for(; i < sizeof(text); i++){
    				if(text[i] == ' '){
    					//got the segments
    					break;
    				}
    				else{
    					getSeg[segmentCounter] = text[i];
    					segmentCounter++;
    				}
    			}

    			printf("Starting memtest at %s for %s segments...\r\n",getAddr,getSeg);
    			int address = strtol(getAddr, NULL, 16);
    			int segments = atoi(getSeg);
    			//printf("addre: %d %x; segments: %d %x\r\n",address,address,segments,segments);
    			memTestStart(address,segments);


    		}


    		//"reboot" command
    		else if(strcmp(command, "reset") == 0){
    			printf("Soft resetting microcontroller...\r\n");
    			return; //dropping back to main.c main() func
    		}


    		//editor
    		else if(strcmp(command, "edit") == 0){

    			int num_lines = 0;
    			//100 maximum lines
    			while (num_lines < 100) {
					char input[100] = "\0";
    				printf("> ");
    				scanf("%[^\r\n]%*c", input);
    				if(strcmp(input, "::quit") == 0){
    					printf("Closing Editor.\r\n");
    					break;
   					}
    				else{

						strcpy(file[num_lines], input); // Copy input to the array
						num_lines++;
    				}

   			    }
    		}
    		else if(strcmp(command, "read") == 0){
    			printf("FILE: \r\n-------\r\n");

    			for(int i = 0; i < 100; i++){
    				if(strcmp(file[i], "\0\0") == 0){ // hide empty lines
    					break;
    				}
    				else{

						printf("%d  %s\r\n",i, file[i]);
    				}
    			}

    			printf("-------\r\nEOF\r\n");
    		}
    		else if(strcmp(command, "clear") == 0){
    			int i = 0;
    			while(strcmp(file[i],"\0\0") != 0){
					strcpy(file[i],"\0");
					i++;
    			}
    			printf("FILE-buffer cleared.\r\n");

    		}


    		else{
    			printf("\r\nType 'help' to see what you can do.\r\n");

    		}



    	}



    	//fail if something really bad happends
    	break;


    }

    printf("ERROR ACCRUED !\r\n");
    printf("Hardlocking...\r\n");
    for(;;);


}


void memTestStart(int address, int segments){
	int currAddr = 0;
	int arr[3];
	int segmentCounter = 0;
	const int segmentLimit = segments; //how many complete array runs in total
	int ret = memTest(address, arr, &currAddr);

	while(ret == 0) {
		for(int i = 0; i < segmentLimit; i++){
			printf("Memory test successful.\r\nMemory test complete.\r\nReturn code: %d\r\nSegment Counter: %d\r\n", ret, segmentCounter);
			segmentCounter++;
			arr[0] = 0;
			arr[1] = 0;
			arr[2] = 0;
			ret = memTest(currAddr, arr, &currAddr);

		}
		printf("Memory test successful.\r\nMemory test complete.\r\nReturn code: %d\r\nSegment Counter: %d\r\n", ret, segmentCounter);

		break;


	}
	if(ret != 0) {
		printf("Memory test failed at: %x: %d Expected: %x\r\nReturn code: %d\r\nSegment Counter: %d\r\n", arr[0], arr[1], arr[2], ret, segmentCounter);
	}
	//printf("Running Memtest simple without error checking...\r\n");
	//memTestSimple(0x60000000);
	//printf("Done.\r\n");
}

// Function definitions

void memWrite(int addr, int32_t data) {
    volatile int *ptr = (int *)addr;
    *ptr = data;
}

int memRead(int addr) {
    volatile int *readaddr = (int *)addr;
    return *readaddr;
}

void memTestSimple(int addr){
	int address = addr;

	printf("Checking memory (not initialized)...\r\n");

	    for (int i = 0; i < LIMIT2; i++) {
	        int val = memRead(address);


	        printf("Memory at address %x -- value: %d\r\n", address, val);
	        address += sizeof(int);
	}
	address = addr;
    printf("Writing values to memory...\r\n");

    // write values to memory
    for (int i = 0; i < LIMIT2; i++) {
        memWrite(address, i);
        printf("Memory at address %x set to value: %d\r\n", address, i);
        address += sizeof(int);
    }

    address = addr;

    printf("Checking memory (forwards)...\r\n");

    for (int i = 0; i < LIMIT2; i++) {
        int val = memRead(address);


        printf("Memory at address %x -- value: %d\r\n", address, val);
        address += sizeof(int);
    }

    printf("Memory test successful.\r\n");

    //address = addr; don't reset address so it can count down from previous test
    address -= sizeof(int);
    printf("Checking memory (backwards)...\r\n");

    for (int i = LIMIT2; i > 0; i--) {
        int val = memRead(address);

        printf("Memory at address %x -- value: %d\r\n", address, val);
        address -= sizeof(int);
    }

    //printf("Memory test successful.\r\n");
    address = addr;
    printf("Checking memory (random)...\r\n");

       for (int i = 0; i < LIMIT2; i++) {

    	   int randomNum = getRandomNumber(i, LIMIT2);
    	   //printf("FIRST random num: %d, address wihtout rand: %x",randomNum, address);
    	   address += randomNum;
    	   //printf("SECOND addres with rand: %x", address);
           int val = memRead(address);

           printf("Memory at address %x -- value: %d\r\n", address, val);
           address = addr;
       }


}

int memTest(int addr, int returnArray[], int *currAddr) {
    int address = addr;
    int dataArr[LIMIT][2] = { 0 };

    printf("Initializing data array...\r\n");

    // Initialize dataArr
    for (int i = 0; i < LIMIT; i++) {
        dataArr[i][0] = address;
        dataArr[i][1] = i; // Store the expected value in the second column
        printf("Data Array[%d] - Address: %x, Expected Value: %d\r\n", i, address, i);
        address += sizeof(int);
    }

    /*
     * 	Array structure
     *
     * 	|0x60000000|0x60000004|0x60000008|... (address)
     *  ----------------------------------
     *  |	  1    |     2    |     3    |... (value)
     *
     */


    address = addr;

    printf("Writing values to memory...\r\n");

    // write values to memory
    for (int i = 0; i < LIMIT; i++) {
        memWrite(address, i);
        printf("Memory at address %x set to value: %d\r\n", address, i);
        address += sizeof(int);
    }

    address = addr;

    printf("Checking memory (forwards)...\r\n");

    for (int i = 0; i < LIMIT; i++) {
        int val = memRead(address);

        //find the index in dataArr (which is the the current address)
        int indexInArray = -1;
        for (int j = 0; j < LIMIT; j++) {
            if (address == dataArr[j][0]) {
                indexInArray = j;
                break;
            }
        }

        if (val != dataArr[indexInArray][1]) {
            returnArray[0] = address;
            returnArray[1] = val;
            returnArray[2] = dataArr[indexInArray][1];
            //printf("Memory test failed at: %x: %d Expected: %d\r\n", address, val, dataArr[indexInArray][1]);
            return -1;
        }

        printf("Memory at address %x matches expected value: %d\r\n", address, val);
        address += sizeof(int);
    }
    *currAddr = address;
    printf("Memory test successful.\r\n");

    //address = addr; don't reset address so it can count down from previous test
    address -= sizeof(int);
    printf("Checking memory (backwards)...\r\n");

    for (int i = LIMIT; i > 0; i--) {
        int val = memRead(address);

        // find the index in dataArr (which is the the current address)
        int indexInArray = -1;
        for (int j = LIMIT; j > -1; j--) {
            if (address == dataArr[j][0]) {
                indexInArray = j;
                break;
            }
        }

        if (val != dataArr[indexInArray][1]) {
            returnArray[0] = address;
            returnArray[1] = val;
            returnArray[2] = dataArr[indexInArray][1];
            //printf("Memory test failed at: %x: %d Expected: %d\r\n", address, val, dataArr[indexInArray][1]);
            return -1;
        }

        printf("Memory at address %x matches expected value: %d\r\n", address, val);
        address -= sizeof(int);
    }

    //printf("Memory test successful.\r\n");
    address = addr;
    printf("Checking memory (random)...\r\n");

       for (int i = 0; i < LIMIT; i++) {

    	   int randomNum = getRandomNumber(i, LIMIT);
    	   //printf("FIRST random num: %d, address wihtout rand: %x",randomNum, address);
    	   address += randomNum;
    	   //printf("SECOND addres with rand: %x", address);
           int val = memRead(address);
           //printf("THIRD val: %d",val);

           // find the index in dataArr (which is the the current address)
           int indexInArray = -1;
           for (int j = 0; j < LIMIT; j++) {
               if (address == dataArr[j][0]) {
                   indexInArray = j;
                  // printf("%d",indexInArray);
                   break;
               }
           }

           if (val != dataArr[indexInArray][1]) {
               returnArray[0] = address;
               returnArray[1] = val;
               returnArray[2] = dataArr[indexInArray][1];
               //printf("Memory test failed at: %x: %d Expected: %d\r\n", address, val, dataArr[indexInArray][1]);
               return -1;
           }

           printf("Memory at address %x matches expected value: %d\r\n", address, val);
           address = addr;
       }

       //printf("Memory test successful.\r\n");
    return 0;
}
int getRandomNumber(int steps, int limit){ // steps --> something that changes everytime
	int reroll = 54321; //any random number
	int seed = 123123123; //any random number
	int max = limit;
	int step = steps;
	while(1){
		srand(seed + step);
		int num = rand() % max;
		if(num % 4 == 0){
			return num;
		}
		else{
			//reroll if it is not a vaild address
			step += reroll;
		}
	}
}

