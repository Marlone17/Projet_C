#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>
#include <errno.h>
#include <fcntl.h>


int open(const char *chemin_fichier, int flags, ...) {
    static int (*fonction_de_base)(const char *, int, ...) = NULL;
    if (!fonction_de_base) {
        fonction_de_base = dlsym(RTLD_NEXT, "open");
    }

    //blqouer l'overture de ouvrir /etc/passwd
    if (strcmp(chemin_fichier, "/etc/passwd") == 0) {
        printf("c'est bloqué hehe\n");
        errno = EACCES; // pour afficher le permiison denied
        return -1;
    }

    // sino on appelle la vraie fonction open
    return fonction_de_base(chemin_fichier, flags);
}
