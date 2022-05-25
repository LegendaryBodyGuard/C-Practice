#include <iostream>
#include <ctype.h>

const int SIZE = 30;
const int ROW = 4;

char title1[SIZE] = { "Data Structures In C++" };
char title2[SIZE] = { "Data   Structures		 In C++" };
char password[ROW][SIZE] = { "monkey", "MonnkeeY", "M8nnkeeY", "M8nnkeeY!" };

void splittedPrint(char arr[]);
void stringFlipCase(char arr[]);
void stringTrimNonAlphanumeric(char arr[]);
bool isValidPassword(char arr[]);

int main() {
    std::cout << "Splitting title1: ";
    splittedPrint(title1);

    std::cout << "\n\nSplitting title2: ";
    splittedPrint(title2);

    std::cout << "\nFlipping the case in title1: ";
    stringFlipCase(title1);

    std::cout << "\nTrimming non-alphanumeric characters in title1: ";
    stringTrimNonAlphanumeric(title1);

    std::cout << "\nTrimming non-alphanumeric characters in title2: ";
    stringTrimNonAlphanumeric(title1);
    std::cout << "\n\n";

    for (int i = 0; i < ROW; i++) {
        if (isValidPassword(password[i])) {
            std::cout << password[i] << " Accepted: ";
        }
        std::cout << "\n";
    }
}

void splittedPrint(char arr[]) {
    char character;
    int i = 0;
    while (arr[i]) {
        character = arr[i];
        if (isspace(character)) {
            character = '\0';
        }
        if (isupper(character)) {
            std::cout << "\n";
            std::cout << character;
        }
        else {
            putchar(character);
        }
        
        i++;
    }
}

void stringFlipCase(char arr[]) {
    char character;
    int i = 0;
    while (arr[i]) {
        character = arr[i];
        
        if (isupper(character)) {
            putchar(tolower(character));
        }
        else {
            putchar(toupper(character));
        }
        i++;
    }
}

void stringTrimNonAlphanumeric(char arr[]) {
    char character;
    int i = 0;
    while (arr[i]) {
        character = arr[i];

        if (isspace(character)) {
            character = '\0';
        }
        if (isalpha(character)) {
            putchar(character);
        }
        i++;
    }
}

bool isValidPassword(char arr[]) {
    bool boolean = true;
    int len = 0;
    int digit = 0;
    int lowerCase = 0;
    int upperCase = 0;
    int specialCase = 0;
    for (int i = 0; i < arr[i]; i++)
    {
        len++;
        if (isdigit(arr[i])) {
            digit++;

        }
        else if (islower(arr[i])) {
            lowerCase++;
        }
        else if (isupper(arr[i])) {
            upperCase++;
        }
        else if (ispunct(arr[i])) {
            specialCase++;
        }
    }
    if (len < 8) {
        std::cout << arr << " Not Accepted: Password must be at least 8 characters long.\n";
        boolean = false;
    }
    if (lowerCase == 0) {
        std::cout << arr << " Not Accepted: Password must at least include one lowercase alphabetic charcter.\n";
        boolean = false;
    }
    if (upperCase == 0) {
        std::cout << arr << " Not Accepted: Password must at least include one uppercase alphabetic charcter.\n";
        boolean = false;
    }
    if (digit == 0) {
        std::cout << arr << " Not Accepted: Password must at least include one digit.\n";
        boolean = false;
    }
    if (specialCase == 0) {
        std::cout << arr << " Not Accepted: Password must at least include one special charcter: " << "\n$ % &'()*+,-./:;<=>?@[\\]^_`{|}~\n";
        boolean = false;
    }
    return boolean;
}