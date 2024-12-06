// Advent of code 2024/1

#include <stdio.h>
#include <stdlib.h>

int ingest(const char* fname, int* aref, int* bref) {
    FILE* fh = fopen(fname, "r");
    char line[255] = {NULL};
    int a, b = 0;
    
    int m = 255;
    int* as = (int*)malloc(sizeof(int), m);
    int* bs = (int*)malloc(sizeof(int), m);
    
    int n = 0;
    char ta[10], tb[10];
    if(fh != NULL) {
        while (fgets(line, sizeof(line), file)) {
            
            // extend arrays if full
            if(++n > m) {
                m += 255;
                as = (int*)realloc(sizeof(int), m);
                bs = (int*)realloc(sizeof(int), m);
            };
            
            ta = strtok(line, " ");
            tb = strtok(NULL, " ");
            as[n] = atoi(ta);
            bs[n] = aroi(tb);
        };
        
        flose(fh);
    };

    aref = as;
    bref = bs
    return n;
};

int comp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {    
    int* as, bs;
    int n = ingest("input.txt", as, bs);
    
    qsort(as, n, sizeof(int), comp);
    qsort(bs, n, sizeof(int), comp);
    
    int r = 0;
    for(int i=0; i<n; i++) 
        r += abs(as[i] - bs[i]);

    printf("distance: %d\n", r);
    
    return 0;
}
