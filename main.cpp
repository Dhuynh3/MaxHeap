#include <iostream>
#include <vector>

#define MAX_INTEGER 2147483647

class MaxHeap {
public:
	
	std::vector<int> HeapArray;

	void InsertElement(int val);

	void PercolateUp(int node_index);

	void PrintArray();

	void RemoveMax();
};


void MaxHeap::InsertElement(int val) {
	
	// Insert into tree's last level
	this->HeapArray.push_back(val);

	// Find it's current index
	int idx = this->HeapArray.size() - 1; 

	while (idx > 0) { // While not the root node

		int parent_index = (idx - 1) / 2;

		if (this->HeapArray[idx] <= this->HeapArray[parent_index]) { // If our inserted node is less than it's parent, it belongs there.
			return;
		}
		else {
			int temp = this->HeapArray[parent_index];
			this->HeapArray[parent_index] = this->HeapArray[idx];
			this->HeapArray[idx] = temp;

			idx = parent_index;
		}

	}

}

void MaxHeap::RemoveMax() {



}


void MaxHeap::PrintArray() {

	for (auto x : this->HeapArray) {
		printf("%i ", x);
	}

}


int main() {

	MaxHeap* Heap = new MaxHeap();

	Heap->InsertElement(10);
	Heap->InsertElement(5);
	Heap->InsertElement(20);
	Heap->InsertElement(31);
	Heap->InsertElement(60);
	

	Heap->PrintArray();

	system("pause");
	return 0;
}