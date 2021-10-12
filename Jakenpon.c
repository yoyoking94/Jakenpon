#include<stdio.h>
//#include<math.h>
//#include<limits.h>
//#include<float.h>
#include<string.h>
//#include<ctype.h>
#include<stdlib.h>
#include<time.h>

const char *tab[] = {"pierre", "feuille", "ciseau", "lezard", "spoke"};

void main(){

    Jakenpon_setup();
    Jakenpon_rand();
    Jakenpon_gameIn();
    Jakenpon_verif();
}

void Jakenpon_setup(){
    printf("Bienvenue au Pierre / Feuille / Ciseau / Lezard / Spoke\n");
    printf(
           "Les regles sont simple : \n"

            "\n"

           "Spoke casse les ciseaux \n"
           "Les ciseaus coupe la feuille \n"
           "La feuille recouvre la pierre \n"
           "La pierre ecrase le lezard \n"
           "Le lezard empoisonne spoke \n"

           "\n"

           "Spoke vaporise la pierre \n"
           "La pierre casse les ciseaux \n"
           "les ciseaux decapite le lezard \n"
           "Le lezard mange la feuille \n"
           "La feuille refute spoke \n"
           "\n"
    );

    printf("Vous pouvez choisir entre : ");
    for(int c = 0; c < 5; c++){
        printf("%s ", tab[c]);
    }
}


int Jakenpon_rand(){
    srand(time(NULL));
    int nbr_choiceIA = rand()%5;
    return nbr_choiceIA;
}


void Jakenpon_gameIn(){
    char choice[11];

    int ptsP = 0;
    int ptsIA = 0;

    for(int i = 0; i < 3; i++){
        printf("\nQuel est votre choix : ");
        scanf(" %s", &choice);
        printf("Vous avez choisi : :%s:\n", choice);

        char *choiceIA = tab[Jakenpon_rand()];
        printf("J'ai choisi : %s", choiceIA);
        int res = Jakenpon_verif(choice, choiceIA);
        printf("\n%d",res);
        if(res == 0){
            printf("\nJ'ai gagné");
            ptsIA++;
        }
        else if(res == 1){
            printf("\nNous avons fait match nul");
            ptsIA++;
            ptsP++;
        }
        else if(res == 2){
            printf("\n avez gagnez fdp");
            ptsP++;
        }
    }

    if(ptsP > ptsIA){
        printf("\nVous avez gagné avec ", ptsP, "points");
    }
    else if(ptsP < ptsIA){
        printf("\nj'ai gagné avec ", ptsIA, "points");
    }
}

int Jakenpon_verif(char *choiceP, char *choice_IA){
    if(choiceP == "spoke" && choice_IA == "ciseaux"){return 2;}
        else if(choiceP == "spoke" && choice_IA == "spoke"){return 0;}

        else if(choiceP == "ciseau" && choice_IA == "feuille"){return 2;}
        else if(choiceP == "feuille" && choice_IA == "ciseau"){return 0;}

        else if(choiceP == "feuille" && choice_IA == "pierre"){return 2;}
        else if(choiceP == "pierre" && choice_IA == "feuille"){return 0;}

        else if(choiceP == "pierre" && choice_IA == "lezard"){return 2;}
        else if(choiceP == "lezard" && choice_IA == "pierre"){return 0;}

        else if(choiceP == "lezard" && choice_IA == "spoke"){return 2;}
        else if(choiceP == "spoke" && choice_IA == "lezard"){return 0;}


        else if(choiceP == "spoke" && choice_IA == "pierre"){return 2;}
        else if(choiceP == "pierre" && choice_IA == "spoke"){return 0;}

        else if(choiceP == "pierre" && choice_IA == "ciseaux"){return 2;}
        else if(choiceP == "ciseaux" && choice_IA == "pierre"){return 0;}

        else if(choiceP == "ciseaux" && choice_IA == "lezard"){return 2;}
        else if(choiceP == "lezard" && choice_IA == "ciseaux"){return 0;}

        else if(choiceP == "lezard" && choice_IA == "feuille"){return 2;}
        else if(choiceP == "feuille" && choice_IA == "lezard"){return 0;}

        else if(choiceP == "feuille" && choice_IA == "spoke"){return 2;}
        else if(choiceP == "spoke" && choice_IA == "feuille"){return 0;}

        else{
            return 1;
        }


}
