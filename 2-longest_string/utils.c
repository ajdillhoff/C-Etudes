#include <string.h>

#include "utils.h"

void trim(char *str) {
    str[strcspn(str, "\r\n")] = 0;
}
