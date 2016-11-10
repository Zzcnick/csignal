// Signals in C

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal Handling
static void sighandler(int signo) {
  if (signo == SIGINT)
    { // ^C (signal 2)
      printf("\nGoodbye, friend. [Closed by SIGINT]\n");
      exit(0);
    }
  if (signo == SIGUSR1)
    { // (signal 10)
      printf("\nMy parent is %d!\n", getppid());
    }
}

int main() {

  signal (SIGINT, sighandler);
  signal (SIGUSR1, sighandler); 
 
  while (1) {
    printf("Hello, this is %d!\n", getpid());
    sleep(1);
  }
  return 0;

}
