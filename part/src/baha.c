#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<gtk/gtk.h>
#include "baha.h"

enum {
	EIDD,
	EN,
	EP,
	ENT,
	EJ,
	EM,
	EA,
	ES,
	ETS,
	COLUMNSS
	
};
void ajouter_baha(user d) {
    FILE *f = fopen("user.txt", "a+");
    if (f != NULL) {
        fprintf(f, "%s %s %s %s %s %s %s %s %s\n",d.cin,d.nom,d.prenom,d.numero_de_tel,d.jour,d.mois,d.annee,d.sexe,d.role);
;

        fclose(f);
    }
}

//****************************************************************************
void afficher_baha(GtkWidget *liste){
user d;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
	char cin[60];
	char nom[60];
	char prenom[60];
	char numero_de_tel[60];
	char jour[60];
	char mois[60];
	char annee[60];
	char sexe[60];
	char role[60];
store = NULL;
FILE *f;
store = gtk_tree_view_get_model(liste);
if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",EIDD,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",EN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numero_de_tel",renderer,"text",ENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ES,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("role",renderer,"text",ETS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

}
store=gtk_list_store_new(COLUMNSS,G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

{
f = fopen("user.txt", "r");

if(f==NULL)

{
	return;
}

else
{
	while(fscanf(f, "%s %s %s %s %s %s %s %s %s\n",d.cin,d.nom,d.prenom,d.numero_de_tel,d.jour,d.mois,d.annee,d.sexe,d.role)!=EOF)

	{

		gtk_list_store_append(store, &iter);

		gtk_list_store_set(store, &iter,EIDD, d.cin, EN, d.nom,EP,d.prenom,ENT,d.numero_de_tel,EJ,d.jour,EM,d.mois,EA,d.annee, ES,d.sexe,ETS,d.role,-1);

}	
	fclose(f);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);


}
}
}

void supprimer_baha(char *cin)
{
FILE*f=NULL;
FILE*f1=NULL;
user d;
f=fopen("user.txt","r");
f1=fopen("user1.txt","w+");
while(fscanf(f, "%s %s %s %s %s %s %s %s %s\n",d.cin,d.nom,d.prenom,d.numero_de_tel,d.jour,d.mois,d.annee,d.sexe,d.role)!=EOF)
{
	if(strcmp(cin,d.cin)!=0)
	fprintf(f1, "%s %s %s %s %s %s %s %s %s\n",d.cin,d.nom,d.prenom,d.numero_de_tel,d.jour,d.mois,d.annee,d.sexe,d.role);
}
fclose(f);
fclose(f1);
remove("user.txt");
rename("user1.txt","user.txt");
}
//********************************************************************************************
void Chercher_baha(GtkWidget *liste,char *cin1){

user d;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
	char cin[60];
	char nom[60];
	char prenom[60];
	char numero_de_tel[60];
	char jour[60];
	char mois[60];
	char annee[60];
	char sexe[60];
	char role[60];
store = NULL;
FILE *f;
store = gtk_tree_view_get_model(liste);
	    if (store == NULL)
{
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("cin",renderer,"text",EIDD,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("nom",renderer,"text",EN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("prenom",renderer,"text",EP,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("numero_de_tel",renderer,"text",ENT,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJ,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EM,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EA,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

	
	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("sexe",renderer,"text",ES,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("role",renderer,"text",ETS,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste), column);

}
store=gtk_list_store_new(COLUMNSS,G_TYPE_STRING , G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	    f=fopen("user.txt","r");
	    if(f==NULL)
	    {
	          return;
	    }

	    else
	    {  
			
			while(fscanf(f, "%s %s %s %s %s %s %s %s %s\n",d.cin,d.nom,d.prenom,d.numero_de_tel,d.jour,d.mois,d.annee,d.sexe,d.role)!=EOF)
			{
				 if ((strcmp(cin1,d.cin)==0)||(strcmp(cin1, d.role) == 0)||(strcmp(cin1, d.nom) == 0))
				{
				 	
					gtk_list_store_append(store, &iter);
					gtk_list_store_set(store, &iter,EIDD, d.cin, EN, d.nom,EP,d.prenom,ENT,d.numero_de_tel,EJ,d.jour,EM,d.mois,EA,d.annee, ES,d.sexe,ETS,d.role,-1);
				}
	                }
			fclose(f);
			gtk_tree_view_set_model (GTK_TREE_VIEW (liste), GTK_TREE_MODEL (store));
			g_object_unref (store);
	    }

}




void modifier_baha(user D)
{
    FILE *f = NULL;
    FILE *f1 = NULL;
    user r;

    f = fopen("user.txt", "r");
    f1 = fopen("user1.txt", "w+");

    while (fscanf(f, "%s %s %s %s %s %s %s %s %s\n", r.cin, r.nom, r.prenom, r.numero_de_tel, r.jour, r.mois, r.annee, r.sexe, r.role) != EOF)
    {
        if (strcmp(D.cin, r.cin) == 0)
        {
            fprintf(f1, "%s %s %s %s %s %s %s %s %s\n", D.cin, D.nom, D.prenom, D.numero_de_tel, D.jour, D.mois, D.annee, D.sexe, D.role);
        }
        else
        {
            fprintf(f1, "%s %s %s %s %s %s %s %s %s\n", r.cin, r.nom, r.prenom, r.numero_de_tel, r.jour, r.mois, r.annee, r.sexe, r.role);
        }
    }

    fclose(f);
    fclose(f1);

    remove("user.txt");
    rename("user1.txt", "user.txt");
}











float statistique()
{
    FILE *f;
    user p;
    int i = 0;
    int nb = 0; 

    //******************* calcul nb de user  **************************
    f = fopen("user.txt", "r");

    if (f == NULL)
    {
        return -1;
    }
    else
    {
        while (fscanf(f, "%s %s %s %s %s %s %s %s %s\n", p.cin, p.nom, p.prenom, p.numero_de_tel, p.jour, p.mois, p.annee, p.sexe, p.role) != EOF)
        {
            nb++;
            if (strcmp(p.sexe, "h") == 0)
            {
                i++;
            }
        }
        fclose(f);

        float ph = ((float)i / nb) * 100; 
        return ph; 
    }
}


