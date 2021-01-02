#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include"ouvrierCrud.h"
#include"tropauxCrud.h"
#include"equipementCrud.h"
#include"clientCrud.h"
#include"capteurCrud.h"
#include"agricultureCrud.h"
#include"dashboard.h"

void
on_button_login_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
char username[30];
char password[30];
int b=1;
GtkWidget *entryUsername;
GtkWidget *entryPassword;
/*les labels*/
GtkWidget* LUsername;
GtkWidget* Lpassword;
GtkWidget* Linexistant;

entryUsername=lookup_widget(login,"entry1");
entryPassword=lookup_widget(login,"entry2");

LUsername=lookup_widget(login,"label5");
Lpassword=lookup_widget(login,"label6");
Linexistant=lookup_widget(login,"label2");

strcpy(username,gtk_entry_get_text(GTK_ENTRY(entryUsername) ) );
strcpy(password,gtk_entry_get_text(GTK_ENTRY(entryPassword) ) );




/*Controle saisie*/
/*
if(strcmp(username,"")==0){
		  gtk_widget_show (LUsername);
b=0;
}
else {
		  gtk_widget_hide(LUsername);
}

if(strcmp(password,"")==0){
		  gtk_widget_show (Lpassword);
b=0;
}
else {
		  gtk_widget_hide(Lpassword);
}




if(b==1){

if(strcmp(username,"Admin")!=0 || strcmp(password,"Admin")!=0){
		  gtk_widget_show (Linexistant);

}
else {
		  gtk_widget_hide(Linexistant);
*/
menu = create_menu ();
gtk_widget_show (menu);
gtk_widget_destroy (login);

//}


//}

}


void
on_button_logout_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
login = create_login ();
gtk_widget_show (login);
gtk_widget_destroy (menu);
}


void
on_button_gest_ouvrier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
gestion_ouvrier = create_gestion_ouvrier ();


/*Preparation Treeview*/
GtkWidget *p;


p=lookup_widget(gestion_ouvrier,"treeview1");

i=0;


afficher_ouvrier(p,"ouvrier.txt");

gtk_widget_show (gestion_ouvrier);

gtk_widget_hide (menu);
}


void
on_retour_ouvrier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

gtk_widget_show (menu);
gtk_widget_destroy (gestion_ouvrier);
}


void
on_ajouter_ouvrier_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{


ouvrier o;
strcpy(o.permis ,"---");


GtkWidget *entryID;
GtkWidget *entryCin;
GtkWidget *entryNom;
GtkWidget *entryPrenom;
GtkWidget *entryTel;
GtkWidget *entryEmail;
GtkWidget *entryNumtel;
GtkWidget *entryAdresse;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;



GtkWidget *comboOccupation;
GtkWidget *calendar;
int jj,mm,aa,b=1;
GtkWidget *p;
p=lookup_widget(gestion_ouvrier,"treeview1");





// associer les variables aux composantes glade
entryID=lookup_widget(gestion_ouvrier,"entry10");
entryCin=lookup_widget(gestion_ouvrier,"entry3");
entryNom=lookup_widget(gestion_ouvrier,"entry4");
entryPrenom=lookup_widget(gestion_ouvrier,"entry6");
entryEmail=lookup_widget(gestion_ouvrier,"entry9");
entryTel=lookup_widget(gestion_ouvrier,"entry7");
entryAdresse=lookup_widget(gestion_ouvrier,"entry8");


check1=lookup_widget(gestion_ouvrier,"checkbutton1");
check2=lookup_widget(gestion_ouvrier,"checkbutton2");
check3=lookup_widget(gestion_ouvrier,"checkbutton3");


radiobutt1=lookup_widget(gestion_ouvrier,"radiobutton1");
radiobutt2=lookup_widget(gestion_ouvrier,"radiobutton2");

comboOccupation=lookup_widget(gestion_ouvrier,"combobox1");
calendar=lookup_widget(gestion_ouvrier,"calendar1");



//recuperation des donnees
 strcpy(o.id,gtk_entry_get_text(GTK_ENTRY(entryID)));
 strcpy(o.cin,gtk_entry_get_text(GTK_ENTRY(entryCin)));
 strcpy(o.nom,gtk_entry_get_text(GTK_ENTRY(entryNom)));
 strcpy(o.prenom,gtk_entry_get_text(GTK_ENTRY(entryPrenom)));
 strcpy(o.tel,gtk_entry_get_text(GTK_ENTRY(entryTel)));
 strcpy(o.email,gtk_entry_get_text(GTK_ENTRY(entryEmail)));
 strcpy(o.adressePostale,gtk_entry_get_text(GTK_ENTRY(entryAdresse)));





if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
o.permis[0]='A';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
o.permis[1]='B';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check3) )){
o.permis[2]='C';
}



if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(o.sexe,"femme");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(o.sexe,"homme");
}

//hide label success
gtk_widget_hide (lookup_widget(gestion_ouvrier,"label46"));




/*Controle saisie*/
if(strcmp(o.id,"")==0){
		  gtk_widget_show (lookup_widget(gestion_ouvrier,"label37"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_ouvrier,"label37"));
}



if(strcmp(o.cin,"")==0){
		  gtk_widget_show (lookup_widget(gestion_ouvrier,"label40"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_ouvrier,"label40"));
}


if(strcmp(o.nom,"")==0){
		  gtk_widget_show (lookup_widget(gestion_ouvrier,"label39"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_ouvrier,"label39"));
}


if(strcmp(o.prenom,"")==0){
		  gtk_widget_show (lookup_widget(gestion_ouvrier,"label38"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_ouvrier,"label38"));
}

if(strcmp(o.tel,"")==0){
		  gtk_widget_show (lookup_widget(gestion_ouvrier,"label45"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_ouvrier,"label45"));
}

if(strcmp(o.adressePostale,"")==0){
		  gtk_widget_show (lookup_widget(gestion_ouvrier,"label44"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_ouvrier,"label44"));
}
if(strcmp(o.email,"")==0){
		  gtk_widget_show (lookup_widget(gestion_ouvrier,"label41"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_ouvrier,"label41"));
}




if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboOccupation))==-1){
                gtk_widget_show (lookup_widget(gestion_ouvrier,"label43"));
b=0;
}
else{

           gtk_widget_hide (lookup_widget(gestion_ouvrier,"label43"));
}







if(b==1){



strcpy(o.occupation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboOccupation)));




gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);//fct GTK pour recuperer la date

//convertion int => chaine
sprintf(o.dateNaissance,"%d/%d/%d",jj,mm+1,aa);


if(exist_ouvrier(o.id)==1)
        {

				  gtk_widget_show (lookup_widget(gestion_ouvrier,"label42"));
        }
        else {
						  gtk_widget_hide (lookup_widget(gestion_ouvrier,"label42"));
                ajouter_Nouv_ouvrier(o);

						  gtk_widget_show (lookup_widget(gestion_ouvrier,"label46"));
		/*Mise a jour treeView*/

		afficher_ouvrier(p,"ouvrier.txt");
        }




}




}


void
on_button_consulter_ouvrier_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
char id[20];
int b=1,x1;
GtkWidget *entryID;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;
ouvrier o ;
entryID=lookup_widget(gestion_ouvrier,"entry11");
check1=lookup_widget(gestion_ouvrier,"checkbutton4");
check2=lookup_widget(gestion_ouvrier,"checkbutton5");
check3=lookup_widget(gestion_ouvrier,"checkbutton6");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));
//controle saisie
if(strcmp(id,"")==0){
		  gtk_widget_show (lookup_widget(gestion_ouvrier,"label48"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_ouvrier,"label48"));
}




