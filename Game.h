/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */

#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "Card.h"
#include <vector>
using namespace std;

class Game {
private:
	//Game(const Game &g);
	Card current; // the current card 
	int num_of_players;
	vector<Player> players_list;//vector of players
	//Player turn; // hows turn
	string direction;
	
	void swap_dir(); //after change direction card
public:
	//public members and functions
	//Game();
	void start();
	void print_players();
};
#endif




