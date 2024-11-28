#include "JeuModeConsole.h"
#include <unistd.h>

JeuModeConsole::JeuModeConsole()
{



    do
    {
        initFruitActuel();
        afficherScore();
        afficherLeJeu();
        partie.fruitQuiTombe();
        mise_a_jour_position();
        plat.dansTableau();
        sleep(1);
        afficherScore();
        afficherLeJeu();

    } while (partie.est_sortie() != true || finDeJeu() != true);
}
JeuModeConsole::~JeuModeConsole()
{

}
void JeuModeConsole::afficherLeJeu()
{

    for (int i = 0; i < HAUTEUR; ++i)
    {
        for (int j = 0; j < LARGEUR; ++j)
        {
            /*printf("%c", c[j * HAUTEUR + i]);
            printf("\n");*/
            // cout << c[j * HAUTEUR + i];
            cout << plat.plateau[i][j];
        }
        cout << endl;
    }
}
void JeuModeConsole::initFruitActuel()
{
    switch (partie.getIdFruitActuel())
    {
    case 1:
        plat.PlateauDeJeu[0][11] = Cer;
        break;
    case 2:
        plat.PlateauDeJeu[0][11] = Fra;
        break;
    case 3:
        plat.PlateauDeJeu[0][11] = Rais;
        break;
    case 4:
        plat.PlateauDeJeu[0][11] = Mand;
        break;

    default:
        break;
    }
    plat.dansTableau();
}
void JeuModeConsole::mise_a_jour_position()
{

    //obsolète et cause une erreur de segmentation à cause des set up de jeuSDL
   /* plat.PlateauDeJeu[0][11] = vide;
    vector tab(partie.getTableauDeFruit());
    for (int i = 0; i < (int)tab.size(); ++i)
    {
        switch (partie.getIdFruitActuel())
        {
        case 1:
            plat.PlateauDeJeu[(int)tab[i].getPosition().x][(int)tab[i].getPosition().y] = Cer;
            break;
        case 2:
            plat.PlateauDeJeu[(int)tab[i].getPosition().x][(int)tab[i].getPosition().y] = Fra;
            break;
        case 3:
            plat.PlateauDeJeu[(int)tab[i].getPosition().x][(int)tab[i].getPosition().y] = Rais;
            break;
        case 4:
            plat.PlateauDeJeu[(int)tab[i].getPosition().x][(int)tab[i].getPosition().y] = Mand;
            break;

        default:
            break;
        }
    }
    */
}
void JeuModeConsole::afficherScore()
{
    cout << "                                               "
         << "score:" << partie.getScore() << endl;
}
bool JeuModeConsole::finDeJeu()
{
    char fin;
    cout << "saisir f pour terminer" << endl;
    cin >> fin;
    if (fin == 'f')
        return true;
    else
        return false;
}
