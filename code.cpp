#include<bits/stdc++.h>
using namespace std;

#define opt() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

class Vehicle
{
private:
    string make;
    string model;
    int year;
    double rentalRate;

public:
    Vehicle(string make, string model, int year, double rentalRate)
        : make(make), model(model), year(year), rentalRate(rentalRate) {}

    void displayInfo() const
    {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << "Rental Rate: " << rentalRate << endl;
    }

    double getRentalRate() const
    {
        return rentalRate;
    }

    string getMake() const
    {
        return make;
    }

    string getModel() const
    {
        return model;
    }
};

class Car : public Vehicle
{
private:
    int doors;
    string fuelType;

public:
    Car(string make, string model, int year, double rentalRate, int doors, string fuelType)
        : Vehicle(make, model, year, rentalRate), doors(doors), fuelType(fuelType) {}

    void displayInfo() const
    {
        Vehicle::displayInfo();
        cout << "Number of doors: " << doors << endl;
        cout << "Fuel Type: " << fuelType << endl;
    }

    bool operator==(const Car &other) const
    {
        return getMake() == other.getMake() &&
               getModel() == other.getModel() &&
               doors == other.doors &&
               fuelType == other.fuelType;
    }
};

class Motorcycle : public Vehicle
{
private:
    string bikeType;

public:
    Motorcycle(string make, string model, int year, double rentalRate, string bikeType)
        : Vehicle(make, model, year, rentalRate), bikeType(bikeType) {}

    void displayInfo() const
    {
        Vehicle::displayInfo();
        cout << "Bike Type: " << bikeType << endl;
    }

    bool operator==(const Motorcycle &other) const
    {
        return getMake() == other.getMake() &&
               getModel() == other.getModel() &&
               bikeType == other.bikeType;
    }
};

class Truck : public Vehicle
{
private:
    int capacity;
    string cargoType;

public:
    Truck(string make, string model, int year, double rentalRate, int capacity, string cargoType)
        : Vehicle(make, model, year, rentalRate), capacity(capacity), cargoType(cargoType) {}

    void displayInfo() const
    {
        Vehicle::displayInfo();
        cout << "Load Capacity: " << capacity << endl;
        cout << "Cargo Type: " << cargoType << endl;
    }

    bool operator==(const Truck &other) const
    {
        return getMake() == other.getMake() &&
               getModel() == other.getModel() &&
               capacity == other.capacity &&
               cargoType == other.cargoType;
    }
};

class RentalSystem
{
private:
    vector<Car> availableCars;
    vector<Motorcycle> availableMotorcycles;
    vector<Truck> availableTrucks;
    vector<Car> rentedCars;
    vector<Motorcycle> rentedMotorcycles;
    vector<Truck> rentedTrucks;

public:
    void addVehicle(const Car &car)
    {
        availableCars.push_back(car);
    }

    void addVehicle(const Motorcycle &motorcycle)
    {
        availableMotorcycles.push_back(motorcycle);
    }

    void addVehicle(const Truck &truck)
    {
        availableTrucks.push_back(truck);
    }

    const vector<Car> &getAvailableCars() const
    {
        return availableCars;
    }

    const vector<Motorcycle> &getAvailableMotorcycles() const
    {
        return availableMotorcycles;
    }

    const vector<Truck> &getAvailableTrucks() const
    {
        return availableTrucks;
    }

    const vector<Car> &getRentedCars() const
    {
        return rentedCars;
    }

    const vector<Motorcycle> &getRentedMotorcycles() const
    {
        return rentedMotorcycles;
    }

