#include <iostream>  // For standard input and output
#include <fstream>   // For file handling
#include <string>    // For string handling
using namespace std;

void registerUser();    // Function to register a new user
bool loginUser();       // Function to handle user login

int main() {
    int choice;  // Variable to store user choice

    do {
        // Display menu options
        cout << "\n===== Login & Registration System =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;  // Get user inpu?t

        // Handle the user's choice
        switch (choice) {
            case 1:
                registerUser();  // Call the function to register a user
                break;
            case 2:
                if (loginUser()) {  // Call the function to handle login
                    cout << "Login Successful!\n";
                } else {
                    cout << "Login Failed! Incorrect username or password.\n";
                }
                break;
            case 3:
                cout << "Exiting the system...\n";
                break;
            default:
                cout << "Invalid choice! Please enter 1, 2, or 3.\n";
        }
    } while (choice != 3);  // Keep looping until the user chooses to exit

    return 0;  // Exit the program
}

// Function to register a new user
void registerUser() {
    string username, password;  // Variables to store username and password

    cout << "Enter a username: ";
    cin >> username;  // Input username
    cout << "Enter a password: ";
    cin >> password;  // Input password

    // Open file to read existing users
    ifstream readFile("users.txt");
    string storedUser, storedPass;

    // Check if the username already exists
    while (readFile >> storedUser >> storedPass) {
        if (storedUser == username) {
            cout << "Username already exists. Try a different one.\n";
            return;  // Exit function if the username exists
        }
    }
    readFile.close();  // Close the file

    // Open file in append mode to save new user credentials
    ofstream writeFile("users.txt", ios::app);
    writeFile << username << " " << password << endl;  // Save the credentials
    writeFile.close();  // Close the file

    cout << "Registration Successful!\n";  // Confirm registration
}

// Function to handle user login
bool loginUser() {
    string username, password;  // Variables to store user input
    string storedUser, storedPass;  // Variables to store data from the file

    cout << "Enter your username: ";
    cin >> username;  // Input username
    cout << "Enter your password: ";
    cin >> password;  // Input password

    // Open file to check credentials
    ifstream readFile("users.txt");

    // Check if the username and password match
    while (readFile >> storedUser >> storedPass) {
        if (storedUser == username && storedPass == password) {
            readFile.close();  // Close the file
            return true;  // Login successful
        }
    }
    readFile.close();  // Close the file
    return false;  // Login failed
}
