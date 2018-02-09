#include <iostream>

class WorldGrid{

public:
	WorldGrid(int, int);
	WorldGrid(const WorldGrid&);
	~WorldGrid();
	WorldGrid& operator=(const WorldGrid&);
	int getRows();
	int getColumns();
	void viewMap();
	void updateMap(int*, char);
	void populateMap(char, int*, int, int**, int*);
private:
	int mapRows;
	int mapColumns;
	char** mapMatrix;
	char enemyID;
	char goalId;
};