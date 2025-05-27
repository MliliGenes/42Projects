/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 23:09:18 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/05/20 02:16:59 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_BONUS_H
# define BUILTINS_BONUS_H

# include "dependencies_bonus.h"
# include "lib_bonus.h"
# include "structs_bonus.h"

int			is_valid_key(char *str);
int			key_exist(t_env_var *env_list, char *key);
t_env_kv	split_key_value(char *arg);
void		free_2d(char **arr);

void		handle_pwd(void);
void		handle_echo(char **args);
int			handle_exit(char **args, t_shell *shell);
void		handle_env(t_env_var *env);
int			handle_export(char **args, t_env_var **env_list);
void		handle_unset(char **args, t_env_var **env_list);
int			handle_cd(char **args, t_env_var *env);

t_env_var	*init_env(char *envp[]);
void		free_env_list(t_env_var *head);
t_env_var	*handle_empty_env(void);
t_env_var	*create_env_var(char *key, char *value);
void		add_env_back(t_env_var **head, t_env_var *node);
void		env_update(t_env_var *env_list, char *key, char *value);

void		print_cd_error(char *prefix, char *path, char *message);
int			update_pwd(t_env_var *env, char *old_pwd);
char		*get_env_value(t_env_var *env_list, char *key);

int			is_builtin(char *cmd);
int			execute_builtin(t_cmd *cmd, t_shell *shell);
int			execute_builtins_with_redir(t_cmd *cmd, t_shell *shell);

#endif
