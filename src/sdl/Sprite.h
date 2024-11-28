#ifndef SPRITE_H
#define SPRITE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <cassert>
#include <iostream>
using namespace std;

/** 
 * \class Sprite
 *  \brief class pour générer les éléments dans SDL
 */
class Sprite
{

private:
    SDL_Surface *surface;
    SDL_Texture *texture;
    SDL_Rect pos;
    bool m_hasChanged;

public:
    Sprite();
    /** \fn Sprite()
     *  \brief constructeur de la clase Sprite
     */
    ~Sprite();
    /** \fn ~Sprite()
     *  \brief destructeur de la clase Sprite
     */
    Sprite(const Sprite &im);
    /** \fn Sprite(const Sprite &im)
     *  \brief constructeur par copie de la clase Sprite
     */
    Sprite &operator=(const Sprite &im);
    void loadFromFile(const char *filename, SDL_Renderer *renderer, int id);
    /** \fn loadFromFile(const char *filename, SDL_Renderer *renderer, int id)
     *  \brief va charger le fichier d'apparence du Sprite et le charge dans la surface
     */
    void loadFromCurrentSurface(SDL_Renderer *renderer);
    /** \fn loadFromCurrentSurface(SDL_Renderer *renderer)
     *  \brief simplement créer la texture avec la surface
     */
    void dessiner(SDL_Renderer *renderer, int x, int y, int w, int h,int id);
    void dessiner(SDL_Renderer *renderer, int id);
    /** \fn dessiner(SDL_Renderer *renderer, int id)
     *  \brief va créer la texture avec la surface puis la copier dans le renderer
     */
    SDL_Surface *getSurface() const;
    /** \fn *getSurface() const
     *  \brief va calculer la surface
     * \return SDL_Surfaace
     */
    SDL_Texture *getTexture() const;
    /** \fn *getTexture() const
     *  \brief va retourner la texture
     * \return SDL_Texture
     */
    SDL_Rect &getPosition();
    /** \fn &getPosition()
     *  \brief Pour obtenir la position du Sprite
     * \return SDL_Rect
     */
    void setPos(int a,int b,int c,int d);
    /** \fn setPos(int a,int b,int c,int d)
     *  \brief va créer la texture avec la surface puis la copier dans le renderer
     */
    void drawScore(SDL_Renderer *renderer,TTF_Font * font,SDL_Color color,int score);
    /** \fn drawScore(SDL_Renderer *renderer,TTF_Font * font,SDL_Color color,int score)
     *  \brief va mettre le score en police défini dans font dans le renderer pour l'affichage des scores
     */
    
    

};





#endif