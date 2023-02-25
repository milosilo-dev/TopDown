#ifndef __ENTITY_H__
#define __ENTITY_H__
#include <SDL2/SDL.h>
#include "Player.h"

class Entity{
    public:
        SDL_Surface* surface;
        char* path = "Assets/Box.bmp";
        int x = 0;
        int y = 0;
        int width;
        int height;
        SDL_Rect rect;
        bool Colliders = false;
        void setPath(char* newPath);
        bool init();
        bool checkCollider(SDL_Rect PlayerInstance);
        void moveCollider(PlayerClass* PlayerInstance, SDL_Event e);
        void draw(SDL_Surface* ScreenSurface);
        void exit();
};
#endif