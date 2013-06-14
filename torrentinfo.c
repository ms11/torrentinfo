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
#include "torrentinfo.h"

int main(int argc, char** argv) {
    FILE* torrent = fopen(argv[2],"r");
    if(torrent == 0) {
        printf("Failed to open file: \"%s\"!\n",argv[2]);
        exit(100);
    }
    if(strcmp(argv[1],"info") == 0) {
        if(fpeek(torrent) != 'd') {
            printf("Invalid file: \"%s\"!\n",argv[2]);
            exit(100);
        }
        Dictionary* f = read_dict(torrent);
        dump(f);
        free_storage(f);
    }
    fclose(torrent);
    return 0;
}
