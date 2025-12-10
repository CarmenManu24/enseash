#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 128


void write_str(const char *str) {
    write(STDOUT_FILENO, str, strnlen(str, BUFFER_SIZE));
}

int main() {
    char buffer[BUFFER_SIZE];

    write_str("Bienvenue dans le Shell ENSEA.\n");
    write_str("Pour quitter, tapez 'exit'.\n");

    while (1) {
        // Affichage du prompt
        write_str("enseash % ");

        // Read user input
        ssize_t read_bytes = read(STDIN_FILENO, buffer, BUFFER_SIZE);
        if (read_bytes <= 0) {
            write_str("\n");
            break; // EOF or error → exit shell
        }

        // Replace '\n' with '\0'
        for (int i = 0; i < read_bytes; i++) {
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                break;
            }
        }

        if (strncmp(buffer, "exit", 4) == 0) {
            break;
        }

    }

    write_str("Au revoir !\n");
    return 0;
}
