#include <fcntl.h> // pour open()
#include <stdio.h> // pour printf()
#include <unistd.h> // pour read()

int main(void)
{
    int fd; // la variable qui va contenir le numéro que retourne la fonction open()
    char buf[26]; // le buffer dans lequel on va stocker les lettres lues

    fd = open("./file.txt", O_RDONLY); // appel open en mode lecture seule (O_RDONLY)
    if (fd == -1) // je vérifie si open a bien ouvert le fichier ou non (-1 = erreur)
        return (1);

    // je while tant que read ne retourne pas 0 (read retourne 0 = plus rien à lire)
    while (read(fd, buf, 25) != 0)
    {
        buf[25] = '\0'; // Assurer que la chaîne soit terminée
        printf("%s\n", buf);
    }

    return (0);
}