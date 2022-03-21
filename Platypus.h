#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;
class Platypus {
	float weight;
	short age;					//იხვნისკარტას ცვლადები
	char name, gender;
	bool alive, mutant;
public:
	Platypus();		//default კონსტრუქტორი
	Platypus(const float&, const short&, const char&, const char&, bool = 1, bool = 0);		//პარამეტრებიანი კონსტრუქტორი(ნაგულისხმეად bool alive=true,mutant=false)
	const float& getWeight() const;
	void setWeight(const float&);
	const short& getAge() const;
	void setAge(const short&);
	const char& getName() const;
	void setName(const char&);           //სეთერები და გეთერები
	const char& getGender() const;
	void setGender(const char&);
	const bool& isMutant() const;
	void setMutant(const bool&);
	const bool& isAlive() const;
	void setAlive(const bool&);
	void print()const;				//მონაცემთა ბეჭვდის ფუნქცია
	void age_me(const short&);		//ასაკის ზრდის ფუნქცია
	void fight(Platypus&);			//შებრძოლების ფუნქცია
	void eat();						//ჭამის ფუნქცია	
	void hatch();					//ახალშობილი იხვნისკარტას ცვლადების ინიციალიზაციის ფუნქცია
};