#ifndef MAIN_H
#define MAIN_H

#include "../Map/map.h"
#include "../Player/player.h"


char *WORDS[] = { "Map/rep/gar/", "Map/rep/hel/", "Map/rep/cas/", "Map/rep/par/"};

struct game
{
    struct player *p;
    struct map *m;
    int word;
    char lvl;
};

#endif
