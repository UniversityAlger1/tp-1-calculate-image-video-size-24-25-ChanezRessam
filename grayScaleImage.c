#include <stdio.h>
#include "config/grayScaleImage.h"

// Function to calculate the size of a grayscale Bitmap image in bytes
float grayScaleImage(int w, int h) {
    // Each pixel is 1 byte, so size is width * height
    float size = w * h * 1;
    return size;
}

int main() {
    int width, height;

    
    printf("Enter the width of the grayscale image (in pixels): ");
    scanf("%d", &width);

    printf("Enter the height of the grayscale image (in pixels): ");
    scanf("%d", &height);

    // Calculate the size
    float imageSize = grayScaleImage(width, height);

    // Display the result
    printf("The size of the grayscale image is: %.2f bytes\n", imageSize);

    return 0;
}
