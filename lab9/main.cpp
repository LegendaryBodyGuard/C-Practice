#include <iostream>
#include <vector>

const int SIZE = 10;

int a[SIZE] = { 5,7,-2,8,11,-9,4,6,12,-1 };
int b[SIZE] = { 4,16,9,-2,1,1,-2,9,16,4 };

std::vector<int> vec1;
std::vector<int> vec2;
std::vector<int> vec3;

void initVector(std::vector<int>& vec, int arr[], int size);
void printVector(std::vector<int>& vec);
int minVector(std::vector<int>& vec);
int productVector(std::vector<int>& vec);
void copyVector(std::vector<int>& vec, std::vector<int>& vec2);
void greaterVector(std::vector<int>& vec, std::vector<int>& vec2, std::vector<int>& vec3);
bool isPalindrome(std::vector<int>& vec);
void updateLast(std::vector<int>& vec, int value);

int main() {
	std::cout << "initial size of vec1: " << vec1.size() << std::endl;
	initVector(vec1, a, SIZE);
	std::cout << "size of vec1 after initialization: " << vec1.size() << std::endl;
	initVector(vec2, b, SIZE);
	std::cout << "Vec1 content: "; printVector(vec1);
	std::cout << "\nVec2 content: "; printVector(vec2);
	std::cout << "\nminimum of a[]: " << minVector(vec1) << std::endl;
	std::cout << "product of a[]: " << productVector(vec1) << std::endl;
	std::cout << "copy vec1 to vec3: ";
	copyVector(vec1, vec3);
	printVector(vec3);
	vec3.clear();
	std::cout << "\nCollect larger elements from vec1 and vec2 to vec3: ";
	greaterVector(vec1, vec2, vec3);
	printVector(vec3);
	if (isPalindrome(vec1)) {
		std::cout << "\nvec1 " << "is a Palindrome" << std::endl;
	}
	else {
		std::cout << "\nvec1 " << "is not a Palindrome" << std::endl;
	}
	if (isPalindrome(vec2)) {
		std::cout << "vec2 " << "is a Palindrome" << std::endl;
	}
	else {
		std::cout << "vec2 " << "is not a Palindrome" << std::endl;
	}
	updateLast(vec3, 21);
	std::cout << "Updated the last element of vec3: ";
	printVector(vec3);
}

void initVector(std::vector<int>& vec, int arr[], int size) {
	for (int i = 0; i < size; i++) {
		vec.push_back(arr[i]);
	}
}

void printVector(std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		std::cout << vec[i];
		if (i < vec.size()-1) {
			std::cout << ", ";
		}
	}
}

int minVector(std::vector<int>& vec) {
	int small = vec[0];
	for (int i = 0; i < vec.size(); i++)
	{
		// std::cout << vec[i] << " ";
		if (vec[i] < small) {
			small = vec[i]; 
		}
	}
	return small;
}

int productVector(std::vector<int>& vec) {
	int product = 1;
	for (int i = 0; i < vec.size(); i++) {
		product = product * vec[i];
	}
	return product;
}

void copyVector(std::vector<int>& vec, std::vector<int>& vec2) {
	vec2 = vec1;
}

void greaterVector(std::vector<int>& vec, std::vector<int>& vec2, std::vector<int>& vec3) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] > vec2[i]) {
			vec3.push_back(vec[i]);
		}
		else {
			vec3.push_back(vec2[i]);
		}
	}
}

bool isPalindrome(std::vector<int>& vec) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] != vec[vec.size() - i - 1]) {

			return false;
		}
	}
	return true;
}

void updateLast(std::vector<int>& vec, int value) {
	vec.pop_back();
	vec.push_back(value);
}
