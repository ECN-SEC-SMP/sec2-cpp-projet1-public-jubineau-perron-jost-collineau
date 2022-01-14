#ifndef POINT2D_HPP
#define POINT2D_HPP

#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Point2D;

template <typename T>
ostream& operator<< (ostream &, Point2D<T> const&);

template<typename T> 
class Point2D 
{
  private:
    T x;
    T y;

  public:
    Point2D();
    Point2D(T x,T y);
    Point2D(Point2D const &p);

    T getX() const;
    T getY() const;
    void setX(T x);
    void setY(T x);

    T norm2() const;
    void translater(T xt, T yt);
    void translater(string xt, string yt);

    friend std::ostream& operator<< <T>(std::ostream &, Point2D const&);
};


//--------------------------------------------------------------------
//Constructeurs
//--------------------------------------------------------------------

template<typename T> 
Point2D<T>::Point2D(T x,T y)
{
  this->x = x;
  this->y = y;
}

template<typename T> 
Point2D<T>::Point2D()
{
  this->x = (T)0;
  this->y = (T)0;
}

template<typename T>
Point2D<T>::Point2D(Point2D const &p)
{
  this->x = p.getX();
  this->y = p.getY();
}

//--------------------------------------------------------------------
//Getteurs et Setteurs
//--------------------------------------------------------------------

template<typename T> 
T Point2D<T>::getX() const
{
  return this->x;
}

template<typename T> 
void Point2D<T>::setX(T x)
{
  this->x = x;
}

template<typename T> 
T Point2D<T>::getY() const
{
  return this->y;
}

template<typename T> 
void Point2D<T>::setY(T y)
{
  this->y = y;
}


//--------------------------------------------------------------------
//Les fonctions
//--------------------------------------------------------------------

template<typename T>
T Point2D<T>::norm2() const
{
  return x*x+y*y;
}

template<typename T>
void Point2D<T>::translater(T xt, T yt)
{ 
  setX(getX() + xt);
  setY(getY() + yt);
}

template<typename T>
void Point2D<T>::translater(string xt, string yt)
{ 
  setX(getX() + xt);
  setY(getY() + yt);
}

//--------------------------------------------------------------------
//Surcharge d'opérateur
//--------------------------------------------------------------------

template<typename T>
std::ostream& operator<< (std::ostream &flux, Point2D<T> const &p )
{
  flux << "[" << p.getX()  << ";" << p.getY() << "]" << std::endl;
  return flux;
}

#endif
