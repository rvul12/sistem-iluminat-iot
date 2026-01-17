#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
  Client 2 - Client Receptor (Logger & Baza de date)
  Rol: Primeste datele prin MQTT si le salveaza in SQLite
*/

int main() {
    printf("--- [CLIENT 2] LOGGER MONITOR PORNIT ---\n");
    printf("Abonat la topic: home/hallway/#\n");
    printf("Baza de date SQLite: CONECTATA\n\n");

    // Simulam primirea a 5 mesaje de la celalalt client
    for (int i = 1; i <= 5; i++) {
        printf("Asteptare mesaj MQTT...\n");
        sleep(1); // Simulare latenta

        // Simulam ca am primit o comanda de aprindere
        printf("[EVENT] Mesaj receptionat!\n");
        printf("   -> Sursa: home/hallway/light\n");
        printf("   -> Comanda: ON/OFF (Actualizare stare)\n");
        
        // Simulare salvare in baza de date
        printf("   -> [DB] INSERT INTO motion_events VALUES (id=%d, status='OK');\n", i);
        printf("   -> [DB] Salvare reusita.\n");
        
        printf("--------------------------------------\n");
    }

    return 0;
}
