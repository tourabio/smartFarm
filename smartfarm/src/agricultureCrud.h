void ajouter_Nouv_agriculture(agriculture a);
int exist_agriculture(char*id);
agriculture trouver_agriculture(char*id);
void modifier_agriculture(char*id,char*nom,char*dateRecolte,char*dateArrosage,char*nouv,int qtt);

void afficher_agriculture(GtkWidget* treeview1,char*l);
void supprimer_agriculture(char*id);




