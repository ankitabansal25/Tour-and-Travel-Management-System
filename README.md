# Tour & Travel Management System

## Overview
The **Tour & Travel Management System** is a console-based C++ application designed to help users book travel packages. The system offers functionalities such as user registration and login, destination selection, travel mode selection, passenger booking, and receipt generation.

## Features
- **User Authentication**
  - User login and registration
  - Password retrieval option

- **Destination Selection**
  - Various tour packages available
  - Selection of travel modes (Flight, Train, Road)

- **Booking Module**
  - Passenger details entry
  - Travel date selection

- **Receipt Generation**
  - Displays travel details and total cost
  - Booking confirmation message

## Modules
### 1. Login/Registration Module
- Allows users to register and log in using stored credentials.
- Users can retrieve forgotten passwords.

### 2. Destination Module
- Users can select from different travel packages.
- Provides various travel options with costs.

### 3. Booking Module
- Passengers can enter their details (name, age, gender, mobile number).
- Users specify the departure date.

### 4. Receipt Module
- Generates a detailed receipt with travel details and costs.
- Confirms booking.

### 5. Exit Module
- Allows users to exit the program.

## Installation & Usage
### Prerequisites
- C++ Compiler (G++ recommended)
- Dev-C++ or any other IDE (if preferred)

### Compilation & Execution
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/Tour-Travel-Management.git
   ```
2. Navigate to the project directory:
   ```sh
   cd Tour-Travel-Management
   ```
3. Compile the program:
   ```sh
   g++ main.cpp -o travel
   ```
4. Run the executable:
   ```sh
   ./travel
   ```

## File Structure
```
Tour-Travel-Management/
│── main.cpp          # Main source code file
│── records.txt       # Stores user credentials
│── README.md         # Project documentation
```

## Contributing
Feel free to submit pull requests or report issues on the GitHub repository.

## License
This project is open-source and available under the [MIT License](LICENSE).

