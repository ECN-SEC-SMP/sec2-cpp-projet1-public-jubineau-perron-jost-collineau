#pragma once
#include <iostream>
#include <vector>
#include "point2d.hpp"

using namespace std;

template <typename T>
class Polygone;

template <typename T>
std::ostream& operator<<(std::ostream &, Polygone<T> const&);


template <typename T>
class Polygone
{
  private:
    vector<Point2D<T>> sommets;

  public:
    Polygone(void);
    Polygone(vector <Point2D<T> > listeSommets);
    Polygone(Polygone<T> const &poly);

    vector<Point2D<T>> getSommets() const;
    void setSommets(vector<Point2D<T>> listeSommets);
    void addPoint(Point2D<T>);
    void translate(T x , T y );

    friend std::ostream& operator<< <T>(std::ostream &, Polygone const&);
};


//--------------------------------------------------------------------
//Constructeurs
//--------------------------------------------------------------------

template <typename T>
Polygone<T>::Polygone(void){
  
}


template <typename T>
Polygone<T>::Polygone(vector <Point2D<T> > listeSommets){
  this->sommets = listeSommets;
}

template <typename T>
Polygone<T>::Polygone(Polygone<T> const &poly){
  this->sommets = poly.sommets;
}

//--------------------------------------------------------------------
//Getteurs et Setteurs
//--------------------------------------------------------------------

template <typename T>
vector<Point2D<T>> Polygone<T>::getSommets() const
{
  return this->sommets;
}

template <typename T>
void Polygone<T>::setSommets(vector<Point2D<T>> listeSommets)
{
  this->sommets = listeSommets;
}

//--------------------------------------------------------------------
//Les fonctions
//--------------------------------------------------------------------

template <typename T>
void Polygone<T>::translate(T x , T y )
{
  for(int i = 0 ; i < sommets.size() ; i++) 
  	sommets[i].translater(x, y);
}

template <typename T>
std::ostream& operator<<(std::ostream &flux, Polygone<T> const &P)
{
	vector <Point2D<T>> monVect = P.getSommets();
	
  flux << "Polygone a " << monVect.size() << " sommets :" << "\n";
	for(int i = 0 ; i < monVect.size() ; i++) 
  	flux	<< "sommet " << i << ": " << monVect[i];
  return flux;
}
