#pragma once

typedef struct {
    int* tiles;
    int numTiles;
    int height;
    int width;
} Map;

Map   EmptyMap      ();
void  AppendTile    (Map* map, int newTile);
void  FreeMapTiles  (Map* map);
int   GetTile       (Map* map, iPoint2 coord);
void  PrintMap      (Map* map);
Map   InjestMap     (char* mapFileName);