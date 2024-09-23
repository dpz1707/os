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

    // open input and output files
    inputFile = open(argv[1], O_RDONLY);  // reading only from input file
    outputFile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);  // open, create if not exists, truncate for shorter data in input than already in output
    char myName[] = "Daniel Zhang";
    myUid = getuid();  
    char outputBuffer[100];
    snprintf(outputBuffer, sizeof(outputBuffer), "%s %d\n", myName, myUid);

    // write name, id, and new line
    writeBytes = write(outputFile, outputBuffer, strlen(outputBuffer));

    // input --> output
    while ((readBytes = read(inputFile, buffer, sizeof(buffer))) > 0) {
        writeBytes = write(outputFile, buffer, readBytes);  
    }

    close(inputFile);
    close(outputFile);

    return EXIT_SUCCESS;
}
