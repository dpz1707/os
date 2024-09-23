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
    char uid_input[20]; // Buffer to store user ID input
    ssize_t uid_bytes_read;

    // Open the input file for reading
    input_fd = open(argv[1], O_RDONLY);
    output_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    // Hardcoded full name
    char full_name[] = "Daniel Zhang";

    // Prompt the user to enter their user ID
    const char prompt_msg[] = "Please enter your user ID: ";
    write(STDOUT_FILENO, prompt_msg, strlen(prompt_msg));

    // Read the user ID from terminal input using system calls
    uid_bytes_read = read(STDIN_FILENO, uid_input, sizeof(uid_input) - 1);
    uid_input[uid_bytes_read] = '\0'; // Null-terminate the string


    // Convert user ID string to integer using strtol()
    char *endptr;
    user_id = strtol(uid_input, &endptr, 10);


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
