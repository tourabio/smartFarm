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
char type[30];
char zone[30];
char precision[4];
char dateEntretien[30];
*/

void ajouter_Nouv_capteur(capteur cap){
FILE*f=NULL;
f=fopen("capteur.txt","a+");//(+) creation du fichier sil nexsite pas
fprintf(f,"%s %s %s %s %s %s %d\n",cap.id,cap.type,cap.marque,cap.zone,cap.precision,cap.dateEntretien,cap.defectueux);
fclose(f);
}

int exist_capteur(char*id){
FILE*f=NULL;
capteur cap;
f=fopen("capteur.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %d\n",cap.id,cap.type,cap.marque,cap.zone,cap.precision,cap.dateEntretien,&cap.defectueux)!=EOF){
if(strcmp(cap.id,id)==0)return 1;
}
fclose(f);
return 0;
}
capteur trouver_capteur(char*id) {

FILE*f=NULL;
capteur cap ;
capteur cap1 ;
int b=0;
f=fopen("capteur.txt","r");
while(fscanf(f,"%s %s %s %s %s %s %d\n",cap.id,cap.type,cap.marque,cap.zone,cap.precision,cap.dateEntretien,&cap.defectueux)!=EOF){
if (strcmp(cap.id,id)==0)
{
cap1=cap;
b=1;
}

}
fclose(f);
if(b==0){
strcpy(cap1.id,"notFound");
}

return  cap1;




}

void modifier_capteur(char*id,char*zone,char*precision,char*dateEntretien,int defectueux){


FILE*f=NULL;
FILE*f1=NULL;
capteur cap ;
f=fopen("capteur.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %d\n",cap.id,cap.type,cap.marque,cap.zone,cap.precision,cap.dateEntretien,&cap.defectueux)!=EOF){
if(strcmp(id,cap.id)!=0){fprintf(f1,"%s %s %s %s %s %s %d\n",cap.id,cap.type,cap.marque,cap.zone,cap.precision,cap.dateEntretien,cap.defectueux);
}else{
fprintf(f1,"%s %s %s %s %s %s %d\n",cap.id,cap.type,cap.marque,zone,precision,dateEntretien,defectueux);
}
}
fclose(f);
fclose(f1);
remove("capteur.txt");
rename("ancien.txt","capteur.txt");


}

void afficher_capteur(GtkWidget* treeview1,char*l){


capteur cap;
char precision[50];
/*
char id[30];
char type[30];
char zone[30];
char precision[4];
char dateEntretien[30];
*/
        /* Creation du modele */
        adstore = gtk_list_store_new(7,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
                                     G_TYPE_STRING,
				     G_TYPE_INT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%s %s %s %s %s %s %d\n",cap.id,cap.type,cap.marque,cap.zone,cap.precision,cap.dateEntretien,&cap.defectueux)!=EOF)
        {GtkTreeIter pIter;
strcpy(precision,"");
if(cap.precision[0]=='A'){
		strcat(precision,"fort");
			}
if(cap.precision[1]=='B'){
		strcat(precision,"/faible");
			}
if(cap.precision[2]=='C'){
		strcat(precision,"/moyenne");
			}
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,cap.id,
                            1,cap.type,
                            2,cap.marque,
                            3,cap.zone,
                            4,precision,
			    5,cap.dateEntretien,
			    6,cap.defectueux,

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
        adcolumn = gtk_tree_view_column_new_with_attributes("MARQUE",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

	/* Creation de la 3eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ZONE DE CAPTEUR",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);
	/* Ajouter la 3emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);









	/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("PRECISION",
                                                            cellad,
                                                            "text", 4,
                                                            NULL);
	/* Ajouter la 4emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DATE Entretien",
                                                            cellad,
                                                            "text", 5,
                                                            NULL);
	/* Ajouter la 5emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);

/* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("DEFECTUEUX",
                                                            cellad,
                                                            "text", 6,
                                                            NULL);
	/* Ajouter la 6emme colonne à la vue */
	gtk_tree_view_append_column(GTK_TREE_VIEW(treeview1), adcolumn);






	i++;}


 	gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview1),
                                  GTK_TREE_MODEL(adstore)  );

}
void supprimer_capteur(char*id){

FILE*f=NULL;
FILE*f1=NULL;
capteur cap ;
f=fopen("capteur.txt","r");

f1=fopen("ancien.txt","w+");
while(fscanf(f,"%s %s %s %s %s %s %d\n",cap.id,cap.type,cap.marque,cap.zone,cap.precision,cap.dateEntretien,&cap.defectueux)!=EOF){
if(strcmp(id,cap.id)!=0)fprintf(f1,"%s %s %s %s %s %s %d\n",cap.id,cap.type,cap.marque,cap.zone,cap.precision,cap.dateEntretien,cap.defectueux);
}
fclose(f);
fclose(f1);
remove("capteur.txt");
rename("ancien.txt","capteur.txt");




}


