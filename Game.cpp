/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */
using namespace std;
#include "Game.h"
#include "Player.h"
#include <algorithm>


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
    Card curr = Card::generate_card();

    while(true){
        bool ans = turn->play(curr);

        if (curr.get_sign() == sign::STOP){  //if the card is STP
            if(turn->isWinner()) return; //this plater win!
            if(players_list.size() == 2) turn = turn; //turn the same player
            else if(turn == players_list.end()-1) turn = players_list.begin()+1; //השחקן האחרון עשה עצור על השחקן הראשון
            else if(turn == players_list.end()-2) turn = players_list.begin(); //השחקן לפני האחרון עצר את האחרון
            else
                turn = turn+2; //כל שאר המקרים הלא מיוחדים
        }

        else if(curr.get_sign() == sign::PLUS){
            if(turn->isWinner()) return; //this plater win!
            turn = turn; //the same player turn again
        }
        
        else if(curr.get_sign() == sign::CD){ //if the card is change direction
            if(turn->isWinner()) return; //this plater win!
            if(turn == players_list.begin()){
                reverse(players_list.begin(), players_list.end());
                turn = players_list.begin(); // the last one became the first so it his turn.
            }
            else{
                vector<Player> new_vec;
                Player curr_turn = *turn;
                reverse(players_list.begin(), players_list.end());
                vector<Player>::iterator it = players_list.begin(); //changing the player vector

                int count =1;
        	    while(*it != curr_turn){
                    count++;
                    it++;
    	    }
    	    int i;
                vector<Player>::iterator it2 = players_list.begin();
        	    while(it2 != players_list.end() && it != players_list.end()){
                    for(i=0; i<players_list.size()%count; i++ ){
                        new_vec.push_back(*(it+1));
                        it2++;
                        it++;
                    }
                    it = players_list.begin();
                    for(int j=0; j<players_list.size()-(players_list.size()%count); j++ ){
                        new_vec.push_back(*(it));
                        it2++;
                        it++;
                    }
    	    }
                players_list=new_vec;
                turn = players_list.begin();
            }
        }
        
        else{ //other sign (not special sign)
            if(turn->isWinner()) return; //this player win!
            if(turn == players_list.end()-1) turn = players_list.begin();
            else turn++;
        }
        //         if(!ans&&players_list.size()==2)
        // {
        //     if(turn==players_list.begin())
        //         turn=players_list.end()-1;
        //     else 
        //         turn=players_list.begin();
            
        // }
        
    }  //end while
}

void Game::print_players(){
    vector<Player>::iterator it = players_list.begin();
    cout << "[ ";
    	    while(it != players_list.end()){
                cout << *it << " ";
                it++;
	    }
	   cout<< "]"<<endl;
}
