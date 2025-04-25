#include"minimap.h"
void InitMinimap (minimap *m)
{
	m->img=IMG_Load("mini.png");
	m->pos.x=0;
	m->pos.y=0;
	m->pos.h = m->img->h;
	m->pos.w = m->img->w;
	m->image_perso=IMG_Load("perso.png");
	m->pos_perso.x=0;
	m->pos_perso.y=0;
	initialiser_textTemps(&m->time);
	m->pos2_perso.x=500;	
	m->pos2_perso.y=500;
	m->pos2_perso.w=3000; 
	m->pos2_perso.h=800;  
 
}
void AfficheMinimap(SDL_Surface *screen , minimap m)
{
	SDL_BlitSurface(m.img , NULL , screen , &m.pos);
	SDL_BlitSurface(m.image_perso , NULL , screen , &m.pos_perso);
	SDL_BlitSurface(m.time.txt , NULL , screen ,&m.time.pos);
}
void initialiser_textTemps(text *t)
{
	t->color.r=255;
	t->color.g=255;
	t->color.b=255;
	t->police=TTF_OpenFont("Ubuntu-Bold.ttf" , 40);
	strcpy(t->ch , "00:00:00");
	t->txt = TTF_RenderText_Blended(t->police , t->ch , t->color);
	t->pos.x=1200;
	t->pos.y=0;
}
void annimer_MiniMap(minimap *m)  
{
	int time = SDL_GetTicks() /1000 ;
	
	int heure = time / 3600;
	
	int minute = time / 60 - heure * 60;

	int seconde = time - heure * 3600 - minute * 60 ;
	
	char h[10] , min[10] , s[10];
	
	
	sprintf(h , "%d" , heure);
	sprintf(min , "%d" , minute);
	sprintf(s , "%d" , seconde);
	
	if(heure<10)
		strcpy(m->time.ch , "0");
	strcat(m->time.ch , h);
	strcat(m->time.ch , ":");
	if(minute<10)
		strcat(m->time.ch , "0");	
	strcat(m->time.ch , min);
	strcat(m->time.ch , ":");
	if(seconde<10)
		strcat(m->time.ch , "0");
	strcat(m->time.ch , s);
	
	

	SDL_FreeSurface(m->time.txt);
	m->time.txt = TTF_RenderText_Blended(m->time.police , m->time.ch , m->time.color);

	int px = (m->pos2_perso.x * 100) /m->pos2_perso.w;
	int py = (m->pos2_perso.y * 100) /m->pos2_perso.h ;


	m->pos_perso.x = (px * m->pos.w) /100 +m->pos.x;
	m->pos_perso.y = (py * m->pos.h) /100 +m->pos.y;
}
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y)
{
	SDL_Color color; 
	Uint32 col=0; 
	char* pPosition=(char*) pSurface->pixels; 
	pPosition+= (pSurface->pitch * y);
	pPosition+= (pSurface->format->BytesPerPixel *x);
	memcpy(&col ,pPosition ,pSurface->format->BytesPerPixel); 
	SDL_GetRGB(col,pSurface->format, &color.r, &color.g, &color.b); 
	return (color);
   
}
	

int collisionPP(SDL_Rect pos_p, SDL_Surface *Masque)
{
	
	SDL_Rect pos[8];
 	pos[0].x=pos_p.x; 
 	pos[0].y=pos_p.y; 
 	pos[1].x=pos_p.x+pos_p.w/2;
  	pos[1].y=pos_p.y; 
  	pos[2].x=pos_p.x+pos_p.w;
  	pos[2].y=pos_p.y; 
  	pos[3].x=pos_p.x; 
  	pos[3].y=pos_p.y+pos_p.h/2;
   	pos[4].x=pos_p.x; 
    	pos[4].y=pos_p.y+pos_p.h;
    	pos[5].x=pos_p.x+pos_p.w/2; 
    	pos[5].y=pos_p.y+pos_p.h;
      	pos[6].x=pos_p.x+pos_p.w;
       	pos[6].y=pos_p.y+pos_p.h; 
      	pos[7].x=pos_p.x+pos_p.w; 
       	pos[7].y=pos_p.y+pos_p.h/2; 
	for (int i = 0; i < 8; i++) 
	{
       	 SDL_Color pixel_color = GetPixel(Masque, pos[i].x, pos[i].y);
        if (pixel_color.r == 0 && pixel_color.g == 0 && pixel_color.b == 0) 
        {
            return 1; 
        }
    }
    return 0; 
}

