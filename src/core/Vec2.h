#ifndef _VEC2_H
#define _VEC2_H


/**
 * \struct  Vec2
 * \brief une structure avec une position en x et en y
 */
struct Vec2
{

public:

    float x,y;
    Vec2();
    /** \fn Vec2()
     *  \brief constructeur de la structure 
     */
    void make_Vec2 (float r, float j);
    /** \fn  void make_Vec2 (float r, float j)
     *  \brief pour initialiser le vecteur x et y
     */
    Vec2 operator+(const Vec2& b) const;
    Vec2 operator-(const Vec2 & b) const;
    Vec2 operator* (Vec2 b) const;
    Vec2 operator*(const float & b) const;
    Vec2 operator/ (const float& b) const;
    Vec2 &operator=(const Vec2& a);
    bool operator==(const Vec2& a) const;


};
#endif