# Lista de tarefas
  - Exibir um prompt.
  - Ler comandos do usuário.
  - Analise do input
  - Executar programas externos.
  - Redirecionamento (>, >>, <, <<, |).
  - Controle de sinais.
  - Implementar built-ins (echo, cd, pwd, export, unset, env, exit).

ls ./u | grep -c

token -> <ls> <./u>  <|> <grep> <-c>

struct
  cmd - ls
  arg - ./u

struct
  special - |

struct
  smd - grep
  opt - -c
