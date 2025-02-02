#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	if (!s && c != '\0')
		return (0);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_free(char *tmp, ssize_t read_bytes, char *final_string)
{
	if (tmp && *tmp && read_bytes == 0)
	{
		final_string = ft_strdup(tmp);
		free(tmp);
		tmp = NULL;
		return (final_string);
	}
	free(tmp);
	return (NULL);
}

char	*ft_verify(char *str, char *buff, int read_bytes)
{
	char	*ptr_free;

	ptr_free = NULL;
	buff[read_bytes] = '\0';
	if (str)
	{
		ptr_free = ft_strdup(str);
		free(str);
		str = ft_strjoin(ptr_free, buff);
		free(ptr_free);
	}
	else if (!str)
	{
		free(str);
		str = ft_strdup(buff);
	}
	return (str);
}

char	*ft_extract(char *tmp)
{
	char	*keep_tmp;

	keep_tmp = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	tmp = keep_tmp;
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	*tmp;
	char		buff[BUFFER_SIZE + 1];
	char		*final_string;
	ssize_t		read_bytes;

	final_string = NULL;
	read_bytes = 1;
	while (read_bytes != 0)
	{
		if ((ft_strchr(tmp, '\n') != NULL))
		{
			final_string = ft_substr(tmp, 0, (ft_strlen(tmp)
						- ft_strlen(ft_strchr(tmp, '\n'))) + 1);
			tmp = ft_extract(tmp);
			return (final_string);
		}
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		tmp = ft_verify(tmp, buff, read_bytes);
	}
	final_string = ft_free(tmp, read_bytes, final_string);
	tmp = NULL;
	return (final_string);
}

/*int main(void)
{
	int	fd = 0;
	char *string = NULL;

	fd = open("./files/file1.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Erreur d'ouverture du fichier\n");
        return (1);
	}
	string = get_next_line(fd);
	while (string != NULL)
	{
		printf("%s", string);
		string = get_next_line(fd);
	}
	return (0);
}*/