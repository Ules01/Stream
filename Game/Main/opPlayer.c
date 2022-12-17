#include "opPlayer.h"

float slow_hor(float a);

struct game *chute(struct game *g);

struct game *actu_acc(struct game *g, enum dir d)
{
    int x = g->p->x;
    int y = g->m->h - g->p->y - 2;
    if (g->p->y > 0 || g->m->m[x + g->m->h * y] == ' ')
    {
        g->p->ax = slow_hor(g->p->ax);
        return chute(g);
    }
    if (d == droite)
    {
        if (g->p->ax <= 0)
        {
            g->p->ax = 1;
        }
        else
        {
            g->p->ax = log(g->p->ax)/log(20) + 1 ;
        }
    }
    else if (d == gauche)
    {
        if (g->p->ax >= 0)
            g->p->ax = -1
        else
            g->p->ax = -log(-g->p->ax)/log(20) + 1;
    }
    else
    {
        if (d == haut)
        {
            g->p->ay = 4;
        }
    }
    return g; 
}
