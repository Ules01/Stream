#include "map.h"

int parse_map(char *line, size_t size, int *l, int *h)
{
    size_t i = 0;
    while (i < size && line[i] != 'l')
        i++;
    if (i == size)
        return 1;
    *l = 0;
    i++;
    while (i < size && line[i] >= '0' && line[i] <= '9')
    {
        *l = *l * 10 + line[i] - '0';
        i++;
    }
    if (*l == 0 || i == size || line[i] !='h')
        return 1;
    i++;
    *h = 0;
    while (i < size && line[i] >='0' && line[i] <= '9')
    {
        *h = *h * 10 + line[i] - '0';
        i++;
    }
    if (*h == 0)
        return 1;
    return 0;
}

struct map *init_map(const char *pathname)
{
    
    FILE *f = fopen(pathname, "r");
    if (f == NULL)
        return NULL;
    char **line = calloc(1, sizeof(char *));
    size_t size = 0;
    size_t s = 0;
    if ((size = getline(line, &s, f)) == -1)
    {
        fclose(f);
        free(*line);
        free(line);
        return NULL;
    }
    int l = 0;
    int h = 0;
    if (parse_map(*line, size, &l, &h) == 1)
    {
        free(*line);
        free(line);
        fclose(f);
        return NULL;
    }
    free(*line);
    free(line);
    char *li = calloc (l + 1, sizeof(char));
    char *m = calloc(l * h, sizeof(char));
    int j;
    int i = 0;
    int k = 0;
    while(i < h)
    {
        if ((size = fread(li, sizeof(char), l, f)) == -1)
        {
           free(m);
           free(li);
           fclose(f);
           return NULL;
        }
        j = 0;
        while (j < size)
        {
            //printf("i = %d, j = %d, size = %ld\n", i, j, size);
            if (li[j] == '\n')
            {
                while (k < l)
                {
                    m[i * l + k] = ' ';
                    k++;
                }
                k = 0;
                j++;
                i++;
            }
            else
            {
                m[i * l + k] = li[j];
                k++;
                j++;
            }
        }
    }
    while (k < l)
    {
        m[i * l + k] = ' ';
        k++;
    }
    fclose(f);
    free(li);
    //cration structure
    struct map *map = calloc(1, sizeof(struct map));
    if (map == NULL)
        return NULL;
    map->m = m;
    map->l = l;
    map->h = h;
    return map;
}

void destroy_map(struct map *m)
{
    free(m->m);
    free(m);
}

void printm(struct map *map)
{
    printf("hauteur = %d\nlargeur = %d\n",map->h, map->l);
    for (int y = 0; y < map->h; y++)
    {
        for (int x = 0; x < map->l; x++)
        {
            putchar(map->m[y * map->l + x]);
        }
        putchar('\n');
    }
}
