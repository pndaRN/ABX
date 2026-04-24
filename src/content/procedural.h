#ifndef PROCEDURAL_H
#define PROCEDURAL_H

#include <SDL2/SDL.h>

typedef enum {
  FORMATION_TYPE_LINE,
  FORMATION_TYPE_V,
  FORMATION_TYPE_STAGGER,
  FORMATION_TYPE_DIAMOND,
  FORMATION_TYPE_HEXAGON,
  FORMATION_TYPE_CIRCLE,
  FORMATION_TYPE_COUNT,
} FormationType;

typedef enum {
  PATH_ARC,
  PATH_LINE_ISH,
  PATH_TIGHT_HOOK,
  PATH_WIDE_SWEEP,
  PATH_LOOP_DE_LOOP,
} PathType;

typedef struct {
  float x, y, width, height;
} FormationBounds;

typedef struct {
  int total_enemies, max_simult_divers, species_unlocked, level;
  float speed_scalar, spawn_delay, dive_delay, threshold;
  PathType path_type;
  FormationType formation_type;
  FormationParams formation_params;
} WaveParams;

typedef struct {
  FormationType type;
  int max_per_row;
} FormationDefinition;

typedef struct {
  SDL_FPoint control_points[8];
  int num_segments;
} EntryPathData;

typedef struct {
  float x, y;
} SpawnPointFraction;

WaveParams level_to_params(int level);

void generate_formation(SDL_FPoint *positions, int total_enemies,
                        FormationType type, FormationParams params,
                        FormationBounds bounds);

EntryPathData generate_path(PathType type, int screen_height, int screen_width,
                            SDL_FPoint start, SDL_FPoint end);

SDL_FPoint generate_spawn_point(int level, int screen_width, int screen_height);

#endif
