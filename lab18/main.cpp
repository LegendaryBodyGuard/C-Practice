#include <iostream>

int a[] = {2, 8, 1, 7, 3};
int b[] = {};

void printArray(int a[], int size, int index);
void printReverseArray(int a[], int size, int index);
void reverseArray(int a[], int start, int end);
int sumArray(int a[], int size, int index);
int productArray(int a[], int size, int index);
int minArray(int a[], int size, int index);
int maxArray(int a[], int size, int index);

void printArray(int a[], int size, int index)
{
    std::cout << a[index] << " ";
    if (size > 1)
    {
        printArray(a, size - 1, index + 1);
    }
}

void printReverseArray(int a[], int size, int index)
{
    std::cout << a[index] << " ";
    if (size > 1)
    {
        printReverseArray(a, size - 1, index - 1);
    }
}

void reverseArray(int a[], int start, int end)
{
    //  012      432
    if (start < end)
    {
        int temp = a[start];
        a[start] = a[end];
        a[end] = temp;
        reverseArray(a, ++start, --end);
    }
}

int sumArray(int a[], int size, int index)
{
    if (index == size)
    {
        return 0;
    }
    // std::cout << "before recursive" << a[index] << std::endl;
    int sum = sumArray(a, size, index + 1);
    // std::cout << "A index is this" << a[index] << " ";
    // std::cout << "Sum" << sum << " \n\n";
    return a[index] + sum;
}

int productArray(int a[], int size, int index)
{
    if (index == size)
    {
        return 1;
    }
    // std::cout << "before recursive" << a[index] << std::endl;
    int product = productArray(a, size, index + 1);
    // std::cout << "A index is this" << a[index] << " ";
    // std::cout << "product" << product << " \n\n";
    return a[index] * product;
}

int minArray(int a[], int size, int index)
{
    if (size == 1)
    {
        return a[index];
    }
    return std::min(a[size - 1], minArray(a, size - 1, index));
}
int maxArray(int a[], int size, int index)
{
    if (size == 1)
    {
        return a[index];
    }
    return std::max(a[size - 1], maxArray(a, size - 1, index));
}

int main()
{
    std::cout << "Array a[] content in order:" << std::endl;
    printArray(a, 5, 0);
    std::cout << "Array a[] content in reverse:" << std::endl;
    printReverseArray(a, 5, 4);
    reverseArray(a, 0, 4);
    std::cout << "Reversing a[]" << std::endl;
    printArray(a, 5, 0);
    std::cout << "Summation of elements in a[]:" << std::endl;
    std::cout << sumArray(a, 5, 0) << std::endl;
    std::cout << "Product of element in a[]" << std::endl;
    std::cout << productArray(a, 5, 0) << std::endl;

    std::cout << "Minimum element in a[]" << std::endl;
    std::cout << minArray(a, 5, 0) << std::endl;
    std::cout << "Maximum element in a[]" << std::endl;
    std::cout << maxArray(a, 5, 0) << std::endl;
    return 0;
}
