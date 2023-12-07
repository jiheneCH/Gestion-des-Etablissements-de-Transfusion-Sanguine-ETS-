#include <string.h>
#include "etablissement.h"
#include <gtk/gtk.h>

enum
{
  EID,
  ENOM ,
  EDEL,
  EREG,
  ECAP,
 COLUMNS,

} ;
void ajouterETS( etablissement p )

{
    FILE * f=fopen("/home/baha/Desktop/part/src/etablissement.txt", "a+");
    if(f!=NULL)
    {
        fprintf(f,"%s %s %s %s %s\n",p.id,p.ne,p.delegation,p.region,p.cap);
        fclose(f);
       
    }
    
}

void modifierETS(  char id[50], etablissement nouv )
{
    
    etablissement p;
    FILE *f=fopen("/home/baha/Desktop/part/src/etablissement.txt", "r");
    FILE *f2=fopen("/home/baha/Desktop/part/src/nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s\n",p.id,p.ne,p.delegation,p.region,p.cap)!=EOF)
        {
            if(strcmp(p.id, id)==0)
            {
                fprintf(f2,"%s %s %s  %s %s\n",nouv.id,nouv.ne,nouv.delegation,nouv.region,nouv.cap);
                
            }
            else
                fprintf(f2,"%s %s %s %s %s\n",p.id,p.ne,p.delegation,p.region,p.cap);

        }
    }
    fclose(f);
    fclose(f2);
    remove("/home/baha/Desktop/part/src/etablissement.txt");
    rename("/home/baha/Desktop/part/src/nouv.txt", "/home/baha/Desktop/part/src/etablissement.txt");
   

}
void supprimerETS( char id[50])
{
    int tr=0;
    etablissement p;
    FILE * f=fopen("/home/baha/Desktop/part/src/etablissement.txt", "r");
    FILE * f2=fopen("/home/baha/Desktop/part/src/nouv.txt", "w");
    if(f!=NULL && f2!=NULL)
    {
        while(fscanf(f,"%s %s %s %s %s\n",p.id,p.ne,p.delegation,p.region,p.cap)!=EOF)
        {
            
            if(strcmp(p.id,id)!=0)
                fprintf(f2,"%s %s %s %s %s\n",p.id,p.ne,p.delegation,p.region,p.cap);
        }
    }
    fclose(f);
    fclose(f2);
    remove("/home/baha/Desktop/part/src/etablissement.txt");
    rename("/home/baha/Desktop/part/src/nouv.txt", "/home/baha/Desktop/part/src/etablissement.txt");
    
}
void chercherETS(GtkWidget *liste, char *cin)
{
    etablissement p;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[50];
char ne[100];
char region[100];
char delegation[100];
char cap[10];

store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ne",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("delegation",renderer,"text",EDEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("region",renderer,"text",EREG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cap",renderer,"text",ECAP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("/home/baha/Desktop/part/src/etablissement.txt","r");

if(f==NULL)
{
return;
}

else{
 f=fopen("/home/baha/Desktop/part/src/etablissement.txt","a+");

while(fscanf(f,"%s %s %s %s %s\n",p.id,p.ne,p.delegation,p.region,p.cap)!=EOF)
{
if(strcmp(cin,p.id)==0){
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EID,p.id,ENOM,p.ne,EDEL,p.delegation,EREG,p.region,ECAP,p.cap,-1);
}}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}

}
int ETSParRegion(char *filename, char *region)
{
    etablissement E;
    int tr=0;
    int n=0;
    FILE * f=fopen(filename, "r");
    FILE * f2=fopen("/home/baha/Desktop/part/src/region.txt", "w");
    if(f!=NULL)
    {
        while( fscanf(f,"%s %s %s %s %s\n",E.id,E.ne,E.delegation,E.region,E.cap)!=EOF)
        {
            if(strcmp(E.delegation,region)==0 )
               {
                   
                   tr++;

                 fprintf(f2,"%s %s %s %s %s\n",E.id,E.ne,E.delegation,E.region,E.cap);

               }


             
        }

    }
    fclose(f);
    fclose(f2);
    return tr;
}

