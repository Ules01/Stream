#ifndef MAP_H
#define MAP_H

#include <stdio.h>
#include <stdlib.h>

struct map
{
    int l;
    int h;
    int end; //si le joueur a déjà fini la map a voir si utile ou non
    char *m;
};

struct map *init_map(const char *pathname);
void destroy_map(struct map *m);
void printm(struct map *map);

#endif