if(b==1){

o=trouver_ouvrier(id);
if(strcmp(o.cin,"notFound")==0){

gtk_widget_show (lookup_widget(gestion_ouvrier,"label61"));

}
else
{
//remplire les donnees
gtk_widget_hide (lookup_widget(gestion_ouvrier,"label61"));
gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_ouvrier,"entry12")),o.email);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_ouvrier,"entry13")),o.tel);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_ouvrier,"entry14")),o.adressePostale);


if(o.permis[0]=='A'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check1),TRUE );
printf("%s","check1");
}

if(o.permis[1]=='B'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check2),TRUE );
printf("%s","check2");
}

if(o.permis[2]=='C'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check3),TRUE );
printf("%s","check3");
}


if(strcmp(o.occupation,"chef_de_ferme")==0)x1=0;//signifie 1er choix		
if(strcmp(o.occupation,"ouvrier")==0)x1=1;                
if(strcmp(o.occupation,"responsable")==0)x1=2 ;  

gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_ouvrier,"combobox2")),x1);









}
}
}





void
on_button_modifier_ouvrier_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

char id[20];
char permis[4];
char occupation[30];
char tel[9];
char email[30];
char adressePostale[30];
strcpy(permis,"---");
GtkWidget *p;
p=lookup_widget(gestion_ouvrier,"treeview1");

int b=1;
GtkWidget *entryID;
GtkWidget *entryEmail;
GtkWidget *entryTel;
GtkWidget *entryAdresse;
GtkWidget *comboOccupation;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;

entryID=lookup_widget(gestion_ouvrier,"entry11");
entryEmail=lookup_widget(gestion_ouvrier,"entry12");
entryTel=lookup_widget(gestion_ouvrier,"entry13");
entryAdresse=lookup_widget(gestion_ouvrier,"entry14");
comboOccupation=lookup_widget(gestion_ouvrier,"combobox2");

check1=lookup_widget(gestion_ouvrier,"checkbutton4");
check2=lookup_widget(gestion_ouvrier,"checkbutton5");
check3=lookup_widget(gestion_ouvrier,"checkbutton6");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entryTel)));
strcpy(email,gtk_entry_get_text(GTK_ENTRY(entryEmail)));
strcpy(adressePostale,gtk_entry_get_text(GTK_ENTRY(entryAdresse)));

//hide success label
gtk_widget_hide(lookup_widget(gestion_ouvrier,"label62"));

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
permis[0]='A';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
permis[1]='B';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check3) )){
permis[2]='C';
}

strcpy(occupation,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboOccupation)));


modifier_ouvrier(id,permis,occupation,tel,email,adressePostale);

gtk_widget_show(lookup_widget(gestion_ouvrier,"label62"));

//mise a jour du treeView


afficher_ouvrier(p,"ouvrier.txt");





}


void
on_button_supprimer_ouvrier_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* id;
        label=lookup_widget(gestion_ouvrier,"label64");
        p=lookup_widget(gestion_ouvrier,"treeview1");


        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));

        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_ouvrier(id);// supprimer la ligne du fichier

           gtk_widget_hide (label);
	}else{
                gtk_widget_show (label);
        }


}


void
on_button_ajouter_tropaux_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{

tropaux t;
strcpy(t.zone ,"---");


GtkWidget *entryID;
GtkWidget *entryVeterinaire;
GtkWidget *entrySigne;



GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;



GtkWidget *comboType;
GtkWidget *comboPoids;
GtkWidget *calendar;
int jj,mm,aa,b=1;
GtkWidget *p;
p=lookup_widget(gestion_tropaux,"treeview2");





entryID=lookup_widget(gestion_tropaux,"entry30");
entryVeterinaire=lookup_widget(gestion_tropaux,"entry31");
entrySigne=lookup_widget(gestion_tropaux,"entry32");



check1=lookup_widget(gestion_tropaux,"checkbutton12");
check2=lookup_widget(gestion_tropaux,"checkbutton13");
check3=lookup_widget(gestion_tropaux,"checkbutton14");


radiobutt1=lookup_widget(gestion_tropaux,"radiobutton7");
radiobutt2=lookup_widget(gestion_tropaux,"radiobutton8");

comboType=lookup_widget(gestion_tropaux,"combobox7");
comboPoids=lookup_widget(gestion_tropaux,"combobox8");
calendar=lookup_widget(gestion_tropaux,"calendar4");



 strcpy(t.id,gtk_entry_get_text(GTK_ENTRY(entryID)));
 strcpy(t.veterinaire,gtk_entry_get_text(GTK_ENTRY(entryVeterinaire)));
 strcpy(t.signe,gtk_entry_get_text(GTK_ENTRY(entrySigne)));








if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
t.zone[0]='A';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
t.zone[1]='B';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check3) )){
t.zone[2]='C';
}

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(t.sexe,"femelle");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(t.sexe,"male");
}
//hide success label
gtk_widget_hide (lookup_widget(gestion_tropaux,"label133"));

/*Controle saisie*/




/*
char id[20];
char type[30];
char poids[30];
char veterinaire[30];
char signe[30];
char dateNaissance[30];
char zone[4];
char sexe[20];
*/


if(strcmp(t.id,"")==0){
		  gtk_widget_show (lookup_widget(gestion_tropaux,"label131"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_tropaux,"label131"));
}



if(strcmp(t.veterinaire,"")==0){
		  gtk_widget_show (lookup_widget(gestion_tropaux,"label140"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_tropaux,"label140"));
}


if(strcmp(t.signe,"")==0){
		  gtk_widget_show (lookup_widget(gestion_tropaux,"label142"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_tropaux,"label142"));
}



if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboType))==-1){
                gtk_widget_show (lookup_widget(gestion_tropaux,"label138"));
b=0;
}
else{

           gtk_widget_hide (lookup_widget(gestion_tropaux,"label138"));
}

if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboPoids))==-1){
                gtk_widget_show (lookup_widget(gestion_tropaux,"label147"));
b=0;
}
else{

           gtk_widget_hide (lookup_widget(gestion_tropaux,"label147"));
}






if(b==1){



strcpy(t.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboType)));
strcpy(t.poids,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboPoids)));
t.nbVaccin =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_tropaux,"spinbutton1")));


gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);//fct GTK pour recuperer la date


sprintf(t.dateNaissance,"%d/%d/%d",jj,mm+1,aa);

if(exist_tropaux(t.id)==1)
        {

				  gtk_widget_show (lookup_widget(gestion_tropaux,"label132"));
        }
        else {
						  gtk_widget_hide (lookup_widget(gestion_tropaux,"label132"));
                ajouter_Nouv_tropaux(t);

						  gtk_widget_show (lookup_widget(gestion_tropaux,"label133"));

		/*mise a jour treeView*/
		afficher_tropaux(p,"tropaux.txt");
        }




}












}


void
on_retour_tropaux_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (menu);
gtk_widget_destroy (gestion_tropaux);
}


void
on_button_modifier_tropaux_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

char id[20];
char zone[4];
char veterinaire[30];
char signe[30];
int nbVaccin;
strcpy(zone,"---");


int b=1;
GtkWidget *entryID;
GtkWidget *entryVeterinaire;
GtkWidget *entrySigne;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;
GtkWidget *p;
p=lookup_widget(gestion_tropaux,"treeview2");
entryID=lookup_widget(gestion_tropaux,"entry22");



