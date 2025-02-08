#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

enum Operatar
    {add,sub,mul,DIV,mod,eql,noteql,smaller,larger,smallereql,largereql};
enum Satement
    {STOP,IF,GOTO,PRINT,ASSIGN};

#define MAXLENGTH 80
typedef struct variable{
    char name[MAXLENGTH];
    int value;
} Variable;

#define VAR 100
typedef struct variableSet{
    Variable variables[VAR];
    char *varNameTable[VAR];
} VariableSet;

typedef struct statement{
    int code;
    int opd1,opd2,compopr;
    int gotoline;
    int target;
} Statement;

int find(char *string,char *table[]){
    int index = 0;
    while(table[index] != NULL){
        if(strcmp(string,table[index]) == 0)
            return index;
        index++;
    }
    return -1;
}

int findOprCode(char *name){
    char *operators[] = {"+","-","*","/","%","==","!=","<",">","<=",">=",NULL};
    int code = find(name,operators);
    if(code == -1)
        exit(-1);
    return code;
}

int findVariable(char *name, VariableSet *variableSet){
    int index = find(name,variableSet->varNameTable);
    if(index == -1)
        exit(-1);
    return index;
}

void processIF(Statement *statement,VariableSet *variableSet){
    char gotoStr[MAXLENGTH];
    char opd[MAXLENGTH], opr[MAXLENGTH];
    statement->code = IF;
    scanf("%s", opd);
    statement->opd1 = findVariable(opd,variableSet);
    scanf("%s", opr);
    statement->compopr = findOprCode(opr);
    scanf("%s", opd);
    statement->opd2 = findVariable(opd,variableSet);
    scanf("%s", gotoStr);
    assert(strcmp(gotoStr,"GOTO") == 0);
    scanf("%d",&(statement->gotoline));
}

void processASSIGN(Statement *statement, char *first, VariableSet *variableSet){
    char opd[MAXLENGTH], opr[MAXLENGTH];
    statement->target = findVariable(first,variableSet);
    char assignStr[MAXLENGTH];
    scanf("%s",assignStr);
    assert(strcmp(assignStr,"=") == 0);
    scanf("%s",opd);
    statement->opd1 = findVariable(opd,variableSet);
    scanf("%s",opr);
    statement->compopr = findOprCode(opr);
    scanf("%s",opd);
    statement->opd2 = findVariable(opd,variableSet);
}

void processCode(VariableSet *variableSet, Statement statements[]){
    char first[MAXLENGTH], opd[MAXLENGTH];
    char *firstTable[] = {"STOP","IF","GOTO","PRINT",NULL};
    Statement *statement = &(statements[2]);
    while(scanf("%s",first) != EOF){
        int firstType = find(first,firstTable);
        switch(firstType){
            case GOTO:
                statement->code = GOTO;
                scanf("%d",&(statement->gotoline));
                break;
            case STOP:
                statement->code = STOP;
                break;
            case IF:
                statement->code = IF;
                processIF(statement,variableSet);
                break;
            case PRINT:
                statement->code = PRINT;
                scanf("%s",opd);
                statement->target = findVariable(opd,variableSet);
                break;
            default:
                statement->code = ASSIGN;
                processASSIGN(statement,first,variableSet);
                break;
        }
        statement++;
    }
}

int compare(int operand1,int operand2,int operator){
    switch(operator){
        case eql:
            return (operand1 == operand2);
        case noteql:
            return (operand1 != operand2);
        case smaller:
            return (operand1 < operand2);
        case larger:
            return (operand1 > operand2);
        case smallereql:
            return (operand1 <= operand2);
        case largereql:
            return (operand1 >= operand2);
        default:
            printf("invalid comp %d\n",operator);
            exit(-1);
    }
}

int arithemetic(int operand1, int operand2,int operator){
    switch(operator){
        case add:
            return (operand1 + operand2);
        case sub:
            return (operand1 - operand2);
        case mul:
            return (operand1 * operand2);
        case DIV:
            return (operand1 / operand2);
        case mod:
            return (operand1 % operand2);
        default:
            printf("invalid comp %d\n",operator);
            exit(-1);
    }
}

void runCode(VariableSet *variableSet, Statement statements[]){
    int line = 2;
    Statement *statement = &(statement[line]);
    Variable *vars = variableSet->variables;
    while(statement->code != STOP){
        switch(statement->code){
        case IF:
            if(compare(vars[statement->opd1].value,vars[statement->opd2].value,statement->compopr))
                line = statement->gotoline;
            else
                line++;
            break;
        case GOTO:
            line = statement->gotoline;
            break;
        case ASSIGN:
            vars[statement->target].value = arithemetic(vars[statement->opd1].value,vars[statement->opd2].value,statement->compopr);
            line++;
            break;
        case PRINT:
            printf("%d\n",vars[statement->target].value);
            line++;
            break;
        default:
            printf("invalid code %d\n",statement->code);
            exit(-1);
        }
        statement = &(statements[line]);
    }
}

void readVariable(VariableSet *variableSet){
    int count = 0;
    char name[MAXLENGTH];
    scanf("%s",name);
    while(strcmp(name,"END") != 0){
        char assignStr[MAXLENGTH];
        Variable *variable = &(variableSet->variables[count]);
        strcpy(variable->name,name);
        scanf("%s",assignStr);
        variableSet->varNameTable[count] = variable->name;
        assert(strcmp(assignStr,"=") == 0);
        scanf("%d",&(variable->value));
        scanf("%s",name);
        count++;
    }
    variableSet->varNameTable[count] = NULL;
}

#define LINE 200

int main(){
    VariableSet variableSet;
    readVariable(&variableSet);

    Statement statements[LINE];
    processCode(&variableSet,statements);

    runCode(&variableSet,statements);
    return 0;
}