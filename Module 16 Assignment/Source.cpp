#include <iostream>
#include <time.h>
#include <ctime>
#include <ratio>
#include <chrono>
#include <unordered_set>
#include <fstream>
using namespace std;

bool SequentialSearch(int arr[100], int value)
{
	for (size_t i = 0; i < 100; i++)
	{
		if (arr[i] == value)
		{
			return true;
		}
	}
	return false;
}

int BinarySearch(int arr[100], int low, int high, int value)
{
	if (high >= low)
	{
		int mid = low + (high - low) / 2;

		if (arr[mid] == value)
		{
			return mid;
		}

		if (arr[mid] > value)
		{
			return BinarySearch(arr, low, mid - 1, value);
		}

		return BinarySearch(arr, mid + 1, high, value);
	}
	return -1;
}

int InterpolationSearch(int arr[100], int low, int high, int value)
{
	int pos;

	if (low <= high && value >= arr[low] && value <= arr[high])
	{
		pos = low + (((high - low) / (arr[high] - arr[low])) * (value - arr[low]));

		if (arr[pos] == value)
		{
			return pos;
		}

		if (arr[pos] < value)
		{
			return InterpolationSearch(arr, pos + 1, high, value);
		}

		if (arr[pos] > value)
		{
			return InterpolationSearch(arr, low, pos - 1, value);
		}
	}
	return -1;
}

int TernarySearch(int arr[100], int l, int r, int key)
{
	if (r >= l)
	{
		int mid1 = l + (r - l) / 3;
		int mid2 = r - (r - l) / 3;

		if (arr[mid1] == key)
		{
			return mid1;
		}
		if (arr[mid2] == key)
		{
			return mid2;
		}

		if (key < arr[mid1])
		{
			return TernarySearch(arr, l, mid1 - 1, key);
		}
		else if (key > arr[mid2])
		{
			return TernarySearch(arr, mid2 + 1, r, key);
		}
		else
		{
			return TernarySearch(arr, mid1 + 1, mid2 - 1, key);
		}
	}

	return -1;
}

//template <typename Iterator>
//void printContainer(Iterator begin, Iterator end)
//{
//	while (begin != end)
//	{
//		std::cout << *begin << std::endl;
//
//		begin++;
//	}
//}
//std::ostream& operator<<(ostream& out,chrono::duration<chrono::milliseconds> time) 
//{
//	return out << time;
//}
void LinearSearchTime(int arr[100])
{
	int time[10]{};
	double averageTime{};
	int totalTime{};

	for (size_t i = 0; i < 10; i++)
	{

		using namespace chrono;
		high_resolution_clock::time_point startTime = high_resolution_clock::now();
		SequentialSearch(arr, i + 1);
		high_resolution_clock::time_point endTime = chrono::high_resolution_clock::now();

		std::chrono::duration<double, std::nano> timeElapsed = endTime - startTime;

		//duration<milliseconds> timeElapsed = duration_cast<duration<milliseconds>> (endTime - startTime);
		cout << "Looking for value " << i + 1 << " took " << timeElapsed.count() << " nanoseconds" << endl;
		time[i] = timeElapsed.count();
	}

	for (int i = 0; i < 10; i++)
	{
		totalTime += time[i];
	}
	averageTime = totalTime / 10;
	cout << "Average time for Linear Search is " << averageTime << "nanoseconds" << endl;
}
int main()
{
	int arr[100]{};

	for (int i = 0; i < 100; i++)
	{
		int j = 0;
		do
		{
			arr[i] = rand() % 100;
			if (arr[i] != arr[j])
			{
				break;
			}
			j++;
		} while (arr[i] == arr[j]);

	}

	for (size_t i = 0; i < 100; i++)
	{
		cout << arr[i] << ", ";
	}

	/*std::unordered_set<int> set{};
	while (set.size() < 100)
	{
		set.insert(rand() % 100);
	}
	printContainer(set.begin(), set.end());*/


	LinearSearchTime(arr);

	return 0;
}