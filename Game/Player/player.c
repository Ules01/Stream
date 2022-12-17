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
    printf("*life = %d\n*power = %d\n*vitesse horizontale = %f\n*accélération horizontale = %f\n*x = %f\n*vitesse verticale = %f\n *accélération verticale = %f\n*y = %f\n",
    p->life, p->power, p->vx, p->ax, p->x, p->vy, p->ay, p->y);
}
