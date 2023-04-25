#ifndef ALX_H
#define ALX_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int _strcmp(char *nick, char *anna);
int _strlen(char *anna);
int _putchar(char x);
char *_strcpy(char *nick, char *anna);
char *_strdup(char *anna);
char *_strcat(char *nick, char *anna);
void p_env(char **anna);
char **_token(const char *str);
int _path(char **nick, char **anna);
void _getenv(char *nick, char **env);
char *cat(char *nick, char *anna, char **ven);
void s_exit(char *anna);
void _execve(char **nick, char *anna);
ssize_t _getline(char **p_line, size_t *n, FILE *stream);
char **_strtok(char *input, char *dlm);
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size);

#endif /*ALX_H*/
