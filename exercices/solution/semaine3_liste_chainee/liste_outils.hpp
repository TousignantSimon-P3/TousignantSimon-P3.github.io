#pragma once

#include "Noeud.hpp"
#include "ListeChainee.hpp"
#include <vector>        // Pour la fonction to_array
#include <stdexcept>     // Pour std::runtime_error et std::out_of_range
#include <iostream>      // Pour l'affichage optionnel
#include <format>        // Pour std::format (C++20)

// Crée et retourne une liste chaînée vide.
ListeChainee creer_liste_vide() {
    return ListeChainee{}; // Initialise avec tete = nullptr et compte = 0
}

// Libère toute la mémoire allouée dynamiquement pour les nœuds de la liste
// et réinitialise la liste à un état vide.
void effacer_toute_la_liste(ListeChainee& liste) {
    Noeud* courant = liste.tete;
    while (courant != nullptr) {
        Noeud* suivant = courant->suivant;
        delete courant;
        courant = suivant;
    }
    liste.tete = nullptr;
    liste.compte = 0;
}

// Ajoute un nouveau nœud avec la valeur au début de la liste.
void ajouter_valeur_debut(ListeChainee& liste, int valeur) {
    Noeud* nouveau_noeud = new Noeud;
    nouveau_noeud->valeur = valeur;
    nouveau_noeud->suivant = liste.tete;
    liste.tete = nouveau_noeud;
    liste.compte++;
}

// Ajoute un nouveau nœud avec la valeur à la fin de la liste.
void ajouter_valeur_fin(ListeChainee& liste, int valeur) {
    Noeud* nouveau_noeud = new Noeud;
    nouveau_noeud->valeur = valeur;
    nouveau_noeud->suivant = nullptr;

    if (liste.tete == nullptr) {
        liste.tete = nouveau_noeud;
    } else {
        Noeud* courant = liste.tete;
        while (courant->suivant != nullptr) {
            courant = courant->suivant;
        }
        courant->suivant = nouveau_noeud;
    }
    liste.compte++;
}

// Ajoute un nouveau nœud avec la valeur à l'index spécifié.
// Si index <= 0, ajoute au début (index 0).
// Si index >= liste.compte, ajoute à la fin.
void ajouter_valeur_index(ListeChainee& liste, int valeur, int index) {
    if (index <= 0) {
        ajouter_valeur_debut(liste, valeur);
    } else if (index >= liste.compte) {
        ajouter_valeur_fin(liste, valeur);
    } else {
        Noeud* nouveau_noeud = new Noeud;
        nouveau_noeud->valeur = valeur;

        Noeud* courant = liste.tete;
        for (int i = 0; i < index - 1; ++i) {
            courant = courant->suivant;
        }
        nouveau_noeud->suivant = courant->suivant;
        courant->suivant = nouveau_noeud;
        liste.compte++;
    }
}

// Retire le premier nœud et retourne sa valeur.
// Lève std::runtime_error si la liste est vide.
int retirer_valeur_debut(ListeChainee& liste) {
    if (liste.tete == nullptr) {
        throw std::runtime_error("Impossible de retirer du debut: la liste est vide.");
    }
    Noeud* noeud_a_retirer = liste.tete;
    int valeur = noeud_a_retirer->valeur;
    liste.tete = liste.tete->suivant;
    delete noeud_a_retirer;
    liste.compte--;
    return valeur;
}

// Retire le dernier nœud et retourne sa valeur.
// Lève std::runtime_error si la liste est vide.
int retirer_valeur_fin(ListeChainee& liste) {
    if (liste.tete == nullptr) {
        throw std::runtime_error("Impossible de retirer de la fin: la liste est vide.");
    }
    if (liste.tete->suivant == nullptr) { // Un seul élément
        return retirer_valeur_debut(liste);
    }

    Noeud* courant = liste.tete;
    while (courant->suivant->suivant != nullptr) {
        courant = courant->suivant;
    }
    int valeur = courant->suivant->valeur;
    delete courant->suivant;
    courant->suivant = nullptr;
    liste.compte--;
    return valeur;
}

// Retire le nœud à l'index spécifié et retourne sa valeur.
// Lève std::out_of_range si l'index est invalide (négatif ou supérieur/égal au nombre d'éléments)
// ou si la liste est vide.
int retirer_valeur_index(ListeChainee& liste, int index) {
    if (liste.tete == nullptr) {
        throw std::runtime_error("Impossible de retirer a l'index: la liste est vide.");
    }
    if (index < 0 || index >= liste.compte) {
        throw std::out_of_range(std::format("Index {} hors limites [0, {})", index, liste.compte));
    }
    if (index == 0) {
        return retirer_valeur_debut(liste);
    }
    if (index == liste.compte - 1) {
        return retirer_valeur_fin(liste);
    }

    Noeud* courant = liste.tete;
    for (int i = 0; i < index - 1; ++i) {
        courant = courant->suivant;
    }
    Noeud* noeud_a_retirer = courant->suivant;
    int valeur = noeud_a_retirer->valeur;
    courant->suivant = noeud_a_retirer->suivant;
    delete noeud_a_retirer;
    liste.compte--;
    return valeur;
}

// Retourne (sans retirer) la valeur du nœud au début de la liste.
// Lève std::runtime_error si la liste est vide.
int regarder_valeur_debut(const ListeChainee& liste) {
    if (liste.tete == nullptr) {
        throw std::runtime_error("Impossible de regarder le debut: la liste est vide.");
    }
    return liste.tete->valeur;
}

// Retourne (sans retirer) la valeur du nœud à la fin de la liste.
// Lève std::runtime_error si la liste est vide.
int regarder_valeur_fin(const ListeChainee& liste) {
    if (liste.tete == nullptr) {
        throw std::runtime_error("Impossible de regarder la fin: la liste est vide.");
    }
    Noeud* courant = liste.tete;
    while (courant->suivant != nullptr) {
        courant = courant->suivant;
    }
    return courant->valeur;
}

// Retourne (sans retirer) la valeur du nœud à l'index spécifié.
// Lève std::out_of_range si l'index est invalide (négatif ou supérieur/égal au nombre d'éléments)
// ou si la liste est vide.
int regarder_valeur_index(const ListeChainee& liste, int index) {
    if (liste.tete == nullptr) {
        throw std::runtime_error("Impossible de regarder a l'index: la liste est vide.");
    }
    if (index < 0 || index >= liste.compte) {
        throw std::out_of_range(std::format("Index {} hors limites [0, {})", index, liste.compte));
    }

    Noeud* courant = liste.tete;
    for (int i = 0; i < index; ++i) {
        courant = courant->suivant;
    }
    return courant->valeur;
}

// Crée et retourne un std::vector<int> contenant toutes les valeurs de la liste dans l'ordre actuel.
std::vector<int> to_array(const ListeChainee& liste) {
    std::vector<int> tableau;
    Noeud* courant = liste.tete;
    while (courant != nullptr) {
        tableau.push_back(courant->valeur);
        courant = courant->suivant;
    }
    return tableau;
}

// Affiche les éléments de la liste dans la console.
void afficher_liste(const ListeChainee& liste) {
    std::cout << "[";
    Noeud* courant = liste.tete;
    while (courant != nullptr) {
        std::cout << courant->valeur;
        if (courant->suivant != nullptr) {
            std::cout << ", ";
        }
        courant = courant->suivant;
    }
    std::cout << "]" << std::endl;
}
