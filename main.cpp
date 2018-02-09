#include <iostream>
#include <string>
#include "WorldGrid.h"
#include "Player.h"


int main(){
	
	WorldGrid gameMap(7, 10);
	int initLocation[2] = {1, 1}; //add chosen functionality later?
	Player player1(1, initLocation);
	int enemyCount = 3;// eventually make this users choice
	int** enemyPlace = new int*[enemyCount];
	for(int i = 0 ; i < enemyCount; i++)
		enemyPlace[i] = new int[2];
	
	//this isn't great, going to make the input much better
	for(int i = 0; i < enemyCount; i++)
	{
		std::cout << "Please enter enemy coordinates here:";
		std::cin >> enemyPlace[i][0];
		std::cin >> enemyPlace[i][1];
	}
	
	int goalPlace[2] = {6,9};

	gameMap.populateMap(player1.getID(),player1.getLocation(),3,enemyPlace,goalPlace);

	while(player1.getHealth() > 0 && !player1.getWinflag()){
		gameMap.viewMap();
		std::cout << "Please Enter a Direction:";
		std::string chosenDirection;
		std::cin >> chosenDirection;
		gameMap.updateMap(
			player1.movePlayer(chosenDirection, gameMap.getRows(), gameMap.getColumns()), 
			player1.getID()
		);
		player1.checkLocation(enemyCount, enemyPlace, goalPlace);
	}
	
	if(player1.getWinflag())
		std::cout << "You Win!" << std::endl;
	else
		std::cout << "You Lose :(" << std::endl;

	for(int i = 0; i < enemyCount; i++){
		delete [] enemyPlace[i];
	}

	return 0;
}