/*
 * Apr 17, 2014
 * Author: Yuancheng PENG
 * Description: replace space of a string by "%20"
 * Exemple:
 *    input: "You are a boy"
 *    output: "You%20are%20a%20boy"
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* change(char* str)
{
    // count spaces
    int count = 0;
    char* p = str;
    while(*p != '\0')
    {
        p = p + 1;
        if (*p == ' ')
        {
            count++;
        }
    }

    // allocate memory
    char* temp = (char*)malloc(strlen(str) + 2*count + 1);

    // copy new string
    p = str;
    int k = 0;
    while (*p != '\0')
    {
        if (*p == ' ')
        {
            temp[k++] = '%';
            temp[k++] = '2';
            temp[k] = '0';
        }
        else
        {
            temp[k] = *p;
        }
        k++;
        p++;
    }
    temp[k] = '\0';
    return temp;
}


int main()
{
    char str[10000000];

    while(gets(str))
    {
        char* str2 = change(str);
        printf("%s\n", str2);
    }

    return 0;
}
