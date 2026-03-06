#include "bullet.h"

Bullet bullet_init(Player *player) {
  Bullet b;

  b.width = 8;
  b.height = 23;

  b.x = player->x + (player->width / 2.0f) - (b.width / 2.0f);
  b.y = player->y;

  b.speed = 300;
  b.active = true;

  b.type = player->current_ammo;

  b.texture = player->bullet_texture;

  return b;
}

void bullet_update(Bullet *b, float deltaTime) {
  b->y -= b->speed * deltaTime;
  if (b->y + b->height < 0) {
    b->active = false;
  }
}
