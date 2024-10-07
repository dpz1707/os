#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // parent
    if (fork() == 0) { 
        // child 1
        if (fork() == 0) {
            // child 3 
            exit(0);
        }
        exit(0);
    } 
    else {
        if (fork() == 0) {
            // child 2
            if (fork() == 0) {
                // child 4
                exit(0);
            }
            exit(0);
        }
    }
    sleep(1);  // To prevent conflicts
    return 0;
}
