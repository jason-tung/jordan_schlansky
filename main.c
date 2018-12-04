#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


void main(void){
  key_t key;
  int shmid;
  char *data;

  key = ftok("jordan.scfdsffdhlansky", 'R');
  if (shmid == shmget(key, 200, 0644)){
    shmid = shmget(key, 200, 0644 | IPC_CREAT);
    printf("string was just created\n");
  }
  data = shmat(shmid, (void *)0, 0);
  printf("test\n");
  printf("the shared memory says: %s\n", data);
  char * answer;
  while (!(strcmp(answer, "yes") && strcmp(answer, "no"))){
    printf("do you want to modify the string data? 'yes' or 'no' only.\n");
    fgets(answer, 201, stdin);
  }
  if (!strcmp(answer, "yes")){
    printf("pick new string\n");
    fgets(data, 201, stdin);
    //testing
    printf("new string: %s\n", data);
  }
  answer = 0;
  while (!(strcmp(answer, "yes") && strcmp(answer, "no"))){
    printf("do you want to delete the string data? 'yes' or 'no' only.\n");
    fgets(answer, 201, stdin);
  }
  if (!strcmp(answer, "yes")){
    printf("deleting string\n");
    data = 0;
    //testing
    printf("new string: %s\n", data);
  }
}
