#ifndef PRODUIT_HPP_INCLUDED
#define PRODUIT_HPP_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class produit{
private:
    int m_id;
    string m_nom;
    int m_quantite;
    float m_prix;
public:
    //Constructeur
    produit();
    produit (int id, std::string nom, int quantite, float prix);

    //Méthode pour afficher les informations du produit
    void afficher();
    //Méthode pour mettre à jour la quantité
    void mettreAJourQuantite(int nouvelleQuantite);
    //Méthode pour calculer la valeur totale en stock du produit
    float calculerValeurTotale();
};
#endif // PRODUIT_HPP_INCLUDED
