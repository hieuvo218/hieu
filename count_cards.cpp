#include <iostream>
#include <vector>
using namespace std;

//declare suits
vector <string> hearts;
vector <string> diamonds;
vector <string> clubs;
vector <string> spades;
int length;
void count(vector <string> suits, string name){
	int number_of_cards_have_i_value[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};		//we set the value of each number to array
	for(vector<string>::iterator i = suits.begin(); i != suits.end(); ++i){
		if((*i)[1] > 47 && (*i)[1] < 58)
			number_of_cards_have_i_value[((*i)[0] - '0') * 10 + (*i)[1] - '0' - 1] += 1;
		else number_of_cards_have_i_value[(*i)[0] - '0' - 1] += 1;					//example: arr[i] = "3h" => number[2] := + 1. we set the value of the card plus 1
	}
	for(int i = 0; i < 13; i++){
		if(number_of_cards_have_i_value[i] > 1) cout << number_of_cards_have_i_value[i] - 1 << " extra " << i + 1 << ' ' << name << " cards" << endl;
		else if(number_of_cards_have_i_value[i] == 0) cout << "lacks" << " one " << i+1 << ' ' << name << " card " << endl; 
	}
}

void classify_into_suits(string card){
	if(card[1] == 'h' || card[2] == 'h') hearts.push_back(card);
	else if(card[1] == 'd' || card[2] == 'd') diamonds.push_back(card);
	else if(card[1] == 'c' || card[2] == 'c') clubs.push_back(card);
	else if(card[1] == 's' || card[2] == 's') spades.push_back(card);
}

int main(){
	string card;
	cout << "please type in your cards " << endl
		 << "form: number + suit (no space)" << endl
		 << "each card is separated by a space" << endl
		 << "if you want to end, type in " << "end" << endl;
	while(card != "end"){
		cin >> card;
		classify_into_suits(card);
	}
	count(hearts, "heart");
	count(diamonds, "diamond");
	count(clubs, "club");
	count(spades, "spade");
}