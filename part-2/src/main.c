// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// 
/*
#include <raylib.h>

#define TILE_SIZE 32         // Each tile is 32x32 pixels
#define MAP_WIDTH 200        // Width of the map in tiles (200x200)
#define MAP_HEIGHT 200       // Height of the map in tiles
#define VIEW_WIDTH 15        // Viewport width in tiles (15x15)
#define VIEW_HEIGHT 11       // Viewport height in tiles

typedef struct {
    int id;                  // Tile ID for different types
    Color color;             // Color for rendering each tile type
} Tile;

// Function to render visible portion of the map
void RenderVisibleMap(Tile map[MAP_HEIGHT][MAP_WIDTH], int viewX, int viewY) {
    for (int y = 0; y < VIEW_HEIGHT; y++) {
        for (int x = 0; x < VIEW_WIDTH; x++) {
            int mapX = viewX + x;
            int mapY = viewY + y;

            
            int screenX = x * TILE_SIZE;
            int screenY = y * TILE_SIZE;


            if (mapX >= 0 && mapX < MAP_WIDTH && mapY >= 0 && mapY < MAP_HEIGHT) {
                Tile tile = map[mapY][mapX];
                DrawRectangle(screenX, screenY, TILE_SIZE, TILE_SIZE, tile.color);
            }
            else {
                DrawRectangle(screenX, screenY, TILE_SIZE, TILE_SIZE, BLACK);
            }
        }
    }
}

int main() {
    // Initialize Raylib
    InitWindow(800, 400, "Ultima III Tilemap");
    SetTargetFPS(60);

    // Create a large map with varied tile types (grass, water, mountains)
    Tile map[MAP_HEIGHT][MAP_WIDTH];
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if ((x + y) % 3 == 0) map[y][x] = (Tile){ 1, BLUE };       // Water
            else if ((x + y) % 5 == 0) map[y][x] = (Tile){ 2, BROWN };  // Mountains
            else map[y][x] = (Tile){ 0, GREEN };                        // Grass
        }
    }

    // Initial player position at the center of the map
    int playerX = 5 * TILE_SIZE; //MAP_WIDTH / 2;
    int playerY = 5 * TILE_SIZE; //MAP_HEIGHT / 2;

    while (!WindowShouldClose()) {
        // Move player based on key input
        if (IsKeyPressed(KEY_RIGHT) && playerX < MAP_WIDTH - 1) {
            playerX += 1;
        }
        if (IsKeyPressed(KEY_LEFT) && playerX > 0) {
            playerX -= 1;
        }
        if (IsKeyPressed(KEY_DOWN) && playerY < MAP_HEIGHT - 1) {
            playerY += 1;
        }
        if (IsKeyPressed(KEY_UP) && playerY > 0) {
            playerY -= 1;
        }

        // Calculate the viewport’s top-left corner to keep player centered
        int viewX = playerX - VIEW_WIDTH / 2;
        int viewY = playerY - VIEW_HEIGHT / 2;

        // Clamp view to map boundaries
        //if (viewX < 0) viewX = 0;
        //if (viewY < 0) viewY = 0;
        //if (viewX + VIEW_WIDTH > MAP_WIDTH) viewX = MAP_WIDTH - VIEW_WIDTH;
        //if (viewY + VIEW_HEIGHT > MAP_HEIGHT) viewY = MAP_HEIGHT - VIEW_HEIGHT;

        BeginDrawing();
        ClearBackground(BLACK);

        // Render the visible portion of the map
        RenderVisibleMap(map, viewX, viewY);

        // Draw the player as a red square in the center of the viewport
        DrawRectangle((VIEW_WIDTH / 2) * TILE_SIZE, (VIEW_HEIGHT / 2) * TILE_SIZE, TILE_SIZE, TILE_SIZE, RED);

        DrawText(TextFormat("Player: (%d, %d)", playerX, playerY), 10, 10, 14, YELLOW);

        EndDrawing();
    }

    // Close Raylib
    CloseWindow();

    return 0;
}*/

#include "stdafx.h"



int main()
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Raylib 2D RPG");
    SetTargetFPS(60);

    GameStartup();

    while (!WindowShouldClose()) {

        GameUpdate();

        BeginDrawing();
        ClearBackground(GRAY);

        GameRender();

        EndDrawing();
    }

    GameShutdown();

    CloseWindow();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
