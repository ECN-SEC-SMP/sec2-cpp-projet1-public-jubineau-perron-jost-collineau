#include "point2d.hpp"
#include "polygone.hpp"
#include "parcelle.hpp"
#include "types_parcelle.hpp"
#include "carte.hpp"

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

	//--------------------------------------------------------------------
  //Jeu de tests polygone
  //--------------------------------------------------------------------
  cout << endl <<  "------------------" << endl;
  cout << "Jeu de tests polygone"	<< endl;
  cout << "---------------------"	<< endl << endl;
  Point2D<int> p1(1,1);  
  Point2D<int> p2(1,2);
  Point2D<int> p3(2,1);
	Point2D<int> p4(2,2);
	
  cout << "points utilisés:" << endl;
  cout<< p1 << p2 << p3 << p4 << endl;
  
	
  //creation
  vector<Point2D<int>> monVect = {p1, p2, p3, p4};
  Polygone<int> poly1 (monVect);
	cout << "polygone 1: " << poly1 << endl;
	
  //creation par recopie
  Polygone<int> poly2 (poly1);
	cout << "polygone 2 par recopie: " << poly2 << endl;

	//translation
	poly1.translate(10, 10);

	//test translation
	cout << "polygone 1: " << poly1 << endl;
	cout << "polygone 2 par recopie: " << poly2 << endl;
  
  
  //--------------------------------------------------------------------
  //Declarations pour les parcelles
  //--------------------------------------------------------------------
  cout << endl << "------------------" << endl;
  cout << "Jeu de tests parcelle"	<< endl;
  cout << "---------------------"	<< endl << endl;
  
  Point2D<int> p11(0, 30);  
  Point2D<int> p12(60, 100);
  Point2D<int> p13(0, 100);
  vector<Point2D<int>> vecteur_zone_1 = {p11, p12, p13};
  Polygone<int> poly_zone_1 (vecteur_zone_1);

  Point2D<int> p21(0, 125);  
  Point2D<int> p22(-38, 146);
  Point2D<int> p23(-60, 115);
	Point2D<int> p24(0, 50);
  vector<Point2D<int>> vecteur_zone_2 = {p21, p22, p23, p24};
  Polygone<int> poly_zone_2 (vecteur_zone_2);

  Point2D<int> p31(-47, 300);  
  Point2D<int> p32(3, 203);
  Point2D<int> p33(50, 203);
	Point2D<int> p34(50, 282);
  vector<Point2D<int>> vecteur_zone_3 = {p31, p32, p33, p34};
  Polygone<int> poly_zone_3 (vecteur_zone_3);

  Point2D<int> p41(128, 100);  
  Point2D<int> p42(146, 171);
  Point2D<int> p43(102, 194);
	Point2D<int> p44(55, 100);
  Point2D<int> p45(111, 50);
  vector<Point2D<int>> vecteur_zone_4 = {p41, p42, p43, p44, p45};
  Polygone<int> poly_zone_4 (vecteur_zone_4);

  //--------------------------------------------------------------------
  //Jeu de tests parcelle
  //--------------------------------------------------------------------
	ZU zone_urbaine(1, "Musk", poly_zone_1, 50, 110);
	cout <<  zone_urbaine << endl;

  ZAU zone_a_urbaniser(2, "Biden", poly_zone_2, 50);
  cout <<  zone_a_urbaniser << endl;

  ZA zone_agricole(3, "Guillaume", poly_zone_3, "trefles");
  cout <<  zone_agricole << endl;

  ZN zone_naturelle(4, "Jancovici", poly_zone_4);
	cout <<  zone_naturelle << endl;

  //--------------------------------------------------------------------
  //Jeu de tests de carte
  //--------------------------------------------------------------------
  cout << "---------------------"	<< endl;
  cout << "Jeu de tests carte"	<< endl;
  cout << "---------------------"	<< endl << endl;

  Point2D<int> p100(25, -208);  
  Point2D<int> p101(0, -275);
  Point2D<int> p102(50, -300);
	Point2D<int> p103(113, -277);
  vector<Point2D<int>> vecteur_zone_105 = {p100, p101, p102, p103};
  Polygone<int> poly_zone_105 (vecteur_zone_105);
  ZU nouvelleParcelle(105, "Le_Z", poly_zone_105, 80, 115);
  
	Carte maCarte("Parcelles_short.txt");
  
  maCarte.addParcelle(&nouvelleParcelle);
  cout << maCarte << endl;
  maCarte.printToFile("sortie.txt");

  cout << "---------------------"	<< endl;

	cout << "\nfinito del madrido\n";
} 