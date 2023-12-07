#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED
#include <stdio.h>
#include <gtk/gtk.h>
typedef struct
{ char id[50];
    char ne [100];
    char delegation[100];
    char region[100];
   
    char cap[50];


} etablissement;
etablissement p;
//le type de  retour int c'est pour indiquer si la tache a été réalisée avec succés ou non// pour afficher des lsg plus tard exemple erreur d'ouverture de fichier, element introuvable
void ajouterETS( etablissement );
void modifierETS( char id[50], etablissement nouv );
void supprimerETS(char * );
void chercherETS(GtkWidget * liste, char *);
int ETSParRegion(char *filename , char *reg);
void ETSTrieCapacite(char *filename);
void afficherETS(GtkWidget * liste);
void affichertricap(GtkWidget *liste);
void affichertrireg(GtkWidget *liste);

#endif // POINT_H_INCLUDED