check1=lookup_widget(gestion_tropaux,"checkbutton15");
check2=lookup_widget(gestion_tropaux,"checkbutton16");
check3=lookup_widget(gestion_tropaux,"checkbutton17");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));
strcpy(veterinaire,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_tropaux,"entry23") )));
strcpy(signe,gtk_entry_get_text(GTK_ENTRY(GTK_ENTRY(lookup_widget(gestion_tropaux,"entry24")))));
nbVaccin =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_tropaux,"spinbutton2")));



//hide success label
gtk_widget_hide(lookup_widget(gestion_tropaux,"label96"));

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
zone[0]='A';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
zone[1]='B';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check3) )){
zone[2]='C';
}




modifier_tropaux(id,zone,veterinaire,signe,nbVaccin);

//show success label
gtk_widget_show(lookup_widget(gestion_tropaux,"label96"));
/*mise a jour treeView*/
afficher_tropaux(p,"tropaux.txt");


}


void
on_button_consulter_tropaux_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
char id[20];
int b=1,x1;
GtkWidget *entryID;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;
tropaux t ;
entryID=lookup_widget(gestion_tropaux,"entry22");
check1=lookup_widget(gestion_tropaux,"checkbutton15");
check2=lookup_widget(gestion_tropaux,"checkbutton16");
check3=lookup_widget(gestion_tropaux,"checkbutton17");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));
if(strcmp(id,"")==0){
		  gtk_widget_show (lookup_widget(gestion_tropaux,"label99"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_tropaux,"label99"));
}


if(b==1){

t=trouver_tropaux(id);
if(strcmp(t.id,"notFound")==0){

gtk_widget_show (lookup_widget(gestion_tropaux,"label95"));

}
else
{
gtk_widget_hide (lookup_widget(gestion_tropaux,"label95"));
gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_tropaux,"entry23")),t.veterinaire);
gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_tropaux,"entry24")),t.signe);
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_tropaux,"spinbutton2")),t.nbVaccin);  


if(t.zone[0]=='A'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check1),TRUE );
printf("%s","check1");
}

if(t.zone[1]=='B'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check2),TRUE );
printf("%s","check2");
}

if(t.zone[2]=='C'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check3),TRUE );
printf("%s","check3");
}

             



}
}

}


void
on_button_supprimer_tropaux_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* id;
        label=lookup_widget(gestion_tropaux,"label101");
        p=lookup_widget(gestion_tropaux,"treeview2");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_tropaux(id);// supprimer la ligne du fichier

           gtk_widget_hide (label);
	}else{
                gtk_widget_show (label);
        }

}


void
on_button_gest_tropaux_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
gestion_tropaux = create_gestion_tropaux ();


/*Preparation Treeview*/

GtkWidget *p;


p=lookup_widget(gestion_tropaux,"treeview2");

i=0;


afficher_tropaux(p,"tropaux.txt");

gtk_widget_show (gestion_tropaux);

gtk_widget_hide (menu);
}


void
on_button_ajouter_equipement_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

equipement e;
strcpy(e.materielUtiliser ,"---");


GtkWidget *entryID;
GtkWidget *entryImmatricule;
GtkWidget *entryRemarque;



GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;



GtkWidget *comboMatrielDispo;

GtkWidget *calendar;
int jj,mm,aa,b=1;
GtkWidget *p;
p=lookup_widget(gestion_equipement,"treeview3");





entryID=lookup_widget(gestion_equipement,"entry38");
entryImmatricule=lookup_widget(gestion_equipement,"entry39");
entryRemarque=lookup_widget(gestion_equipement,"entry40");



check1=lookup_widget(gestion_equipement,"checkbutton23");
check2=lookup_widget(gestion_equipement,"checkbutton24");
check3=lookup_widget(gestion_equipement,"checkbutton25");


radiobutt1=lookup_widget(gestion_equipement,"radiobutton10");
radiobutt2=lookup_widget(gestion_equipement,"radiobutton11");

comboMatrielDispo=lookup_widget(gestion_equipement,"combobox10");

calendar=lookup_widget(gestion_equipement,"calendar5");



 strcpy(e.id,gtk_entry_get_text(GTK_ENTRY(entryID)));
 strcpy(e.remarque,gtk_entry_get_text(GTK_ENTRY(entryRemarque)));
 strcpy(e.immatricule,gtk_entry_get_text(GTK_ENTRY(entryImmatricule)));








if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
e.materielUtiliser[0]='A';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
e.materielUtiliser[1]='B';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check3) )){
e.materielUtiliser[2]='C';
}


if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(e.type,"moteur");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(e.type,"agricole");
}
//hide success label
gtk_widget_hide (lookup_widget(gestion_equipement,"label195"));

/*Controle saisie*/


/*
char id[20];
char type[30];
char remarque[30];
char immatricule[30];
char dateUtilisation[30];
char materielDispo[30];
char materielUtiliser[4];
*/




if(strcmp(e.id,"")==0){
		  gtk_widget_show (lookup_widget(gestion_equipement,"label188"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_equipement,"label188"));
}



if(strcmp(e.remarque,"")==0){
		  gtk_widget_show (lookup_widget(gestion_equipement,"label192"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_equipement,"label192"));
}


if(strcmp(e.immatricule,"")==0 && strcmp(e.type,"moteur")==0){
		  gtk_widget_show (lookup_widget(gestion_equipement,"label196"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_equipement,"label196"));
		  
}



if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboMatrielDispo))==-1){
                gtk_widget_show (lookup_widget(gestion_equipement,"label189"));
b=0;
}
else{

           gtk_widget_hide (lookup_widget(gestion_equipement,"label189"));
}





if(b==1){



strcpy(e.materielDispo,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboMatrielDispo)));

if(strcmp(e.type,"agricole")==0){
strcpy(e.immatricule,"***");
}
gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);//fct GTK pour recuperer la date


sprintf(e.dateUtilisation,"%d/%d/%d",jj,mm+1,aa);

if(exist_equipement(e.id)==1)
        {

				  gtk_widget_show (lookup_widget(gestion_equipement,"label194"));
        }
        else {
						  gtk_widget_hide (lookup_widget(gestion_equipement,"label194"));
                ajouter_Nouv_equipement(e);

						  gtk_widget_show (lookup_widget(gestion_equipement,"label195"));

/*mise a jour treeView*/
afficher_equipement(p,"equipement.txt");
        }




}








}


void
on_button_consulter_equipement_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
char id[20];
int b=1,x1,jj,mm,aa;
GtkWidget *entryID;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;
equipement e ;

entryID=lookup_widget(gestion_equipement,"entry41");
check1=lookup_widget(gestion_equipement,"checkbutton28");
check2=lookup_widget(gestion_equipement,"checkbutton29");
check3=lookup_widget(gestion_equipement,"checkbutton30");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));
if(strcmp(id,"")==0){
		  gtk_widget_show (lookup_widget(gestion_equipement,"label207"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_equipement,"label207"));
}


if(b==1){

e=trouver_equipement(id);
if(strcmp(e.id,"notFound")==0){
//show label inexistant
gtk_widget_show (lookup_widget(gestion_equipement,"label208"));

}
else
{
gtk_widget_hide (lookup_widget(gestion_equipement,"label208"));
gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_equipement,"entry43")),e.remarque);
//convertir la chaine en entiers
sscanf(e.dateUtilisation,"%d/%d/%d",&jj,&mm,&aa);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_equipement,"spinbutton5")),jj);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_equipement,"spinbutton6")),mm);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_equipement,"spinbutton7")),aa);  


if(e.materielUtiliser[0]=='A'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check1),TRUE );

}

if(e.materielUtiliser[1]=='B'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check2),TRUE );

}

if(e.materielUtiliser[2]=='C'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check3),TRUE );

}



