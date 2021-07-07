#include "HelperFunctions.h"
queue<char> read(string& name) { // четене от файл и бутане в опашка
	string myString;
	ifstream myFile(name);
	if (myFile.is_open())
	{
		while (myFile.good())
		{
			string newString;
			getline(myFile, newString);
			myString.append(newString);
			myString.append("/");
		}

		myFile.close();
	}
	queue<char> myQueue;
	for (int i = 0; i < myString.size() - 1; i++)
	{

		myQueue.push(myString[i]);
	}
	return myQueue;

}
int getXroom(queue <char> str) {
	int Xroom = 0;
	int count = 1;
	while (str.front() != ' ') {//взимаме Х на стаята

		Xroom *= count;
		Xroom = Xroom + (str.front() - '0');
		count *= 10;
		str.pop();
	}
	return Xroom;
}
int getYroom(queue<char> str) {
	int Yroom = 0;
	int count = 1;
	while (str.front() != ' ') {//взимаме Х на стаята

		str.pop();
	}
	str.pop();
	while (str.front() != '/') { //взимаме У на стаята

		Yroom *= count;
		Yroom = Yroom + (str.front() - '0');
		count *= 10;
		str.pop();
	}
	return Yroom;
}
char** toMatrix(queue<char>& str,char** matrix) {

	int Xroom = 0;
	int count = 1;
	while (str.front() != ' ') {//взимаме Х на стаята

		Xroom *= count;
		Xroom = Xroom + (str.front() - '0');
		count *= 10;
		str.pop();
	}
	count = 1;
	str.pop();
	int Yroom = 0;
	while (str.front() != '/') { //взимаме У на стаята

		Yroom *= count;
		Yroom = Yroom + (str.front() - '0');
		count *= 10;
		str.pop();
	}
	count = 1;
	str.pop();
	
	int xJerry = 0;
	while (str.front() != ' ') { // взимаме координати на Джери

		xJerry *= count;
		xJerry = xJerry + (str.front() - '0');
		count *= 10;
		str.pop();
	}
	count = 1;
	str.pop();
	int yJerry = 0;
	while (str.front() != '/') {

		yJerry *= count;
		yJerry = yJerry + (str.front() - '0');
		count *= 10;
		str.pop();
	}
	count = 1;
	str.pop();
	matrix[xJerry][yJerry] = 'J';
	//////////////////
	int xTom = 0;
	while (str.front() != ' ') { //взимаме координати на Том

		xTom *= count;
		xTom = xTom + (str.front() - '0');
		count *= 10;
		str.pop();
	}
	count = 1;
	str.pop();
	int yTom = 0;
	while (str.front() != '/') {

		yTom *= count;
		yTom = yTom + (str.front() - '0');
		count *= 10;
		str.pop();
	}
	count = 1;
	str.pop();
	matrix[xTom][yTom] = 'T';
	//////////////////
	int numberOfFurniture = 0;
	while (str.front() != ' ') { //взимаме колко мебели има

		numberOfFurniture *= count;
		numberOfFurniture = numberOfFurniture + (str.front() - '0');
		count *= 10;
		str.pop();
	}
	count = 1;
	str.pop();
	//////////////////
	int numberOfPaint = 0;
	while (str.front() != '/') { //взимаме колко боя може да разлеем

		numberOfPaint *= count;
		numberOfPaint = numberOfPaint + (str.front() - '0');
		count *= 10;
		str.pop();
	}
	count = 1;
	str.pop();
	////////////////// слагаме мебелите в стаята
	for (int i = 0; i < numberOfFurniture; i++)
	{
		int x = 0;
		while (str.front() != ' ') {

			x *= count;
			x = x + (str.front() - '0');
			count *= 10;
			str.pop();
		}
		count = 1;
		str.pop();
		int y = 0;
		while (str.front() != '/') {

			y *= count;
			y = y + (str.front() - '0');
			count *= 10;
			str.pop();
		}
		count = 1;
		str.pop();
		int count = x;
		int count2 = y;
		while (str.front() != '=') {
			if (str.front() == '1') {
				matrix[count][count2] = 'X';
				count2++;
				str.pop();
			}
			else if (str.front() == ' ') {
				count2++;
				str.pop();
			}
			else if (str.front() == '/') {
				count = x + 1;
				count2 = y;
				str.pop();
			}
		}
		str.pop();
		str.pop();
		str.pop();
		str.pop();

	}
	////////////////// слагаме местата с боя
	for (int i = 0; i < numberOfPaint; i++)
	{
		int x = 0;
		while (str.front() != ' ') {

			x *= count;
			x = x + (str.front() - '0');
			count *= 10;
			str.pop();
		}
		count = 1;
		str.pop();
		int y = 0;
		while (str.front() != '/') {

			y *= count;
			y = y + (str.front() - '0');
			count *= 10;
			str.pop();
		}
		count = 1;
		str.pop();
		matrix[x][y] = 'P';

	}
	return matrix;
}
//char** matrixNumbers(int Xroom, int Yroom) {
//	char** matrix = new char* [Xroom];
//	for (int i = 0; i < Xroom; i++)
//	{
//		matrix[i] = new char[Yroom];
//	}
//	int count = 1;
//	for (int i = 0; i < Xroom; i++)
//	{
//		for (int j = 0; j < Yroom; j++)
//		{
//
//			matrix[i][j] = count;
//			count++;
//		}
//	}
//	return matrix;
//}
void printMatrix(char** matrix, int Xroom, int Yroom) {
	for (int i = 0; i < Xroom; i++)
	{
		for (int j = 0; j < Yroom; j++) {

			cout << matrix[i][j];
		}
		cout << endl;
	}
}
void addConnections(Game& myGame, int Xroom, int Yroom, char** matrix) {
	char** matrix2 = new char* [Xroom];
	for (int i = 0; i < Xroom; i++)
	{
		matrix2[i] = new char[Yroom];
	}
	int count = 1;
	for (int i = 0; i < Xroom; i++)
	{
		for (int j = 0; j < Yroom; j++)
		{

			matrix2[i][j] = count;
			count++;
		}
	}
	
	for (int i = 0; i < Xroom; i++)
	{
		for (int j = 0; j < Yroom; j++)
		{
			if (i == 0) {
				if (j == 0) {
					if (matrix[i][j] != 'X') {
						if (matrix[i + 1][j] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i + 1][j]);
						}

						if (matrix[i][j + 1] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i][j + 1]);
						}
					}
				}
				else if (j == Yroom - 1) {
					if (matrix[i][j] != 'X') {

						if (matrix[i + 1][j] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i + 1][j]);
						}

						if (matrix[i][j - 1] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i][j - 1]);
						}
					}


				}
				else {
					if (matrix[i][j] != 'X') {
						if (matrix[i + 1][j] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i + 1][j]);
						}

						if (matrix[i][j - 1] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i][j - 1]);
						}

						if (matrix[i][j + 1] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i][j + 1]);
						}

					}
				}
			}
			else if (i == Xroom - 1) {
				if (j == 0) {
					if (matrix[i][j] != 'X') {
						if (matrix[i - 1][j] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i - 1][j]);
						}

						if (matrix[i][j + 1] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i][j + 1]);
						}

					}
				}
				else if (j == Yroom - 1) {
					if (matrix[i][j] != 'X') {
						if (matrix[i - 1][j] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i - 1][j]);
						}

						if (matrix[i][j - 1] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i][j - 1]);
						}

					}
				}
				else {
					if (matrix[i][j] != 'X') {
						if (matrix[i - 1][j] != 'X')
							myGame.addConnection(matrix2[i][j], matrix2[i - 1][j]);

						if (matrix[i][j - 1] != 'X')
							myGame.addConnection(matrix2[i][j], matrix2[i][j - 1]);

						if (matrix[i][j + 1] != 'X')
							myGame.addConnection(matrix2[i][j], matrix2[i][j + 1]);

					}
				}
			}
			else {
				if (matrix[i][j] != 'X') {
					if (j == 0) {
						if (matrix[i - 1][j] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i - 1][j]);
						}

						if (i < Xroom - 1 && matrix[i + 1][j] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i + 1][j]);
						}

						if (j < Yroom - 1 && matrix[i][j + 1] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i][j + 1]);
						}
					}
					else if (j == Yroom - 1) {
						if (matrix[i - 1][j] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i - 1][j]);
						}

						if (matrix[i + 1][j] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i + 1][j]);
						}

						if (matrix[i][j - 1] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i][j + 1]);
						}

					}
					else {
						if (matrix[i - 1][j] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i - 1][j]);
						}

						if (i < Xroom - 1 && matrix[i + 1][j] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i + 1][j]);
						}

						if (matrix[i][j + 1] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i][j + 1]);
						}

						if (matrix[i][j - 1] != 'X') {
							myGame.addConnection(matrix2[i][j], matrix2[i][j - 1]);
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < Xroom; i++)
	{
		delete matrix2[i];

	}
	delete[] matrix2;
}
vector<int> getPositions(char** matrix, int Xroom, int Yroom) {
	int Tom;
	int Jerry;
	vector<int> positions;

	char** matrix2 = new char* [Xroom];
	for (int i = 0; i < Xroom; i++)
	{
		matrix2[i] = new char[Yroom];
	}
	int count = 1;
	for (int i = 0; i < Xroom; i++)
	{
		for (int j = 0; j < Yroom; j++)
		{

			matrix2[i][j] = count;
			count++;
		}
	}
	for (int i = 0; i < Xroom; i++)
	{
		for (int j = 0; j < Yroom; j++)
		{
			if (matrix[i][j] == 'T') {
				Tom = matrix2[i][j];
			}
			if (matrix[i][j] == 'J') {
				Jerry = matrix2[i][j];
			}
			if (matrix[i][j] == 'P') {
				positions.push_back(matrix2[i][j]);
			}
		}
	}

	for (int i = 0; i < Xroom; i++)
	{
		delete matrix2[i];

	}
	delete[] matrix2;
	positions.push_back(Tom);
	positions.push_back(Jerry);
	return positions;


}