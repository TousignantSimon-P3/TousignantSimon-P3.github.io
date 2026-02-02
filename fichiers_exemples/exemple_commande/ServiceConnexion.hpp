#pragma once

/**
 * @brief Simule une connexion à un service externe.
 */
class ServiceConnexion {
public:
    /// @brief Vérifie si la connexion au service est active.
    /// @return true si le service est disponible, sinon false.
    bool est_active() const;
};
