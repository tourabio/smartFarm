#include <gtk/gtk.h>


typedef struct ouvrier ouvrier;
struct ouvrier{
char id[20];
char cin[9];
char nom[30];
char prenom[30];
char dateNaissance[30];
char permis[4];
char occupation[30];
char sexe[20];
char tel[9];
char email[30];
char adressePostale[30];
};

typedef struct tropaux tropaux;
struct tropaux{
char id[20];
char type[30];
char poids[30];
char veterinaire[30];
char signe[30];
char dateNaissance[30];
char zone[4];
char sexe[20];
int nbVaccin;
};
typedef struct equipement equipement;
struct equipement{
char id[20];
char type[30];
char remarque[30];
char immatricule[30];
char dateUtilisation[30];
char materielDispo[30];
char materielUtiliser[4];
};

typedef struct client client;
struct client{
char cin[9];
char nom[30];
char prenom[30];
char sexe[30];
char promo[30];
char dateNaissance[30];
char tel[30];
char addresse[30];
char email[30];
};

typedef struct capteur capteur;
struct capteur{
char id[30];
char type[30];
char marque[30];
char zone[30];
char precision[4];
char dateEntretien[30];
int defectueux;
};

typedef struct agriculture agriculture;
struct agriculture{
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
};

typedef struct absenteisme absenteisme;
struct absenteisme{
char id[20];
int jj;
int mm;
int aa;
int present;
};

typedef struct temperature temperature;
struct temperature{
char idCapteur[20];
int jj;
int mm;
int aa;
float valeur;
};

typedef struct tabAnneeMoy tabAnneeMoy;
struct tabAnneeMoy{
int aa;
float moy;
};
typedef struct tabOuvrierAbs tabOuvrierAbs;
struct tabOuvrierAbs{
int id_ouv;
int somme_abs;
};
typedef struct tabCapteurs tabCapteurs;
struct tabCapteurs{
int id_cap;
float max_cap;
float min_cap;
};

typedef struct tabCapteurs_def tabCapteurs_def;
struct tabCapteurs_def{
char marque[30];
int frequence;
};


GtkWidget *login;
GtkWidget *menu;
GtkWidget *gestion_ouvrier;
GtkWidget *gestion_tropaux;
GtkWidget *gestion_equipement;
GtkWidget *gestion_client;
GtkWidget *gestion_capteur;
GtkWidget *gestion_agriculture;
GtkWidget *gestion_admin;
GtkWidget *fiche_presence;
GtkWidget *annee_seche;
GtkWidget *meilleur_ouvrier;
GtkWidget *pire_ouvrier;
GtkWidget *capteur_alarmante;
GtkWidget *marque_defectueuse;
GtkWidget *type_tropaux;
int i;

void
on_button_login_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_logout_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gest_ouvrier_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_ouvrier_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_ouvrier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_consulter_ouvrier_clicked    (GtkButton       *button,
                                        gpointer         user_data);



void
on_button_modifier_ouvrier_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_ouvrier_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_tropaux_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_tropaux_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_tropaux_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_consulter_tropaux_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_tropaux_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gest_tropaux_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_equipement_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_consulter_equipement_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_equipement_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_equipement_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_equipement_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gest_equipement_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_client_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_client_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_consulter_client_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_client_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gest_client_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_client_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_capteur_clicked      (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_consulter_capteur_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_capteur_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_capteur_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_capteur_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gest_capteur_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_agriculture_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajouter_agriculture_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_consulter_agriculture_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modifier_agriculture_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_supprimer_agriculture_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gest_agriculture_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_enregistrer_presence_clicked (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_presence_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_fich_presence_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_gest_admin_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_admin_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_annee_plus_seche_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_meilleur_ouvrier_clicked     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_pire_ouvrier_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_numero_equipement_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_nombre_troupau_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_chercher_annee_clicked       (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_annee_seche_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_agricole_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_moteur_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_retour_meuilleur_ouvrier_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_chercher_meuilleur_ouvrier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_chercher_pire_ouvrier_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_pire_ouvrier_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_chercher_capteur_alarmante_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_capteur_alarmante_clicked    (GtkButton       *button,
                                        gpointer         user_data);

void chercher_max_def(tabCapteurs_def*e,int n);

void
on_button_marque_defectueuse_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_marque_defectueuse_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_chercher_tropaux_type_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_type_tropaux_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_chercher_marque_plus_defectueuse_clicked
                                        (GtkButton       *button,
                                        gpointer         user_data);
