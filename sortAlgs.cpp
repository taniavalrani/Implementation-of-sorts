#include <iostream>
#include <vector>

using namespace std;

// declaration for helper function for merge
void merge(vector<int>& leftVector, vector<int>& rightVector, 
	vector<int>& myVector);
// declarations for helper functions for quick sort
int splitQuick(vector <int>& myVector, int start, int end);
void quickSort(vector <int>& myVector, int start, int end);
void swap(vector<int>& myVector, int index, int end);

// insertion sort
void insertionSort(vector <int>& myVector)
{
	// iterate through the unsorted vector starting at index 1 and check
	// whether the element before it is greater than it. If so, swap the
	// elements
	for(unsigned int i = 1; i < myVector.size(); i++)
	{
		int value = myVector[i];
		unsigned int location = i;
		for(unsigned int j = i; ((location > 0) 
			and (myVector[location - 1]) > value); j--)
		{
			myVector[location] = myVector[location - 1];
			location--;
		}
		myVector[location] = value;
	}
}

// helper function for merge sort. 
void merge(vector<int>& leftVector, vector<int>& rightVector, 
	vector<int>& myVector)
{
	unsigned int sizeLeft = leftVector.size();
	unsigned int sizeRight = rightVector.size();
	unsigned int position_merge = 0;
	unsigned int position_left = 0;
	unsigned int position_right = 0;
	// while we are within the count of the left and right vector
	// we check to see if whether the left position is less than or
	// equal to the right position, and then fill the sorted vector
	// with the correct input from the left and right vector
	while((position_left < sizeLeft) and (position_right < sizeRight))
	{
		// if the left index is a smaller, put that value in the
		// merged vector
		if(leftVector[position_left] <= rightVector[position_right])
		{
			myVector[position_merge] = leftVector[position_left];
			position_merge++;
			position_left++;
		}
		// otherwise put the right value
		else
		{
			myVector[position_merge] = rightVector[position_right];
			position_merge++;
			position_right++;
		}
	}
	// if there are leftover elements in one vector while another is empty,
	// empty the vector with elements (that are already sorted) into the
	// new sorted vector.
	while(position_left < sizeLeft)
	{
		myVector[position_merge] = leftVector[position_left];
		position_left++;
		position_merge++;
	}
	while(position_right < sizeRight)
	{
		myVector[position_merge] = rightVector[position_right];
		position_right++;
		position_merge++;
	}
	
}

// merge sort function
void mergeSort(vector <int>& myVector)
{
	// if the size is less than 2, stop splitting the vector
	unsigned int n = myVector.size();
	if(n < 2)
	{
		return;
	}
	// split the vector into two recursively call the mergeSort function
	// and then call helper function that actually sorts the vectors
	else
	{
		unsigned int mid = n/2;
		vector <int> newLeftVector;
		vector <int> newRightVector;
		for(unsigned int i = 0; i < mid; i++)
		{
			newLeftVector.push_back(myVector[i]);
		}
		for(unsigned int j = mid; j < n; j++)
		{
			newRightVector.push_back(myVector[j]);
		}
		mergeSort(newLeftVector);
		mergeSort(newRightVector);
		merge(newLeftVector, newRightVector, myVector);
	}
}

// quicksort function
void quickSort(vector<int>& myVector)
{
	// declare and initialize variables I need to call the helper function
	unsigned int start = 0;
	unsigned int end = myVector.size();
	end = end - 1;
	// call helper function
	quickSort(myVector, start, end);

}

// helper function for quicksort
void quickSort(vector <int>& myVector, int start, int end)
{
	// so long as start is less than the end, find a partition using the
	// partition helper function, and then call the quicksort function
	// on an updated value for start and end using the partition helper
	// function
	if(start < end)
	{
		int pi_index = splitQuick(myVector, start, end);
		quickSort(myVector, start, pi_index - 1);
		quickSort(myVector, pi_index+1, end);
	}
}

// helper function to partition the vector
int splitQuick(vector <int>& myVector, int start, int end)
{
	// pivot is at the end of the vector
	int pivot = myVector[end];
	int index = start - 1;
	// go through the vector and if i is less than pivot, swap it
	for(int i = start; i < end; i++)
	{
		if(myVector[i] <= pivot)
		{
			index++;
			swap(myVector[i], myVector[index]);
		}
	}
	swap(myVector, index, end);
	// return a new partition point
	return index + 1;
}

// swap helper functions
void swap(vector<int>& myVector, int index, int end)
{
	// use a temp variable to store one value while swapping it with the
	// other
	int temp = myVector[end];
	myVector[end] = myVector[index + 1];
	myVector[index + 1] = temp;
}
