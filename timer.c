#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <unistd.h>
#include <semphore>

#define MAX_SEC 6039
#define KEY 0x520260A

enum op {SYNCH, DOOR, LIGHT, EMIT, KEYPAD, RUN, TIME};

void stopTimer();

int main() {
	key_t key = KEY;
	int shm_id;
	int *shm;
	int time = shm[SYCH+KEYPAD];

  shm_id = shmget(key, sizeof(int)*10, 0666);
  shm = shmat(shm_id,0,0);


	if(shm[SYNCH+DOOR] == 0) { // door is close
		if(shm[SYNCH+RUN] == 1 && time > 0){ // start button push
			shm[SYNCH+EMIT] = 1;
			time--;
	    sleep(1);
		}
		else {
			stopTimer();
		}
	}
	else {
		stopTimer();
	}

}

void stopTimer(){
	shm[SYCH+EMIT] = 0;
	shm[SYCH+RUN] = 0;
	shm[SYCH+KEYPAD] = time;
}
