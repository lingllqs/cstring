#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/utils.h"
#include "include/cstring.h"

String *new_string(const char *str) {
    String *string = malloc(sizeof(String));
    if (NULL == string) {
        die("malloc string:");
    }

    uint32_t str_len = strlen(str);
    string->str      = malloc((str_len + 1));
    if (NULL == string->str) {
        free(string);
        perror("malloc str");
        return NULL;
    }

    strcpy(string->str, str);

    StrAttr str_attr = get_str_attr(str);
    string->length   = str_len;
    string->nlength  = str_attr.cell_len;
    string->zh_count = str_attr.zh_nums;

    return string;
}

StrAttr get_str_attr(const char *str) {
    uint32_t zh_nums    = 0;  // 中文或者其他非 ascii 字符个数
    uint32_t char_len   = 0;  // 字符所占的字节数
    uint32_t str_length = 0;
    const char *ptr     = str;

    while (*ptr) {
        /* ascii 字符 */
        if ((*ptr & 0x80) == 0x00) {
            char_len    = 1;
            str_length += 1;
        }
        /* 2 个字节表示一个字符 */
        else if ((*ptr & 0xe0) == 0xc0) {
            char_len    = 2;
            str_length += 1;
            zh_nums    += 1;
        }
        /* 3 个字节表示一个字符 */
        else if ((*ptr & 0xf0) == 0xe0) {
            char_len    = 3;
            str_length += 1;
            zh_nums    += 1;
        }
        /* 4 个字节表示一个字符 */
        else if ((*ptr & 0xf8) == 0xf0) {
            char_len    = 4;
            str_length += 1;
            zh_nums    += 1;
        }

        ptr += char_len;
    }

    StrAttr strattr = {.cell_len = str_length, .zh_nums = zh_nums};
    return strattr;
}

void print_string(String string) {
    printf(
        "String {\n    str = \"%s\"\n    zh_count = %d\n    length = %u\n    "
        "nlength = %d\n}\n",
        string.str, string.zh_count, string.length, string.nlength
    );
}

void free_string(String *string) {
    if (string) {
        if (string->str) {
            free(string->str);
        }
        free(string);
    }
}
