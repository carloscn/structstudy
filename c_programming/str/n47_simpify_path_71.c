#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "strlist.h"
#include "utils.h"

// note, the path memory must be writeable.
int32_t simplify_path(char path[])
{
    int32_t ret = 0;
    size_t len = 0;
    char *path_dup = NULL;
    STRLIST_T *path_list = NULL;
    STRLIST_T *new_list = NULL;
    size_t i = 0;

    UTILS_CHECK_PTR(path);
    UTILS_CHECK_LEN(len = strlen(path));

    path_dup = (char *)malloc(len + 1);
    UTILS_CHECK_PTR(path_dup);

    memset(path_dup, (int)'\0', len + 1);

    // format ///// -> /; strip tail /;
    char e = 0;
    size_t j = 0;
    for (i = 0; i < len; i ++) {
        if (path[i] == '/') {
            if (strlen(path_dup) != 0 && path_dup[j - 1] != '/') {
                path_dup[j] = path[i];
                j ++;
            }
        } else {
            path_dup[j] = path[i];
            j ++;
        }
    }
    if (path_dup[j - 1] != '/') {
        path_dup[j] = '/';
        j ++;
    }

    path_list = strlist_malloc();
    UTILS_CHECK_PTR(path_list);

    ret = strlist_add_split_by_char(path_list, (const char *)path_dup, '/');
    UTILS_CHECK_RET(ret);

    strlist_infolog(path_list);

    new_list = strlist_malloc();
    UTILS_CHECK_PTR(new_list);

    char *str = NULL;
    len = strlist_get_size(path_list);
    for (i = 0; i < len; i ++) {
        str = strlist_get_str_at(path_list, i);
        UTILS_CHECK_PTR(str);
        if (0 == strcmp(str, "..")) {
            if (strlist_get_size(new_list) != 0) {
                ret = strlist_remove_last(new_list);
                UTILS_CHECK_RET(ret);
            } else {
<<<<<<< HEAD
                ret = -1;
                LOG("the path input is error!\n");
=======
                strcpy(path, "/");
>>>>>>> 00e1771fb8689111614db169a0e0ca7b8cfe3d25
                goto finish;
            }
        } else if (0 == strcmp(str, ".")) {
            continue;
        } else {
            ret = strlist_add(new_list, str);
            UTILS_CHECK_RET(ret);
        }
    }

    memset(path_dup, '\0', strlen(path) + 1);
    len = strlist_get_size(new_list);
    for (i = 0; i < len; i ++) {
        str = strlist_get_str_at(new_list, i);
        UTILS_CHECK_PTR(str);
        strcat(path_dup, "/");
        strcat(path_dup, str);
    }

    strcpy(path, path_dup);

finish:
    if (path_dup != NULL) {
        free(path_dup);
    }
    strlist_free(path_list);
    strlist_free(new_list);
    return ret;
}


int32_t main(void)
{
    int32_t ret = 0;
    char path[1024] = {0};

    sprintf(path, "/home/");
    simplify_path(path);
<<<<<<< HEAD
    assert(strcmp(path, "/home"));

    sprintf(path, "/../");
    simplify_path(path);
    assert(strcmp(path, "/"));

    sprintf(path, "/home//foo");
    simplify_path(path);
    assert(strcmp(path, "/home/foo"));

    sprintf(path, "/home//foo/");
    simplify_path(path);
    assert(strcmp(path, "/home/foo"));

    sprintf(path, "/a/./b/../../c/");
    simplify_path(path);
    assert(strcmp(path, "/c"));
=======
    LOG("the output is %s\n", path);
    assert(!strcmp(path, "/home"));

    sprintf(path, "/../");
    simplify_path(path);
    LOG("the output is %s\n", path);
    assert(!strcmp(path, "/"));

    sprintf(path, "/home//foo");
    simplify_path(path);
    LOG("the output is %s\n", path);
    assert(!strcmp(path, "/home/foo"));

    sprintf(path, "/home//foo/");
    simplify_path(path);
    LOG("the output is %s\n", path);
    assert(!strcmp(path, "/home/foo"));

    sprintf(path, "/a/./b/../../c/");
    simplify_path(path);
    LOG("the output is %s\n", path);
    assert(!strcmp(path, "/c"));
>>>>>>> 00e1771fb8689111614db169a0e0ca7b8cfe3d25

finish:
    return ret;
}