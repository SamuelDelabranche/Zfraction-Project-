#ifndef DEF_ZFRACTION
#define DEF_ZFRACTION

#include <iostream>
#include <cmath>

class Zfraction{
    public:
    // Constructeurs
        Zfraction(int numerateur = 0, int denominateur = 1);  // constructeur
        
    // Méthode écriture (operateur <<) 
        void afficherFraction(std::ostream &os) const;

    // Méthode addition (operator+ et +=)
        Zfraction &operator+=(Zfraction const &objet2);

    // Méthode addition (operator* et *=)
        Zfraction &operator*=(Zfraction const &objet2);

    // Surcharge d'opérateurs logiques '>' et '<'
        bool estSuperieurQue(Zfraction const &objet2) const;

    // Surcharge d'opérateurs logiques '==' et '!='
        bool estEgal(Zfraction const &objet2) const;


    // Ajout annexes
        void numerateur() const;
        void denominateur() const; 
        double nombreReel() const; // Affiche la fraction sous nombre reel

        // Surchage d'opérateurs - et /
        Zfraction &operator-=(Zfraction const &objet2);
        Zfraction &operator/=(Zfraction const &objet2);

    private:
        int m_numerateur;
        int m_denominateur;

        // Simplification fractions
        int pgcd(int a, int b);
        void simplifier();
};
std::ostream &operator<<(std::ostream &flux, Zfraction const &objet); // Ecriture

// Surcharge d'opérateurs arithmétiques
Zfraction operator+(Zfraction const &a, Zfraction const &b); // Addition
Zfraction operator*(Zfraction const &a, Zfraction const &b); // multiplication

// Surcharge d'opérateurs logiques
bool operator>(Zfraction const &a, Zfraction const &b); // a supérieur b
bool operator<(Zfraction const &a, Zfraction const &b); // a inférieur b

bool operator==(Zfraction const &a, Zfraction const &b); // a == b
bool operator!=(Zfraction const &a, Zfraction const &b); // a != b

// Ajouts annexes
Zfraction operator-(Zfraction const &a, Zfraction const &b);
Zfraction operator/(Zfraction const &a, Zfraction const &b);

#endif