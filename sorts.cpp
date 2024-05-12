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


////// MergeSort
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


//////QucikSort
void setMedian(std::vector<int>& arr,int first, int last)
{
	    int mid = first + (last - first) / 2;
    if (arr[first] > arr[mid])
        std::swap(arr[first], arr[mid]);
    if (arr[mid] > arr[last])
        std::swap(arr[mid], arr[last]);
    if (arr[first] > arr[mid])
        std::swap(arr[first], arr[mid]);
    std::swap(arr[mid], arr[last - 1]);
}

int partition(std::vector<int>& arr ,int first,int last)
{
    setMedian(arr, first, last);
    int pivot = arr[last - 1];
    int leftIndex = first+1;
    int rightIndex = last - 2;
    while (true)
    {
        while (arr[leftIndex] < pivot)
            ++leftIndex;
        while (arr[rightIndex] > pivot)
            --rightIndex;
        if (leftIndex >= rightIndex)
            break;
        std::swap(arr[leftIndex++], arr[rightIndex--]);
    }
    std::swap(arr[leftIndex], arr[last - 1]);
    return leftIndex;
}

void quickSort(std::vector<int>& arr, int first, int last)
{
    if (first < last)
    {
        if (last - first + 1 <= 3)
        {
            std::sort(arr.begin() + first, arr.begin() + last + 1);
        }
        else
        {
            int pivotIndex = partition(arr, first, last);
            quickSort(arr, first, pivotIndex - 1);
            qucikSort(arr, pivotIndex + 1, last);
        }
    }
}

///// CountSort
void countsort(std::vector<int>& arr)
{
    int minElem = min(arr);
    int maxElem = max(arr);
    int countSize = maxElem - minElem + 1;
    std::vector<int> count(countSize, 0);
    for (int i = 0; i < arr.size(); ++i)
	++count[arr[i]-minElem];
    for (int i = 1; i < countSize; ++i)
    {
        count[i] += count[i - 1];
    }
    std::vector<int> outArr(arr.size());
    for (int i = arr.size()-1; i >= 0; --i)
    {
        outArr[count[arr[i]-minElem] - 1] = arr[i];
        --count[arr[i] - minElem];
    }
    arr = std::move(outArr);
}


