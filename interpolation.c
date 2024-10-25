#include <sdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

float lagrange(DataSet * set, float x){
    float result = 0;
    float temp = 1;
    int i, j;

    for(i=0; i<set->size+1; i++){
        for(j=0; j<set->size+1; j++){
            if(i!=j){
                temp = temp * ((x-set->tab[j].x)/(set->tab[i].x - set->tab[j].x));
            }
        }
        result += temp;
        temp = 1;
    }

    return result;
}