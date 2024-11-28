#ifndef JEU_MODE_CONSOLE_H
#define JEU_MODE_CONSOLE_H

#include "../core/Jeu.h"

class JeuModeConsole
{
    private:
    Plateau plat;
    Jeu partie;



    public:
/**
* \fn JeuModeConsole()
* \brief constructeur de la classe.
*/
    JeuModeConsole();
/**
 * \fn JeuModeConsole()
 * \brief destructeur dela classe.
*/
    ~JeuModeConsole();
/**
 * \fn afficherLeJeu()
 * \brief fonction permettant l'affichage 
*/
    void afficherLeJeu();
/**
 * \fn initFruitActuel()
 * \brief fonction permettant d'initialiser le fruit actuel 
*/
    void initFruitActuel();
    void mise_a_jour_position();
/**
 * \fn mise_a_jour_position()
 * \brief fonction permettant de retourner le fruit actuellement dans la main du joueur
 */
    void afficherScore();
/**
 * \fn afficherScore()
 * \brief fonction permettant de retourner le fruit actuellement dans la main du joueur
 */
    bool finDeJeu();
/**
 * \fn bool finDeJeu()
 * \brief fonction qui demande à l'utilisateur si il veut finir le jeu
 * \return booléen
 */
   



};

#endif
