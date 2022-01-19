#include<iostream>
#include<cstring>
using namespace std;

void changed_number(int ordinal_number, char number[], int n){
	int position = 1;
	while(!(ordinal_number & 1)){
		ordinal_number = ordinal_number >> 1;
		position++;
	}
	if(number[n - position] == '0') number[n - position] = '1';
	else number[n - position] = '0';
	for(int i = 0; i < n; i++) cout << number[i];
	cout << endl;
}
int main(){
	char s[100];
	int bit, ordinal_number = 1;
	cout << "insert your wanted number of bit: " << endl;
	cin >> bit;
	cout << "this is the table for " << bit << "-bit gray code:" << endl;
	for(int i = 0; i < bit; i++) s[i] = '0';
	int n = (1 << bit) - 1;
	for(int i = 0; i < bit; i++) cout << s[i];
	cout << endl;
	while(n){
		changed_number(ordinal_number, s, bit);
		ordinal_number++;
		n--;
	}
}