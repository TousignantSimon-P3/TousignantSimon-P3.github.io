// Fichier : Exercices.hpp
#pragma once
#include "Livre.hpp" // Dépendance : on a besoin de connaître la struct Livre.
#include <string>    // Dépendance pour std::string dans les déclarations

// Déclarations (promesses) des fonctions que nous allons offrir.
void afficher_livre(const Livre& l);
void corriger_annee(Livre& l, int nouvelle_annee);
Livre creer_best_seller();

// Une fonction "chef d'orchestre" qui exécute tous nos exercices.
void executer_les_exercices();
