/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiraud <agiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:04:03 by agiraud           #+#    #+#             */
/*   Updated: 2022/07/22 21:01:49 by agiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			nb_words++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (nb_words);
}

static char	*ft_fill(char const *s, char c, int i, char *tab)
{
	int	k;

	k = i;
	while (s[k] != c && s[k] != '\0')
		k++;
	tab = malloc(sizeof(char) * (k + 1));
	if (!tab)
	{
		free(tab);
		tab = NULL;
		return (NULL);
	}
	k = 0;
	while (s[i] != c && s[i] != '\0')
		tab[k++] = s[i++];
	tab[k] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		size;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	size = ft_count_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = -1;
	while (++j < size)
	{
		while (s[i] == c)
			i++;
		tab[j] = ft_fill(s, c, i, tab[j]);
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	tab[j] = 0;
	return (tab);
}
/*
char	*ft_strdup(const char *src)
{
	char	*cp;
	size_t	i;

	i = 0;
	cp = (char *)malloc(ft_strlen(src) + 1);
	if (!cp)
		return (NULL);
	while (src[i])
	{
		cp[i] = src[i];
		i++;
	}
	cp[i] = '\0';
	return (cp);
}

static size_t	words_count(char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c)
			i++;
		else if (*s == c && i != 0)
		{
			j++;
			i = 0;
		}
		s++;
	}
	if (i != 0)
		j++;
	return (j);
}

static char	*word(char *s, char c)
{
	char	*buf;

	while (*s == c)
		s++;
	buf = s;
	while (*buf && *buf != c)
		buf++;
	*buf = '\0';
	return (ft_strdup(s));
}

static char	**free_arr(char **arr, char *s)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free(s);
	return (NULL);
}

static char	**worker(char **arr, char *s1, char c, size_t j)
{
	size_t	i;
	char	*str;

	str = s1;
	i = 0;
	while (i < j)
	{
		if (*s1 != c)
		{
			arr[i] = word(s1, c);
			if (!arr[i])
				return (free_arr(arr, s1));
			s1 = s1 + ft_strlen(arr[i]);
			i++;
		}
		s1++;
	}
	arr[i] = NULL;
	free(str);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**w_arr;
	char	*s1;
	size_t	j;

	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	j = words_count(s1, c);
	w_arr = (char **)malloc(sizeof(char *) * (j + 1));
	if (!w_arr)
		return (NULL);
	return (worker(w_arr, s1, c, j));
}
*/
