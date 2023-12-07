#ifndef FONCTIONS22_H_
#define FONCTIONS22_H_
#include<gtk/gtk.h>


typedef struct {
	char cin[60];
	char nom[60];
	char prenom[60];
	char numero_de_tel[60];
	char jour[60];
	char mois[60];
	char annee[60];
	char sexe[60];
	char role[60];
    
}user;

user d;
void ajouter_baha(user d) ;
void modifier_baha(user D);
void afficher_baha(GtkWidget *liste);
void supprimer_baha(char *cin);
void Chercher_baha(GtkWidget *liste,char *cin1);
#endif