if(strcmp(e.materielDispo,"tracteurs")==0)x1=0;		
if(strcmp(e.materielDispo,"camion")==0)x1=1;                
if(strcmp(e.materielDispo,"voiture")==0)x1=2 ;  

gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_equipement,"combobox11")),x1);

         

}
}

}


void
on_button_modifier_equipement_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
char id[20];
char remarque[30];
char dateUtilisation[30];
char materielDispo[30];
char materielUtiliser[4];
int b=1,x1,jj,mm,aa;
strcpy(materielUtiliser,"---");
GtkWidget *entryID;
GtkWidget *entryRemarque;

GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;
GtkWidget *p;
p=lookup_widget(gestion_equipement,"treeview3");
entryID=lookup_widget(gestion_equipement,"entry41");



check1=lookup_widget(gestion_equipement,"checkbutton28");
check2=lookup_widget(gestion_equipement,"checkbutton29");
check3=lookup_widget(gestion_equipement,"checkbutton30");
strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));
strcpy(remarque,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_equipement,"entry43") )));

jj =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_equipement,"spinbutton5")));
mm =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_equipement,"spinbutton6")));
aa =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_equipement,"spinbutton7")));

sprintf(dateUtilisation,"%d/%d/%d",jj,mm,aa);
strcpy(materielDispo,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_equipement,"combobox11"))));

//hide success label
gtk_widget_hide(lookup_widget(gestion_equipement,"label206"));

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
materielUtiliser[0]='A';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
materielUtiliser[1]='B';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check3) )){
materielUtiliser[2]='C';
}


modifier_equipement(id,remarque,dateUtilisation,materielDispo,materielUtiliser);

//show success label
gtk_widget_show(lookup_widget(gestion_equipement,"label206"));
/*mise a jour treeView*/
afficher_equipement(p,"equipement.txt");









}


void
on_button_supprimer_equipement_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* id;
        label=lookup_widget(gestion_equipement,"label212");
        p=lookup_widget(gestion_equipement,"treeview3");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_equipement(id);// supprimer la ligne du fichier

           gtk_widget_hide (label);
	}else{
                gtk_widget_show (label);
        }

}


void
on_retour_equipement_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (menu);
gtk_widget_destroy (gestion_equipement);
}


void
on_button_gest_equipement_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
gestion_equipement = create_gestion_equipement ();


/*Preparation Treeview*/

GtkWidget *p;


p=lookup_widget(gestion_equipement,"treeview3");

i=0;


afficher_equipement(p,"equipement.txt");

gtk_widget_show (gestion_equipement);

gtk_widget_hide (menu);

}


void
on_retour_client_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (menu);
gtk_widget_destroy (gestion_client);
}


void
on_button_ajouter_client_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{

client c;




GtkWidget *entryCin;
GtkWidget *entryNom;
GtkWidget *entryPrenom;
GtkWidget *entryTel;
GtkWidget *entryEmail;
GtkWidget *entryAdresse;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
GtkWidget *calendar;
GtkWidget * togg1;
GtkWidget * togg2;
int jj,mm,aa,b=1;
GtkWidget *p;
p=lookup_widget(gestion_client,"treeview4");






togg1=lookup_widget(gestion_client,"togglebutton1");
togg2=lookup_widget(gestion_client,"togglebutton2");


entryCin=lookup_widget(gestion_client,"entry44");
entryNom=lookup_widget(gestion_client,"entry49");
entryPrenom=lookup_widget(gestion_client,"entry50");
entryEmail=lookup_widget(gestion_client,"entry51");
entryTel=lookup_widget(gestion_client,"entry45");
entryAdresse=lookup_widget(gestion_client,"entry46");





radiobutt1=lookup_widget(gestion_client,"radiobutton13");
radiobutt2=lookup_widget(gestion_client,"radiobutton14");


calendar=lookup_widget(gestion_client,"calendar6");





 strcpy(c.cin,gtk_entry_get_text(GTK_ENTRY(entryCin)));
 strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entryNom)));
 strcpy(c.prenom,gtk_entry_get_text(GTK_ENTRY(entryPrenom)));
 strcpy(c.tel,gtk_entry_get_text(GTK_ENTRY(entryTel)));
 strcpy(c.email,gtk_entry_get_text(GTK_ENTRY(entryEmail)));
 strcpy(c.addresse,gtk_entry_get_text(GTK_ENTRY(entryAdresse)));




if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(c.sexe,"femme");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(c.sexe,"homme");
}
//par defaut
strcpy(c.promo,"non");

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(togg1) )){
strcpy(c.promo,"oui");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(togg2) )){
strcpy(c.promo,"non");
}



gtk_widget_hide (lookup_widget(gestion_client,"label238"));

/*Controle saisie*/




if(strcmp(c.cin,"")==0){
		  gtk_widget_show (lookup_widget(gestion_client,"label233"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_client,"label233"));
}


if(strcmp(c.nom,"")==0){
		  gtk_widget_show (lookup_widget(gestion_client,"label234"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_client,"label234"));
}


if(strcmp(c.prenom,"")==0){
		  gtk_widget_show (lookup_widget(gestion_client,"label260"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_client,"label260"));
}

if(strcmp(c.tel,"")==0){
		  gtk_widget_show (lookup_widget(gestion_client,"label236"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_client,"label236"));
}

if(strcmp(c.addresse,"")==0){
		  gtk_widget_show (lookup_widget(gestion_client,"label239"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_client,"label239"));
}
if(strcmp(c.email,"")==0){
		  gtk_widget_show (lookup_widget(gestion_client,"label262"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_client,"label262"));
}










if(b==1){








gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);//fct GTK pour recuperer la date


sprintf(c.dateNaissance,"%d/%d/%d",jj,mm+1,aa);

if(exist_client(c.cin)==1)
        {

				  gtk_widget_show (lookup_widget(gestion_client,"label237"));
        }
        else {
						  gtk_widget_hide (lookup_widget(gestion_client,"label237"));
                ajouter_Nouv_client(c);

						  gtk_widget_show (lookup_widget(gestion_client,"label238"));
/*mise a jour treeView*/
afficher_client(p,"client.txt");
        }




}


}


void
on_button_consulter_client_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
char cin[9]="";
int b=1,x1;
GtkWidget *entryCin;
GtkWidget *entryTel;
GtkWidget *entryEmail;
GtkWidget *entryAdresse;
GtkWidget * togg1;
GtkWidget * togg2;
client c ;
entryCin=lookup_widget(gestion_client,"entry47");
entryEmail=lookup_widget(gestion_client,"entry54");
entryTel=lookup_widget(gestion_client,"entry52");
entryAdresse=lookup_widget(gestion_client,"entry53");
togg1=lookup_widget(gestion_client,"togglebutton3");
togg2=lookup_widget(gestion_client,"togglebutton4");
strcpy(cin,gtk_entry_get_text(GTK_ENTRY(entryCin)));



if(strcmp(cin,"")==0){
		  gtk_widget_show (lookup_widget(gestion_client,"label250"));
b=0;

}
else {
		  gtk_widget_hide(lookup_widget(gestion_client,"label250"));
}


if(b==1){

c=trouver_client(cin);
if(strcmp(c.cin,"notFound")==0){
//label cin inexistante
gtk_widget_show (lookup_widget(gestion_client,"label251"));

}
else
{
gtk_widget_hide (lookup_widget(gestion_client,"label251"));
gtk_entry_set_text(GTK_ENTRY(entryEmail),c.email);
gtk_entry_set_text(GTK_ENTRY(entryTel),c.tel);
gtk_entry_set_text(GTK_ENTRY(entryAdresse),c.addresse);


if (strcmp(c.promo,"oui")==0) {
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(togg1),TRUE );
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(togg2) ,FALSE);
}

