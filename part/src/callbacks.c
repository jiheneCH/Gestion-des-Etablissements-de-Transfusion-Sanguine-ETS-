#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "baha.c"

#include "etablissement.c"

int check=0;
int check0=1;
int check00=1;
int jj,mm,aa;
void
on_buttonadministrateur_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *choixacteur, *login_admin_b_j;
choixacteur = lookup_widget(GTK_WIDGET(button), "choixacteur");
   gtk_widget_destroy(choixacteur);
        login_admin_b_j = create_login_admin_b_j();
        gtk_widget_show(login_admin_b_j);
}



void
on_login_baha_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *acceuil_admin, *login_admin_b_j,*dialog;
login_admin_b_j = lookup_widget(GTK_WIDGET(button), "login_admin_b_j");

GtkWidget *usename,*password;
char user[50];
char pass[50];

usename=lookup_widget(GTK_WIDGET(button),"entry7");
password=lookup_widget(GTK_WIDGET(button),"entry8");
strcpy(user,gtk_entry_get_text(GTK_ENTRY(usename)));
strcpy(pass,gtk_entry_get_text(GTK_ENTRY(password)));
if ((strcmp(user,"admin")==0)&&(strcmp(pass,"admin")==0))
{if ((check==1))
{
gtk_widget_destroy(login_admin_b_j);
acceuil_admin=create_acceuil_admin();
gtk_widget_show (acceuil_admin);

}

else 
{dialog=gtk_message_dialog_new(GTK_WINDOW(dialog),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_WARNING,
			GTK_BUTTONS_OK,
			"Le choix du captcha est incorrect");
			gtk_window_set_title(GTK_WINDOW(dialog),"Alerte");	
			gtk_dialog_run(GTK_DIALOG(dialog));
			gtk_widget_destroy(dialog);
}


}

else 
{dialog=gtk_message_dialog_new(GTK_WINDOW(dialog),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_WARNING,
			GTK_BUTTONS_OK,
			"Le mot de passe ou le username entré est incorrect");
			gtk_window_set_title(GTK_WINDOW(dialog),"Alerte");	
			gtk_dialog_run(GTK_DIALOG(dialog));
			gtk_widget_destroy(dialog);
}
}
void
on_check2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		check=1;
}
void
on_check1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		check00=0;
}


void
on_check3_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
		check0=0;
}

void
on_utilisateur_baha_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *acceuil_admin, *liste_util_b,*tr1;
acceuil_admin = lookup_widget(GTK_WIDGET(button), "acceuil_admin");
   gtk_widget_destroy(acceuil_admin);
        liste_util_b = create_liste_util_b();
        gtk_widget_show(liste_util_b);
	tr1 = lookup_widget(liste_util_b, "treeview_baha");
afficher_baha(tr1);
}
char xx[5];
void
on_nouveau_baha_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *form_ajout_b, *liste_util_b;
liste_util_b = lookup_widget(GTK_WIDGET(button), "liste_util_b");
   gtk_widget_destroy(liste_util_b);
        form_ajout_b = create_form_ajout_b();
        gtk_widget_show(form_ajout_b);

}

void
on_button8_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
int j22,m22,a22;

user D;

	GtkWidget *triew1,*dialog;
	GtkWidget *cin,*nom,*prenom,*num_tel,*jour,*mois,*annee ,*sexe,*role;
	GtkWidget *form_ajout_b,*liste_util_b;


	form_ajout_b=lookup_widget(GTK_WIDGET(button),"form_ajout_b");

	cin=lookup_widget(GTK_WIDGET(button),"entry10");
	nom=lookup_widget(GTK_WIDGET(button),"entry11");
	prenom=lookup_widget(GTK_WIDGET(button),"entry12");
	num_tel=lookup_widget(GTK_WIDGET(button),"entry13");
	role=lookup_widget(GTK_WIDGET(button),"combobox1");
	jour=lookup_widget(GTK_WIDGET(button),"spinbutton1");
	mois=lookup_widget(GTK_WIDGET(button),"spinbutton2");
	annee=lookup_widget(GTK_WIDGET(button),"spinbutton3");

	  strcpy(D.cin, gtk_entry_get_text(GTK_ENTRY(cin)));
