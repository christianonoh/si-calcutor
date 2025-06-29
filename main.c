#include "include/input_utils.h"
#include <stdio.h>

float calculateSI(float P, float R, float T);
float calculateP(float SI, float R, float T);
float calculateR(float SI, float P, float T);
float calculateT(float SI, float P, float R);
int printHeader(int choice);

int main() {
    int choice;
    float P, R, T, SI;

    printf("=== Simple Interest Calculator ===\n");

    while (1) {
        printf("\nWhat would you like to calculate?\n");
        printf("1. Interest (SI)\n");
        printf("2. Principal (P)\n");
        printf("3. Rate (R)\n");
        printf("4. Time (T)\n");
        printf("0. Quit\n");

        choice = get_int("Enter your choice (0-4): ");

        switch(choice) {
            case 1:
                printHeader(choice);
                P = get_float("Enter Principal (P): ");
                R = get_float("Enter Rate (R): ");
                T = get_float("Enter Time (T): ");
                SI = calculateSI(P, R, T);
                printf("Simple Interest (SI) = %.2f\n", SI);
                break;

            case 2:
                printHeader(choice);
                SI = get_float("Enter Interest (SI): ");
                R = get_float("Enter Rate (R): ");
                T = get_float("Enter Time (T): ");
                P = calculateP(SI, R, T);
                printf("Principal (P) = %.2f\n", P);
                break;

            case 3:
                printHeader(choice);
                SI = get_float("Enter Interest (SI): ");
                P = get_float("Enter Principal (P): ");
                T = get_float("Enter Time (T): ");
                R = calculateR(SI, P, T);
                printf("Rate (R) = %.2f%%\n", R);
                break;

            case 4:
                printHeader(choice);
                SI = get_float("Enter Interest (SI): ");
                P = get_float("Enter Principal (P): ");
                R = get_float("Enter Rate (R): ");
                T = calculateT(SI, P, R);
                printf("Time (T) = %.2f years\n", T);
                break;

            case 0:
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please enter a number between 0 and 4.\n");
        }
    }

    return 0;
}

// Function definitions
float calculateSI(float P, float R, float T) {
    return (P * R * T) / 100;
}

float calculateP(float SI, float R, float T) {
    return (SI * 100) / (R * T);
}

float calculateR(float SI, float P, float T) {
    return (SI * 100) / (P * T);
}

float calculateT(float SI, float P, float R) {
    return (SI * 100) / (P * R);
}

int printHeader(int choice){
    switch(choice) {
        case 1:
            printf("Calculating Simple Interest (SI)\n");
            break;
        case 2:
            printf("Calculating Principal (P)\n");
            break;
        case 3:
            printf("Calculating Rate (R)\n");
            break;
        case 4:
            printf("Calculating Time (T)\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
    return 0;
}