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

    int getPourcentageConstructible(){
      return this->pourcentageConstructible;
    }
};

/*
 *	Zones Urbaines (ZU)
 */
class ZU : public Constructible
{
  protected:
	  float surfaceConstruite;
  public:
    ZU(int num, string prop, Polygone<int> forme, float _surfaceConstruite) : Constructible(num, prop, forme)
    {
      this->pourcentageConstructible = 80;
      this->surfaceConstruite = _surfaceConstruite;
    }
 		string getType() const {return "ZU";}

    float getSurfaceConstruite() const {return surfaceConstruite;}
    
    //Calcul la valeur de surface constructible
    float surfaceConstructible(void) {
      float surface_constructible = 0;
      //Le 200 est a remplacer par surface lorsque le calcul de la surface
      //de la parcelle sera termine
      float surface_constructible_totale = ((float)pourcentageConstructible / 100) * 250;

      if( surface_constructible_totale >= surfaceConstruite)
      {
        surface_constructible = (((float)pourcentageConstructible / 100) * 250) - this->surfaceConstruite;
      }
  
      return surface_constructible;
    }

		friend std::ostream& operator<< (std::ostream &, ZU const&);
};

/*
 *	Zones à Urbaniser (ZAU)
 */
class ZAU : public Constructible
{
  public:
		ZAU(int num, string prop, Polygone<int> forme) : Constructible(num, prop, forme)
    {
      this-> pourcentageConstructible = 60;    
    }

		string getType() const {return "ZAU";}

    //Calcul la valeur de surface constructible
    float surfaceConstructible(void) {
      //Le 200 est a remplacer par surface lorsque le calcul de la surface
      //de la parcelle sera termine
      float surface_constructible = (float(pourcentageConstructible) / 100) * 250; 
      return surface_constructible;
    }

		friend std::ostream& operator<< (std::ostream &, ZAU const&);
};

/*
 *	Zones Naturelles et Forestières (ZN)
 */
class ZN : public Parcelle
{
  public:
		ZN(int num, string prop, Polygone<int> forme) : Parcelle(num, prop, forme){}
		string getType() const {return "ZN";}

    friend std::ostream& operator<< (std::ostream &, ZN const&);
};

/*
 *	Zones Agricoles (ZA)
 */
class ZA : public ZN, public Constructible
{
  protected:
		string typeCulture;
  public:
  	ZA(int num, string prop, Polygone<int> forme, string typeCult) 
			:ZN(num, prop, forme)
			,Constructible(num, prop, forme)
    {
      this->typeCulture = typeCult;
      this->pourcentageConstructible = 10;
  	}
		float surfaceConstructible(void) {
      //Le 250 est a remplacer par surface lorsque le calcul de la surface
      //de la parcelle sera termine
      float surface_constructible = (float(pourcentageConstructible) / 100) * 250; 

      if(surface_constructible >= 200)
      {
        surface_constructible = 200;
      }
			return surface_constructible;
    }

		string getType() const {return "ZA";}
    string getTypeCulture() const {return typeCulture;}

    //Pour eviter les ambiguites (Ne fonctionne pas)
    /*
    using Constructible::getNumero;
    using Constructible::getForme;
    using Constructible::getProprietaire;
    using Constructible::getSurface;
    */
		friend std::ostream& operator<< (std::ostream &, ZA &);		
};

//-----------------------------------------------------------
// SURCHARGE OPERATEURS <<
//-----------------------------------------------------------

/*
 *	Surcharge opérateur << pour ZU
 */
std::ostream& operator<< (std::ostream &flux, ZU &p )
{
  flux << "Parcelle n°" << p.getNumero() << " :" << endl
       << "  Type : " << p.getType() << endl
       << "  Polygone : " << p.getForme() << endl
       << "  Proprietaire : " << p.getProprietaire() << endl
       << "  Surface : " << p.getSurface() << endl
       << "  % constructible : " << p.getPourcentageConstructible() << "%" << endl
       << "  Surface construite : " << p.getSurfaceConstruite() << endl
       << "  Surface a construire restante : " << p.surfaceConstructible() << endl;
  return flux;
}

/*
 *	Surcharge opérateur << pour ZA
 */
std::ostream& operator<< (std::ostream &flux, ZA &p )
{
  //cast static pour les fonctions ambigues
  ZN _p = static_cast<ZN&>(p);
  flux << "Parcelle n°" << _p.getNumero() << " :" << endl
       << "  Type : " << p.getType() << endl
       << "  Polygone : " << _p.getForme() << endl
       << "  Proprietaire : " << _p.getProprietaire() << endl
       << "  Surface : " << _p.getSurface() << endl
       << "  TypeCulture : " << p.getTypeCulture() << endl
       << "  % constructible : " << p.getPourcentageConstructible() << "%" << endl
       << "  Surface constructible (limite a 200m² sinon 10%) : " << p.surfaceConstructible() << endl;
  return flux;
}

/*
 *	Surcharge opérateur << pour ZN
 */
std::ostream& operator<< (std::ostream &flux, ZN &p )
{
  flux << "Parcelle n°" << p.getNumero() << " :" << endl
       << "  Type : " << p.getType() << endl
       << "  Polygone : " << p.getForme() << endl
       << "  Proprietaire : " << p.getProprietaire() << endl
       << "  Surface : " << p.getSurface() << endl;
  return flux;
}

/*
 *	Surcharge opérateur << pour ZAU
 */
std::ostream& operator<< (std::ostream &flux, ZAU &p )
{
  flux << "Parcelle n°" << p.getNumero() << " :" << endl
       << "  Type : " << p.getType() << endl
       << "  Polygone : " << p.getForme() << endl
       << "  Proprietaire : " << p.getProprietaire() << endl
       << "  Surface : " << p.getSurface() << endl
       << "  % constructible : " << p.getPourcentageConstructible() << "%" << endl
       << "  Surface a construire restante : " << p.surfaceConstructible() << endl;
  return flux;
}