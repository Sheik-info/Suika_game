#include "Jeu.h"
#include <cassert>
#include <fstream>
#include <iostream>
#include <string>

Jeu::Jeu()
{
    score = 0;
    Fruit b;
    srand(time(NULL));
    int f1 = rand() % 100;
    if (f1 <= 40)
        f1 = 1;
    else
    {
        if (f1 <= 65)
            f1 = 2;
        else
        {
            if (f1 <= 90)
                f1 = 3;
            else
                f1 = 4;
        }
    }

    fruit_actuel.setFruit(f1);
    fruit_actuel.setPosition(400.0, 404.0);
    tableau_fruit.push_back(fruit_actuel);

    int f2 = rand() % 100;
    if (f2 <= 40)
        f2 = 1;
    else
    {
        if (f2 <= 65)
            f2 = 2;
        else
        {
            if (f2 <= 90)
                f2 = 3;
            else
                f2 = 4;
        }
    }

    fruit_suivant.setFruit(f2);
    string filename = "./data/best_score.txt";
    ifstream fichier(filename.c_str());
    fichier >> score1 >> score2 >> score3;
}

// constructeur par defaut de jeu

Jeu::~Jeu()
{
    score = 0;
}
// destructeur par defaut de jeu

void Jeu::increment_score(unsigned int val)
{
    score += val;
}
int Jeu::norme(Vec2 a)
{
    return (int)sqrt(pow(a.x, 2) + pow(a.y, 2));
}
void Jeu::fusionner_fruit()
{
    // Créer un nouveau tableau pour stocker les fruits fusionnés
    vector<Fruit> nouveaux_fruits;

    // Parcourir le tableau de fruits
    for (int i = 0; i < (int)tableau_fruit.size(); ++i)
    {
        // Parcourir à partir du fruit suivant
        for (int j = i + 1; j < (int)tableau_fruit.size(); ++j)
        {
            // Vérifier si les fruits ont le même identifiant et si cet identifiant est inférieur à 11
            if (tableau_fruit[i].getIdFruit() == tableau_fruit[j].getIdFruit() && tableau_fruit[i].getIdFruit() < 11)
            {
                // Calculer la position moyenne des deux fruits
                Vec2 temp = (tableau_fruit[i].getPosition() + tableau_fruit[j].getPosition()) / 2.0;

                // Créer un nouveau fruit avec l'identifiant suivant
                Fruit nouveau_fruit = genereFruit(tableau_fruit[i].getIdFruit() + 1);

                // Définir la position du nouveau fruit
                nouveau_fruit.setPosition(round(temp.x), round(temp.y));

                // Ajouter le nouveau fruit au tableau des nouveaux fruits
                nouveaux_fruits.push_back(nouveau_fruit);

                // Incrémenter le score
                increment_score(tableau_fruit[i].getIdFruit() * tableau_fruit[j].getIdFruit());

                // Sortir de la boucle intérieure après avoir trouvé une paire de fruits à fusionner
                break;
            }
        }
    }

    // Effacer le tableau de fruits actuel
    tableau_fruit.clear();

    // Ajouter les nouveaux fruits au tableau de fruits
    for (int i = 0; i < (int)nouveaux_fruits.size(); ++i)
    {
        tableau_fruit.push_back(nouveaux_fruits[i]);
    }
}

bool Jeu::est_sortie()
{
    for (int i = 0; i < (int)tableau_fruit.size(); ++i)
        if (tableau_fruit[i].getPosition().y != p.getHauteur() || tableau_fruit[i].getPosition().x != p.getLargeur())
            return true;
    return false;
}
Fruit Jeu::getFruitActuel() const
{
    return fruit_actuel;
}

Fruit Jeu::getFruitSuivant() const
{
    return fruit_suivant;
}
int Jeu::getScore() const
{
    return score;
}
void Jeu::generationFruit()
{
    tableau_fruit.push_back(genereFruit(fruit_actuel.getIdFruit()));
    tableau_fruit[tableau_fruit.size()].setFruit(fruit_actuel.getIdFruit());
    increment_score(fruit_actuel.getIdFruit() * 5);
    fruit_actuel = fruit_suivant;

    int f2 = rand() % 100;
    if (f2 <= 40)
        f2 = 1;
    else
    {
        if (f2 <= 65)
            f2 = 2;
        else
        {
            if (f2 <= 90)
                f2 = 3;
            else
                f2 = 4;
        }
    }

    fruit_suivant.setFruit(f2);
    fruit_actuel.setPosition(400.0, 404.0);
}

