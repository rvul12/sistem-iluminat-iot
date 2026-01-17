#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // Pentru sleep

/*
  Client 1 - Client Embedded (Senzor Hol)
  Rol: Simuleaza detectia miscarii si trimite comenzi MQTT
*/

int main() {
    int motion_detected;
    srand(time(NULL)); // Initializare random

    printf("--- [CLIENT 1] SENZOR PIR PORNIT ---\n");
    printf("Conectat la broker MQTT...\n\n");

    // Simulam 5 verificari ale senzorului
    for (int i = 1; i <= 5; i++) {
        // Generam random 0 sau 1 (0=nimic, 1=miscare)
        motion_detected = rand() % 2;

        printf("[Timp T+%d] Verificare senzor... ", i);

        if (motion_detected) {
            printf("MISCARE DETECTATA!\n");
            printf("   -> [MQTT] Publicare topic: home/hallway/light  | Mesaj: ON\n");
            printf("   -> [MQTT] Publicare topic: home/hallway/motion | Mesaj: DETECTED\n");
        } else {
            printf("Fara miscare.\n");
            printf("   -> [MQTT] Publicare topic: home/hallway/light  | Mesaj: OFF\n");
        }
        
        printf("--------------------------------------\n");
        sleep(1); // Asteapta 1 secunda
    }

    return 0;
}
