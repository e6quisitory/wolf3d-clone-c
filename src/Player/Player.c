#include "Player.h"

void Player_UpdateVectors(Player* p) {
    p->east  = Vec2_Rotate(p->viewDir, -M_PI/2.0);
    p->west  = Vec2_Rotate(p->viewDir, M_PI/2.0);
    p->south = Vec2_Rotate(p->viewDir, M_PI);
}

Player Player_New(Point2 location) {
    Player p;
    p.location = location;
    p.viewDir = UnitVector(Point2_New(1.0, 1.0));
    Player_UpdateVectors(&p);
    return p;
}

void Player_MoveIfValid(Player* p, Map* map, Point2 proposedLoc) {
    int tileAtLoc = GetTile(map, Point2_to_iPoint2(proposedLoc));
    if (tileAtLoc == 0)
        p->location = proposedLoc;
}

void Player_Update(Player* p, InputsBuffer* buffer, Map* map) {

    /************************* Move player *************************/

    static const double moveIncr = 0.08;
    Point2 proposedLoc = p->location;
    switch (buffer->moveCommand) {
        case MOVE_NORTH:
            proposedLoc = Vec2_Add(p->location, Vec2_Scale(p->viewDir, moveIncr));
            break;
        case MOVE_SOUTH:
            proposedLoc = Vec2_Subtract(p->location, Vec2_Scale(p->viewDir, moveIncr));
            break;
        case MOVE_EAST:
            proposedLoc = Vec2_Add(p->location, Vec2_Scale(p->east, moveIncr));
            break;
        case MOVE_WEST:
            proposedLoc = Vec2_Add(p->location, Vec2_Scale(p->west, moveIncr));
            break;
        case MOVE_NORTHEAST: {
            Vec2 viewDirComp = Vec2_Scale(p->viewDir, 0.7071067*moveIncr);
            Vec2 eastDirComp = Vec2_Scale(p->east, 0.7071067*moveIncr);
            Vec2 totalComp   = Vec2_Add(viewDirComp, eastDirComp);
            proposedLoc      = Vec2_Add(p->location, totalComp);
            break;
        }
        case MOVE_NORTHWEST: {
            Vec2 viewDirComp = Vec2_Scale(p->viewDir, 0.7071067*moveIncr);
            Vec2 westDirComp = Vec2_Scale(p->west, 0.7071067*moveIncr);
            Vec2 totalComp   = Vec2_Add(viewDirComp, westDirComp);
            proposedLoc      = Vec2_Add(p->location, totalComp);
            break;
        }
        case MOVE_SOUTHEAST: {
            Vec2 southDirComp = Vec2_Scale(p->south, 0.7071067*moveIncr);
            Vec2 eastDirComp  = Vec2_Scale(p->east, 0.7071067*moveIncr);
            Vec2 totalComp    = Vec2_Add(southDirComp, eastDirComp);
            proposedLoc       = Vec2_Add(p->location, totalComp);
            break;
        }
        case MOVE_SOUTHWEST: {
            Vec2 southDirComp = Vec2_Scale(p->south, 0.7071067*moveIncr);
            Vec2 westDirComp  = Vec2_Scale(p->west, 0.7071067*moveIncr);
            Vec2 totalComp    = Vec2_Add(southDirComp, westDirComp);
            proposedLoc       = Vec2_Add(p->location, totalComp);
            break;
        }
        case MOVE_NONE:
            // Do nothing
            break;
    }
    Player_MoveIfValid(p, map, proposedLoc);

    /************************* Swivel player *************************/

    // Update viewDir
    static const double swivelIncr = 0.00125;
    switch (buffer->lookCommand) {
        case LOOK_RIGHT:
            p->viewDir = Vec2_Rotate(p->viewDir, -swivelIncr*((double)buffer->mouseAbsXrel));
            break;
        case LOOK_LEFT:
            p->viewDir = Vec2_Rotate(p->viewDir, swivelIncr*((double)buffer->mouseAbsXrel));
            break;
        case LOOK_NONE:
            // Do nothing
            break;
    }

    // Update east, west and south vectors
    Player_UpdateVectors(p);
}
