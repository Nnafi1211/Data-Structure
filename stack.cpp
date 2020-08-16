#include <bits/stdc++.h>
using namespace std;

#define MAX 1000

class Stack{
	int top;

public:
	int a[MAX];

	Stack() { top = -1; }
	void push(int x);
	void pop();
	int top();
	bool isEmpty();
};

void Stack::push(int x){

	if(top >= MAX - 2){
		cout << "stack overflow!";
		return;
	}

	else{
		a[++top] = x;
		cout << x << " pushed into stack!\n";
		return;
	}
}

void Stack::pop(){

	if(top < 0){
		cout << "stack underflow\n";
		return;
	}

	else{
		int x = a[top--];
		cout << x << " popped from stack!\n";
	}
}

int Stack::top(){
	
	if(top < 0){
		cout << "stack is empty!\n";
	}
	else{
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty(){
	return (top < 0);
}

int main(){
	Stack s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.pop();
	cout << s.top() << "\n";
	s.pop();
	s.pop();
	cout << s.top() << "\n";
	s.pop();
	cout << s.isEmpty() << "\n";
	s.pop();

	return 0;
}


