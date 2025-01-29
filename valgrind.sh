make
valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck --trace-children=yes --suppressions=test/supress.doc ./minishell
