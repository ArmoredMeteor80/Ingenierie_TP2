#include "dataset.h"
#include <stdlib.h>
#include <stdio.h>

DataSet * create_dataset_from_array(int size, float array[]){
    DataSet * set = malloc(sizeof(DataSet));
    set->size = size;
    set->tab = malloc(sizeof(Point)*size);
    int i;
    for (i=0;i<size;i++){
        set->tab[i].x = array[i*2];
        set->tab[i].y = array[i*2+1];
    }
    return set;
}

void print_point(Point point){
    printf("| %f;%f ", point.x, point.y);
}

void print_dataset(DataSet * set){
    int i;
    for (i=0;i<set->size;i++){
        print_point(set->tab[i]);
        if (i==set->size-1){
            printf("|\n");
        }
    }
    printf("\n");
}

void free_dataset(DataSet * set){
    free(set->tab);
    free(set);
}

