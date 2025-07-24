#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

#define MAX_ERRORS_ALLOWED 11

int main() {


        //printf("Saisir un mot a deviner : ");
        //    scanf("%s", motSecret);


        const char *word = "anaconda"; // String correspondant au mot à trouver
        int len = strlen(word); // taille du mot à trouver
        int guessed[len]; // tableau de la taille du mot à trouver pour indiquer quelles lettres ont été trouvées
        // si guessed[i]==1, alors la lettre du mot à trouver à l'emplacement i a été trouvée
        memset(guessed, 0, sizeof(guessed)); // initaliser le tableau avec des 0

        int life_left = MAX_ERRORS_ALLOWED; // init du nombre de vies restantes
        char guessed_letters[26] = {0}; // registre des lettres déjà devinées
        char guess; // variable contenant le caratère deviné à chaque boucle

        // itère tant que le joueur a toujours des essais restants
        while (life_left > 0) {
        system("@cls||clear"); // efface l'écran
            
        if (life_left == 11) {
            system("@cls||clear"); // efface l'écran
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
        }

        if (life_left == 10) {
            system("@cls||clear"); // efface l'écran
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("\n");
            printf("_____________\n");
        }

        if (life_left == 9) {
            system("@cls||clear"); // efface l'écran
            printf("\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|____________\n");
        }

        if (life_left == 8) {
            system("@cls||clear"); // efface l'écran
            printf("\n");
            printf(" | /\n");
            printf(" |/\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|____________\n");
        }

        if (life_left == 7) {
            system("@cls||clear"); // efface l'écran
            printf("_____________\n");
            printf(" | /\n");
            printf(" |/\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|____________\n");
        }

        if (life_left == 6) {
            system("@cls||clear"); // efface l'écran
            printf("_____________\n");
            printf(" | /       |\n");
            printf(" |/\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|____________\n");
            printf("Oh non... Ma fin est proche... \n");
        }

        if (life_left == 5) {
            system("@cls||clear"); // efface l'écran
            printf("_____________\n");
            printf(" | /       |\n");
            printf(" |/        O\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|____________\n");
        }

        if (life_left == 4) {
            system("@cls||clear"); // efface l'écran
            printf("_____________\n");
            printf(" | /       |\n");
            printf(" |/        O\n");
            printf(" |         |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|____________\n");
        }

        if (life_left == 3) {
            system("@cls||clear"); // efface l'écran
            printf("_____________\n");
            printf(" | /       |\n");
            printf(" |/        O\n");
            printf(" |        /|\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|____________\n");
        }

        if (life_left == 2) {
            system("@cls||clear"); // efface l'écran
            printf("_____________\n");
            printf(" | /       |\n");
            printf(" |/        O\n");
            printf(" |        /|\\\n");
            printf(" |\n");
            printf(" |\n");
            printf("_|____________\n");
            printf("Je me sens partir... \n");
        }

        if (life_left == 1) {
            system("@cls||clear"); // efface l'écran
            printf("_____________\n");
            printf(" | /       |\n");
            printf(" |/        O\n");
            printf(" |        /|\\\n");
            printf(" |        /\n");
            printf(" |\n");
            printf("_|____________\n");
        }

            // parcourt le tableau guessed
            for (int i = 0; i < len; i++) {
                if (guessed[i]) { // si la lettre a été trouvée
                    printf("%c", word[i]); // affichée la lettre
                } else { // sinon
                    printf(" _"); // affiche '_'
                }
            }
            printf("\n");

            printf("Lettres déjà essayées : ");
            for (int i = 0; i < 26; i++) {
                if (guessed_letters[i]) {
                    printf("%c ", 'a' + i);
                }  
           }
            printf("\n");

            printf("Donne un lettre : ");
            scanf(" %c", &guess); // scanne le caractère donné et l'enregristre dans guess
            guess = tolower(guess); // met le caractère en minuscule
            while (getchar() != '\n'); // vérifie que la mémoire d'entrée est vide

            if (guessed_letters[guess - 'a']) { // si la lettre a déjà été donnée
                printf("Cette lettre à déjà été utilisée\n"); // l'indiquer
                continue; // recommencer la boucle
            }

            guessed_letters[guess - 'a'] = 1; // mémoriser quelle lettre a été utilisée à cette itération

            // flag pour savoir si la lettre donnée est valide
            int guess_is_correct = 0;
            for (int i = 0; i < len; i++) { // parcourt les caractères du mot a trouver
                if (word[i] == guess && !guessed[i]) { // si le caractère est contenu dans le mot et qu'il n'a pas encore été trouvé
                    guessed[i] = 1; // mémoriser qu'il a été trouvé
                    guess_is_correct = 1; // flag indique que la lettre donnée est valide
                }
            }

            if (guess_is_correct) { // si la lettre donnée est valide
                printf("Lettre trouvée\n"); // l'indiquer

                int game_is_won = 1;
                // vérifie si la partie est gagnée (indiqué par le flag game_is_word)
                for (int i = 0; i < len; i++) {
                    if (guessed[i] == 0) { // si le tableau guessed ne contient aucun zéro, la game est gagnée
                        game_is_won = 0;
                        break;
                    }
                }
                if (game_is_won) { // si la game est gagnée
                    system("@cls||clear"); // on efface l'ecran
                    printf("_____________\n");
                    printf(" | /       |\n");
                    printf(" |/\n");
                    printf(" |\n");
                    printf(" |                    \\O/\n");
                    printf(" |                     |\n");
                    printf("_|____________        / \\\n");
                    printf("\nJe suis en vie grâce à toi, merci ! Le mot était bien : '%s', Bien Joué", word); // on dit au joueur qu'il a gagné en lui affichant le mot qu'il a trouvé
                    return 0;
                } else {
                    continue; // si la game est pas gagnée, elle doit continuer
                }
            } else {
                life_left--; // si la lettre donnée n'est pas contenue dans le mot à trouver
            }
        }

        if (life_left == 0) {
            system("@cls||clear"); // efface l'écran
            printf("_____________\n");
            printf(" | /       |\n");
            printf(" |/        O\n");
            printf(" |        /|\\\n");
            printf(" |        / \\\n");
            printf(" |\n");
            printf("_|____________\n");
            printf("\nC'est fini, je suis mort, le mot était : %s", word);
        }
    return 0;
}
