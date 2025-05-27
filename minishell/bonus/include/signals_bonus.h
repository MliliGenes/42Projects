/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssbaytri <ssbaytri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 18:55:22 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/20 02:20:09 by ssbaytri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNALS_BONUS_H
# define SIGNALS_BONUS_H

# include "dependencies_bonus.h"

void		handle_sigint(int sig);
void		setup_signals(void);
void		reset_signals_for_child(void);
void		reset_signals_for_heredoc(void);

#endif
