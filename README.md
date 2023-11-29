Author- S S P Junak.<br>
ID: 222-115-103.<br>
Batch: 57(C).<br>
Metropolitan University.


Vehicle Rental System

This C++ program implements a simple Vehicle Rental System. The system allows users to rent and return vehicles such as Cars, Motorcycles, and Trucks. It provides options for renting, returning, and displaying rental information. The code is organized into classes for Vehicles, Cars, Motorcycles, Trucks, and a RentalSystem to manage the rental process.

Classes
Vehicle Class

Represents a generic vehicle with common attributes like make, model, year, and rental rate.
Provides methods for displaying vehicle information and retrieving details.
Car Class (Inherits from Vehicle)

Represents a specific type of vehicle with additional attributes such as the number of doors and fuel type.
Overrides the displayInfo method to include car-specific details.
Implements the equality operator for comparing two cars.
Motorcycle Class (Inherits from Vehicle)

Represents a motorcycle with an additional attribute for the bike type.
Overrides the displayInfo method to include motorcycle-specific details.
Implements the equality operator for comparing two motorcycles.
Truck Class (Inherits from Vehicle)

Represents a truck with attributes for load capacity and cargo type.
Overrides the displayInfo method to include truck-specific details.
Implements the equality operator for comparing two trucks.
RentalSystem Class

Manages the available and rented vehicles of each type (Car, Motorcycle, Truck).
Provides methods to add vehicles, rent, and return vehicles.
Includes methods to display information about available and rented vehicles.
Calculates the total rental cost based on the rental rate and duration.
Main Functionality
Adding Vehicles: The main function demonstrates adding instances of Car, Motorcycle, and Truck to the rental system.

Renting Vehicles: Users can select the type of vehicle they want to rent (Car, Motorcycle, or Truck) and specify the make and model. The system checks for availability and calculates the rental cost based on the duration.

Returning Vehicles: Users can return a rented vehicle by specifying the type, make, and model. The system moves the vehicle from the rented list to the available list.

Displaying Rental Information: The system provides options to display information about available and rented vehicles for each type.

Exit Option: Users can choose to exit the program.

Usage Instructions
Compile and run the program.
Choose options from the menu to rent, return, or display rental information.
Follow the prompts to input necessary details.
Exit the program when done.