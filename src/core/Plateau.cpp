#include "Plateau.h"
#include <cassert>
using namespace std;

//Constructeur par défaut du tableau
Plateau::Plateau() : plateau{
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "#                  #",
 "####################"
}
{
    //pour la version texte
    hauteur = HAUTEUR;
    largeur = LARGEUR;
    //pour la version sdl
    xmin = 205;
    xmax = 595;
    ymin = 981;
    ymax = 433;

}

Plateau::~Plateau()
{
}

// Permet de pouvoir récupérer la hauteur de la fenêtre
unsigned int Plateau::getHauteur() const
{
    return hauteur;
}

// Permet de pouvoir récupérer la largeur de la fenêtre
unsigned int Plateau::getLargeur() const
{
    return largeur;
}
void Plateau::dansTableau()
{
    for (int i = 0; i < HAUTEUR; ++i)
    {
        for (int j = 0; j < LARGEUR; ++j)
        {

            switch (PlateauDeJeu[i][j])
            {
            case Cer:
                if (PlateauDeJeu[i][j] == Cer)
                    plateau[i][j] = 'C';
                break;
            case Fra:
                if (PlateauDeJeu[i][j] == Fra)
                    plateau[i][j] = 'F';
                break;
            case Rais:
                if (PlateauDeJeu[i][j] == Rais)
                    plateau[i][j] = 'R';
                break;
            case Mand:
                if (PlateauDeJeu[i][j] == Mand)
                    plateau[i][j] = 'm';
                break;
            case Ora:
                if (PlateauDeJeu[i][j] == Ora)
                    plateau[i][j] = 'O';
                break;
            case Pom:
                if (PlateauDeJeu[i][j] == Pom)
                    plateau[i][j] = 'a';
                break;
            case Poi:
                if (PlateauDeJeu[i][j] == Poi)
                    plateau[i][j] = 'p';
                break;
            case Pec:
                if (PlateauDeJeu[i][j] == Pec)
                    plateau[i][j] = 'Q';
                break;
            case Ana:
                if (PlateauDeJeu[i][j] == Ana)
                    plateau[i][j] = 'A';
                break;
            case Mel:
                if (PlateauDeJeu[i][j] == Mel)
                    plateau[i][j] = 'M';
                break;
            case Pas:
                if (PlateauDeJeu[i][j] == Pas)
                    plateau[i][j] = 'W';
                break;
            }
        }
    }
}

void Plateau::testRegression_plateau()
{
    Plateau *P;
    P = new Plateau[100];
    for (int i = 0; i < 100; i++)
    {
        assert(P[i].hauteur == HAUTEUR);
        assert(P[i].largeur == LARGEUR);
        assert(P[i].getHauteur() == P[i].hauteur);
        assert(P[i].getLargeur() == P[i].largeur);
    }
}
int Plateau::getXmin() const
{
    return xmin;
}
int Plateau::getXmax() const
{
    return xmax;
}
int Plateau::getYmin() const
{
    return ymin;
}
int Plateau::getYmax() const
{
    return ymax;
}
