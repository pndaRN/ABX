#include "procedural.h"

WaveParams level_to_params(int level) {
    WaveParams wp;

    wp.total_enemies = 5;
    wp.max_simult_divers = 1;
    wp.speed_scalar = 1.0f;
    wp.spawn_delay = 0.3f;
    wp.dive_delay = 2.0f;
    wp.threshold = .8;

    return wp;
}