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
		Polygone<int/*, float*/> forme;

    void computeSurface(); //Calcul la valeur de surface a la construction
		
  public:
    Parcelle(int num, string prop, Polygone<int/*, float*/> forme);
    Parcelle(Parcelle const &parc);

    int getNumero();
    string getProprietaire();
    float getSurface();
    Polygone<int/*, float*/> getForme();
    virtual string getType() =0;
};

Parcelle::Parcelle(int num, string prop, Polygone<int /*, float*/> forme){
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

int Parcelle::getNumero(){
  return this->numero;
}

string Parcelle::getProprietaire(){
  return this->proprietaire;
}

void Parcelle::computeSurface(){
  int n = forme.getSommets().size() - 1;
  vector<Point2D<int>> v;

  for(int i = 0 ; i < n ; i++){
    surface += v[i].getX()*v[i+1].getY() - v[i+1].getX()*v[i].getY();
  }
  surface = surface / 2;
}

float Parcelle::getSurface(){
  return surface;
}