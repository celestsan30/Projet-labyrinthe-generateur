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

const int DX[] = {0, 0, -2, 2};
const int DY[] = {-2, 2, 0, 0};

void genererLabyrinthe(vector<vector<char>>& labyrinthe, int departX, int departY) {
    stack<pair<int, int>> pile;
    pile.push({departX, departY});
    labyrinthe[departX][departY] = '.';

    while (!pile.empty()) {
        int x = pile.top().first;
        int y = pile.top().second;
        pile.pop();

        vector<int> directions = {0, 1, 2, 3};
        std::random_device rd;                             // Générateur de graines
        std::mt19937 g(rd());                              // Générateur Mersenne Twister
        std::shuffle(directions.begin(), directions.end(), g);

        for (int i : directions) {
            int nx = x + DX[i];
            int ny = y + DY[i];

            if (dansLesLimites(nx, ny) && labyrinthe[nx][ny] == '#') {
                labyrinthe[x + DX[i] / 2][y + DY[i] / 2] = '.';
                labyrinthe[nx][ny] = '.';
                pile.push({nx, ny});
            }
        }
    }
}
