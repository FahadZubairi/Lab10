// Write a program that uses structures to manage flight information, including flight
// number, departure city, destination city, date, and available seats. Create functionalities
// to book a seat and display flight details.

#include <stdio.h>
#include <string.h>

#define MAX_SEATS 100
#define MAX_FLIGHTS 10

typedef struct {
    int flightNumber;
    char departureCity[50];
    char destinationCity[50];
    char date[15];
    int availableSeats;
} Flight;


void displayFlightDetails(Flight flight) {
    printf("\nFlight Number: %d\n", flight.flightNumber);
    printf("Departure City: %s\n", flight.departureCity);
    printf("Destination City: %s\n", flight.destinationCity);
    printf("Date: %s\n", flight.date);
    printf("Available Seats: %d\n", flight.availableSeats);
}

void bookSeat(Flight *flight) {
    if (flight->availableSeats > 0) {
        flight->availableSeats--;
        printf("Seat booked successfully! Remaining seats: %d\n", flight->availableSeats);
    } else {
        printf("No seats available on this flight.\n");
    }
}

int main() {
    Flight flights[MAX_FLIGHTS];
    int choice, flightNumber, i, flightFound = 0;

    flights[0] = (Flight){1001, "New York", "Los Angeles", "2024-12-01", 50};
    flights[1] = (Flight){1002, "Chicago", "Miami", "2024-12-02", 30};
    flights[2] = (Flight){1003, "Dallas", "San Francisco", "2024-12-03", 20};

    int totalFlights = 3;

    while (1) {
        // Menu
        printf("\n--- Flight Management System ---\n");
        printf("1. Display Flight Details\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- Available Flights ---\n");
                for (i = 0; i < totalFlights; i++) {
                    displayFlightDetails(flights[i]);
                }
                break;

            case 2:
                printf("Enter flight number to book a seat: ");
                scanf("%d", &flightNumber);

                flightFound = 0;
                for (i = 0; i < totalFlights; i++) {
                    if (flights[i].flightNumber == flightNumber) {
                        bookSeat(&flights[i]);
                        flightFound = 1;
                        break;
                    }
                }
                if (!flightFound) {
                    printf("Flight not found.\n");
                }
                break;

            case 3:
                printf("Exiting program. Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
