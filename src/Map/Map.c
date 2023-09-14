#include "Map.h"

Map EmptyMap() {
    Map map;
    map.tiles = (int*)malloc(0);
    map.numTiles = 0;
    map.height = 0;
    map.width = 0;
    return map;
}

void AppendTile(Map* map, int newTile) {
    map->tiles = (int*)realloc(map->tiles, (map->numTiles+1)*sizeof(int));
    map->tiles[map->numTiles] = newTile;
    ++map->numTiles;
}

void FreeMapTiles(Map* map) {
    free(map->tiles);
}

int GetTile(Map* map, iPoint2 coord) {
    return map->tiles[coord.y*map->width + coord.x];
}

void PrintMap(Map* map) {
    printf("Rows: %d, Columns: %d\n", map->height, map->width);
    for (int i = map->height - 1; i >= 0; --i) {
        for (int j = 0; j < map->width; ++j) {
            printf("%d", map->tiles[i*map->width + j]);
        }
        printf("\n");
    }
}

Map InjestMap(char* mapFileName) {
    FILE* mapFile = fopen(mapFileName, "r");

    if (mapFile == NULL) {
        printf("Map file could not be read. Aborting.\n");
        exit(1);
    }

    Map map = EmptyMap();

    char* currCellString = strdup("");
    bool cellReadInProgress = false;

    while (true) {
        char currentChar = (char)fgetc(mapFile);

        bool isComma   = currentChar == ',';
        bool isNewline = currentChar == '\r' || currentChar == '\n';
        bool isEOF     = currentChar == EOF;

        if (isComma) {
            goto PushCurrentTileInfo;
        } else if (isNewline) {
            if (cellReadInProgress == true) {
                ++map.height;
                goto PushCurrentTileInfo;
            } else
                continue;
        } else if (isEOF) {
            ++map.height;
            fclose(mapFile);
            goto PushCurrentTileInfoAndExitLoop;
        } else if (cellReadInProgress == true) {
            currCellString = AppendCharToString(currCellString, currentChar);
        } else {
            cellReadInProgress = true;
            currCellString = AppendCharToString(currCellString, currentChar);
            if (map.height == 0)
                ++map.width;
        }

        goto LoopEnd;

        PushCurrentTileInfo: {
            cellReadInProgress = false;
            AppendTile(&map, currCellString[0] - '0');
            currCellString = ClearString(currCellString);
            goto LoopEnd;
        }

        PushCurrentTileInfoAndExitLoop: {
            cellReadInProgress = false;
            AppendTile(&map, currCellString[0] - '0');
            goto Exit;
        }

        LoopEnd: {}
    }
    Exit: {}
    free(currCellString);
    
    Map vFlipMap = EmptyMap();
        vFlipMap.height = map.height;
        vFlipMap.width = map.width;

    for (int i = map.height - 1; i >= 0; --i) {
        for (int j = 0; j < map.width; ++j) {
            AppendTile(&vFlipMap, map.tiles[i*map.width + j]);
        }
    }
    FreeMapTiles(&map);

    return vFlipMap;
}