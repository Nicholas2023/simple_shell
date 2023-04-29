#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


void inicialize_data(_st *nick, int arc, char *argv[], char **env);
void sisifo(char *prompt, _st *nick);
void handle_ctrl_c(int opr UNUSED);
int check_logic_ops(char *array_commands[], int i, char array_operators[]);
void expand_variables(_st *nick);
void expand_alias(_st *nick);
int buffer_add(char *buffer, char *str_to_add);
void tokenize(_st *nick);
int execute(_st *nick);
int builtins_list(_st *nick);
int print_alias(_st *nick, char *alias);
char *get_alias(_st *nick, char *alias);
int set_alias(char *alias_string, _st *nick);
char **tokenize_path(_st *nick);
int find_program(_st *nick);


#endif
