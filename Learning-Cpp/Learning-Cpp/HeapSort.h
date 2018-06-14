#pragma once
class Heap
{
public:
	Heap ();
	Heap (int* data, int count);

	void PrintAll ();
	void PrintAll (int count);
	void Heapify ();
	void Add (int sk);
	void Remove ();
	void HeapSort ();

private:
	int arr[100];
	int count;
	void Replace (int& i, int& j);
};