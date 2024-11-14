#include "include/cstring.h"
#include <stdio.h>

int main()
{
    String *string = new_string("Hello 世界");

    StrAttr str_attr = get_str_attr(string->str);
    printf("str_attr.nlength = %d\nstr_attr.zh_count = %d\nstr_attr.length = %d\n", str_attr.nlength, str_attr.zh_count, str_attr.length);

    print_string(*string);
    free_string(string);
    return 0;
}
