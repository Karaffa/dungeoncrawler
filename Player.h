#include <iostream>
#include <string>

class Player{

public:
	Player(int, int*);
	Player(const Player&);
	~Player();
	Player& operator=(const Player&);
	int* getLocation();
	int getHealth();
	bool getWinflag();
	int* movePlayer(std::string&, int, int);
	char getID();
	void setWinflag();
	void setHealth();
	void checkLocation(int, int**, int*);
private:
	char playerId;
	int playerHealth;
	int* playerLocation;
	bool winFlag;
};