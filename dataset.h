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
float x_bar(DataSet * set);
float y_bar(DataSet * set);
float yx_bar(DataSet * set);
float x2_bar(DataSet * set);
float a0(DataSet * set);
float a1(DataSet * set);
void droite_regression(DataSet * set);
void tout_remettre_comme_avant_le_log(DataSet * set);
void tout_mettre_en_log(DataSet * set);
void ajustement_expo(DataSet * set);



#endif // !DATASET_H
