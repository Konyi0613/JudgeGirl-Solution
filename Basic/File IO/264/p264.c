#include <stdio.h>
 
int main() {
    char file_name[201];
    scanf("%s", file_name);
    FILE *fp = fopen(file_name, "rb");
    int num;
    fread(&num, 4, 1, fp);
    int frequency[65537] = {0};
    short int input;
    fread(&input, 2, 1, fp);
    int max = input + 32768;
    while (!feof(fp)) {
        frequency[input + 32768]++;
        if (frequency[input + 32768] > frequency[max] || 
            (frequency[input + 32768] == frequency[max]) && input + 32768 > max)
            max = input + 32768;
        fread(&input, 2, 1, fp);
    }
    printf("%d\n%d\n", max - 32768, frequency[max]);
    fclose(fp);
}