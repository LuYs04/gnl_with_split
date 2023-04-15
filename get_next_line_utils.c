/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 19:08:41 by luatshem          #+#    #+#             */
/*   Updated: 2023/03/04 15:21:06 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

int	count(char *str, char c)
{
	int i;
	int count;

	count = 1;
	i = 0;
	while (str[i])
		if (str[i++] == c)
			count++;
	return (count);
}

void ft_free(char **arr, char *s, char c)
{
	int	i;

	i = 0;
	while (i < count(s, c))
	{
		free(arr[i]);
		arr[i] = 0;
		i++;
	}
	// free(arr);
	// arr = 0;
}

char	**ft_split_by_lines(char *s, char c)
{
	char	**array;
	// char	**tmp;
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	if (!s)
		return ((char **) NULL);
	array = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	while (s[i] && j < count(s, c))
	{
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		array[j++] = ft_substr(s, start, i - start + 1);
		if (s[i])
			i++;
	}
	array[j] = NULL;
	// tmp = array;
	// ft_free(array, s, c);
	return (array);
	// return tmp;
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		sub = (char *)malloc(1);
		*sub = 0;
		return (sub);
	}
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = (char *)malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	while (i < len)
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*t;

	if (!s2)
		return (NULL);
	t = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!t)
		return (NULL);
	i = 0;
	while (s1 != 0 && s1[i])
	{
		t[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		t[i++] = s2[j++];
	t[i] = '\0';
	if(s1)
		free(s1);
	return (t);
}

