#include <iostream>

const int SIZE = 10;

int a[SIZE] = { 5,7,-2,8,11,-9,4,6,12,-1 };
int b[SIZE] = { 4,16,9,-2,1,14,-4,8,10,0 };
int c[SIZE] = {};

void printArray(int arr[], int size);
int minArray(int arr[], int size);
int maxArray(int arr[], int size);
int sumArray(int arr[], int size);
int productArray(int arr[], int size);
void copyArray(int arr[], int arr2[], int size);
void greaterArray(int arr[], int arr2[], int arr3[], int size);

int main() {
	std::cout << "minimum of a[]: " << minArray(a, SIZE) << std::endl;
	std::cout << "maximum of a[]: " << maxArray(a, SIZE) << std::endl;
	std::cout << "sum of a[]: " << sumArray(a, SIZE) << std::endl;
	std::cout << "product of a[]: " << productArray(a, SIZE) << std::endl;
	std::cout << "copy a[] to c[]: "; 
	copyArray(a, b, SIZE);
	printArray(b, SIZE);
	std::cout << "\nCollect larger elements from a[] and b[] to c[]: "; 
	greaterArray(a, b, c, SIZE);
	printArray(c, SIZE);
}

void printArray(int arr[], int size) {
	for (int i = 0; i <= size; i++) {
		std::cout << arr[i];
		if (i < size) {
			std::cout << ", ";
		}
	}
}

int minArray(int arr[], int size) {
	int small = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < small) {
			small = arr[i];
		}
	}
	return small;
}

int maxArray(int arr[], int size) {
	int max = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	return max;
}

int sumArray(int arr[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum = sum + arr[i];
	}
	return sum;
}

int productArray(int arr[], int size) {
	int product = 1;
	for (int i = 0; i < size; i++) {
		product = product * arr[i];
	}
	return product;
}

void copyArray(int arr[], int arr2[], int size) {
	for (int i = 0; i < size; i++) {
		arr2[i] = arr[i];
	}
}

void greaterArray(int arr[], int arr2[], int arr3[], int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] > arr2[i]) {
			arr3[i] = arr[i];
		}
		else {
			arr3[i] = arr2[i];
		}
	}
}