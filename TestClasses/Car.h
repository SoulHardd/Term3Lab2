#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

typedef std::string String;

class Car
{
private:
    String maker;
    String model;
    String color;
    String license_plate;
    String owner_name;
    String owner_address;
    String fuel_type;

    long id;

    double engine_capacity;
    double mileage;
    double price;

    int year;
    int doors;
    int seats;

    bool is_insured;
    bool is_damaged;

public:
    Car()
        : maker(""),
          model(""),
          color(""),
          license_plate(""),
          owner_name(""),
          owner_address(""),
          fuel_type(""),
          id(0),
          engine_capacity(0.0),
          mileage(0.0),
          price(0.0),
          year(0),
          doors(0),
          seats(0),
          is_insured(false),
          is_damaged(false) {}

    Car(
        const String &maker,
        const String &model,
        const String &color,
        const String &license_plate,
        const String &owner_name,
        const String &owner_address,
        const String &fuel_type,
        long id,
        double engine_capacity,
        double mileage,
        double price,
        int year,
        int doors,
        int seats,
        bool is_insured,
        bool is_damaged)
        : maker(maker),
          model(model),
          color(color),
          license_plate(license_plate),
          owner_name(owner_name),
          owner_address(owner_address),
          fuel_type(fuel_type),
          id(id),
          engine_capacity(engine_capacity),
          mileage(mileage),
          price(price),
          year(year),
          doors(doors),
          seats(seats),
          is_insured(is_insured),
          is_damaged(is_damaged) {}

    friend std::ostream &operator<<(std::ostream &os, const Car &c)
    {
        return os << "|Maker: " << c.maker
                  << "|Model: " << c.model
                  << "|Color: " << c.color
                  << "|License Plate: " << c.license_plate
                  << "|Owner Name: " << c.owner_name
                  << "|Owner Address: " << c.owner_address
                  << "|Fuel Type: " << c.fuel_type
                  << "|ID: " << c.id
                  << "|Engine Capacity: " << c.engine_capacity << " L"
                  << "|Mileage: " << c.mileage << " km"
                  << "|Price: $" << c.price
                  << "|Year: " << c.year
                  << "|Doors: " << c.doors
                  << "|Seats: " << c.seats
                  << "|Insured: " << (c.is_insured ? "Yes" : "No")
                  << "|Damaged: " << (c.is_damaged ? "Yes" : "No") << "|\n";
    }

    friend std::istream &operator>>(std::istream &is, Car &c)
    {
        std::cout << "Maker: ";
        is >> c.maker;
        std::cout << "Model: ";
        is >> c.model;
        std::cout << "Color: ";
        is >> c.color;
        std::cout << "License Plate: ";
        is >> c.license_plate;
        std::cout << "Owner Name: ";
        is >> c.owner_name;
        std::cout << "Owner Address: ";
        is >> c.owner_address;
        std::cout << "Fuel Type: ";
        is >> c.fuel_type;
        std::cout << "ID: ";
        is >> c.id;
        std::cout << "Engine Capacity: ";
        is >> c.engine_capacity;
        std::cout << "Mileage: ";
        is >> c.mileage;
        std::cout << "Price: ";
        is >> c.price;
        std::cout << "Year: ";
        is >> c.year;
        std::cout << "Doors: ";
        is >> c.doors;
        std::cout << "Seats: ";
        is >> c.seats;
        std::cout << "Is Insured (1 for Yes, 0 for No): ";
        is >> c.is_insured;
        std::cout << "Is Damaged (1 for Yes, 0 for No): ";
        is >> c.is_damaged;
        return is;
    }
};

#endif