vector<Fruit> Jeu::getTableauDeFruit() const
{
    return tableau_fruit;
}
void Jeu::fruitQuiTombe()
{
    // pour la partie console obsolète
    float temp = 0.0;
    char c;
    cout << "tapez t pour jouer" << endl;
    cin >> c;

    do
    {
        temp = fruit_actuel.getPosition().x + fruit_actuel.getVitesse().x;
        fruit_actuel.setPosition(temp, fruit_actuel.getPosition().y);

    } while (((int)fruit_actuel.getPosition().x) < HAUTEUR - 2);

    increment_score(fruit_actuel.getIdFruit());

    generationFruit();
}

void Jeu::sauvegarder()
{
    string filename = "./data/save.txt";
    ofstream fichier(filename.c_str());
    assert(fichier.is_open());
    fichier << score << endl;
    fichier << fruit_actuel.getIdFruit() << endl;
    fichier << fruit_suivant.getIdFruit() << endl;
    fichier << tableau_fruit.size() << endl;
    for (int i = 0; i < (int)tableau_fruit.size(); i++)
    {
        fichier << tableau_fruit[i].getIdFruit() << endl;
        fichier << tableau_fruit[i].getPosition().x << ' ' << tableau_fruit[i].getPosition().y << endl;
    }
}

void Jeu::sauvegarder(const unsigned int score)
{
    if (score >= score1)
    {
        score3 = score2;
        score2 = score1;
        score1 = score;
    }
    else if (score >= score2)
        {
            score3 = score2;
            score2 = score;
        }
        else if (score >= score3)
            {
                score3 = score;
            }
    

    string filename = "./data/best_score.txt";
    ofstream fichier(filename.c_str());
    assert(fichier.is_open());
    fichier << score1 << endl << score2 << endl << score3;
}
void Jeu::recuperer()
{
    string filename = "./data/save.txt";
    ifstream fichier(filename.c_str());
    int fa, fs, size;
    fichier >> score >> fa >> fs >> size;
    fruit_actuel.setFruit(fa);
    fruit_suivant.setFruit(fs);

    int Id;
    float x, y;
    for (int i = 0; i < size; i++)
    {
        fichier >> Id >> x >> y;
        tableau_fruit[i].setFruit(Id);
        tableau_fruit[i].setPosition(x, y);
    }
}
void Jeu::setPosition(float x, float y, int a)
{
    tableau_fruit[a].setPosition(x, y);
}
void Jeu::setPosition(float x, float y)
{
    fruit_actuel.setPosition(x, y);
}
Vec2 Jeu::getPosition(int a) const
{
    return tableau_fruit[a].getPosition();
}
int Jeu::getTaille() const
{
    return fruit_actuel.getTaille();
}
Vec2 Jeu::getVitesse(int a) const
{
    return tableau_fruit[a].getVitesse();
}
int Jeu::getIdFruit(int a) const
{
    return tableau_fruit[a].getIdFruit();
}
int Jeu::getXmin() const
{
    return p.getXmin();
}
int Jeu::getXmax() const
{
    return p.getXmax();
}
int Jeu::getYmin() const
{
    return p.getYmin();
}
int Jeu::getYmax() const
{
    return p.getYmax();
}
Vec2 Jeu::getPositionFruitActuel() const
{
    return fruit_actuel.getPosition();
}
int Jeu::getIdFruitActuel() const
{
    return fruit_actuel.getIdFruit();
}
int Jeu::getIdFruitSuivant() const
{
    return fruit_suivant.getIdFruit();
}

// Fonction permettant de définir la force appliquée à une particule
void Jeu::FruitAddForce(Fruit &F)
{
    F.setForce(0, 9.0); // Ajout de la force
}

// Gestion des collision avce les murs
void Jeu::collision_Mur(Fruit &F)
{
    // Le Fruit ne peut pas dépasser le mur gauche
    if (F.getPosition().x < p.getXmin() + F.getTaille()) // Si on est sur ou apres le mur de droite
    {
        F.setVitesse(0, F.getVitesse().y);                             // On nullifie le vecteur vitesse
        F.setPosition(p.getXmin() + F.getTaille(), F.getPosition().y); // On déplace la particule dans les limites de la fenêtre
    }

    // Le Fruit ne peut pas dépasser le mur droit
    if (F.getPosition().x > p.getXmax() - F.getTaille()) // Si on est sur ou apres le mur de droite
    {
        F.setVitesse(0, F.getVitesse().y);                     // On nullifie le vecteur vitesse
        F.setPosition(595 - F.getTaille(), F.getPosition().y); // On déplace la particule dans les limites de la fenêtre
    }
}