if (strcmp(c.promo,"non")==0) {
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(togg2) ,TRUE);
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(togg1),FALSE );
}






}

}


}


void
on_button_modifier_client_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
char cin[9];
char tel[30];
char addresse[30];
char email[30];
char promo[30];



int b=1;
GtkWidget *entryCin;
GtkWidget *entryTel;
GtkWidget *entryEmail;
GtkWidget *entryAdresse;
GtkWidget * togg1;
GtkWidget * togg2;
GtkWidget *p;
p=lookup_widget(gestion_client,"treeview4");


entryCin=lookup_widget(gestion_client,"entry47");
entryTel=lookup_widget(gestion_client,"entry52");
entryAdresse=lookup_widget(gestion_client,"entry53");
entryEmail=lookup_widget(gestion_client,"entry54");
togg1=lookup_widget(gestion_client,"togglebutton3");
togg2=lookup_widget(gestion_client,"togglebutton4");


strcpy(cin,gtk_entry_get_text(GTK_ENTRY(entryCin)));
strcpy(tel,gtk_entry_get_text(GTK_ENTRY(entryTel)));
strcpy(addresse,gtk_entry_get_text(GTK_ENTRY(entryAdresse)));
strcpy(email,gtk_entry_get_text(GTK_ENTRY(entryEmail)));

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(togg1) )){
strcpy(promo,"oui");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(togg2) )){
strcpy(promo,"non");
}






//hide success label
gtk_widget_hide(lookup_widget(gestion_client,"label252"));






modifier_client(cin,tel,addresse,email,promo);

//show success label
gtk_widget_show(lookup_widget(gestion_client,"label252"));

/*mise a jour treeView*/
afficher_client(p,"client.txt");

}


void
on_button_gest_client_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
gestion_client = create_gestion_client ();


/*Preparation Treeview*/

GtkWidget *p;


p=lookup_widget(gestion_client,"treeview4");

i=0;


afficher_client(p,"client.txt");

gtk_widget_show (gestion_client);

gtk_widget_hide (menu);
}


void
on_button_supprimer_client_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* cin;
        label=lookup_widget(gestion_client,"label255");
        p=lookup_widget(gestion_client,"treeview4");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&cin,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_client(cin);// supprimer la ligne du fichier

           gtk_widget_hide (label);
	}else{
                gtk_widget_show (label);
        }

}


void
on_button_ajouter_capteur_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
/*
char id[30];
char type[30];
char zone[30];
char precision[4];
char dateEntretien[30];
*/
capteur cap;
strcpy(cap.precision ,"---");
cap.defectueux=0;

GtkWidget *entryID;
GtkWidget *entryCin;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;
GtkWidget *comboZone;
GtkWidget *comboMarque;
GtkWidget *calendar;

int jj,mm,aa,b=1;
GtkWidget *p;
p=lookup_widget(gestion_capteur,"treeview5");






entryID=lookup_widget(gestion_capteur,"entry55");




check1=lookup_widget(gestion_capteur,"checkbutton36");
check2=lookup_widget(gestion_capteur,"checkbutton37");
check3=lookup_widget(gestion_capteur,"checkbutton38");


radiobutt1=lookup_widget(gestion_capteur,"radiobutton15");
radiobutt2=lookup_widget(gestion_capteur,"radiobutton16");

comboZone=lookup_widget(gestion_capteur,"combobox13");
comboMarque=lookup_widget(gestion_capteur,"combobox16");
calendar=lookup_widget(gestion_capteur,"calendar7");




 strcpy(cap.id,gtk_entry_get_text(GTK_ENTRY(entryID)));
 





if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
cap.precision[0]='A';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
cap.precision[1]='B';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check3) )){
cap.precision[2]='C';
}

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(cap.type,"temperature");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(cap.type,"humidite");
}
//hide label success

gtk_widget_hide (lookup_widget(gestion_capteur,"label279"));

/*Controle saisie*/
if(strcmp(cap.id,"")==0){
		  gtk_widget_show (lookup_widget(gestion_capteur,"label274"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_capteur,"label274"));
}






if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboZone))==-1){
                gtk_widget_show (lookup_widget(gestion_capteur,"label275"));
b=0;
}
else{

           gtk_widget_hide (lookup_widget(gestion_capteur,"label275"));
}



if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboMarque))==-1){
                gtk_widget_show (lookup_widget(gestion_capteur,"label401"));
b=0;
}
else{

           gtk_widget_hide (lookup_widget(gestion_capteur,"label401"));
}







if(b==1){



strcpy(cap.zone,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboZone)));
strcpy(cap.marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboMarque)));



gtk_calendar_get_date (GTK_CALENDAR(calendar),
                       &aa,
                       &mm,
                       &jj);//fct GTK pour recuperer la date


sprintf(cap.dateEntretien,"%d/%d/%d",jj,mm+1,aa);

if(exist_capteur(cap.id)==1)
        {

				  gtk_widget_show (lookup_widget(gestion_capteur,"label278"));
        }
        else {

						  gtk_widget_hide (lookup_widget(gestion_capteur,"label278"));
                ajouter_Nouv_capteur(cap);

						  gtk_widget_show (lookup_widget(gestion_capteur,"label279"));
/*mise a jour treeView*/
afficher_capteur(p,"capteur.txt");
        }




}

}


void
on_button_consulter_capteur_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
char id[20];
int b=1,x1,jj,mm,aa;
GtkWidget *entryID;

GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
capteur cap ;

entryID=lookup_widget(gestion_capteur,"entry58");


check1=lookup_widget(gestion_capteur,"checkbutton41");
check2=lookup_widget(gestion_capteur,"checkbutton42");
check3=lookup_widget(gestion_capteur,"checkbutton43");

radiobutt1=lookup_widget(gestion_capteur,"radiobutton23");
radiobutt2=lookup_widget(gestion_capteur,"radiobutton24");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));
if(strcmp(id,"")==0){
		  gtk_widget_show (lookup_widget(gestion_capteur,"label291"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_capteur,"label291"));
}


if(b==1){

cap=trouver_capteur(id);
if(strcmp(cap.id,"notFound")==0){
//show label inexistant
gtk_widget_show (lookup_widget(gestion_capteur,"label292"));

}
else
{
gtk_widget_hide (lookup_widget(gestion_capteur,"label292"));


//convertir la chaine en entiers
sscanf(cap.dateEntretien,"%d/%d/%d",&jj,&mm,&aa);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_capteur,"spinbutton8")),jj);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_capteur,"spinbutton9")),mm);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_capteur,"spinbutton10")),aa);  


if(cap.precision[0]=='A'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check1),TRUE );

}

if(cap.precision[1]=='B'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check2),TRUE );

}

if(cap.precision[2]=='C'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check3),TRUE );

}

if(cap.defectueux==1){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(radiobutt1),TRUE );

}

if(cap.defectueux==0){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(radiobutt2),TRUE );

}



if(strcmp(cap.zone,"A")==0)x1=0;		
if(strcmp(cap.zone,"B")==0)x1=1;                
if(strcmp(cap.zone,"C")==0)x1=2;  
if(strcmp(cap.zone,"D")==0)x1=3; 

gtk_combo_box_set_active(GTK_COMBO_BOX(lookup_widget(gestion_capteur,"combobox14")),x1);

         

}
}
}


void
on_button_modifier_capteur_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
char id[20];
char zone[30];
char dateEntretien[30];
char precision[4];
int defectueux;
int b=1,x1,jj,mm,aa;
strcpy(precision,"---");
GtkWidget *entryID;
GtkWidget *entryRemarque;

GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
GtkWidget *p;
p=lookup_widget(gestion_capteur,"treeview5");
entryID=lookup_widget(gestion_capteur,"entry58");



check1=lookup_widget(gestion_capteur,"checkbutton41");
check2=lookup_widget(gestion_capteur,"checkbutton42");
check3=lookup_widget(gestion_capteur,"checkbutton43");

radiobutt1=lookup_widget(gestion_capteur,"radiobutton23");
radiobutt2=lookup_widget(gestion_capteur,"radiobutton24");



strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));

jj =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_capteur,"spinbutton8")));
mm =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_capteur,"spinbutton9")));
aa =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_capteur,"spinbutton10")));
sprintf(dateEntretien,"%d/%d/%d",jj,mm,aa);
strcpy(zone,gtk_combo_box_get_active_text(GTK_COMBO_BOX(lookup_widget(gestion_capteur,"combobox14"))));

//hide success label
gtk_widget_hide(lookup_widget(gestion_capteur,"label293"));

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
precision[0]='A';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
precision[1]='B';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check3) )){
precision[2]='C';
}


if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
defectueux= 1;
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
defectueux= 0;
}



modifier_capteur(id,zone,precision,dateEntretien,defectueux);

//show success label
gtk_widget_show(lookup_widget(gestion_capteur,"label293"));
/*mise a jour treeView*/
afficher_capteur(p,"capteur.txt");






}


void
on_button_supprimer_capteur_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* id;
        label=lookup_widget(gestion_capteur,"label296");
        p=lookup_widget(gestion_capteur,"treeview5");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_capteur(id);// supprimer la ligne du fichier

           gtk_widget_hide (label);
	}else{
                gtk_widget_show (label);
        }

}


void
on_retour_capteur_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (menu);
gtk_widget_destroy (gestion_capteur);
}


void
on_button_gest_capteur_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
gestion_capteur = create_gestion_capteur ();


/*Preparation Treeview*/

GtkWidget *p;


p=lookup_widget(gestion_capteur,"treeview5");

i=0;


afficher_capteur(p,"capteur.txt");

gtk_widget_show (gestion_capteur);

gtk_widget_hide (menu);
}


void
on_retour_agriculture_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (menu);
gtk_widget_destroy (gestion_agriculture);
}


void
on_button_ajouter_agriculture_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{
agriculture a;
strcpy(a.nouv ,"--");


GtkWidget *entryID;
GtkWidget *entryNom;




GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
GtkWidget *check1;
GtkWidget *check2;




GtkWidget *comboType;

GtkWidget *calendar1;
GtkWidget *calendar2;
GtkWidget *calendar3;
GtkWidget *calendar4;
int jj,mm,aa,b=1;
GtkWidget *p;
p=lookup_widget(gestion_agriculture,"treeview6");





entryID=lookup_widget(gestion_agriculture,"entry59");
entryNom=lookup_widget(gestion_agriculture,"entry64");




check1=lookup_widget(gestion_agriculture,"checkbutton50");
check2=lookup_widget(gestion_agriculture,"checkbutton51");



radiobutt1=lookup_widget(gestion_agriculture,"radiobutton17");
radiobutt2=lookup_widget(gestion_agriculture,"radiobutton18");

comboType=lookup_widget(gestion_agriculture,"combobox15");

calendar1=lookup_widget(gestion_agriculture,"calendar9");
calendar2=lookup_widget(gestion_agriculture,"calendar8");
calendar3=lookup_widget(gestion_agriculture,"calendar10");
calendar4=lookup_widget(gestion_agriculture,"calendar11");



 strcpy(a.id,gtk_entry_get_text(GTK_ENTRY(entryID)));
 strcpy(a.nom,gtk_entry_get_text(GTK_ENTRY(entryNom)));









if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
a.nouv[0]='O';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
a.nouv[1]='N';
}


if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(a.genre,"legume");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(a.genre,"fruit");
}
//hide success label
gtk_widget_hide (lookup_widget(gestion_agriculture,"label317"));

/*Controle saisie*/







if(strcmp(a.id,"")==0){
		  gtk_widget_show (lookup_widget(gestion_agriculture,"label312"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_agriculture,"label312"));
}



if(strcmp(a.nom,"")==0){
		  gtk_widget_show (lookup_widget(gestion_agriculture,"label313"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_agriculture,"label313"));
}






if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboType))==-1){
                gtk_widget_show (lookup_widget(gestion_agriculture,"label351"));
b=0;
}
else{

           gtk_widget_hide (lookup_widget(gestion_agriculture,"label351"));
}








if(b==1){



strcpy(a.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboType)));

a.qtt =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_agriculture,"spinbutton14")));


gtk_calendar_get_date (GTK_CALENDAR(calendar1),
                       &aa,
                       &mm,
                       &jj);//fct GTK pour recuperer la date


sprintf(a.datePlantation,"%d/%d/%d",jj,mm+1,aa);

gtk_calendar_get_date (GTK_CALENDAR(calendar2),
                       &aa,
                       &mm,
                       &jj);//fct GTK pour recuperer la date


sprintf(a.dateRecolte,"%d/%d/%d",jj,mm+1,aa);

gtk_calendar_get_date (GTK_CALENDAR(calendar3),
                       &aa,
                       &mm,
                       &jj);//fct GTK pour recuperer la date


sprintf(a.dateArrosage,"%d/%d/%d",jj,mm+1,aa);

gtk_calendar_get_date (GTK_CALENDAR(calendar4),
                       &aa,
                       &mm,
                       &jj);//fct GTK pour recuperer la date


sprintf(a.dateDefloration,"%d/%d/%d",jj,mm+1,aa);

if(exist_agriculture(a.id)==1)
        {

				  gtk_widget_show (lookup_widget(gestion_agriculture,"label316"));
        }
        else {
						  gtk_widget_hide (lookup_widget(gestion_agriculture,"label316"));
                ajouter_Nouv_agriculture(a);

						  gtk_widget_show (lookup_widget(gestion_agriculture,"label317"));

/*mise a jour treeView*/
afficher_agriculture(p,"agriculture.txt");
        }




}



}


void
on_button_consulter_agriculture_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
char id[20];
int b=1,x1,jj1,mm1,aa1,jj2,mm2,aa2;
GtkWidget *entryID;
GtkWidget *check1;
GtkWidget *check2;

agriculture a ;
entryID=lookup_widget(gestion_agriculture,"entry62");
check1=lookup_widget(gestion_agriculture,"checkbutton52");
check2=lookup_widget(gestion_agriculture,"checkbutton53");


strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));
if(strcmp(id,"")==0){
		  gtk_widget_show (lookup_widget(gestion_agriculture,"label329"));
b=0;
}
else {
		  gtk_widget_hide(lookup_widget(gestion_agriculture,"label329"));
}


if(b==1){

a=trouver_agriculture(id);
if(strcmp(a.id,"notFound")==0){

gtk_widget_show (lookup_widget(gestion_agriculture,"label330"));

}
else
{
gtk_widget_hide (lookup_widget(gestion_agriculture,"label330"));
gtk_entry_set_text(GTK_ENTRY(lookup_widget(gestion_agriculture,"entry65")),a.nom);

//convertir la chaine en entiers
sscanf(a.dateRecolte,"%d/%d/%d",&jj1,&mm1,&aa1);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_agriculture,"spinbutton11")),jj1);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_agriculture,"spinbutton12")),mm1);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_agriculture,"spinbutton13")),aa1);  

