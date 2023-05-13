#ifndef _DIM_ARRAY_H
#define _DIM_ARRAY_H

#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct dim_array_t DIM_ARRAY_T;

DIM_ARRAY_T* dim_array_malloc(void);
void dim_array_free(DIM_ARRAY_T *ctx);
int32_t dim_array_add(DIM_ARRAY_T *ctx, int64_t* *array, size_t len, size_t depth);
int32_t dim_array_get_value(DIM_ARRAY_T *ctx, size_t row_index, size_t column_index, int64_t *out);
int32_t dim_array_set_value(DIM_ARRAY_T *ctx, size_t row_index, size_t column_index, int64_t in);
int32_t dim_array_convert_array(DIM_ARRAY_T *ctx, int64_t **out, size_t *o_len);
int32_t dim_array_remove_row(DIM_ARRAY_T *ctx, size_t row_index);
int32_t dim_array_remove_column(DIM_ARRAY_T *ctx, size_t column_index);

#endif /* _DIM_ARRAY_H */