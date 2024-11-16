#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "dataset.h"

float x_bar(DataSet * set){
    float res = 0;
    int i;
    for (i=0; i<set->size; i++){
        res += set->tab[i].x;
    }
    return res/set->size;
}

float y_bar(DataSet * set){
   float res = 0;
    int i;
    for (i=0; i<set->size; i++){
        res += set->tab[i].y;
    }
    return res/set->size;
}

float yx_bar(DataSet * set){
    float res = 0;
    int i;
    for (i=0; i<set->size; i++){
        res += set->tab[i].x*set->tab[i].y; 
    }
    return res/set->size;
}

float x2_bar(DataSet * set){
    float res = 0;
    int i;
    for (i=0; i<set->size; i++){
        res += set->tab[i].x*set->tab[i].x;
    }
    return res/set->size;
}

float a1(DataSet * set){
    float res = (yx_bar(set)-x_bar(set)*y_bar(set))/(x2_bar(set)-(x_bar(set)*x_bar(set)));
    return res;
}

float a0(DataSet * set){
    float res = (y_bar(set)*x2_bar(set)-x_bar(set)*yx_bar(set))/(x2_bar(set)-(x_bar(set)*x_bar(set)));
    return res;
}

void droite_regression(DataSet * set){
    printf("La droite de regression est : f(x) = %f + %fx\n", a0(set), a1(set));
}

void ajustement_expo(DataSet * set){
    tout_mettre_en_log(set);
    printf("Ajustement expo : y = %fe^(%fx)", exp(a0(set)), a1(set));
    tout_remettre_comme_avant_le_log(set);
}

void tout_mettre_en_log(DataSet * set){
    int i;
    for (i=0; i<set->size; i++){
        set->tab[i].x = log(set->tab[i].x);
        set->tab[i].y = log(set->tab[i].y);
    }
}

void tout_remettre_comme_avant_le_log(DataSet * set){
    int i;
    for (i=0; i<set->size; i++){
        set->tab[i].x = exp(set->tab[i].x);
        set->tab[i].y = exp(set->tab[i].y);
    }
}


/*void ajustement_exponentiel(int n, float *a_b, float *tab_x, float *tab_y) {*/
/*    int i;*/
/*    float ln_x[n];*/
/*    float ln_y[n];*/
/*    for (i = 0; i < n; i++) {*/
/*        ln_x[i] = log(tab_x[i]);*/
/*        ln_y[i] = log(tab_y[i]);*/
/*    }*/
/*    droite_regression(n, a_b, ln_x, ln_y);*/
/*    a_b[1] = exp(a_b[1]);*/
/*}*/
/**/
/*void ajustement_puissance(int n, float *a_b, float *tab_x, float *tab_y) {*/
/*    int i;*/
/*    float ln_x[n];*/
/*    float ln_y[n];*/
/*    float ln_a_b[2];*/
/*    for (i = 0; i < n; i++) {*/
/*        ln_x[i] = log(tab_x[i]);*/
/*        ln_y[i] = log(tab_y[i]);*/
/*    }*/
/*    droite_regression(n, ln_a_b, ln_x, ln_y);*/
/*    a_b[0] = exp(ln_a_b[1]);*/
/*    a_b[1] = ln_a_b[0];*/
/*}*/
