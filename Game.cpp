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

    for(i = 0; i < num_players; i++){
        cout << "player number " << i+1 << " name?" << endl;
        cin >> player_name;
        Player p(player_name, num);
        this->players_list.push_back(p);
    }
    
    vector<Player>::iterator turn = players_list.begin();
    Card curr = generate_card();

    while(true){
        bool ans = turn->play(curr);
        if (curr.get_sign() == STOP){  //if the card is STP
            if(turn->isWinner()) return; //this plater win!
            if(players_list.size() == 2) turn = turn; //turn the same player
            else if(turn == players_list.end()-1) turn = players_list.begin()+1; //השחקן האחרון עשה עצור על השחקן הראשון
            else if(turn == players_list.end()-2) turn = players_list.begin(); //השחקן לפני האחרון עצר את האחרון
            else
                turn = turn+2; //כל שאר המקרים הלא מיוחדים
        }
        else if(curr.get_sign() == PLUS){
            if(turn->isWinner()) return; //this plater win!
            turn = turn; //the same player turn again
        }
        
        else if(curr.get_sign() == CD){ //if the card is change direction
            if(turn->isWinner()) return; //this plater win!
            if(turn == players_list.begin()){
                reverse(players_list.begin(), players_list.end());
                turn = players_list.end(); //הראשון שם שנה כיוון ועכשיו תור האחרון
                
            }
        }
        else{ //other sign (not special sign)
            if(turn->isWinner()) return; //this plater win!
            if(turn == players_list.end()-1) turn = players_list.begin();
            else turn++;
        }
        
    }  //end while
}

void Game::print_players(){
    vector<Player>::iterator it = players_list.begin();
    	    while(it != players_list.end()){
                cout << *it << " ";
                it++;
	    }
	   cout<<endl;
}