// Gestion des collisions entre deux fruits
void Jeu::collision_Entre_Fruit(Fruit &F1, Fruit &F2)
{
    // Calcule la distance entre les deux fruits
    float dx = F2.getPosition().x - F1.getPosition().x;
    float dy = F2.getPosition().y - F1.getPosition().y;
    float distance = sqrt(dx * dx + dy * dy);

    // Calcule la distance minimale de collision
    float minDistance = (F1.getTaille() + F2.getTaille()) / 1.8;

    if (distance < minDistance)
    {
        // Détermine la direction de la collision
        float collisionAngle = atan2(dy, dx) + .1f;
        float chevauchement = minDistance - distance;
        // Sépare les fruits selon l'angle de collision
        F1.setPosition(F1.getPosition().x - chevauchement * cos(collisionAngle) * 0.5f, F1.getPosition().y - chevauchement * sin(collisionAngle) * 0.5f);
        F2.setPosition(F2.getPosition().x + chevauchement * cos(collisionAngle) * 0.5f, F2.getPosition().y + chevauchement * sin(collisionAngle) * 0.5f);

        // Ajuste la vitesse en fonction de l'angle de collision
        float angle1 = atan2(F1.getVitesse().y, F1.getVitesse().x);
        float angle2 = atan2(F2.getVitesse().y, F2.getVitesse().x);
        float magnitude1 = norme(F1.getVitesse()) + norme(origine);
        float magnitude2 = norme(F2.getVitesse()) + norme(origine);
        float newVelX1 = magnitude1 * cos(angle1 - collisionAngle);
        float newVelY1 = magnitude1 * sin(angle1 - collisionAngle);
        float newVelX2 = magnitude2 * cos(angle2 - collisionAngle);
        float newVelY2 = magnitude2 * sin(angle2 - collisionAngle);

        // echange les vitesses selon l'angle de collision
        F1.setVitesse(newVelX2 * cos(collisionAngle) + newVelX1 * cos(collisionAngle + M_PI), newVelY1 * sin(collisionAngle) + newVelY2 * sin(collisionAngle + M_PI));
        F2.setVitesse(newVelX1 * cos(collisionAngle) + newVelX2 * cos(collisionAngle + M_PI), newVelY2 * sin(collisionAngle) + newVelY1 * sin(collisionAngle + M_PI));

        if (F1.getIdFruit() == F2.getIdFruit() && F1.getIdFruit() < 11)
        {
            fusionner_fruit();
        }
    }
}

void Jeu::maj_vitesse_position_fruit(Fruit &F, const float G)
{
    F.setForce(0, (-(F.getPoids()) * G)); // La force devient la gravité

    if (F.getPoids() > 0 && F.getPosition().y < 915 + F.getTaille())
    {
        // .1f est le pas de temps
        F.setPosition(round(F.getPosition().x), round(F.getPosition().y + (F.getVitesse().y * .01f)));             // Formule de la position vu en TD
        F.setVitesse(round(F.getVitesse().x), round(F.getVitesse().y - (F.getForce().y * (.01f / F.getPoids())))); // Formule de la vitesse vu en TD
    }
}

void Jeu::physique_fruit()
{
    for (int i = 0; i < (int)tableau_fruit.size() - 1; ++i)
    {
        maj_vitesse_position_fruit(tableau_fruit[i], 9.81);
        collision_Mur(tableau_fruit[i]);
        for (int j = 0; j < (int)tableau_fruit.size() - 1; ++j)
        {
            if (i != j)
                collision_Entre_Fruit(tableau_fruit[i], tableau_fruit[j]);
        }
    }
}
Fruit Jeu::genereFruit(int id)
{
    Fruit temp;
    temp.setFruit(id);
    return temp;
}
bool Jeu::finDeJeu()
{

    for (int i = 0; i < (int)tableau_fruit.size(); ++i)
    {
        if (tableau_fruit[i].getPosition().y + 60 > p.getYmax())
            return true;
        else
            return false;
    }
}
