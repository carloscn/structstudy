#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "strlist.h"
#include "utils.h"

STRLIST_T* strlist_malloc(void)
{
    STRLIST_T *strlist = (STRLIST_T*)malloc(sizeof(STRLIST_T));
    memset(strlist, 0, sizeof(STRLIST_T));
    return strlist;
}

int32_t strlist_add(STRLIST_T *strlist, char *str)
{
    int32_t len = strlen(str);
    strlist->size++;
    strlist->list = (char**)realloc(strlist->list, sizeof(char*) * strlist->size);
    if(strlist->list == NULL){
        /* out of memory! */
        printf("error: not enough memory (realloc returned NULL)\n");
        return -1;
    }
    strlist->list[strlist->size-1]=(char*)malloc(len+1);
    memcpy(strlist->list[strlist->size-1], str, len);
    (strlist->list[strlist->size-1])[len]=0;
    return strlist->size;
}

int32_t strlist_insert_after(STRLIST_T *strlist, char* str, uint32_t index)
{
    int32_t i, len;
    if(index >= strlist->size){
        return -1;
    }
    len = strlen(str);
    strlist->size++;
    strlist->list = (char**)realloc(strlist->list, sizeof(char*) * strlist->size);
    if(strlist->list == NULL){
        /* out of memory! */
        printf("error: not enough memory (realloc returned NULL)\n");
        return -1;
    }
    for(i= strlist->size-1; i>index+1; i--){
        strlist->list[i] = strlist->list[i-1];
    }
    strlist->list[index+1] = (char*)malloc(len+1);
    memcpy(strlist->list[index+1], str, len);
    strlist->list[index+1][len]=0;
    return 0;
}

int32_t strlist_remove_last(STRLIST_T *strlist)
{
    if(strlist->size <=0){
        return -1;
    }
    free(strlist->list[strlist->size-1]);
    strlist->size--;
    return strlist->size;
}

int32_t strlist_remove_at(STRLIST_T *strlist, uint32_t index)
{
    int32_t i;
    if(index >= strlist->size){
        return -1;
    }
    free(strlist->list[index]);
    for(i=index; i< strlist->size-1; i++){
        strlist->list[i] = strlist->list[i+1];
    }
    strlist->size--;
    return strlist->size;
}

char* strlist_get_str_at(STRLIST_T *strlist, uint32_t index)
{
    if(strlist==NULL || index>=strlist->size){
        return NULL;
    }
    return strlist->list[index];
}

int32_t strlist_contains(STRLIST_T *strlist, char* str)
{
    int32_t i;
    for(i=0; i<strlist->size; i++){
        if(0 == (strcmp(strlist->list[i], str))){
            return 1;
        }
    }
    return 0;
}

int32_t strlist_free(STRLIST_T *strlist)
{
    int32_t i;
    if(!strlist){
        return -1;
    }
    for(i=0; i<strlist->size; i++){
        free(strlist->list[i]);
    }
    free(strlist->list);
    free(strlist);
    return 0;
}

void strlist_infolog(STRLIST_T *strlist)
{
    int32_t i;
    printf("\n>>>\n");
    printf("strlist info:\n");
    printf("strlist size: %zu\n", strlist->size);
    for(i = 0; i < strlist->size; i ++){
        printf("%d : %s\n", i , strlist->list[i]);
    }
}

int32_t strlist_selftest(void)
{
    printf("hello c_strlist!");

    STRLIST_T *strlist = strlist_malloc();

    strlist_infolog(strlist);

    strlist_add(strlist,(char*)"aaaa");
    strlist_infolog(strlist);

    strlist_add(strlist,(char*)"bbbb");
    strlist_infolog(strlist);

    strlist_add(strlist,(char*)"字符串列表测试");
    strlist_infolog(strlist);

    strlist_insert_after(strlist, (char*)"ccccc", 1);
    strlist_infolog(strlist);

    printf("\nis strlist contians \"123\"?  %d\n",
           strlist_contains(strlist,(char*)"123"));

    printf("\nis strlist contians \"字符串列表测试\" ? %d\n",
           strlist_contains(strlist,(char*)"字符串列表测试"));

    strlist_remove_last(strlist);
    strlist_infolog(strlist);

    printf("\nis strlist contians \"字符串列表测试\" ? %d\n",
           strlist_contains(strlist,(char*)"字符串列表测试"));

    strlist_remove_at(strlist,1);
    strlist_infolog(strlist);


    strlist_free(strlist);

    return 0;
}