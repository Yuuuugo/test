#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>


#include <termios.h>


#define TRUE 256
#define FALSE 0

static struct termios origtc, newtc;

enum METHODE {Backtrack,Force_Brute};


typedef struct{
    int **sudoku;
    int lignes; // Nombre de lignes de plateau
    int colonnes; // Nobre de colonnes de plateau
    enum METHODE METHODE;
    char nom[31];
}sudo_t;


void lire_plateau(char *fichier,sudo_t *sudo);
void clearScreen();
void afficher_plateau(sudo_t sudo);
int resolu(sudo_t sudo);
int resolution_Backtrack(sudo_t *sudo);
void resolution_ForceBrute(sudo_t *sudo);
int TrouverCaseVide(sudo_t sudo,int l[]);
int EstValide(sudo_t sudo,int i , int j, int chiffre);
sudo_t convertisseur(sudo_t sudo);
int appartenir(int *sudoku,int k);
void ecriture();