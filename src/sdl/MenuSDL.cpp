#include "MenuSDL.h"
#include <fstream>


const int TAILLE_SPRITE = 12;

MenuSDL::MenuSDL() 
{
        if(SDL_Init(SDL_INIT_TIMER | SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    window = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              700, 700, 0);
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
    if(TTF_Init()==-1)
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_SOFTWARE );
    SDL_SetWindowTitle(window,"Menu");
    surface = SDL_LoadBMP("./data/menu/menuFond.bmp");
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer,texture,NULL,NULL);

    string filename = "./data/best_score.txt";
    ifstream fichier(filename.c_str());
    fichier >> score_1 >> score_2 >> score_3;


    button.loadFromFile("./data/menu/btn-start.png",renderer,2);
    button.setPos(100,250,TAILLE_SPRITE, TAILLE_SPRITE);

    bool fichier_vide = fichierVide("./data/save.txt");

    if(fichier_vide)
    {
        cont.loadFromFile("./data/menu/CONTINUE_f.png",renderer,2);
    }
    else
    {
       cont.loadFromFile("./data/menu/CONTINUE.png",renderer,2);
    }
 
    cont.setPos(100,350,TAILLE_SPRITE, TAILLE_SPRITE);

    score.loadFromFile("./data/menu/score.png",renderer,2);
    score.setPos(10,10,TAILLE_SPRITE, TAILLE_SPRITE);


    font = TTF_OpenFont("./data/utile/arial.ttf",25);
    if(font==NULL) TTF_CloseFont(font);

        score1.setPos(85,49,30,30);
        score2.setPos(85,121,30,30);
        score3.setPos(85,190,30,30);


    boucleMenu();
    

    
}

MenuSDL::~MenuSDL() 
{
    fermerMenu();
}

bool MenuSDL::fichierVide(const string& filename) {
    std::ifstream file(filename);
    return file.peek() == std::ifstream::traits_type::eof();
}

void MenuSDL::boucleMenu()
{
    int x,y;
    SDL_Event event;
    do
    {
        while(SDL_PollEvent(&event)) 
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    continu = SDL_FALSE;
                    break;
                case SDL_MOUSEBUTTONUP:
                x = event.motion.x;
                y = event.motion.y;
                    bool fichier = fichierVide("./data/save.txt");
                    if (((x >= 120 && x <= 600)
                                && (y >= 263 && y <= 333)))
                        {
                            fermerMenu();
                            JeuSDL j;
                            j.boucleDeJeu();
                        }
                    
                    if ((x >= 120 && x <= 600)
                                && (y >= 366 && y <= 433) && !fichier)
                    {
                        fermerMenu();
                        JeuSDL j;
                        j.getPartie().recuperer();
                        j.boucleDeJeu();
                    }


                break;

            
            }

        }
        afficher();
        SDL_RenderPresent(renderer);

    }while(continu);
}
void MenuSDL::setBoutons()
{

    button.dessiner(renderer,button.getPosition().x,button.getPosition().y
                                , TAILLE_SPRITE, TAILLE_SPRITE,0);
        
    SDL_RenderCopy(renderer,texture,&button.getPosition(),&button.getPosition());

    cont.dessiner(renderer,cont.getPosition().x,cont.getPosition().y
                                , TAILLE_SPRITE, TAILLE_SPRITE,0);
        
    SDL_RenderCopy(renderer,texture,&cont.getPosition(),&cont.getPosition());

    score.dessiner(renderer,score.getPosition().x,score.getPosition().y
                                , TAILLE_SPRITE, TAILLE_SPRITE,0);
        
    SDL_RenderCopy(renderer,texture,&score.getPosition(),&score.getPosition());
}
void MenuSDL::afficher()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,texture,NULL,NULL);
    setBoutons();
    //maintenant il faut juste initialiser 
    score1.drawScore(renderer,font,color,score_1);
    score2.drawScore(renderer,font,color,score_2);
    score3.drawScore(renderer,font,color,score_3);

}
void MenuSDL::fermerMenu()
{
        SDL_DestroyWindow(window);  
        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);
        TTF_CloseFont(font);
        TTF_Quit();
        SDL_Quit();

}
