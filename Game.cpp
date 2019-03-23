/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */
using namespace std;
#include "Game.h"
#include "Player.h"


 void Game::start(){
    int i,num,num_players;
    string player_name;

    cout << "How many players?" << endl;
    cin >> num_players;
    cout << "How many cards?" << endl;
    cin >>  num;

    for(i=0; i<num_players; i++){
        cout << "player number " << i+1 << " name?" << endl;
        cin >> player_name;
        Player p(player_name, num);
        this->players_list.push_back(p);


    }
    vector<Player>::iterator turn = players_list.begin();
    Card curr=generate_card();
    bool ans = turn->play(curr);
}

void Game::print_players(){
    vector<Player>::iterator it = players_list.begin();
    	    while(it != players_list.end()){
                cout << *it << " ";
                it++;
	    }
	   cout<<endl;
}
