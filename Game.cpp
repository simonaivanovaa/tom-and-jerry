#include "Game.h"

Game::Game(int conditions) : connections(conditions)
{
    this->conditions = conditions;

}
void Game::addConnection(int v, int w)
{
    connections[v].push_back(w);
}
void Game:: allpath(vector<vector<int>>& allpaths, vector<int>& path)
{
	allpaths.push_back(path);
}
bool Game:: isNotVisited(int x, vector<int>& path)
{
	int size = path.size();
	for (int i = 0; i < size; i++)
		if (path[i] == x)
			return 0;
	return 1;
}
void Game:: findpaths(vector<vector<int> >& g, int start,int end, int v, vector<vector<int>>& solutions)
{
	
	queue<vector<int> > q;
	vector<int> path;
	path.push_back(start);
	q.push(path);
	while (!q.empty()) {
		path = q.front();
		q.pop();
		int last = path[path.size() - 1];

		if (last == end)
			allpath(solutions, path);

		for (int i = 0; i < g[last].size(); i++) {
			if (isNotVisited(g[last][i], path)) {
				vector<int> newpath(path);
				newpath.push_back(g[last][i]);
				q.push(newpath);
			}
		}
	}
}
int Game::getShortestPath(vector<vector<int>>& paths) {

	int minDist = paths[0].size();
	for (int i = 1; i < paths.size(); i++)
	{
		for (int j = 0; j < paths[i].size(); j++)
		{
			if (paths[i].size() < minDist)
				minDist = paths[i].size();
		}
	}
	return minDist-1;

}
void Game::print(vector<int>& path)
{
	for (int i = 0; i < path.size(); i++)
	{
		cout << path[i];
	}
}
void Game:: print(vector<int>& path, vector<int>& paint, int Xroom, int Yroom)
{
	cout<< FromNumbersToDirections(path, paint, Xroom, Yroom);
}
vector<int> Game::fromMatrix(int number, int Xroom, int Yroom) {
	vector<int> toreturn;
	
	int** matrix2 = new int* [Xroom];
	for (int i = 0; i < Xroom; i++)
	{
		matrix2[i] = new int[Yroom];
	}
	int count2 = 1;
	for (int i = 0; i < Xroom; i++)
	{
		for (int j = 0; j < Yroom; j++)
		{

			matrix2[i][j] = count2;
			count2++;
		}
	}
	for (int i = 0; i < Xroom; i++)
	{
		for (int j = 0; j < Yroom; j++)
		{
			if (matrix2[i][j] == number) {

				toreturn.push_back(i);
				toreturn.push_back(j);
				break;
			}

		}
	}
	for (int i = 0; i < Xroom; i++)
	{
		delete matrix2[i];

	}
	delete[] matrix2;
	return toreturn;
}

string Game::FromNumbersToDirections(vector<int>& path, vector<int>& paint, int Xroom, int Yroom)
{
	string str = "";
	vector<int> first;
	vector<int> second;
	for (int i = 0; i < path.size() - 1; i++)
	{
		first = fromMatrix(path[i],Xroom,Yroom);
		second = fromMatrix(path[i + 1],Xroom, Yroom);
		int x1 = first.at(0);
		int y1 = first.at(1);
		int x2 = second.at(0);
		int y2 = second.at(1);
		for (int z = 0; z < paint.size(); z++) {
			if (paint[z] == path[i]) {
				str.append("P");
			}
		}

		if (x1 > x2 && y1 == y2) {
			str.append("N");
		}
		else if (x1 < x2 && y1 == y2) {
			str.append("S");
		}
		else if (x1 == x2 && y1 > y2) {
			str.append("W");
		}
		else if (x1 == x2 && y1 < y2) {
			str.append("E");
		}
	}

	for (int z = 0; z < paint.size(); z++) {
		if (paint[z] == (path.at(path.size() - 1))) {
			str.append("P");
		}
	}

	return str;

}
vector<vector<int>> Game:: allShortestPath(vector<vector<int>>& paths) {
	vector<vector<int>> wantedPaths;
	int dist = getShortestPath(paths)+1;
	for (int i = 0; i < paths.size(); i++)
	{
		for (int j = 0; j < paths[i].size(); j++)
		{
			if (paths[i].size() == dist) {
				wantedPaths.push_back(paths[i]);
				break;
			}
		}
	}

	return wantedPaths;

}

