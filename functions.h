#ifndef MATRIX_H
#define MATRIX_H

struct Point{
    float x;
    float y;
};

typedef struct Point Point;

struct DataSet{
    int size;
    Point * tab;
};

typedef struct DataSet DataSet;

DataSet * create_dataset_from_array(int size, float array[]);
void print_point(Point point);
void print_dataset(DataSet * set);
void free_dataset(DataSet * set);

#endif // !MATRIX_H
