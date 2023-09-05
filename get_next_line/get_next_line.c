/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eali <eali@student.42abudhabi.ae>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:29:43 by eali              #+#    #+#             */
/*   Updated: 2023/09/05 23:09:47 by eali             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*get_lline(char *s)

{
	int		i;
	char	*line;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		line[i] = s[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*rewrite(char *used)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	while (used[i] != '\0' && used[i] != '\n')
		i++;
	if (used[i] == '\0')
	{
		free(used);
		return (NULL);
	}
	new = malloc((ft_strlen(used) - i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i++;
	j = 0;
	while (used[i] != '\0')
		new[j++] = used[i++];
	new[j] = '\0';
	free(used);
	return (new);
}

char	*get_next_line(int fd)
{
	static char		*reminder;
	char			*buf;
	char			*line;
	ssize_t			nbyte;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	nbyte = 1;
	while (!ft_strchr(reminder, '\n') && nbyte != 0)
	{
		nbyte = read(fd, buf, BUFFER_SIZE);
		if (nbyte == -1)
		{
			return (free(buf), NULL);
		}
		buf[nbyte] = '\0';
		reminder = ft_strjoin(reminder, buf);
	}
	free(buf);
	line = get_lline(reminder);
	reminder = rewrite(reminder);
	if (!reminder)
		free(reminder);
	return (line);
}

// char	*read_allocate(int fd, char *s)
// {
// 	char	*buffer;
// 	int		n;

// 	buffer = malloc((size_t)(BUFFER_SIZE + 2) * sizeof(char));
// 	if (!buffer)
// 		return (NULL);
// 	n = 1;
// 	while (!ft_strchr(s, 10) && (n != 0))
// 	{
// 		n = read(fd, buffer, BUFFER_SIZE);
// 		if (n == -1)
// 		{
// 			free(buffer);
// 			free(s);
// 			return (NULL);
// 		}
// 		buffer[n] = '\0';
// 		s = ft_strjoin(s, buffer);
// 	}
// 	free(buffer);
// 	return (s);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*reminder;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
// 		return (0);
// 	reminder = read_allocate(fd, reminder);
// 	if (!reminder)
// 		return (NULL);
// 	line = get_lline(reminder);
// 	reminder = rewrite(reminder);
// 	return (line);
// }

// int	main(void)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	while (line)
// 	{
// 		printf("\noutput :%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}
// 	// printf("\noutput :%s", line);
// 	// free(line);
// 	// line = get_next_line(fd);
// 	// printf("\noutput :%s", line);
// 	// free(line);
// 	close(fd);
// }

// // int main()
// {
// 	char *s = "hvd\nfj hvs";
// 	char *z = get_line(s);
// 	printf("%s", z);
// }
// int main()
// {
// 	char *s = "hvd\n\n\n\nj hvs";
// 	char *z = rewrite(s);
// 	printf("%s", z);
// }
// int main()
// {
// 	char *s = "hvd\n\n\n\nj hvs";
// 	char *z = read_allocate(3, s);
// 	printf("%s", z);
// }
// int main()
// {
// 	char *name = "test.txt";
// 		int fd = open(name, O_RDONLY);
// 		char *temp;
// 		temp = get_next_line(fd);
// 		printf("%s", temp);
// 		free(temp);
// 		close(fd);
// }