void Game:: paint(vector<vector<int>>&paths, vector<int>& paints, int Xroom,int Yroom) {
	int count = 0;

	for (int i = 0; i < paths.size(); i++)
	{
		for (int j = 0; j < paths[i].size(); j++)
		{
			for (int s = 0; s < paints.size(); s++)
			{
				if (paths[i][j] == paints[s]) {
					count++;

				}
			}


		}
		print(paths[i], paints, Xroom, Yroom);
		cout << " " << count;
		count = 0;
		cout << endl;
	}
}
vector<vector<int>> Game::getAdj() {
	return connections;
}
void Game::printMyGame() {
	for (int i = 0; i < connections.size(); i++)
	{
		for (int j = 0; j < connections[i].size(); j++) {
			cout << connections[i][j]<<' ';
		}
		cout << endl;
	}
}
int Game::numberOfTurns(vector<int>& path,vector<int>& paint, int Xroom, int Yroom) {
	int count = 0;
	string str = FromNumbersToDirections(path, paint,Xroom,Yroom);
	int len = str.length();
	for (int i = 0; i <len-1; i++)
	{		
		if (str[i] == str[i + 1])
		{
			continue;
		}
		else if (str[i + 1] == 'P') {
			continue;
		}
		else if (str[i] == 'P' && i - 1 >= 0 && i + 1 <= len - 1 && str[i - 1] == str[i + 1])
		{
			continue;
		}
		else {
			count++;
		}
			
	}
	return count;
}
void  Game::representPath(vector<int>& path,int x, int y) {
	char** matrix = new char* [x];
	int count = 1;
	for (int i = 0; i < x; i++)
	{
		matrix[i] = new char[y];
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			matrix[i][j] = '=';
		}
	}
	int** matrix2 = new int* [x];

	for (int i = 0; i < x; i++)
	{
		matrix2[i] = new int[y];
	}

	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			matrix2[i][j] = count;
			count++;
		}
	}
	
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			for (int s = 0; s < path.size(); s++)
			{
				if (s == 0 && path[s] == matrix2[i][j]) {
					matrix[i][j] = 'S';
					continue;;
				}
				else if (s == path.size() - 1 && path[s] == matrix2[i][j]) {
					matrix[i][j] = 'D';
					continue;
				}
				else if (path[s] == matrix2[i][j]) {
					matrix[i][j] = 'X';
					continue;
				}
				
			}
						
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < y; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < x; i++)
	{
		delete matrix2[i];

	}
	delete[] matrix2;


	for (int i = 0; i < x; i++)
	{
		delete matrix[i];

	}
	delete[] matrix;


}
void  Game::visualise(vector <vector<int>>& paths,vector<int>& paints,int x, int y) {
	vector<vector<string>> sol;
	for (int i = 0; i < paths.size(); i++)
	{
		cout << "Path: " << i + 1 << endl;
		representPath(paths[i], x, y);
		cout << "Number of turns: " << numberOfTurns(paths[i], paints,x,y) << endl;
		cout << "Amount of spilt paint:" << numberOfPaint(paths[i], paints) << endl;
		cout << endl;
	}

}
void Game::allPrintPaths(vector<vector<int>>& paths) {
	for (int i = 0; i < paths.size(); i++)
	{
		print(paths[i]);
	}
	
}
int Game::numberOfPaint(vector<int>&paths, vector<int>& paints) {
	int count = 0;

	for (int i = 0; i < paths.size(); i++)
	{
		
		for (int s = 0; s < paints.size(); s++)
		{
			if (paths[i] == paints[s]) {
				count++;

			}
		}		
	}
	return count;
}

void Game::maxPaint(vector <vector<int>>& paths, vector<int>& paint,int x, int y) {
	vector<int> numberPaint;
	vector<int> numberTurns;

	for (int i = 0; i < paths.size(); i++){
		numberPaint.push_back(numberOfPaint(paths[i], paint));
		numberTurns.push_back(numberOfTurns(paths[i], paint,x,y));	
	}
	int max = 0;
	int current = 0;
	for (int i = 0; i < numberPaint.size(); i++)
	{
		if (numberPaint[i] > max) {
			max = numberPaint[i];
			current = i;
		}
		else if (numberPaint[i] == max) {
			if (numberTurns[current] > numberTurns[i]) {
				current = i;
			}
		}
	}
	cout << "This is the path with the maximum paint you can spill in the room and with the smallest number of turns: ";
	cout << FromNumbersToDirections(paths[current], paint,x,y) << endl;
	representPath(paths[current], x, y);
	cout << endl << "The number of turns are: " << numberTurns[current];
	cout << endl << "The amount of spilt paint: " << max;

}
void Game::withAnotherDrone(vector<vector<int>>& paths, vector<int>& paint, int Xroom,int Yroom) {
	vector<vector<int>> sol = allShortestPath(paths);
	if (sol.size() == 2) {
		for (int i = 0; i < 2; i++)
		{
			cout << FromNumbersToDirections(sol[i], paint,Xroom, Yroom) << endl;
		}
	}
	else if(sol.size() > 2) {
		vector<int> maxPaint;
		for (int i = 0; i < sol.size(); i++)
		{
			maxPaint.push_back(numberOfPaint(sol[i], paint));
		}
		int first=0;
		int second=1;
		for (int i = 2; i < maxPaint.size(); i++)
		{
			if (maxPaint[i] >= maxPaint[first]) {
				if (maxPaint[first] >= maxPaint[second]) {
					second = first;
					first = i;
				}
				else {					
					first = second;
					second = i;
				}
			}
			else {
				if (maxPaint[first] >= maxPaint[second]) {
					second = first;
					first = i;
				}
				else {
					first = second;
					second = i;
				}
			}
		}
		print(sol[first], paint, Xroom, Yroom);
		cout << endl;
		print(sol[second],paint, Xroom, Yroom);
		cout << endl;

	}
	else {
		cout << "You cannot use your friend's drone because there is no other path to Jerry!" << endl;
	}


}