user d;
    FILE *f1;
    f1 = fopen("user.txt", "r");
int a=0;
    if (f1 != NULL) {
        while (fscanf(f1, "%s %s %s %s %s %s %s %s %s\n", d.cin, d.nom, d.prenom, d.numero_de_tel,d.jour, d.mois, d.annee,d.sexe, d.role) != EOF) {
if (strcmp(d.cin,D.cin)==0){
a=1;
}}

           
 if ((strlen(D.cin) == 8) &&a==0) {
		a++;
	strcpy(D.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
	strcpy(D.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
	strcpy(D.numero_de_tel,gtk_entry_get_text(GTK_ENTRY(num_tel)));
	strcpy(D.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));
	j22=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
	m22=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
	a22=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

	sprintf(D.jour, "%d" , j22);
	sprintf(D.mois, "%d" , m22);
	sprintf(D.annee, "%d" , a22);

	strcpy(D.sexe,xx);
	
	
	ajouter_baha(D);

	gtk_widget_destroy(form_ajout_b);
	liste_util_b=create_liste_util_b();
	gtk_widget_show (liste_util_b);}
else {
                dialog = gtk_message_dialog_new(NULL,
                                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                                 GTK_MESSAGE_ERROR,
                                                 GTK_BUTTONS_OK,
                                                 "CIN est incorrect ou existe déjà");
                gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
                gtk_dialog_run(GTK_DIALOG(dialog));
                gtk_widget_destroy(dialog);
                return;
            }
        
    
    fclose(f1);

	triew1 = lookup_widget(liste_util_b, "treeview_baha");
	afficher_baha(triew1);}

}


void
on_button9_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{	
GtkWidget *form_ajout_b,*liste_util_b,*triew1;


	form_ajout_b=lookup_widget(GTK_WIDGET(button),"form_ajout_b");
gtk_widget_destroy(form_ajout_b);
	liste_util_b=create_liste_util_b();
	gtk_widget_show (liste_util_b);


	triew1 = lookup_widget(liste_util_b, "treeview_baha");
	afficher_baha(triew1);
}




void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(xx,"h");}
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(xx,"f");}
}

void
on_modifier_baha_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *form_modif_b,*liste_util_b,*dialog;



	 
	    GtkTreeSelection *selection;
	    GtkTreeIter iter;
	    GtkTreeModel *model;
	    GtkWidget *treee;
		gchar *cin;
		gchar *nom;
		gchar *prenom;
		gchar *numero_de_tel;
		gchar *jour;
		gchar *mois;
		gchar *annee;
		gchar *sexe;
		gchar *role;
	int jj,mm,aa;
    treee = lookup_widget(GTK_WIDGET(button), "treeview_baha");
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treee));

    if (gtk_tree_selection_get_selected(selection, &model, &iter))
    {
       gtk_tree_model_get (GTK_LIST_STORE(model),&iter,0,&cin,1,&nom,2,&prenom,3,&numero_de_tel,4,&jour,5,&mois,6,&annee,7,&sexe,8,&role, -1);
        gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
		liste_util_b=lookup_widget(GTK_WIDGET(button),"liste_util_b");
		gtk_widget_destroy(liste_util_b);

		form_modif_b = create_form_modif_b ();
  		gtk_widget_show (form_modif_b);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(form_modif_b,"entry16")),cin);
   
