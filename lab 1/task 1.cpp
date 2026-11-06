#include<iostream>
using namespace std;
template<class T>
void selectionsort(T arr[], int size)
{
	for (int i = 0; i < size - 1; i++) {
		int smallindex = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[smallindex]) {
				smallindex = j;
			}
		}
		T temp = arr[i];
		arr[i] = arr[smallindex];
		arr[smallindex] = temp;
	}
}
template<class T>
void display(T arr[], int size)
{
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " "<<endl;
	}
}
int main() {
	int arr[5] = { 64,25,12,22,11 };
	int size = 5;
	cout << "before sorting" << endl;
	display(arr, size);
	selectionsort(arr, size);
	cout << "After sorting" << endl;
	display(arr, size);
	return 0;
}