#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "config/video.h"


// Fonction qui calcule la taille de la vidéo
float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
    // Bits par pixel pour l'image colorée (24 bits)
    float bitsPerPixel = 24;

    // Calcul de la taille des images colorées en bits
    float clrImage = w * h * bitsPerPixel * durationMovie * fps;
    // Calcul de la taille des crédits en bits (1 bit par pixel)
    float BImage = w * h * durationCredits * fps;

    // Taille totale en bits
    float sizeInBits = clrImage + BImage;

    float size;

    // Convertir la taille en fonction de l'unité demandée
    if (strcmp(unit, "bt") == 0) {
        size = sizeInBits; // Taille en bits
    } else if (strcmp(unit, "ko") == 0) {
        size = sizeInBits / 8 / 1024; // Convertir en kilooctets (1 Ko = 8 bits, 1 Ko = 1024 octets)
    } else if (strcmp(unit, "mo") == 0) {
        size = sizeInBits / 8 / 1024 / 1024; // Convertir en mégaoctets (1 Mo = 1024 Ko)
    } else if (strcmp(unit, "go") == 0) {
        size = sizeInBits / 8 / 1024 / 1024 / 1024; // Convertir en gigaoctets (1 Go = 1024 Mo)
    } else {
        // Si l'unité n'est pas reconnue, retourne -1
        return -1.0f;
    }

    return size; // Retourner la taille dans l'unité choisie
}

int main() {
    
    int w, h, durationMovie, durationCredits, fps;
    char unit[3];

    // Entrées utilisateur
    printf("Enter the width of the colored image (in pixels): ");
    scanf("%d", &w);
    printf("Enter the height of the colored image (in pixels): ");
    scanf("%d", &h);
    printf("Enter the duration of the color section of the movie (in seconds): ");
    scanf("%d", &durationMovie);
    printf("Enter the duration of the credits section (in seconds): ");
    scanf("%d", &durationCredits);
    printf("Enter the frames per second (fps) of the video: ");
    scanf("%d", &fps);
    printf("Enter the unit for the output value ('bt' for bits, 'ko' for kilobits, 'mo' for megabits, 'go' for gigabits): ");
    scanf("%s", unit);

    // Appeler la fonction pour calculer la taille de la vidéo
    float result = video(w, h, durationMovie, durationCredits, fps, unit);

    if (result != -1.0f) {
        // Afficher le résultat
        printf("The size of the video is: %.9f %s\n", result, unit);
    } else {
        // Si l'unité n'est pas valide
        printf("Invalid unit.\n");
    }

    return 0;
}
