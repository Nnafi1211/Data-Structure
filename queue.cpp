#include <iostream>
using namespace std;

#define MAX 1000

class queue{
	int rear = -1;
	int f = -1;
	int queue[MAX];

public:
	void push(int x);
	void pop();
	bool isEmpty();
	void front();
	void print();
};

bool queue::isEmpty(){
	if(rear == -1 && f == -1)
		return true;
	return false;
}

void queue::push(int x){
	if((rear + 1) % MAX == f){
		cout << "overflow!\n";
		return;
	}
	if(isEmpty()){
		f = 0;
		rear = 0;
	}
	else if(rear != MAX)
		rear = (rear + 1) % MAX;

	queue[rear] = x;
	cout << x << " pushed into the queue!\n";

}

void queue::pop(){

	if(isEmpty()){
		cout << "Queue empty\n";
		return;
	}
	else if(f == rear){
		f = -1;
		rear = -1;
	}
	else{
		f = (f + 1) % MAX;
	}
}

void queue::front(){
	if(!isEmpty())
		cout << queue[f] << "\n";
	else
		cout << "Queue is empty!\n";
}

int main(){
	queue a;

	a.front();
	for(int i=1; i<1005; ++i)
		a.push(i);
	a.pop();
	a.push(20);
	a.front();
	a.pop();
	a.front();
	
	return 0;
}