/************************************************/
int exist_cap(tabCapteurs*e,int n,int id){
int i=0;
for(i=0;i<n;i++){
    if(e[i].id_cap==id)return 1;
}
return 0;
}



int remplire_numero(tabCapteurs*e,int aa,char*fich){
FILE*f=NULL;
int i=-1,id;
temperature t;
f=fopen(fich,"r");
while(fscanf(f,"%s %d %d %d %f\n",t.idCapteur,&t.jj,&t.mm,&t.aa,&t.valeur)!=EOF){
        if(t.aa ==aa){
sscanf(t.idCapteur,"%d",&id);
if(exist_cap(e,i+1,id)==0){
i++;
e[i].id_cap=id;
}
}
}

fclose(f);
return i+1;
}

float calculer_max(int id,int aa,char*fich){
FILE*f=NULL;
int id1;
float max=-500;
temperature t;
f=fopen(fich,"r");
while(fscanf(f,"%s %d %d %d %f\n",t.idCapteur,&t.jj,&t.mm,&t.aa,&t.valeur)!=EOF){
sscanf(t.idCapteur,"%d",&id1);
if(aa==t.aa && id==id1){

if(t.valeur>max){
    max=t.valeur;
}

}

}
fclose(f);
return max;
}
float calculer_min(int id,int aa,char*fich){
FILE*f=NULL;
int id1;
float min=1000;
temperature t;
f=fopen(fich,"r");
while(fscanf(f,"%s %d %d %d %f\n",t.idCapteur,&t.jj,&t.mm,&t.aa,&t.valeur)!=EOF){
sscanf(t.idCapteur,"%d",&id1);
if(aa==t.aa && id==id1){

if(t.valeur<min){
    min=t.valeur;
}

}
}
fclose(f);
return min;
}

int remplire_id_capt(char*fich,int aa,float seuil_minA,float seuil_minB,float seuil_maxA,float seuil_maxB,int*capt){
int n,j=-1,i;
tabCapteurs e[50];



n = remplire_numero(e,aa,fich);


for (i=0;i<n;i++){
    printf("id = %d \t",e[i].id_cap);
    e[i].max_cap = calculer_max(e[i].id_cap,aa,fich);
    e[i].min_cap = calculer_min(e[i].id_cap,aa,fich);
    printf("max_cap=%f\t",e[i].max_cap);
    printf("min_cap = %f\n",e[i].min_cap);

    if((e[i].min_cap>=-3 && e[i].min_cap<=-1) ||  (e[i].max_cap>=50 && e[i].max_cap<=69)    ){

        j++;
        capt[j]=e[i].id_cap;
        printf("\n in intervalle [-3,-1] ou [50,69] : %d\n",capt[j]);

    }
}

return j+1;
}



/************************************************************************/

int remplire_tabCapteurs_def(char*fich,int aa,float seuil_minA,float seuil_minB,float seuil_maxA,float seuil_maxB,int*capt){
int n,j=-1,i;
tabCapteurs e[50];



n = remplire_numero(e,aa,fich);


for (i=0;i<n;i++){
    e[i].max_cap = calculer_max(e[i].id_cap,aa,fich);
    e[i].min_cap = calculer_min(e[i].id_cap,aa,fich);
    printf("min_cap = %f\n",e[i].min_cap);
    printf("max_cap=%f\n",e[i].max_cap);

    if((e[i].min_cap>=-500 && e[i].min_cap<=-4) ||  (e[i].max_cap>=70 && e[i].max_cap<=1000)    ){
        j++;
        capt[j]=e[i].id_cap;
        printf("in intervalle (min)[-500,-4] ou [60,1000](max) : %d\n",capt[j]);
    }
}

return j+1;
}


int exist_marque(tabCapteurs_def*e,int n,char*marque){
int i=0;
for(i=0;i<n;i++){
    if(strcmp(e[i].marque,marque)==0)return 1;
}
return 0;
}
















