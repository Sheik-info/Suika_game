#include "Fruit.h"
#include <assert.h>


//constructeur par default
Fruit::Fruit()
{


}
//destructeur
Fruit::~Fruit()
{
}
//va calculer la distance entre deux fruits en fonction de la position
float norme(Vec2 a, Vec2 b)
{
    return (sqrt((pow(b.x - a.x, 2.0)) + (pow(b.y - a.y, 2.0))));
}

Vec2 origine;

//intialiser le fruit selon son identité  avec sa taille poids et vitesse
void Fruit::setFruit(int id)
{
    fruit = (fruits) id;
    idFruit = id;
    setPoids();
    setVitesse(0, 50);
    setForce(0, 0);
    setTaille(idFruit);
}
Vec2 Fruit::getVitesse() const
{
    return vitesse;
}
Vec2 Fruit::getPosition() const
{
    return position;
}
Vec2 Fruit::getForce() const
{
    return force;
}
int Fruit::getIdFruit() const 
{
    return (int) idFruit;
}
//initialise la vitesse selon le type de fruit
void Fruit::setVitesse(float x, float y)
{
    vitesse.make_Vec2(x, y);
}
//initialise le poids selon le type de fruit
void Fruit::setPoids()
{
        switch (idFruit)
    {
        case 1:
        poids = 0.2;
        break;

        case 2:
        poids = 0.3;
        break;

        case 3:
        poids = 0.5;
        break;

        case 4:
        poids = 1;
        break;

        case 5:
        poids = 1.2;
        break;
        
        case 6:
        poids = 1.3;
        break;

        case 7:
        poids = 1.5;
        break;

        case 8:
        poids = 1.8;
        break;

        case 9:
        poids = 2.7;
        break;

        case 10:
        poids = 3;
        break;

        case 11:
        poids = 10;
        break;
    
    default: 
        break;

    }


}
//initialise la force avec la deuxieme loi de newton
void Fruit::setForce(float x, float y)
{
    force.make_Vec2(x, y);

}
void Fruit::setPosition(float x, float y)
{
    position.x = x;
    position.y = y;
}
//pour obtenir le nom du fruit
string Fruit::getNomFruit() const
{
    string nom;
    switch (idFruit)
    {
        case 1:
        nom = "Cerise";
        break;

        case 2:
        nom = "Fraise";
        break;

        case 3:
        nom = "Raisin";
        break;

        case 4:
        nom = "Mandarine";
        break;

        case 5:
        nom = "Orange";
        break;

        case 6:
        nom = "Pomme";
        break;

        case 7:
        nom = "Poire";
        break;

        case 8:
        nom = "Peche";
        break;

        case 9:
        nom = "Ananas";
        break;

        case 10:
        nom = "Melon";
        break;

        case 11:
        nom = "Pasteque";
        break;
    
    default: nom = "fruit pas initialisé";
        break;

    }
    return nom;

}
//calcule la distance entre deux fruits avec la norme
float Fruit::distanceFruit(const Fruit & b)
{
    return norme(position, b.getPosition());
}
void Fruit::testRegression()
{
    Fruit *f2;
    f2 = new Fruit [100];
    for(int i=100;i<100;++i)
    {
        srand(time(NULL));
        f2[i].setFruit(1+rand()%12);
        //test si la getForce donne bien la force
        //assert(f2[i].position==position);
        assert(f2[i].getForce()==f2[i].force);
        assert(f2[i].getPosition()==f2[i].position);
        assert(f2[i].getVitesse()==f2[i].vitesse);
        assert(f2[i].getIdFruit()==f2[i].idFruit);

    }
    delete [] f2; //    Fruit::testRegression(); dans le main
}
int Fruit::getTaille() const
{
    return taille;
}
void Fruit::setTaille(int id)
{
    switch (idFruit)
    {
        case 1:
        taille = 30;
        break;

        case 2:
        taille = 35;
        break;

        case 3:
        taille = 40;
        break;

        case 4:
        taille = 45;
        break;

        case 5:
        taille = 50;
        break;
        
        case 6:
        taille = 55;
        break;

        case 7:
        taille = 60;
        break;

        case 8:
        taille = 65;
        break;

        case 9:
        taille = 70;
        break;

        case 10:
        taille = 80;
        break;

        case 11:
        taille = 110;
        break;
    
    default: 
        break;

    }
}

float Fruit::getPoids()
{
    return poids;
}
