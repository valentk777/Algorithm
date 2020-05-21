#include "stdafx.h"
#include "stdio.h"
#include "SortAlgorithms.h"

void Replace (int& i, int& j);
void PrintAll (int *buff, int count);
void SelectionSort (int *buff, int count);
void InsertionSort (int *buff, int count);
void BoubleSort (int *buff, int count);
void BoubleSortOptimized (int *buff, int count);
void MergeSort (int *buff, int count);
void Merge (int* source, int* destination, int count, int currentCount);
int Partition (int* arr, int from, int to);
void QS (int* arr, int from, int to);
void QuickSort (int* arr, int count);
int* Partition_P (int* arr, int* from, int* to);
void QS_P (int* arr, int* from, int* to);
void QuickSort_P (int* arr, int count);

void PrintAll (int *buff, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf ("%d, ", buff[i]);
	}
	printf ("\n");
}

void SelectionSort (int *buff, int count)
{
	// iterate all array
	for (int* it = buff; it < buff + count - 1; it++)
	{
		int* min = it;

		// find min value in arr
		for (int* i = it + 1; i < buff + count; i++)
			if (*min > *i)
				min = i;

		Replace (*it, *min);
	}
}

void Replace (int& i, int& j)
{
	int temp = j;
	j = i;
	i = temp;
}

void InsertionSort (int *buff, int count)
{
	// iterate array from the beginning
	for (int* it = buff + 1; it < buff + count; it++)
	{
		for (int* i = it - 1; i >= buff && *i > *(i + 1); i--)
		{
			Replace (*i, *(i + 1));
		}
	}
}

void BoubleSort (int *buff, int count)
{
	for (int* it = buff + count; it > buff; it--)
	{
		bool NotChanged = true;
		for (int* i = buff; i < it - 1; i++)
		{
			if (*i > *(i + 1))
			{
				Replace (*i, *(i + 1));
				NotChanged = false;
			}
		}

		if (NotChanged)
		{
			break;
		}
	}
}


void BoubleSortOptimized (int *buff, int count)
{
	int* end = buff + count;
	while (end != NULL)
	{
		int* lastChanged = NULL;
		for (int* i = buff; i < end - 1; i++)
		{
			if (*i > *(i + 1))
			{
				Replace (*i, *(i + 1));
				lastChanged = i + 1;
			}
		}
		end = lastChanged;
	}
}

//currentCount - mini array length; count - all array length
void Merge (int* source, int* destination, int count, int currentCount)
{
	int* p1 = source;
	int* w = destination; // writer
	while (w < destination + count)
		// for (int i = 0; i < count / (2 * currentCount); i++)
	{
		int* p2 = p1 + currentCount;
		int* e1 = p2; // end of first mini array + 1
		int* e2 = p2 + currentCount; // end of second mini array + 1

									 // check an array "tail"
		e1 = e1 > source + count ? source + count : e1;
		e2 = e2 > source + count ? source + count : e2;

		while (p1 < e1 && p2 < e2)
		{
			// *w++ = *p2 < *p1 ? *(p2++) : *(p1++);
			*w++ = *((*p2 < *p1 ? p2 : p1)++); // same as commented
		}
		while (p1 < e1)
			*w++ = *p1++;
		while (p2 < e2)
			*w++ = *p2++;
		p1 += currentCount;
	}
}

void MergeSort (int *buff, int count)
{
	int* array2 = new int[count] ();
	int* a1 = buff;
	int* a2 = array2;

	for (int i = 1; i < count; i *= 2)
	{
		Merge (a1, a2, count, i);
		int* temp = a1;
		a1 = a2;
		a2 = temp;
	}
	if (a1 != buff)
	{
		for (int* i = buff; i < buff + count; i++)
			*i = *a1++;
	}
}

// find element and place it to correct position
// there is a lot of implementations and ideas
// one of them - take last element and replace it with first one if it is bigger 

int Partition (int* arr, int from, int to)
{
	while (from < to)
	{
		if (arr[from] < arr[to])
		{
			from++;
			continue;
		}

		int temp = arr[from];
		arr[from] = arr[to - 1];
		arr[to - 1] = arr[to];
		arr[to] = temp;
		to--;
	}
	return to;
}

// main QS with recursion
void QS (int* arr, int from, int to)
{
	int ind = Partition (arr, from, to);
	if (ind - 1 > from)
	{
		QS (arr, from, ind - 1);
	}
	if (ind + 1 < to)
	{
		QS (arr, ind + 1, to);
	}
}

// call QS for your array
void QuickSort (int* arr, int count)
{
	QS (arr, 0, count - 1);
}

// with pointers

int* Partition_P (int* arr, int* from, int* to)
{
	while (from < to)
	{
		if (*from < *to)
		{
			from++;
			continue;
		}

		int temp = *from;
		*from = *(to - 1);
		*(to - 1) = *to;
		*to = temp;
		to--;
	}
	return to;
}

// main QS with recursion
void QS_P (int* arr, int* from, int* to)
{
	int* ind = Partition_P (arr, from, to);
	if (*ind - 1 > *from)
	{
		QS_P (arr, from, ind - 1);
	}
	if (ind + 1 < to)
	{
		QS_P (arr, ind + 1, to);
	}
}

// call QS for your array
void QuickSort_P (int* arr, int count)
{
	QS (arr, 0, count - 1);
}