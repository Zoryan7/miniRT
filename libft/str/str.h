/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etessoer <etessoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:28:53 by etessoer          #+#    #+#             */
/*   Updated: 2026/04/15 10:22:49 by etessoer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H
# include "../libc/libc.h"

typedef struct s_itoa_info
{
	long	nb;
	int		len;
	int		zero;
	int		ini_len;
}	t_itoa_float;

int		ft_strschr(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s1, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_ff(char *s1, char const *s2);
char	*ft_strjoin_fs(char *s1, char *s2);
char	*ft_strjoin_df(char *s1, char *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t siz);
size_t	ft_strlcat(char *dest, const char *src, size_t siz);
void	ft_free_tab(char **split);
int		ft_len_split(char **split);
char	**ft_split_whitespace(char const *s);
long	ft_atol(const char *nptr);
char	*ft_itoa_int(int n);
float	ft_atof(char *src);
char	*ft_itoa_float(float n);
char	*ft_clamp_name(char *str, size_t len);

#endif