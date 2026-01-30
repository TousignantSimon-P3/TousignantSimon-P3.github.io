// Fichier : Exercices.cpp
#include "Exercices.hpp" // On inclut le menu des fonctions à implémenter.
#include <iostream>
#include <format>

// Implémentation de la fonction d'affichage
void afficher_livre(const Livre& l) {
    std::cout << std::format("--- Fiche du Livre ---\n");
    std::cout << std::format("Titre: {}\n", l.titre);
    std::cout << std::format("Auteur: {}\n", l.auteur);
    std::cout << std::format("Année: {}\n", l.annee_publication);
    std::cout << "----------------------\n\n";
}

// Implémentation de la fonction de modification
void corriger_annee(Livre& l, int nouvelle_annee) {
    l.annee_publication = nouvelle_annee;
}

// Implémentation de la "Factory Function"
Livre creer_best_seller() {
    Livre best_seller {
        .titre = "Dune",
        .auteur = "Frank Herbert",
        .annee_publication = 1965
    };
    return best_seller; // Retour par copie
}

// Implémentation du chef d'orchestre
void executer_les_exercices() {
    std::cout << "--- DEBUT DES EXERCICES ---\n\n";

    // --- Exercice 1: Définition et Initialisation ---
    std::cout << "--- Exercice 1 ---\n";
    Livre mon_livre_favori {
        .titre = "Le Seigneur des Anneaux",
        .auteur = "J.R.R. Tolkien",
        .annee_publication = 1954
    };
    // L'affichage se fait via la fonction de l'exercice 2 pour ne pas répéter de code.
    std::cout << "Livre favori créé.\n\n";


    // --- Exercice 2: Passage en Lecture Seule ---
    std::cout << "--- Exercice 2 ---\n";
    std::cout << "Affichage du livre favori :\n";
    afficher_livre(mon_livre_favori);


    // --- Exercice 3: Passage en Lecture/Écriture ---
    std::cout << "--- Exercice 3 ---\n";
    std::cout << "Correction de l'année de publication...\n";
    corriger_annee(mon_livre_favori, 1955); // Oups, une erreur dans l'année !
    std::cout << "Affichage après correction :\n";
    afficher_livre(mon_livre_favori);


    // --- Exercice 4: Manipulation par Pointeur ---
    std::cout << "--- Exercice 4 ---\n";
    Livre* ptr_livre = &mon_livre_favori;
    std::cout << "Modification de l'auteur via pointeur...\n";
    ptr_livre->auteur = "John Ronald Reuel Tolkien";
    std::cout << "Affichage après modification de l'auteur :\n";
    afficher_livre(mon_livre_favori);

    
    // --- Exercice 5: "Factory Function" ---
    std::cout << "--- Exercice 5 ---\n";
    std::cout << "Création d'un best-seller via la factory...\n";
    Livre mon_best_seller = creer_best_seller();
    afficher_livre(mon_best_seller);

    std::cout << "--- FIN DES EXERCICES ---\n";
}
