#include "GUI.h"
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "stm32f723e_discovery.h"


void memWrite(int addr, int32_t data);
int memRead(int addr);
int memTest(int addr, int returnArray[], int *currAddr);
void memTestStart(int address, int segments);
//https://stackoverflow.com/questions/5130978/passing-and-returning-variables-in-c
int getRandomNumber(int steps, int limit);
void memTestSimple(int addr);

void Delay(int num);

void commandEcho(char * command);
void commandDisplayClear();
void commandDisplaySet(char * command);
void commandMemTest(char * command);
void commandHello();
void commandHelp();
void commandGame();

#define CHAR_LIMIT 100
#define MAX_LINES 100




#define LIMIT 100 //maximum array limit 13000
#define LIMIT2 100000 //for simple memtest
//for the sleep thing (experimental)
//#define STEPS_PER_SEC 1000

//TODO:  When moving pipes it displays parts of the pipes at closed places


void MainTask(void) {
    while (1) {
    	GUI_Clear();
    	GUI_SetFont(GUI_DEFAULT_FONT);
    	GUI_SetColor(GUI_WHITE);
    	GUI_DispStringAt("Hello world!", (LCD_GetXSize()-100)/2, (LCD_GetYSize()-20)/2);

		//char prompt[] = "[root@uartconsole]:~$ ";
    	printf("\r\nType 'help' to see what you can do.\r\n");

    	//for the editor so it is visible while in the main program loop but clears the file when softresetting or clearing
    	char file[CHAR_LIMIT][MAX_LINES] = { "\0" };
    	while(1){


    		char command[CHAR_LIMIT] = "\0"; //limit of 100 chars in a command otherwise it leads so unexpected behaviour
        	printf("[root@uartconsole]:~$ ");


    		scanf("%[^\r\n]%*c",command); //https://www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/

    		//printf("this is what you typed: %s",command);


    		//hello command
    		if(strcmp(command,"hello") == 0){
    			commandHello();

    		}
    		//help command
    		else if(strcmp(command,"help") == 0){
    		    commandHelp();

    		}

    		//echo command

    		else if(strcmp(command,"echo") == 0){
    			printf("No arguments given!\r\n");
    		}
    		else if(strncmp(command,"echo ",5) == 0){
    		    commandEcho(command);

    		}

    		//display command
    		else if((strcmp(command,"display") == 0) || (strcmp(command, "display set") == 0)){
    			printf("No arguments given!\r\n");
    		}
    		else if(strcmp(command, "display clear") == 0){
    			commandDisplayClear();

    		}
    		else if(strncmp(command, "display set ",12) == 0){
    			commandDisplaySet(command);
    		}


    		//memtest stuff

    		else if(strcmp(command, "memtest") == 0){
    			printf("No arguments given!\r\n");

    		}
    		else if(strncmp(command, "memtest ", 8) == 0){

    			commandMemTest(command);

    		}

    		//game (experimental)
    		else if(strcmp(command, "game") == 0){
    			commandGame();
    		}



    		//"reboot" command
    		else if(strcmp(command, "reset") == 0){
    			printf("Soft resetting microcontroller...\r\n");
    			return; //dropping back to main.c main() func must be called inside MainTask() --> not from other func
    		}

    		//--- editor commands not intended for script use ---
    		//editor
    		else if(strcmp(command, "edit") == 0){

    			int num_lines = 0;

    			//1000 maximum lines
    			while (num_lines < MAX_LINES) {
					char input[CHAR_LIMIT] = "\0"; //1000 chars in one line
    				printf("> ");
    				scanf("%[^\r\n]%*c", input);
    				if(strcmp(input, "!q") == 0){
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

    			for(int i = 0; i < MAX_LINES; i++){
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
    		//scripting stuff done directly in main for simplicity
    		else if(strcmp(command, "run") == 0){
    			if(strcmp(file[0], "!script") == 0){
    				//running script
    				int i = 1;
    				//bool loop = false;
    				while(strcmp(file[i], "!endscript") != 0){


    					//parsing and executing


    					if(strcmp(file[i],"echo") == 0){
    						printf("Syntax error at line %d String expected!\r\n", i);
    						break;
    					}
    					else if(strncmp(file[i], "echo ",5) == 0){
    						commandEcho(file[i]);
    					}


    					//display command
    					else if((strcmp(file[i],"display") == 0) || (strcmp(file[i], "display set") == 0)){
    						printf("Syntax error at line %d\r\n",i);
    						break;
    					}
    					else if(strcmp(file[i], "display clear") == 0){
    						commandDisplayClear();
    					}
    					else if(strncmp(file[i], "display set ",12) == 0){
    						commandDisplaySet(file[i]);
    					}


    					//hello command

    					else if(strcmp(file[i], "hello") == 0){
    						commandHello();
    					}

    					//help command

    					else if(strcmp(file[i], "help") == 0){
    						commandHelp();
    					}
    					else if(strcmp(file[i], "memtest") == 0){
    						printf("No arguments given!\r\n");
    					}
    					else if(strncmp(file[i], "memtest ", 8) == 0){
    						commandMemTest(file[i]);
    					}

    					else if(strcmp(file[i], "loop") == 0){
    						//loop = true;
    					}

    					/*
    					else if(strcmp(file[i], "sleep") == 0){
    						printf("Syntax error at line %d Value expected\r\n", i);
    						break;
    					}
    					else if(strncmp(file[i],"sleep ", 6) == 0){
    						int sleepnum = 0;
    						char text[100] = "\0";
    						char sleepchars[sizeof(text)];
    						int temp_i = 0;
   							strcpy(text, file[i]);
    						for(int i = 6; i < sizeof(sleepchars); i++){
    							sleepchars[temp_i] = text[i];
    							temp_i++;
    						}
    						sleepnum = atoi(sleepchars);
    						printf("%d\r\n",sleepnum);
    						for(int a = 0; a < sleepnum; a++){
    							for(int b = 0; b < STEPS_PER_SEC; b++){
    								asm volatile("nop");
    							}
    						}
    					}*/

    					else{
    						printf("Failed to parse FILE. Check the syntax!\r\n");
    						break;
    					}

    					i++;


    				}
    				//printf("exit while loop\r\n");
    			}
    			else{
    				printf("No script found in buffer!\r\n");
    			}
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

void commandEcho(char *command){
	//copy org val into temp val
	char cpy_command[CHAR_LIMIT] = "\0";
	strcpy(cpy_command, command);


	for(int i = 5; i < CHAR_LIMIT; i++){ // i starts at 5 because of e c h o < TEXT > so it doesnt print "echo "
		printf("%c",cpy_command[i]);
	}
	printf("\r\n"); // add return and newline after completed word
}

void commandDisplayClear(){
	GUI_Clear();
    printf("Display cleared.\r\n");
}

void commandDisplaySet(char * command){
	char text[CHAR_LIMIT] = "\0";
	strcpy(text, command);

	int posX = (LCD_GetXSize()-100)/2; // default value for posX
	int posY = (LCD_GetYSize()-20)/2; // default value for posY

	char temp[CHAR_LIMIT] = "\0";
	int temp_i = 0;
	for(int i = 12; i < CHAR_LIMIT-12; i++){ // i starts at 12 to filter out the user input string
		//temp = for constructing the string from text[] to be displayed in the GUI_Disp() func
		temp[temp_i] = text[i]; //start copying chars from text[] "i" place into temp[] at the temp_i place (0)
		temp_i++;
	}
	GUI_DispStringAt(temp, posX,posY);
	printf("Displayed string.\r\n");
}
void commandMemTest(char * command){


	//char addressval[sizeof(command)] = "\0";
	char text[CHAR_LIMIT] = "\0";
	char getAddr[CHAR_LIMIT] = "\0";
	char getSeg[CHAR_LIMIT] = "\0";
	strcpy(text,command+8);
	int i; //save the sate of i after the for loop because thats where the second arg is
	for(i = 0; i < CHAR_LIMIT; i++){

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
	for(; i < CHAR_LIMIT; i++){
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

void commandHello(){
	printf("hello from the uart console!\r\n");
}

void commandHelp(){
	printf("available commands:\r\n"
	    		    		"hello                     -> says hello\r\n"
	    		    		"reset                     -> soft reset the microcontroller/program\r\n"
	    		    		"                             and clears the FILE-buffer\r\n"
	    		    		"help  	                  -> shows this\r\n"
	    		    		"echo <string>             -> prints the given string\r\n"
	    		    		"display clear             -> clears the display\r\n"
	    		    		"display set <string>      -> displays a string on the LCD\r\n"
	    		    		"memtest <addr> <segments> -> does an error checking memtest in 100s\r\n"
	    		    		"edit                      -> opens the text editor, type '!q' to close it\r\n"
	    		    		"                             (saves automatically, has 100chars per 100lines)\r\n"
	    		    		"							  (i think)\r\n"
	    		    		"read                      -> (editor command) reads/displays the contents\r\n"
	    		    		"                             of the file\r\n"
	    		    		"clear                     -> (editor command) clears the FILE-buffer\r\n"
	    		    		"run                       -> runs a script (if found) in the FILE-buffer\r\n"
	    		    		"!script to define one !endscript to close it;\r\n"
	    		    		"	supported commands: \r\n"
							"	------------------- \r\n"
	    		    		"	echo, display clear/set, \r\n"
	    		    		"	hello, help, reset(use with caution), \r\n"
	    		    		"	memtest \r\n");
}


void commandGame(){
	printf("look at the LCD\r\n");
	int x = 50;
	int stepsUp = 30;
	bool btn_pressed = false;
	//int y = 50;
	GUI_Clear();
	int Vpos = 100;

	//set the background color
	GUI_SetColor(GUI_CYAN);
	GUI_FillRect(0,0,240,240);

	//rectangle

	int RectXPos = 240;
	int Rect2XPos = 120;
	int RectWidth = 20;

	//rng
	int randSteps = 1;
	int seed = 12437899;
	int genNum = 0;

	while(true){

		//drawing character

		//generate a random position of top and bottom bars


		//randPosTop -= 20;

		GUI_SetColor(GUI_CYAN);

		GUI_FillRect(x,Vpos-5,x+5,Vpos+5);
		//printf("%d",GUI_GetTime());
		Delay(5);
		GUI_SetColor(GUI_YELLOW);
		GUI_FillRect(x,Vpos,x+5,Vpos+5);
		Delay(5);

		int pipeDistance = 180;
		//predefined state of pipes first num is TOP second is BOTTOM (pairs)
		//they get selected randomly

		//leave 70 as a space between
		int posPipe1[10][2] = { {40, 110},
								 {20, 90},
								 {130, 200},
								 {75, 145},
								 {90, 180},
								 {100, 170},
								 {50, 130},
								 {35, 105},
								 {220,150},
								 {200, 130} };


		int posPipe2[10][2] = { {40, 110},
								{20, 90},
								{130, 200},
								{75, 145},
								{90, 180},
								{100, 170},
								{50, 130},
								{35, 105},
								{220,150},
								{200, 130} };


		//first pipe top and bottom
		//set standard positin at first run...
		int PosTop = posPipe1[genNum][0]; //first [] --> the value at the random index
										  //second [] --> the value corresponding to it aka the second value of the first index
		int PosBottom = posPipe1[genNum][1];
		//printf("POS1:   %d    %d\r\n", PosTop, PosBottom);





		//second pipe top and bottom, set default position
		int PosTop2 = posPipe2[genNum][0];
		int PosBottom2 = posPipe2[genNum][1];

		//printf("POS1:   %d    %d\r\n", PosTop2, PosBottom2);
		//coutner for pseudo rng
		randSteps++;


		//regenerate pipes
		if(Rect2XPos < -20){
			//first pipe
			GUI_SetColor(GUI_CYAN);

			GUI_FillRect(Rect2XPos+RectWidth,PosBottom2,Rect2XPos+RectWidth,240);

			GUI_FillRect(Rect2XPos+RectWidth,0,Rect2XPos+RectWidth,PosTop2);
			Rect2XPos = RectXPos + (pipeDistance / 2);
			GUI_SetColor(GUI_GREEN);

			//generate new position and set the variable for the next drawcall

			srand(seed + randSteps);
			genNum = rand() % 10; // get random number from 0-9 for array

		}
		if(RectXPos < -20){
			//second pipe
			GUI_SetColor(GUI_CYAN);

			GUI_FillRect(RectXPos+RectWidth,PosBottom,RectXPos+RectWidth,240);

			GUI_FillRect(RectXPos+RectWidth,0,RectXPos+RectWidth,PosTop);
			RectXPos = Rect2XPos + (pipeDistance / 2);
			GUI_SetColor(GUI_GREEN);


			//generate new position and set the variable for the next drawcall
			srand(seed+13231233 + randSteps); //change the seed
			genNum = rand() % 10; // get random number from 0-9 for array
		}

		//drawing second pipe
		GUI_SetColor(GUI_GREEN);
							//v--- bottom bar	 v---limit bottom bar (to the edge of the screen
		GUI_FillRect(RectXPos,PosBottom,RectXPos+RectWidth,240);
			//                v--- limit top bar (to the edge of the screen
												//  v--- top bar
		GUI_FillRect(RectXPos,0,RectXPos+RectWidth,PosTop);

		Delay(10);

		GUI_SetColor(GUI_CYAN);


		GUI_FillRect(RectXPos+RectWidth,PosBottom,RectXPos+RectWidth,240);

		GUI_FillRect(RectXPos+RectWidth,0,RectXPos+RectWidth,PosTop);
		Delay(10);
		RectXPos--;


		//drawing first pipe
		GUI_SetColor(GUI_GREEN);

		GUI_FillRect(Rect2XPos,PosBottom2,Rect2XPos+RectWidth,240);

		GUI_FillRect(Rect2XPos,0,Rect2XPos+RectWidth,PosTop2);

		Delay(10);

		GUI_SetColor(GUI_CYAN);


		GUI_FillRect(Rect2XPos+RectWidth,PosBottom2,Rect2XPos+RectWidth,240);

		GUI_FillRect(Rect2XPos+RectWidth,0,Rect2XPos+RectWidth,PosTop2);
		Delay(10);
		Rect2XPos--;


		Vpos++;



		//borders

		if(Vpos > 230){
			//gameover
			GUI_SetColor(GUI_WHITE);
	    	GUI_DispStringAt("Game Over!", (LCD_GetXSize()-100)/2, (LCD_GetYSize()-20)/2);
			break;
		}
		if(Vpos < 1){
			Vpos = 5;
		}

		//button events

		int btnStateOld = BSP_PB_GetState(BUTTON_WAKEUP);
		if(btnStateOld == 1 && !btn_pressed){
			printf("button pressed\r\n");
			//delete rectangle at old posision
			GUI_SetColor(GUI_CYAN);
			GUI_FillRect(x,Vpos-5,x+5,Vpos+5);
			Vpos -= stepsUp;
			GUI_SetColor(GUI_GREEN);
			btn_pressed = true;

		}
		int btnStateNew = BSP_PB_GetState(BUTTON_WAKEUP);
		if(btnStateNew == 0){
			btn_pressed = false;
		}



	}



}

//bitte nicht anschauen
volatile void Delay(int num){
	for(int i = 0; i < num*1000; i++){
		asm("nop");
	}
}





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

