#ifndef PLATEAU_H
#define PLATEAU_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <iostream>

const int HAUTEUR = 15;
const int LARGEUR = 21;


/**
 * \enum une enumeration sur les fruits et le caractère qui lui est assignée
 * \brief est composé de vide=' ', murs='#',Cer='C', Fra='F', Rais='R',Mand='m',Ora='O',Pom='a',
 * \brief Poi='p', Pec='Q', Ana='A', Mel='M', Pas='W'
 */
enum modele { vide=' ', murs='#',Cer='C', Fra='F', Rais='R',Mand='m',Ora='O',Pom='a',
Poi='p', Pec='Q', Ana='A', Mel='M', Pas='W' };

class Plateau
    /**
     *\class Plateau
     *\brief Classe qui gère le plateau du jeu.
     * Données membres :
     * unsigned int hauteur, la hauteur du Plateau
     * unsigned int largeur, la largeur du Plateau
     */
{
private:
    unsigned int hauteur;
    unsigned int largeur;
    int xmin;
    int xmax;
    int ymin;
    int ymax;

public:
    /**
     * \fn Plateau()
     * \brief constructeur de la classe Plateau initialisant le valeurs hauteur et largeur à des valeurs défini
     */
    Plateau();
    /**
     * \fn ~Plateau()
     * \brief destructeur de la classe Plateau
     */
    ~Plateau();
    /**
     * \fn PlateauDeJeu
     * \brief sert à sauvegarder le plateau du jeu.
     */
    /**
     * \fn getHauteur
     * \brief fonction retournant la hauteur du plateau.
     */
    unsigned int getHauteur() const;
    /**
     * \fn getLargeur()
     * \brief fonction retournant la largeur du plateau.
     */
    unsigned int getLargeur() const;
    /**
     * \fn dansTableau()
     * \brief verifie la présence d'un fruit dans le Plateau
     */
    void dansTableau();
    /**
     * \fn testRegression_plateau()
     * \brief fonction effectuant les test de regression de la classe plateau 
    */
    static void testRegression_plateau();
    int getXmin() const;
    /** \fn int getXmin() const
     *  \brief pour obtenir la position en x minimum du plateau SDL
     * \return entier
     */
    int getXmax() const;
    /** \fn int getXmax() const
     *  \brief pour obtenir la position en x maximum du plateau SDL
     * \return entier
     */
    int getYmin() const;
    /** \fn int getYmin() const
     *  \brief pour obtenir la position en y minimum du plateau SDL
     * \return entier
     */
    int getYmax() const;
    /** \fn int getYmax() const
     *  \brief pour obtenir la position en y maximum du plateau SDL
     * \return entier
     */
    modele PlateauDeJeu[HAUTEUR][LARGEUR];
    /** \fn modele PlateauDeJeu[HAUTEUR][LARGEUR]
     *  \brief tableau d'enumération sur ce qu'il y'a dans le tableau de char pour la version texte
     * \return modele
     */
    char plateau[HAUTEUR][LARGEUR];
};

#endif
