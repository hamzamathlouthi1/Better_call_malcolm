#include "minimap.h"



int main()
{
   
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_Surface *screen, *perso,*back ;
    screen = SDL_SetVideoMode(1920, 1080, 32, SDL_HWSURFACE | SDL_DOUBLEBUF); 
    SDL_Rect camera, pospersonnage; 
    SDL_Event event; 
    minimap m; 
    temps t; 




    perso = IMG_Load("tools/perso.png");
    back = IMG_Load("tools/image1.jpg");


    

    int continuer = 1;
    init_map(&m); 
    camera.x = 30;
    camera.y = 20;
    camera.w = 800;
    camera.h = 537;
    pospersonnage.x = 0;
    pospersonnage.y = 260;
    SDL_EnableKeyRepeat(100, 10); 
    initialiser_temps(&t); 
    int i=2;
    while (continuer)
    {

        SDL_BlitSurface(back, NULL, screen, NULL);
        
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                continuer = 0;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                case SDLK_LEFT:
                    {
                        pospersonnage.x -= 5;
                    }
                    break;
                case SDLK_RIGHT:
                        pospersonnage.x += 5;
                    break;
                case SDLK_UP:
                        pospersonnage.y -= 5;
                    break;
                case SDLK_DOWN:
                        pospersonnage.y += 5;
                    break;
                }
                break;
            }
        }

        SDL_BlitSurface(perso, NULL, screen, &pospersonnage);
        
        afficher_temps(&t, screen);  // temps.c
        animerminimap(&m,&i);
        MAJMinimap(pospersonnage, &m, camera, 20); // mise a jour minimap.c
        afficherminimap(m, screen); // affichage minimap.c


        
        

        SDL_Flip(screen);  
        SDL_Delay(20); // decalage de 20 ms 
    }
    SDL_FreeSurface(perso);
    SDL_FreeSurface(back);
    SDL_FreeSurface(m.minijoueur);
    SDL_FreeSurface(m.map);
    SDL_FreeSurface(m.engime);
    free_temps(&t);
    TTF_Quit();
    SDL_Quit();

    return 0;
}
