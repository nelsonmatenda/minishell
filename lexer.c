#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum e_token_type {
    WORD,
    PIPE,       // |
    REDIR_IN,   // <
    REDIR_OUT,  // >
    DREDIR_IN,  // <<
    DREDIR_OUT, // >>
} t_token_type;

typedef struct s_token {
    t_token_type type;
    char *value;
    struct s_token *next;
} t_token;

t_token *new_token(t_token_type type, char *value) {
    t_token *token = malloc(sizeof(t_token));
    if (!token)
        return NULL;
    token->type = type;
    token->value = strdup(value);
    token->next = NULL;
    return token;
}

void add_token(t_token **tokens, t_token *new) {
    if (!*tokens) {
        *tokens = new;
    } else {
        t_token *temp = *tokens;
        while (temp->next)
            temp = temp->next;
        temp->next = new;
    }
}

t_token *lexer(const char *input) {
    t_token *tokens = NULL;
    int i = 0;
    while (input[i]) {
        if (isspace(input[i])) { // Ignorar espaços
            i++;
            continue;
        }
        if (input[i] == '|') { // Pipe |
            add_token(&tokens, new_token(PIPE, "|"));
            i++;
        } else if (input[i] == '<' || input[i] == '>') { // Redirecionamentos
            if (input[i] == '<' && input[i + 1] == '<') {
                add_token(&tokens, new_token(DREDIR_IN, "<<"));
                i += 2;
            } else if (input[i] == '>' && input[i + 1] == '>') {
                add_token(&tokens, new_token(DREDIR_OUT, ">>"));
                i += 2;
            } else {
                add_token(&tokens, new_token(input[i] == '<' ? REDIR_IN : REDIR_OUT, (input[i] == '<') ? "<" : ">"));
                i++;
            }
        } else { // Palavras e argumentos
            int start = i;
            while (input[i] && !isspace(input[i]) && input[i] != '|' && input[i] != '<' && input[i] != '>')
                i++;
            char *word = strndup(&input[start], i - start);
            add_token(&tokens, new_token(WORD, word));
            free(word);
        }
    }
    return tokens;
}

// Função para imprimir tokens (para depuração)
void print_tokens(t_token *tokens) {
    while (tokens) {
        printf("Token: %s (Tipo: %d)\n", tokens->value, tokens->type);
        tokens = tokens->next;
    }
}
