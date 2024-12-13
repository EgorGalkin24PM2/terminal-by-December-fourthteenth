#ifndef MUSEUM_H
#define MUSEUM_H

typedef struct {
    char name[100];
    int year;
    char material[50];
} Exhibit;

void load_exhibits(Exhibit **exhibits, int *count, const char *filename);
void save_exhibits(Exhibit *exhibits, int count, const char *filename);
void add_exhibit(Exhibit **exhibits, int *count);
void edit_exhibit(Exhibit *exhibits, int count);
void delete_exhibit(Exhibit **exhibits, int *count);
void list_exhibits(Exhibit *exhibits, int count);
void search_exhibits(Exhibit *exhibits, int count);

#endif 
