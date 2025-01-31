#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <readline/readline.h>

// Handler para Ctrl+C (SIGINT)
void handle_sigint(int sig) {
    // Escreve "^C" no terminal
    write(STDOUT_FILENO, "^C\n", 3);

    // Atualiza o estado interno do Readline para nova linha
    rl_on_new_line();

    // Prepara para redesenhar o prompt
    rl_replace_line("", 0); // Limpa o buffer de entrada atual
    rl_redisplay();         // Redesenha o prompt
}

int main() {
    // Configura o handler para Ctrl+C
    signal(SIGINT, handle_sigint);

    // Loop principal do terminal
    while (1) {
        char *input = readline("👽-➤ ");
        if (!input) break; // Sai se receber EOF (Ctrl+D)

        // Processa o comando aqui (exemplo: echo)
        printf("Comando: %s\n", input);
        free(input);
    }

    return 0;
}