gtk_entry_set_text(GTK_ENTRY(lookup_widget(form_modif_b,"entry17")),nom);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(form_modif_b,"entry18")),prenom);
		gtk_entry_set_text(GTK_ENTRY(lookup_widget(form_modif_b,"entry19")),numero_de_tel);

		jj=atoi(jour);
		mm=atoi(mois);
		aa=atoi(annee);

		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(form_modif_b,"spinbutton4")),jj);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(form_modif_b,"spinbutton5")),mm);
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(lookup_widget(form_modif_b,"spinbutton6")),aa);



		 if (strcmp(role,"responsable_ETS")==0)
		{
			gtk_combo_box_set_active (GTK_COMBO_BOX(lookup_widget(form_modif_b,"combobox2")),2 );
		}
		else if (strcmp(role,"infermier")==0)
		{
			gtk_combo_box_set_active (GTK_COMBO_BOX(lookup_widget(form_modif_b,"combobox2")),1 );
		}
		else if (strcmp(role,"medecin_biologiste")==0)
		{
			gtk_combo_box_set_active (GTK_COMBO_BOX(lookup_widget(form_modif_b,"combobox2")),0 );
		}
 

}
else 
{dialog=gtk_message_dialog_new(GTK_WINDOW(dialog),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_WARNING,
			GTK_BUTTONS_OK,
			"Le mot de passe ou le username entré est incorrect");
			gtk_window_set_title(GTK_WINDOW(dialog),"Alerte");	
			gtk_dialog_run(GTK_DIALOG(dialog));
			gtk_widget_destroy(dialog);
}
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(xx,"f");}
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(togglebutton)){
strcpy(xx,"h");}
}

void
on_button25_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
int j22,m22,a22;

user D;

	GtkWidget *triew1,*dialog;
	GtkWidget *cin1,*nom1,*prenom1,*num_tel1,*jour1,*mois1,*annee1,*sexe1,*role1;
	GtkWidget *form_modif_b,*liste_util_b;


	form_modif_b=lookup_widget(GTK_WIDGET(button),"form_modif_b");

	cin1=lookup_widget(GTK_WIDGET(button),"entry16");
	nom1=lookup_widget(GTK_WIDGET(button),"entry17");
	prenom1=lookup_widget(GTK_WIDGET(button),"entry18");
	num_tel1=lookup_widget(GTK_WIDGET(button),"entry19");
	role1=lookup_widget(GTK_WIDGET(button),"combobox2");
	jour1=lookup_widget(GTK_WIDGET(button),"spinbutton4");
	mois1=lookup_widget(GTK_WIDGET(button),"spinbutton5");
	annee1=lookup_widget(GTK_WIDGET(button),"spinbutton6");

	  strcpy(D.cin, gtk_entry_get_text(GTK_ENTRY(cin1)));
	strcpy(D.nom, gtk_entry_get_text(GTK_ENTRY(nom1)));
	strcpy(D.prenom, gtk_entry_get_text(GTK_ENTRY(prenom1)));
	strcpy(D.numero_de_tel,gtk_entry_get_text(GTK_ENTRY(num_tel1)));
	strcpy(D.role,gtk_combo_box_get_active_text(GTK_COMBO_BOX(role1)));
	j22=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour1));
	m22=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois1));
	a22=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee1));

	sprintf(D.jour, "%d" , j22);
	sprintf(D.mois, "%d" , m22);
	sprintf(D.annee, "%d" , a22);

	strcpy(D.sexe,xx);
	
	
	modifier_baha(D);

	gtk_widget_destroy(form_modif_b);
	liste_util_b=create_liste_util_b();
	gtk_widget_show (liste_util_b);

	triew1 = lookup_widget(liste_util_b, "treeview_baha");
	afficher_baha(triew1);



}



void
on_button26_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{	GtkWidget *triew1;
	GtkWidget *form_modif_b,*liste_util_b;
	form_modif_b=lookup_widget(GTK_WIDGET(button),"form_modif_b");
	gtk_widget_destroy(form_modif_b);
	liste_util_b=create_liste_util_b();
	gtk_widget_show (liste_util_b);

	triew1 = lookup_widget(liste_util_b, "treeview_baha");
	afficher_baha(triew1);
}