    const vector<Truck> &getRentedTrucks() const
    {
        return rentedTrucks;
    }
    void rentVehicle(const Vehicle &vehicle)
    {
        // Check if the vehicle is a Car
        for (auto it = availableCars.begin(); it != availableCars.end(); ++it)
        {
            if (it->getMake() == vehicle.getMake() && it->getModel() == vehicle.getModel())
            {
                rentedCars.push_back(*it);
                availableCars.erase(it);
                return;
            }
        }

        // Check if the vehicle is a Motorcycle
        for (auto it = availableMotorcycles.begin(); it != availableMotorcycles.end(); ++it)
        {
            if (it->getMake() == vehicle.getMake() && it->getModel() == vehicle.getModel())
            {
                rentedMotorcycles.push_back(*it);
                availableMotorcycles.erase(it);
                return;
            }
        }

        // Check if the vehicle is a Truck
        for (auto it = availableTrucks.begin(); it != availableTrucks.end(); ++it)
        {
            if (it->getMake() == vehicle.getMake() && it->getModel() == vehicle.getModel())
            {
                rentedTrucks.push_back(*it);
                availableTrucks.erase(it);
                return;
            }
        }
    }
    void returnVehicle(const Vehicle &vehicle)
    {
        // Check if the vehicle is a Car
        for (auto it = rentedCars.begin(); it != rentedCars.end(); ++it)
        {
            if (it->getMake() == vehicle.getMake() && it->getModel() == vehicle.getModel())
            {
                availableCars.push_back(*it);
                rentedCars.erase(it);
                return;
            }
        }

        // Check if the vehicle is a Motorcycle
        for (auto it = rentedMotorcycles.begin(); it != rentedMotorcycles.end(); ++it)
        {
            if (it->getMake() == vehicle.getMake() && it->getModel() == vehicle.getModel())
            {
                availableMotorcycles.push_back(*it);
                rentedMotorcycles.erase(it);
                return;
            }
        }

        // Check if the vehicle is a Truck
        for (auto it = rentedTrucks.begin(); it != rentedTrucks.end(); ++it)
        {
            if (it->getMake() == vehicle.getMake() && it->getModel() == vehicle.getModel())
            {
                availableTrucks.push_back(*it);
                rentedTrucks.erase(it);
                return;
            }
        }
    }

    void displayInfo() const
    {
        cout << "===== Available Cars =====" << endl;
        //cout << "Available Cars: " << endl;
        for (const Car &car : availableCars)
        {
            car.displayInfo();
            cout << endl;
        }

        cout << "===== Available Motorcycles =====" << endl;

        //cout << "Available Motorcycles: " << endl;
        for (const Motorcycle &motorcycle : availableMotorcycles)
        {
            motorcycle.displayInfo();
            cout << endl;
        }
        cout << "===== Available Trucks =====" << endl;

        //cout << "Available Trucks: " << endl;
        for (const Truck &truck : availableTrucks)
        {
            truck.displayInfo();
            cout << endl;
        }
        cout << "===== Rented Cars =====" << endl;

       // cout << "Rented Cars: " << endl;
        for (const Car &car : rentedCars)
        {
            car.displayInfo();
            cout << endl;
        }
        cout << "===== Rented Motorcycles =====" << endl;

        //cout << "Rented Motorcycles: " << endl;
        for (const Motorcycle &motorcycle : rentedMotorcycles)
        {
            motorcycle.displayInfo();
            cout << endl;
        }

        //cout << "Rented Trucks: " << endl;
        cout << "===== Rented Trucks =====" << endl;
        for (const Truck &truck : rentedTrucks)
        {
            truck.displayInfo();
            cout << endl;
        }
    }

    double totalCost(const Vehicle &vehicle, int days) const
    {
        double rate = vehicle.getRentalRate();
        return rate * days;
    }
    void displayforCar() const
    {
        if (availableCars.empty())
        {
            cout << "No cars available for rent." << endl;
        }
        else
        {
            cout << "Available Cars: " << endl;
            for (const Car &car : availableCars)
            {
                car.displayInfo();
                cout << endl;
            }
        }
    }

    void displayforMotorcycle() const
    {
        if (availableMotorcycles.empty())
        {
            cout << "No motorcycles available for rent." << endl;
        }
        else
        {
            cout << "Available Motorcycles: " << endl;
            for (const Motorcycle &motorcycle : availableMotorcycles)
            {
                motorcycle.displayInfo();
                cout << endl;
            }
        }
    }

