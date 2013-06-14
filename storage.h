/*
 * This file is part of torrentinfo.
 * 
 * torrentinfo is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * torrentinfo is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with torrentinfo.  If not, see <http://www.gnu.org/licenses/>.
 */
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
