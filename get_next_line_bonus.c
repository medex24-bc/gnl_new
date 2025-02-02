#include "get_next_line_bonus.h"

// servir a chercher le carcatere '\n' pour savoir si on retourne la string ou pas
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

int	ft_return_position(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char *tmp;
	char		buff[BUFFER_SIZE + 1];
	char		*keep_tmp = NULL;
	char		*final_string = NULL;
	ssize_t		read_bytes;
	char		*ptr_free = NULL;

	read_bytes = 1;
	while (read_bytes != 0)
	{
		if ((ft_strchr(tmp,'\n') != NULL))
		{
			final_string = ft_substr(tmp, 0, ft_return_position(tmp, '\n') + 1);
			keep_tmp = ft_strdup(ft_strchr(tmp, '\n') + 1);
			free(tmp);
			tmp = keep_tmp;
			return (final_string);
		}
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes <= 0)
			break;
		buff[read_bytes] = '\0';
		if (tmp)
		{
			ptr_free = ft_strdup(tmp);
			free(tmp);
			tmp = ft_strjoin(ptr_free, buff);
			free(ptr_free);
		}
		else if (!tmp)
		{
			free(tmp);
			tmp = ft_strdup(buff);
		}
	}
	if (tmp && *tmp && read_bytes == 0)
    {
        final_string = ft_strdup(tmp);
        free(tmp);
        tmp = NULL;
        return (final_string);
    }
	free(tmp);
	tmp = NULL;
	return (NULL); // retour de la derniere ligne sans new line
}


/*int main(void)
{
    int	fd1 = 0;
	int fd2 = 0;
	int fd3 = 0;
	char *string = NULL;

    fd1 = open("./files/file1.txt", O_RDONLY);
	fd2 = open("./files/file2.txt", O_RDONLY);
	fd3 = open("./files/file3.txt", O_RDONLY);
	if (fd1 != -1)
	{
		string = get_next_line(fd1);
		printf("%s", string);
	}
	if (fd2 != -1)
	{
		string = get_next_line(fd2);
		printf("%s", string);
	}
	if (fd3 != -1)
	{
		string = get_next_line(fd3);
		printf("%s", string);
	}

/// DEUXIEME FOIS

	if (fd1 != -1)
	{
		string = get_next_line(fd1);
		printf("%s", string);
	}
	if (fd2 != -1)
	{
		string = get_next_line(fd2);
		printf("%s", string);
	}
	if (fd3 != -1)
	{
		string = get_next_line(fd3);
		printf("%s", string);
	}
	else
	{
		printf("Erreur d'ouverture du fichier\n");
        return (1);
	}
	return (0);
}*/