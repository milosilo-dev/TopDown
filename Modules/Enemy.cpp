#include "Enermy.h"
#include "Global.h"
#include "Player.h"
#include "SAE.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <SDL2/SDL.h>

void Enermy::init(){
    this->self.path = "Assets/Zombie.bmp";
    this->self.width = 32;this->self.height = 32;
    this->self.x = 100;this->self.y = 100;
    this->self.Colliders = true;
    this->self.init();
}
void Enermy::moveAI(){
    /* initialize random seed: */
    srand (time(NULL));

    /* generate secret number between 1 and 10: */
    iSecret = rand() % 2;
    if (iSecret == 0)
    {
        if (PlayerInstance.Playerx >= this->self.x){
            this->self.x += 1;
        }
        if (PlayerInstance.Playerx <= this->self.x){
            this->self.x -= 1;
        }
    }
    if (iSecret == 1)
    {
        if (PlayerInstance.Playery > this->self.y){
            this->self.y += 1;
        }
        if (PlayerInstance.Playery < this->self.y){
            this->self.y -= 1;
        }
    }
}
void Enermy::frame(){
    if (this->self.checkCollider(PlayerInstance.rect)){
        if (this->swi == true){
            this->Health += 1;
            this->swi = false;
        }
    }else{this->swi = true;}
    if (this->Health > 100){
        this->kill();
    }
    this->self.draw(gScreenSurface);
    std::cout << SDL_GetError();
}
void Enermy::kill(){
    printf("Killed!");
    this->self.exit();
    close();
}