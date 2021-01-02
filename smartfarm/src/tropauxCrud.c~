#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include <gtk/gtk.h>
#include "interface.h"
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
/*
char id[20];
char type[30];
char poids[30];
char veterinaire[30];
char signe[30];
char dateNaissance[30];
char zone[4];
char sexe[20];
int nbVaccin;
*/

void ajouter_Nouv_tropaux(tropaux t){
FILE*f=NULL;
f=fopen("tropaux.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %s %s %s %s %s %d\n",t.id,t.type,t.poids,t.veterinaire,t.signe,t.dateNaissance,t.zone,t.sexe,t.nbVaccin);
fclose(f);
}

int exist_tropaux(char*id){
FILE*f=NULL;
 tropaux t;
f=fopen("tropaux.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %d\n",t.id,t.type,t.poids,t.veterinaire,t.signe,t.dateNaissance,t.zone,t.sexe,&t.nbVaccin)!=EOF){
if(strcmp(t.id,id)==0)return 1;
}
fclose(f);
return 0;
}

tropaux trouver_tropaux(char*id){
FILE*f=NULL;
tropaux t ;
tropaux t1 ;
int b=0;
f=fopen("tropaux.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %d\n",t.id,t.type,t.poids,t.veterinaire,t.signe,t.dateNaissance,t.zone,t.sexe,&t.nbVaccin)!=EOF){
if (strcmp(t.id,id)==0)
{
t1=t;
b=1;
}

}
fclose(f);
if(b==0){
strcpy(t1.id,"notFound");
}

return  t1;


}


void modifier_tropaux(char*id,char*zone,char*veterinaire,char*signe,int nbVaccin){

FILE*f=NULL;
FILE*f1=NULL;
tropaux t ;
f=fopen("tropaux.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %d\n",t.id,t.type,t.poids,t.veterinaire,t.signe,t.dateNaissance,t.zone,t.sexe,&t.nbVaccin)!=EOF){
if(strcmp(id,t.id)!=0){fprintf(f1,"%s %s %s %s %s %s %s %s %d\n",t.id,t.type,t.poids,t.veterinaire,t.signe,t.dateNaissance,t.zone,t.sexe,t.nbVaccin);
}else{
fprintf(f1,"%s %s %s %s %s %s %s %s %d\n",t.id,t.type,t.poids,veterinaire,signe,t.dateNaissance,zone,t.sexe,nbVaccin);
}
}
fclose(f);
fclose(f1);
remove("tropaux.txt");
rename("ancien.txt","tropaux.txt");


}


void supprimer_tropaux(char*id){


FILE*f=NULL;
FILE*f1=NULL;
tropaux t ;
f=fopen("tropaux.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %d\n",t.id,t.type,t.poids,t.veterinaire,t.signe,t.dateNaissance,t.zone,t.sexe,&t.nbVaccin)!=EOF){
if(strcmp(id,t.id)!=0)fprintf(f1,"%s %s %s %s %s %s %s %s %d\n",t.id,t.type,t.poids,t.veterinaire,t.signe,t.dateNaissance,t.zone,t.sexe,t.nbVaccin);
}
fclose(f);
fclose(f1);
remove("tropaux.txt");
rename("ancien.txt","tropaux.txt");




}


void afficher_tropaux(GtkWidget* treeview1,char*l)
{

tropaux t;


        /* Creation du modele */
        adstore = gtk_list_store_new(9,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %d\n",t.id,t.type,t.poids,t.veterinaire,t.signe,t.dateNaissance,t.zone,t.sexe,&t.nbVaccin)!=EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,t.id,
                            1,t.type,
                            2,t.poids,
                            3,t.veterinaire,
                            4,t.signe,
                            5,t.dateNaissance,
                            6,t.zone,
                            7,t.sexe,
                            8,t.nbVaccin,
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
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("POIDS A LA NAISSANCE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("VETERINAIRE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);









	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SIGNE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE NAISSANCE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ZONE",
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
        adcolumn = gtk_tree_view_column_new_with_attributes("NOMBRE DE VACCIN",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	

	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}



int rechercher_tropaux_par_type(GtkWidget* treeview1,char*l,char*type){


tropaux t;
int s=0;

        /* Creation du modele */
        adstore = gtk_list_store_new(9,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_INT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %d\n",t.id,t.type,t.poids,t.veterinaire,t.signe,t.dateNaissance,t.zone,t.sexe,&t.nbVaccin)!=EOF)
        {GtkTreeIter pIter;
	if(strcmp(t.type,type)==0){s++;
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,t.id,
                            1,t.type,
                            2,t.poids,
                            3,t.veterinaire,
                            4,t.signe,
                            5,t.dateNaissance,
                            6,t.zone,
                            7,t.sexe,
                            8,t.nbVaccin,
                            -1);}
		}
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
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("POIDS A LA NAISSANCE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("VETERINAIRE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);









	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SIGNE",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE NAISSANCE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ZONE",
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
        adcolumn = gtk_tree_view_column_new_with_attributes("NOMBRE DE VACCIN",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	

	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );








return s;



}
















