/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfigueir <nfigueir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:29:09 by nfigueir          #+#    #+#             */
/*   Updated: 2025/01/24 13:38:16 by nfigueir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_token {
    int type;
    char *value;
    struct s_token *next;
} t_token;

typedef struct s_cmd {
    char **args;
    char *input_file;
    char *output_file;
    int append;
    struct s_cmd *next;
} t_cmd;

// Função para criar um novo comando
t_cmd *new_cmd() {
    t_cmd *cmd = malloc(sizeof(t_cmd));
    if (!cmd)
        return NULL;
    cmd->args = NULL;
    cmd->input_file = NULL;
    cmd->output_file = NULL;
    cmd->append = 0;
    cmd->next = NULL;
    return cmd;
}

// Função para contar os argumentos de um comando
int count_args(t_token *tokens) {
    int count = 0;
    while (tokens && tokens->type == 0) { // 0 = WORD (definir no lexer)
        count++;
        tokens = tokens->next;
    }
    return count;
}

// Função principal do parser
t_cmd *parser(t_token *tokens) {
    t_cmd *cmd = new_cmd();
    t_cmd *current = cmd;

    while (tokens) {
        if (tokens->type == 0) { // Palavra (comando ou argumento)
            int arg_count = count_args(tokens);
            current->args = malloc(sizeof(char *) * (arg_count + 1));
            int i = 0;
            while (tokens && tokens->type == 0) {
                current->args[i++] = strdup(tokens->value);
                tokens = tokens->next;
            }
            current->args[i] = NULL;
        } else if (tokens->type == 1) { // Redirecionamento de entrada ('<')
            tokens = tokens->next;
            if (tokens)
                current->input_file = strdup(tokens->value);
            tokens = tokens->next;
        } else if (tokens->type == 2) { // Redirecionamento de saída ('>')
            tokens = tokens->next;
            if (tokens) {
                current->output_file = strdup(tokens->value);
                current->append = 0;
            }
            tokens = tokens->next;
        } else if (tokens->type == 3) { // Redirecionamento de saída com append ('>>')
            tokens = tokens->next;
            if (tokens) {
                current->output_file = strdup(tokens->value);
                current->append = 1;
            }
            tokens = tokens->next;
        } else if (tokens->type == 4) { // Pipe ('|')
            current->next = new_cmd();
            current = current->next;
            tokens = tokens->next;
        } 
    }
    return cmd;
}

// Função para imprimir os comandos (depuração)
void print_cmds(t_cmd *cmd) {
    while (cmd) {
        printf("Comando: ");
        for (int i = 0; cmd->args && cmd->args[i]; i++)
            printf("%s ", cmd->args[i]);
        printf("\n");
        if (cmd->input_file)
            printf("  Entrada: %s\n", cmd->input_file);
        if (cmd->output_file)
            printf("  Saída: %s (%s)\n", cmd->output_file, cmd->append ? "append" : "overwrite");
        printf("  ---\n");
        cmd = cmd->next;
    }
}

// Testando o parser
int main() {
    // Simulando tokens gerados pelo lexer
    t_token tokens[] = {
        {0, "echo", &tokens[1]},
        {0, "hello", &tokens[2]},
        {4, "|", &tokens[3]},
        {0, "cat", &tokens[4]},
        {1, "<", &tokens[5]},
        {0, "file.txt", &tokens[6]},
        {2, ">", &tokens[7]},
        {0, "output.txt", NULL}
    };

    t_cmd *cmds = parser(tokens);
    print_cmds(cmds);
    return 0;
}
