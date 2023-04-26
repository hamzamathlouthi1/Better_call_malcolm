#include "minimap.h"

void init_map(minimap *m)
{
// kharajt l bg 
    m->map = IMG_Load("tools/background.jpg");
 // nloadi fel image perso fel minimap 
    m->minijoueur = IMG_Load("tools/littleguy.png");
    // taswira li chtokhrej loula fel boucle mta3 animation
    m->engime = IMG_Load("tools/animation 1.png");
    
    
   //parametres w positionnement mta3 minimap w mini joueur w engime
    m->positionmap.x = 250;
    m->positionmap.y = 19;
    m->positionminijoueur.x = 200;
    m->positionminijoueur.y = 21;
    m->positionengime.x = 0;
    m->positionengime.y = 0;
}

//maj

void MAJMinimap(SDL_Rect posJoueur, minimap *m, SDL_Rect camera, int redimensionnement)
{
    SDL_Rect posJoueurABS;
    posJoueurABS.x = 0;
    posJoueurABS.y = 0;
    posJoueurABS.x = posJoueur.x + camera.x;
    posJoueurABS.y = posJoueur.y + camera.y;
    m->positionminijoueur.x = (posJoueurABS.x * redimensionnement / 100) + 250;
    m->positionminijoueur.y = (posJoueurABS.y * redimensionnement / 100) + 21;
}
//affichage minimp
void afficherminimap(minimap m, SDL_Surface *screen)
{
    SDL_BlitSurface(m.map, NULL, screen, &m.positionmap);
    SDL_BlitSurface(m.minijoueur, NULL, screen, &m.positionminijoueur);
    SDL_BlitSurface(m.engime, NULL, screen, &m.positionengime);
}



//partie animation
void animerminimap(minimap * m ,int *i)
{

 char ch[40];
    sprintf(ch, "tools/animation %d.png",*i);
    if ((*i)==2)
        (*i)=0;
    (*i)++;
    m->engime=IMG_Load(ch);
    
        m->positionengime.x = 799;
        m->positionengime.y = 0;
         
   
}

void initialiser_temps(temps *t)
{
  t->texte = NULL; // espace le lwakt m,s
  t->score = NULL;
  t->s = 0;
  t->position.x = 10;
  t->position.y = 50;
  t->police = NULL;
  t->police = TTF_OpenFont("tools/arial.ttf", 40);
  if (t->police == NULL)
  {
    printf("error loading font \n ");
  }
  t->color.r = 0 ; 
  t->color.g = 0 ; 
  t->color.b = 0 ; 

  strcpy(t->entree, "");
  (t->secondspassed) = 0;
  time(&(t->t1)); // temps du debut
}
void afficher_temps(temps *t, SDL_Surface *ecran)
{ 
  SDL_Rect pos_score;
  char sscore[100];
  pos_score.x= 1000;
  pos_score.y= 50;

  time(&(t->t2)); // wakt taw

  t->secondspassed = t->t2 - t->t1;

  t->min = ((t->secondspassed / 60) % 60);
  t->sec = ((t->secondspassed) % 60);

  sprintf(t->entree, "%02d:%02d", t->min, t->sec); 

  t->texte = TTF_RenderText_Blended(t->police, t->entree, t->color);

  SDL_BlitSurface(t->texte, NULL, ecran, &(t->position)); /// blit mta3 temp

  t->s = (t->sec * 10 + t->min * 600);
  sprintf(sscore, "%02d", t->s ); 

  t->score = TTF_RenderText_Blended(t->police, sscore , t->color);

  SDL_BlitSurface(t->score, NULL, ecran, &pos_score); //el blit surface mta3 score 
}

void free_temps(temps *t)
{
  SDL_FreeSurface(t->texte);
  SDL_FreeSurface(t->score);
  TTF_CloseFont(t->police);
}




















