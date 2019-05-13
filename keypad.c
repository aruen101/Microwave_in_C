#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
enum op {SYNCH, DOOR, LIGHT, EMIT, KEYPAD, RUN, COOKTIME};

main() {
	key_t key;
	int shm_id;
	int *shm;
	int doorstat;
	int oc;

	key=0x520260A;
	//key = ftok("/home/kosuke/IPU", 'a' );
	printf("key= %x\n", key);
	shm_id = shmget(key, sizeof(int)*10, 0666);

	printf(" shm_id = %d\n", shm_id);
	shm = shmat(shm_id,0,0);
	printf("waiting for GO.\n");
	while ( *(shm+SYNCH) == 0 );

	// start application

	int option = 0;

	while(option != 4) {
		option = displayMenu();
		if(option == 1) {
			// assume power level 100, ask for time
			normCook();
		}
		else if(option == 2) {
			// ask for power level, time
		}
		else if(option == 3) {
			// show list of popcorn, pork, chicken, beef, 1 cup water
		}

	}
	printf("goodbye. \n");
}

int displayMenu() {
	int choice = 0;
	printf("Welcome to Microwave 9000! \n");
	printf("Please select an option: \n");
	printf("1. quick cook \n");
	printf("2. set power level and cook \n");
	printf("3. cook by item \n");
	printf("4. quit \n");
	scanf("%d", &choice);
	return choice;

	}

normCook() {
	int cookTime;
	char ch[] = {' '};
	// call to keypad.c
	printf("How long to cook for?");
	scanf("%d", &cookTime);
	//timer(cookTime);
	for(int i = 1; i <= cookTime; i++) {
		printf("%d \n", i);
		// ch = i;
		// write(0, &i, 1);
		sleep(1);
	}
}
