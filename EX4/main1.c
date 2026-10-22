#include <stdio.h>

int main() {
    FILE *fp;

    // Part 1: Definition and Writing (寫入二進位檔案)
    int a[] = {0, 1, 2};
    char b[] = "ABC"; 
    float c[] = {1.1, 1.2, 1.3}; 

    // Explicitly define sizes for fwrite/fread
    size_t sizeA = sizeof(a); 
    size_t sizeB = sizeof(b);
    size_t sizeC = sizeof(c); 

    // Open for binary writing
    fp = fopen("a.bin", "wb"); 
    if (fp == NULL) {
        perror("Error opening file for writing");
        return 1;
    }
    
    // Write arrays
    fwrite(a, sizeA, 1, fp); 
    fwrite(b, sizeB, 1, fp); 
    fwrite(c, sizeC, 1, fp); 
    fclose(fp);

    // Part 2: Reading (讀取二進位檔案)
    // Create new arrays with matching types and sizes to read into
    int ra[3];
    char rb[4]; 
    float rc[3];

    // Open for binary reading
    fp = fopen("a.bin", "rb");
    if (fp == NULL) { 
        perror("Error opening file for reading");
        return 1;
    }

    // Read arrays
    fread(ra, sizeA, 1, fp); 
    fread(rb, sizeB, 1, fp); 
    fread(rc, sizeC, 1, fp); 
    fclose(fp);

    // Part 3: Output (輸出內容)
    // Print read arrays to match the target output format
    for (int i = 0; i < 3; i++) {
        printf("%d ", ra[i]);
    }
    printf("\n");

    printf("%s\n", rb);

    for (int i = 0; i < 3; i++) {
        printf("%.6f ", rc[i]);
    }
    printf("\n");

    return 0;
}
