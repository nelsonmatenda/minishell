#include <stdio.h>

// Handler para Ctrl+C (SIGINT)
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void handler(int sig) {
    exit(0); // Finaliza o processo ao receber SIGINT
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Código do filho
        signal(SIGINT, handler); // Instala o handler
        while (1); // Loop infinito para teste
    } else {
        // Código do pai
        wait(NULL);
    }
    return 0;
}
