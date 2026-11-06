#include<iostream>
using namespace std;
template<class T>
int linearsearch(T arr[], int size,T key)
{

	for (int i = 0; i < size ; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}
int main() {
	int arr[5] = { 64,25,12,22,11 };
	int size = 5;
	int key = 11;
	int result = linearsearch(arr, size, key);
	if (result != -1) {
		cout << "Result found at index"<<"=" << result << endl;
	}
	else
		cout << "Not found" << result << endl;
	return 0;
}