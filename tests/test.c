#include <stdio.h>

#include "../src/include/cstring.h"
#include "../src/include/utils.h"

int main(int argc, char *argv[]) {
    char *str  = "hello 世界";
    char *str2 = "hello rust";
    char *str3 = "你好,世界";

    StrAttr str_attr  = get_str_attr(str);
    StrAttr str_attr2 = get_str_attr(str2);
    StrAttr str_attr3 = get_str_attr(str3);

    printf("nlength: %d\nzh_count: %d\n", str_attr.nlength, str_attr.zh_count);
    printf("nlength: %d\nzh_count: %d\n", str_attr2.nlength, str_attr2.zh_count);
    printf("nlength: %d\nzh_count: %d\n", str_attr3.nlength, str_attr3.zh_count);

    int max_length = max(str_attr.nlength, max(str_attr2.nlength, str_attr3.nlength));

    printf("+");
    for (int i = 0; i < max_length + 2; i++) {
        printf("-");
    }
    printf("+\n");

    int a = 3 > 5 ? 3 : 5;

    printf("|");
    printf(" %-*s ", str_attr.nlength + str_attr.zh_count, str);
    printf("|\n");
    printf("------------------------------------------------\n");
    String *string1 = new_string("Hello 世界");
    print_string(*string1);

    free_string(string1);

    return 0;
}
