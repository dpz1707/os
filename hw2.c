#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int inputFile, outputFile;
    ssize_t readBytes, writeBytes;
    char buffer[1024];  
    int myUid;

    // open input and outputs, 
    inputFile = open(argv[1], O_RDONLY); // only reading file 1
    outputFile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644); // opens, creates if not there, and truncates in case new information is shorter than previous information in file
    char myName[] = "Daniel Zhang";
    myUid = getuid();  

    char outputBuffer[100];
    snprintf(outputBuffer, sizeof(outputBuffer), "%s %d\n", myName, myUid);

    // write name, uid, and adds a new line 
    writeBytes = write(outputFile, outputBuffer, strlen(outputBuffer));

    // input --> output
    while ((readBytes = read(inputFile, buffer, 1024)) > 0) {  
        writeBytes = write(outputFile, buffer, writeBytes);
    }

    close(inputFile);
    close(outputFile);

    return EXIT_SUCCESS;
}
