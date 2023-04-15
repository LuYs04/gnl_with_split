/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luatshem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:12:11 by luatshem          #+#    #+#             */
/*   Updated: 2023/04/05 17:59:51 by luatshem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *)malloc((ft_strlen(s) * sizeof(char)) + 1);
	if (!p)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*get_next_line(int fd)
{
	static char	**lines;
	char		str[BUFFER_SIZE + 1];
	char		*read_file;
	int 		n;
	
	read_file = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, str, 0))
		return (0);
	while (1)
	{
		n = read(fd, str, BUFFER_SIZE);
		if (n <= 0)
			break ;
		str[n] = '\0';
		read_file = ft_strjoin(read_file, str);
	}
	if (read_file != NULL)
	{
		lines = ft_split_by_lines(read_file, '\n');
		free(read_file);
	}
	if (lines != NULL && *lines != NULL)
	{
		read_file = ft_strdup(*lines);
		free(*lines);
		lines ++;
	}
	return (read_file);
}

/*int main()
{
    int fd = open("42_with_nl", O_RDONLY);
	char *str = get_next_line(fd);
    printf ("call1: [%s]\n", str);
	free(str);
	str = get_next_line(fd);
    printf ("call2: [%s]\n", str);
	free(str);
	str = get_next_line(fd);
    printf ("call3: [%s]\n", str);
	free(str);
	str = get_next_line(fd);
    printf ("call4: [%s]\n", str);
	free(str);
	str = get_next_line(fd);
    printf ("call5: [%s]\n", str);
	free(str);
	str = get_next_line(fd);
    printf ("call6: [%s]\n", str);
	free(str);
	str = get_next_line(fd);
    printf ("call7: [%s]\n", str);
	free(str);
	str = get_next_line(fd);
    printf ("call8: [%s]\n", str);
	free(str);
	str = get_next_line(fd);
    printf ("call9: [%s]\n", str);
	free(str);
	str = get_next_line(fd);
    printf ("call10: [%s]\n", str);
	free(str);
	system("leaks a.out");
	return (0);
}*/