sscanf(a.dateArrosage,"%d/%d/%d",&jj2,&mm2,&aa2);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_agriculture,"spinbutton15")),jj2);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_agriculture,"spinbutton16")),mm2);  
gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_agriculture,"spinbutton17")),aa2);  


gtk_spin_button_set_value (GTK_SPIN_BUTTON(lookup_widget(gestion_agriculture,"spinbutton18")),a.qtt);  



if(a.nouv[0]=='O'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check1),TRUE );
printf("%s","check1");
}

if(a.nouv[1]=='N'){
gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON(check2),TRUE );
printf("%s","check2");
}



             



}
}

}


void
on_button_modifier_agriculture_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
char id[20];
char nom[30];
char dateRecolte[30];
char dateArrosage[30];
char nouv[3];
int qtt;
int b=1,x1,jj1,mm1,aa1,jj2,mm2,aa2;
strcpy(nouv,"--");
GtkWidget *entryID;
GtkWidget *entryNom;

GtkWidget *check1;
GtkWidget *check2;
GtkWidget *check3;
GtkWidget *p;
p=lookup_widget(gestion_agriculture,"treeview6");
entryID=lookup_widget(gestion_agriculture,"entry62");



check1=lookup_widget(gestion_agriculture,"checkbutton52");
check2=lookup_widget(gestion_agriculture,"checkbutton53");

strcpy(id,gtk_entry_get_text(GTK_ENTRY(entryID)));
strcpy(nom,gtk_entry_get_text(GTK_ENTRY(lookup_widget(gestion_agriculture,"entry65") )));
jj1 =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_agriculture,"spinbutton11")));
mm1 =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_agriculture,"spinbutton12")));
aa1 =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_agriculture,"spinbutton13")));
sprintf(dateRecolte,"%d/%d/%d",jj1,mm1,aa1);

jj2 =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_agriculture,"spinbutton15")));
mm2 =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_agriculture,"spinbutton16")));
aa2 =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_agriculture,"spinbutton17")));
sprintf(dateArrosage,"%d/%d/%d",jj2,mm2,aa2);

qtt =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(gestion_agriculture,"spinbutton18")));


//hide success label
gtk_widget_hide(lookup_widget(gestion_agriculture,"label331"));

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check1) )){
nouv[0]='O';
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(check2) )){
nouv[1]='N';
}



modifier_agriculture(id,nom,dateRecolte,dateArrosage,nouv,qtt);

//show success label
gtk_widget_show(lookup_widget(gestion_agriculture,"label331"));

/*mise a jour treeView*/
afficher_agriculture(p,"agriculture.txt");

}


void
on_button_supprimer_agriculture_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkTreeSelection *selection;
        GtkTreeModel     *model;
        GtkTreeIter iter;
        GtkWidget* p;
        GtkWidget *label;
        gchar* id;
        label=lookup_widget(gestion_agriculture,"label334");
        p=lookup_widget(gestion_agriculture,"treeview6");
        selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(p));
        if (gtk_tree_selection_get_selected(selection, &model, &iter))
        {  gtk_tree_model_get (model,&iter,0,&id,-1);
           gtk_list_store_remove(GTK_LIST_STORE(model),&iter);//supprimer la ligne du treeView

           supprimer_agriculture(id);// supprimer la ligne du fichier

           gtk_widget_hide (label);
	}else{
                gtk_widget_show (label);
        }

}


void
on_button_gest_agriculture_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
gestion_agriculture = create_gestion_agriculture ();


/*Preparation Treeview*/

GtkWidget *p;


p=lookup_widget(gestion_agriculture,"treeview6");

i=0;


afficher_agriculture(p,"agriculture.txt");

gtk_widget_show (gestion_agriculture);

gtk_widget_hide (menu);
}


void
on_button_enregistrer_presence_clicked (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *entryID;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
absenteisme ab;




entryID=lookup_widget(fiche_presence,"entry66");
radiobutt1=lookup_widget(fiche_presence,"radiobutton19");
radiobutt2=lookup_widget(fiche_presence,"radiobutton20");
strcpy(ab.id,gtk_entry_get_text(GTK_ENTRY(entryID) ) );


gtk_widget_hide(lookup_widget(fiche_presence,"label362"));
if(exist_ouvrier(ab.id)==1){
gtk_widget_hide(lookup_widget(fiche_presence,"label356"));
ab.jj =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(fiche_presence,"spinbutton19")));
ab.mm =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(fiche_presence,"spinbutton20")));
ab.aa =gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(fiche_presence,"spinbutton21")));

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
ab.present=1;
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
ab.present=0;
}

enregistrer_presence_ouvrier(ab);
gtk_widget_show(lookup_widget(fiche_presence,"label362"));
}
else{
gtk_widget_show(lookup_widget(fiche_presence,"label356"));
}

}


void
on_retour_presence_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (menu);
gtk_widget_destroy (fiche_presence);
}


void
on_button_fich_presence_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
fiche_presence = create_fiche_presence ();

gtk_widget_show (fiche_presence);

gtk_widget_hide (menu);
}


void
on_button_gest_admin_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
gestion_admin = create_gestion_admin ();
gtk_widget_show (gestion_admin);
gtk_widget_hide (menu);
}


void
on_retour_admin_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (menu);
gtk_widget_hide (gestion_admin);
}


void
on_button_annee_plus_seche_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
annee_seche = create_annee_seche ();
gtk_widget_show (annee_seche);
gtk_widget_hide (gestion_admin);
}


void
on_button_meilleur_ouvrier_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
meilleur_ouvrier = create_meilleur_ouvrier ();
gtk_widget_show (meilleur_ouvrier);
gtk_widget_hide (gestion_admin);
i=0;
}


void
on_button_pire_ouvrier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
pire_ouvrier = create_pire_ouvrier ();
gtk_widget_show (pire_ouvrier);
gtk_widget_hide (gestion_admin);
i=0;
}


void
on_button_numero_equipement_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
capteur_alarmante = create_capteur_alarmante ();
gtk_widget_show (capteur_alarmante);
gtk_widget_hide (gestion_admin);





}


void
on_button_nombre_troupau_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *p;
type_tropaux = create_type_tropaux ();

p=lookup_widget(type_tropaux,"treeview9");
i=0;

rechercher_tropaux_par_type(p,"tropaux.txt","");




gtk_widget_show (type_tropaux);
gtk_widget_hide (gestion_admin);
}


void
on_button_chercher_annee_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
char fich[40];
char labelAnnee[10];
int aa;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
radiobutt1=lookup_widget(annee_seche,"radiobutton21");
radiobutt2=lookup_widget(annee_seche,"radiobutton22");
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(fich,"humidite.txt");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(fich,"temperature.txt");
}
aa = trouver_annee_plus_seche(fich);
sprintf(labelAnnee,"%d",aa);
gtk_label_set_text(GTK_LABEL( lookup_widget(annee_seche,"label396") ),labelAnnee);

}


void
on_retour_annee_seche_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{

gtk_widget_show (gestion_admin);
gtk_widget_hide (annee_seche);
}


void
on_agricole_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
gtk_widget_hide(lookup_widget(gestion_equipement,"entry39"));
gtk_widget_hide(lookup_widget(gestion_equipement,"label186"));
}


void
on_moteur_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
gtk_widget_show(lookup_widget(gestion_equipement,"entry39"));
gtk_widget_show(lookup_widget(gestion_equipement,"label186"));
}


void
on_retour_meuilleur_ouvrier_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (gestion_admin);
gtk_widget_hide (meilleur_ouvrier);
}



