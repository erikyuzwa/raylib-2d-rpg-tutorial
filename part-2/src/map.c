#include "stdafx.h"


void UpdateViewData(
    sTile map_data[][WORLD_HEIGHT], 
    int map_width, 
    int map_height,
    sTile view_data[][VIEW_HEIGHT],
    int view_width,
    int view_height,
    int player_x, int player_y) {

    
    for (int i = 0; i < VIEW_WIDTH; i++) {
        for (int j = 0; j < VIEW_HEIGHT; j++) {
            view_data[i][j] = (sTile)
            {
                //.x = i,
                //.y = j,
                .id = -1
            };
        }
    }

    // Calculate the top-left corner of the viewable area to center the player
    int view_x = player_x - (view_width / 2);
    int view_y = player_y - (view_height / 2);

    //if (view_x < 0) view_x = 0;
    //if (view_y < 0) view_y = 0;
    //int view_x = player_x;
    //int view_y = player_y;

   
    // Loop through the visible portion of the map and copy tiles to the viewable array
    for (int i = 0; i < view_width; i++) {
        for (int j = 0; j < view_height; j++) {
            // Calculate the map coordinates from the viewable coordinates
            int map_x = view_x + i;
            int map_y = view_y + j;


            // Copy the tile from the map to the viewable array
            if (map_x >= 0 && map_x < map_width && map_y >= 0 && map_y < map_height) {
                view_data[i][j] = map_data[map_x][map_y];
            }
            else {
                view_data[i][j].id = -1;
            }
            
            //view_data[i][j].x = map_data[map_x][map_y].x;
            //view_data[i][j].y = map_data[map_x][map_y].y;
            //view_data[i][j].type = map_data[map_x][map_y].type;
           
        }
    }

}




void RenderViewData(sTile view_data[][VIEW_HEIGHT], int view_width, int view_height, Rectangle view_pos) {

    int texture_index_x = 0;
    int texture_index_y = 0;
    sTile tile;
    for (int i = 0; i < view_width; i++) {
        for (int j = 0; j < view_height; j++) {
            
            tile = view_data[i][j];

            int screen_x = i * TILE_SIZE * TILE_SCALE;
            int screen_y = j * TILE_SIZE * TILE_SCALE;

            if (tile.id != -1) {

                switch (tile.type) {
                case TILE_TYPE_DIRT:
                    texture_index_x = 4;
                    texture_index_y = 4;
                    break;
                case TILE_TYPE_GRASS:
                    texture_index_x = 5;
                    texture_index_y = 4;
                    break;
                case TILE_TYPE_TREE:
                    texture_index_x = 5;
                    texture_index_y = 5;
                    break;
                }

                DrawMapTile(
                    //view_pos.x + (tile.x * TILE_SIZE * TILE_SCALE),
                    //view_pos.y + (tile.y * TILE_SIZE * TILE_SCALE),
                    //view_pos.x + (i * TILE_SIZE * TILE_SCALE),
                    //view_pos.y + (j * TILE_SIZE * TILE_SCALE),
                    view_pos.x + screen_x,
                    view_pos.y + screen_y,
                    texture_index_x,
                    texture_index_y
                );
            }
            else {
                DrawRectangle(
                    //view_pos.x + (i * TILE_SIZE * TILE_SCALE),
                    //view_pos.y + (j * TILE_SIZE * TILE_SCALE),
                    view_pos.x + screen_x,
                    view_pos.y + screen_y,
                    TILE_SIZE * TILE_SCALE,
                    TILE_SIZE * TILE_SCALE,
                    BLACK);
                //DrawMapTile(
                    //view_pos.x + (tile.x * TILE_SIZE * TILE_SCALE),
                    //view_pos.y + (tile.y * TILE_SIZE * TILE_SCALE),
                //    view_pos.x + (x * TILE_SIZE * TILE_SCALE),
                //    view_pos.y + (y * TILE_SIZE * TILE_SCALE),
                //    4,
                //    4);
            }
        }
    }

    DrawRectangleLines(view_pos.x, view_pos.y, view_pos.width, view_pos.height, YELLOW);
}


void DrawMapTile(int pos_x, int pos_y, int texture_index_x, int texture_index_y) {
    Rectangle source = { (float)(TILE_SIZE * texture_index_x), (float)(TILE_SIZE * texture_index_y), (float)TILE_SIZE, (float)TILE_SIZE };
    Rectangle dest = { (float)pos_x, (float)pos_y, (float)(TILE_SIZE * TILE_SCALE), (float)(TILE_SIZE * TILE_SCALE) };
    Vector2 origin = { 0, 0 };
    DrawTexturePro(textures[TEXTURE_TILEMAP], source, dest, origin, 0.0f, WHITE);
}
