#include "get_next_line_bonus.h"

char	*ft_extract(char *tmp)
{
	char	*keep_tmp;

	keep_tmp = ft_strdup(ft_strchr(tmp, '\n') + 1);
	free(tmp);
	tmp = keep_tmp;
	return (tmp);
}

char	*ft_free(char **tmp, ssize_t read_bytes, char *final_string)
{
	if (*tmp && **tmp && read_bytes == 0)
	{
		final_string = ft_strdup(*tmp);
		free(*tmp);
		*tmp = NULL;
		return (final_string);
	}
	if (ft_strchr(*tmp, '\n') != NULL)
	{
		final_string = ft_substr(*tmp, 0, (ft_strlen(*tmp)
					- ft_strlen(ft_strchr(*tmp, '\n'))) + 1);
		*tmp = ft_extract(*tmp);
		return (final_string);
	}
	free(*tmp);
	*tmp = NULL;
	return (NULL);
}

// si tmp est deja plein, sa met dans ptr_free ce qu'il y a dans tmp
// ensuite ca join ptr_free + ptr value de buff dans tmp
char	*ft_verify(char *tmp, char *buff, int read_bytes)
{
	char	*ptr_free;
	size_t	len;

	ptr_free = NULL;
	buff[read_bytes] = '\0';
	if (tmp)
	{
		ptr_free = ft_strdup(tmp);
		free(tmp);
		len = ft_strlen(ptr_free) + ft_strlen(buff);
		tmp = (char *)malloc((sizeof(char) * len) + 1);
		if (tmp == NULL)
			return (NULL);
		ft_memcpy(tmp, ptr_free, ft_strlen(ptr_free) + 1);
		tmp[ft_strlen(ptr_free)] = '\0';
		ft_memcpy(ft_strchr(tmp, '\0'), buff, ft_strlen(buff));
		tmp[len] = '\0';
		free(ptr_free);
	}
	else if (!tmp)
	{
		free(tmp);
		tmp = ft_strdup(buff);
	}
	return (tmp);
}


t_gnl	*ft_multiple_fd(int fd, t_gnl *ptr)
{
	t_gnl	*current;

	current = ptr;
	while (current != NULL)
	{
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	current = (t_gnl *)malloc(sizeof(t_gnl));
	if (current == NULL)
		return (NULL);
	current->fd = fd;
	current->next = NULL;
	return (current);
}

// IMPORTANT: la seul variable qui sera statique dans le bonus est la variable qui garde la tete de lecture de la liste chainee PLUS BESOIN DE TMP
// PUISQUE LES LISTES CHAINEE PRESERVE LES ALLOCATIONS JUSQUA CE QUE TU LES LIBERES UNE APRES LAUTRE
char	*get_next_line(int fd)
{
	static t_gnl	*ptr;
	t_gnl			*new;
	char			*tmp;
	char			*final_string;
	ssize_t			read_bytes;

	final_string = NULL;
	read_bytes = 1;
	tmp = NULL;
	new = NULL;

	if (ptr == NULL)
		ptr = ft_multiple_fd(fd, ptr);
	new = ft_multiple_fd(fd, ptr);
	while (read_bytes != 0)
	{
		if ((ft_strchr(tmp, '\n') != NULL))
			return (ft_free(&tmp, read_bytes, final_string));
		read_bytes = read(fd, new->buff, BUFFER_SIZE);
		if (read_bytes <= 0)
			break ;
		tmp = ft_verify(tmp, new->buff, read_bytes);
	}
	return (ft_free(&tmp, read_bytes, final_string));
}

/*int main(void)
{
    int	fd1 = 0;
	int fd2 = 0;
	int fd3 = 0;
	char *string = NULL;

    fd1 = open("./files/file2.txt", O_RDONLY);
	fd2 = open("./files/file3.txt", O_RDONLY);
	fd3 = open("./files/file4.txt", O_RDONLY);

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
