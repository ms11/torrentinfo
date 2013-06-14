#ifndef STORAGE_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define STORAGE_H_
#define DICT_BASE_SIZE 5
#define LIST_BASE_SIZE 5
#define clean_malloc(N) memset( malloc(N) , 0, N );
typedef struct {
    char type;
    int size;
    int count;
    char** keys;
    void** values;
} Dictionary;

typedef struct {
    char type;
    int size;
    int count;
    void** values;
} List;

typedef struct {
    char type; // s: string, i: int
    void* value;
} Value;

List* new_list();
Dictionary* new_dict();
void add_dict_item(char* key, void* value, Dictionary* dict);
void add_list_item(void* value, List* list);
void free_storage(void* storage);
void dump(void* storage);
void dump_list(List* list);
void dump_dict(Dictionary* dict);

#endif
// vim: set ft=c :
