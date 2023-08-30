#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define DEBUG

#include "mystrings.h"
#include "color_print.h"
#include "debug.h"

#define RUN_TEST(func) TestPrint(#func, func())

static void TestPrint(const char *func_name, bool expr);

static bool TestMyStrchr();
static bool TestMyStrlen();
static bool TestMyStrcpy();
static bool TestMyStrncpy();
static bool TestMyStrcat();
static bool TestMyStrncat();
static bool TestMyStrdup();

int main()
{
    /*fclose(stdin);

    int a = 0;

    assert(scanf("%d", &a) == EOF);

    FILE *ptr_file = fopen("test.txt", "w");

    fwrite("aboba", sizeof(char), sizeof("aboba"), ptr_file);

    fclose(ptr_file);

    stdin = fopen("test.txt", "r");

    char c = (char) getc(stdin);

    printf("%c", c);*/

    RUN_TEST(TestMyStrchr);

    RUN_TEST(TestMyStrchr);

    RUN_TEST(TestMyStrlen);

    RUN_TEST(TestMyStrcpy);

    RUN_TEST(TestMyStrncpy);

    RUN_TEST(TestMyStrcat);

    RUN_TEST(TestMyStrncat);

    RUN_TEST(TestMyStrdup);

    printf("%s", myStrStr("aboba", "bo"));

    return 0;
}

static void TestPrint(const char *func_name, bool expr)
{
    if (expr)
    {
        ColorPrintf(kGreen,"#/ %-15s : succeded.\n", func_name);
    }
    else
    {
        ColorPrintf(kRed, "#/ %-15s : fault.\n", func_name);
    }
    return;
}

static bool TestMyStrchr()
{
    char str[] = "aboba";

    return (strchr(str, 'o') == myStrchr(str, 'o'));

}

static bool TestMyStrlen()
{
    char str[] = "zhmih airlines";

    return (myStrlen(str) == strlen(str));
}

static bool TestMyStrcpy()
{
    char ref_str[20] = {0};
    char testing_str[20] = {0};

    return (strcmp(strcpy(ref_str, "1234"),
            myStrcpy(testing_str,  "1234")) == 0);
}

static bool TestMyStrncpy()
{
    char ref_str[20] = {0};
    char testing_str[20] = {0};

    return (strcmp(strncpy(ref_str, "ajhflos", 4),
            myStrncpy(testing_str,  "ajhflos", 4)) == 0);
}

static bool TestMyStrcat()
{
    char ref_str[20] = "Ded";
    char testing_str[20] = "Ded";

    return (strcmp(strcat(ref_str, " Inside"),
            myStrcat(testing_str,  " Inside")) == 0);
}

static bool TestMyStrncat()
{
    char ref_str[20] = "Ded";
    char testing_str[20] = "Ded";

    return (strcmp(strncat(ref_str, " Inside", 3),
            myStrncat(testing_str,  " Inside", 3)) == 0);
}

static bool TestMyStrdup()
{
    return (strcmp(myStrdup("Ded Inside"),
                   strdup(  "Ded Inside")) == 0);
}


