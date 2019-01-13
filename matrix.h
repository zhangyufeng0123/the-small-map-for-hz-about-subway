#pragma once

typedef int DataType;

enum MatrixMode{ROW_MAJOR=0,COLUMN_MAJOR=1};
struct Matrix {
	int rows;
	int cols;
	enum MatrixMode mode;
	DataType *buffer;
};

void matrix_init(struct Matrix *m, int rows, int cols, enum MatrixMode mode);

void matrix_destroy(struct Matrix *m);

DataType matrix_get(struct Matrix *m, int row, int col);

void matrix_set(struct Matrix *m, int row, int col, DataType type);

void matrix_print(struct Matrix *m);