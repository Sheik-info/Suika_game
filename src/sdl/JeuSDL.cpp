#include "JeuSDL.h"
// using namespace std;

const int TAILLE_SPRITE = 40;

JeuSDL::JeuSDL()
{   

    initMembresSDL();
    //if(Mix_PlayMusic(musique, -1)!=0) cerr << "Erreur lors de la création du son : " << SDL_GetError() << endl;
    initTabSprite();
    for(int i=0 ; i<11 ; ++i) tabLoad[i].dessiner(renderer,1);
    
    fruitActuel.setPos(partie.getPositionFruitActuel().x, partie.getPositionFruitActuel().y, TAILLE_SPRITE, TAILLE_SPRITE);
    fruitSuivant.setPos(744, 37, TAILLE_SPRITE, TAILLE_SPRITE);
    score.setPos(10,20,30,30);

}
// Détruit et ferme SDL2
JeuSDL::~JeuSDL()
{
    Mix_CloseAudio();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyWindow(window);
    if(renderer) SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(texture);
    Mix_FreeMusic(musique);
    Mix_CloseAudio();
    SDL_Quit();
}
void JeuSDL::initMembresSDL()
{
    if (SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              800, 1000, 0);
    if (window == nullptr)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0)
    {
        cerr << "Erreur lors de la création du son : " << SDL_GetError() << endl;
    }
    if(TTF_Init()==-1)
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    SDL_SetWindowTitle(window, "Suika Game");
    surface = SDL_LoadBMP("./data/utile/arriere.bmp");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    font = TTF_OpenFont("./data/utile/arial.ttf",25);
    if(font==NULL) TTF_CloseFont(font);

    musique = Mix_LoadMUS("./data/utile/son.mp3");

}

void JeuSDL::initTabSprite()
{
    Plateau.loadFromFile("./data/utile/plateau_suika.png", renderer, 0);
    Plateau.setPos(157, 401, TAILLE_SPRITE, TAILLE_SPRITE);

    tabLoad[0].loadFromFile("./data/fruits/circle0.png", renderer, 1);
    tabLoad[1].loadFromFile("./data/fruits/circle1.png", renderer, 1);
    tabLoad[2].loadFromFile("./data/fruits/circle2.png", renderer, 1);
    tabLoad[3].loadFromFile("./data/fruits/circle3.png", renderer, 1);
    tabLoad[4].loadFromFile("./data/fruits/circle4.png", renderer, 1);
    tabLoad[5].loadFromFile("./data/fruits/circle5.png", renderer, 1);
    tabLoad[6].loadFromFile("./data/fruits/circle6.png", renderer, 1);
    tabLoad[7].loadFromFile("./data/fruits/circle7.png", renderer, 1);
    tabLoad[8].loadFromFile("./data/fruits/circle8.png", renderer, 1);
    tabLoad[9].loadFromFile("./data/fruits/circle9.png", renderer, 1);
    tabLoad[10].loadFromFile("./data/fruits/circle10.png", renderer, 1);


}
// fabrique tout ce qui est necessaire pour le fruit actuel
void JeuSDL::drawFruitActuel()
{
    fruitActuel.setPos(partie.getPositionFruitActuel().x,partie.getPositionFruitActuel().y
                                ,TAILLE_SPRITE,TAILLE_SPRITE);
    SDL_RenderCopy(renderer, tabLoad[partie.getIdFruitActuel()-1].getTexture(), nullptr, &fruitActuel.getPosition());
}

void JeuSDL::drawFruitSuivant()
{

    fruitActuel.setPos(fruitSuivant.getPosition().x,fruitSuivant.getPosition().y
                                ,TAILLE_SPRITE,TAILLE_SPRITE);
    SDL_RenderCopy(renderer, tabLoad[partie.getIdFruitSuivant()-1].getTexture(), nullptr, &fruitSuivant.getPosition());
}

void JeuSDL::drawPlateau()
{
    Plateau.dessiner(renderer, 0);
}

void JeuSDL::fruitQuiTombe()
{
    tableauFruits.push_back(genereSprite());
    partie.generationFruit();
    nbFruits++;
}

void JeuSDL::drawTableauDeFruits()
{
    for (int i = 0; i < nbFruits; ++i)
    {

        tableauFruits[i].setPos(partie.getPosition(i).x,partie.getPosition(i).y
                                ,TAILLE_SPRITE,TAILLE_SPRITE);
        SDL_RenderCopy(renderer, tabLoad[partie.getIdFruit(i)-1].getTexture(), nullptr, &tableauFruits[i].getPosition());
    }
}
void JeuSDL::afficher()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);

    drawPlateau();
    drawFruitActuel();
    drawFruitSuivant();
    //gestionFusion();
    gestionCollision();
    drawTableauDeFruits();
    score.drawScore(renderer,font,SDL_Color {149,15,15},partie.getScore());
}

void JeuSDL::boucleDeJeu()
{
    int x, y;
    SDL_Event event;
    do
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
            case SDL_QUIT:
                cont = SDL_FALSE;
                partie.sauvegarder();
                partie.sauvegarder(partie.getScore());
                break;
            case SDL_MOUSEBUTTONUP:
                x = event.motion.x;
                y = event.motion.y;

                if (((x >= partie.getPositionFruitActuel().x && x <= partie.getPositionFruitActuel().x + partie.getTaille()) 
                            && (y >= partie.getPositionFruitActuel().y && y <= partie.getPositionFruitActuel().y + partie.getTaille())))
                {
                    tombe = true;
                }

                if (tombe)
                {
                    fruitQuiTombe();
                    tombe = false;
                }

                break;
            }
        }
        afficher();
        

        SDL_RenderPresent(renderer);

    } while (cont || !partie.finDeJeu());
    partie.sauvegarder(partie.getScore());
    SDL_DestroyWindow(window);
    MenuSDL s;
}

Sprite JeuSDL::genereSprite()
{
    Sprite temp;
    temp.setPos(partie.getPositionFruitActuel().x, partie.getPositionFruitActuel().y, TAILLE_SPRITE, TAILLE_SPRITE);

    return temp;
}
void JeuSDL::gestionCollision()
{
    partie.physique_fruit();
}

Jeu JeuSDL::getPartie()
{
    return partie;
}