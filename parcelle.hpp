#pragma once
#include <iostream>
#include <string.h>
#include <vector>

#include "polygone.hpp"

using namespace std;

class Parcelle 
{
  protected:
		//string type;
		int numero;
		string proprietaire;
		float surface;
		int pourcentConstructible;
		Polygone<int> forme;

    void computeSurface(); //Calcul la valeur de surface a la construction
    void triOrdreTrigo(vector<Point2D<int>> *vect); //A finir
		
  public:
    Parcelle(int num, string prop, Polygone<int> forme);
    Parcelle(Parcelle const &parc);

    int getNumero() const;
    string getProprietaire() const;
    float getSurface() const;
    Polygone<int> getForme() const;

    virtual string getType() const = 0;
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
//@TODO calculer en prenant les sommets dans l'ordre trigonometrique
void Parcelle::computeSurface()
{
  // surface = 0;
  // int n = forme.getSommets().size() - 1;
  // vector<Point2D<int>> v = forme.getSommets();
  // //triOrdreTrigo(&v); // A FINIR

  // for(int i = 0 ; i < n ; i++){
  //   surface += v[i].getX()*v[i+1].getY() - v[i+1].getX()*v[i].getY();
  //   //cout << "surface: " << surface << endl;//DEBUG
  // }
  // // surface = surface / 2;

  surface = 250;

  //cout << "surface: " << surface << endl << endl;
}

/**
 *  Reorganise le vecteur dans l'ordre trigo
 *  A FINIR
 */
void Parcelle::triOrdreTrigo(vector<Point2D<int>> *vect){
  /*
  float currPente, memPente;
  int n = vect->size();
  int i=0, y=0; 
  vector<Point2D<int>> inVect = *vect;		//?

  //Vecteur temporaire qui sera retourne a la fin
  vector<Point2D<int>> newVect;
  vector<Point2D<int>>::iterator it;

  //Init du premier element (necessaire pour commencer le tri)
  newVect.insert(newVect.begin(), inVect[0]);

  for(i = 1 ; i < n ; i++){
    currPente = inVect[i].getX() / inVect[i].getY();

    y = 0;
    memPente = newVect[y].getX() / newVect[y].getY();
    while( (currPente < memPente) && (y < n)){
      it++;
      memPente = newVect[y].getX() / newVect[y].getY();
    }
    newVect.insert(y, inVect[0]);
  }
  */
}