#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "museum.h"

void load_exhibits(Exhibit **exhibits, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        *count = 0;
        *exhibits = NULL;
        return;
    }

    fscanf(file, "%i\n", count);
    *exhibits = malloc(sizeof(Exhibit) * (*count));
    for (int i = 0; i < *count; i++) {
        fgets((*exhibits)[i].name, sizeof((*exhibits)[i].name), file);
        (*exhibits)[i].name[strcspn((*exhibits)[i].name, "\n")] = 0; // лишаемся бесконечного потока текста +0
        fscanf(file, "%i\n", &(*exhibits)[i].year);
        fgets((*exhibits)[i].material, sizeof((*exhibits)[i].material), file);
        (*exhibits)[i].material[strcspn((*exhibits)[i].material, "\n")] = 0; // оно же
    }
    fclose(file);
}

void save_exhibits(Exhibit *exhibits, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    fprintf(file, "%i\n", count);
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s\n%i\n%s\n", exhibits[i].name, exhibits[i].year, exhibits[i].material);
    }
    fclose(file);
}

void add_exhibit(Exhibit **exhibits, int *count) {
    *exhibits = realloc(*exhibits, sizeof(Exhibit) * (*count + 1));
    printf("Введите название:");
    fgets((*exhibits)[*count].name, sizeof((*exhibits)[*count].name), stdin);
    (*exhibits)[*count].name[strcspn((*exhibits)[*count].name, "\n")] = 0; // (ук. на массив)[ук на переменную каунт].ук на имя экспоната[указатель на первый символ имени приравниваем к пустоте, чтобы сплошняком тескт не лился]
    printf("Введите год создания: ");
    scanf("%i", &(*exhibits)[*count].year);
    getchar();
    printf("Введите материал: ");
    fgets((*exhibits)[*count].material, sizeof((*exhibits)[*count].material), stdin);
    (*exhibits)[*count].material[strcspn((*exhibits)[*count].material, "\n")] = 0; // то же самое =)

    (*count)++;
}

void edit_exhibit(Exhibit *exhibits, int count) {
    char name[100];
    printf("Введите название экспоната для редактирования: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(exhibits[i].name, name) == 0) {
            printf("Введите новый год создания: ");
            scanf("%i", &exhibits[i].year);
            getchar();
            printf("Введите новый материал: ");
            fgets(exhibits[i].material, sizeof(exhibits[i].material), stdin);
            exhibits[i].material[strcspn(exhibits[i].material, "\n")] = 0;
            return;
        }
    }
    printf("Экспонат не найден.\n");
}

void delete_exhibit(Exhibit **exhibits, int *count) {
    char name[100];
    printf("Введите название экспоната для удаления: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < *count; i++) {
        if (strcmp((*exhibits)[i].name, name) == 0) {
            for (int j = i; j < *count - 1; j++) {
                (*exhibits)[j] = (*exhibits)[j + 1];
            }
            *exhibits = realloc(*exhibits, sizeof(Exhibit) * (--(*count)));
            return;
        }
    }
    printf("Экспонат не найден.\n");
}

void list_exhibits(Exhibit *exhibits, int count) {
    printf("Список экспонатов:\n");
    for (int i = 0; i < count; i++) {
        printf("\nНазвание: %s\nГод: %i\nМатериал: %s\n\n", exhibits[i].name, exhibits[i].year, exhibits[i].material);
    }
}

void search_exhibits(Exhibit *exhibits, int count) {
    char name[100];
    printf("Введите название экспоната для поиска: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    printf("Результаты поиска:\n");
    for (int i = 0; i < count; i++) {
        if (strstr(exhibits[i].name, name)) {
            printf("/nНазвание: %s\nГод: %i\nМатериал: %s\n\n", exhibits[i].name, exhibits[i].year, exhibits[i].material);
        }
    }
}
