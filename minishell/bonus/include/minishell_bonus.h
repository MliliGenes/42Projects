/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 14:48:36 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/20 02:19:18 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

# include "execution_bonus.h"
# include "parsing_bonus.h"
# include "signals_bonus.h"

void	shell_loop(t_shell *shell);
void	cleanup_iteration(t_shell *shell);
void	cleanup_shell(t_shell *shell);

#endif
