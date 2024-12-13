#include <stdio.h>
#include <stdlib.h>
#include "museum.h"


int main() {
    Exhibit *exhibits = NULL;
    int count = 0;

    load_exhibits(&exhibits, &count, "exhibits.txt");

    while (1) {
        int choice;
	printf("\tКраевеческий музей города Кстово вас приветствует!\n");
        printf("1. Вывести экспонаты на экран\n");
        printf("2. Добавить новый экспонат\n");
        printf("3. Поиск экспоната\n");
        printf("4. Редактировать экспонат\n");
        printf("5. Удалить экспонат\n");
        printf("0. Выйти\n");
        printf("Введите номер:");
        scanf("%i", &choice);
        getchar();

        switch (choice) {
            case 1:
                list_exhibits(exhibits, count);
                break;
            case 2:
                add_exhibit(&exhibits, &count);
                break;
            case 3:
                search_exhibits(exhibits, count);
                break;
            case 4:
                edit_exhibit(exhibits, count);
                break;
            case 5:
                delete_exhibit(&exhibits, &count);
                break;
            case 0:
                save_exhibits(exhibits, count, "exhibits.txt");
                free(exhibits);
                exit(0);
            default:
                printf("Неверный выбор!\n");
        }
    }

    return 0;
}
