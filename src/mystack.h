/*
 * mystack.h
 *
 *  Created on: Oct 25, 2019
 *      Author: akhan
 */

#ifndef MYSTACK_H_
#define MYSTACK_H_

//  mystack.h	 mystack class INTERFACE using pointers
#ifndef   _MYSTACK_H
#define  _MYSTACK_H
#include "stddef.h"
using namespace std;
class mystack {
public:
	mystack();				// constructs empty stack
	mystack(const mystack &S);	// copy constructor
	~mystack(); 			// destructor to deallocate memory
	char top() const;			// returns top, no pop
	bool isEmpty() const;		// test for no nodes
	int length() const; 			// return number of elements
	void push(char item);		// push char onto top
	void pop();				// remove top and deallocate node
	char pop(char item);		// retrieve top char and deallocate node
	void makeEmpty(); 		// make stack empty & deallocate memory
	mystack operator=(const mystack &S);	// assignment operator
private:
	struct nodetype {
		char info;
		nodetype *next;
	};
	nodetype *mytop;	// pointer to top of stack
};

mystack::mystack() {
	mytop = NULL;
}

mystack::mystack(const mystack &S) {
	mytop = S.mytop;
}

mystack::~mystack() 			// destructor to deallocate memory
{
	delete(this);
}
char mystack :: top() const			// returns top, no pop
{
	return mytop->info;
}
bool mystack:: isEmpty() const		// test for no nodes
{
	if(mytop == NULL){
		return true;
	}
	return false;
}
int mystack :: length() const 			// return number of elements
{
	int count = 0;
	if(isEmpty()){
		return count;
	}
	nodetype *counter = mytop;
	while((counter) != (NULL)){
		count++;
		counter = counter->next;
	}
	return count;

}
void mystack :: push(char item)		// push char onto top
{
	nodetype *pushNode = new nodetype;
	pushNode->info = item;
	pushNode->next = mytop;
	mytop = pushNode;
}
void mystack:: pop()				// remove top and deallocate node
{
if(!isEmpty()){
	nodetype *temp = mytop;
	mytop = mytop->next;
	delete(temp);
}
}
char mystack:: pop(char item)		// retrieve top char and deallocate node
{
if(this->length() != 0){
	nodetype *popNode = mytop;
	mytop = mytop->next;
	char topChar = popNode->info;
	delete(popNode);
	return topChar;
}
}
void mystack :: makeEmpty() 		// make stack empty & deallocate memory
{
	while(!isEmpty()){
		pop();
	}
	mytop = NULL;
}
mystack mystack :: operator =(const mystack &S){
	return S;
}

#endif

#endif /* MYSTACK_H_ */
