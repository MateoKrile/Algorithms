#include <vector>

using namespace std;

class PriorityQueue
{
	PriorityQueue()
	{
		heap = {};
	}
	
	vector<int> heap;

	int Parent(int index)
	{
		return floor((index - 1) / 2);
	}
	int ChildLeft(int index)
	{
		return index * 2 + 1;
	}
	int ChildRight(int index)
	{
		return index * 2 + 2;
	}
	void ShiftUp(vector<int>& heap, int index)
	{
		int temp = heap[Parent(index)];
		heap[Parent(index)] = heap[index];
		heap[index] = temp;
	}

	void Insert(vector<int>& heap, int value)
	{
		int index = heap.size();
		heap.push_back(value);
		//This is in case of a max heap, for a min heap check if the value is smaller
		while (value > heap[Parent(index)]) //Above formula for getting the parent
		{
			ShiftUp(heap, index);
			index = Parent(index);
		}
	}

	int ShiftDown(vector<int>& heap, int index, bool min = false)
	{
		int child;
		if (min)
		{
			child = heap[ChildLeft(index)] < heap[index] ? ChildLeft(index) : ChildRight(index);
		}
		else
		{
			child = heap[ChildLeft(index)] > heap[index] ? ChildLeft(index) : ChildRight(index);
		}
		int temp = heap[child];
		heap[child] = heap[index];
		heap[index] = temp;
		return child;
	}

	void Delete(vector<int>& heap, int index)
	{
		int last = heap.size() - 1;
		heap[index] = last;
		while (heap[index] < heap[ChildLeft(index)] || heap[index] < heap[ChildRight(index)])
		{
			index = ShiftDown(heap, index);
		}
	}
};