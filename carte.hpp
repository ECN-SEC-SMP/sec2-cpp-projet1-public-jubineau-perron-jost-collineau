#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <stdio.h>

#include "parcelle.hpp"
#include "types_parcelle.hpp"

using namespace std;

class Carte
{
  private:
    vector<Parcelle*> listeParcelles;

	public :
	  Carte(string nomFichier);

    void printToFile(string fileName);
    string toString();
    friend std::ostream& operator<< (ostream &, Carte &);

    void addParcelle(Parcelle* p);
};

Carte::Carte(string nomFichier){
	int numParcelle = 0;
  int p_surfaceConstructible = 0;
	float surfaceConstruite = 0;
	string nomProprio;
	string typeCulture;
	
	string line;
	string line_points;

	ifstream myfile;
  myfile.open (nomFichier);
	//for each line
  while ( getline(myfile,line) )
  {
    getline(myfile,line_points);
    vector<Point2D<int>> vecteur_zone;
		int startBracketPos = 0;
		int ptVirgulePos = 0;
		int endBracketsPos = 0;
		string myXStr;
		string myYStr;
		//int lastEndBracketsPos;
		while (line_points.find("[", endBracketsPos) != string::npos){
			startBracketPos = line_points.find("[", endBracketsPos);
			ptVirgulePos = line_points.find(";", startBracketPos);
			endBracketsPos = line_points.find("]", ptVirgulePos);
			myXStr = line_points.substr(startBracketPos+1, ptVirgulePos-startBracketPos+1);
			myYStr = line_points.substr(ptVirgulePos+1, endBracketsPos-ptVirgulePos+1);
			Point2D<int> monPoint(stoi(myXStr), stoi(myYStr));
		//	std::cout << "POINT CREE :" << monPoint << std::endl;
			vecteur_zone.push_back(monPoint);
  
		}
    
		Polygone<int> poly_zone (vecteur_zone);
		//std::cout << poly_zone << std::endl; //debug

		//recup data + creation de la parcelle appropriée
		string space_delimiter = " ";
    vector<string> words;
    size_t pos = 0;
		//remove spaces
    string currentWord = "";
		int y = 0;
		for (int i = 0; i < line.size(); i++){
			if((line[i] == ' ') && (currentWord != "")){
        words.push_back(currentWord);
        currentWord = "";
      }
      else
        currentWord += line[i];
		}

    if(currentWord != ""){
      words.push_back(currentWord);
    }

		if (!strcmp(words[0].c_str(), "ZU")){
      //numéro propriétaire pConstructible surfaceConstruite
			numParcelle = stoi(words[1].c_str());
			nomProprio = words[2].c_str();
			p_surfaceConstructible = stoi(words[3].c_str());
			surfaceConstruite = stof(words[4].c_str());

			ZU* maZU = new ZU(numParcelle, nomProprio, poly_zone, p_surfaceConstructible, surfaceConstruite);
			listeParcelles.push_back(maZU);
		}
		else if (!strcmp(words[0].c_str(), "ZAU")){
      //numéro propriétaire pConstructible
			numParcelle = stoi(words[1].c_str());
			nomProprio = words[2].c_str();
			p_surfaceConstructible = stoi(words[3].c_str());

      ZAU* maZAU = new ZAU(numParcelle, nomProprio, poly_zone, p_surfaceConstructible);
			listeParcelles.push_back(maZAU);
		}
		else if (!strcmp(words[0].c_str(), "ZA")){
      //numéro propriétaire typeCulture
			numParcelle = stoi(words[1].c_str());
			nomProprio = words[2].c_str();
			typeCulture = words[3].c_str();

      ZA* maZA = new ZA(numParcelle, nomProprio, poly_zone, typeCulture);
			listeParcelles.push_back(maZA);
		}
		else if (!strcmp(words[0].c_str(), "ZN")){
      //numéro propriétaire
			numParcelle = stoi(words[1].c_str());
			nomProprio = words[2].c_str();

      ZN* maZN = new ZN(numParcelle, nomProprio, poly_zone);
			listeParcelles.push_back(maZN);
		}
		else {
			cout << "ERREUR PARSING CARTE" << endl;
		}
  }
  myfile.close();
}

/*
ZU 17 Martin 55 1003
[0;30] [60;100] [0;100] 
ZAU 25 Robert 16 
[0;30] [80;30] [80;100] [60;100] 
ZA 42 Babin blé
[0;0] [80;0] [80;30] [0;30]
ZN 54 Savard 
[80;0] [100;0] [100;100] [80;100]
*/

string Carte::toString(){
  string s = "";
  string type = "";

  for(int i=0 ; i < listeParcelles.size() ; i++){
    type = listeParcelles[i]->getType();

    //Affichage des parametres de la parcelle en fonction de son type 
    if(type == "ZU"){
      ZU* p = dynamic_cast<ZU*>(listeParcelles[i]);
      
      s += "ZU ";
      s += to_string(listeParcelles[i]->getNumero()) + " ";
      s += listeParcelles[i]->getProprietaire() + " ";
      s += to_string(p->getPourcentageConstructible())+ " ";
      s += to_string((int) p->getSurfaceConstruite()) + "\n";
    }
    else if(type == "ZN"){
      s += "ZN ";
      s += to_string(listeParcelles[i]->getNumero()) + " ";
      s += listeParcelles[i]->getProprietaire() + " \n";
    }
    else if(type == "ZAU"){
      ZAU* p = dynamic_cast<ZAU*>(listeParcelles[i]);
      s += "ZAU ";
      s += to_string(listeParcelles[i]->getNumero()) + " ";
      s += listeParcelles[i]->getProprietaire() + " ";
      s += to_string((int) p->getPourcentageConstructible())+ " \n";
    }
    else if(type == "ZA"){
      //indication du chemin d'héritage à prendre Parcelle->ZN->ZA pour eviter les ambiguites
      ZA* p = dynamic_cast<ZA*>(dynamic_cast<ZN*>(listeParcelles[i]));
      
      s += "ZA ";
      s += to_string(listeParcelles[i]->getNumero()) + " ";
      s += listeParcelles[i]->getProprietaire() + " ";
      s += p->getTypeCulture() + " \n";
    }
    else if(type == "ZN"){
      s += "ZN ";
      s += to_string(listeParcelles[i]->getNumero()) + " ";
      s += listeParcelles[i]->getProprietaire() + " \n";
    }
    else{
      s += "ERREUR DE TYPE\n";
    }

    vector <Point2D<int>> monVect = listeParcelles[i]->getForme().getSommets();
    for(int i = 0 ; i < monVect.size() ; i++){
      s	+= "[" + to_string(monVect[i].getX()) + ";" + to_string(monVect[i].getY()) + "]" + " ";
    }
    s += "\n";
  }
  return s;
}

void Carte::printToFile(string fileName){
	std::ofstream out(fileName);
  out << this->toString();
  out.close();
}

std::ostream& operator<< (ostream &os, Carte &c){
  os << c.toString();
  return os;
}


void Carte::addParcelle(Parcelle* p){
  listeParcelles.push_back(p);
}