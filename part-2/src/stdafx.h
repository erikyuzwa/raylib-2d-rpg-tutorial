#ifndef __STDAFX_H_
#define __STDAFX_H_

#include "raylib.h"
#include "raymath.h"

#define TILE_WIDTH 8
#define TILE_HEIGHT 8

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define MAX_TEXTURES 1
typedef enum {
    TEXTURE_TILEMAP = 0
} texture_asset;

#define MAX_SOUNDS 5
typedef enum {
    SOUND_FOOT_GRASS = 0,
    SOUND_FOOT_STONE,
    SOUND_ATTACK,
    SOUND_DEATH,
    SOUND_COINS
} sound_asset;

#define MAX_MUSIC 2
typedef enum {
    MUSIC_LIGHT_AMBIENCE = 0,
    MUSIC_DARK_AMBIENCE
} music_asset;

#define WORLD_WIDTH 20 // 20 * TILE_WIDTH
#define WORLD_HEIGHT 20 // 20 * TILE_HEIGHT

typedef enum {
    TILE_TYPE_DIRT = 0,
    TILE_TYPE_GRASS,
    TILE_TYPE_TREE,
} tile_type;

typedef struct {
    int x;
    int y;
    int type;
} sTile;

typedef enum {
    ZONE_ALL = 0,
    ZONE_WORLD,
    ZONE_DUNGEON
} eZone;

typedef struct {
    int x;
    int y;
    eZone zone;
    bool isAlive;
    bool isPassable;
    int health;
    int damage;
    int money;
    int experience;
} sEntity;

// https://github.com/raysan5/raylib/wiki/Frequently-Asked-Questions#how-do-i-make-a-timer
typedef struct Timer {
    double startTime;   // Start time (seconds)
    double lifeTime;    // Lifetime (seconds)
    bool isActive;
} sTimer;

void GameStartup();
void GameUpdate();
void GameRender();
void GameShutdown();
void DrawTile(int pos_x, int pos_y, int texture_index_x, int texture_index_y);


void StartTimer(sTimer* timer, double lifetime);
bool IsTimerDone(sTimer timer);
double GetElapsed(sTimer timer);



#endif
