/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eali <eali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:29:37 by eali              #+#    #+#             */
/*   Updated: 2023/09/05 22:24:45 by eali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
	{
		i++;
	}
	return (i);
}

char	*ft_calloc(void)
{
	char	*str;

	str = (char *)malloc(1 * sizeof(char));
	str[0] = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	ii;
	char	*str;

	if (!s1)
		s1 = ft_calloc();
	if (!s1 || !s2)
		return (NULL);
	str = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	ii = 0;
	while (s2[ii])
	{
		str[i++] = s2[ii++];
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char *s = "askdkjasd\n1asd,jagkd";
// 	char *c = ft_strchr(s, 10);
// 	printf("%s", c);
// }
// int main()
// {
// 	char *s = "ask";
// 	char *d = "ask";
// 	char *c = ft_strjoin(s, d);
// 	printf("%s", c);
// }