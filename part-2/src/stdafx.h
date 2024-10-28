#ifndef __STDAFX_H_
#define __STDAFX_H_

#include "raylib.h"
#include "raymath.h"

#define TILE_SIZE 8
#define TILE_SCALE 3

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400

#define WORLD_WIDTH 64 // map width in tiles (aka. 20 * TILE_SIZE)
#define WORLD_HEIGHT 64 // map height in tiles (aka. 20 * TILE_HEIGHT)

#define VIEW_WIDTH 19 // width of the viewable area in tiles (aka. 19 * TILE_SIZE = 9 tiles on west, east + 1 in the center)
#define VIEW_HEIGHT 13 // height of the viewable area in tiles (aka. 13 * TILE_SIZE = 6 tiles on north, south + 1 in the center)

#define VIEW_CENTER_X (10 * TILE_SIZE * TILE_SCALE) 
#define VIEW_CENTER_Y (7 * TILE_SIZE * TILE_SCALE)



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



typedef enum {
    TILE_TYPE_DIRT = 0,
    TILE_TYPE_GRASS,
    TILE_TYPE_TREE,
} tile_type;

typedef struct {
    //int x;
    //int y;
    int type;
    int id;
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


void StartTimer(sTimer* timer, double lifetime);
bool IsTimerDone(sTimer timer);
double GetElapsed(sTimer timer);


extern Texture2D textures[MAX_TEXTURES];

void UpdateViewData(sTile map_data[][WORLD_HEIGHT], int map_width, int map_height, sTile view_data[][VIEW_HEIGHT], int view_width, int view_height, int player_x, int player_y);

void RenderViewData(sTile view_data[][VIEW_HEIGHT], int view_width, int view_height, Rectangle view_pos);
void DrawMapTile(int pos_x, int pos_y, int texture_index_x, int texture_index_y);

#endif
