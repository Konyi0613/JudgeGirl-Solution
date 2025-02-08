#define MAXLEN 105
#define SIZERATE 10
 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
typedef struct hash_element{
    int size;
    int data_num;
    char (*data)[MAXLEN];
}Hash_element;
 
typedef struct hash_table{
    int size;
    Hash_element *data; //array of hash element
}Hash_table;
 
void initiate_hashtable(Hash_table *table, const int size);
void initiate_element(Hash_element* element);
void add_hash(Hash_table *table, char const *element);
void free_hashtable(Hash_table* table);
 
int hash_value(const char *data, const int size);
int get_element(const Hash_table table, char const *target);
 
int main(){
    int size, data_num, query;
    scanf("%d%d%d", &size, &data_num, &query);
 
    Hash_table table;
    initiate_hashtable(&table, size);
 
    for(int i = 0; i < data_num; i++){
        char input[MAXLEN];
        scanf("%s", input);
 
        add_hash(&table, input);
    }
 
    for(int i = 0; i < query; i++){
        char question[MAXLEN];
        scanf("%s", question);
 
        int index = get_element(table, question);
        printf("%d\n", index);
    }
 
 
    free_hashtable(&table);
 
    return 0;
}
 
void initiate_hashtable(Hash_table *table, const int size){
    table->data = (Hash_element*)malloc(sizeof(Hash_element) * size);
    table->size = size;
 
    //init element
    for(int i = 0; i < size; i++){
        initiate_element(&table->data[i]);
    }
 
    return ;
}
 
void initiate_element(Hash_element* element){
    element->size = SIZERATE;
    element->data_num = 0;
    element->data = (char (*)[MAXLEN])malloc(sizeof(char [MAXLEN]) * element->size);
 
    return;
}
 
int hash_value(const char *data, const int size){
    int len = strlen(data);
 
    int value = 0;
    for(int i = 0; i < len; i++){
        if(isdigit(data[i]))
            value += data[i] - '0';
        else if(isalpha(data[i]))
            value += data[i];
        value %= size;
    }
 
    return value % size;
}
 
void add_hash(Hash_table *table, char const *element){
    int index = hash_value(element, table->size);
 
    //add to index
    //expand if not enough space
    if(table->data[index].size == table->data[index].data_num){
        table->data[index].size += SIZERATE;
        table->data[index].data = (char (*)[MAXLEN])realloc(table->data[index].data, 
                                    sizeof(char[MAXLEN]) * table->data[index].size);
    }
 
    strcpy(table->data[index].data[table->data[index].data_num++], element);
 
    return;
}
 
void free_hashtable(Hash_table* table){
    for(int i = 0; i < table->size; i++)
        free(table->data[i].data);
    free(table->data);
 
    return;
}
 
int get_element(const Hash_table table, char const *target){
    int index = hash_value(target, table.size);
 
    for(int i = 0; i < table.data[index].data_num; i++){
        if(strcmp(target, table.data[index].data[i]) == 0)
            return index;
    }
 
    return -1;
}