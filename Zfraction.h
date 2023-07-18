#ifndef DEF_ZFRACTION
#define DEF_ZFRACTION

#include <iostream>

class Zfraction{
    public:
    // Constructeurs
        Zfraction();  // constructeur pour c et d
        Zfraction(int n); // constructeur pour b
        Zfraction(int n, int d); // constructeur pour a
        
    // Méthode écriture (operateur <<) 
        void afficherFraction(std::ostream &os) const;

    // Simplification fractions
        int pgcd(int a, int b);
        void simplifier();

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
    

    private:
        int m_numerateur;
        int m_denominateur;
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

#endif