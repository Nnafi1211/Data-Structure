#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
	int *harr; //pointer to array element in the heap
	int capacity;
	int heap_size;

public:
	MinHeap(int capacity); // constractor
	int parent(int i) { return (i-1)/2; }
	int left(int i) { return (2*i)+1; }
	int right(int i) { return (2*i)+2; }
	int extractMin();
	int getMin() { return harr[0]; }
	void shiftUp(int i);
	void shiftDown(int i);
	void insert(int value);
	void remove(int i);
	void changePriority(int i, int value);
};

MinHeap::MinHeap(int cap){
	heap_size = 0;
	capacity = cap;
	harr = new int[cap];
}

void MinHeap::insert(int value){
	if(heap_size == capacity){
		cout << "Overflow!! Could not insert\n";
		return;
	}
	
	heap_size++;
	int i = heap_size - 1;
	harr[i] = value;

	shiftUp(i);

}

void MinHeap::remove(int i){
	harr[i] = INT_MIN;
	shiftUp(i);
	extractMin();
}

void MinHeap::shiftUp(int i){
	while(i != 0 && harr[parent(i)] > harr[i]){
		swap(harr[parent(i)], harr[i]);
		i = parent(i);
	}
}

void MinHeap::shiftDown(int i){
	int minIndex = i;
	int l = left(i), r = right(i);
	if(l < heap_size && harr[l] < harr[minIndex])
		minIndex = l;
	if(r < heap_size && harr[r] < harr[minIndex])
		minIndex = r;

	if(i != minIndex){
		swap(harr[i], harr[minIndex]);
		shiftDown(minIndex);
	}
}

int MinHeap::extractMin(){
	if(heap_size <= 0){
		return INT_MAX;
	}

	if(heap_size == 1){
		heap_size--;
		return harr[0];
	}

	int result = harr[0];
	harr[0] = harr[heap_size - 1];
	heap_size--;
	shiftDown(0);

	return result;
}

void MinHeap::changePriority(int i, int value){
	int old_value = harr[i];
	harr[i] = value;

	if(value < old_value)
		shiftUp(i);
	else
		shiftDown(i);
}

int main(){
	MinHeap h(11);

    h.insert(2); 
    h.insert(15); 
    h.insert(5); 
    h.insert(4); 
    h.insert(45);
    h.insert(11); 
    cout << h.getMin() << "\n";
    h.remove(0);
    cout << h.getMin() << "\n";
    h.changePriority(2, 6);
    h.remove(2);
    cout << h.extractMin() << " " << h.extractMin() << " " << h.extractMin() << " " << h.extractMin() << "\n";

	return 0;

}
