#include "WorldGrid.h"

//Constructor
WorldGrid::WorldGrid(int rows, int columns) : 
	mapRows(rows), 
	mapColumns(columns), 
	mapMatrix(new char*[rows]),
	enemyID('T'),
	goalId('X')
{
	for(int i = 0; i < mapRows; i++)
		mapMatrix[i] = new char[mapColumns];

	for(int i = 0; i < mapRows; i++)
		for(int j = 0; j < mapColumns; j++){
			mapMatrix[i][j] = '.';
		}
}

//Copy constructor
WorldGrid::WorldGrid(const WorldGrid& gMap) : 
	mapRows(gMap.mapRows),
	mapColumns(gMap.mapColumns), 
	mapMatrix(new char*[mapRows]),
	enemyID(gMap.enemyID),
	goalId(gMap.goalId)
{
	for(int i = 0; i < mapRows; i++)
		mapMatrix[i] = new char[mapColumns];

	for(int i = 0; i < mapRows; i++)
		for(int j = 0; j < mapColumns; j++){
			mapMatrix[i][j] = gMap.mapMatrix[i][j];
		}
}

//Destructor
WorldGrid::~WorldGrid(){
	for(int i = 0; i < mapRows; i++)
		delete [] mapMatrix[i];
}

//Overloaded assignment operator
WorldGrid& WorldGrid::operator=(const WorldGrid& gMap){
	if(this == &gMap) return *this;
	for(int i = 0; i < mapRows; i++)
		delete [] mapMatrix[i];
	mapRows = gMap.mapRows;
	mapColumns = gMap.mapColumns;
	mapMatrix = new char*[mapRows];
	for(int i = 0; i < mapRows; i++)
		mapMatrix[i] = new char[mapColumns];

	for(int i = 0; i < mapRows; i++)
		for(int j = 0; j < mapColumns; j++){
			mapMatrix[i][j] = gMap.mapMatrix[i][j];
		}
	return *this;
} 

//Returns rows
int WorldGrid::getRows(){
	return mapRows;
}

//Returns columns
int WorldGrid::getColumns(){
	return mapColumns;
}

//Prints the map to std output
void WorldGrid::viewMap(){
	for(int i = 0; i < mapRows; i++){
		for(int j = 0; j < mapColumns; j++){
			std::cout << mapMatrix[i][j];
		}
		std::cout << std::endl;
	}
}

//Updates where everything is on the map !!Awaiting further functionality!!
void WorldGrid::updateMap(int* location, char id){
	for(int i = 0; i < mapRows; i++)
		for(int j = 0; j < mapColumns; j++){
			if(mapMatrix[i][j] == id)
				mapMatrix[i][j] = '.';
		}

	mapMatrix[location[0]][location[1]] = id;
}

//Places everything into the map in its proper place making sure the player and goal are not 
//overwritten. Needs more protections though as there is still the possibility of having no goal.
// add functionality to this late like randomized enemy placement...
void WorldGrid::populateMap(char id, int* location, int enemyCount, int** enemyPlace, int* goalPlace){
	for(int i = 0; i < mapRows; i++){
		for(int j = 0; j < mapColumns; j++){
			if(i == location[0] && j == location[1])
				mapMatrix[i][j] = id;
			if(i == goalPlace[0] && j == goalPlace[1] && mapMatrix[i][j] != id)
				mapMatrix[i][j] = goalId;
			for(int k = 0; k < enemyCount; k++){
				if(i == enemyPlace[k][0] && j == enemyPlace[k][1] && mapMatrix[i][j] != id && mapMatrix[i][j] != goalId)
				{	mapMatrix[i][j] = enemyID; std::cout << "here" << std::endl;}
			}
		}
	}
}