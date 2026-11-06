#include<iostream>
using namespace std;
template<class T>
int binarysearch(T arr[], int size, T key)
{
	int low = 0;
	int high = size - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] == key) {
			return mid;
		}
		else if (arr[mid] < key) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
		return -1;
	
}
int main() {
	int arr[5] = { 64,25,12,22,11 };
	int size = 5;
	int key = 12;
	int result = binarysearch(arr, size, key);
	if (result != -1) {
		cout << "Result found at index" << "=" << result << endl;
	}
	else
		cout << "Not found" << result << endl;
	return 0;
}