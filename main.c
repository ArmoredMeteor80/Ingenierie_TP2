#include "dataset.h"
#include <math.h>
#include <stdio.h>
#include <stdio.h>

int main(){
    //premier jeu de données 
    float set1_values[] = {-1.0, 1.0, -0.5, 0.5, 0.0, 0.0, 0.5, 0.5, 1.0, 1.0};
    DataSet * set1 = create_dataset_from_array(5, set1_values);
    //deuxième jeu de données
    float set2_values[] = {-1.0, 1.0, -0.8, 0.8, -0.6, 0.6, -0.4, 0.4, -0.2, 0.2, 0.0, 0.0, 0.2, 0.2, 0.4, 0.4, 0.6, 0.6, 0.8, 0.8, 1.0, 1.0};
    DataSet * set2 = create_dataset_from_array(11, set2_values);
    
    // Définir les bornes de l'intervalle [-1, 1]
    float x_min = -1.0;
    float x_max = 1.0;
    // Nombre de points souhaités pour le graphique
    int nb_points = 100;
    // Calculer le pas entre chaque point
    float step = (x_max - x_min) / (nb_points - 1);
    // fichier_valeurs aura en première colonne x, en deuxième |x|, en troisième Lagrange avec n vaut 4 et en quatrième Lagrange avec n vaut 10
    FILE * fichier_valeurs = fopen("fichier_valeurs.csv", "w+");
    // Boucle pour générer les points du polynôme de Lagrange et les mettre dans le fichier
    for (int i = 0; i < nb_points; i++) {
        float x = x_min + i * step;
        float y = lagrange(set1, x);
        float z = lagrange(set2, x);
        fprintf(fichier_valeurs, "%f;%f;%f;%f\n", x, fabs(x), y, z);
    }

    printf("----------- Partie 1 ----------\n");

    free_dataset(set1);
    free_dataset(set2);

    printf("----------- Partie 2 ----------\n");
    // Jeux de données pour la partie 4 
    // Densité
    float set4_1_values[] = {0, 0.99987, 2, 0.99997, 4, 1, 6, 0.99997, 8, 0.99988, 10, 0.99973, 12, 0.99953, 14, 0.99927, 16, 0.99897, 18, 0.99846, 20, 0.99805, 22, 0.999751, 24, 0.99705, 26, 0.99650, 28, 0.99664, 30, 0.99533, 32, 0.99472, 34, 0.99472, 36, 0.99333, 38, 0.99326};
    DataSet * set4_1 = create_dataset_from_array(20, set4_1_values);
   
    float set4_2_values[] = {752, 85, 855, 83, 871, 162, 734, 79, 610, 81, 582, 83, 931, 281, 492, 81, 569, 81, 462, 80, 807, 243, 643, 84, 862, 84, 524, 82, 679, 80, 902, 226, 918, 260, 828, 82, 875, 186, 809, 77, 894, 223};
    DataSet * set4_2 = create_dataset_from_array(21, set4_2_values);

    float set4_3_values[] = {10, 8.04, 8, 6.95, 13, 7.58, 9, 8.81, 11, 8.33, 14, 9.96, 6, 7.24, 4, 4.26, 12, 10.84, 7, 4.82, 5, 5.68};
    DataSet * set4_3 = create_dataset_from_array(11, set4_3_values);

    float set4_4_values[] = {88, 5.89, 89, 6.77, 90, 7.87, 91, 9.11, 92, 10.56, 93, 12.27, 94, 13.92, 95, 15.72, 96, 17.91, 97, 22.13};
    DataSet * set4_4 = create_dataset_from_array(10, set4_4_values);

    float set4_5_values[] = {20, 352, 30, 128, 40, 62.3, 50, 35.7, 100, 6.3, 300, 0.4, 500, 0.1};
    DataSet * set4_5 = create_dataset_from_array(7, set4_5_values);
    
    printf("Pour le jeu de données 4.1, ");
    droite_regression(set4_1);
    printf("Pour le jeu de données 4.2, ");
    droite_regression(set4_2);
    printf("Pour le jeu de données 4.3, ");
    droite_regression(set4_3);
    printf("Ajustement pour 4.4, ");
    ajustement_expo(set4_4);
    
    

    free_dataset(set4_1);
    free_dataset(set4_2);
    free_dataset(set4_3);
    free_dataset(set4_4);
    free_dataset(set4_5);
    return 0;
}
