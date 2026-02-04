#pragma once

// Struct pour représenter un nœud de la liste chaînée.
// Pas de constructeur explicite requis par les consignes.
struct Noeud {
    int valeur;         // La donnée stockée dans ce nœud.
    Noeud* suivant = nullptr; // Pointeur vers le nœud suivant, initialisé à nullptr.
};
