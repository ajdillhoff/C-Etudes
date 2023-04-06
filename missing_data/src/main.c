#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "passenger.h"

#define BUFSIZE 1024

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        printf("USAGE: %s path/to/csv\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Cannot open \"%s\"\n", argv[1]);
        return 1;
    }

    char csv_line[BUFSIZE] = { 0 };
    passenger_s **passengers = NULL;
    int num_passengers = 0;

    // Skip header line
    fgets(csv_line, BUFSIZE, fp);

    char test[] = "0064_02,,True,E/3/S,TRAPPIST-1e,33.0,False,0.0,0.0,,0.0,0.0,Colatz Keen,True";

    passenger_s *p = parse_passenger_csv(test);

    print_passenger(p);

    // while (fgets(csv_line, BUFSIZE, fp)) {
    //     trim(csv_line);

    //     passengers = realloc(passengers, (num_passengers + 1) * sizeof(passenger_s *));
    //     passengers[num_passengers++] = parse_passenger_csv(csv_line);
    // }

    // print_passengers(passengers, num_passengers);

    // // Free memory
    // for (int i = 0; i < num_passengers; i++) {
    //     // Free strings in each passenger
    //     free_passenger(passengers[i]);
    // }

    // free(passengers);

    return 0;
}
