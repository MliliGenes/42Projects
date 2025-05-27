/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mlil <sel-mlil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:48:36 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/17 17:21:18 by sel-mlil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "execution.h"
# include "parsing.h"
# include "signals.h"

void	shell_loop(t_shell *shell);
void	cleanup_iteration(t_shell *shell);
void	cleanup_shell(t_shell *shell);

#endif
