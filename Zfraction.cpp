#include <iostream>
#include "Zfraction.h"
using namespace std;

// Constructeurs 
Zfraction::Zfraction(): m_numerateur(0), m_denominateur(1){}
Zfraction::Zfraction(int n): m_numerateur(n), m_denominateur(1){}
Zfraction::Zfraction(int n, int d): m_numerateur(n), m_denominateur(d){}

// Methode operateur << 
void Zfraction::afficherFraction(ostream &os) const{
    if(this->m_denominateur == 1){
        os << this->m_numerateur;
    } else {
        os << this->m_numerateur << "/" << this->m_denominateur;
    }
}

ostream &operator<<(ostream &os, Zfraction const &objet){
    objet.afficherFraction(os);
    return os;
}

// Methode addition
Zfraction operator+(Zfraction const &a, Zfraction const &b){
    Zfraction copie(a);
    copie += b;
    return copie;
}

Zfraction& Zfraction::operator+=(Zfraction const &objet2){
    this->m_numerateur = (this->m_numerateur * objet2.m_denominateur) + (this->m_denominateur * objet2.m_numerateur);
    this->m_denominateur = this->m_denominateur * objet2.m_denominateur;

    simplifier();
    return *this;
}

// Methode multiplication
Zfraction operator*(Zfraction const &a, Zfraction const &b){
    Zfraction copie(a);
    copie *= b;
    return copie;
}

Zfraction& Zfraction::operator*=(Zfraction const &objet2){
    this->m_numerateur *= objet2.m_numerateur;
    this->m_denominateur *= objet2.m_denominateur;

    return *this;
}


// Simplification 
int Zfraction::pgcd(int a, int b){ // a = numerateur | b = denominateur
    while(b != 0){
        const int t(b);
        b = a%b;
        a=t;
    }
    return a;
}

void Zfraction::simplifier(){
    int coefDirecteur = pgcd(m_numerateur, m_denominateur);

    m_numerateur /= coefDirecteur;
    m_denominateur /= coefDirecteur;
}

// Opérateurs logiques '>' et '<'
bool operator>(Zfraction const &a, Zfraction const &b){
    if(a.estSuperieurQue(b)){return true;} 
    else {return false;}
}

bool operator<(Zfraction const &a, Zfraction const &b){
    if(a.estSuperieurQue(b)){return false;} 
    else {return true;}
}

bool Zfraction::estSuperieurQue(Zfraction const &objet2) const{
    int pAD = this->m_numerateur * objet2.m_denominateur;
    int pBC = this->m_denominateur * objet2.m_numerateur;
    if(pAD > pBC){return true;}
    else{return false;}
}

// Opérateur logique '==' et '!='
bool operator==(Zfraction const &a, Zfraction const &b){
    if(a.estEgal(b)){return true;}
    else{return false;}
}
bool operator!=(Zfraction const &a, Zfraction const &b){
    if(a.estEgal(b)){return false;}
    else{return true;}
}

bool Zfraction::estEgal(Zfraction const &objet2) const{
    if(this->m_numerateur == objet2.m_numerateur && this->m_denominateur == objet2.m_denominateur){return true;}
    else{return false;}
}