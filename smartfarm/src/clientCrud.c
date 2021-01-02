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
char cin[9];
char nom[30];
char prenom[30];
char sexe[30];
char dateNaissance[30];
char tel[30];
char addresse[30];
char email[30];
*/

void ajouter_Nouv_client(client c){
FILE*f=NULL;
f=fopen("client.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,c.promo,c.dateNaissance,c.tel,c.addresse,c.email);
fclose(f);
}

int exist_client(char*cin){
FILE*f=NULL;
 client c;
f=fopen("client.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,c.promo,c.dateNaissance,c.tel,c.addresse,c.email)!=EOF){
if(strcmp(c.cin,cin)==0)return 1;
}
fclose(f);
return 0;
}


client trouver_client(char*cin){
FILE*f=NULL;
client c ;
client c1 ;
int b=0;
f=fopen("client.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,c.promo,c.dateNaissance,c.tel,c.addresse,c.email)!=EOF){
if (strcmp(c.cin,cin)==0)
{
c1=c;
b=1;
}

}
fclose(f);
if(b==0){
strcpy(c1.cin,"notFound");
}

return  c1;


}

void modifier_client(char*cin,char*tel,char*addresse,char*email,char*promo){
FILE*f=NULL;
FILE*f1=NULL;
client c ;
f=fopen("client.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,c.promo,c.dateNaissance,c.tel,c.addresse,c.email)!=EOF){
if(strcmp(cin,c.cin)!=0){fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,c.promo,c.dateNaissance,c.tel,c.addresse,c.email);
}else{
fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,promo,c.dateNaissance,tel,addresse,email);
}
}
fclose(f);
fclose(f1);
remove("client.txt");
rename("ancien.txt","client.txt");
}


void afficher_client(GtkWidget* treeview1,char*l)
{

client c;


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
                                     G_TYPE_STRING);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,c.promo,c.dateNaissance,c.tel,c.addresse,c.email)!=EOF)
        {GtkTreeIter pIter;

         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,c.cin,
                            1,c.nom,
                            2,c.prenom,
                            3,c.sexe,
                            4,c.promo,
                            5,c.dateNaissance,
                            6,c.tel,
                            7,c.addresse,
                            8,c.email,
                            -1);}
        fclose(f);

	/* Creation de la 1ere colonne */
if(i==0)
	{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("CIN",
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
        adcolumn = gtk_tree_view_column_new_with_attributes("PRENOM",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("SEXE",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);









	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("AFFICHER PROMO",
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
        adcolumn = gtk_tree_view_column_new_with_attributes("TEL",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 7eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ADDRESSE",
                                                            cellad,
                                                            "text", 7,
                                                            NULL);
	/* Ajouter la 7emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 8eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("MAIL",
                                                            cellad,
                                                            "text", 8,
                                                            NULL);
	/* Ajouter la 8emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);





	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}




void supprimer_client(char*cin){


FILE*f=NULL;
FILE*f1=NULL;
client c ;
f=fopen("client.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,c.promo,c.dateNaissance,c.tel,c.addresse,c.email)!=EOF){
if(strcmp(cin,c.cin)!=0)fprintf(f1,"%s %s %s %s %s %s %s %s %s\n",c.cin,c.nom,c.prenom,c.sexe,c.promo,c.dateNaissance,c.tel,c.addresse,c.email);
}
fclose(f);
fclose(f1);
remove("client.txt");
rename("ancien.txt","client.txt");



}



