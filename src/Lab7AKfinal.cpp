//============================================================================
// Name        : realLab5AK.cpp
// Author      : Abdul Khan
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "mystack.h"
using namespace std;

int main() {
	string word;
	bool drome = true;
	mystack *newStack = new mystack();
	cout << "Enter a word: " << endl;
	cin >> word;
	for (int i = 0; i < word.length(); i++) {
		newStack->push(word.at(i));
	}
	if (word.length() % 2 == 0) {
		char array1[word.length() / 2];
		char array2[word.length() / 2];
		for (int i = 0; i < (word.length() / 2); i++) {
			array1[i] = newStack->pop('a');
		}
		for (int i = 0; i < word.length() / 2; i++) {
			array2[word.length() / 2 - (i + 1)] = newStack->pop('a');
		}
		for(int i = 0; i < word.length()/2; i++){
			if(array1[i] != array2[i]){
				drome = false;
			}
		}
	}

	else {
		char array1[word.length() / 2];
		char array2[word.length() / 2 + 1];
		for (int i = 0; i < (word.length() / 2); i++) {
			array1[i] = newStack->pop('a');
		}
		for (int i = 0; i < word.length() / 2 + 1; i++) {
			array2[word.length() / 2 - (i)] = newStack->pop('a');
		}
		for(int i = 0; i < word.length()/2 ; i ++){
		if((array2[i]) != (array1[i])){
			drome = false;
					}
		}
	}
	string answer;
	if(drome == 1){
		answer = "true";
	}
	else{
		answer = "false";
	}
	cout << word << " is a palindrome: " << answer;
}
