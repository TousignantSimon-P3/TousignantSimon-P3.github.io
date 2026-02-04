#pragma once

#include "Noeud.hpp" // La liste chaînée a besoin de connaître la structure d'un Nœud.

// Struct pour représenter la liste chaînée elle-même.
// Pas de constructeur explicite requis par les consignes.
struct ListeChainee {
    Noeud* tete = nullptr; // Pointeur vers le premier nœud de la liste, initialisé à nullptr.
    int compte = 0;        // Nombre d'éléments dans la liste, initialisé à 0.
};
