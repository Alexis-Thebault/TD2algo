#include <stdio.h>
#include <stdlib.h>




int recherche_dichotomique(int * t, int x, int d, int f) {
    int milieu = t[(d + f) / 2];
    if (x == milieu) {
        return (d + f) / 2;
    }
    else{
        if (x < milieu) {
            f = milieu - 1;
            return recherche_dichotomique(t, x, d, f);
    }
        if (x > milieu) {
            d = milieu + 1;
            return recherche_dichotomique(t, x, d, f);
    }
    else {
        return -1;}
    }
    return -1;
}

void affiche_tab(double t[], int n){
    for (int i=0; i<n; i++){
        printf("%f ", t[i]);
    }
    printf("\n");
}

double* raz(double t[], int n){
    for (int i=0; i<n; i++){
        t[i] = 0.0;
    }
    return t;
}

 int indice_premier_negatif (double t[], int n){
    int gauche = 0;
    int droite = n - 1;
    int resultat = -1;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;

        if (t[milieu] < 0) {
            resultat = milieu; // On a trouvé un négatif, on continue à chercher à gauche
            droite = milieu - 1;
        } else {
            gauche = milieu + 1; // Continuer à chercher à droite
        }
    }

    return resultat;
 }

 double valeur_plus_grand (double t[], int n){
    double max = t[0];
    for (int i=1; i<n; i++){
        if (t[i] > max){
            max = t[i];
        }
    }
    return max;
 }

int indice_plus_grand (double t[], int n){
    int indicemax = 0;
    for ( int i=1; i<n ; i++){
        if (t[i] > t[indicemax]){
            indicemax = i;
        }
    }
    return indicemax;
}

int est_trie (double t[], int n){
    int a = 1;
    for(int i = 0; i<n-1; i++){
        if (t[i] > t[i+1]){
            a = 0;
            break;
        }
    }
    return a;
}

double moyenne (double t[], int n){
    double somme = 0.0;
    for (int i = 0; i<n ; i++){
        somme += t[i];
    }
    return somme / n;
}

int PGCD(int a, int b){
    if (a == 0) {
        return b;
    }
    else {
        int r = b % a;
        return PGCD(r, a);
    }
}

const int MAXSIZE = 1000000;
const int P = 5150377;

int test_tableau(int * t, int n) {
    int p=-P;
    for (int i=0; i<n; i++) {
        // Test de l'élément (P*i)%n
        p = (p+P)%n;

        if (recherche_dichotomique(t, t[p], 0, n) != p) {
            printf("echoue: element %d a la position %d pas trouve\n", t[p], p);
            return 0;
        }

        if (p+1 < n && t[p+1] > t[p]+1) {
            int r = recherche_dichotomique(t, (t[p]+t[p+1])/2, 0, n);
            if (r != -1) {
                printf("echoue: element inexistant %d trouve a la position %d\n", (t[p]+t[p+1])/2, r);
                return 0;
            }
        }
    }
    printf("reussi\n");
    return 1;
}

int main() {
    int * t = (int*) malloc(MAXSIZE * sizeof(int));
    int points = 0, num_tests = 0;

    // Test 1
    printf("[Test %d] ", ++num_tests);
    t[0] = 1; t[1] = 4; t[2] = 23; t[3] = 44; t[4] = 72; t[5] = 100;
    points += test_tableau(t, 6);

    // Test 2
    printf("[Test %d] ", ++num_tests);
    for (int i=0; i<=10; i++) t[i] = (i>0)?(t[i-1]*2):1;
    points += test_tableau(t, 11);

    // Test 3
    printf("[Test %d] ", ++num_tests);
    for (int i=0; i<1000; i++) t[i] = i*i;
    points += test_tableau(t, 1000);

    // Test 4
    printf("[Test %d] ", ++num_tests);
    for (int i=0; i<MAXSIZE; i++) t[i] = 2*i;
    points += test_tableau(t, MAXSIZE);

    printf("Tests reussis: %d/%d\n", points, num_tests);
}
