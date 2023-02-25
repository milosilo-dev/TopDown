#include "Entity.h"
#include <SDL2/SDL.h>

bool Entity::init(){            
    this->surface = SDL_LoadBMP(path);
    if (this->surface != NULL){
        return false;
    }
    return true;
}
void Entity::draw(SDL_Surface* ScreenSurface)
{
    this->rect.x = x;
    this->rect.y = y;
    SDL_BlitSurface( this->surface, NULL, ScreenSurface, &this->rect );
}
void Entity::exit()
{
    SDL_FreeSurface(this->surface);
    this->surface = NULL;
}
void Entity::setPath(char* newPath)
{
    this->path = newPath;
}
bool Entity::checkCollider(SDL_Rect b)
{
    if (this->Colliders)
    {
        SDL_Rect a = this->rect;
        //The sides of the rectangles
        int leftA, leftB;
        int rightA, rightB;
        int topA, topB;
        int bottomA, bottomB;

        //Calculate the sides of rect A
        leftA = a.x;
        rightA = a.x + a.w;
        topA = a.y;
        bottomA = a.y + a.h;

        //Calculate the sides of rect B
        leftB = b.x;
        rightB = b.x + b.w;
        topB = b.y;
        bottomB = b.y + b.h;
	    //If any of the sides from A are outside of B
        if( bottomA <= topB )
        {
            return false;
        }

        if( topA >= bottomB )
        {
            return false;
        }   

        if( rightA <= leftB )
        {
            return false;
        }

        if( leftA >= rightB )
        {
            return false;
        }

        //If none of the sides from A are outside B
        return true;
    }
}
void Entity::moveCollider(PlayerClass* PlayerInstance, SDL_Event e)
{
    switch (e.key.keysym.sym)
    {
    case SDLK_UP:
        PlayerInstance->Playery = this->y + this->height + 1;
        break;
    case SDLK_DOWN:
        PlayerInstance->Playery = this->y - PlayerInstance->height - 1;
        break;
    case SDLK_RIGHT:
        PlayerInstance->Playerx = this->x - PlayerInstance->width - 1;
        break;
    case SDLK_LEFT:
        PlayerInstance->Playerx = this->x + this->width + 1;
        break;
    }
}