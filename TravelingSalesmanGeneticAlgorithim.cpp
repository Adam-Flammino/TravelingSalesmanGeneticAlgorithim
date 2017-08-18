// TravelingSalesmanGeneticAlgorithim.cpp 
// Adam Flammino
// Uses a genetic algorithm to find a good solution to the traveling salesman problem

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <vector>
#include <algorithm>
#include <string>

// Holds city details

struct City {
private:
	int x;
	int y;
public:
	// Constructor with random city coordinatates in a 1000 unit grid
	City() {
		x = rand() % 1000;
		y = rand() % 1000;
	}
	// Constructor with specific city coordinates
	City(int lat, int lon) {
		x = lat;
		y = lon;
	}
	// Get x coordinat;
	int getX() {
		return x;
	}
	// Get y coordinate
	int getY() {
		return y;
	}
};

// List of cities
class CityList
{
private:
	std::vector<City> cities; // Holds cities
public:
	// Adds city
	void addCity(City city) {
		cities.push_back(city);
	}
	// Gets city, takes city index as parameter
	City getCity(int i)
	{
		return cities.at(i);
	}
	// Get list of cities
	std::vector<City> getCityList()
	{
		return cities;
	}
};
// Holds each tour individual
class Tour
{
private:
	std::vector<City> tour;
	double distance = 0;
	double fitness = 0;
	int size;
	// Gets distance between two cities
	double distanceTwoCities(City city1, City city2) {
		int latDist = abs(city1.getX() - city2.getX());
		int lonDist = abs(city1.getY() - city2.getY());
		return sqrt((latDist * latDist) + (lonDist *lonDist)); // a^2 + b^2 = c^2
	}
public:
	// Constructor
	Tour(std::vector<City> cities)
	{
		createIndividual(cities);
	}
	// Generates a random tour of all cities
	void createIndividual(std::vector<City> cities) 
	{
		tour = cities; // Copies vector of cities
		random_shuffle(tour.begin(), tour.end()); // Shuffles tour vector
	}
	// Gets city at i
	City getCity(int i)
	{
		return tour.at(i);
	}
	// Sets city at position i
	void setCity(int i, City c)
	{
		tour.at(i) = c;
	}
	// Gets distance traveled
	double getDistance()
	{
		distance = 0;
		int size = tour.size();
		for (int i = 0; i < size - 1; i++)
		{
			distance += distanceTwoCities(tour.at(i), tour.at(i + 1));
		}
		distance += distanceTwoCities(tour.at(0), tour.at(size - 1)); // Return to starting city
		return distance;
	}
	// Gets fitness of tour individual
	double getFitness()
	{
		return 1 / getDistance();
	}
	// Check if a city is on tour
	bool onTour(City c)
	{
		for (int i = 0; i < size; i++)
		{
			if(tour.at(i).getX() == c.getX()) // Does X coord match?
			{
				if(tour.at(i).getY() == c.getY()) // Does Y coord match?
				{
					return true;
				}
			}
		}
		return false;
	}
	
};
// Population of tours
class Population
{
private:
	std::vector<Tour> tours; // Holds population of tours
	CityList cl;
	int size;
public:
	// Constructor that seeds random tours of cities
	Population(int popSize, int numCities)
	{
		for (int i = 0; i < numCities; i++) // First, add cities to list
		{
			cl.addCity(City());
		}
		for (int i = 0; i < popSize; i++); // Next, create population of tours
		{
			tours.push_back(cl.getCityList());
		}
		size = tours.size();
	}
	// Constructor that just sets size of tour
	Population(int popSize)
	{
		size = popSize;
	}
	// Adds a tour to specific index
	void addTour(Tour t)
	{
		tours.push_back(t);
	}
	// Finds shortest tour
	Tour getFittest()
	{
		Tour fittest = tours.at(0);
		for (int i = 1; i < size; i++)
		{
			if (fittest.getFitness() < tours.at(i).getFitness())
			{
				fittest = tours.at(i);
			}
		}
		return fittest;
	}
	int getPopSize()
	{
		return size;
	}
};

// Breeds population to increase fitness
class Genetics
{
private:
	const double mutationRate = .0075; // Reccomended to be between .005 and .01
	const int tournamentSize = 5;
	bool elitism = true; // If true fittest individual will move to next generation
	std::vector<Tour> tours;
public:
	// Constructor
	Genetics(std::vector<Tour> t)
	{
		tours = t;

	}
	// Evolves for one generation
	Population evolve(Population p)
	{
		int size = p.getPopSize();
		Population nextGen = Population(size);
		int eliteOffset = 0;
		if (elitism) // Saves fittest individual
		{
			eliteOffset = 1;
			nextGen.addTour(p.getFittest());
		}
	}
};

int main()
{
	const int numberOfCities = 50; // Sets number of cities
	const int populationSize = 50; // Sets size of population
	srand(time(nullptr)); // Needed so random cities are actually random
	Population p = Population(populationSize, numberOfCities); // Creates population
	Tour fittest = p.getFittest();
	std::cout << "Of the " << populationSize << " initial tours of the " << numberOfCities <<
		" cities the shortest distance was:\t" << fittest.getDistance() << std::endl;
	std::cout << "\n\nThe intial route was: \n";
	for (int i = 0; i < numberOfCities; i++) // Shows route of cities identified by coordinates
	{
		std::cout << "(" << fittest.getCity(i).getX() << "," << fittest.getCity(i).getY() << ") -> ";
	}
	std::cout << "(" << fittest.getCity(0).getX() << "," << fittest.getCity(0).getY() << ")\n"; // Back to first city
}

