#include"minimap.h"
int main()
{

	int boucle=1;
	
	SDL_Surface *screen;
	
	SDL_Event event ;
	
	minimap m;
	
	SDL_Surface *img_p = IMG_Load("perso1.png");
	SDL_Rect pos_p; pos_p.x=500 ; pos_p.y=500;
	
	TTF_Init();
	srand(time(NULL));
	screen = SDL_SetVideoMode(1400 , 800 , 32 , SDL_HWSURFACE|SDL_SRCALPHA);
	InitMinimap(&m);
	
	SDL_Surface *img = IMG_Load("background.png");
	SDL_Rect pos ; pos.x=0 ; pos.y=0;
	SDL_Surface *masque= SDL_LoadBMP("background.bmp");
	while(boucle==1)
	{
		
		
		SDL_BlitSurface(img , NULL , screen , &pos);	
		AfficheMinimap(screen , m);
		SDL_BlitSurface(img_p , NULL , screen , &pos_p);
		
		SDL_Flip(screen);
		
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					boucle=0;
					break;
				case SDL_KEYDOWN:
					if(event.key.keysym.sym == SDLK_RIGHT)
					{
						pos_p.x+=20;
						m.pos2_perso.x=pos_p.x;
					}
					else if(event.key.keysym.sym == SDLK_LEFT)
					{
						pos_p.x-=20;
						m.pos2_perso.x=pos_p.x;
					}
					else if(event.key.keysym.sym == SDLK_UP)
					{
						pos_p.y-=20;
						m.pos2_perso.y=pos_p.y;
					}
					else if(event.key.keysym.sym == SDLK_DOWN)
					{
						pos_p.y+=20;
						m.pos2_perso.y=pos_p.y;
					}
					break;
			}
		}
		
		if (collisionPP(pos_p, masque))
		{
      
    		}

		
		annimer_MiniMap(&m);
		
		
	}
	
	SDL_FreeSurface(img) ;
	SDL_FreeSurface(img_p) ;
	SDL_FreeSurface(m.img);
	SDL_FreeSurface(m.image_perso);
	
	
}
