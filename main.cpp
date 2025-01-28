#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <stack>
#include <random>
#include <algorithm>
#include "genere_avec_DFS.h"
#include "affiche_labyrinthe.h"

using namespace std;


int main() {
    srand(time(0));

    // Crée une grille pleine de murs
    vector<vector<char>> labyrinthe(hauteur, vector<char>(largeur, '#'));

    // Génère le labyrinthe à partir d'un point de départ
    int departX = 1;
    int departY = 1;
    genererLabyrinthe(labyrinthe, departX, departY);

    // Ajoute une entrée et une sortie
    labyrinthe[0][1] = 'E';
    labyrinthe[hauteur - 1][largeur - 2] = 'S';

    // Affiche le labyrinthe avec les couleurs
    affiche_labi(labyrinthe);

    return 0;
}
