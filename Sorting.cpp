#include <vector>
#include <limits>
#include <iostream>
#include <math.h>

using namespace std;

class Sorting
{
public:
    //Constructor
    Sorting(){}

    void BubbleSort(vector<int>& array)
    {
        for(unsigned int j=0; j<array.size(); j++)
        {
            for(unsigned int i=1; i<array.size(); i++)
            {
                if(array[i-1]>array[i])
                {
                    swap(array[i], array[i - 1]);
                }
            }
        }
        return;
    }

    void SelectionSort(vector<int>& array)
    {
        for(unsigned int i=0; i<array.size(); i++)
        {
            int minIndex = i;
            for(unsigned int j=0; j<array.size(); j++)
            {
                if(array[j] < array[minIndex])
                {
                    minIndex = j;
                }
            }
            swap(array[i], array[minIndex]);
        }
        return;
    }

    void InsertionSort(vector<int>& array)
    {
        int j, value;
        for(unsigned int i=0; i<array.size(); i++)
        {
            value = array[i];
            j = i-1;
            while(j>=0 && array[j]>value)
            {
                array[j+1] = array[j];
                j--;
            }
            array[j+1] = value;
        }
        return;
    }

    vector<int> MergeSort(vector<int>& array)
    {
        if (array.size() == 0) { return array; }

        int mid = int(floor(array.size() / 2));
        vector<int> left;
        vector<int> right;
        int last = array.size() - 1;
        copy(0, mid, left);
        copy(mid+1, last, right);
        return MergeSort(Merge(left, right));
    }

    vector<int> Merge(const vector<int>& left, const vector<int>& right)
    {
        unsigned int leftIndex = 0;
        unsigned int rightIndex = 0;
        vector<int> result;
        while (leftIndex < left.size() && rightIndex < right.size())
        {
            if (left[leftIndex] < right[rightIndex])
            {
                result.push_back(left[leftIndex]);
                leftIndex++;
            }
            else
            {
                result.push_back(right[rightIndex]);
                rightIndex++;
            }
        }
        while (!left.empty())
        {            
            result.push_back(left[leftIndex]);
            leftIndex++;
        }
        while (!right.empty())
        {
            result.push_back(right[rightIndex]);
            rightIndex++;
        }
        return result;
    }

    void Quicksort(vector<int>& array, int left, int right)
    {
        if (left < right)
        {
            int partIndex = Partition(array, left, right);
            Quicksort(array, left, partIndex - 1);
            Quicksort(array, partIndex + 1, right);
        }
        return;
    }

    int Partition(vector<int>& array, int left, int right)
    {
        int pivot = right;
        int partition = left;
        for (int i = left; i < right; i++)
        {
            if (array[i] <= pivot)
            {
                swap(array[i], array[partition]);
                partition++;
            }
        }
        swap(array[partition], array[pivot]);
        return partition;
    }

    void PrintArray(vector<int>& array)
    {
        for (int i : array)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};