void afficher_taux_meilleur(char*id, int aa){
int nbPresence=0;
int totale=0;
char chNbP[10];
char chTaux[10];
FILE*f=NULL;
absenteisme a;
f=fopen("absenteisme.txt","r");
while(fscanf(f,"%s %d %d %d %d\n",a.id,&a.jj,&a.mm,&a.aa,&a.present)!=EOF){
if(strcmp(a.id, id)==0 && aa==a.aa){
    totale++;
    if(a.present==1)nbPresence++;
}
}
sprintf(chNbP,"%d",nbPresence);
sprintf(chTaux,"%.3f",(float)nbPresence/totale);

gtk_label_set_text(GTK_LABEL( lookup_widget(meilleur_ouvrier,"label441") ),chNbP);
gtk_label_set_text(GTK_LABEL( lookup_widget(meilleur_ouvrier,"label442") ),chTaux);

}


void
on_button_chercher_meuilleur_ouvrier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
int aa,flag=1 ;
ouvrier o;
GtkWidget *p;
p=lookup_widget(meilleur_ouvrier,"treeview7");
aa=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(meilleur_ouvrier,"spinbutton22")));
o = trouver_meilleur(aa,flag);
afficher_taux_meilleur(o.id,aa);
afficher_single_ouvrier(o,p);

}


void afficher_taux_pire(char*id, int aa){
int nbPresence=0;
int totale=0;
char chNbP[10];
char chTaux[10];
FILE*f=NULL;
absenteisme a;
f=fopen("absenteisme.txt","r");
while(fscanf(f,"%s %d %d %d %d\n",a.id,&a.jj,&a.mm,&a.aa,&a.present)!=EOF){
if(strcmp(a.id, id)==0 && aa==a.aa){
    totale++;
    if(a.present==1)nbPresence++;
}
}
sprintf(chNbP,"%d",nbPresence);
sprintf(chTaux,"%.3f",(float)nbPresence/totale);

gtk_label_set_text(GTK_LABEL( lookup_widget(pire_ouvrier,"label445") ),chNbP);
gtk_label_set_text(GTK_LABEL( lookup_widget(pire_ouvrier,"label446") ),chTaux);

}


void
on_button_chercher_pire_ouvrier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
int aa,flag=0 ;
ouvrier o;
GtkWidget *p;
p=lookup_widget(pire_ouvrier,"treeview8");
aa=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(pire_ouvrier,"spinbutton23")));
o = trouver_meilleur(aa,flag);
afficher_taux_pire(o.id,aa);
afficher_single_ouvrier(o,p);
}


void
on_retour_pire_ouvrier_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (gestion_admin);
gtk_widget_hide (pire_ouvrier);
}


void
on_button_chercher_capteur_alarmante_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
int aa,m,i;
float seuil_minA=-3,seuil_minB=-1,seuil_maxA=50,seuil_maxB=69;

char fich[30];
char chId[30];
int capt[50];
char nombre[30];
char ch[200]="";
capteur c;
GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
GtkWidget*text; 
GtkTextBuffer *buffer;
radiobutt1=lookup_widget(capteur_alarmante,"radiobutton25");
radiobutt2=lookup_widget(capteur_alarmante,"radiobutton26");
text=lookup_widget(capteur_alarmante,"textview1");

aa=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(capteur_alarmante,"spinbutton26")));



if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(fich,"humidite.txt");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(fich,"temperature.txt");
}

m =remplire_id_capt(fich,aa,seuil_minA,seuil_minB,seuil_maxA,seuil_maxB,capt);


for(i=0;i<m;i++){
sprintf(chId,"%d",capt[i]);
c= trouver_capteur(chId);
strcat(ch,c.id);
strcat(ch,"\n");
}

buffer=gtk_text_view_get_buffer (GTK_TEXT_VIEW(text));
gtk_text_buffer_set_text (buffer,
                          ch,
                          -1);


gtk_text_view_set_editable(GTK_TEXT_VIEW(text), FALSE);
gtk_text_view_set_cursor_visible (GTK_TEXT_VIEW(text), FALSE);


sprintf(nombre,"%d",m);

gtk_label_set_text(GTK_LABEL( lookup_widget(capteur_alarmante,"label435") ),nombre);





}


void
on_retour_capteur_alarmante_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (gestion_admin);
gtk_widget_hide (capteur_alarmante);
}


void chercher_max_def(tabCapteurs_def*e,int n){
int i,max_val = e[0].frequence;
char max_marque[30];
strcpy(max_marque,e[0].marque);
for (i=1;i<n;i++){
if(e[i].frequence >max_val){
    max_val = e[i].frequence ;
    strcpy(max_marque,e[i].marque);
}

}

printf("la marque ayant des capteurs les plus defectueuses :%s\n ",max_marque);
gtk_label_set_text(GTK_LABEL( lookup_widget(marque_defectueuse,"label437") ),max_marque);

}




void
on_button_marque_defectueuse_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{

marque_defectueuse = create_marque_defectueuse ();
gtk_widget_hide (gestion_admin);
gtk_widget_show (marque_defectueuse);

}


void
on_retour_marque_defectueuse_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (gestion_admin);
gtk_widget_hide (marque_defectueuse);
}


void
on_button_chercher_tropaux_type_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

int b=1;
char type[30];
char labelType[30];
int nb;
GtkWidget *p;
GtkWidget *comboType;
comboType=lookup_widget(type_tropaux,"combobox17");



if(gtk_combo_box_get_active (GTK_COMBO_BOX(comboType))==-1){
                gtk_widget_show (lookup_widget(type_tropaux,"label426"));
b=0;
}
else{

           gtk_widget_hide (lookup_widget(type_tropaux,"label426"));
}


if(b==1){
strcpy(type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboType)));





p=lookup_widget(type_tropaux,"treeview9");







nb=rechercher_tropaux_par_type(p,"tropaux.txt",type);

sprintf(labelType,"%d",nb);
gtk_label_set_text(GTK_LABEL( lookup_widget(type_tropaux,"label431") ),labelType);



}








}


void
on_retour_type_tropaux_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_widget_show (gestion_admin);
gtk_widget_hide (type_tropaux);
}


void
on_button_chercher_marque_plus_defectueuse_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data)
{

GtkWidget *radiobutt1;
GtkWidget *radiobutt2;
int m,i,aa,j=-1;
int capt[50];
capteur c;
char fich[30];
char chId[30];
float seuil_minA=-500,seuil_minB=-4,seuil_maxA=70,seuil_maxB=1000;
tabCapteurs_def e[50];

radiobutt1=lookup_widget(marque_defectueuse,"radiobutton27");
radiobutt2=lookup_widget(marque_defectueuse,"radiobutton28");
aa=gtk_spin_button_get_value_as_int (GTK_SPIN_BUTTON (lookup_widget(marque_defectueuse,"spinbutton27")));

if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt1) )){
strcpy(fich,"humidite.txt");
}
if(gtk_toggle_button_get_active (GTK_TOGGLE_BUTTON(radiobutt2) )){
strcpy(fich,"temperature.txt");
}




m=remplire_tabCapteurs_def(fich,aa,seuil_minA,seuil_minB,seuil_maxA,seuil_maxB,capt);
for(i=0;i<m;i++){
sprintf(chId,"%d",capt[i]);
c= trouver_capteur(chId);
if(exist_marque(e,j+1,c.marque)==1){
    e[j].frequence++;
}else{
    j++;
strcpy(e[j].marque,c.marque);
e[j].frequence=1;
}
}
for(i=0;i<j+1;i++){
printf("%s\t%d\n",e[i].marque,e[i].frequence);
}

chercher_max_def(e,j+1);


}

