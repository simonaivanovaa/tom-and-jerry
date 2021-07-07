#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
class Game
{
private:
	int conditions;
	vector<vector<int>> connections;
	
public:
	Game(int conditions);
	void addConnection(int v, int w);
	vector<vector<int>> getAdj();
	
	bool isNotVisited(int x, vector<int>& path);
	void allpath(vector<vector<int>>& allpaths, vector<int>& path);
	void findpaths(vector<vector<int> >& g, int start, int end, int v, vector<vector<int>>& solutions);

	int getShortestPath(vector<vector<int>>& paths);
	vector<vector<int>> allShortestPath(vector<vector<int>>& paths);
	void paint(vector<vector<int>>& paths, vector<int>& paints,int Xroom, int Yroom);
	int numberOfTurns(vector<int>& path, vector<int>& paint, int Xroom, int Yroom);
	int numberOfPaint(vector<int>& paths, vector<int>& paints);
	
	vector<int>fromMatrix(int number, int Xroom, int Yroom);
	string FromNumbersToDirections(vector<int>& path, vector<int>& paint, int Xroom, int Yroom);
	void visualise(vector <vector<int>>& paths, vector<int>& paints,int x, int y);
	void representPath(vector<int>& path, int x, int y);
	
	void maxPaint(vector <vector<int>>& paths, vector<int>& paint,int x,int y);
	void withAnotherDrone(vector<vector<int>>& paths, vector<int>& paint,int Xroom, int Yroom);

	void allPrintPaths(vector<vector<int>>& paths);
	void print(vector<int>& path, vector<int>& paint, int Xroom, int Yroom);
	void print(vector<int>& path);
	void printMyGame();

};