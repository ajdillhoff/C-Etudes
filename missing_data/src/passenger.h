#ifndef PASSENGER_H_
#define PASSENGER_H_

#include <stdbool.h>

typedef struct {
    int groupid;
    int memberid;
    char *home_planet;
    bool cryo_sleep;
    char *cabin;
    char *destination;
    int age;
    bool vip;
    float room_service;
    float food_court;
    float shopping_mall;
    float spa;
    float vr_deck;
    char *name;
    bool transported;
} passenger_s;

passenger_s *parse_passenger_csv(char *);
void print_passenger(passenger_s *);
void print_passengers(passenger_s **, int);
void free_passenger(passenger_s *);

#endif