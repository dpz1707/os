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

    // Open the input file for reading
    input_fd = open(argv[1], O_RDONLY);
    output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // Hardcoded full name
    char full_name[] = "Daniel Zhang";

    // Get the user ID using the system call `getuid()`
    user_id = getuid();

    // Write the full name to the output file
    bytes_written = write(output_fd, full_name, strlen(full_name));

    // Write a space separator
    bytes_written = write(output_fd, " ", 1);

    // Write the user ID to the output file
    char uid_str[20];
    snprintf(uid_str, sizeof(uid_str), "%d", user_id);
    bytes_written = write(output_fd, uid_str, strlen(uid_str));

    // Write a newline character
    bytes_written = write(output_fd, "\n", 1);

    // Copy the contents from the input file to the output file
    while ((bytes_read = read(input_fd, buffer, BUFFER_SIZE)) > 0) {
        ssize_t total_written = 0;
        while (total_written < bytes_read) {
            bytes_written = write(output_fd, buffer + total_written, bytes_read - total_written);
            total_written += bytes_written;
        }
    }

    // Close the file descriptors
    close(input_fd);
    close(output_fd);

    return EXIT_SUCCESS;
}
