#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int input_fd, output_fd;
    ssize_t bytes_read, bytes_written;
    char buffer[BUFFER_SIZE];
    int user_id;

    // opening input and outputs
    input_fd = open(argv[1], O_RDONLY);
    output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char full_name[] = "Daniel Zhang";
    user_id = getuid(); // uid call
    
    char output_buffer[100]; 
    snprintf(output_buffer, sizeof(output_buffer), "%s %d\n", full_name, user_id);

    // Write the combined full name, user ID, and newline in one go
    bytes_written = write(output_fd, output_buffer, strlen(output_buffer));

    // Copy the contents from the input file to the output file
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        bytes_written = write(output_fd, buffer, bytes_read);
    }

    // Close the file descriptors
    close(input_fd);
    close(output_fd);

    return EXIT_SUCCESS;
}
