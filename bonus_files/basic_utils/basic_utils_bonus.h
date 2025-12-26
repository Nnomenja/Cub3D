/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: toloandr <toloandr@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:43:30 by toloandr          #+#    #+#             */
/*   Updated: 2025/12/06 11:53:56 by toloandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASIC_UTILS_BONUS_H
# define BASIC_UTILS_BONUS_H

# include <stdlib.h>
# include <unistd.h> 

int			str_len(char *str);
int			str_cmp(char *str1, char *str2);
int			str_cmp_(char *str1, char *str2);
int			str_n_cmp(const char *s1, const char *s2, size_t n);
char		*str_dup(char *str);
char		*str_dup_delim(char *str);
char		*str_n_join(char *str, char *to_join, int n);
void		str_cat(char *dest, char *src);
void		str_cpy(char *dest, char *src);
char		*str_tok(char *str, const char *delim);
int			is_space(char c);
int			is_alpha(int c);
int			is_alnum(int c);
int			is_digit(int c);
void		print_error(char *err);
void		exit_error(char *s);
void		put_str(char *str);
void		put_str_fd(int fd, char *str);
int			ft_atoi(const char *nptr);
long long	ft_atol(const char *nptr);
char		**ft_split(char const *s, char c);
void		free_split(char **tab);
char		*without_spaces(char *path);

#endif
