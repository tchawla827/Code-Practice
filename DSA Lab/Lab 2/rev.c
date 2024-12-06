#include <stdio.h>
#include <string.h>

void reversewords(char *str, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    reversewords(str, start + 1, end - 1);
}

void reversewords2(char *str)
{
    int length = strlen(str);

    reversewords(str, 0, length - 1);

    int start = 0, end;
    for (int i = 0; i <= length; i++)
    {
        if (str[i] == ' ' || str[i] == '\0')
        {
            end = i - 1;
            reversewords(str, start, end);
            start = i + 1;
        }
    }
}

int main()
{
    char str[100];
    fgets(str, 100, stdin);
    reversewords2(str);
    printf("Reversed string: %s", str);
    return 0;
}