#ifndef BUILTINS_H
#define BUILTINS_H


/* Builtin prototypes */
int blt_in_ext(_st *nick);
int blt_in_cd(_st *nick);
int st_wk_dir(_st *nick, char *new_dir);
int builtin_help(_st *nick);
int builtin_alias(_st *nick);
int builtin_env(_st *nick);
int builtin_set_env(_st *nick);
int builtin_unset_env(_st *nick);
int builtins_list(_st *nick);

#endif /* BUILTINS_H */
