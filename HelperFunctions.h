#include "Game.h"
#include <fstream>
queue<char> read(string& name);
int getXroom(queue <char> str);
int getYroom(queue<char> str);
char** toMatrix(queue<char>& str,char** matrix);
void printMatrix(char** matrix, int Xroom, int Yroom);
void addConnections(Game& myGame, int Xroom, int Yroom, char** matrix);
vector<int> getPositions(char** matrix, int Xroom, int Yroom);