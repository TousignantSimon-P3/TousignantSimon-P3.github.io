#include <iostream>
#include <vector>
#include <stdexcept>
#include <cassert> // Pour les assertions basiques

#include "Noeud.hpp"
#include "ListeChainee.hpp"
#include "liste_outils.hpp"

void test_creation_et_ajout() {
    std::cout << "--- Test de creation et ajout ---" << std::endl;
    ListeChainee ma_liste = creer_liste_vide();
    afficher_liste(ma_liste); // Devrait afficher []
    assert(ma_liste.compte == 0);

    ajouter_valeur_debut(ma_liste, 10);
    afficher_liste(ma_liste); // Devrait afficher [10]
    assert(ma_liste.compte == 1);
    assert(regarder_valeur_debut(ma_liste) == 10);

    ajouter_valeur_fin(ma_liste, 20);
    afficher_liste(ma_liste); // Devrait afficher [10, 20]
    assert(ma_liste.compte == 2);
    assert(regarder_valeur_fin(ma_liste) == 20);

    ajouter_valeur_index(ma_liste, 15, 1);
    afficher_liste(ma_liste); // Devrait afficher [10, 15, 20]
    assert(ma_liste.compte == 3);
    assert(regarder_valeur_index(ma_liste, 1) == 15);

    ajouter_valeur_index(ma_liste, 5, 0); // Ajout au début
    afficher_liste(ma_liste); // Devrait afficher [5, 10, 15, 20]
    assert(ma_liste.compte == 4);
    assert(regarder_valeur_debut(ma_liste) == 5);

    ajouter_valeur_index(ma_liste, 25, 100); // Ajout à la fin
    afficher_liste(ma_liste); // Devrait afficher [5, 10, 15, 20, 25]
    assert(ma_liste.compte == 5);
    assert(regarder_valeur_fin(ma_liste) == 25);

    std::cout << "Test de creation et ajout reussi." << std::endl;
    effacer_toute_la_liste(ma_liste); // Nettoyage
}

void test_regarder_valeurs() {
    std::cout << "
--- Test de regarder valeurs ---" << std::endl;
    ListeChainee ma_liste = creer_liste_vide();
    ajouter_valeur_debut(ma_liste, 10);
    ajouter_valeur_fin(ma_liste, 20);
    ajouter_valeur_index(ma_liste, 15, 1); // Liste: [10, 15, 20]
    afficher_liste(ma_liste);

    assert(regarder_valeur_debut(ma_liste) == 10);
    assert(regarder_valeur_fin(ma_liste) == 20);
    assert(regarder_valeur_index(ma_liste, 1) == 15);

    try {
        regarder_valeur_index(ma_liste, 3); // Index hors limites
        assert(false && "Devrait lancer une exception pour index hors limites");
    } catch (const std::out_of_range& e) {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }

    ListeChainee liste_vide = creer_liste_vide();
    try {
        regarder_valeur_debut(liste_vide); // Liste vide
        assert(false && "Devrait lancer une exception pour liste vide");
    } catch (const std::runtime_error& e) {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }
    
    std::cout << "Test de regarder valeurs reussi." << std::endl;
    effacer_toute_la_liste(ma_liste); // Nettoyage
}

void test_retirer_valeurs() {
    std::cout << "
--- Test de retirer valeurs ---" << std::endl;
    ListeChainee ma_liste = creer_liste_vide();
    ajouter_valeur_debut(ma_liste, 10);
    ajouter_valeur_fin(ma_liste, 30);
    ajouter_valeur_index(ma_liste, 20, 1); // Liste: [10, 20, 30]
    afficher_liste(ma_liste);
    assert(ma_liste.compte == 3);

    assert(retirer_valeur_debut(ma_liste) == 10);
    afficher_liste(ma_liste); // Devrait afficher [20, 30]
    assert(ma_liste.compte == 2);
    assert(regarder_valeur_debut(ma_liste) == 20);

    assert(retirer_valeur_fin(ma_liste) == 30);
    afficher_liste(ma_liste); // Devrait afficher [20]
    assert(ma_liste.compte == 1);
    assert(regarder_valeur_fin(ma_liste) == 20);

    assert(retirer_valeur_index(ma_liste, 0) == 20);
    afficher_liste(ma_liste); // Devrait afficher []
    assert(ma_liste.compte == 0);

    try {
        retirer_valeur_debut(ma_liste); // Liste vide
        assert(false && "Devrait lancer une exception pour liste vide");
    } catch (const std::runtime_error& e) {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }

    ajouter_valeur_debut(ma_liste, 100); // Liste: [100]
    try {
        retirer_valeur_index(ma_liste, 1); // Index hors limites
        assert(false && "Devrait lancer une exception pour index hors limites");
    } catch (const std::out_of_range& e) {
        std::cout << "Exception attendue: " << e.what() << std::endl;
    }
    effacer_toute_la_liste(ma_liste); // Nettoyage
    
    std::cout << "Test de retirer valeurs reussi." << std::endl;
}

void test_to_array() {
    std::cout << "
--- Test de to_array ---" << std::endl;
    ListeChainee ma_liste = creer_liste_vide();
    ajouter_valeur_debut(ma_liste, 1);
    ajouter_valeur_fin(ma_liste, 2);
    ajouter_valeur_fin(ma_liste, 3); // Liste: [1, 2, 3]

    std::vector<int> arr = to_array(ma_liste);
    assert(arr.size() == 3);
    assert(arr[0] == 1);
    assert(arr[1] == 2);
    assert(arr[2] == 3);

    effacer_toute_la_liste(ma_liste);
    arr = to_array(ma_liste);
    assert(arr.empty());

    std::cout << "Test de to_array reussi." << std::endl;
}

void test_effacer_toute_la_liste() {
    std::cout << "
--- Test d'effacer_toute_la_liste ---" << std::endl;
    ListeChainee ma_liste = creer_liste_vide();
    ajouter_valeur_debut(ma_liste, 1);
    ajouter_valeur_fin(ma_liste, 2);
    ajouter_valeur_fin(ma_liste, 3);
    assert(ma_liste.compte == 3);
    afficher_liste(ma_liste); // Devrait afficher [1, 2, 3]

    effacer_toute_la_liste(ma_liste);
    assert(ma_liste.compte == 0);
    assert(ma_liste.tete == nullptr);
    afficher_liste(ma_liste); // Devrait afficher []

    // Assurer que l'effacement d'une liste vide ne cause pas de problème
    effacer_toute_la_liste(ma_liste);
    assert(ma_liste.compte == 0);
    assert(ma_liste.tete == nullptr);
    
    std::cout << "Test d'effacer_toute_la_liste reussi." << std::endl;
}


int main() {
    std::cout << "Demarrage des tests de la Liste Chainee" << std::endl;

    test_creation_et_ajout();
    test_regarder_valeurs();
    test_retirer_valeurs();
    test_to_array();
    test_effacer_toute_la_liste();

    std::cout << "
Tous les tests de la Liste Chainee termines avec succes !" << std::endl;

    return 0;
}
