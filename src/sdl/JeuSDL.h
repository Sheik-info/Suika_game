#ifndef JEU_SDL_H
#define JEU_SDL_H

#include "Sprite.h"
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include "../core/Jeu.h"
#include "../sdl/MenuSDL.h"
#include <list>

/**
 * \class JeuSDL
 * \brief class pour le Jeu version SDL
 */
class JeuSDL
{
private:
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_Surface *surface = NULL;
    SDL_Texture *texture = NULL;
    Jeu partie;
    SDL_bool cont = SDL_TRUE;
    Mix_Music *musique = NULL;
    Sprite fruitActuel;
    Sprite fruitSuivant;
    Sprite Plateau;
    vector<Sprite> tableauFruits;
    list<Sprite> fruitsList;
    bool tombe = false;
    int nbFruits = 0;
    Sprite tabLoad[10];
    Sprite score;
    TTF_Font * font;

public:

    JeuSDL();
    /** \fn JeuSDL()
     *  \brief constructeur de la clase JeuSDL
     */
    ~JeuSDL();
    /** \fn JeuSDL()
     *  \brief Destructeur de la clase JeuSDL
     */
    void drawFruitActuel();
    /** \fn drawFruitActuel()
     *  \brief va dessiner le fruit actuel
     */
    void drawFruitSuivant();
    /** \fn drawFruitSuivant()
     *  \brief va dessiner le fruit en attente
     */
    void drawPlateau();
    /** \fn drawPlateau()
     *  \brief va dessiner le plateau de jeu
     */
    void fruitQuiTombe();
    /** \fn fruitQuiTombe()
     *  \brief fait en sorte que le fruit actuel tombe vers le bas du plateau
     */
    void boucleDeJeu();
    /** \fn boucleDeJeu()
     *  \brief pour la gestion des evenement et de l'affichage
     */
    void afficher();
    /** \fn afficher()
     *  \brief fonction qui va gérer tout les affichages dans la fenêtre SDL
     */
    void drawTableauDeFruits();
    /** \fn drawTableauDeFruits()
     *  \brief dessiner les fruits présents dans la fenêtre dans le tableau
     */
    Sprite genereSprite();
    /** \fn genereSprite(int id)
     *  \brief pour obtenir l'identité du fruit sa valeur réel
     * \return Sprite
     */
    void gestionCollision();
    /** \fn gestionCollision()
     *  \brief pour faire la gestion de la collision
     */
    void initTabSprite();
    /** \fn initTabSprite()
     *  \brief initialise le tableau pour l'apparence des différends fruits
     */
    void initMembresSDL();
    /** \fn initMembresSDL()
     *  \brief va initialiser les différends fonctions SDL pour la fenetre, texture, surface, etc
     */
    Jeu getPartie();
    /** \fn getPartie()
     *  \brief obtenir les données de la partie
     *  \return Jeu
     */
};

#endif
