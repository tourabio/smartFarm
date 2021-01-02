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



void ajouter_Nouv_equipement(equipement e){
FILE*f=NULL;
f=fopen("equipement.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %s %s %s %s\n",e.id,e.type,e.remarque,e.immatricule,e.dateUtilisation,e.materielDispo,e.materielUtiliser);
fclose(f);
}

int exist_equipement(char*id){
FILE*f=NULL;
equipement e;
f=fopen("equipement.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s\n",e.id,e.type,e.remarque,e.immatricule,e.dateUtilisation,e.materielDispo,e.materielUtiliser)!=EOF){
if(strcmp(e.id,id)==0)return 1;
}
fclose(f);
return 0;
}


equipement trouver_equipement(char*id){
FILE*f=NULL;
equipement e ;
equipement e1 ;
int b=0;
f=fopen("equipement.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s\n",e.id,e.type,e.remarque,e.immatricule,e.dateUtilisation,e.materielDispo,e.materielUtiliser)!=EOF){
if (strcmp(e.id,id)==0)
{
e1=e;
b=1;
}

}
fclose(f);
if(b==0){
strcpy(e1.id,"notFound");
}

return  e1;


}



void modifier_equipement(char*id,char*remarque,char*dateUtilisation,char*materielDispo,char*materielUtiliser){

FILE*f=NULL;
FILE*f1=NULL;
equipement e ;
f=fopen("equipement.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s\n",e.id,e.type,e.remarque,e.immatricule,e.dateUtilisation,e.materielDispo,e.materielUtiliser)!=EOF){
if(strcmp(id,e.id)!=0){fprintf(f1,"%s %s %s %s %s %s %s\n",e.id,e.type,e.remarque,e.immatricule,e.dateUtilisation,e.materielDispo,e.materielUtiliser);
}else{
fprintf(f1,"%s %s %s %s %s %s %s\n",e.id,e.type,remarque,e.immatricule,dateUtilisation,materielDispo,materielUtiliser);
}
}
fclose(f);
fclose(f1);
remove("equipement.txt");
rename("ancien.txt","equipement.txt");















}






void afficher_equipement(GtkWidget* treeview1,char*l)
{

equipement e;
char materielUtiliser[50];

        /* Creation du modele */
        adstore = gtk_list_store_new(7,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s %s\n",e.id,e.type,e.remarque,e.immatricule,e.dateUtilisation,e.materielDispo,e.materielUtiliser)!=EOF)
        {GtkTreeIter pIter;
strcpy(materielUtiliser,"");
if(e.materielUtiliser[0]=='A'){
		strcat(materielUtiliser,"Marteaux");
			}
if(e.materielUtiliser[1]=='B'){
		strcat(materielUtiliser,"/Faucheuses");
			}
if(e.materielUtiliser[2]=='C'){
		strcat(materielUtiliser,"/Broyeurs");
			}
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,e.id,
                            1,e.type,
                            2,e.remarque,
                            3,e.immatricule,
                            4,e.dateUtilisation,
                            5,e.materielDispo,
                            6,materielUtiliser,
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
        adcolumn = gtk_tree_view_column_new_with_attributes("REMARQUE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("IMMATRICULE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);









	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE UTILISATION",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MATERIEL DISPONIBLE",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MATERIEL DISPONIBLE",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);






	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}



void supprimer_equipement(char*id){
FILE*f=NULL;
FILE*f1=NULL;
equipement e ;
f=fopen("equipement.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s\n",e.id,e.type,e.remarque,e.immatricule,e.dateUtilisation,e.materielDispo,e.materielUtiliser)!=EOF){
if(strcmp(id,e.id)!=0)fprintf(f1,"%s %s %s %s %s %s %s\n",e.id,e.type,e.remarque,e.immatricule,e.dateUtilisation,e.materielDispo,e.materielUtiliser);
}
fclose(f);
fclose(f1);
remove("equipement.txt");
rename("ancien.txt","equipement.txt");



}





















