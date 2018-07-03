class Stack
{
public:
	Stack (int size);
	~Stack ();      // destructor

	void Push (int value);
	int Pop ();
	void PrintAll ();

private:
	int* buff;
	int index;
	int size;
};

class Queue
{
public:
	Queue (int size);
	~Queue ();      // destructor

	void Enqueue (int value);
	int Dequeue ();
	void PrintAll ();

private:
	int* buff;
	int reader;
	int writer;
	int size;
};