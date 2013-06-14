#include "bencode.h"
char fpeek(FILE* f) {
    char r = fgetc(f);
    fseek(f,-1,SEEK_CUR);
    return r;
}
Value* read_string(FILE* file) {
    printf("Reading string.\n");
    char* numbuff = clean_malloc(sizeof(char)*23);
    int numi = 0;
    for(;;) {
        if(feof(file)) {
            free(numbuff);
            return 0;
        }
        char r = fgetc(file);
        if((r >= '0' && r <= '9') || (r == '-' && numi == 0)) {
            numbuff[numi++] = r;
        }else if(r == ':') {
            int n = strtol(numbuff,NULL,10);
            char* str = clean_malloc(sizeof(char)*n+1);
            fread(str,sizeof(char),n,file);
            Value* ret = malloc(sizeof(Value));
            ret->type = 's';
            ret->value = str;
            free(numbuff);
            return ret;
        }
    }
    free(numbuff);
    return 0;
}

void* read_any(FILE* file) {
    printf("Reading any.\n");
    char r = fpeek(file);
    if((r >= '0' && r <= '9') || r == '-')
        return read_string(file);
    else if(r == 'd')
        return read_dict(file);
    else if(r == 'l')
        return read_list(file);
    else if(r == 'i')
        return read_int(file);
    return 0;
}

Dictionary* read_dict(FILE* file) {
    printf("Reading dict.\n");
    if(fgetc(file) != 'd') return 0;
    Dictionary* ret = new_dict();
    for(;;) {
        if(feof(file))
            return 0;
        char r = fgetc(file);
        if( r == 'e') {
            return ret;
        }else{
            fseek(file,-1,SEEK_CUR);
            Value* key = read_string(file);
            void* val = read_any(file);
            add_dict_item((char*)key->value,val,ret);
            free(key);
        }
    }
    free_storage(ret);
    return 0;
}

List* read_list(FILE* file) {
    printf("Reading list.\n");
    if(fgetc(file) != 'l') return 0;
    List* ret = new_list();
    for(;;) {
        if(feof(file))
            return 0;
        char r = fgetc(file);
        if( r == 'e') {
            return ret;
        }else{
            fseek(file,-1,SEEK_CUR);
            void* val = read_any(file);
            add_list_item(val,ret);
        }
    }
    free_storage(ret);
    return 0;
}
Value* read_int(FILE* file) {
    printf("Reading int.\n");
    char* numbuff = clean_malloc(sizeof(char)*23);
    int numi = 0;
    if(fgetc(file) != 'i') return 0;
    for(;;) {
        if(feof(file)) {
            free(numbuff);
            return 0;
        }
        char r = fgetc(file);
        if((r >= '0' && r <= '9') || (r == '-' && numi == 0)) {
            numbuff[numi++] = r;
        }else if(r == 'e') {
            Value* ret = malloc(sizeof(Value));
            int* val = malloc(sizeof(int));
            *val = strtol(numbuff,NULL,10);
            ret->type = 'i';
            ret->value = val;
            free(numbuff);
            return ret;
        }
    }
    free(numbuff);
    return 0;
}
