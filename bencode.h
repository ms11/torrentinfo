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
