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

void ft_extract(char *buff, ssize_t read_bytes)
{
        variable char *line
        varibale static char *tmp
        variable char *keep_tmp

        if (tmp == NULL) // ca c'est pour le premier premier premier appel de GNL
        {
                malloc tmp selon ft_strlen(buff) + 1;
                copie buff dans tmp;
        }
        malloc keep_tmp selon strlen(tmp);
        copy tmp dans keep_tmp
        free(tmp); // pcq juste apres on va renvoye un nouvelle endroit avec strjoin donc faut eviter fuite de memoire
        strjoin keep_tmp + buff dans tmp; (tmp = strjoin(keep_tmp, buff))
        if (tmp == NULL)
			arret du programme

        si tout va bien
		strsrch '\n' dans tmp
        if (strsrch trouve le '\n')
		1. extract tout ce qu'il y a apres le '\n' dans keep_tmp avec strdup
                2. je copie tout ce qu'il y a avant le '\n' dans la final_string avec le '\n' + '\0'
                3. je remet keep_tmp dans tmp
        free(keep_tmp);
}

char *get_next_line(int fd)
{
		
	variable read_byte de type size_t pour recupe le return de read() ++
	varibale char buff[BUFFER_SIZE] qu'on va utiliser avec la fonction read() ++
	variable de type char * qui nous servira de final_string a renvoyer ++
	
        final_string = NULL;
	j'initialise read_byte à 1 pour que le while ci-dessous puisse demarré ++
	while (read_byte != 0)
	{
	      read_byte recupere retour de read(fd, variable buff de type *char, la size du BUFFER_SIZE); ++
              if (read_byte egale 0 ||read_byte egale -1)
		       arret du programme
              APPEL de la fonction ft_extrac(buff, final_string, read_byte);      
              if (final_string != NULL)
                        return final_string  
              else          
	        la boucle recommence
        }	
}

int main(void)
{
        int     fd;
	char *string = NULL;

        fd = open("./file.txt", O_RDONLY);
        if (fd == -1)
                return (1);
        string = get_next_line(fd);
        while (string != NULL)
        {
                printf("%s", string);
                string = get_next_line(fd);
        }
	return (0);
}
