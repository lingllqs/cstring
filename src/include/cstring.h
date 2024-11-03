#ifndef CSTRING_H
#define CSTRING_H

#include <stdint.h>

typedef struct String {
    char    *str;       // 字符串
    uint32_t zh_count;  // 中文个数
    uint32_t length;    // 字符串长度
    uint32_t nlength;   // 中文算一个 char
} String;

typedef struct StrAttr {
    uint32_t cell_len;  // 终端中占用多少个格子
    uint32_t zh_nums;   // 中文个数
} StrAttr;

String *new_string(const char *str);    // 新建 String
StrAttr get_str_attr(const char *str);  // 获取字符串属性
void    print_string(String string);    // 打印 String
void    free_string(String *string);    // 释放资源

#endif
