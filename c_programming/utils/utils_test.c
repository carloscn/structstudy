#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "linklist.h"
#include "strlist.h"
#include "utils.h"
#include "binary_tree.h"
#include "buffer.h"
#include "multi_tree.h"
#include "hash_map.h"
#include "bufferlist.h"

int main(void)
{
    size_t i = 8, j = 10;
    UTILS_SWAP((uint32_t*)&i, (uint32_t*)&j);
    LOG("the i = %zu, j = %zu\n", i, j);
    // LOG("queue selftest: \n");
    // LOG_LINE_WITH_TR();
    // queue_selftest();
    // LOG("stack selftest: \n");
    // LOG_LINE_WITH_TR();
    // stack_selftest();
    // LOG("linklist selftest: \n");
    // LOG_LINE_WITH_TR();
    // linklist_selftest();
    // LOG("strlist selftest: \n");
    // LOG_LINE_WITH_TR();
    //strlist_selftest();
    // LOG_LINE_WITH_DOUBLE_TR();
    // LOG("binary_tree selftest: please input: 124#7###35##68###\n");
    // LOG_LINE_WITH_DOUBLE_TR();
    // binarytree_selftest();
    //LOG("dynamic array selftest: \n");
    //LOG_LINE_WITH_DOUBLE_TR();
    //buffer_selftest();
    //multitree_selftest();
    //hashmap_selftest();
    //buflist_selftest();

    return 0;
}