#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include <gtk/gtk.h>
#include "interface.h"


/*
char cin[9];
char nom[30];
char prenom[30];
char dateNaissance[30];
char permis[4];
char occupation[20];
char sexe[20];
char tel[9];
char email[20];
char adressePostale[20];

*/

//reserver treeView
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;



void ajouter_Nouv_ouvrier(ouvrier o){
FILE*f=NULL;
f=fopen("ouvrier.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",o.id,o.cin,o.nom,o.prenom,o.dateNaissance,o.permis,o.occupation,o.sexe,o.tel,o.email,o.adressePostale);
fclose(f);
}

int exist_ouvrier(char*id){
FILE*f=NULL;
 ouvrier o;
f=fopen("ouvrier.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",o.id,o.cin,o.nom,o.prenom,o.dateNaissance,o.permis,o.occupation,o.sexe,o.tel,o.email,o.adressePostale)!=EOF){
if(strcmp(o.id,id)==0)return 1;
}
fclose(f);
return 0;
}
ouvrier trouver_ouvrier(char*id){
FILE*f=NULL;
ouvrier o ;
ouvrier o1 ;
int b=0;
f=fopen("ouvrier.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",o.id,o.cin,o.nom,o.prenom,o.dateNaissance,o.permis,o.occupation,o.sexe,o.tel,o.email,o.adressePostale)!=EOF){
if (strcmp(o.id,id)==0)
{
o1=o;
b=1;
}

}
fclose(f);
if(b==0){
strcpy(o1.cin,"notFound");
}

return  o1;


}


void modifier_ouvrier(char*id,char*permis,char*occupation,char*tel,char*email,char*adressePostale){
FILE*f=NULL;
FILE*f1=NULL;
ouvrier o ;
f=fopen("ouvrier.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",o.id,o.cin,o.nom,o.prenom,o.dateNaissance,o.permis,o.occupation,o.sexe,o.tel,o.email,o.adressePostale)!=EOF){
if(strcmp(id,o.id)!=0){fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s\n",o.id,o.cin,o.nom,o.prenom,o.dateNaissance,o.permis,o.occupation,o.sexe,o.tel,o.email,o.adressePostale);
}else{
fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s\n",o.id,o.cin,o.nom,o.prenom,o.dateNaissance,permis,occupation,o.sexe,tel,email,adressePostale);
}
}
fclose(f);
fclose(f1);
remove("ouvrier.txt");
rename("ancien.txt","ouvrier.txt");

}

void supprimer_ouvrier(char*id){

FILE*f=NULL;
FILE*f1=NULL;
ouvrier o ;
f=fopen("ouvrier.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",o.id,o.cin,o.nom,o.prenom,o.dateNaissance,o.permis,o.occupation,o.sexe,o.tel,o.email,o.adressePostale)!=EOF){
if(strcmp(id,o.id)!=0)fprintf(f1,"%s %s %s %s %s %s %s %s %s %s %s\n",o.id,o.cin,o.nom,o.prenom,o.dateNaissance,o.permis,o.occupation,o.sexe,o.tel,o.email,o.adressePostale);
}
fclose(f);
fclose(f1);
remove("ouvrier.txt");
rename("ancien.txt","ouvrier.txt");
}



void afficher_ouvrier(GtkWidget* treeview1,char*l)
{

ouvrier o;


        /* Creation du modele */
        adstore = gtk_list_store_new(11,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %s %s\n",o.id,o.cin,o.nom,o.prenom,o.dateNaissance,o.permis,o.occupation,o.sexe,o.tel,o.email,o.adressePostale)!=EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,o.id,
                            1,o.cin,
                            2,o.nom,
                            3,o.prenom,
                            4,o.dateNaissance,
                            5,o.permis,
                            6,o.occupation,
                            7,o.sexe,
                            8,o.tel,
                            9,o.email,
                            10,o.adressePostale,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(i==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CIN",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PRENOM",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);









	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE NAISSANCE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PERMIS",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("OCCUPATION",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SEXE",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TEL",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("EMAIL",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ADRESSE POSTALE",
                                                            cellad,
                                                            "text", 10,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);







	i++;
}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}

void enregistrer_presence_ouvrier(absenteisme ab){

FILE*f=NULL;
f=fopen("absenteisme.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %d %d %d %d\n",ab.id,ab.jj,ab.mm,ab.aa,ab.present);
fclose(f);

}



void afficher_single_ouvrier(ouvrier o,GtkWidget* treeview1)
{




        /* Creation du modele */
        adstore = gtk_list_store_new(11,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */


        GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,o.id,
                            1,o.cin,
                            2,o.nom,
                            3,o.prenom,
                            4,o.dateNaissance,
                            5,o.permis,
                            6,o.occupation,
                            7,o.sexe,
                            8,o.tel,
                            9,o.email,
                            10,o.adressePostale,
                            -1);


	/* Creation de la 1ere colonne */
if(i==0){
	cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 2eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CIN",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PRENOM",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);









	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE NAISSANCE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PERMIS",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("OCCUPATION",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SEXE",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TEL",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("EMAIL",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ADRESSE POSTALE",
                                                            cellad,
                                                            "text", 10,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );



}







