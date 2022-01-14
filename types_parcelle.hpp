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

/*
 *	Zones Urbaines (ZU)
 */
class ZU : public Constructible
{
  protected:
	  float surfaceConstruite;
    int p_surfaceConstructible = 80;
  public:
    ZU(int num, string prop, Polygone<int> forme, float _surfaceConstruite) : Constructible(num, prop, forme){
      this->surfaceConstruite = _surfaceConstruite;

    }
 		string getType() const {return "ZU";}

    float getSurfaceConstruite() const {return surfaceConstruite;}
    
    //Calcul la valeur de surface constructible
    float surfaceConstructible(void) {
      float surface_constructible = 0;
      if(((p_surfaceConstructible / 100) * surface) >= surfaceConstruite)
      {
        surface_constructible = ((p_surfaceConstructible / 100) * surface) - surfaceConstruite; 
      }
      else {surface_constructible = 0;}
      return surface_constructible;
    }

		friend std::ostream& operator<< (std::ostream &, ZU const&);
};

/*
 *	Zones à Urbaniser (ZAU)
 */
class ZAU : public Constructible
{
  protected:
    int p_surfaceConstructible = 80;
  public:
		ZAU(int num, string prop, Polygone<int> forme) : Constructible(num, prop, forme){
    }
		string getType() const {return "ZAU";}

    //Calcul la valeur de surface constructible
    float surfaceConstructible(void) {
      float surface_constructible = (p_surfaceConstructible / 100) * surface; 
      return surface_constructible;
    }

		friend std::ostream& operator<< (std::ostream &, ZAU const&);
};

/*
 *	Zones Naturelles et Forestières (ZN)
 */
class ZN : public Parcelle
{
  protected:
    string typeCulture;
  public:
		ZN(int num, string prop, Polygone<int> forme, string typeCult) : Parcelle(num, prop, forme){
      this->typeCulture = typeCult;
  	}
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
			:ZN(num, prop, forme, typeCult) 
			,Constructible(num, prop, forme){
      this->typeCulture = typeCult;
  	}
		float surfaceConstructible(void) {
      //TODO A CALCULER !!!!!
			return 0;
    }
		string getType() const {return "ZA";}
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
       << "  " << p.getForme() << endl
       << "  Proprietaire : " << p.getProprietaire() << endl
       << "  Surface : " << p.getSurface() << endl
       << "  % constructible : " << p.surfaceConstructible() << "%" << endl
       << "  surface construite : " << p.getSurfaceConstruite() << endl
       << "  surface a construire restante : " << p.surfaceConstructible() - p.getSurfaceConstruite() << endl;
  return flux;
}

/*
 *	Surcharge opérateur << pour ZA
 */
std::ostream& operator<< (std::ostream &flux, ZA &p )
{
  flux << "Parcelle n°" << p.getNumero() << " :" << endl
       << "  Type : " << p.getType() << endl
       << "  " << p.getForme() << endl
       << "  Proprietaire : " << p.getProprietaire() << endl
       << "  Surface : " << p.getSurface() << endl
       << "  % constructible : " << p.surfaceConstructible() << "%" << endl;
			 //TODO A COMPLETER
  return flux;
}

/*
 *	Surcharge opérateur << pour ZN
 */
std::ostream& operator<< (std::ostream &flux, ZN &p )
{
  /*flux << "Parcelle n°" << p.getNumero() << " :" << endl
       << "  Type : " << p.getType() << endl
       << "  " << p.getForme() << endl
       << "  Proprietaire : " << p.getProprietaire() << endl
       << "  Surface : " << p.getSurface() << endl;*/
  return flux;
}

/*
 *	Surcharge opérateur << pour ZAU
 */
std::ostream& operator<< (std::ostream &flux, ZAU &p )
{
  //flux << "[" << p.getX()  << ";" << p.getY() << "]";
  return flux;
}