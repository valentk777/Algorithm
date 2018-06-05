#include "stdafx.h"
#include "HeapSort.h"

Heap::Heap ()
	: count (0), arr () {} //constructor

Heap::Heap (int* data, int _count)
	: count (_count), arr ()
{
	for (int i = 0; i < count; i++)
	{
		arr[i] = data[i];
	}
}

void Heap::Add (int sk)
{
	arr[count] = sk;
	for (int i = count; i > 0 && arr[(i - 1) / 2] < arr[i]; i = (i - 1) / 2)
	{
		Replace (arr[(i - 1) / 2], arr[i]);
	}
	count++;
}

void Heap::PrintAll ()
{
	for (int i = 0; i < count; i++)
	{
		printf ("%d, ", arr[i]);
	}
	printf ("\n");
}

void Heap::Replace (int& i, int& j)
{
	int temp = j;
	j = i;
	i = temp;
}

void Heap::Heapify ()
{
	for (int i = count / 2 - 1; i >= 0; --i)
	{
		for (int j = i; j <= count / 2 - 1; )
		{
			int left = 2 * j + 1;
			int right = 2 * j + 2;
			int index = right <= count && arr[left] < arr[right] ? right : left;
			if (arr[j] < arr[index])
			{
				Replace (arr[j], arr[index]);
				j = index;
			}
			else
			{
				break;
			}
		}
	}
}

