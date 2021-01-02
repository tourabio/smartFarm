#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include<string.h>
#include <gtk/gtk.h>
#include "interface.h"
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
/*
char id[30];
char nom[30];
char genre[30];
char nouv[3];
char datePlantation[30];
char dateRecolte[30];
char dateArrosage[30];
char dateDefloration[30];
char type[30];
int qtt;
*/


void ajouter_Nouv_agriculture(agriculture a){
FILE*f=NULL;
f=fopen("agriculture.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %s %s %s %s %s %s %d\n",a.id,a.nom,a.genre,a.nouv,a.datePlantation,a.dateRecolte,a.dateArrosage,a.dateDefloration,a.type,a.qtt);
fclose(f);
}

int exist_agriculture(char*id){
FILE*f=NULL;
 agriculture a;
f=fopen("agriculture.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %d\n",a.id,a.nom,a.genre,a.nouv,a.datePlantation,a.dateRecolte,a.dateArrosage,a.dateDefloration,a.type,&a.qtt)!=EOF){
if(strcmp(a.id,id)==0)return 1;
}
fclose(f);
return 0;
}

agriculture trouver_agriculture(char*id){

FILE*f=NULL;
agriculture a ;
agriculture a1 ;
int b=0;
f=fopen("agriculture.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %d\n",a.id,a.nom,a.genre,a.nouv,a.datePlantation,a.dateRecolte,a.dateArrosage,a.dateDefloration,a.type,&a.qtt)!=EOF){
if (strcmp(a.id,id)==0)
{
a1=a;
b=1;
}

}
fclose(f);
if(b==0){
strcpy(a1.id,"notFound");
}

return  a1;






}

void modifier_agriculture(char*id,char*nom,char*dateRecolte,char*dateArrosage,char*nouv,int qtt){


FILE*f=NULL;
FILE*f1=NULL;
agriculture a ;
f=fopen("agriculture.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %d\n",a.id,a.nom,a.genre,a.nouv,a.datePlantation,a.dateRecolte,a.dateArrosage,a.dateDefloration,a.type,&a.qtt)!=EOF){
if(strcmp(id,a.id)!=0){fprintf(f1,"%s %s %s %s %s %s %s %s %s %d\n",a.id,a.nom,a.genre,a.nouv,a.datePlantation,a.dateRecolte,a.dateArrosage,a.dateDefloration,a.type,a.qtt);
}else{
fprintf(f1,"%s %s %s %s %s %s %s %s %s %d\n",a.id,nom,a.genre,nouv,a.datePlantation,dateRecolte,dateArrosage,a.dateDefloration,a.type,qtt);
}
}
fclose(f);
fclose(f1);
remove("agriculture.txt");
rename("ancien.txt","agriculture.txt");






}



void afficher_agriculture(GtkWidget* treeview1,char*l)
{

agriculture a;
char nouv[30];
/*
char id[30];
char nom[30];
char genre[30];
char nouv[3];
char datePlantation[30];
char dateRecolte[30];
char dateArrosage[30];
char dateDefloration[30];
char type[30];
int qtt;
*/

        /* Creation du modele */
        adstore = gtk_list_store_new(10,
                                     G_TYPE_STRING,
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
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %d\n",a.id,a.nom,a.genre,a.nouv,a.datePlantation,a.dateRecolte,a.dateArrosage,a.dateDefloration,a.type,&a.qtt)!=EOF)
        {GtkTreeIter pIter;
strcpy(nouv,"");
if(a.nouv[0]=='O'){
		strcat(nouv,"Oui");
			}
if(a.nouv[1]=='N'){
		strcat(nouv,"/Non");
			}
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,a.id,
                            1,a.nom,
                            2,a.genre,
                            3,nouv,
                            4,a.datePlantation,
                            5,a.dateRecolte,
                            6,a.dateArrosage,
                            7,a.dateDefloration,
                            8,a.type,
                            9,a.qtt,
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
        adcolumn = gtk_tree_view_column_new_with_attributes("NOM",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
	/* Ajouter la 2emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("GENRE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("NOUVELLE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);









	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE PLANTATION",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE RECOLTE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE ARROSAGE",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE DEFLORATION",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);


	/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("TYPE",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 9eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("QUANTITE",
                                                            cellad,
                                                            "text", 9,
                                                            NULL);
	/* Ajouter la 9emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	

	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}




void supprimer_agriculture(char*id){
FILE*f=NULL;
FILE*f1=NULL;
agriculture a ;
f=fopen("agriculture.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s %d\n",a.id,a.nom,a.genre,a.nouv,a.datePlantation,a.dateRecolte,a.dateArrosage,a.dateDefloration,a.type,&a.qtt)!=EOF){
if(strcmp(id,a.id)!=0)fprintf(f1,"%s %s %s %s %s %s %s %s %s %d\n",a.id,a.nom,a.genre,a.nouv,a.datePlantation,a.dateRecolte,a.dateArrosage,a.dateDefloration,a.type,a.qtt);
}
fclose(f);
fclose(f1);
remove("agriculture.txt");
rename("ancien.txt","agriculture.txt");



}











































