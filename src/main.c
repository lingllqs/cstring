#include "include/cstring.h"

int main()
{
    String *string = new_string("Hello 世界");
    print_string(*string);
    free_string(string);
    return 0;
}