    void displayforTruck() const
    {
        if (availableTrucks.empty())
        {
            cout << "No trucks available for rent." << endl;
        }
        else
        {
            cout << "Available Trucks: " << endl;
            for (const Truck &truck : availableTrucks)
            {
                truck.displayInfo();
                cout << endl;
            }
        }
    }
    bool enoghCar()
    {
        if (availableCars.empty())
        {
            return false;
        }
        else return true;
    }
    bool enoughMotorcycle()
    {
        if (availableMotorcycles.empty())
        {
            return false;
        }
        else return true;
    }
    bool enoughTruck()
    {
        if (availableTrucks.empty())
        {
            return false;
        }
        else return true;
    }
    bool RentCar()
    {
        if (rentedCars.empty())
        {
            return false;
        }
        else return true;
    }
    bool RentMotorcycle()
    {
        if (rentedMotorcycles.empty())
        {
            return false;
        }
        else return true;
    }
    bool RentTruck()
    {
        if (rentedTrucks.empty())
        {
            return false;
        }
        else return true;
    }
    void returnCar()
    {
        cout << "Rented Cars: " << endl;
        for (const Car &car : rentedCars)
        {
            car.displayInfo();
            cout << endl;
        }
    }
    void returnMotorcycle()
    {
        cout << "Rented Motorcycles: " << endl;
        for (const Motorcycle &motorcycle : rentedMotorcycles)
        {
            motorcycle.displayInfo();
            cout << endl;
        }
    }
    void returnTruck()
    {
        cout << "Rented Trucks: " << endl;
        for (const Truck &truck : rentedTrucks)
        {
            truck.displayInfo();
            cout << endl;
        }
    }

};

