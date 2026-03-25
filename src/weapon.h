#ifndef WEAPON_H
#define WEAPON_H

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "shared_types.h"

typedef struct {
  WeaponType type;
  const char *texture_path;
  int damage_effective, damage_neutral, damage_ineffective, width, height;
  float speed;
} WeaponDefinition;

const WeaponDefinition *get_weapon_def(WeaponType type);

#endif
