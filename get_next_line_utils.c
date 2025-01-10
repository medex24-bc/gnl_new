#include "get_next_line.h"

// nous servira pour connaitre la taille a malloc etc
size_t  ft_strlen(const char *s)
{
        int     i;

        i = 0;
        while (s[i])
                i++;
        return (i);
}

// je lutilise dans ma fonction strjoin
void    *ft_memcpy(void *dst, const void *src, size_t n)
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

// va servir a update notre variable static tmp, a retirer la phrase pour le 
// prochain appel de la fonction get_next_line
char    *ft_substr(char const *s, unsigned int start, size_t len)
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

// servir a join (copier) le buff dans le tmp
// pour ensuite verifier si tmp contient le '\n'
char    *ft_strjoin(char const *s1, char const *s2)
{
        char    *final_string;

        if (s1 == NULL && s2 == NULL)
                return (NULL);
        if (s1 == NULL)
                return ((char *)s2);
        if (s2 == NULL)
                return ((char *)s1);
        final_string = (char *)malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
        if (final_string == NULL)
                return (NULL);
        ft_memcpy(final_string, s1, ft_strlen(s1));
        ft_memcpy(final_string + ft_strlen(s1), s2, ft_strlen(s2));
        final_string[ft_strlen(s1) + ft_strlen(s2)] = '\0';
        return (final_string);
}

// servir a chercher le carcatere '\n' pour savoir si on retourne la string ou pas
char    *ft_strchr(const char *s, int c)
{
        int     i;

        i = 0;
        while (s[i])
        {
                if (s[i] == (char)c)
                        return (&((char *)s)[i]);
                i++;
        }
        if (c == '\0')
                return (&((char *)s)[i]);
        return (NULL);
}