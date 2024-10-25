#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    //premier jeu de données 
    float set1_values[] = {-1.0, 1.0, -0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 1.0, 1.0};
    DataSet * set1 = create_dataset_from_array(5, set1_values);
    print_dataset(set1);
    //deuxième jeu de données
    float set2_values[] = {-1, 1, -0.8, 0.8, -0.6, 0.6, -0.4, 0.4, -0.2, 0.2, 0.0, 0.0, 0.2, 0.2, 0.4, 0.4, 0.6, 0.6, 0.8, 0.8, 1.0, 1.0};
    DataSet * set2 = create_dataset_from_array(11, set2_values);
    print_dataset(set2);


    free_dataset(set1);
    free_dataset(set2);
    return 0;
}

DataSet * create_dataset_from_array(int size, float array[]){
    DataSet * set = malloc(sizeof(DataSet));
    set->size = size;
    set->tab = malloc(sizeof(Point)*size);
    int i;
    for (i=0;i<size*2;i++){
        printf("%d\n", i);
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