void ETSTrieCapacite(char *filename)
{
    etablissement E[100];
    int n=0,i=0,min;
char aux[100];
char id[100];
    char nom[100];
    char reg[100];
    char del[100];

    FILE * f=fopen("/home/baha/Desktop/part/src/etablissement.txt", "r");
    FILE * f2=fopen("/home/baha/Desktop/part/src/cap.txt", "w");

    if(f!=NULL)
    {while( fscanf(f,"%s %s %s %s %s\n",E[n].id,E[n].ne,E[n].delegation,E[n].region,E[n].cap)!=EOF){
     n++;
    }

    for (i=0;i<n-1;i++)
{
min=i ;

for (int j=i+1;j<n;j++)
{
if (strcmp(E[j].cap,E[min].cap)<0)

min=j;

}

strcpy(aux,E[i].cap);
strcpy(id,E[i].id);
strcpy(nom,E[i].ne);
strcpy(del,E[i].delegation);
strcpy(reg,E[i].region);

strcpy(E[i].cap,E[min].cap);
strcpy(E[i].id,E[min].id);
strcpy(E[i].ne,E[min].ne);
strcpy(E[i].delegation,E[min].delegation);
strcpy(E[i].region,E[min].region);

strcpy(E[min].cap,aux);
strcpy(E[min].id,id);
strcpy(E[min].ne,nom);
strcpy(E[min].delegation,del);
strcpy(E[min].region,reg);

}
for(int i=0;i<n;i++)
{fprintf(f2,"%s %s %s %s %s\n",E[i].id,E[i].ne,E[i].delegation,E[i].region,E[i].cap);

}
    }
    fclose(f);
    fclose(f2);

}




void afficherETS(GtkWidget *liste)
{	etablissement p;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[50];
char ne[100];
char region[100];
char delegation[100];
char cap[10];

store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ne",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("delegation",renderer,"text",EDEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("region",renderer,"text",EREG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cap",renderer,"text",ECAP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("/home/baha/Desktop/part/src/etablissement.txt","r");

if(f==NULL)
{
return;
}

else{
 f=fopen("/home/baha/Desktop/part/src/etablissement.txt","a+");

while(fscanf(f,"%s %s %s %s %s\n",p.id,p.ne,p.delegation,p.region,p.cap)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EID,p.id,ENOM,p.ne,EDEL,p.delegation,EREG,p.region,ECAP,p.cap,-1);
}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
}
void affichertricap(GtkWidget *liste)
{	etablissement p;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[50];
char ne[100];
char region[100];
char delegation[100];
char cap[10];

store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ne",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("delegation",renderer,"text",EDEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("region",renderer,"text",EREG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cap",renderer,"text",ECAP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("/home/baha/Desktop/part/src/cap.txt","r");

if(f==NULL)
{
return;
}

else{
 f=fopen("/home/baha/Desktop/part/src/cap.txt","a+");

while(fscanf(f,"%s %s %s %s %s\n",p.id,p.ne,p.delegation,p.region,p.cap)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EID,p.id,ENOM,p.ne,EDEL,p.delegation,EREG,p.region,ECAP,p.cap,-1);
}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
}

void affichertrireg(GtkWidget *liste)
{	etablissement p;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	char id[50];
char ne[100];
char region[100];
char delegation[100];
char cap[10];

store=NULL;
FILE *f;
store=gtk_tree_view_get_model(liste);
if(store==NULL){
renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("id",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("ne",renderer,"text",ENOM,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("delegation",renderer,"text",EDEL,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("region",renderer,"text",EREG,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

renderer=gtk_cell_renderer_text_new();
column=gtk_tree_view_column_new_with_attributes("cap",renderer,"text",ECAP,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}

store=gtk_list_store_new(COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("/home/baha/Desktop/part/src/region.txt","r");

if(f==NULL)
{
return;
}

else{
 f=fopen("/home/baha/Desktop/part/src/region.txt","a+");

while(fscanf(f,"%s %s %s %s %s\n",p.id,p.ne,p.delegation,p.region,p.cap)!=EOF)
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,EID,p.id,ENOM,p.ne,EDEL,p.delegation,EREG,p.region,ECAP,p.cap,-1);
}

fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
g_object_unref(store);

}
}



