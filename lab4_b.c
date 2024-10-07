#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid1, pid2, pid3, pid4;

    pid1 = fork();
    if (pid1 == 0) {  

        pid3 = fork();
        if (pid3 == 0) {  
        } 
        else {
            sleep(1);
        }
    }

    pid2 = fork();
    if (pid2 == 0) {  
        pid4 = fork();
        if (pid4 == 0) {  
        } 
        else {
            sleep(1);
        }
    }

    sleep(1);
    return 0;
}
