/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include <vector>
using namespace std;

class Player {
private:
	int n; //num of cards
	vector<Card> cards; // vector of cards
	// more private members

public:
	string name; //name of player

//	Player();
	Player(string name="noy" , int n=1);
	bool play(Card &current); //players turn 
	void show_cards(); 
	void options(Card &current);
	bool isWinner();
	string get_name(); //#
	//void next_turn(); //update the turn 
	friend  ostream &operator<<(ostream &os,  Player& p);
	bool operator!= ( Player& p2);

};
inline ostream &operator<<(ostream &os,  Player& p) {  //toString (cout)
        os<< "name: " << p.name <<", cards: - " << endl;
        	    int count=1;
	    cout<<"Your cards: ";
  for(vector<Card>::iterator it = p.cards.begin();it!=p.cards.end();it++)
    {
        cout<<"("<<count<<")"<<*it<<" ";
        count++;
    }
	   cout<<endl;
        return os;
    }
#endif



