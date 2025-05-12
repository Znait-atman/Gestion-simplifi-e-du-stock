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

    //M�thode pour afficher les informations du produit
    void afficher();
    //M�thode pour mettre � jour la quantit�
    void mettreAJourQuantite(int nouvelleQuantite);
    //M�thode pour calculer la valeur totale en stock du produit
    float calculerValeurTotale();
};
#endif // PRODUIT_HPP_INCLUDED
