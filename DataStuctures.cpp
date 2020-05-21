#include "stdafx.h"
#include "DataStructures.h"

Stack::Stack (int size)
{
	Stack::size = size;
	buff = new int[size];
	int index = -1;
} //constructor

void Stack::Push (int value)
{
	if (index == size) { throw "Stack overflow"; }
	buff[index++] = value;
}

int Stack::Pop ()
{
	if (index == -1) { throw "Stack is empty"; }
	return buff[--index];
}

void Stack::PrintAll ()
{
	for (int i = 0; i < index; i++)
	{
		printf ("%d, ", buff[i]);
	}
	printf ("\n");
}

Stack::~Stack ()
{
	delete[] buff;
}

Queue::Queue (int size)
{
	Queue::size = size;
	buff = new int[size];
	Queue::reader = -1;
	Queue::writer = -1;
} //constructor

void Queue::Enqueue (int value)
{
	if (writer == reader && writer != -1)
	{
		throw "Queue is full";
	}
	++writer;
	writer %= size;
	buff[writer] = value;
}

int Queue::Dequeue ()
{
	if (writer == reader && writer == -1) { throw "Queue is empty"; }
	++reader;
	reader %= size;
	return buff[reader];
}

void Queue::PrintAll ()
{
	for (int i = reader != -1 ? reader + 1 % size : 0; i <= writer; i++ % size)
	{
		printf ("%d, ", buff[i]);
	}
	printf ("\n");
}

Queue::~Queue ()
{
	delete[]buff;
}