/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */

#include "Player.h"

	Player::Player(string name, int n){
	    int j;
		this->name = name;
		this->n = n;
		
		for(j=0; j<n; j++){
		    Card c(generate_card());
            cards.push_back(c);
        }
        std::cout << "whattttt" << std::endl;
	}
	
// 	bool Player::isWin(){
//     if(cards.size() == 0){
//         cout << getName() << " Wins" << endl;
//         return true;
//     }
//     else 
//         return false;
//     }

	
	void Player::show_cards(){
	    int count=1;
	    cout<<"Your cards: ";
	    vector<Card>::iterator it=cards.begin();
	    
	    while(it != cards.end()){
            cout << "(" << count << ")" << *it << " ";
            count++;
	    }
	   cout<<endl;
	}
	
    string Player::get_name(){
        return name;
    }

    bool Player::play(Card &current){
        cout << "current: " << current << endl;
        cout<<"bla"<<endl;
        cout << get_name() <<", your turn - " << endl;
        //show_cards();
        
    return true;
    }
