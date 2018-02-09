#include "Player.h"

//Constructor
Player::Player(int health, int* location) : 
	playerId('P'),
	playerHealth(health),
	playerLocation(new int[2]),
	winFlag(false)
{
	playerLocation[0] = location[0];
	playerLocation[1] = location[1];
}

//Copy Constructor
Player::Player(const Player& p) :
	playerId(p.playerId),
	playerHealth(p.playerHealth),
	playerLocation(new int[2]),
	winFlag(false)
{
	playerLocation[0] = p.playerLocation[0];
	playerLocation[1] = p.playerLocation[1];
}

//Destructor
Player::~Player(){
	delete [] playerLocation;
}

//Overloaded Assignment Operator
Player& Player::operator=(const Player& p){
	if(this == &p) return *this;
	delete [] playerLocation;
	playerLocation = new int[2];
	playerLocation[0] = p.playerLocation[0];
	playerLocation[1] = p.playerLocation[1];
	playerId = p.playerId;
	playerHealth = p.playerHealth;
	winFlag = p.winFlag;

	return *this;
}

//Returns the players current location
int* Player::getLocation(){
	return playerLocation;
}

//Returns the players current health
int Player::getHealth(){
	return playerHealth;
}

//Returns whether the player has won or not
bool Player::getWinflag(){
	return winFlag;
}

//Calculates characters movement and updates the playerlocation array
//Also checks the player for going out of bounds
//Contains unimplemented playerhealth modifiers.
int* Player::movePlayer(std::string& chosenDirection, int Rows, int Columns){
	if(chosenDirection == "left" || chosenDirection == "l" || chosenDirection == "L")
		playerLocation[1]--;
	if(chosenDirection == "right" || chosenDirection == "r" || chosenDirection == "R")
		playerLocation[1]++;
	if(chosenDirection == "up" || chosenDirection == "u" || chosenDirection == "U")
		playerLocation[0]--;
	if(chosenDirection == "down" || chosenDirection == "d" || chosenDirection == "D")
		playerLocation[0]++;

	if(playerLocation[0] < 0 ){
		//playerHealth--;
		playerLocation[0]++;
	}
	if(playerLocation[0] > Rows-1){
		//playerHealth--;
		playerLocation[0]--;
	}
	if(playerLocation[1] < 0){
		//playerHealth--;
		playerLocation[1]++;
	}
	if(playerLocation[1] > Columns-1){
		//playerHealth--;
		playerLocation[1]--;
	}

	return playerLocation;
}

//Returns the player character
char Player::getID(){
	return playerId;
}

//For use if the player wins
void Player::setWinflag(){
	winFlag = true;
}

//Decrements health by one
void Player::setHealth(){
	playerHealth--;
}

//checks the players surroundings for enemies and goals
void Player::checkLocation(int enemyCount, int** enemyPlace, int* goalPlace){
	for(int i = 0; i < enemyCount; i++)
		if(enemyPlace[i][0] == playerLocation[0] && enemyPlace[i][1] == playerLocation[1])
			playerHealth--;
	if(goalPlace[0] == playerLocation[0] && goalPlace[1] == playerLocation[1])
		winFlag = true;
}