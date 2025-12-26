/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tok_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 00:26:40 by toloandr          #+#    #+#             */
/*   Updated: 2025/12/06 11:53:52 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./basic_utils_bonus.h"

int	char_in_delim(char c, const char *delim)
{
	while (*delim)
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

static void	skip_delims(char *str, int *i, const char *delim)
{
	while (str[*i] && char_in_delim(str[*i], delim))
		(*i)++;
}

static void	skip_token(char *str, int *i, const char *delim)
{
	while (str[*i])
	{
		if (char_in_delim(str[*i], delim))
			break ;
		(*i)++;
	}
}

char	*str_tok(char *str, const char *delim)
{
	static int	i = 0;
	static char	*tokens = NULL;
	char		*token;

	if (str != NULL)
	{
		tokens = str;
		i = 0;
	}
	if (tokens == NULL)
		return (NULL);
	skip_delims(tokens, &i, delim);
	if (tokens[i] == '\0')
	{
		tokens = NULL;
		return (NULL);
	}
	token = &tokens[i];
	skip_token(tokens, &i, delim);
	if (tokens[i])
	{
		tokens[i] = '\0';
		i++;
	}
	return (token);
}
