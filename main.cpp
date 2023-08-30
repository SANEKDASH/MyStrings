#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#define DEBUG

#include "mystrings.h"
#include "color_print.h"
#include "debug.h"

static void TestPrint(const char *func_name, bool expr);

static void TestMyStrchr();
static void TestMyStrlen();
static void TestMyStrcpy();
static void TestMyStrncpy();
static void TestMyStrcat();
static void TestMyStrncat();
static void TestMyStrdup();

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

    //res =
    TestMyStrchr();
    //RUN_TEST(TestMyStrchr);

    TestMyStrlen();

    TestMyStrcpy();

    TestMyStrncpy();

    TestMyStrcat();

    TestMyStrncat();

    TestMyStrdup();

    char *str = nullptr;

    size_t n = 1;

    myGetline(&str, &n, stdin);
    printf("%s", str);

    return 0;
}

static void TestPrint(const char *func_name, bool expr)
{
    if (expr)
    {
        ColorPrintf(kGreen,"#/ %s test: succeded.\n", func_name);
    }
    else
    {
        ColorPrintf(kRed, "#/ %s test: fault.\n", func_name);
    }
    return;
}

static void TestMyStrchr()
{
    char str[] = "aboba";

    if (strchr(str, 'o') == myStrchr(str, 'o'))
    {
        ColorPrintf(kGreen, "#/ myStrchr test: succeded.\n");

        return;
    }

    ColorPrintf(kRed, "#/ myStrchr test: fault.\n");

    return;
}

static void TestMyStrlen()
{
    char str[] = "zhmih airlines";

    if (myStrlen(str) == strlen(str))
    {
        ColorPrintf(kGreen, "#/ myStrlen test: succeded.\n");

        return;
    }

    ColorPrintf(kRed, "#/ myStrlen test: fault.\n");

    return;
}

static void TestMyStrcpy()
{
    char ref_str[20] = {0};
    char testing_str[20] = {0};

    if (strcmp(strcpy(ref_str, "1234"), myStrcpy(testing_str, "1234")) == 0)
    {
        ColorPrintf(kGreen, "#/ myStrcpy test: succeded.\n");

        return;
    }

    ColorPrintf(kRed, "#/ myStrcpy test: fault.\n");

}

static void TestMyStrncpy()
{
    char ref_str[20] = {0};
    char testing_str[20] = {0};

    if (strcmp(strncpy(ref_str, "ajhflos", 4), myStrncpy(testing_str, "ajhflos", 4)) == 0)
    {
        ColorPrintf(kGreen, "#/ myStrncpy test: succeded.\n");

        return;
    }

    ColorPrintf(kRed, "#/ myStrncpy test: fault.\n");

    return;
}

static void TestMyStrcat()
{
    char ref_str[20] = "Ded";
    char testing_str[20] = "Ded";

    TestPrint("myStrcat", strcmp(strcat(ref_str, " Inside"), myStrcat(testing_str, " Inside")) == 0);

    return;
}

static void TestMyStrncat()
{
    char ref_str[20] = "Ded";
    char testing_str[20] = "Ded";

    TestPrint("myStrncat", strcmp(strncat(ref_str, " Inside", 3),
                           myStrncat(testing_str,  " Inside", 3)) == 0);

    return;
}

static void TestMyStrdup()
{
    TestPrint("myStrdup", strcmp(myStrdup("Ded Inside"), strdup("Ded Inside")) == 0);

    return;
}
