void ajouter_Nouv_equipement(equipement e);
int exist_equipement(char*id);
equipement trouver_equipement(char*id);
void modifier_equipement(char*id,char*remarque,char*dateUtilisation,char*materielDispo,char*materielUtiliser);
void afficher_equipement(GtkWidget* treeview1,char*l);
void supprimer_equipement(char*id);
