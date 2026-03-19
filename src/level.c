#include "level.h"
#include "procedural.h"

Level level_init(int level, int screen_height, int screen_width) {
    Level l; 
    l.level = level;
    l.wave_count = 0;

    for (int i = 0; i < MAX_WAVES; i++) {
        l.wave[i].is_active = false;
    }

    WaveParams wp = level_to_params(l.level);

    static const SDL_FPoint test_path[] = {
        {640, -50},
        {900, 50},
        {900, 150},
        {640, 200},
    };

    static SDL_FPoint formation_positions[5];

    for (int i = 0; i < 5; i++) {
        formation_positions[i].x = (screen_width / 6.0f) * (i + 1);
        formation_positions[i].y = 200.0f;
    }

    l.wave[0] = wave_init(&wp, test_path[0], test_path[1], test_path[2],
                test_path[3], formation_positions, screen_height, screen_width);
    
    return l;
}

void level_update(Level *l, float deltaTime, Enemy *e, int max_enemies) {
    for (int i = 0; i < MAX_WAVES; i++) {
        if (l->waves[i].is_active){
            wave_update(&l->waves[i], deltaTime, e, max_enemies);
            if(l->wave[i].threshold_crossed) {
                // Need to put in wave vs level logic here
            }
        }
    }
}