void
on_recherche_baha_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *b, *dialog;
    GtkWidget *entry;
    GtkWidget *nbResultat;
    char rech[30];

    entry = lookup_widget(GTK_WIDGET(button), "entry9");
    b = lookup_widget(GTK_WIDGET(button), "treeview_baha");
    strcpy(rech, gtk_entry_get_text(GTK_ENTRY(entry)));

    FILE *f;
    f = fopen("user.txt", "r");     
	user d;

    if (strcmp(rech, "") == 0)
    {
        dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_WARNING,
                                        GTK_BUTTONS_OK,
                                        "Saisir votre identifiant");
        gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
   else if (f != NULL)
    {
        int found = 0; 

        while (fscanf(f, "%s %s %s %s %s %s %s %s %s\n",d.cin,d.nom,d.prenom,d.numero_de_tel,d.jour,d.mois,d.annee,d.sexe,d.role) != EOF)
        {
            if( (strcmp(rech, d.nom) == 0)||(strcmp(rech, d.cin) == 0)||(strcmp(rech, d.role) == 0))
            {
                found = 1;
                break; 
            }
        }

        fclose(f);

        if (found == 0)
        {
            dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_WARNING,
                                            GTK_BUTTONS_OK,
                                            "Identifiant incorrect");
            gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
        }
        else
        {
            Chercher_baha(b, rech);
        }
   }
}






void
on_button27_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *triew1;
	GtkWidget *liste_util_b;
	liste_util_b=lookup_widget(GTK_WIDGET(button),"liste_util_b");
	gtk_widget_destroy(liste_util_b);
	liste_util_b=create_liste_util_b();
	gtk_widget_show (liste_util_b);

	triew1 = lookup_widget(liste_util_b, "treeview_baha");
	afficher_baha(triew1);
}



void
on_supprimer_baha_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection2;
    GtkTreeIter iter;
    GtkTreeModel *model;
    GtkWidget *tree,*dialog;
        gchar *cin;
	gchar *nom;
	gchar *prenom;
       	gchar *numero_de_tel;
        gchar *jour;
	gchar *mois;
	gchar *annee;
	gchar *sexe;
	gchar *role;
	

    tree = lookup_widget(GTK_WIDGET(button), "treeview_baha");
    selection2 = gtk_tree_view_get_selection(GTK_TREE_VIEW(tree));

    if (gtk_tree_selection_get_selected(selection2, &model, &iter))
    {
       gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&cin,1,&nom,2,&prenom,3,&numero_de_tel,4,&jour,5,&mois,6,&annee,7,&sexe,8,&role,-1);
        gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
supprimer_baha(cin);
    }
else 
{dialog=gtk_message_dialog_new(GTK_WINDOW(dialog),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_WARNING,
			GTK_BUTTONS_OK,
			"Le mot de passe ou le username entré est incorrect");
			gtk_window_set_title(GTK_WINDOW(dialog),"Alerte");	
			gtk_dialog_run(GTK_DIALOG(dialog));
			gtk_widget_destroy(dialog);
}
}




void
on_deconnexion_baha_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

	GtkWidget *liste_util_b,*login_admin_b_j;
	liste_util_b=lookup_widget(GTK_WIDGET(button),"liste_util_b");
	gtk_widget_destroy(liste_util_b);
	login_admin_b_j=create_login_admin_b_j();
	gtk_widget_show (login_admin_b_j);


}


void on_statistique_baha_clicked(GtkButton *button, gpointer user_data)
{
    GtkWidget *liste_util_b, *pourcentage_par_sexe_b, *phh, *pff;
    liste_util_b = lookup_widget(GTK_WIDGET(button), "liste_util_b");
    gtk_widget_destroy(liste_util_b);
    pourcentage_par_sexe_b = create_pourcentage_par_sexe_b();
    gtk_widget_show(pourcentage_par_sexe_b);

    phh = lookup_widget(pourcentage_par_sexe_b, "pour_h");
    pff = lookup_widget(pourcentage_par_sexe_b, "pour_f");

    float p = statistique();
    float pf = (100 - p);
    char p1[40];
    char p2[40];
    sprintf(p1, "%.2f", p);
    sprintf(p2, "%.2f", pf);
    gtk_label_set_text(GTK_LABEL(phh), p1);
    gtk_label_set_text(GTK_LABEL(pff), p2);
}

void
on_acceuil2_baha_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *liste_util_b,*pourcentage_par_sexe_b,*triew1;
	pourcentage_par_sexe_b=lookup_widget(GTK_WIDGET(button),"pourcentage_par_sexe_b");
	gtk_widget_destroy(pourcentage_par_sexe_b);
	liste_util_b=create_liste_util_b();
	gtk_widget_show (liste_util_b);
	triew1 = lookup_widget(liste_util_b, "treeview_baha");
	afficher_baha(triew1);
}


