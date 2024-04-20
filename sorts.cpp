#include <iostream>
#include <vector>
#include <algorithm>


void IS(std::vector<int>& arr)
{
	int size = arr.size();
	int j;
	int key;
	for (int i = 1; i < size; ++i)
	{
		j = i - 1;
		key = arr[i];
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}



void SS(std::vector<int>& arr)
{
	int size = arr.size();
	for (int i = 0; i < size-1; ++i)
	{
		int minind = i;
		for (int j = i+1; j < size; ++j)
		{
			if (arr[j] < arr[minind])
			{
				minind = j;
			}
		}
		std::swap(arr[i], arr[minind]);
	}
}


void BS(std::vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; ++i)
	{
		for (int j = 0; j < arr.size() - 1 - i; ++j)
		{
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
	}
}


void merge(std::vector<int>& nums, int begin, int mid, int end)
{
	int leftsize = mid - begin + 1;
	int rightsize = end - mid;
	int* leftarr = new int[leftsize];
	int* rightarr = new int[rightsize];

	for (int i = 0; i < leftsize; ++i)
		leftarr[i] = nums[begin + i];
	for (int i = 0; i < rightsize; ++i)
		rightarr[i] = nums[mid + i + 1];

	int leftindex = 0;
	int rightindex = 0;
	int mergeindex = begin;

	while (leftindex < leftsize && rightindex < rightsize)
	{
		if (leftarr[leftindex] <= rightarr[rightindex])
		{
			nums[mergeindex++] = leftarr[leftindex++];
		}
		else
		{
			nums[mergeindex++] = rightarr[rightindex++];
		}
	}

	while (leftindex < leftsize)
	{
		nums[mergeindex++] = leftarr[leftindex++];
	}
	while (rightindex < rightsize)
	{
		nums[mergeindex++] = rightarr[rightindex++];
	}

	delete[] leftarr;
	delete[] rightarr;
}

void mergesort(std::vector<int>& nums, int begin, int end)
{
	if (begin >= end)
		return;
	int mid = begin + (end - begin) / 2;
	mergesort(nums,begin, mid);
	mergesort(nums, mid + 1, end);
	merge(nums, begin, mid, end);
}
