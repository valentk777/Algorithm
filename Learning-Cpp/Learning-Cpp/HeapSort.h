#pragma once
class Heap
{
public:
	Heap ();
	Heap (int* data, int count);

	void PrintAll ();
	void Heapify ();
	void Add (int sk);

private:
	int arr[100];
	int count;
	void Replace (int& i, int& j);
};