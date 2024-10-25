#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    //premier jeu de données 
    float set1_values[] = {-1.0, 1.0, -0.5, 0.5, 0, 0, 0.5, 0.5, 1, 1};
    DataSet * set1 = create_dataset_from_array(4, set1_values);
    print_dataset(set1);
    return 0;
}

DataSet * create_dataset_from_array(int size, float array[]){
    DataSet * set = malloc(sizeof(DataSet));
    set->size = size;
    set->tab = malloc(sizeof(Point)*size);
    int i;
    for (i=0;i<size;i+=2){
        set->tab[i].x = array[i];
        set->tab[i].y = array[i+1];
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
}


