#pragma once
#include <iostream>
#include <string.h>
#include <vector>

#include "polygone.hpp"

class Parcelle 
{
  protected:
		string type;
		int numero;
		string proprietaire;
		float surface;
		int pourcentConstructible;
		Polygone<int> forme;

    void computeSurface(); //Calcul la valeur de surface a la construction
		
  public:
    Parcelle(int num, string prop, Polygone<int> forme);
    Parcelle(Parcelle const &parc);

    int getNumero() const;
    string getProprietaire() const;
    float getSurface() const;
    Polygone<int> getForme() const;

    virtual string getType() = 0;
};


//--------------------------------------------------------------------
//Constructeurs
//--------------------------------------------------------------------

Parcelle::Parcelle(int num, string prop, Polygone<int> forme){
  this->numero = num;
  this->proprietaire = prop;
  this->forme = forme;
  computeSurface();
}

Parcelle::Parcelle(Parcelle const &parc){
  this->numero = parc.numero;
  this->proprietaire = parc.proprietaire;
  this->forme = parc.forme;
  this->surface = parc.surface;
}

//--------------------------------------------------------------------
//Getteurs et Setteurs
//-------------------------------------------------------------------

int Parcelle::getNumero() const
{
  return this->numero;
}

string Parcelle::getProprietaire() const
{
  return this->proprietaire;
}

float Parcelle::getSurface() const
{
  return this->surface;
}

Polygone<int> Parcelle::getForme() const
{
  return this-> forme;
}


//--------------------------------------------------------------------
//Les fonctions
//--------------------------------------------------------------------

void Parcelle::computeSurface()
{
  int n = forme.getSommets().size() - 1;
  vector<Point2D<int>> v;

  for(int i = 0 ; i < n ; i++){
    surface += v[i].getX()*v[i+1].getY() - v[i+1].getX()*v[i].getY();
  }
  surface = surface / 2;
}