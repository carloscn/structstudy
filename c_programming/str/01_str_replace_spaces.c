#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// replace spaces to "%20"
// For examples:
// We are happy -> We%20are%20happy.

static int method_1(const char *str)
{
    // check parameter
    if (NULL == str) {
        printf("error: input parameter NULL\n");
        return -1;
    }

    size_t str_len = strlen(str);
    size_t i = 0, pos = 0;
    char *new_str = (char *)malloc(str_len * 3 + 1);

    for (i = 0; i < str_len; i ++) {
        if (str[i] == (char)0x20) {
            memcpy(new_str + pos, "%20", 3);
            pos += 3;
        } else {
            new_str[pos] = str[i];
            pos ++;
        }
    }
    new_str[pos] = '\0';
    printf("new str is %s\n", new_str);
    free(new_str);

finish:
    return 0;
}

static int method_2(char *str)
{
    // check parameter
    if (NULL == str) {
        printf("error: input parameter NULL\n");
        return -1;
    }

    size_t str_len = strlen(str);
    size_t i = 0, pos = 0;

    do {
        if (str[pos] == (char)0x20) {
            memcpy(str + pos + 3, str + pos + 1, strlen(str) - pos + 1);
            memcpy(str + pos, "%20", 3);
            pos += 3;
        } else {
            pos ++;
        }
        i ++;
    } while (i < str_len);

    printf("new str is %s\n", str);

finish:
    return 0;
}

static void print_str(char *str, size_t len)
{
    size_t i = 0;
    for (i = 0; i < len; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

static int method_3(char *str)
{
    // check parameter
    if (NULL == str) {
        printf("error: input parameter NULL\n");
        return -1;
    }

    size_t str_len = strlen(str);
    size_t ext_str_len = 0;
    char *p1 = NULL, *p2 = NULL;
    size_t pos = 0, i = 0;
    for (i = 0; i < str_len; i ++) {
        if (str[i] == ' ') {
            pos++;
        }
    }
    ext_str_len = (pos * 2) + str_len + 1;
    p1 = str + str_len + 1;
    p2 = str + ext_str_len;

    do {
        *(p2--) = *(p1--);
        if (*p1 == ' ') {
            *(p2 --) = '0';
            *(p2 --) = '2';
            *(p2 --) = '%';
            p1 --;
        }
    } while (p1 != p2);

    printf("new str is %s\n", str);
finish:
    return 0;
}

int main(void) {
    int ret;
    clock_t start, end;
    const char *str = "We are hap p y.";
    char input_str[100];
    memset(input_str, 0, sizeof(input_str));
    memcpy(input_str, str, strlen(str) + 1);

    start = clock();
    ret = method_1(input_str);
    end = clock();
    printf("\nmethod 1 time = %f\n\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    memcpy(input_str, str, strlen(str) + 1);
    start = clock();
    ret = method_2(input_str);
    end = clock();
    printf("\nmethod 2 time = %f\n\n\n", (double)(end - start) / CLOCKS_PER_SEC);

    memcpy(input_str, str, strlen(str) + 1);
    start = clock();
    ret = method_3(input_str);
    end = clock();
    printf("\nmethod 3 time = %f\n\n\n", (double)(end - start) / CLOCKS_PER_SEC);
    return ret;
}