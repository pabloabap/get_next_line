/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 09:04:15 by pabad-ap          #+#    #+#             */
/*   Updated: 2023/11/05 19:57:13 by pabad-ap         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	contador;

	contador = 0;
	if (!s)
		return (0);
	while (s[contador])
		contador ++;
	return (contador);
}

char	*ft_strjoin(char	*s1, char	*s2)
{
	size_t	n;
	char	*p;
	int		i;
	int		j;

	i = 0;
	j = 0;
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	p = malloc(n * sizeof(char));
	if (!p)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0' && s1 != NULL)
		{
			p[i] = s1[i];
			i ++;
		}
	}
	while (s2[j] != '\0')
		p[i++] = s2[j++];
	p[n - 1] = '\0';
	free(s1);
	free(s2);
	return (p);
}

char	*ft_strchr(const char *s, int c)
{
	int	pos;

	pos = 0;
	while (s[pos] != '\0' && s[pos] != (char)c)
		pos ++;
	if (!s || s[pos] == '\0')
		return (NULL);
	return ((char *)(s + pos));
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if ((start + len) <= ft_strlen(s))
		p = malloc((len + 1) * sizeof(char));
	else if (ft_strlen(s) < start)
		p = malloc(sizeof(char));
	else
		p = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (start < ft_strlen(s) && i < len)
	{
		p[i] = s[start];
		start ++;
		i ++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i ++;
	}
	p[i] = '\0';
	return (p);
}
