#ifndef _VECTOR2D_HPP_
#define _VECTOR2D_HPP_
#include <math.h>

/* Classe template */
template <class TIPO>
class vector2D
{
public:
    TIPO x, y;

    vector2D(TIPO X = 0.0, TIPO Y = 0.0) : x(X), y(Y)
    {

    }
    ~vector2D()
    {
    }
    vector2D<TIPO> operator+(vector2D<TIPO> v)
    {
        return vector2D<TIPO>(x + v.x, y + v.y);
    }
    void operator+=(vector2D<TIPO> v)
    {
        x += v.x;
        y += v.y;
    }
    /* void operator-=vector2D<TIPO> v) */
    vector2D<TIPO> operator-(vector2D<TIPO> v)
    {
        return vector2D<TIPO>(x - v.x, y - v.y);
    }
    /* void operator*=(vector2D<TIPO> v) */
    vector2D<TIPO> operator*(vector2D<TIPO> v)
    {
        return vector2D<TIPO>(x * v.x, y * v.y);
    }
    vector2D<TIPO> operator*(int i)
    {
        return vector2D<TIPO>(x * i, y * i);
    }
    vector2D<TIPO> operator*(float f)
    {
        return vector2D<TIPO>(x * f, y * f);
    }
    vector2D<TIPO> operator*(double d)
    {
        return vector2D<TIPO>(x * d, y * d);
    }
    /*         TIPO operator*(vector2D<TIPO> v) */
    /*         { */
    /*             return x*v.x + y*v.y */
    /*         } */
    TIPO modulo()
    {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    vector2D<TIPO> versor()
    {
        return this->operator*(1.0 / this->modulo());
    }
    /* Projeção desse vetor na direcao de v */
    vector2D<TIPO> projOrtogonal(vector2D<TIPO> v)
    {
        return v * this->operator*(v) / pow(v.modulo(), 2);
    }
};

#endif