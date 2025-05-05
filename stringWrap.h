#pragma once

#define STRING_MAX_LEN 100

typedef struct stringWrap {
    char text[STRING_MAX_LEN];
} StringWrap;

StringWrap stringWrapCreate(char *str);
