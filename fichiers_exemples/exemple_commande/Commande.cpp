#include "Commande.hpp"
#include <iostream>

// --- Implémentation de la classe Commande ---

Commande::Commande(int id)
    : id_commande_(id) {
    // Le constructeur initialise les valeurs par défaut.
    // L'utilisation de la liste d'initialisation est une bonne pratique.
}

void Commande::ajouter_article(const Article& article) {
    if (articles_.size() < MAX_ARTICLES) {
        articles_.push_back(article);
    }
}

bool Commande::est_valide() const {
    // Une commande est valide si elle a un ID positif et n'est pas vide.
    return id_commande_ > 0 && !articles_.empty();
}

bool Commande::a_du_stock() const {
    // Vérifie si tous les articles de la commande sont en stock.
    for (const auto& article : articles_) {
        if (article.quantite_en_stock <= 0) {
            return false; // Au moins un article est en rupture de stock
        }
    }
    return true; // Tous les articles sont disponibles
}

void Commande::traiter_commande(const ServiceConnexion& connexion) {
    std::cout << "--- Traitement de la commande " << id_commande_ << " ---" << std::endl;

    // Garde 1 : Validation de la commande elle-même
    if (!est_valide()) {
        log_erreur("Commande invalide ou vide.");
        return; // Retour anticipé
    }

    // Garde 2 : Validation de la connexion
    if (!connexion.est_active()) {
        log_erreur("Le service de connexion est inactif.");
        return; // Retour anticipé
    }

    // Garde 3 : Validation du stock
    if (!a_du_stock()) {
        log_erreur("Un ou plusieurs articles sont en rupture de stock.");
        return; // Retour anticipé
    }

    // "Happy Path" : toutes les vérifications ont réussi.
    // L'indentation est minimale.
    envoyer_commande();

    std::cout << std::endl;
}

// Méthodes privées

void Commande::envoyer_commande() const {
    std::cout << "SUCCES : La commande " << id_commande_ << " a ete envoyee avec succes." << std::endl;
}

void Commande::log_erreur(const std::string& message) const {
    std::cout << "ERREUR (Cmd " << id_commande_ << "): " << message << std::endl;
}