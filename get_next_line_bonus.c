#include "get_next_line.h"

/*
 *
 * FONCTION ICI POUR FAIRE TES BONUS AVEC LES LISTES CHAINEE
 *	
 *
 *	remplace le strjoin par un vrai malloc et une vrai copie dans ton str 
 *
 *	 jai  deja retirer la fonction malloc du fichier utils donc il tu utilsiera cette espace
 *
 *	 pour faire une fonction pour gerer tes bonus avec  les listes chaineee
 *
 *	 va voir chat gpt il ta expliquee le principe
 *
 * */

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
	size_t	len;

	ptr_free = NULL;
	buff[read_bytes] = '\0';
	if (str)
	{
		ptr_free = ft_strdup(str);
		free(str);
		len = ft_strlen(ptr_free) + ft_strlen(buff);
		str = (char *)malloc((sizeof(char) * len) + 1);
		if (str == NULL)
			return (NULL);
		ft_memcpy(str, ptr_free, ft_strlen(ptr_free) + 1);
		str[ft_strlen(ptr_free)] = '\0';
		ft_memcpy(ft_strchr(str, '\0'), buff, ft_strlen(buff));
		str[len] = '\0';
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
	t_gnl		l_buff;
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
		read_bytes = read(fd, l_buff->buff, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		tmp = ft_verify(tmp, buff, read_bytes);
	}
	final_string = ft_free(tmp, read_bytes, final_string);
	tmp = NULL;
	return (final_string);
}

int main(void)
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
}
