/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dependencies_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 08:49:15 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/21 12:21:23 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEPENDENCIES_BONUS_H
# define DEPENDENCIES_BONUS_H

# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <unistd.h>
# include "/Users/sel-mlil/readline/history.h"
# include "/Users/sel-mlil/readline/readline.h"

# define PROMPT "\001\033[31m\002sel-shell\001\033[0m\002$ "

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define BRIGHT_BLACK "\033[90m"
# define BG_BLACK "\033[40m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"
# define BOLDWHITE "\033[1m\033[37m"

# define REDIR_NEEDS_TARGET "Redirection needs target file"
# define CONSECUTIVE_OPS "Consecutive operators not allowed"
# define CHAINED_REDIRS "Can't chain redirections"
# define INVALID_AFTER_PAREN "Invalid token after parenthesis"
# define INVALID_SEQUENCE "Invalid token sequence"
# define MISPLACED_PAREN "Misplaced parenthesis"
# define PIPE_CONNECT "Pipe must connect commands"
# define UNBALANCED_QUOTES "Unbalanced quotes in command"
# define UNBALANCED_PARENS "Unbalanced parentheses in command"

#endif
