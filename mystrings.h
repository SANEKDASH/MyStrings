#ifndef mystrings

#define mystrings

char *myStrStr(const char *str, const char *pattern);

int myPuts(const char *str);

char *myStrchr(char *str, int ch);

size_t myStrlen(const char *str);

char *myStrcpy( char *dest, const char *src );

char *myStrncpy(char *dest, const char *src, size_t count);

char *myStrcat(char *dest, const char *src);

char *myStrncat(char *dest, const char *src, size_t count);

char *myFgets(char *str, size_t count, FILE *stream);

char *myStrdup(const char *str);

ssize_t myGetline(char **ptr_line, size_t *n, FILE *stream);

#endif
