#ifndef LEVEL_H
#define LEVEL_H
#define MAX_WAVES 10

#include "wave.h"
#include "enemy.h"

typedef struct {
    Wave wave[MAX_WAVES];
    int wave_count, level;
} Level;

Level level_init(int level, int screen_height, int screen_width);
void level_update(Level *l, float deltaTime, Enemy *e, int max_enemies);
void level_free(Level *l);

#endif