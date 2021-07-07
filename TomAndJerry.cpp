#pragma once
#include "Game.h"
#include "HelperFunctions.h"
using namespace std;
int main()
{
	string name = "text.txt";
	queue<char> myInfo = read(name);

	int Xroom = getXroom(myInfo);
	int Yroom = getYroom(myInfo);	
	//////////////////
	char** matrix = new char* [Xroom];
	for (int i = 0; i < Xroom; i++) //създаваме матрица за стаята 
	{
		matrix[i] = new char[Yroom];
	}
	for (int i = 0; i < Xroom; i++) //пълним я с дефолтни стоности
	{
		for (int j = 0; j < Yroom; j++)
		{
			matrix[i][j] = '0';
		}
	}
	//////////////////
	toMatrix(myInfo, matrix);
	//printMatrix(matrix,Xroom,Yroom);
	vector<int> positions = getPositions(matrix,Xroom,Yroom);
	vector<int> paint;
	for (int i = 0; i < positions.size()-2; i++)
	{
		paint.push_back(positions[i]);
	}

	int Tom = positions[positions.size() - 2];
	int Jerry= positions[positions.size() - 1];


	Game myGame((Xroom * Yroom) + 1);
	addConnections(myGame, Xroom, Yroom, matrix);
	vector<vector<int> > sol;
	vector<vector<int>> edges = myGame.getAdj();
	myGame.findpaths(edges, Tom, Jerry, Xroom * Yroom, sol);

	
	
		
	cout << "Hello, there! This is the Tom&Jerry game!" << endl;
	cout << "The cartoon characters Tom and Jerry are good friends and that's why they often play tricks on each other." << endl;
	cout << "You play the role of Tom and you have a drone so as to play your tricks and spill paint on the floor!" << endl;
	cout << "You have some information in a file so as to know where is Jerry and the obstacles you have on your way to him." << endl;
	cout << "You can chose from these commands:" << endl;
	cout << endl;
	cout << "1. Length of the shortest path to Jerry - this shows you the length of shortest path from you to Jerry" << endl;
	cout << "2. All shortest paths to Jerry - this shows you the commands that you have to enter in your drone so as to reach Jerry" << endl;
	cout << "3. Paint on each path - this shows you how paint you will spill on each path" << endl;
	cout << "4. Turns on each path - this shows you how turns you drone has to make so as to reach Jerry" << endl;
	cout << "5. Commands to enter - this shows you what commands you have to enter so as to make your drone reach Jerry" << endl;
	cout << "6. Max paint and min turns - this shows you the command you have to enter so as to spill maximum paint and make as few as possible turns" << endl;
	cout << "7. Visualise all paths - this shows you the maps of all paths including numbers of turns, amount of spilt paint, length of the path and the command the drone has to make" << endl;
	cout << "8. Use the drone of Mr Djinks" << endl;
	cout << "9. End of the game - this allows you to exit the game" << endl;
	cout << endl;
	int command;
	cout << "Let me show you the map of the room." << endl << "- J - stands for Jerry" << endl << "- T - stands for Tom" << endl << "- X - stands for furniture" << endl << "- P - stands for you can spill paint" << endl << "- 0 - stands for you can pass through this place" << endl;
	printMatrix(matrix, Xroom, Yroom);
	for (int i = 0; i < Xroom; i++)
	{
		delete matrix[i];

	}
	delete[] matrix;
	
	while (1) {
		cout << "Enter you command:" << endl;
		cin >> command;
		if (command == 1) {
			cout << "Shortest path to Jerry is with length: " << myGame.getShortestPath(sol) << endl;

		}
		else if (command == 2) {
			cout << "All shortest paths to Jerry" << endl;
			vector<vector<int>> shortestPaths = myGame.allShortestPath(sol);
			for (int i = 0; i < shortestPaths.size(); i++)
			{
				cout << "Command you have to enter: ";
				cout << myGame.FromNumbersToDirections(shortestPaths[i], paint,Xroom,Yroom);
				cout << ". Length of the path: " << shortestPaths[i].size() - 1 << endl;
			}
		}
		else if (command == 3) {
			cout << "Amount of paint you wiil spill on each path" << endl;
			myGame.paint(sol, paint, Xroom, Yroom);

		}
		else if (command == 4) {
			cout << "Number of turns the drone has to make on each path:" << endl;
			for (int i = 0; i < sol.size(); i++)
			{
				myGame.print(sol[i], paint,Xroom,Yroom);
				cout << ' ';
				cout << myGame.numberOfTurns(sol[i], paint,Xroom,Yroom) << endl;
			}
		}
		else if (command == 5) {
			cout << "Commands to enter to your drone:" << endl;
			for (int i = 0; i < sol.size(); i++)
			{
				myGame.representPath(sol[i], Xroom, Yroom);
				cout << endl<<myGame.FromNumbersToDirections(sol[i], paint, Xroom, Yroom)<<endl;
			}

		}
		else if (command == 6) {
			
			myGame.maxPaint(sol, paint, Xroom, Yroom);
			cout << endl;

		}
		else if (command == 7) {
			myGame.visualise(sol,paint, Xroom, Yroom);
			int path;
			

			while (1) {
				cout << "Choose a path:";
				cin >> path;
				if (path < 0 || path > sol.size())
				{
					cout << "There is no such path!" << endl;					
				}
				else {
					myGame.representPath(sol[path - 1],Xroom,Yroom);
					cout << "The entered commands are: " << myGame.FromNumbersToDirections(sol[path - 1], paint, Xroom, Yroom) << endl;
					cout << "You reached Jerry and spilt " << myGame.numberOfPaint(sol[path - 1], paint)<< " paint on the floor!"<< endl;
					break;
				}
			}
		}
		else if (command == 8) {
			cout << "You are using two drones to reach Jerry! Here are your commands so as to go to Jerry as fast as possible and spill as much as possible paint: " << endl;
			myGame.withAnotherDrone(sol, paint, Xroom, Yroom);
			
		}
		else if (command == 9) {
			return 0;
		}

		else{
			cout << "Invalid command!" << endl;
		}

	}


	




}

