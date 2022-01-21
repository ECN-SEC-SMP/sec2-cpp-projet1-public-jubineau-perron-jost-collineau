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
    vector<Parcelle> listeParcelles;

	public :
	  Carte(string nomFichier);

    void printToFile(string fileName);
    string toString();

    friend std::ostream& operator<< (ostream &, Carte const&);
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
    
		Polygone<int> poly_zone_2 (vecteur_zone);
		std::cout << poly_zone_2 << std::endl; //debug

		//recup data + creation de la parcelle appropriée
		string space_delimiter = " ";
    vector<string> words{};
    size_t pos = 0;
		//remove spaces
    while ((pos = line.find(space_delimiter)) != string::npos) {
        words.push_back(line.substr(0, pos));
        line.erase(0, pos + space_delimiter.length());
    }

		/*//debugging only for loop
    for (const auto &str : words) {
        cout << str << endl;
    }*/
		if (!strcmp(words[0].c_str(), "ZU")){
			//ZU maZU();
			numParcelle = stoi(words[1].c_str());
			nomProprio = words[2].c_str();
			p_surfaceConstructible = stoi(words[3].c_str());
			surfaceConstruite = stof(words[4].c_str());
			std::cout << "test" <<std::endl;
		}
		else if (!strcmp(words[0].c_str(), "ZAU")){
			//ZAU maZAU();
			numParcelle = stoi(words[1].c_str());
			nomProprio = words[2].c_str();
			p_surfaceConstructible = stoi(words[3].c_str());
		}
		else if (!strcmp(words[0].c_str(), "ZA")){
			//ZA maZA();
			numParcelle = stoi(words[1].c_str());
			nomProprio = words[2].c_str();
			typeCulture = words[3].c_str();
		}
		else if (!strcmp(words[0].c_str(), "ZN")){
			//ZN maZN();
			numParcelle = stoi(words[1].c_str());
			nomProprio = words[2].c_str();
		}
		else {
			cout << "ERREUR PARSING CARTE" << endl;
		}
  	std::cout << "numparcelle " << numParcelle << std::endl;
		std::cout << "nomproprio " << nomProprio << std::endl;

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

  for(int i=0 ; i < listeParcelles.size() ; i++){
    //Affichage des parametres de la parcelle en fonction de son type 
    if(listeParcelles[i].getType() == "ZU"){
      ZU p = static_cast<ZU&>(listeParcelles[i]);

      s += "ZU ";
      s += to_string(listeParcelles[i].getNumero()) + " \n";
      s += listeParcelles[i].getProprietaire() + " \n";
      s += to_string(p.getPourcentageConstructible())+ " \n";
      s += to_string(p.getSurfaceConstruite()) + "\n";
    }
    else if(listeParcelles[i].getType() == "ZN"){
      s += "ZN ";
      s += to_string(listeParcelles[i].getNumero()) + " \n";
      s += listeParcelles[i].getProprietaire() + " \n";
    }
    else if(listeParcelles[i].getType() == "ZAU"){
      ZAU p = static_cast<ZAU&>(listeParcelles[i]);
      s += "ZAU ";
      s += to_string(listeParcelles[i].getNumero()) + " \n";
      s += listeParcelles[i].getProprietaire() + " \n";
      s += to_string(p.getPourcentageConstructible())+ " \n";
    }
    else if(listeParcelles[i].getType() == "ZA"){
      //indication du chemin d'héritage à prendre Parcelle->ZN->ZA pour eviter les ambiguite
      ZA p = static_cast<ZA&>(static_cast<ZN&>(listeParcelles[i]));
      
      s += "ZA ";
      s += to_string(listeParcelles[i].getNumero()) + " \n";
      s += listeParcelles[i].getProprietaire() + " \n";
      s += p.getTypeCulture();
    }
    else /* ZN */{
      s += "ZN ";
      s += to_string(listeParcelles[i].getNumero()) + " \n";
      s += listeParcelles[i].getProprietaire() + " \n";
    }
    vector <Point2D<int>> monVect = listeParcelles[i].getForme().getSommets();
	
    for(int i = 0 ; i < monVect.size() ; i++){
      s	+= "[" + to_string(monVect[i].getX()) + ";" + to_string(monVect[i].getY()) + "]" + " ";
    }
  }
  return s;
}

void Carte::printToFile(string fileName){
	std::ofstream out(fileName);
  out << this->toString();
  out.close();
}