void
on_deconnexion3_baha_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *pourcentage_par_sexe_b,*login;
	pourcentage_par_sexe_b=lookup_widget(GTK_WIDGET(button),"pourcentage_par_sexe_b");
	gtk_widget_destroy(pourcentage_par_sexe_b);
	login=create_login_admin_b_j();
	gtk_widget_show (login);
}




void
on_treeviewETS_row_activated           (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar *id;
gchar *ne;
gchar *delegation;
gchar *region;
gchar  *cap;

etablissement p;

GtkTreeModel *model=gtk_tree_view_get_model(treeview);


if(gtk_tree_model_get_iter(model,&iter,path))
{ 
gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&ne,2,&delegation,3,&region,4,&cap,-1);

strcpy(p.id,id);
strcpy(p.ne,ne);
strcpy(p.delegation,delegation);
strcpy(p.region,region);
strcpy(p.cap,cap);

afficherETS(treeview);
}
}


void
on_buttonsupprimerETS_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
    GtkTreeIter iter;
    GtkTreeModel *model;
    GtkWidget *treeviewETS;
        gchar *id;
	gchar *ne;
	gchar *delegation;
       	gchar *region;
        gchar *cap;
	
	

    treeviewETS = lookup_widget(GTK_WIDGET(button), "treeviewETS");
    selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeviewETS));

    if (gtk_tree_selection_get_selected(selection, &model, &iter))
    {
       gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0,&id,1,&ne,2,&delegation,3,&region,4,&cap, -1);
        gtk_list_store_remove(GTK_LIST_STORE(model), &iter);
        supprimerETS(id);
    }
}


void
on_buttonmodifierETS_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * listeETS=lookup_widget(GTK_WIDGET(button),"listeETS");

gtk_widget_destroy(listeETS);
GtkWidget * modifierETS_J=create_modifierETS_J();
gtk_widget_show (modifierETS_J);
}


void
on_buttonTri_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonajouterETS_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * listeETS=lookup_widget(GTK_WIDGET(button),"listeETS");

gtk_widget_destroy(listeETS);
GtkWidget * ajoutETS_J=create_ajoutETS_J();
gtk_widget_show (ajoutETS_J);
}


void
on_buttonacceuilETS_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttondec_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{


}


void
on_buttonchercherETS_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonRetourETS_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonconfirmerajoutETS_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
etablissement p;
int cap;
 GtkWidget *input1,*input2,*input3,*input4,*input5,*dialog;
GtkWidget *ajoutETS_J;
ajoutETS_J=lookup_widget(GTK_WIDGET(button),"ajoutETS_J");

            
input1=lookup_widget(GTK_WIDGET(button),"entryID");
input2=lookup_widget(GTK_WIDGET(button),"entrynomETS");
input3=lookup_widget(GTK_WIDGET(button),"comboboxentrydel");
input4=lookup_widget(GTK_WIDGET(button),"entryregion");
input5=lookup_widget(GTK_WIDGET(button),"spinbuttoncap");
char id[30];
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));


 FILE *f;
    f = fopen("/home/baha/Desktop/part/src/etablissement.txt", "r");

/*if (strcmp(id, "") == 0) {
        dialog = gtk_message_dialog_new(NULL,
                                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                                 GTK_MESSAGE_ERROR,
                                                 GTK_BUTTONS_OK,
                                                 "Saisir un ID");
                gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
                gtk_dialog_run(GTK_DIALOG(dialog));
                gtk_widget_destroy(dialog);
                return;
    }
   */
int found = 0; 
if (f != NULL)
    {
        

        while (fscanf(f, "%s %s %s %s %s\n",p.id,p.ne,p.delegation,p.region,p.cap) != EOF)
        {
            if (strcmp(id, p.id) == 0)
            {
                found = 1;
                break; 
            }
        }


}
if ((found == 0)&& (strcmp(id,"")!=0))
        {

	g_strlcpy(p.id, gtk_entry_get_text(GTK_ENTRY(input1)), sizeof(input1));
	g_strlcpy(p.ne, gtk_entry_get_text(GTK_ENTRY(input2)), sizeof(input2));
	strcpy(p.delegation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));


	g_strlcpy(p.region, gtk_entry_get_text(GTK_ENTRY(input4)), sizeof(input4));
	cap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
	sprintf(p.cap,"%d",cap);
 ajouterETS(p);
