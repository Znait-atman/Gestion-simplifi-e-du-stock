#include <iostream>
#include "produit.hpp"
#include <string>
using namespace std;

//Constructeur par d�faut ou l'initialisation se fait dans le corps
 produit::produit ()
{
    //Initialisation des attributs dans le corps du constructeur
     m_id = 0;
     m_nom = "Inconnu";
     m_quantite = 0;
     m_prix = 0;
}

//Constructeur
produit::produit (int id, std::string nom, int quantite, float prix)
{
    m_id= id;
    m_nom= nom ;
    m_quantite= quantite ;
    m_prix = prix;
}

//M�thode pour initialiser les informations du produit
void produit::afficher () {
    cout<<"Les informations du votre produit: \n"<<endl;
    cout << "Identifiant unique du produit: " << m_id << "\n"<<endl;
    cout << "Nom du produit: " << m_nom << "\n"<< endl;
    cout << "Quantit� disponible en stock: " << m_quantite << "\n"<< endl;
    cout << "Prix unitaire du produit: " << m_prix << " Euro " << "\n"<< endl;
}

//M�thode pour mettre � jour la quantit�
void produit::mettreAJourQuantite(int nouvelleQuantite)
{
    m_quantite = nouvelleQuantite;
}

 //M�thode pour calculer la valeur totale en stock du produit
float produit::calculerValeurTotale() {
    return m_quantite * m_prix;
}
