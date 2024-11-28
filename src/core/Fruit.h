#ifndef _FRUIT_H
#define _FRUIT_H

#include "Vec2.h"
#include <iostream>
#include <string>
#include "math.h"
#include <time.h>
#include <stdlib.h>
using namespace std;

/**
 * \enum une enumeration sur les fruits plus elle est grande plus sa valeur est haute
 * \brief est composé de Cerise=1, Fraise=2, Raisin=3, Mandarine=4, Orange=5, Pomme=6, Poire=7, Peche=8, Ananas=9, Melon=10, Pasteque=11
 */
enum fruits
{
    Cerise = 1,
    Fraise = 2,
    Raisin = 3,
    Mandarine = 4,
    Orange = 5,
    Pomme = 6,
    Poire = 7,
    Peche = 8,
    Ananas = 9,
    Melon = 10,
    Pasteque = 11
};
/**
 * \class Fruit
 * \brief une classe pour les fruits en utilisant l'enum pour initialiser les diffèrents types de fruits
 */
class Fruit
{

private:
    float taille;
    float poids;
    Vec2 position;
    Vec2 posPrecedent;
    Vec2 vitesse;
    Vec2 force;
    fruits fruit;
    int idFruit;


public:
    /** \fn Fruit()
     *  \brief constructeur par default du Fruit*/
    Fruit();
    /** \fn ~Fruit()
     *  \brief destructeur du fruit*/
    ~Fruit();
    /** \fn setFruit(int id)
     * \brief pour initialiser un fruit selon l'identité donné et surtout avec enum fruits
     */
    void setFruit(int id);
    /** \fn void setVitesse()
     *  \brief pour initialiser la vitesse en fonction de idFruits plus elle est grande plus elle tombe vite  */
    void setVitesse(float x, float y);
    /** \fn void setForce()
     *  \brief pour initialiser la Force en fonction de la vitesse et du poids en utilisant la deuxième loi de newton*/
    void setForce(float x, float y);
    /** \fn void setPosition(float x, float y)
     *  \brief initialise la position du fruit avec une position x et y 2 réels*/
    void setPosition(float x, float y);
    /** \fn Vec2 getVitesse() const
     *  \brief pour obtenir la vitesse fu fruit*/
    Vec2 getVitesse() const;
    /** \fn Vec2 getPosition() const
     *  \brief pour obtenir la position du fruit
     * \return vecteur x et y
     */
    Vec2 getPosition() const;
    /** \fn Vec2 getPoids() const
     *  \brief pour obtenir la force du fruit
     * \return vecteur x et y
     */
    float getPoids();
    /** \fn Vec2 getForce() const
     *  \brief pour obtenir la force du fruit
     * \return vecteur x et y
     */
    Vec2 getForce() const;
    /** \fn string getNomFruit() const
     *  \brief pour obtenir le nom du fruit
     * \return chaine de caractère
     */
    string getNomFruit() const;
    int getTaille() const;
    /** \fn static void testRegression()
     *  \brief va faire les tests sur les fruits avec des asserts*/
    static void testRegression();
    /** \fn int getIdFruit() const
     *  \brief pour obtenir l'identité du fruit sa valeur réel
     * \return réel
     */
    int getIdFruit() const;
    /** \fn float distanceFruit(const Fruit& b)
     *  \brief va calculer la distance entre les fruits
     * \return réel*/
    float distanceFruit(const Fruit &b);
    /** \fn void setPoids()
     *  \brief initialise le poids du fruit*/
    void setPoids();
    /** \fn void settaille()
     *  \brief initialise la taille du fruit en fonction de son identité*/
    void setTaille(int id);
/*    friend std::ostream &operator<<(std::ostream &flux, const Fruit &B);
    friend std::istream &operator>>(std::istream &flux, Fruit &A);
*/

};

#endif
