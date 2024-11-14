#define _GNU_SOURCE
#include "include/cstring.h"

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/utils.h"

String *new_string(const char *str) {
    String *string = malloc(sizeof(String));
    if (NULL == string) {
        die("malloc string:");
    }

    string->str = strdup(str);
    if (NULL == string->str) {
        free(string);
        perror("malloc str");
        return NULL;
    }


    StrAttr str_attr = get_str_attr(str);
    string->str_attr.length = str_attr.length;
    string->str_attr.nlength = str_attr.nlength;
    string->str_attr.zh_count = str_attr.zh_count;

    return string;
}

StrAttr get_str_attr(const char *str) {
    uint32_t zh_count = 0;  // 中文或者其他非 ascii 字符个数
    uint32_t char_len = 0;  // 字符所占的字节数
    uint32_t length = 0;
    uint32_t nlength = 0;
    const char *ptr = str;

    while (*ptr) {
        /* ascii 字符 */
        if ((*ptr & 0x80) == 0x00) {
            char_len = 1;
        }
        /* 2 个字节表示一个字符 */
        else if ((*ptr & 0xe0) == 0xc0) {
            char_len = 2;
            zh_count += 1;
        }
        /* 3 个字节表示一个字符 */
        else if ((*ptr & 0xf0) == 0xe0) {
            char_len = 3;
            zh_count += 1;
        }
        /* 4 个字节表示一个字符 */
        else if ((*ptr & 0xf8) == 0xf0) {
            char_len = 4;
            zh_count += 1;
        }

        length += char_len;
        nlength += 1;
        ptr += char_len;
    }

    StrAttr strattr = {.nlength = nlength, .zh_count = zh_count, .length = length};
    return strattr;
}

void print_string(String string) {
    printf(
        "String {\n    str = \"%s\"\n    zh_count = %d\n    length = %u\n    "
        "nlength = %d\n}\n",
        string.str, string.str_attr.zh_count, string.str_attr.length, string.str_attr.nlength
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
