#include "get_next_line_bonus.h"

// nous servira pour connaitre la taille a malloc etc
size_t  ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

// sert a copier une string dans une autre et retourne la string copié deja alloué
char    *ft_strdup(char *s)
{
        char    *new_string;
        int             i;
        int             len;

        i = 0;
        len = ft_strlen(s);
        if (s == NULL)
        	return (NULL);
        new_string = (char *)malloc(len + 1);
        if (new_string == NULL)
            return (NULL);
        while (s[i])
        {
            new_string[i] = s[i];
            i++;
        }
        new_string[i] = '\0';
        return (new_string);
}

// va servir a update notre variable static tmp, a retirer la phrase pour le 
// prochain appel de la fonction get_next_line
char    *ft_substr(char *s, unsigned int start, size_t len)
{
        size_t  i;
        char    *final_string;

        i = 0;
        if ((start >= ft_strlen(s)) || len == 0)
        {
            final_string = (char *)malloc(1);
            final_string[i] = '\0';
            return (final_string);
        }
        final_string = (char *)malloc(len + 1);
        if (final_string == NULL)
            return (NULL);
        while (s[start] && i < len)
        {
            final_string[i] = s[start];
            start++;
            i++;
        }
        final_string[i] = '\0';
        return (final_string);
}

// je lutilise dans ma fonction strjoin
void    *ft_memcpy(void *dst, void *src, size_t n)
{
        size_t  i;

        i = 0;
        if (dst == NULL && src == NULL)
            return (NULL);
        while (i < n)
        {
            ((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
            i++;
        }
        return (dst);
}

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
