#ifndef MINIMAP_H
#define MINIMAP_H
#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include"time.h"
typedef struct
{
	SDL_Color color;
	TTF_Font *police;
	char ch[50];
	SDL_Surface *txt;
	SDL_Rect pos;
}text;
typedef struct
{
	text time;
	SDL_Surface *img; 
	SDL_Rect pos; 
	SDL_Surface *image_perso ; 
	SDL_Rect pos_perso;
	SDL_Rect pos2_perso;
}minimap;

void InitMinimap (minimap *m);
void AfficheMinimap(SDL_Surface *screen , minimap m);
void annimer_MiniMap(minimap *m);
void initialiser_textTemps(text *t);
SDL_Color GetPixel(SDL_Surface *pSurface,int x,int y);
int collisionPP( SDL_Rect pos_p, SDL_Surface * Masque);
#endif
