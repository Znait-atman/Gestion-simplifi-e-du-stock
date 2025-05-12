#include <iostream>
#include "produit.hpp"
#include "produit.cpp"
#include <string>
#include <Windows.h>
#include <limits>

using namespace std;

int main() {
    SetConsoleOutputCP(1252); // Pour gérer les accents

    // Message d'accueil
    cout << " -----------------------------------------------------" << endl;
    cout << "|Bonjour et bienvenue dans votre espace de stockage ! |" << endl;
    cout << " -----------------------------------------------------" << endl;
    cout << endl;

    // Variables
    int id, quantite, choix, nouvelleQuantite;
    float prix, valeurTotale;
    string nom;

    // Création du produit
    cout << "Créons votre premier produit ensemble !" << endl;

    // ID du produit
    while (true) {
        cout << "Entrez l'ID du produit : ";
        cin >> id;
        if (cin.fail() || id <= 0) {
            cout << "Erreur, entrez un nombre entier positif.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }

    // Nom du produit
    cin.ignore(); // pour vider le buffer
    cout << "Entrez le nom du produit : ";
    getline(cin, nom);

    // Quantité
    while (true) {
        cout << "Entrez la quantité du produit : ";
        cin >> quantite;
        if (cin.fail() || quantite <= 0) {
            cout << "Erreur, entrez un nombre entier positif.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }

    // Prix unitaire
    while (true) {
        cout << "Entrez le prix unitaire du produit : ";
        cin >> prix;
        if (cin.fail() || prix <= 0) {
            cout << "Erreur, entrez un nombre valide.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else break;
    }

    // Création de l'objet
    produit produit(id, nom, quantite, prix);

    // Confirmation stockage
    cout << "\nProduit enregistré avec succès !\n" << endl;

    // Menu de gestion
    do {
        cout << "====================== MENU ======================" << endl;
        cout << "1. Afficher les informations du produit" << endl;
        cout << "2. Mettre à jour la quantité du produit" << endl;
        cout << "3. Calculer la valeur totale en stock" << endl;
        cout << "0. Quitter" << endl;
        cout << "==================================================" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        if (cin.fail()) {
            cout << "Erreur, entrez un nombre entier." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choix) {
            case 1:
                produit.afficher();
                break;
            case 2:
                while (true) {
                    cout << "Nouvelle quantité : ";
                    cin >> nouvelleQuantite;
                    if (cin.fail() || nouvelleQuantite < 0) {
                        cout << "Erreur, entrez un entier positif." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    } else {
                        produit.mettreAJourQuantite(nouvelleQuantite);
                        break;
                    }
                }
                break;
            case 3:
                valeurTotale = produit.calculerValeurTotale();
                cout << "Valeur totale du stock : " << valeurTotale << " €" << endl;
                break;
            case 0:
                cout << "Merci de votre visite. À bientôt !" << endl;
                break;
            default:
                cout << "Choix invalide. Essayez encore." << endl;
        }

        cout << endl;

    } while (choix != 0);

    return 0;
}
