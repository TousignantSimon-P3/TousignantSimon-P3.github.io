/**
 * @file main.cpp
 * @brief Fichier d'exemple pour démontrer les différentes manières de passer la taille
 *        d'un tableau à une fonction en C++, en soulignant les avantages et les risques
 *        de chaque approche.
 */

#include <iostream>
#include <iterator> // Pour std::ssize
#include <cstddef>  // Pour std::ptrdiff_t

/**
 * @brief Affiche la moyenne des notes. Utilise 'long long' pour la taille.
 * @param notes Le tableau de notes.
 * @param taille La taille du tableau.
 * @note L'utilisation de `long long` est un choix simple et sûr sur la plupart des 
 *       systèmes 64-bit, car il est garanti d'être assez grand. Cependant, le type
 *       du compteur de boucle `i` (int) est différent de `taille`, ce qui pourrait
 *       générer des avertissements de compilation.
 */
void afficher_moyenne(const int notes[], long long taille) {
    // Une "sanity check" est toujours une bonne idée pour éviter les divisions par zéro.
    if (taille <= 0) return;

    double somme {0.0};
    for (int i {0}; i < taille; ++i) { 
        somme += notes[i];
    }
    std::cout << "[long long] La moyenne est : " << somme / taille << std::endl;
}

/**
 * @brief Affiche la moyenne des notes. Utilise 'int' pour la taille.
 * @param notes Le tableau de notes.
 * @param taille La taille du tableau.
 * @note Cette version est **risquée**. Un `int` est souvent sur 32 bits et pourrait être
 *       trop petit pour contenir la taille d'un très grand tableau sur un système 64-bit,
 *       menant à des bogues de dépassement de capacité (overflow).
 */
void afficher_moyenne_risque(const int notes[], int taille) {
    std::cout << "[int] Appel a la fonction risquee..." << std::endl;
    // ... implémentation similaire ...
}

/**
 * @brief Affiche la moyenne des notes. Utilise 'std::ptrdiff_t' pour la taille.
 * @param notes Le tableau de notes.
 * @param taille La taille du tableau.
 * @note Cette version est la plus **techniquement correcte et portable**. `std::ptrdiff_t` est le 
 *       type signé que `std::ssize` retourne. Il est garanti d'être assez grand
 *       pour représenter la taille d'un tableau sur n'importe quelle plateforme.
 */
void afficher_moyenne_semi_pro(const int notes[], std::ptrdiff_t taille) {
    std::cout << "[ptrdiff_t] Appel a la fonction semi-pro..." << std::endl;
    // ... implémentation similaire ...
}

/**
 * @brief Affiche la moyenne en utilisant un template de fonction (C++20).
 * @param notes Le tableau de notes.
 * @param taille La taille du tableau, dont le type est déduit par le compilateur.
 * @note L'utilisation de `auto` dans un paramètre de fonction est une fonctionnalité C++20
 *       qui crée un "template de fonction abrégé". C'est très flexible, mais moins
 *       explicite que les autres méthodes.
 */
void afficher_moyenne_moderne(const int notes[], auto taille)
{
    std::cout << "[auto] Appel a la fonction moderne qui redirige vers la version 'long long'." << std::endl;
    // Cette fonction agit comme un simple passe-plat vers une version spécifique.
    afficher_moyenne(notes, taille);
}

int main() {
    // Initialisation des tableaux de notes avec la syntaxe moderne {}.
    int notes_cours_1[] {80, 85, 90};
    int notes_cours_2[] {75, 82, 68, 91, 88};

    // On utilise std::ssize (C++20) pour obtenir la taille de manière sûre.
    // std::ssize retourne un type signé (std::ptrdiff_t).
    
    std::cout << "--- Affichage des moyennes ---" << std::endl;

    // Appel à la version `long long`. C'est un bon compromis entre simplicité et sécurité.
    afficher_moyenne(notes_cours_1, std::ssize(notes_cours_1));
    afficher_moyenne(notes_cours_2, std::ssize(notes_cours_2));

    std::cout << std::endl;

    // Appel à la version C++20 avec `auto`. Le type de `taille` sera déduit 
    // par le compilateur comme étant `std::ptrdiff_t` (le type de retour de std::ssize).
    afficher_moyenne_moderne(notes_cours_1, std::ssize(notes_cours_1));
    
    return 0;
}