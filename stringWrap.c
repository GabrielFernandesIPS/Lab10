#include "stringWrap.h"
#include <string.h>

StringWrap stringWrapCreate(char *str) {
    StringWrap wrap;
    strcpy(wrap.text, str);
    return wrap;
}