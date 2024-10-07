#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    pid_t pid = fork();

    if (pid == 0) {  
        unsigned long long a = 0, b = 1, temp;
        if (n >= 1){
            printf("%llu\n", 0);
        }
        if (n >= 2){
            printf("%llu\n", 1);  
        }

        for (int i = 2; i < n; ++i) {
            holder = a + b;
            printf("%llu\n", holder);
            a = b;
            b = holder;
        }

        exit(0);
    } 
    else { 
        sleep(10);  
    
        unsigned long long a = 0, b = 1, holder;

        for (int i = 2; i < n; ++i) {
            holder = a + b;
            a = b;
            b = holder;
        }

        holder = a + b;
        printf("%llu\n", holder);  

        a = b;
        b = holder;
        holder = a + b;
        printf("%llu\n", holder);  
        
    }

    return 0;
}
