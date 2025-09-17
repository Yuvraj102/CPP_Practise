#include <iostream>
#include <string>
using namespace std;

enum Genre { FICTION, NONFICTION, SCIENCE, HISTORY, TECHNOLOGY };

string genreToString(Genre g) {
    switch (g) {
        case FICTION: return "Fiction";
        case NONFICTION: return "Nonfiction";
        case SCIENCE: return "Science";
        case HISTORY: return "History";
        case TECHNOLOGY: return "Technology";
        default: return "Unknown";
    }
}

class Book {
private:
    int bookID;
    float rating;
    double price;
    char availabilityStatus;
    bool isReferenceOnly;
    string title;
    Genre genre;

public:
    Book()
        : bookID(0), rating(0.0f), price(0.0),
          availabilityStatus('A'), isReferenceOnly(false),
          title("Untitled"), genre(FICTION) {}

    Book(int id, float r, double p, char status, bool ref, const string &t, Genre g)
        : bookID(id), rating(r), price(p),
          availabilityStatus(status), isReferenceOnly(ref),
          title(t), genre(g) {}

    ~Book() {
        cout << "Book object with ID " << bookID << " destroyed." << endl;
    }

    // Getters and setters
    void setBookID(int id) { bookID = id; }
    int getBookID() const { return bookID; }

    void setRating(float r) { rating = r; }
    float getRating() const { return rating; }

    void setPrice(double p) { price = p; }
    double getPrice() const { return price; }

    void setAvailabilityStatus(char s) { availabilityStatus = s; }
    char getAvailabilityStatus() const { return availabilityStatus; }

    void setIsReferenceOnly(bool ref) { isReferenceOnly = ref; }
    bool getIsReferenceOnly() const { return isReferenceOnly; }

    void setTitle(const string &t) { title = t; }
    string getTitle() const { return title; }

    void setGenre(Genre g) { genre = g; }
    Genre getGenre() const { return genre; }

    void updateAvailability(bool isBorrowed) {
        availabilityStatus = isBorrowed ? 'B' : 'A';
    }

    void displayDetails() const {
        cout << "Book ID: " << bookID << endl;
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
        cout << "Rating: " << rating << endl;
        cout << "Status: " << (availabilityStatus == 'A' ? "Available" : "Borrowed") << endl;
        cout << "Reference Only: " << (isReferenceOnly ? "Yes" : "No") << endl;
        cout << "Genre: " << genreToString(genre) << endl;
    }
};

// Global functions
void markAsReference(Book &book) {
    book.setIsReferenceOnly(true);
    cout << "Book " << book.getBookID() << " marked as Reference Only." << endl;
}

bool isAffordable(const Book &book, double budget) {
    return book.getPrice() <= budget;
}

void printFormattedBookList(const Book books[], int size) {
    cout << "\nID | Title | Price | Rating | Status | Reference | Genre" << endl;
    for (int i = 0; i < size; i++) {
        cout << books[i].getBookID() << " | "
             << books[i].getTitle() << " | "
             << books[i].getPrice() << " | "
             << books[i].getRating() << " | "
             << (books[i].getAvailabilityStatus() == 'A' ? "A" : "B") << " | "
             << (books[i].getIsReferenceOnly() ? "Yes" : "No") << " | "
             << genreToString(books[i].getGenre()) << endl;
    }
}

int main() {
    Book books[3];
    int choice;

    do {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add book details\n";
        cout << "2. Mark as reference-only\n";
        cout << "3. Check affordability\n";
        cout << "4. Update availability\n";
        cout << "5. Display book details\n";
        cout << "6. Display all books\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int idx, id, genreChoice;
            float rating;
            double price;
            char status;
            bool ref;
            string title;

            cout << "Enter index (0-2): ";
            cin >> idx;
            if (idx < 0 || idx > 2) { cout << "Invalid index.\n"; continue; }

            cout << "Enter Book ID: ";
            cin >> id;

            cout << "Enter Rating (0.0-5.0): ";
            cin >> rating;
            if (rating < 0.0f || rating > 5.0f) rating = 0.0f; // simple reset

            cout << "Enter Price (>0): ";
            cin >> price;
            if (price <= 0) price = 1.0; // default to 1

            cout << "Enter Status (A=Available, B=Borrowed): ";
            cin >> status;

            cout << "Is Reference Only? (1=Yes,0=No): ";
            cin >> ref;
            cin.ignore();

            cout << "Enter Title: ";
            getline(cin, title);
            if (title.empty()) title = "Untitled";

            cout << "Select Genre (0=FICTION,1=NONFICTION,2=SCIENCE,3=HISTORY,4=TECHNOLOGY): ";
            cin >> genreChoice;
            if (genreChoice < 0 || genreChoice > 4) genreChoice = 0;

            books[idx] = Book(id, rating, price, status, ref, title, static_cast<Genre>(genreChoice));
            cout << "Book stored at index " << idx << "." << endl;
        }
        else if (choice == 2) {
            int idx;
            cout << "Enter index (0-2): ";
            cin >> idx;
            if (idx >= 0 && idx < 3) markAsReference(books[idx]);
        }
        else if (choice == 3) {
            int idx; double budget;
            cout << "Enter index (0-2): "; cin >> idx;
            cout << "Enter budget: "; cin >> budget;
            if (isAffordable(books[idx], budget))
                cout << "Book is affordable.\n";
            else
                cout << "Book is NOT affordable.\n";
        }
        else if (choice == 4) {
            int idx; bool borrowed;
            cout << "Enter index (0-2): "; cin >> idx;
            cout << "Is borrowed? (1=Yes,0=No): "; cin >> borrowed;
            books[idx].updateAvailability(borrowed);
            cout << "Availability updated.\n";
        }
        else if (choice == 5) {
            int idx;
            cout << "Enter index (0-2): "; cin >> idx;
            books[idx].displayDetails();
        }
        else if (choice == 6) {
            printFormattedBookList(books, 3);
        }
    } while (choice != 7);

    return 0;
}
