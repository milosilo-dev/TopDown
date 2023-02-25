#include "Player.h"
#include <SDL2/SDL.h>
#include <iostream>
#include "Global.h"
#include "Entity.h"
using namespace std;
int frame = 2;
void PlayerClass::CutOutFrame()
{
    frame += 1;
    if (frame >= 4)
    {
        frame = 0;
    }
    this->animationRect.h = 32;
    this->animationRect.w = 32;
    this->animationRect.y = 32 * direction;
    this->animationRect.x = 32 * frame;
}

bool PlayerClass::init(){   
    bool returnbool = true;

    //Load the player surface sprite map
    this->surface = SDL_LoadBMP(path);
    if (this->surface != NULL){
        returnbool = false;
    }

    return returnbool;
}
void PlayerClass::HandleKey(SDL_Event e)
{
    //check for key presses
    switch( e.key.keysym.sym )
    {
	    //If the key is the up key change the playery then chnage the direction so we know were to put it if it has to be moved back from collitions or other things
        case SDLK_UP:
	    this->Playery -= this->PlayerSpeed;
        this->direction = 1;
	    break;

        //If the key is the down key change the playery then chnage the direction so we know were to put it if it has to be moved back from collitions or other things
	    case SDLK_DOWN:
	    this->Playery += this->PlayerSpeed;
        this->direction = 3;
	    break;

        //If the key is the left key change the playerx then chnage the direction so we know were to put it if it has to be moved back from collitions or other things
	    case SDLK_LEFT:
	    this->Playerx -= this->PlayerSpeed;
        this->direction = 0;
	    break;

        //If the key is the right key change the playerx then chnage the direction so we know were to put it if it has to be moved back from collitions or other things
	    case SDLK_RIGHT:
	    this->Playerx += this->PlayerSpeed;
        this->direction = 2;
	    break;
    };
}
void PlayerClass::drawPlayer(SDL_Surface* ScreenSurface)
{
    //Keep Player of the Sides
    if (this->Playery <= 0){this->Playery = 0 + this->height;}
    if (this->Playerx <= 0){this->Playerx = 0 + this->width;}
    if (this->Playery >= SCREEN_HEIGHT){this->Playery = SCREEN_HEIGHT + this->height;}
    if (this->Playerx >= SCREEN_WIDTH){this->Playery = SCREEN_WIDTH + this->width;}

    //Create a Player
    this->rect.x = Playerx;
    this->rect.y = Playery;
    this->rect.h = this->height;
    this->rect.w = this->width;

    //Run The Functions
    this->CutOutFrame();
    SDL_BlitSurface(this->surface, &this->animationRect, gScreenSurface, &this->rect);
}
void PlayerClass::exit()
{
    SDL_FreeSurface(this->surface);
    this->surface = NULL;
}
void PlayerClass::move(int x, int y){
    this->Playerx = x;
    this->Playery = y;
}