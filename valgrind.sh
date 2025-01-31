make
valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck --trace-children=yes --track-origins=yes --track-fds=yes  --keep-debuginfo=yes --suppressions=test/supress.doc --quiet ./minishell
