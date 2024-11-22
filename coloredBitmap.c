#include <stdio.h>
#include <string.h>
#include "config/coloredBitmap.h"

float coloredBitmap(int w, int h, char* unit) {
    double result = w * h * 3;  // Size in bytes (3 bytes per pixel for RGB)

    // Conversion based on the unit
    if (strcmp(unit, "ko") == 0) {
        result /= 1024;  // Convert to kilobytes
    } else if (strcmp(unit, "mo") == 0) {
        result /= (1024 * 1024);  // Convert to megabytes
    } else if (strcmp(unit, "go") == 0) {
        result /= (1024 * 1024 * 1024);  // Convert to gigabytes
    } else if (strcmp(unit, "bt") == 0) {
        result *= 8;  // Convert to bits (1 byte = 8 bits)
    }

    return result;
}

int main() {
    int width, height;
    char unit[10];

    // Get user input for image dimensions
    printf("Enter the width of the colored image (in pixels): ");
    scanf("%d", &width);
    
    printf("Enter the height of the colored image (in pixels): ");
    scanf("%d", &height);
    
    // Get the unit for the result
    printf("Enter the unit for the output value ('bt' for bits, 'ko' for kilobytes, 'mo' for megabytes, 'go' for gigabytes): ");
    scanf("%s", unit);

    // Call the coloredBitmap function and print the result
    float result = coloredBitmap(width, height, unit);
    printf("The size of the colored image is: %.6f %s\n", result, unit);

    return 0;
}
