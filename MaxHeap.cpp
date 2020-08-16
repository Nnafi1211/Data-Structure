#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
	int *harr;
	int capacity;
	int heap_size;

public:
	MaxHeap(int cap); // constractor
	int parent(int i) { return (i-1)/2; }
	int left(int i) { return (2*i)+1; }
	int right(int i) { return (2*i)+2; }

	void shiftUp(int i);
	void shiftDown(int i);

	int getMax() { return harr[0]; }
	int extractMax();
	void insert(int value);
	void remove(int i);
	void changePriority(int i, int value);
	bool isEmpty();
};

MaxHeap::MaxHeap(int cap){
	heap_size = 0;
	capacity = cap;
	harr = new int[capacity];
}

void MaxHeap::shiftUp(int i){
	while(i!=0 && harr[parent(i)] < harr[i]){
		swap(harr[parent(i)], harr[i]);
		i = parent(i);
	}
}

void MaxHeap::shiftDown(int i){
	int maxIndex = i;
	int l = left(i);
	int r = right(i);

	if(l<heap_size && harr[l] > harr[maxIndex])
		maxIndex = l;
	if(r<heap_size && harr[r] > harr[maxIndex])
		maxIndex = r;

	if(maxIndex != i){
		swap(harr[maxIndex], harr[i]);
		shiftDown(maxIndex);
	}
}

void MaxHeap::insert(int value){
	if(heap_size == capacity){
		cout << "Overflow! Cannot insert...";
		return;
	}

	int i = heap_size;
	harr[i] = value;
	heap_size++;

	shiftUp(i);	
}

int MaxHeap::extractMax(){
	if(heap_size == 0){
		return INT_MIN;
	}

	int result;

	result = harr[0];
	heap_size--;

	if(heap_size == 0){
		return result;
	}

	harr[0] = harr[heap_size];
	shiftDown(0);

	return result;
}

void MaxHeap::remove(int i){
	harr[i] = INT_MAX;
	shiftUp(i);
	extractMax();
}

void MaxHeap::changePriority(int i, int value){
	int old_value = harr[i];
	harr[i] = value;

	if(harr[i] > old_value)
		shiftUp(i);
	else if(harr[i] < old_value)
		shiftDown(i);
}

bool MaxHeap::isEmpty(){
	return !heap_size;
}

int main(){
	MaxHeap h(10);

	h.insert(3);
	h.insert(103);
	h.insert(398);
	h.insert(35);
	h.insert(32);
	h.insert(13);
	h.insert(33);

	cout << h.getMax() << "\n";

	h.changePriority(2, 10);
	h.remove(7);

	while(!h.isEmpty()){
		cout << h.extractMax() << " ";
	}

	cout << "\n";

	return 0;
}