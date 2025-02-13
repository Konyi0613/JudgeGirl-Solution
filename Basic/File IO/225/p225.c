#include <stdio.h>
#include <string.h>

struct person {
    unsigned int id;
    char name[32];
};

struct friends {
    unsigned id1;
    unsigned id2;
};

int getIndex(int num, struct person Person[], char *name) {
    for (int i = 0; i < num; i++)
        if (strcmp(Person[i].name, name) == 0)
            return i;
    return -1;
}

int main() {
    FILE *fin = fopen("friends", "rb");
    int num;
    fread(&num, 4, 1, fin);
    struct person Person[num];
    fread(Person, sizeof(struct person), num, fin);
    int pair_num;
    fread(&pair_num, 4, 1, fin);
    struct friends Friend[pair_num];
    fread(Friend, sizeof(struct friends), pair_num, fin);
    char name1[32];
    while (1) {
        scanf("%s", name1);
        if (strcmp(name1, "end") == 0)
            break;
        char name2[32];
        scanf("%s", name2);
        int id1 = getIndex(num, Person, name1);
        int id2 = getIndex(num, Person, name2);
        int flag = 0;
        for (int i = 0; i < pair_num && flag == 0; i++)
            if ((Friend[i].id1 == Person[id1].id && Friend[i].id2 == Person[id2].id) || 
            (Friend[i].id2 == Person[id1].id && Friend[i].id1 == Person[id2].id))
                flag = 1;
        if (flag == 1)
            printf("yes\n");
        else
            printf("no\n");
    }
    fclose(fin);
}