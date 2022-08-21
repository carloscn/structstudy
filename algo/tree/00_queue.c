#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QUEUE_SIZE  (100UL)

static int64_t __queue_space[QUEUE_SIZE] = {0};
static size_t __queue_len = 0;
static int64_t *__queue_head = __queue_space;
static int64_t *__queue_tail = __queue_space;

static int64_t queue_push(int64_t e)
{
    if (__queue_len >= QUEUE_SIZE) {
        printf("queue overflow (full)\n");
        return -1;
    }
    *(__queue_tail++) = e;
    __queue_len ++;

    return 0;
}

static int64_t queue_pop(int64_t *e)
{
    if (__queue_len <= 0) {
        printf("queue overflow (empty)\n");
        return -1;
    }
    if (e != NULL) {
        *e = *__queue_head;
    }
    size_t i = 0;
    __queue_len --;
    for (i = 0; i < __queue_len; i ++) {
        __queue_head[i] = __queue_head[i+1];
    }
    *(__queue_tail --) = 0;
    return 0;
}

static void queue_size_print(void)
{
    printf("queue size : %zd\n", __queue_len);
}

static void queue_print(void)
{
    size_t i = 0;
    printf("head [ ");
    do {
        printf("%lld, ", __queue_space[i++]);
    } while (i < __queue_len);
    printf("] tail. \n -- queue len = %zu\n", __queue_len);
}

static size_t queue_size(void)
{
    return __queue_len;
}

int main(void)
{
    size_t i = 0;
    int64_t val = 0;
    for (i = 0; i < 100; i ++) {
        queue_push((int64_t)i);
    }
    queue_print();
    printf("queue size : %zd\n", queue_size());
    queue_pop(&val);
    printf("popped data %lld\n", val);
    queue_print();
}