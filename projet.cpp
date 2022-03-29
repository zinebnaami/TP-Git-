// ConsoleApplication2.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include<string>
#include <iostream>
using namespace std;




class pilote {


int code;
string nom;



public:
static int nbrP;

pilote() {
nom = "";
code = 0;
}
pilote(string n) {
nom = n;
code= nbrP++;
}



void afficher() {
cout << "nom : " << this->nom << endl << "code : " << this->code << endl;
}



string getNomP() {
return this->nom;
}



void setNom(string n) {
this->nom = n;
}



int getCode() {
return this->code;
}



int getNbPilotes() {
return nbrP;
}



};



int pilote::nbrP = 0;




class vehicule {



protected:

int numero, carburant, vitesse;
bool estDemarre;
pilote p;
int nb_roues;



public:


void set(bool d){
	estDemarre=d;
}

int getCarburant() {
return carburant;
}



int get_nb_roues()
{
return nb_roues;
}




void setestDemarre(bool n) {
this->estDemarre = n;
}
int getNumero() {
return numero;
}
static int nbrV;



vehicule() {
this->numero = 0;
numero = 0;
carburant = 0;
vitesse = 0;
estDemarre = 0;
p = pilote();
}



vehicule(int n, int c, int v, bool ed, pilote plt) {



numero = n;
carburant = c;
vitesse = v;
estDemarre = ed;
p = plt;

}




virtual void demarrer() {
if (this->carburant > 0) {
estDemarre = true;
}
else {
estDemarre = false;
}
}



void accelerer() {
if (this->estDemarre = true && carburant>0) {
this->vitesse++;
this->carburant--;
cout<<"accelere";
}
else if(this->carburant <= 0) {
this->estDemarre = false;
cout << "Carburant indisponible !" << endl;
}

}



virtual void afficher() {
cout << "num : " << this->numero  << " carburant : " << carburant << "  Pilote : " << p.getNomP() << endl;
}



virtual void addCarburant(int c) {



}



virtual void fairLePlein() {
}




};




class voiture : public vehicule{




int capaciteReservoir;
int nb_roues ;



public:







voiture( int n, int c, int v, bool ed, pilote ppp) : vehicule(n, c, v, ed, ppp) {

capaciteReservoir = 80;
nb_roues = 4;




}







void faireLeplain() {
carburant = capaciteReservoir;
}



void addCarburant(int c) {
int max = this->capaciteReservoir - this->carburant;
if (c <= max) {
this->carburant += c;
}
else {
faireLeplain();
cout << "Le plein a été fait mais la quantité(c - MAX) a débordée" << endl;
}



}



void afficher()
{
	vehicule::afficher();
cout <<  "vitesse:" << this->vitesse << "  demarage  "<<estDemarre << endl;
}



};





int vehicule::nbrV = 0;




class moto :public vehicule {




int capaciteReservoir;
int nb_roues;



public:

moto(int n, int c, int v, bool ed, pilote ppp) : vehicule(n, c, v, ed,ppp) {



capaciteReservoir = 30;
nb_roues = 2;




}



void faireLeplain() {
carburant = capaciteReservoir;
}



void addCarburant(int c) {
int max = this->capaciteReservoir - this->carburant;
if (c <= max) {
this->carburant += c;
}
else {
faireLeplain();
cout << "Le plein a été fait mais la quantité(c - MAX) a débordée" << endl;
}



}



void afficher()
{
	vehicule::afficher();
cout << "  vitesse" << this->vitesse <<" demarrer "<<estDemarre << endl;
}



};




class course {

vehicule *lesVehicules;
int nbrVehicule;



public:



course(vehicule *tableVec, int nbv) {
lesVehicules = new vehicule[20];
nbrVehicule=nbv;
for (int i = 0; i < nbrVehicule; i++) {
	lesVehicules[i]=tableVec[i];
}
}



void addVehicule(vehicule v) {

lesVehicules[nbrVehicule] = v;
nbrVehicule++;
}



vehicule getVehicule(int num) {
for (int i = 0; i < nbrVehicule; i++) {



if (lesVehicules[i].getNumero() == num) {
return lesVehicules[i];
}

}
}



void demarrerTous() {
for (int i = 0; i < nbrVehicule; i++) {
		lesVehicules[i].vehicule::demarrer();
}
}




void demarrerVoitures() {
for (int i = 0; i < nbrVehicule; i++) {
if (lesVehicules[i].get_nb_roues() == 4){
lesVehicules[i].demarrer();
}
}
}



void afficheTotaleCarburant() {



int total;
total = 0;



for (int i = 0; i < nbrVehicule; i++) {
lesVehicules[i].afficher();
total += lesVehicules[i].getCarburant();
}



cout << "total : " << total << endl;
}

int getnbv(){
	return nbrVehicule;
}

};










int main() {
pilote p1("belasla"), p2("belatar"),p3("benhsain");

voiture v1(1, 30, 40, false, p1);
voiture v3(3, 30, 40, false, p3);
moto m1(2, 20, 40, false, p2);

vehicule* V = new vehicule[10];
V[0] = v1;
V[1] = v3;
V[2] = m1;

//cout<<"v1"<<endl;
//v1.afficher();
//cout<<"v3"<<endl;
//v3.afficher();
//cout<<"m1"<<endl;
//m1.afficher();
course c(V,3);
//
//v1.addCarburant(10);
//
//cout<<"v1"<<endl;
//v1.afficher();
//
//m1.addCarburant(10);
//
//cout<<"m1"<<endl;
//m1.afficher();
c.demarrerVoitures();
cout<<"apres demarrage"<<endl;
cout<<"v1"<<endl;
v1.afficher();
cout<<"v3"<<endl;
v3.afficher();
cout<<"m1"<<endl;
m1.afficher();
//cout<<"vehicule 2"<<endl;
//vehicule v=c.getVehicule(2);
//v.afficher();
//c.afficheTotaleCarburant();
//
//
//
//for (int i = 0; i < 500; i++)
//{
//if (V[i].get_nb_roues() == 2) {
//V[i].accelerer();
//}
//cout<<"v1"<<endl;
//v1.afficher();
//cout<<"v3"<<endl;
//v3.afficher();
//cout<<"m1"<<endl;
//m1.afficher();
//
//
//
//}






}