gtk_widget_destroy(ajoutETS_J);
GtkWidget * listeETS=create_listeETS();
gtk_widget_show (listeETS);

GtkWidget * treeviewETS=lookup_widget(listeETS,"treeviewETS");
afficherETS(treeviewETS);
        }

        else
        {
 
        dialog = gtk_message_dialog_new(NULL,
                                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                                 GTK_MESSAGE_ERROR,
                                                 GTK_BUTTONS_OK,
                                                 "ID déja existe");
                gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
                gtk_dialog_run(GTK_DIALOG(dialog));
                gtk_widget_destroy(dialog);
                return;
    
        }
    

//ajouterETS(p);
        fclose(f);



}


void
on_buttonRetourja_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * ajoutETS_J=lookup_widget(GTK_WIDGET(button),"ajoutETS_J");



GtkWidget * listeETS=create_listeETS();
gtk_widget_show (listeETS);
GtkWidget * treeviewETS=lookup_widget(listeETS,"treeviewETS");
afficherETS(treeviewETS);
}


void
on_buttonretourtableETS_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * modifierETS_J=lookup_widget(GTK_WIDGET(button),"modifierETS_J");

gtk_widget_destroy(modifierETS_J);
GtkWidget * listeETS=create_listeETS();
gtk_widget_show (listeETS);
GtkWidget * treeviewETS=lookup_widget(listeETS,"treeviewETS");
afficherETS(treeviewETS);
}


void
on_buttonconfirmermodif_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
etablissement E;
int cap;
 GtkWidget *input1,*input2,*input3,*input4,*input5,*dialog;
GtkWidget *modifierETS_J;
modifierETS_J=lookup_widget(GTK_WIDGET(button),"modifierETS_J");

									
input1=lookup_widget(GTK_WIDGET(button),"entryidmodif");
input2=lookup_widget(GTK_WIDGET(button),"entry6");
input3=lookup_widget(GTK_WIDGET(button),"comboboxentrymodif");
input4=lookup_widget(GTK_WIDGET(button),"entryregmodif");
input5=lookup_widget(GTK_WIDGET(button),"spinbuttoncapmodif");
int found;
char id[30];
strcpy(id,gtk_entry_get_text(GTK_ENTRY(input1)));


FILE *f;
    f = fopen("/home/baha/Desktop/part/src/etablissement.txt", "r");
if (f != NULL)
    {
        int found = 0; 

        while (fscanf(f, "%s %s %s %s %s\n",E.id,E.ne,E.delegation,E.region,E.cap) != EOF)
        {
            if (strcmp(id, E.id) == 0)
            {
                found = 1;
                break; 
            }
        }
}
if ((found == 1)&& (strcmp(id,"")!=0))
        {

	g_strlcpy(p.id, gtk_entry_get_text(GTK_ENTRY(input1)), sizeof(input1));
	g_strlcpy(p.ne, gtk_entry_get_text(GTK_ENTRY(input2)), sizeof(input2));
	strcpy(p.delegation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));


	g_strlcpy(p.region, gtk_entry_get_text(GTK_ENTRY(input4)), sizeof(input4));
	cap=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
	sprintf(p.cap,"%d",cap);
 
modifierETS(E.id,E);
gtk_widget_destroy(modifierETS_J);
GtkWidget * listeETS=create_listeETS();
gtk_widget_show (listeETS);

GtkWidget * treeviewETS=lookup_widget(listeETS,"treeviewETS");
afficherETS(treeviewETS);
        }
 else
        {
 
        dialog = gtk_message_dialog_new(NULL,
                                                 GTK_DIALOG_DESTROY_WITH_PARENT,
                                                 GTK_MESSAGE_ERROR,
                                                 GTK_BUTTONS_OK,
                                                 "Id n'existe pas");
                gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
                gtk_dialog_run(GTK_DIALOG(dialog));
                gtk_widget_destroy(dialog);
                return;
    
        }

 
   fclose(f);

}


