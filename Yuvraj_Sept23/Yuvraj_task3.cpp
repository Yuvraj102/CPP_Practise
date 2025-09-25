/*
(Airline Reservations System) A small airline has just purchased a computer for its new au- tomated reservations system. You’ve been asked to program the new system. You are to write a pro- gram to assign seats on each flight of the airline’s only plane (capacity: 10 seats).
Yourprogramshoulddisplaythefollowingmenuofalternatives—Please type 1 for "First Class"andPlease type 2 for "Economy".Ifthepersontypes1,yourprogramshouldassignaseat in the first class section (seats 1–5). If the person types 2, your program should assign a seat in the economy section (seats 6–10). Your program should print a boarding pass indicating the person’s seat number and whether it’s in the first class or economy section of the plane.
Use a one-dimensional array to represent the seating chart of the plane. Initialize all the ele- ments of the array to false to indicate that all seats are empty. As each seat is assigned, set the cor- responding elements of the array to true to indicate that the seat is no longer available.
Your program should, of course, never assign a seat that has already been assigned. When the first class section is full, your program should ask the person if it’s acceptable to be placed in the economy section (and vice versa). If yes, then make the appropriate seat assignment. If no, then print the message "Next flight leaves in 3 hours."
*/


#include <iostream>

int main() {
    bool seats[10] = {false};  // false = available, true = occupied
    int choice;

    while (true) {
        // check if plane is full
        bool full = true;
        for (int i = 0; i < 10; i++) {
            if (!seats[i]) { full = false; break; }
        }
        if (full) {
            std::cout << "\nAll seats are booked. Next flight leaves in 3 hours.\n";
            break;
        }

        std::cout << "\nPlease type 1 for \"First Class\"\n"
                  << "Please type 2 for \"Economy\"\n"
                  << "Choice: ";
        std::cin >> choice;

        if (choice == 1) {
            // assign first class seat
            int seat = -1;
            for (int i = 0; i < 5; i++) {
                if (!seats[i]) { seats[i] = true; seat = i + 1; break; }
            }

            if (seat != -1) {
                std::cout << "Boarding pass: Seat " << seat << " (First Class)\n";
            } else {
                // first class full → offer economy
                std::cout << "First class is full. Would you like Economy? (y/n): ";
                char ans; std::cin >> ans;
                if (ans == 'y' || ans == 'Y') {
                    int econSeat = -1;
                    for (int i = 5; i < 10; i++) {
                        if (!seats[i]) { seats[i] = true; econSeat = i + 1; break; }
                    }
                    if (econSeat != -1) {
                        std::cout << "Boarding pass: Seat " << econSeat << " (Economy)\n";
                    } else {
                        std::cout << "Sorry, Economy is also full. Next flight leaves in 3 hours.\n";
                    }
                } else {
                    std::cout << "Next flight leaves in 3 hours.\n";
                }
            }
        }
        else if (choice == 2) {
            // assign economy seat
            int seat = -1;
            for (int i = 5; i < 10; i++) {
                if (!seats[i]) { seats[i] = true; seat = i + 1; break; }
            }

            if (seat != -1) {
                std::cout << "Boarding pass: Seat " << seat << " (Economy)\n";
            } else {
                // economy full → offer first class
                std::cout << "Economy is full. Would you like First Class? (y/n): ";
                char ans; std::cin >> ans;
                if (ans == 'y' || ans == 'Y') {
                    int fcSeat = -1;
                    for (int i = 0; i < 5; i++) {
                        if (!seats[i]) { seats[i] = true; fcSeat = i + 1; break; }
                    }
                    if (fcSeat != -1) {
                        std::cout << "Boarding pass: Seat " << fcSeat << " (First Class)\n";
                    } else {
                        std::cout << "Sorry, First Class is also full. Next flight leaves in 3 hours.\n";
                    }
                } else {
                    std::cout << "Next flight leaves in 3 hours.\n";
                }
            }
        }
        else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
