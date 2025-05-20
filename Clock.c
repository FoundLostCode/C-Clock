#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <windows.h>

int main(){
    /*
     Dieses Programm soll eine Eingabe von Stunden, Minuten und Sekunden erlauben.
     Und diese runterzählen und nach Ablauf einen Ton von sich geben.
    */
    system("color 02");
    while (true) {
        int stunden = 0;
        int minuten = 0;
        int sekunden = 0;

        printf("Geben Sie Stunden, Minuten und Sekunden ein\n");
        // Überprüfen, ob die Eingabe korrekt ist
        if (scanf("%d %d %d", &stunden, &minuten, &sekunden) != 3 || stunden < 0 || minuten < 0 || sekunden < 0) {
            printf("Ungültige Eingabe! Stellen Sie sicher, dass die Werte nicht negativ sind.\n");
            return 1;
        }

        // Ausgabe zum Testen
        printf("Stunden: %d Minuten: %d Sekunden: %d\n", stunden, minuten, sekunden);

        // Die Schleife zum Runterzählen
        while (stunden > 0 || minuten > 0 || sekunden > 0) {
            sleep(1); // Eine Sekunde warten

            if (sekunden > 0) {
                sekunden--;
            } else {
                if (minuten > 0) {
                    minuten--;
                    sekunden = 59;
                } else if (stunden > 0) {
                    stunden--;
                    minuten = 59;
                    sekunden = 59;
                }
            }

            // Ausgabe des aktuellen Zeitwertes
            printf("\rStunden: %d Minuten: %d Sekunden: %d\n", stunden, minuten, sekunden);
            fflush(stdout);  // Sofortige Ausgabe der Zeit auf der gleichen Zeile
        }
        // Ton mit dem 'beep'-Befehl auslösen
        int countdown = 0;
        bool your = true;
        while (your) {
            printf("\a");
            sleep(2);
            countdown++;
            if (countdown == 15) {
                your=false;
            }
        }
        printf("BOOMM!!\n");
        printf("Wollen Sie das Programm beenden? Wenn ja geben Sie x (klein) ein\n");
        char ending;
        //Das leehrzecihen ist hier wichtig weil er sonst die eingabe überspringt
        scanf(" %c", &ending);
        if (ending == 'x') {
            printf("Programm wird beendet\n");
            exit(0);
        }
    }

}
