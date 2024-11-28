#ifndef MENU_SDL_H
#define MENU_SDL_H

#include <string>
#include "JeuSDL.h"
#include "Sprite.h"

/**
 * \class MenuSDL
 * \brief une classe pour la gestion du menu avant de jouer au jeu
 */
class MenuSDL {
public:
    MenuSDL();
    /** \fn MenuSDL()
     * \brief constructeur de MenuSDL inisialise les éléments du menu
     */
    ~MenuSDL();
    /** \fn ~MenuSDL()
     * \brief destructeur de MenuSDL
     */
    void boucleMenu();
    /** \fn boucleMenu()
     * \brief gère l'affichage et la gestion des évènement de la souris 
     */
    void setBoutons();
    /** \fn setBoutons()
     * \brief pour initialiser un fruit selon l'identité donné et surtout avec enum fruits
     */
    void afficher();
    /** \fn afficher()
     * \brief pour afficher les diffèrends élements du menu
     */
    bool fichierVide(const string& filename);
    /** 
     * \fn fichierVide(const string& filename)
     * \brief vérifie si le fichier est vide
     * \return booléen
     */
    void fermerMenu();
    /** \fn fermerMenu()
     * \brief fermer tout le menu SDL
     */



private:
    unsigned int score_1, score_2, score_3;
    Sprite score1, score2, score3;
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Renderer *renderer;
    SDL_Window *window = NULL;
    SDL_Rect posArrPlan, posBouton, posScore;
    Sprite button;
    Sprite cont;
    Sprite score;
    SDL_bool continu = SDL_TRUE;
    TTF_Font * font;
    SDL_Color color = {255,255,255};
};

#endif 