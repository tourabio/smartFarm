#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include "callbacks.h"
#include "ouvrierCrud.h"

int exist_annee(tabAnneeMoy*e,int n,int aa){
int i=0;
for(i=0;i<n;i++){
    if(e[i].aa==aa)return 1;
}
return 0;
}
int remplir_annees(tabAnneeMoy*e,char*fich){
FILE*f=NULL;
int i=-1;
temperature t;
f=fopen(fich,"r");
while(fscanf(f,"%s %d %d %d %f\n",t.idCapteur,&t.jj,&t.mm,&t.aa,&t.valeur)!=EOF){
if(exist_annee(e,i+1,t.aa)==0){
i++;
e[i].aa=t.aa;

}
}
fclose(f);
return i+1;
}
int maximum(tabAnneeMoy*e,int n){
int i,max_annee = e[0].aa;
float max_val=e[0].moy;
for (i=1;i<n;i++){
if(e[i].moy >max_val){
    max_val = e[i].moy ;
    max_annee = e[i].aa;
}

}
return max_annee;

}


float calculer_moy(int aa, char*fich){
float s=0;
int i=0;
temperature t;
FILE*f=NULL;
f=fopen(fich,"r");
while(fscanf(f,"%s %d %d %d %f\n",t.idCapteur,&t.jj,&t.mm,&t.aa,&t.valeur)!=EOF){
        if(t.aa==aa){
            s+=t.valeur;
            i++;
        }
}
fclose(f);
return s/i;
}


int trouver_annee_plus_seche(char*fich){
tabAnneeMoy e[50];
int j,n,annee_max;
n = remplir_annees(e,fich);
for (j=0;j<n;j++){
    e[j].moy = calculer_moy(e[j].aa, fich);
}

annee_max=maximum(e,n);


return annee_max;


}

/*********************************************************************************/















int exist_ouvrier_tab(tabOuvrierAbs*e,int n,int id){
int i=0;
for(i=0;i<n;i++){
    if(e[i].id_ouv==id)return 1;
}
return 0;
}


int remplir_tabOuvrier(tabOuvrierAbs*e,int aa){
FILE*f=NULL;
int i=-1,id;
absenteisme a;
f=fopen("absenteisme.txt","r");
while(fscanf(f,"%s %d %d %d %d\n",a.id,&a.jj,&a.mm,&a.aa,&a.present)!=EOF){
        if(aa==a.aa){
                 sscanf(a.id,"%d",&id);
            if(exist_ouvrier_tab(e,i+1,id)==0){
            i++;
            e[i].id_ouv = id;
            }
}
}
fclose(f);
return i+1;
}






int calculer_somme(char*id,int flag,int aa){
    FILE*f=NULL;
int s=0;
absenteisme a;


f=fopen("absenteisme.txt","r");
while(fscanf(f,"%s %d %d %d %d\n",a.id,&a.jj,&a.mm,&a.aa,&a.present)!=EOF){
        if(strcmp(id,a.id)==0 && a.present==flag && a.aa==aa){
        s++;
        }
}
fclose(f);
return s;
}
int maximum_abs(tabOuvrierAbs*e,int n){
int i,max_id = e[0].id_ouv;
int max_val=e[0].somme_abs;
for (i=1;i<n;i++){
if(e[i].somme_abs >max_val){
    max_val = e[i].somme_abs ;
    max_id = e[i].id_ouv;
}
}
return max_id;
}

ouvrier trouver_meilleur(int aa,int flag){
tabOuvrierAbs e[50];
int j,n,max;
char chId[30];
n = remplir_tabOuvrier(e,aa);
//printf("n = %d\n",n);
for (j=0;j<n;j++){
    //printf("%d\n",e[j].id_ouv);
    sprintf(chId,"%d",e[j].id_ouv);
    e[j].somme_abs = calculer_somme(chId,flag,aa);
    //printf("%d\n",e[j].somme_abs);
}
max=maximum(e,n);
//printf("max_id = %d\n",max );
sprintf(chId,"%d",max);




return trouver_ouvrier(chId);
}




























