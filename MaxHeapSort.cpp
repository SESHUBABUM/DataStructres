#include<iostream>
#include<string.h>
using namespace std;

class MaxHeap
{
	int N;
	int *arr;
public:
	MaxHeap(int n)
	{
		arr = new int[n+1];
		N = 0;		
	}
	void swap(int i, int j)
	{
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
	void sink(int k)
	{
		while (2*k<=N)
		{
			int j = 2 * k;
			if (j < N && arr[j] < arr[j + 1]) j++;
			if (arr[j] <= arr[k]) break;
			swap(k, j);
			k = j;
		}
	}
	int getele()
	{
		int ele = arr[1];
		swap(1, N--);
		
		sink(1);
		return ele;
	}
	void swim(int k)
	{
		while (k > 1 && arr[k/2] < arr[k])
		{
			swap(k, k / 2);
			k = k / 2;
		}
	}
	void insert(int ele)
	{
		arr[++N] = ele;
		swim(N);
	}
	int isEmpty()
	{
		return N == 0;
	}
};

int main()
{
	MaxHeap mh(10);
	mh.insert(12);
	mh.insert(32);
	mh.insert(22);
	mh.insert(15);
	mh.insert(10);
	mh.insert(14);
	while (!mh.isEmpty())
	{
		cout << mh.getele() << endl;
	}
	mh.insert(13);
	mh.insert(13);mh.insert(13);
	mh.insert(13);
	while (!mh.isEmpty())
	{
		cout << mh.getele() << endl;
	}
	return 0;
}
