#ifndef _JEU_H
#define _JEU_H

#include "Fruit.h"
#include <vector>
#include "Plateau.h"

class Jeu
{
private:
    /**
     *\class Jeu
     *\brief Classe contenant les fonctions utiles au deroulement du jeu.
     *Données membres :
     *vector<Fruit> tableau_fruit, tableau contenant les fruit présents sur le plateau.
     *unsigned int score, score de la partie (jeu) en cours.
     *Fruit fruit_suivant, fruit venant dans la main du joueur au tour suivant.
     *Fruit fruit_suivant, fruit étant dans la main du joueur au tour actuel.
     */
    Plateau p;
    vector<Fruit> tableau_fruit;
    unsigned int score;
    Fruit fruit_suivant;
    Fruit fruit_actuel;
    unsigned int score1, score2, score3;
    Vec2 origine;

public:
    /**
     * \brief Jeu()
     * \return les valeur par defaut du début de jeu, score à 0
     *
     */
    // constructeur par defaut de jeu
    Jeu();

    /**
     * \brief ~Jeu()
     * Destructeur de la classe Jeu
     */
    // destructeur par defaut de jeu
    ~Jeu();

    /**
     * \fn fusionner_fruit(TableauDynamique * tab)
     * \brief fonction permettant la fusion entre deux fruits de même grade.
     */
    void fusionner_fruit();

    /**
     * \fn est_sortie(Fruit f)
     * \brief fonction permettant de verifier si un fruit se trouve en dehors du plateau.
     */
    bool est_sortie();
    /**
     * \fn increment_score(unsigned int val)
     * \brief fonction permettant d'incrementer le score du jeu en cours.
     * \return booléen
     */
    void increment_score(unsigned int val);
    /**
     * \fn getFruitActuel()
     * \brief fonction permettant de retourner le fruit actuellement dans la main du joueur.
     */
    Fruit getFruitActuel() const;
    /**
     * \fn getFruitSuivant()
     * \brief fonction permettant de retourner le fruit dans la main du joueur au tour suivant.
     * \return Fruit
     */
    Fruit getFruitSuivant() const;
    /**
     * \fn getScore()
     * \brief fonction permettant de retourner le score de la partie en cours.
     * \return Fruit
     */
    int getScore() const;
    /**
     * \fn getTablauDeFruit()
     * \brief fonction permettant de retourner le tableau_fruit de la partie en cours.
     */
    vector<Fruit> getTableauDeFruit() const;
    /**
     * \fn generationFruit()
     * \brief fonction permettant de mettre à jour les fruits actuel et suivant de la partie en cours.
     * \return Tableau Fruit
     */
    void generationFruit();
    /**
     * \fn fruitQuiTombe()
     * \brief fonction permettant de retourner le score de la partie en cours.
     */
    void fruitQuiTombe();
    /**
     * \fn sauvegarder()
     * \brief fonction permettant de sauvegarder la partie en cours.
     */
    void sauvegarder();
    void sauvegarder(unsigned int score);

    /**
     * \fn recuperer()
     * \brief fonction permettant de recuperer la dernière partie sauvegardée.
     */
    void recuperer();

    void FruitAddForce(Fruit &F);
    /**
     * \fn FruitAddForce(Fruit & F)
     * \brief initialise la force du fruit
     */
    void collision_Mur(Fruit &F);
    /**
     * \fn collision_Mur(Fruit & F)
     * \brief gère la collision d'un fruit avec les murs
     */
    void collision_Entre_Fruit(Fruit &F1, Fruit &F2);
    /**
     * \fn collision_Entre_Fruit(Fruit & F1, Fruit & F2)
     * \brief gère la collision entre les fruitssans fusion
     */
    void maj_vitesse_position_fruit(Fruit &F, const float G);
    /**
     * \fn maj_vitesse_position_fruit(Fruit & F,const float G)
     * \brief mets à jour la position du fruit
     */
    void physique_fruit();
    /**
     * \fn physique_fruit()
     * \brief gère toutes les interacctions des fruits passés dans le tableau de fruits que ça soit
     * \brief avec les murs ou les autres fruits
     */
    void setPosition(float x, float y, int a);
    /**
     * \fn setPosition(float x,float y,int a)
     * \brief initialise la position d'un fruit dans le tableau de fruits et son indice a
     */
    Vec2 getPosition(int a) const;
    /**
     * \fn getPosition(int a)
     * \brief fonction qui retourne la position d'un fruit dans le tableau de fruit avec l'indice a
     * \return vecteur x et y
     */
    Vec2 getPositionFruitActuel() const;
    /**
     * \fn getPositionFruitActuel()
     * \brief fonction qui retourne la position du Fruit actuel
     * \return vecteur x et y
     */
    int getTaille() const;
    /**
     * \fn getTaille()
     * \brief permet d'obtenir la taille du fruit actuel
     * \return Fruit
     */
    Vec2 getVitesse(int a) const;
    /**
     * \fn getVitesse(int a)
     * \brief permet d'obtenir la vitesse d'un fruit dans le tableau de fruit avec l'indice a
     * \return vecteur x et y
     */
    int getIdFruit(int a) const;
    /**
     * \fn getIdFruit(int a)
     * \brief fonction permettant de retourner l'identité d'un fruit dans le tableau avec l'indice a
     * \return entier
     */
    int getXmin() const;
    /**
     * \fn getXmin()
     * \brief pour obtenir la position en x minimum du plateau SDL
     * \return entier
     */
    int getXmax() const;
    /**
     * \fn getXmax()
     * \brief pour obtenir la position en x maximum du plateau SDL
     * \return entier
     */
    int getYmin() const;
    /**
     * \fn getYmin()
     * \brief pour obtenir la position en y minimum du plateau SDL
     * \return entier
     */
    int getYmax() const;
    /**
     * \fn getYmax()
     * \brief pour obtenir la position en y maximum du plateau SDL
     * \return entier
     */
    int getIdFruitActuel() const;
    /**
     * \fn getIdFruitActuel()
     * \brief fonction permettant de retourner l'identité du fruit actuel
     * \return entier
     */
    int getIdFruitSuivant() const;
    /**
     * \fn getIdFruitSuivant()
     * \brief fonction permettant de retourner l'identité du fruit en attente
     * \return entier
     */
    int norme(Vec2 a);
    /**
     * \fn norme (Vec2 a)
     * \brief fonction permettant de retourner la norme d'un vecteur
     * \return int
     */
    Fruit genereFruit(int id);
    /**
     * \fn genereFruit(int id)
     * \brief fonction permettant de générer un fruit avec l'identité id en paramètre
     * \return Fruit
     */
    void setPosition(float x, float y);
    /**
     * \fn void setPosition(float x,float y)
     * \brief initialise la position du fruit actuel
     */
    bool finDeJeu();
    /**
     * \fn finDeJeu()
     * \brief test si il y'a un fruit dans le tableau de fruit qui a dépassé le plateau
     * \return booléen
     */


};


#endif
