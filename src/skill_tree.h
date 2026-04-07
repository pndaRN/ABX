#ifndef SKILL_TREE_H
#define SKILL_TREE_H

#include <stdbool.h>

typedef enum {
    AGILITY,
    STRENGTH,
    INTELLIGENCE,
} SkillType;

typedef enum {
    NODE_MOVEMENT_SPEED,
    NODE_PROJECTILE_SPEED,
    NODE_ATTACK_SPEED,
    NODE_DAMAGE,
    NODE_HEALTH_INCREASE,
    MAX_NODES,
} SkillNodeType;

typedef struct {
    SkillType skill_type;
    SkillNodeType node_type;
} SkillNodeDefinition;

#endif
