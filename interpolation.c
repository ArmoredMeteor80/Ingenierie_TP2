#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

float lagrange(DataSet * set, float x){
    float sum = 0;
    float product = 1;
    int i, j;

    for(i=0; i<set->size; i++){
        for(j=0; j<set->size; j++){
            if(i!=j){
                product *= ((x-set->tab[j].x)/(set->tab[i].x - set->tab[j].x));
            }
        }
        sum += product*set->tab[i].y;
        product = 1;
    }

    return sum;
}
