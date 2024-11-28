#include "Sprite.h"

void reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        end--;
        start++;
    }
}
//itoa une fonction en c mais pas en c++ donc j'ai du prendre le code
char* citoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;
 
    /* Handle 0 explicitly, otherwise empty string is
     * printed for 0 */
    if (num == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }
 
    // In standard itoa(), negative numbers are handled
    // only with base 10. Otherwise numbers are
    // considered unsigned.
    if (num < 0 && base == 10) {
        isNegative = true;
        num = -num;
    }
 
    // Process individual digits
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    reverse(str, i);
 
    return str;
}

Sprite::Sprite() : m_hasChanged(false)
{
    surface = nullptr;
    texture = nullptr;
}
Sprite::~Sprite()
{
    if (surface!=nullptr) SDL_FreeSurface(surface);
    if (texture!=nullptr) SDL_DestroyTexture(texture);
    surface = nullptr;
    texture = nullptr;
}

Sprite::Sprite(const Sprite &im)
{
    *this = im;
}

Sprite &Sprite::operator=(const Sprite &im)
{

    surface = im.surface;
    texture = im.texture;

    return *this;
}

void Sprite::loadFromFile(const char *filename, SDL_Renderer *renderer,int id)
{
    surface = IMG_Load(filename);
    if (surface == nullptr)
    {
        string nfn = string("../") + filename;
        cout << "Error: cannot load " << filename << ". Trying " << nfn << endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == nullptr)
        {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == nullptr)
    {
        cout << "Error: cannot load " << filename << endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface *surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_ARGB8888, 0);
    //petit doute sur le fait qu'il faille le correct pixel format
    //soit surface normal soit surfacePixel
    if(id==0) SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer, surfaceCorrectPixelFormat);
    if (texture == NULL)
    {
        cout << "Error: problem to create the texture of " << filename << endl;
        SDL_Quit();
        exit(1);
    }
}
void Sprite::loadFromCurrentSurface(SDL_Renderer *renderer)
{
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == nullptr)
    {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Sprite::dessiner(SDL_Renderer *renderer, int id)
{
    const SDL_Rect& r = getPosition();
    dessiner( renderer, r.x, r.y, r.w, r.h, id );
}


void Sprite::dessiner(SDL_Renderer *renderer, int x, int y, int w, int h, int id)
{
    w = -1;
    h = -1;
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w < 0) ? surface->w : w;
    r.h = (h < 0) ? surface->h : h;
    
    if (id == 1)
    {
        r.w = r.w / 24;
        r.h = r.h / 24;
    }
    else
    {
        r.w = r.w;
        r.h = r.h;
    }

    if (m_hasChanged)
    {
        if (!texture)
            texture = SDL_CreateTextureFromSurface(renderer, surface);

        ok = SDL_UpdateTexture(texture, nullptr, surface->pixels, surface->pitch);
        //cout << ok << endl;
        // erreur -1 sur la texture
        if (ok != 0)
        {
            cerr << "Erreur lors de la capture de la texture : " << SDL_GetError() << endl;
            SDL_Quit();
            exit(1);
        }
        m_hasChanged = false;
    }

    if(id==0) 
    {
        ok = SDL_RenderCopy(renderer, texture, nullptr, &r);
        if (ok != 0)
        {
            cerr << "Erreur lors de la capture de la surface : " << SDL_GetError() << endl;
            SDL_Quit();
            exit(1);
        }
    }
}

SDL_Surface *Sprite::getSurface() const
{

    return surface;
}
SDL_Rect &Sprite::getPosition()
{
    return pos;
}
void Sprite::setPos(int a, int b, int c, int d)
{
    pos = {a, b, c, d};
}
SDL_Texture *Sprite::getTexture() const
{
    return texture;
}
void Sprite::drawScore(SDL_Renderer *renderer,TTF_Font * font,SDL_Color color,int score)
{   
    char buffer[20] = {'\0'};

    citoa(score,buffer,10);

    surface = TTF_RenderText_Solid(font,buffer,color);
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer,texture,NULL,&pos);

}

