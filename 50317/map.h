struct element{
    char key[25];
    int value;
};

struct map{
    int end;
    struct element elements[8005];
};
typedef struct map Map;

void initMap(Map *m);
void insert(Map *m, char key[], int value);
int delete(Map *m, char key[]);
int query(Map *m, char key[]);