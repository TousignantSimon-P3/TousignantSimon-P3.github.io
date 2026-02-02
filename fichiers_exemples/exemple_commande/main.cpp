#include <iostream>
#include "Commande.hpp"

/**
 * @brief Programme principal qui démontre l'utilisation de la classe Commande.
 */
int main() {
    // Initialisation des services et des données d'exemple avec la syntaxe {}
    ServiceConnexion service_connexion {};
    Article article_disponible {"Stylo", 10};
    Article article_indisponible {"Cahier", 0};

    std::cout << "--- Debut des tests de scenarios ---\n" << std::endl;

    // --- Scénario 1 : Commande valide ---
    Commande cmd_valide {101};
    cmd_valide.ajouter_article(article_disponible);
    cmd_valide.traiter_commande(service_connexion);

    // --- Scénario 2 : Article en rupture de stock ---
    Commande cmd_stock_epuise {102};
    cmd_stock_epuise.ajouter_article(article_disponible);
    cmd_stock_epuise.ajouter_article(article_indisponible);
    cmd_stock_epuise.traiter_commande(service_connexion);

    // --- Scénario 3 : Commande invalide (vide)
    Commande cmd_vide {103};
    cmd_vide.traiter_commande(service_connexion);

    // --- Scénario 4 : Commande avec ID invalide ---
    // Note : l'initialisation avec {} ne prévient pas les valeurs logiquement invalides comme -1.
    Commande cmd_id_invalide {-1}; 
    cmd_id_invalide.ajouter_article(article_disponible);
    cmd_id_invalide.traiter_commande(service_connexion);
    
    std::cout << "\n--- Fin des tests ---\n";

    return 0;
}