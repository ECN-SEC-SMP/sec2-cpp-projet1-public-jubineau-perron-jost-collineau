#include "point2d.hpp"
#include "polygone.hpp"
#include "parcelle.hpp"

#include <iostream>
#include <vector>
using namespace std;

int main() {
  cout << "------------------"	<< endl;
  cout << "CPP TP 4 note" 			<< endl;
  cout << "------------------"	<< endl;
  cout << "Editeurs : "					<<endl;
  cout << "   @GatienJost"			<< endl; 
  cout << "   @HugoCollineau" 	<< endl;
  cout << "   @YounPerron" 			<< endl;
  cout << "   @BastienJubineau"	<< endl;
  cout << "------------------"	<< endl << endl;

  Point2D<int> p1(1,1);  
  Point2D<int> p2(1,2);
  Point2D<int> p3(2,1);
	Point2D<int> p4(2,2);
	
  cout << "points utilisés:" << endl;
  cout<<p1<<p2<<p3<<p4;
  //--------------------------------------------------------------------
  //Jeu de tests polygone
  //--------------------------------------------------------------------
	//creation
  vector<Point2D<int>> monVect = {p1, p2, p3, p4};
  Polygone<int>* poly1 = new Polygone<int> (monVect);
	cout << "polygone 1:" << poly1 << endl;
	
  //creation par recopie
  Polygone<int>* poly2 = new Polygone<int>(*poly1);
	cout << "polygone 2 par recopie:" << poly2 << endl;

	//translation
	poly1->translate(10, 10);

	//test translation
	cout << "polygone 1:" << poly1 << endl;
	cout << "polygone 2 par recopie:" << poly2 << endl;

  //Jeu de tests de parcelle 
  // Parcelle* parcelle = new Parcelle(1, "moi", *poly);
	
  cout << "\nRe\nfinito del madrido";
} 