void
on_treeviewtriregion_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonacceuiladmin1_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * triregion_J=lookup_widget(GTK_WIDGET(button),"triregion_J");

gtk_widget_destroy(triregion_J);
GtkWidget * acceuil_admin=create_acceuil_admin();
gtk_widget_show (acceuil_admin);
}


void
on_buttondec1_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *triregion_J,*login_admin_b_j;
	triregion_J=lookup_widget(GTK_WIDGET(button),"triregion_J");
	gtk_widget_destroy(triregion_J);
	login_admin_b_j=create_login_admin_b_j();
	gtk_widget_show (login_admin_b_j);
}


void
on_buttonretourgest_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * triregion_J=lookup_widget(GTK_WIDGET(button),"triregion_J");
gtk_widget_destroy(triregion_J);
GtkWidget * choixtri_J=create_choixtri_J();
gtk_widget_show (choixtri_J);
}


void
on_treeviewtricap_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_buttonretour2_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * tricap_J=lookup_widget(GTK_WIDGET(button),"tricap_J");

gtk_widget_destroy(tricap_J);
GtkWidget * choixtri_J=create_choixtri_J();
gtk_widget_show (choixtri_J);
}


void
on_buttondec4_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tricap_J,*login_admin_b_j;
	tricap_J=lookup_widget(GTK_WIDGET(button),"tricap_J");
	gtk_widget_destroy(tricap_J);
	login_admin_b_j=create_login_admin_b_j();
	gtk_widget_show (login_admin_b_j);
}


void
on_buttonaceuil2_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * tricap_J=lookup_widget(GTK_WIDGET(button),"tricap_J");

gtk_widget_destroy(tricap_J);
GtkWidget * acceuil_admin=create_acceuil_admin();
gtk_widget_show (acceuil_admin);
}


void
on_buttonLIsteparreg_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * choixtri_J=lookup_widget(GTK_WIDGET(button),"choixtri_J");

gtk_widget_destroy(choixtri_J);
GtkWidget * triregion_J=create_triregion_J();
gtk_widget_show (triregion_J);
}


void
on_buttonlisteparcap_enter             (GtkButton       *button,
                                        gpointer         user_data)
{
ETSTrieCapacite("/home/baha/Desktop/part/src/etablissement.txt");
GtkWidget * choixtri_J=lookup_widget(GTK_WIDGET(button),"choixtri_J");

gtk_widget_destroy(choixtri_J);
GtkWidget * tricap_J=create_tricap_J();
gtk_widget_show (tricap_J);

GtkWidget * treeviewtricap=lookup_widget(tricap_J,"treeviewtricap");
affichertricap(treeviewtricap);
}


void
on_buttonDonneur_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonresponsable_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonmedecin_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttoninfirmier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_buttongestionETS_enter              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * acceuil_admin=lookup_widget(GTK_WIDGET(button),"acceuil_admin");
gtk_widget_destroy(acceuil_admin);
GtkWidget * listeETS=create_listeETS();
gtk_widget_show(listeETS);

GtkWidget * treeviewETS=lookup_widget(listeETS,"treeviewETS");
afficherETS(treeviewETS);
}







void
on_treeview_baha_row_activated         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}











void
on_treeview2_baha_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_deconnexion2_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}





void
on_but_historique_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_but_rdv_dispo_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_but_gest_rdv_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_but_page_ajout_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_but_page_modif_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_but_page_supp_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_but_retour_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_deconn1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_acceuil1_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_confirmer_supp_enter                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_deconn2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_acceuil2_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_aff_informations_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_acceuil3_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_deconn3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_acceuil4_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour4_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_decc4_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour5_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_acceuil5_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_decc5_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_but_chercher2_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_acceuil6_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_decc6_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_retour6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}













