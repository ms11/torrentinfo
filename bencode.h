#ifndef BENCODE_H_
#define BENCODE_H_
#include "storage.h"
#include <stdio.h>
Value* read_string(FILE* f);
void* read_any(FILE* f);
Dictionary* read_dict(FILE* f);
List* read_list(FILE* f);
Value* read_int(FILE* f);
char fpeek(FILE* f);
#endif
// vim: set ft=c :
