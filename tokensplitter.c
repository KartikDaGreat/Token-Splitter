#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define m 100
struct Symbol
{
    char name[100];
    int addr;
    char type[100];
};

struct Symbol symTable[m];
int symcntr = 0;
int cntr = 1000;  // starting address

void addsym(char *name, char *type)
{
    strcpy(symTable[symcntr].name, name);
    symTable[symcntr].addr = cntr;
    strcpy(symTable[symcntr].type, type);
    symcntr++;
    cntr += 100;  // incrementing the address counter
}

void pnt()
{
    printf("Symbol\t| Address\t| Type\n");
    for (int i = 0; i < symcntr; i++)
        printf("%s\t| %d\t\t| %s\n", symTable[i].name, symTable[i].addr, symTable[i].type);
}

bool iskey(char *word)
{
    const char *keywords[] = {"auto", "break", "case", "char", "const", "continue", "default","do", "double", "else", "enum", "extern", "float", "for", "goto","if", "int", "long", "register", "return", "short", "signed","sizeof", "static", "struct", "switch", "typedef", "union","unsigned", "void", "volatile", "while"};
    int keywordCount = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < keywordCount; i++)
        if (strcmp(word, keywords[i]) == 0)
            return true;
    return false;
}

bool isop(char *symbol)
{
    const char *operators[] = {"+", "-", "*", "/", "%", "=", "==", "!=", ">", "<", ">=", "<=", "&&", "||"};
    int operatorCount = sizeof(operators) / sizeof(operators[0]);
    for (int i = 0; i < operatorCount; i++)
        if (strcmp(symbol, operators[i]) == 0)
            return true;
    return false;
}

bool isid(char *symbol)
{
    for (int i = 0; i < strlen(symbol); i++)
        if (!isalpha(symbol[i]) && !isdigit(symbol[i]))
            return false;
    return true;
}

bool isnum(char *symbol)
{
    for (int i = 0; i < strlen(symbol); i++)
        if (!isdigit(symbol[i]))
            return false;
    return true;
}

int main()
{
    char input[1000];
    printf("Enter input (Enter '~' to stop):\n");
    while (fgets(input, sizeof(input), stdin))
    {
        // Stop reading input if '~' is reached
        if (input[0] == '~')
            break;
        if (isspace(input[0]))
            continue;
        char *token = strtok(input, " \n");
        while (token != NULL)
        {
            if (iskey(token))
                addsym(token, "kw");
            else if (isop(token))
                addsym(token, "op");
            else if (isid(token))
                addsym(token, "id");
            else if (isnum(token))
                addsym(token, "num");
            token = strtok(NULL, " \n");
        }
    }
    pnt();
    return 0;
}
