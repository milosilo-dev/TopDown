#include <SDL2/SDL.h>
#include "Modules/Player.h"
#include "Modules/Enermy.h"
#include "Modules/Entity.h"
#include "Modules/SAE.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool switche = false;

PlayerClass PlayerInstance = PlayerClass();
Entity Box = Entity();
Enermy enermy = Enermy();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;


int main(int argc, char* args[])
{
    Box.setPath("Assets/Box.bmp");
    enermy.init();
    Box.x = SCREEN_WIDTH/2;
    Box.y = SCREEN_HEIGHT/2;
    Box.width = 32;
    Box.height = 32;
    Box.Colliders = true;
    PlayerInstance.width = 32;
    PlayerInstance.height = 32;
    if (!init())
    {
        printf("Failed to initialize!\n");
    }else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
        {
            bool quit = false;
            SDL_Event e;
            int index;
            PlayerInstance.drawPlayer(gScreenSurface);
            while (!quit)
            {
                index = index + 1;
                while(SDL_PollEvent(&e) != 0)
                {
                    if(e.type == SDL_QUIT){
                        quit=true;
                    }
                    else if (e.type == SDL_KEYDOWN){
                        PlayerInstance.HandleKey(e);
                        if (Box.checkCollider(PlayerInstance.rect))
                        {
                            
                            Box.moveCollider(&PlayerInstance, e);
                        }
                    }

                }
                SDL_FillRect(gScreenSurface, NULL, NULL);
                PlayerInstance.drawPlayer(gScreenSurface);
                Box.draw(gScreenSurface);
                enermy.frame();
                if(index%50==0){
                    enermy.moveAI();
                }
                SDL_UpdateWindowSurface( gWindow );
            }
        }
    }
}
