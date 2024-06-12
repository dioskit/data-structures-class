#include <stdio.h>
#include <stdbool.h>

#define MAXSIZE 100

double mean(double lowerLimit[], double upperLimit[], double freq[], int length, bool grouped) {
    double sum = 0, fre = 0;
    if (grouped) {
        for (int i = 0; i < length; i++) {
            double data = (lowerLimit[i] + upperLimit[i]) / 2;
            sum += (data * freq[i]);
            fre += freq[i];
        }
    }
    else {
        for (int i = 0; i < length; i++) {
            sum += (lowerLimit[i] * freq[i]);
            fre += freq[i];
        }
    }
    return sum / fre;
}

double mode(double lowerLimit[], double upperLimit[], double freq[], int length, bool grouped) {
    double maxFreq = -1;
    int modalIndex = -1;
    for (int i = 0; i < length; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            modalIndex = i;
        }
    }

    if (grouped) {
        if (modalIndex == 0 || modalIndex == length - 1) {
            return -1; // Indicate that mode cannot be computed for edge modal classes
        }
        double llModalClass = lowerLimit[modalIndex];
        double classWidth = upperLimit[0] - lowerLimit[0];
        double f1 = freq[modalIndex];
        double f0 = freq[modalIndex - 1];
        double f2 = freq[modalIndex + 1];
        
        return llModalClass + ((f1 - f0) / (2 * f1 - f0 - f2)) * classWidth;
    } 
    else {
        return lowerLimit[modalIndex];
    }
}

int main(void) {
    //test case for not grouped data
    double arr[10] = {1, 3, 5, 6, 78, 9, 90, 34, 56, 79};
    double freq[10] = {1, 5, 6, 7, 8, 9, 8, 0, 4, 12};
    int length = sizeof(arr) / sizeof(arr[0]);

    printf("%d is the length of the array\n", length);

    printf("%.2f is the mean\n", mean(arr, NULL, freq, length, false));
    double modeValue = mode(arr, NULL, freq, length, false);
    if (modeValue != -1) {
        printf("%.2f is the mode\n", modeValue);
    } 
    else {
        printf("Mode cannot be computed for the given data\n");
    }

    //test case for grouped data
    double lowerLimits1[] = {0, 10, 20, 30, 40};
    double upperLimits1[] = {10, 20, 30, 40, 50};
    double frequencies1[] = {5, 10, 15, 10, 5};
    int length1 = sizeof(lowerLimits1) / sizeof(lowerLimits1[0]);

    printf("Test case 1: Grouped data\n");
    printf("Mean: %.2f\n", mean(lowerLimits1, upperLimits1, frequencies1, length1, true));
    double modeValue1 = mode(lowerLimits1, upperLimits1, frequencies1, length1, true);
    if (modeValue1 != -1) {
        printf("Mode: %.2f\n", modeValue1);
    } else {
        printf("Mode cannot be computed for the given data\n");
    }
    printf("\n");

    // Test case 2: Another set of grouped data
    double lowerLimits2[] = {1, 2, 3, 4, 5};
    double upperLimits2[] = {2, 3, 4, 5, 6};
    double frequencies2[] = {2, 4, 6, 4, 2};
    int length2 = sizeof(lowerLimits2) / sizeof(lowerLimits2[0]);

    printf("Test case 2: Grouped data\n");
    printf("Mean: %.2f\n", mean(lowerLimits2, upperLimits2, frequencies2, length2, true));
    double modeValue2 = mode(lowerLimits2, upperLimits2, frequencies2, length2, true);
    if (modeValue2 != -1) {
        printf("Mode: %.2f\n", modeValue2);
    } else {
        printf("Mode cannot be computed for the given data\n");
    }
    printf("\n");


    return 0;
}