void
on_buttonchercherregion_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *reg,*output;
char delegation[50];
output=lookup_widget(GTK_WIDGET(button),"labelcap");
reg=lookup_widget(GTK_WIDGET(button),"comboboxentrychercherregion");
strcpy(delegation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(reg)));
int x=ETSParRegion("/home/baha/Desktop/part/src/etablissement.txt",delegation);
char capa[50];
sprintf(capa,"%d",x);
GtkWidget *triregion_J;
gtk_label_set_text(GTK_LABEL(output),capa);
 GtkWidget *treeviewtriregion=lookup_widget(GTK_WIDGET(button),"treeviewtriregion");
 
affichertrireg(treeviewtriregion);
}





void
on_buttonretourjihenechoix_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * choixtri_J=lookup_widget(GTK_WIDGET(button),"choixtri_J");

gtk_widget_destroy(choixtri_J);
GtkWidget * listeETS=create_listeETS();
gtk_widget_show (listeETS);
GtkWidget *treeviewETS=lookup_widget(listeETS,"treeviewETS");
 
afficherETS(treeviewETS);
}



void
on_buttonretourAA_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * listeETS=lookup_widget(GTK_WIDGET(button),"listeETS");

gtk_widget_destroy(listeETS);
GtkWidget * acceuil_admin=create_acceuil_admin();
gtk_widget_show (acceuil_admin);
}


void
on_buttonacceuiladmin_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * listeETS=lookup_widget(GTK_WIDGET(button),"listeETS");

gtk_widget_destroy(listeETS);
GtkWidget * acceuil_admin=create_acceuil_admin();
gtk_widget_show (acceuil_admin);
}


void
on_button30_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *listeETS,*login_admin_b_j;
	listeETS=lookup_widget(GTK_WIDGET(button),"listeETS");
	gtk_widget_destroy(listeETS);
	login_admin_b_j=create_login_admin_b_j();
	gtk_widget_show (login_admin_b_j);
}


void
on_buttonchercher_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
etablissement d;
 GtkWidget *treeviewETS,*dialog;
    GtkWidget *entry;
    
    char cin1[30];

    entry = lookup_widget(GTK_WIDGET(button), "entrychercher");
    treeviewETS = lookup_widget(GTK_WIDGET(button), "treeviewETS");
    strcpy(cin1, gtk_entry_get_text(GTK_ENTRY(entry)));

    FILE *f;
    f = fopen("/home/baha/Desktop/part/src/etablissement.txt", "r");

           
         if (strcmp(cin1, "") == 0)
    {
        dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                        GTK_DIALOG_DESTROY_WITH_PARENT,
                                        GTK_MESSAGE_WARNING,
                                        GTK_BUTTONS_OK,
                                        "Saisir un identifiant");
        gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
        gtk_dialog_run(GTK_DIALOG(dialog));
        gtk_widget_destroy(dialog);
    }
else if (f != NULL)
    {
        int found = 0; 

        while (fscanf(f, "%s %s %s %s %s\n",d.id,d.ne,d.delegation,d.region,d.cap) != EOF)
        {
            if (strcmp(cin1, d.id) == 0)
            {
                found = 1;
                break; 
            }
        }

        fclose(f);

        if (found == 0)
        {
            dialog = gtk_message_dialog_new(GTK_WINDOW(dialog),
                                            GTK_DIALOG_DESTROY_WITH_PARENT,
                                            GTK_MESSAGE_WARNING,
                                            GTK_BUTTONS_OK,
                                            "Identifiant incorrect");
            gtk_window_set_title(GTK_WINDOW(dialog), "Alerte");
            gtk_dialog_run(GTK_DIALOG(dialog));
            gtk_widget_destroy(dialog);
        }
        else
        {
             chercherETS(treeviewETS, cin1);
        }
    }
    
}


void
on_buttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *treeviewETS;
	GtkWidget *listeETS;
	listeETS=lookup_widget(GTK_WIDGET(button),"listeETS");
	gtk_widget_destroy(listeETS);
	listeETS=create_listeETS();
	gtk_widget_show (listeETS);

	treeviewETS= lookup_widget(listeETS, "treeviewETS");
	afficherETS(treeviewETS);
}







void
on_buttonlistes_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * listeETS=lookup_widget(GTK_WIDGET(button),"listeETS");




gtk_widget_destroy(listeETS);
GtkWidget * choixtri_J=create_choixtri_J();
gtk_widget_show (choixtri_J);

}

