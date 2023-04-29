#ifndef BUILTINS_H
#define BUILTINS_H


/* Builtin prototypes */
int builtin_exit(_st *nick);
int builtin_cd(_st *nick);
int set_work_directory(_st *nick, char *new_dir);
int builtin_help(_st *nick);
int builtin_alias(_st *nick);
int builtin_env(_st *nick);
int builtin_set_env(_st *nick);
int builtin_unset_env(_st *nick);
int builtins_list(_st *nick);

#endif /* BUILTINS_H */
