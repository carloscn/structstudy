#include <iostream>
#include <stdint.h>
#include "utils.h"
#include "LinkedList.h"

class revert_linklist : LinkedList {

public:
    revert_linklist(void);
    int32_t revert(void);
    void print(void);
    int32_t append_array(int64_t *buffer, size_t len);

private:
    LinkedList *list;
};

using namespace std;

revert_linklist::revert_linklist(void)
{
    list = new LinkedList();
}

void revert_linklist::print(void)
{
    this->list->toString();
}

int32_t revert_linklist::append_array(int64_t *buffer, size_t len)
{
    int32_t ret = 0;
    size_t i = 0;

    if (len == 0) {
        goto finish;
    }
    UTILS_CHECK_PTR(buffer);

    while (len --) {
        list->addLast(buffer[i++]);
    }

finish:
    return ret;
}

int32_t main(void)
{
    int32_t ret = 0;
    int64_t buffer[] = {1,2,3,4,5,6,7,8,9};
    class revert_linklist *list = NULL;
    list = new revert_linklist();
    UTILS_CHECK_PTR(list);

    ret = list->append_array(buffer, ARRAY_SIZE(buffer));
    UTILS_CHECK_RET(ret);

    list->print();

finish:
    return ret;
}