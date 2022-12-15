#include "player.h"

struct player *init_player(void)
{
    struct player *p = calloc(1, sizeof(struct player));
    if (p == NULL)
        return NULL;
    p->life = 6;
    p->power = 1;
    return p;
}

void destroy_player(struct player *p)
{
    free(p);
}

void printp(struct player *p)
{
    printf("*life = %d\n*power = %d\n*vitesse = %f\n*accélération = %f\n*x = %f\n*y = %f\n",
    p->life, p->power, p->v, p->a, p->x, p->y);
}
