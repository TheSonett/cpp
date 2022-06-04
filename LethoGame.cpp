#include <iostream>
#include <ctime>

class Player
{
protected:
	int health = 100;
	int maxDamage = 30, minDamage = 20;
	int maxHealing = 15, minHealing = 8;
public:
	Player() {
		std::cout << "\nHi my name is Letho! We need to save princess and get her back" << std::endl;
		std::cout << "Here are some starts that might be useful for you going ahead" << std::endl;

		std::cout << "\nLetho's health: " << health;
		std::cout << "\n_______________________________________\n";
		std::cout << "\nLetho's Attack Range is between: " << minDamage << "-" << maxDamage << ".";
		std::cout << "\n_______________________________________\n";
		std::cout << "\nLetho's Healing Range is between: " << minHealing << "-" << maxHealing << "." << std::endl;
	}
	virtual ~Player() {}
public:
	int getHealth() {
		return health;
	}

	void takeDamage(const int& damage) {
		// if health is greater than 0, it means our player is alive & 
		// only then I can apply the damage to our player
		std::cout << "\n\nOhh NOO!! a critical hit to player!!" << std::endl;
		std::cout << "Enemy is dealing damage of " << damage << " to the Letho!" << std::endl;
		health -= damage;

		if (health < 0)
		{
			std::cout << "\n\nPlayer died!!!, You lost!!\n" << std::endl;
		}
		else {
			std::cout << "Letho's current health after getting damaged is: " << health << std::endl;
		}
	}

	int giveDamage() {
		srand(time(NULL));
		int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);
		std::cout << "\nPlayer is performing hit of " << randomDamage << " to the enemy." << std::endl;
		return randomDamage;
	}

	void heal() {
		srand(time(NULL));
		int randomHeal = (rand() % (maxHealing - minHealing + 1) + minHealing);

		health += randomHeal;

		std::cout << "\n\nLetho's Healed with HP of " << randomHeal << std::endl;
		std::cout << "Letho's Health after Healing " << health << std::endl;
	}
};

class Enemy : public Player {
private:
	int maxDamage = 30, minDamage = 40;
public:
	Enemy() {
		std::cout << "\n\nHa ha ha, I'm the Lord of Darkness!!" << std::endl;
	}
	~Enemy() {}
public:
	int getHealth() {
		return health;
	}
	void takeDamage(const int& damage) {
		// if health is greater than 0, it means our enemy is alive & 
		// only then I can apply the damage to our enemy
		std::cout << "\n\nYESS!! a critical hit to Enemy!!" << std::endl;
		std::cout << "Player is dealing damage of " << damage << " to the Enemy!" << std::endl;
		health -= damage;

		if (health < 0)
		{
			std::cout << "\n\nEnemy died!!!, You Won!!\n" << std::endl;
		}
		else {
			std::cout << "Enemy's current health after getting damaged is: " << health << std::endl;
		}
	}

	int giveDamage() {
		srand(time(NULL));
		int randomDamage = (rand() % (maxDamage - minDamage + 1) + minDamage);
		std::cout << "\nEnemy is performing hit of " << randomDamage << " to the player." << std::endl;
		return randomDamage;
	}
};


void gameStory() {
	system("cls");
	std::cout << "\n__________________________________\n";
	std::cout << "\n| Letho: A true Warrior |";
	std::cout << "\n__________________________________\n";
	std::cout << "\nOnce upon a time, there was a kingdom full of happiness. The king named Garelt had a beautiful princess named Barbara." << std::endl;
	std::cout << "\n__________________________________\n";
	std::cout << "\nUnfortunately, on one evil day the Hollow Knight Kidnapped Barbara.\nNow the entire kingdom is at stake. Hollow Knight is a ruler of the dark world.";
	std::cout << "\n__________________________________\n";
}

// Algorithm
// 1. Either player will heal or will attack
// 2. Enemy's Turn -> Enemy will perform the attack
// 3. Battle loop will continue till either one of them dies

void battleLoop(Player& player, Enemy& enemy) {
	char playerChoice;
	do {
		std::cout << "\n----- It's player's turn ----" << std::endl;
		std::cout << "\nPress A to attack or H to heal" << std::endl;
		std::cin >> playerChoice;

		if (playerChoice == 'a' || playerChoice == 'A') {
			system("cls");
			// Perform attack -> Player giving the damage to the enemy
			enemy.takeDamage(player.giveDamage());

			if (enemy.getHealth() > 0) {
				std::cout << "\n----- It's enemy's turn now ----" << std::endl;
				player.takeDamage(enemy.giveDamage()); // enemy now giving the damage to player
			}
		}
		else if (playerChoice == 'h' || playerChoice == 'H') {
			system("cls");
			// Perform heal
			player.heal();
		}
		else {
			system("cls");
			std::cout << "Invalid input!!" << std::endl;
		}
	} while (player.getHealth() > 0 && enemy.getHealth() > 0);
}

int main() {
	gameStory();
	char userInput;
	do
	{
		std::cout << std::endl;
		std::cout << "\nPress S to start the game! or any other key to exit from game!" << std::endl;
		std::cin >> userInput;

		if (userInput == 'S' || userInput == 's') {
			Player player;
			Enemy enemy;

			battleLoop(player, enemy);

		}
		else {
			std::cout << "\n\nThanks for playing the Letho Game!" << std::endl;
		}

	} while (userInput == 'S' || userInput == 's');

	return 0;
}