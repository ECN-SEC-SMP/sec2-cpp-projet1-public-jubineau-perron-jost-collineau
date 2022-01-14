#pragma once
#include <iostream>
#include <string.h>
#include <vector>

#include "parcelle.hpp"

class Constructible : public Parcelle
{
  protected:
    int pourcentageConstructible;
	public:
    Constructible(int num, string prop, Polygone<int> forme) : Parcelle(num, prop, forme){}

    //Calcul la valeur de surface constructible
    virtual float surfaceConstructible() =0;
};

//Zones Urbaines (ZU)
class ZU : public Constructible
{
  protected:
	  float surfaceConstruite;
  public:
    ZU(int num, string prop, Polygone<int> forme, int _surfaceConstruite) : Constructible(num, prop, forme){
      this->surfaceConstruite = _surfaceConstruite;
    }

    //Calcul la valeur de surface constructible
    float surfaceConstructible(void);

};

//Zones à Urbaniser (ZAU)
class ZAU : public Constructible
{
  protected:
  public:
		ZAU(int num, string prop, Polygone<int> forme) : Constructible(num, prop, forme){
      
    }

    //Calcul la valeur de surface constructible
    float surfaceConstructible(void);

};

//Zones Agricoles (ZA)
class ZA : public Constructible
{
  protected:
		string typeCulture;
  public:
  	ZA(int num, string prop, Polygone<int> forme, string typeCu) : Constructible(num, prop, forme){
      
  	}
};

//Zones Naturelles et Forestières (ZN)
class ZN : public Parcelle
{
  protected:
    string typeCulture;
  public:
		ZN(int num, string prop, Polygone<int> forme) : Parcelle(num, prop, forme){
      
  	}
};

