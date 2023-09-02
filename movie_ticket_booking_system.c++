// Movie Ticket Booking System in C++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// A class to represent a movie
class Movie {
    public:
        string title; // The title of the movie
        int duration; // The duration of the movie in minutes
        double price; // The price of the ticket for the movie in rupees

        // A constructor to initialize the movie object
        Movie(string t, int d, double p) {
            title = t;
            duration = d;
            price = p;
        }
};

// A class to represent a seat
class Seat {
    public:
        int row; // The row number of the seat
        int col; // The column number of the seat
        bool available; // The availability of the seat

        // A constructor to initialize the seat object
        Seat(int r, int c, bool a) {
            row = r;
            col = c;
            available = a;
        }
};

// A class to represent a booking
class Booking {
    public:
        Movie* movie; // The pointer to the movie object
        vector<Seat*> seats; // The vector of pointers to the seat objects
        double total; // The total cost of the booking

        // A constructor to initialize the booking object
        Booking(Movie* m, vector<Seat*> s) {
            movie = m;
            seats = s;
            total = 0;
            for (int i = 0; i < seats.size(); i++) {
                total += movie->price; // Add the price of each seat to the total
            }
        }

        // A method to display the booking details
        void display() {
            cout << "Movie: " << movie->title << endl;
            cout << "Duration: " << movie->duration << " minutes" << endl;
            cout << "Seats: ";
            for (int i = 0; i < seats.size(); i++) {
                cout << "(" << seats[i]->row << ", " << seats[i]->col << ") ";
            }
            cout << endl;
            cout << "Total: Rs. " << total << endl;
        }
};

// A class to represent a cinema hall
class CinemaHall {
    public:
        string name; // The name of the cinema hall
        vector<Movie*> movies; // The vector of pointers to the movie objects
        vector<vector<Seat*>> layout; // The 2D vector of pointers to the seat objects

        // A constructor to initialize the cinema hall object
        CinemaHall(string n, vector<Movie*> m, int rows, int cols) {
            name = n;
            movies = m;
            layout.resize(rows); // Resize the layout to have rows number of rows
            for (int i = 0; i < rows; i++) {
                layout[i].resize(cols); // Resize each row to have cols number of columns
                for (int j = 0; j < cols; j++) {
                    layout[i][j] = new Seat(i + 1, j + 1, true); // Create a new seat object and assign it to the layout
                }
            }
        }

        // A method to display the movie listings
        void displayMovies() {
            cout << "Welcome to " << name << endl;
            cout << "Here are the movies playing today:" << endl;
            for (int i = 0; i < movies.size(); i++) {
                cout << i + 1 << ". " << movies[i]->title << " (" << movies[i]->duration << " minutes)" 
                << " - Rs. " << movies[i]->price << endl;
            }
        }

        // A method to display the seat layout
        void displayLayout() {
            cout << "Here is the seat layout:" << endl;
            cout << "  ";
            for (int j = 0; j < layout[0].size(); j++) {
                cout << j + 1 << " "; // Display the column numbers
            }
            cout << endl;
            for (int i = 0; i < layout.size(); i++) {
                cout << i + 1 << " "; // Display the row numbers
                for (int j = 0; j < layout[i].size(); j++) {
                    if (layout[i][j]->available) { // If the seat is available, display 'O'
                        cout << "O ";
                    }
                    else { // If the seat is not available, display 'X'
                        cout << "X ";
                    }
                }
                cout << endl;
            }
        }

        // A method to make a booking
        Booking* makeBooking() {
            int movieChoice; // The choice of the movie
            int seatCount; // The number of seats to be booked
            vector<Seat*> seatChoice; // The vector of pointers to the seat objects to be booked
            int row, col; // The row and column numbers of the seat to be booked
            bool valid; // A flag to check the validity of the seat selection

            displayMovies(); // Display the movie listings
            cout << "Please enter the number of the movie you want to watch: ";
            cin >> movieChoice; // Get the movie choice from the user
            while (movieChoice < 1 || movieChoice > movies.size()) { // Validate the movie choice
                cout << "Invalid choice. Please enter a valid number: ";
                cin >> movieChoice;
            }
            cout << "You have selected " << movies[movieChoice - 1]->title << endl;

            displayLayout(); // Display the seat layout
            cout << "Please enter the number of seats you want to book: ";
            cin >> seatCount; // Get the seat count from the user
            while (seatCount < 1 || seatCount > layout.size() * layout[0].size()) { // Validate the seat count
                cout << "Invalid number. Please enter a valid number: ";
                cin >> seatCount;
            }
            for (int i = 0; i < seatCount; i++) { // Loop for each seat to be booked
                cout << "Please enter the row and column numbers of seat " << i + 1 << ": ";
                cin >> row >> col; // Get the row and column numbers from the user
                valid = false; // Initialize the flag to false
                while (!valid) { // Loop until a valid seat is selected
                    if (row < 1 || row > layout.size() || col < 1 || col > layout[0].size()) { // Check if the row and column numbers are within range
                        cout << "Invalid seat. Please enter valid row and column numbers: ";
                        cin >> row >> col;
                    }
                    else if (!layout[row - 1][col - 1]->available) { // Check if the seat is already booked
                        cout << "Seat is not available. Please enter another seat: ";
                        cin >> row >> col;
                    }
                    else {
                        valid = true; // Set the flag to true if a valid seat is selected
                    }
                }
                layout[row - 1][col - 1]->available = false; // Mark the seat as not available
                seatChoice.push_back(layout[row - 1][col - 1]); // Add the pointer to the seat object to the vector
            }

            Booking* booking = new Booking(movies[movieChoice - 1], seatChoice); // Create a new booking object and assign it to a pointer
            return booking; // Return the pointer to the booking object
        }
};

// The main function
int main() {
    // Create some movie objects and add them to a vector
    vector<Movie*> movies;
    movies.push_back(new Movie("Avengers: Endgame", 181, 250));
    movies.push_back(new Movie("The Lion King", 118, 200));
    movies.push_back(new Movie("Joker", 122, 150));
    movies.push_back(new Movie("Mission: Impossible - Fallout", 147, 180));

    // Create a cinema hall object with 10 rows and 10 columns of seats
    CinemaHall cinema("PVR Cinemas", movies, 10, 10);

    char choice; // A variable to store the user's choice to continue or exit

    do {
        Booking* booking = cinema.makeBooking(); // Make a booking and get a pointer to it
        booking->display(); // Display the booking details

        cout << "Do you want to make another booking? (Y/N): ";
        cin >> choice; // Get the user's choice to continue or exit
        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') { // Validate the user's choice
            cout << "Invalid choice. Please enter Y or N: ";
            cin >> choice;
        }
    } while (choice == 'Y' || choice == 'y'); // Loop until the user chooses to exit

    cout << "Thank you for using our service. Have a nice day!" << endl;

    return 0;
}
