#include "dataset.h"
#include <stdio.h>
#include <stdio.h>

int main(){
    //premier jeu de données 
    float set1_values[] = {-1.0, 1.0, -0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 1.0, 1.0};
    DataSet * set1 = create_dataset_from_array(5, set1_values);
    print_dataset(set1);
    //deuxième jeu de données
    float set2_values[] = {-1.0, 1.0, -0.8, 0.8, -0.6, 0.6, -0.4, 0.4, -0.2, 0.2, 0.0, 0.0, 0.2, 0.2, 0.4, 0.4, 0.6, 0.6, 0.8, 0.8, 1.0, 1.0};
    DataSet * set2 = create_dataset_from_array(11, set2_values);
    print_dataset(set2);
    

    //obtenir valeurs pour le graphique avec set1
    /*int x;*/
    /*float tab[200];*/
    /*for (x=-100; x<100;x++){*/
    /*    printf("%f", (float)x/100.0);*/
    /*    tab[x+100] = lagrange(set1, (float)x/100.0);*/
    /*}*/
    /**/
    /*int i;*/
    /*for (i=0; i<200; i++){*/
    /*    printf("%f\n", tab[i]);*/
    /*}*/

    free_dataset(set1);
    free_dataset(set2);
    return 0;
}
