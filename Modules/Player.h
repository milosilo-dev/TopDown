#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SDL2/SDL.h>
extern int frame;

class PlayerClass{
    public:
        //Define the surface's
        SDL_Surface* surface;
        
        //Define the path's
        const char* path = "Assets/Player.bmp";
        
        //Define the Player Specific
        int Playerx = 10;
        int Playery = 10;
        const int PlayerSpeed = 3;
        
        //Define the Player Size
        int direction = 0;
        int width;
        int height;
        bool kill;

        //Define the Rectangles for bliting to the screen
        SDL_Rect rect;

        //Define the Functions for the Player
        void CutOutFrame();
        bool init();
        void HandleKey(SDL_Event e);
        void drawPlayer(SDL_Surface* ScreenSurfacem);
        void move(int x, int y);
        void exit();
    private:
        SDL_Rect animationRect;
};

#endif