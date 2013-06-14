#include "storage.h"

List* new_list() {
    printf("Alloc list\n");
    List* ret = malloc(sizeof(List));
    ret->type = 'l';
    ret->size = LIST_BASE_SIZE;
    ret->count = 0;
    ret->values = clean_malloc(sizeof(void*)*LIST_BASE_SIZE);
    return ret;
}
Dictionary* new_dict() {
    printf("Alloc dict\n");
    Dictionary* ret = malloc(sizeof(Dictionary));
    ret->type = 'd';
    ret->size = DICT_BASE_SIZE;
    ret->count = 0;
    ret->values = clean_malloc(sizeof(void*)*DICT_BASE_SIZE);
    ret->keys = clean_malloc(sizeof(char*)*DICT_BASE_SIZE);
    return ret;
}
Value* new_value() {
    printf("Alloc value\n");
    Value* ret = malloc(sizeof(Value));
    return ret;
}

void add_dict_item(char* key, void* value, Dictionary* dict) {
    if(dict->count == dict->size) {
        dict->size++;
        void** nvals = clean_malloc(sizeof(void*)*dict->size);
        char** nkeys = clean_malloc(sizeof(char*)*dict->size);
        memcpy(nvals, dict->values, sizeof(void*)*dict->count);
        memcpy(nkeys, dict->keys, sizeof(void*)*dict->count);
        free(dict->values);
        free(dict->keys);
        dict->values = nvals;
        dict->keys = nkeys;
    }
    dict->keys[dict->count] = key;
    dict->values[dict->count] = value;
    dict->count++;
}

void add_list_item(void* value, List* list) {
    if(list->count == list->size) {
        list->size++;
        void** nvals = clean_malloc(sizeof(void*)*list->size);
        memcpy(nvals, list->values, sizeof(void*)*list->count);
        free(list->values);
        list->values = nvals;
    }
    list->values[list->count] = value;
    list->count++;
}

void free_storage(void* storage) {
    switch(*(char*)storage) {
        case 'd': {
            printf("free dict\n");
            Dictionary* dict = (Dictionary*)storage;
            for(int i = 0; i < dict->count; i++) {
                free_storage(dict->values[i]);
                free(dict->keys[i]);
            }
            free(dict->values);
            free(dict->keys);
            free(dict);
            break;
        }
        case 'l': {
            printf("free list\n");
            List* list = (List*)storage;
            for(int i = 0; i < list->count; i++) {
                free_storage(list->values[i]);
            }
            free(list->values);
            free(list);
            break;
        }
        default: {
            printf("free val\n");
            Value* val = (Value*)storage;
            free(val->value);
            free(val);
        }
    }
}

void dump(void* storage) {
    switch(*(char*)storage) {
        case 'd': {
            Dictionary* dict = (Dictionary*)storage;
            dump_dict(dict);
            break;
        }
        case 'l': {
            List* list = (List*)storage;
            dump_list(list);
            break;
        }
        case 's': {
            Value* val = (Value*)storage;
            printf("%s", (char*)val->value);
            break;
        }
        case 'i': {
            Value* val = (Value*)storage;
            printf("%d", *(int*)val->value);
            break;
        }
    }
}

void dump_list(List* list) {
    printf("list:\n");
    for(int i = 0; i < list->count; i++) {
        dump(list->values[i]);
    }
    printf("end\n");
}
void dump_dict(Dictionary* dict) {
    printf("list:\n");
    for(int i = 0; i < dict->count; i++) {
        printf("%s:\n", dict->keys[i]);
        dump(dict->values[i]);
        printf("end\n");
    }
    printf("end\n");
}
