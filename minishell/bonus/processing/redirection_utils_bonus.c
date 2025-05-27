/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: le-saad <le-saad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 01:11:30 by sel-mlil          #+#    #+#             */
/*   Updated: 2025/05/15 11:41:54 by le-saad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing_bonus.h"

t_redir	*create_redir_node(t_redir_type type, char *file_or_limiter)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir));
	if (!redir || !file_or_limiter)
		return (NULL);
	redir->type = type;
	redir->here_doc_read = -1;
	redir->file_or_limiter = file_or_limiter;
	redir->next = NULL;
	return (redir);
}

void	add_back_redir_node(t_redir **head, t_redir *node)
{
	t_redir	*tmp;

	if (!*head)
	{
		*head = node;
		return ;
	}
	tmp = (*head);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
}

void	free_redirs(t_redir *redirs)
{
	t_redir	*temp;

	while (redirs)
	{
		temp = redirs;
		redirs = redirs->next;
		free(temp->file_or_limiter);
		if (temp->here_doc_read != -1)
			close(temp->here_doc_read);
		free(temp);
	}
}

bool	has_redirections(t_token *start, t_token *end)
{
	while (start && (end == NULL || start->n_index <= end->n_index))
	{
		if (is_redir(start->type))
			return (true);
		start = start->next;
	}
	return (false);
}

t_redir	*get_redirs(t_token *start, t_token *end)
{
	t_redir	*redirs;
	t_redir	*redir_node;

	redirs = NULL;
	while (start && (end == NULL || start->n_index <= end->n_index))
	{
		if (is_redir(start->type))
		{
			redir_node = create_redir_node(token_to_redir_type(start->type),
					ft_strdup(start->next->value));
			if (!redir_node)
			{
				free_redirs(redirs);
				return (NULL);
			}
			add_back_redir_node(&redirs, redir_node);
		}
		start = start->next;
	}
	return (redirs);
}
