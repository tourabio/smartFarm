void ajouter_Nouv_capteur(capteur cap);
int exist_capteur(char*id);
capteur trouver_capteur(char*id);
void modifier_capteur(char*id,char*zone,char*precision,char*dateEntretien,int defectueux);
void afficher_capteur(GtkWidget* treeview1,char*l);
void supprimer_capteur(char*id);
/*******************************************/
int exist_cap(tabCapteurs*e,int n,int id);
int remplire_numero(tabCapteurs*e,int aa,char*fich);
float calculer_max(int id,int aa,char*fich);
float calculer_min(int id,int aa,char*fich);
int remplire_id_capt(char*fich,int aa,float seuil_minA,float seuil_minB,float seuil_maxA,float seuil_maxB,int*capt);
/********************************************/
int remplire_tabCapteurs_def(char*fich,int aa,float seuil_minA,float seuil_minB,float seuil_maxA,float seuil_maxB,int*capt);
int exist_marque(tabCapteurs_def*e,int n,char*marque);
