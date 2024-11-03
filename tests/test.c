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

    printf("length: %d\nzh_nums: %d\n", str_attr.cell_len, str_attr.zh_nums);
    printf("length: %d\nzh_nums: %d\n", str_attr2.cell_len, str_attr2.zh_nums);
    printf("length: %d\nzh_nums: %d\n", str_attr3.cell_len, str_attr3.zh_nums);

    int max_length = max(str_attr.cell_len, max(str_attr2.cell_len, str_attr3.cell_len));

    printf("+");
    for (int i = 0; i < max_length + 2; i++) {
        printf("-");
    }
    printf("+\n");

    int a = 3 > 5 ? 3 : 5;

    printf("|");
    printf(" %-*s ", str_attr.cell_len + str_attr.zh_nums, str);
    printf("|\n");
    printf("------------------------------------------------\n");
    String *string1 = new_string("Hello 世界");
    print_string(*string1);

    free_string(string1);

    return 0;
}
