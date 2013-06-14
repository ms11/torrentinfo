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
