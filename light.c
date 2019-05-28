#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

enum op (SYNCH, DOOR, LIGHT, EMIT, KEYPAD, RUN, TIME);

int main()
{
    int shmid;
    int SHMSZ = sizeof(int*10);
    key_t key = 0x520260a;
    char *shm, *s;

    if((shmid = shmget(key, SHMSZ, 0666)) < 0) {
        perror("shmget didn't work");
        exit(1);
    }

    shm = shmat(shmid, 0, 0);


    if (*(shm+DOOR) == 1){
        printf("Light is ON");
    }
    if (*(shm+DOOR) == 0 && *(shm+RUN) == 1){
        printf("Light is ON");
    }
    else {printf("Light is OFF");}

}
