#ifndef DATASET_H
#define DATASET_H

typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    int size;
    Point * tab;
} DataSet;

DataSet * create_dataset_from_array(int size, float array[]);
void print_point(Point point);
void print_dataset(DataSet * set);
void free_dataset(DataSet * set);
float lagrange(DataSet * set, float x);

#endif // !DATASET_H
