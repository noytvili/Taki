/* Doriya Spielman 313466625 */
/* Noy Tvili 308426790 */

#include "Player.h"

	Player::Player(string name, int n){
	    int j;
		this->name = name;
		this->n = n;
		
		for(j=0; j<n; j++){
		    Card c(Card::generate_card());
            cards.push_back(c);
        }
	}
	
	void Player::show_cards(){
	    int count=1;
	    cout<<"Your cards: ";
	    vector<Card>::iterator it=cards.begin();
	    
	    while(it != cards.end()){
            cout << "(" << count << ")" << *it << " ";
            count++;
            it++;
	    }
	   cout<<endl;
	}
	
	bool Player::options(Card &current){//options when the player pick a card
	    int choice;
	    bool flag =true;
	    
	    while(flag){
	        cin >> choice;
	        if(choice == 0 || choice > cards.size()){ // not in range
	            Card new_card(Card::generate_card());
	            cards.push_back(new_card);
	            flag = false;//next turn
	            return false;

	        }
	        else {
	            if(current.is_legal(cards.at(choice-1))){ // if he picks legal card
	                current = (cards.at(choice-1));
	                cards.erase(cards.begin()+(choice-1));
	                flag = false; //next turn
	                return true;        

	            }
	            else { // not legal card
	                cout << "you can't put " << cards.at(choice-1) << " on " << current << endl;
	                return false;
	            }
	        }
	    }
	}
	
    string Player::get_name(){
        return name;
    }

    bool Player::play(Card &current){ //player playing
        cout << "current: " << current << endl;
        cout << this->get_name() <<", your turn - " << endl;
        show_cards();
        options(current);
        
    return true;
    }
    
    bool Player::isWinner(){ //true if wins , false if not
    if(cards.size() == 0){
    	cout << get_name() << " Wins!" << endl;
        return true;
    }
    else return false;
    }
    
    bool Player::operator!= ( Player& p2){
        return name != p2.name;
    }
