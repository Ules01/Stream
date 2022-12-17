#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>

struct player
{
    int life;
    float x;
    float y;
    float ax;
    float vx;
    float ay;
    float vy;
    int power;
};

struct player *init_player(void);
void destroy_player(struct player *p);
void printp(struct player *p);

#endif
