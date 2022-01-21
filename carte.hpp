#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

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
	string line;
	ifstream myfile;
  myfile.open (nomFichier);
	int numParcelle;
	string nomProprio,
	
	//for each line
  while ( getline(myfile,line) )
  {
		string space_delimiter = " ";
    vector<string> words{};
    size_t pos = 0;

		//remove spaces
    while ((pos = line.find(space_delimiter)) != string::npos) {
        words.push_back(line.substr(0, pos));
        line.erase(0, pos + space_delimiter.length());
    }
		//debugging only for loop
    for (const auto &str : words) {
        cout << str << endl;
    }
		if (!strcmp(words[1], "ZU")){
			ZU maZU();

		}
		else if (!strcmp(words[1], "ZAU")){
			ZAU maZAU();

		}
		else if (!strcmp(words[1], "ZA")){
			ZA maZA();

		}
		else if (!strcmp(words[1], "ZN")){
			ZN maZN();
			
		}
		else
			//DontKnowWhatToDo();
  	//words[1]

		//Parcelle(int num, string prop, Polygone<int> forme)
  }
  myfile.close();
  //return 0;
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
    
  }

  return s;
}

void Carte::printToFile(string fileName){
	std::ofstream out(fileName);
  out << this->toString();
  out.close();
}