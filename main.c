#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>


int main(void){
  key_t key;
  int shmid;
  char *data;
  key = ftok("jordan", 0);
  shmid = shmget(key, 200, 0644 | IPC_CREAT);
  data = shmat(shmid, (void *)0, 0);
  if (!strlen(data)){
    printf("string just created\n");
  }
  printf("the shared memory says: %s\n", data);

  char * answer = malloc(sizeof(char) * 200);
  while (strcmp(answer, "yes") && strcmp(answer, "no")) {
      printf("do you want to modify the string data? 'yes' or 'no' only.\n");
      fgets(answer, 201, stdin);
      answer = strsep(&answer,"\n");
      printf("your answer: %s\n", answer);
  }
  if (!strcmp(answer, "yes")){
    printf("pick new string\n");
    fgets(data, 201, stdin);
  }
  printf("value of string right now: %s", data);
  char * answer2 = malloc(sizeof(char) * 200);
  while (strcmp(answer2, "yes") && strcmp(answer2, "no")){
    printf("do you want to delete the string data? 'yes' or 'no' only.\n");
    fgets(answer2, 201, stdin);
    answer2 = strsep(&answer2,"\n");
    printf("your answer: %s\n", answer2);
  }
  if (!strcmp(answer2, "yes")){
    printf("deleting string\n");
      shmctl(shmid, IPC_RMID, NULL);
      data = 0;
    //testing
  }
    printf("value of string right now: %s\n", data);
  return 0;
}
