#pragma once

typedef struct {
    int* tiles;
    int numTiles;
    int numRows;
    int numColumns;
} Map;

Map   EmptyMap    ();
Map   AppendTile  (Map map, int newTile);
void  DestroyMap  (Map map);
int   GetTile     (Map map, int x, int y);
void  PrintMap    (Map map);
Map   InjestMap   (char* mapFileName);