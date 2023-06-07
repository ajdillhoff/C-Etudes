#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "passenger.h"

void print_passenger(passenger_s *passenger) {
    // Print passenger info as CSV
    // printf("%d,%d,%s,%d,%s,%s,%d,%d,%.2f,%.2f,%.2f,%.2f,%.2f,%s,%d\n",
    //        passenger->groupid,
    //        passenger->memberid,
    //        passenger->home_planet,
    //        passenger->cryo_sleep,
    //        passenger->cabin,
    //        passenger->destination,
    //        passenger->age,
    //        passenger->vip,
    //        passenger->room_service,
    //        passenger->food_court,
    //        passenger->shopping_mall,
    //        passenger->spa,
    //        passenger->vr_deck,
    //        passenger->name,
    //        passenger->transported);

    // Print passenger info as JSON
    printf("{\n");
    printf("\t\"groupid\": %d,\n", passenger->groupid);
    printf("\t\"memberid\": %d,\n", passenger->memberid);
    printf("\t\"home_planet\": \"%s\",\n", passenger->home_planet);
    printf("\t\"cryo_sleep\": %d,\n", passenger->cryo_sleep);
    printf("\t\"cabin\": \"%s\",\n", passenger->cabin);
    printf("\t\"destination\": \"%s\",\n", passenger->destination);
    printf("\t\"age\": %d,\n", passenger->age);
    printf("\t\"vip\": %d,\n", passenger->vip);
    printf("\t\"room_service\": %.2f,\n", passenger->room_service);
    printf("\t\"food_court\": %.2f,\n", passenger->food_court);
    printf("\t\"shopping_mall\": %.2f,\n", passenger->shopping_mall);
    printf("\t\"spa\": %.2f,\n", passenger->spa);
    printf("\t\"vr_deck\": %.2f,\n", passenger->vr_deck);
    printf("\t\"name\": \"%s\",\n", passenger->name);
    printf("\t\"transported\": %d\n", passenger->transported);
    printf("}\n");

}

void print_passengers(passenger_s **passengers, int num_passengers) {
    for (int i = 0; i < num_passengers; i++) {
        print_passenger(passengers[i]);
    }
}

/*
 * Parses a line of CSV into a passenger_s struct.
 */
passenger_s *parse_passenger_csv(char *csv_line) {
    char *token = strsep(&csv_line, "_");
    int num_attr = 0;

    passenger_s *p = calloc(1, sizeof(passenger_s));

    while (token) {
        switch (num_attr) {
            case 0:
                // ID
                p->groupid = atoi(token);
                token = strsep(&csv_line, ",");
                p->memberid = atoi(token);
                break;
            case 1:
                // home planet
                // Replaces empty strings with "Deep Space"
                if (strlen(token) == 0) {
                    p->home_planet = strdup("Deep Space");
                } else {
                    p->home_planet = strdup(token);
                }
                break;
            case 2:
                // cryo sleep
                p->cryo_sleep = strcmp(token, "True") == 0;
                break;
            case 3:
                // cabin
                p->cabin = strdup(token);
                break;
            case 4:
                // destination
                p->destination = strdup(token);
                break;
            case 5:
                // age
                p->age = atoi(token);
                break;
            case 6:
                // VIP
                p->vip = strcmp(token, "True") == 0;
                break;
            case 7:
                // room service
                p->room_service = atof(token);
                break;
            case 8:
                // food court
                p->food_court = atof(token);
                break;
            case 9:
                // shopping mall
                p->shopping_mall = atof(token);
                break;
            case 10:
                // spa
                p->spa = atof(token);
                break;
            case 11:
                // VR deck
                p->vr_deck = atof(token);
                break;
            case 12:
                // name
                p->name = strdup(token);
                break;
            case 13:
                // transported
                p->transported = strcmp(token, "True") == 0;
                break;
        }

        num_attr++;
        token = strsep(&csv_line, ",");
    }

    return p;
}

// Create function to free all data in passenger_s
void free_passenger(passenger_s *passenger) {
    free(passenger->home_planet);
    free(passenger->cabin);
    free(passenger->destination);
    free(passenger->name);
    free(passenger);
}