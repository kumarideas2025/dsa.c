#include<stdio.h>
#include<stdlib.h>

// Function to generate a random number between 0 and a
int random(int a) {
    int num = (rand() % (a + 1)); // Generate a random number
    return num;
}

// Recursive function that performs calculations based on random indices
int function(int n) {
    int i;
    if (n <= 0) { 
        return 0; // Base case: if n is 0 or negative, return 0
    } else {
        i = random(n - 1); // Get a random index
        printf("this\n"); // Print a message
        // Recursively call function with random index and remaining elements
        return function(i) + function(n - 1 - i);
    }
}

// Main function to execute the program
int main() {
    function(6); // Start the recursive function with n = 6
    return 0;
}
