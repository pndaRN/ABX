#ifndef PLAYER_H
#define PLAYER_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdbool.h>

typedef enum { AMMO_PCN, AMMO_POLYMYXIN } AmmoType;

typedef struct {
  float x, y;
  int width, height;
  int hb_offset_x, hb_offset_y;
  int hb_width, hb_height;
  float speed;
  AmmoType current_ammo;
  bool active;
  SDL_Texture *texture;
} Player;

Player player_create(int screen_width, int screen_height,
                     SDL_Renderer *renderer);
void player_update(Player *p, const Uint8 *keystate, float deltaTime,
                   int screenWidth);

#endif