int main()
{
    RentalSystem rentalSystem;

    Car car("Toyota", "Supra", 2020, 100, 4, "Petrol");
    Motorcycle motorcycle("Honda", "CXR", 2000, 50, "Sport");
    Truck truck("Ford", "F150", 2001, 200, 200, "Cargo");

    rentalSystem.addVehicle(car);
    rentalSystem.addVehicle(motorcycle);
    rentalSystem.addVehicle(truck);

    while (true)
    {
        cout << endl;
        cout << "===== Vehicle Rental System =====" << endl;
        cout << "1. Rent a Vehicle" << endl;
        cout << "2. Return a Vehicle" << endl;
        cout << "3. Display Rental Information" << endl;
        cout << "4. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;
        cin.ignore(); // Ignore newline left in the buffer

        switch (choice)
        {
        case 1:
        {
            // Rent a vehicle
            cout << "Enter the vehicle type to rent:" << endl;
            cout << "1. Car" << endl;
            cout << "2. Motorcycle" << endl;
            cout << "3. Truck" << endl;

            int vehicleType;
            cin >> vehicleType;

            if(vehicleType==1)
            {
                if(rentalSystem.enoghCar()==false)
                {
                    cout<<"NO Car is available for rent"<<endl;
                    break;
                }
                else rentalSystem.displayforCar();
            }
            else if(vehicleType==2)
            {
                if(rentalSystem.enoughMotorcycle()==false)
                {
                    cout<<"NO Motorcycle is available for rent"<<endl;
                    break;
                }
                else rentalSystem.displayforMotorcycle();
            }
            else if(vehicleType==3)
            {
                if(rentalSystem.enoughTruck()==false)
                {
                    cout<<"NO Truck is avilable for rent"<<endl;
                    break;
                }
                else rentalSystem.displayforTruck();
            }

            // Additional variables for renting a vehicle
            string make, model;
            int rentalDuration;

            switch (vehicleType)
            {
            case 1:
                //rentalSystem.displayInfo();
                cout << "Enter the make of the car: ";
                cin >> make;
                cout << "Enter the model of the car: ";
                cin >> model;
                break;
            case 2:
                //rentalSystem.displayInfo();
                cout << "Enter the make of the motorcycle: ";
                cin >> make;
                cout << "Enter the model of the motorcycle: ";
                cin >> model;
                break;
            case 3:
                //rentalSystem.displayInfo();
                cout << "Enter the make of the truck: ";
                cin >> make;
                cout << "Enter the model of the truck: ";
                cin >> model;
                break;
            default:
                cout << "Invalid vehicle type. Please enter a valid option..." << endl;
                continue;  // Continue the loop to display the menu again
            }

            // Check if the selected vehicle is available
            Vehicle selectedVehicle("", "", 0, 0);
            switch (vehicleType)
            {
            case 1:
                for (const Car &car : rentalSystem.getAvailableCars())
                {
                    if (car.getMake() == make && car.getModel() == model)
                    {
                        selectedVehicle = car;
                        break;
                    }
                }
                break;
            case 2:
                for (const Motorcycle &motorcycle : rentalSystem.getAvailableMotorcycles())
                {
                    if (motorcycle.getMake() == make && motorcycle.getModel() == model)
                    {
                        selectedVehicle = motorcycle;
                        break;
                    }
                }
                break;
            case 3:
                for (const Truck &truck : rentalSystem.getAvailableTrucks())
                {
                    if (truck.getMake() == make && truck.getModel() == model)
                    {
                        selectedVehicle = truck;
                        break;
                    }
                }
                break;
            }
            double cost;

            if (selectedVehicle.getMake() != "")
            {
                // Add the vehicle to rented vehicles
                rentalSystem.rentVehicle(selectedVehicle);

                cout << "Enter the rental duration in days: ";
                cin >> rentalDuration;
                double rc;

                // Calculate total rental cost
                 rc = rentalSystem.totalCost(selectedVehicle, rentalDuration);
                cout << "Successfully rented." << endl;
                cout << "Total rental Cost: " << rc << endl;
                cost=rc;
            }
            else
            {
                cout << "Matching vehicle is not available for rent." << endl;
            }
            cout<<endl;
            cout << "===== Your Information is =====" << endl;
            cout<<"Your selected Car make is: "<<make<<endl;
            cout<<"Your selected Car model is: "<<model<<endl;
            cout<<"Total Days for rent: "<<rentalDuration<<endl;
            cout<<"Total cost is: "<<cost<<endl;
            break;
        }

        case 2:
        {
            // Return a vehicle
            cout << "Enter the vehicle type to return:" << endl;
            cout << "1. Car" << endl;
            cout << "2. Motorcycle" << endl;
            cout << "3. Truck" << endl;

            int returnVehicleType;
            cin >> returnVehicleType;

            if (returnVehicleType == 1)
            {
                if (rentalSystem.RentCar() == false)
                {
                    cout<<"Oops! No car is rented."<<endl;
                    break;
                }
                else rentalSystem.returnCar();
            }
            else if (returnVehicleType == 2)
            {
                if (rentalSystem.RentMotorcycle() == false)
                {
                    cout<<"Oops! No Motorcycle is rented."<<endl;
                    break;
                }
                else rentalSystem.returnMotorcycle();
            }
            else if (returnVehicleType == 3)
            {
                if (rentalSystem.RentTruck() == false)
                {
                    cout<<"Oops! No Truck is rented."<<endl;
                    break;
                }
                else rentalSystem.returnTruck();
            }
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            cout << "Enter the vehicle make: ";
            string make;
            getline(cin, make);

            cout << "Enter the vehicle model: ";
            string model;
            getline(cin, model);

            Vehicle selectedVehicle("", "", 0, 0);

            // Check the vehicles in rented vehicles
            for (const Car &v : rentalSystem.getRentedCars())
            {
                if (v.getMake() == make && v.getModel() == model)
                {
                    selectedVehicle = v;
                    break;
                }
            }

            if (selectedVehicle.getMake() != "")
            {
                // Add to the returned vehicles
                rentalSystem.returnVehicle(selectedVehicle);
                cout << "Vehicle returned successfully." << endl;
            }
            else
            {
                cout << "Invalid return. Vehicle not rented." << endl;
            }
            break;
        }
        case 3:
        {
            // Display Rental Information
            rentalSystem.displayInfo();
            break;
        }
        case 4:
        {
            // Exit
            cout << "Thank you for using the Vehicle Rental System. Goodbye!" << endl;
            return 0;
        }
        default:
            cout << "Invalid choice. Please enter a valid option..." << endl;
        }
    }

    return 0;
}
