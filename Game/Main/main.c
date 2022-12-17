#include "main.h"

struct map *take_map(int w, char lvl)
{
    char path[13];
    for (int i = 0; i < 12; i++)
        path[i] = WORDS[w][i];
    path[12] = lvl;
    return init_map(path);
}


struct game *init_game(void)
{
    struct game *g = calloc(1, sizeof(struct game));
    if (g == NULL)
        return NULL;
    g->p = init_player();
    if(g->p == NULL)
    {
        free(g);
        return NULL;
    }
    g->lvl = '1';
    g->m = take_map(g->word, g->lvl);
    if (g->m == NULL)
    {
        destroy_player(g->p);
        free(g);
        return NULL;
    }
    return g;
}

void destroy_game(struct game *g)
{
    destroy_player(g->p);
    destroy_map(g->m);
    free(g);
}

void printg(struct game *g)
{
    printf("Player:\n\n");
    printp(g->p);
    printf("\n----------\nMap:\n\n");
    printm(g->m);
}

int main(void)
{
    struct game *g = init_game();
    if (g == NULL)
        return 1;
    printg(g);
    destroy_game(g);
    return 0;
}
