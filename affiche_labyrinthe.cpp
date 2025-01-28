#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <stack>
#include <random>
#include <algorithm>

using namespace std;
int largeur =11;
int hauteur =11;

bool dansLesLimites(int x, int y) {
    return x > 0 && x < hauteur - 1  && y > 0 && y < largeur - 1 ;
}


void affiche_labi(const vector<vector<char>>& labyrinthe){

   for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            if (labyrinthe[i][j] == '#') {

                cout << "#";
            } else if (i == 0 && j == 1) {
   
                cout << "E";
            } else if (i == hauteur - 1 && j == largeur - 2) {
               
                cout << "S";
            } else {
               
                cout << ".";
            }
        }
        cout << endl;
    }
   
}