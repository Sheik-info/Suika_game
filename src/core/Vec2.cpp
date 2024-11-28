#include "Vec2.h"

Vec2::Vec2()
{
    x = 0;
    y = 0;
}
void Vec2::make_Vec2 (float r, float j)
{
    x = r;
    y = j;
}

// Opératon sur les Vec2
Vec2 Vec2::operator+(const Vec2& b) const
{
    Vec2 r;
    r.x = x + b.x;
    r.y = y + b.y;
    return r;
}

Vec2 Vec2::operator-(const Vec2 & b) const
{
    Vec2 r;
    r.x = x - b.x;
    r.y = y - b.y;
    return r;
}

Vec2 &Vec2::operator=(const Vec2& a)
{
    x = a.x;
    y = a.y;

    return *this;
   
}

bool Vec2::operator==(const Vec2& a) const
{
    if(x == a.x && y == a.y) return true;
   
}

Vec2 Vec2::operator* (Vec2 b) const
{
    Vec2 r;
    r.x = (x * b.x) - (y * b.y);
    r.y = (x * b.y) + (y * b.x);
    return r;
}

Vec2 Vec2::operator* (const float & b) const
{
    Vec2 a;
    a.x = x * b;
    a.y = y * b;
    return a;
}

Vec2 Vec2::operator/ (const float& b) const
{
    Vec2 r;
    r.x =  x / b;
    r.y =  y / b;
    return r;
}


