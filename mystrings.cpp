#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "debug.h"
#include "mystrings.h"

int myPuts(const char *str)
{
    CHECK(str);

    int i = 0;

    for (; *(str + i) != '\0'; ++i)
    {
        putchar(*(str + i));
    }
    putchar('\n');

    return i;
}

char *myStrchr(char *str, int ch)
{
    CHECK(str);

    int i = 0;

    for (; *(str + i) != '\0'; ++i)
    {
        if (*(str + i) == ch)
        {
            return str + i;
        }
    }

    return nullptr;
}

size_t myStrlen(const char *str)
{
    CHECK(str);

    size_t i = 0;
    for (; *(str + i) != '\0'; ++i)
    {
        /* Do nothing */
    }

    return i;
}

char *myStrcpy(char *dest, const char *src )
{
    CHECK(dest);
    CHECK(src);

    int i = 0;

    for (; *(src + i) != '\0'; ++i)
    {
        CHECK(i < strlen());
        //*(dest + i) = *(src + i);
        dest[i] = src[i];
    }

    *(dest + i) = '\0';

    return dest;
}

char *myStrncpy(char *dest, const char *src, size_t count)
{
    CHECK(dest);
    CHECK(src);

    size_t i = 0;

    for (; *(src + i) != '\0' && i < count; ++i)
    {
        *(dest + i) = *(src + i);
    }

    for (; i < count; ++i)
    {
        *(dest + i) = '\0';
    }

    return dest;
}

char *myStrcat(char *dest, const char *src)
{
    CHECK(dest);
    CHECK(src);

    int i = myStrlen(dest);

    for (int j = 0; *(src + j) != '\0'; ++i, ++j)
    {
        *(dest + i) = *(src + j);
    }

    *(dest + i) = '\0';

    return dest;
}

char *myStrncat(char *dest, const char *src, size_t count)
{
    CHECK(dest);
    CHECK(src);

    size_t i = myStrlen(dest);

    for (size_t j = 0; *(src + j) != '\0' && j < count; ++i, ++j)
    {
        *(dest + i) = *(src + j);
    }

    *(dest + i) = '\0';

    return dest;
}

char *myFgets(char *str, size_t count, FILE *stream)
{
    CHECK(!ferror(stream));
    CHECK(stream);
    CHECK(str);

    size_t i = 0;

    int c = 0;

    for (; i < count - 1 && (c = getc(stream)) != '\n'; i++)
    {
        *(str + i) = (char) c;
    }

    *(str + i) = '\0';

    return str;
}

char *myStrdup(const char *str)
{
    CHECK(str);

    char *str_copy = (char*) calloc(myStrlen(str) + 1, sizeof(char));

    if (str_copy == nullptr)
    {
        return nullptr;
    }

    myStrcpy(str_copy, str);

    return str_copy;
}

ssize_t myGetline(char **ptr_line, size_t *n, FILE *stream)
{
    CHECK(stream);
    CHECK(ptr_line);
    CHECK(n);

    if (*ptr_line == nullptr)
    {
        *ptr_line = (char *) calloc(*n, sizeof(char));  // !!!!???? realloc(nullptr)
    }

    size_t i = 0;

    int c = 0;

    while ((c = fgetc(stream)) != '\n' && ptr_line != nullptr)
    {
        if (c == EOF)
        {
            return EOF;
        }
        if (i < *n - 1)
        {
            *(*ptr_line + i) = (char) c;

            ++i;
        }
        else
        {
            realloc(*ptr_line, ++*n);

            *(*ptr_line + i) = (char) c;

            ++i;
        }
    }

    *(*ptr_line + i) = '\0';

    return i;
}

char *myStrStr(const char *str, const char *substr)
{
    CHECK(str);
    CHECK(substr);

    for (; *str != '\0'; ++str)
    {
        int j = 0;

        for (; str[j] != '\0' && str[j] == substr[j]; ++j)
        {
            //do nothing
        }

        if (substr[j] == '\0')
        {
            return (char *) str;
        }
    }

    return nullptr;
}

