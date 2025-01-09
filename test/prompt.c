#include "minunit.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "../includes/minishel.h"

MU_TEST(exibe_prompt)
{
	char	buffer[256];
	FILE	*stdout_backup;
	FILE	*temp;

	stdout_backup = stdout;
	temp = tmpfile();
	stdout = temp;
	minishell();
	fflush(stdout);
	rewind(temp);
	fread(buffer, sizeof(char), 255, temp);
	stdout = stdout_backup;
	fclose(temp);
	mu_assert_string_eq("🐧> ", buffer);
}

// Suite de testes
MU_TEST_SUITE(test_suite) {
    MU_RUN_TEST(exibe_prompt);
}

// Função principal para rodar os testes
int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return 0;
}
