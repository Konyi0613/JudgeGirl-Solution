#include <stdio.h>

typedef struct {
    char name[20];
    int id;
    char phone[10];
    float grade[4];
    int birth_year;
    int birth_month;
    int birth_day;
} Student;

int main() {
    char input_name[81], output_name[81];
    scanf("%s%s", input_name, output_name);
    FILE *fin = fopen(input_name, "rb");
    FILE *fout = fopen(output_name, "w");
    Student buffer;
    fprintf(fout, "<table border=\"1\">\n<tbody>\n");
    while (fread(&buffer, sizeof(Student), 1, fin) != 0) {
        fprintf(fout, "<tr>\n");
        fprintf(fout, "<td>%s</td>\n", buffer.name);
        fprintf(fout, "<td>%d</td>\n", buffer.id);
        fprintf(fout, "<td>%s</td>\n", buffer.phone);
        fprintf(fout, "<td>%f, %f, %f, %f</td>\n", buffer.grade[0], buffer.grade[1], buffer.grade[2], buffer.grade[3]);
        fprintf(fout, "<td>%d, %d, %d</td>\n", buffer.birth_year, buffer.birth_month, buffer.birth_day);
        fprintf(fout, "</tr>\n");
    }
    fprintf(fout, "</tbody>\n</table>\n");
    fclose(fin);
    fclose(fout);
}