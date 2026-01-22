#pragma once

#include <vector>
#include <string>
#include "Article.hpp"          // Dépendance vers la structure Article
#include "ServiceConnexion.hpp" // Dépendance vers la classe ServiceConnexion

// Constante en SCREAMING_SNAKE
const int MAX_ARTICLES = 100;

/**
 * @brief Représente une commande client et ses informations de validation.
 */
class Commande { // PascalCase
public:
    /// @brief Construit une nouvelle commande avec un identifiant.
    /// @param id L'identifiant numérique unique de la commande.
    explicit Commande(int id);

    /// @brief Ajoute un article à la commande.
    /// @param article L'article à ajouter (passé par référence constante).
    void ajouter_article(const Article& article);

    /// @brief Vérifie si la commande est valide pour être traitée.
    /// @return true si la commande a un ID positif et contient des articles.
    bool est_valide() const;

    /// @brief Vérifie la disponibilité en stock de tous les articles.
    /// @return true si tous les articles sont en stock, sinon false.
    bool a_du_stock() const;

    /// @brief Orchestre le traitement de la commande en appliquant les règles de validation.
    /// @param connexion Le service de connexion à utiliser (référence constante).
    void traiter_commande(const ServiceConnexion& connexion);

private:
    // Attributs en snake_case
    int id_commande_;
    std::vector<Article> articles_;

    // Méthodes privées en snake_case
    void envoyer_commande() const;
    void log_erreur(const std::string& message) const;
};