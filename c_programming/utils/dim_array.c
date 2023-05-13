#include "utils.h"
#include "dim_array.h"

struct dim_array_t {
    size_t len;
    size_t depth;
    int64_t *rom;
};

DIM_ARRAY_T* dim_array_malloc(void)
{
    DIM_ARRAY_T *ctx = NULL;

    ctx = (DIM_ARRAY_T *)calloc(1, sizeof(DIM_ARRAY_T));

    return ctx;
}

void dim_array_free(DIM_ARRAY_T *ctx)
{
    if (NULL == ctx) {
        return;
    }

    ctx->len = 0;
    ctx->depth = 0;

    UTILS_SAFE_FREE(ctx->rom);
}

int32_t dim_array_add(DIM_ARRAY_T *ctx, int64_t *array, size_t len, size_t depth)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(ctx);
    UTILS_CHECK_PTR(array);
    UTILS_CHECK_LEN(len);
    UTILS_CHECK_LEN(depth);

    if (len != ctx->len) {
        ret = -1;
        LOG("the len != ctx->len!\n");
        goto finish;
    }

    ctx->rom = (int64_t *)realloc((len * depth + ctx->len * ctx->depth) *
                                  sizeof(int64_t));
    UTILS_CHECK_PTR(ctx->rom);

    memcpy(ctx->rom + len * depth * sizeof(int64_t),
           array,
           len * depth * sizeof(int64_t));

    ctx->depth += depth;
    ctx->len += len;

finish:
    return ret;
}

int32_t dim_array_add_row(DIM_ARRAY_T *ctx, int64_t *array, size_t len)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(ctx);

    if (len != ctx->len) {
        ret = -1;
        LOG("the len != ctx->len!\n");
        goto finish;
    }

    ret = dim_array_add(ctx, array, len, 1);
    UTILS_CHECK_RET(ret);

finish:
    return ret;
}

int32_t dim_array_add_column(DIM_ARRAY_T *ctx, int64_t *array, size_t depth)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(ctx);

    if (depth != ctx->depth) {
        ret = -1;
        LOG("the len != ctx->depth!\n");
        goto finish;
    }

    size_t i = 0;

    // todo

finish:
    return ret;
}

int32_t dim_array_get_value(DIM_ARRAY_T *ctx,
                            size_t row_index,
                            size_t column_index,
                            int64_t *out)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(ctx);
    UTILS_CHECK_PTR(out);

    if ((row_index > ctx->len - 1) ||
        (column_index > ctx->depth - 1)) {
        ret = -1;
        goto finish;
    }

    *out = ctx->rom[column_index * ctx->len + row_index];

finish:
    return ret;
}

int32_t dim_array_set_value(DIM_ARRAY_T *ctx,
                            size_t row_index,
                            size_t column_index,
                            int64_t in)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(ctx);

    if ((row_index > ctx->len - 1) ||
        (column_index > ctx->depth - 1)) {
        ret = -1;
        goto finish;
    }

    ctx->rom[column_index * ctx->len + row_index] = in;

finish:
    return ret;
}

int32_t dim_array_convert_array(DIM_ARRAY_T *ctx, int64_t **out, size_t *o_len)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(ctx);
    UTILS_CHECK_PTR(out);
    UITLS_CHECK_PTR(o_len);

    *out = (int64_t *)malloc(sizeof(int64_t) * ctx->len * ctx->depth);
    UTILS_CHECK_PTR(*out);

    *o_len = ctx->depth * ctx->len;
    memcpy(*out, ctx->rom, *o_len * sizeof(int64_t));

finish:
    return ret;
}

int32_t dim_array_remove_row(DIM_ARRAY_T *ctx, size_t row_index)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(ctx);

    if (row_index > ctx->len) {
        goto finish;
    }

    // todo

finish:
    return ret;
}

int32_t dim_array_remove_column(DIM_ARRAY_T *ctx, size_t column_index)
{
    int32_t ret = 0;

    UTILS_CHECK_PTR(ctx);

    if (column_index > ctx->depth) {
        goto finish;
    }

    // todo
finish:
    return ret;
}