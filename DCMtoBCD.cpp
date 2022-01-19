#include <iostream>
#include <stack>
using namespace std;
stack<int> bcd;
int DtoBconverter (int n){
	int digit[] = {0, 0, 0, 0}, i = 0;
	while(n > 0){
		digit[i] = n & 1;
		i++;
		n /= 2;
	}
	for(int i = 0; i < 4; i++){
		bcd.push(digit[i]);
	}
	return 0;
}	
int main(){
	int number, digit, arr[20], i = 0, n;
	cout << "input your number" << endl;
	cin >> number;
	cout << "this is you BCD: " << endl;
	while(number > 0){
		digit = number % 10;
		DtoBconverter(digit);
		number /= 10;
		i++;
	}
	for(int j = 0; j < 4*i; j++){
		n = bcd.top();
		cout << n;
		bcd.pop();
	}
}	