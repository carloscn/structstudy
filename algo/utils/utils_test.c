#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "linklist.h"
#include "strlist.h"
#include "utils.h"

int main(void)
{
    LOG("queue selftest: \n");
    LOG_LINE_WITH_TR();
    queue_selftest();
    LOG("stack selftest: \n");
    LOG_LINE_WITH_TR();
    stack_selftest();
    LOG("linklist selftest: \n");
    LOG_LINE_WITH_TR();
    linklist_selftest();
    LOG("strlist selftest: \n");
    LOG_LINE_WITH_TR();
    strlist_selftest();
    LOG_LINE_WITH_DOUBLE_TR();
    return 0;
}