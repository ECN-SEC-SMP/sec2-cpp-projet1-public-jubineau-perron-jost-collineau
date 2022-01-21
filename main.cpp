#include "point2d.hpp"
#include "polygone.hpp"
#include "parcelle.hpp"
#include "types_parcelle.hpp"
//#include "carte.hpp"

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

	//--------------------------------------------------------------------
  //Jeu de tests polygone
  //--------------------------------------------------------------------
  /*
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

  cout << "---------------------"	<< endl << endl;
  */
	//--------------------------------------------------------------------
  
  
  //--------------------------------------------------------------------
  //Declarations pour les parcelles
  //--------------------------------------------------------------------
  cout << "Jeu de tests parcelle"	<< endl;
  cout << "---------------------"	<< endl << endl;

  Point2D<int> p11(0, 30);  
  Point2D<int> p12(60, 100);
  Point2D<int> p13(100, 0);
	Point2D<int> p14(80, 80);
  vector<Point2D<int>> vecteur_zone_1 = {p11, p12, p13, p14};
  Polygone<int> poly_zone_1 (vecteur_zone_1);

  Point2D<int> p21(0, 0);  
  Point2D<int> p22(150, 150);
  Point2D<int> p23(50, 0);
	Point2D<int> p24(0, 50);
  vector<Point2D<int>> vecteur_zone_2 = {p21, p22, p23, p24};
  Polygone<int> poly_zone_2 (vecteur_zone_2);

  Point2D<int> p31(250, 250);  
  Point2D<int> p32(15, 85);
  Point2D<int> p33(50, 50);
	Point2D<int> p34(2, 8);
  vector<Point2D<int>> vecteur_zone_3 = {p31, p32, p33, p34};
  Polygone<int> poly_zone_3 (vecteur_zone_3);

  Point2D<int> p41(8, 42);  
  Point2D<int> p42(77, 77);
  Point2D<int> p43(25, 25);
	Point2D<int> p44(34, 28);
  vector<Point2D<int>> vecteur_zone_4 = {p41, p42, p43, p44};
  Polygone<int> poly_zone_4 (vecteur_zone_4);

  //--------------------------------------------------------------------
  //Jeu de tests parcelle
  //--------------------------------------------------------------------
	ZU zone_urbaine(1, "Musk", poly_zone_1, 50);
	cout <<  zone_urbaine << endl;

  // cout << "La surface construite de la zone urbaine est : " << endl;
  // cout << zone_urbaine.getSurfaceConstruite() << endl;
  // cout << "Calcul de la surface constructible restante :" << endl; 
  // cout << "(la surface construcible totale est 80% de la parcelle)" << endl;
  // float surface_constructible = zone_urbaine.surfaceConstructible();
  // cout << "La surface construcible restante est : " << surface_constructible << endl;
  

  // ZAU zone_a_urbaniser(2, "Biden", poly_zone_2);
  // cout <<  zone_a_urbaniser << endl;
  // cout << "Calcul de la surface constructible :" << endl; 
  // cout << "(la surface construcible totale est 80% de la parcelle)" << endl;
  // float surface_constructible2 = zone_a_urbaniser.surfaceConstructible();
  // cout << "La surface construcible restante est : " << surface_constructible << endl;

  // ZA zone_agricole(3, "Guillaume", poly_zone_3, "trefles");
  // cout <<  zone_agricole << endl;

  // ZN zone_naturelle(4, "Jancovici", poly_zone_4);
	// cout <<  zone_naturelle << endl;

  cout << "---------------------"	<< endl << endl;
	//Carte maCarte("Parcelles_short.txt");
	cout << "\nfinito del madrido";
} 