#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    printf("Program will exit because there is a SIGINT signal.\n");
    exit(0);
  }
  if(signo == SIGUSR1){
    printf("Parent PID: %d\n", getppid());
  }
}

int main(){

  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  
  while(1){
    printf("Program PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
