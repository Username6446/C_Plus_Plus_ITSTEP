#include <iostream>
#include <string>
using namespace std;

const size_t MIN_POWER = 50;
const size_t MAX_POWER = 100;

const size_t MIN_VOLUME = 0.7;
const size_t MAX_VOLUME = 6;

const size_t MIN_SPEED_LOW = 100;
const size_t MAX_SPEED_UP = 350;

struct  Date {
    size_t day, month, year;
    string getDate()
    {
        return (day < 10 ? "0" : "") + to_string(day) + (".") + (month < 10 ? "0" : "") + to_string(month) + to_string(month) + "." + to_string(month);
    }
};

class Car {
private:
    string brand = "NoBrand";
    string color = "NoColor";
    size_t power = 0;
    double volume = 0;
    size_t max_speed = 0;
    Date date = Date();
public:
    //Car() {
    //    brand = "NoBrand";
    //    color = "NoColor";
    //    power = 0;
    //    volume = 0;
    //    max_speed = 0;
    //    date = Date();
    //}
    Car() = default;
    /*Car(const string& brand_, const string& color_, const size_t& power_, const double& volume_, const Date& date_) {
		brand = brand_;
		color = color_;
		power = power_;
		volume = volume_;
		date = date_;
    }*/
    Car(const string& brand, const string& color, const size_t& power, const double& volume, const Date& date) {
		this->brand = brand;
		this->color = color;
		this->power = power;
		this->volume = volume;
		this->date = date;
    }
    void setBrand(const string & brand) {
        if (brand.empty() or brand == " ") {
			cout << "Error!!! Brand is empty!" << endl;
            return;
            
        }
        
        this->brand = brand;
	}
    string getBrand() const {
        return brand;
	}
    void setColor(const string & color) {
		if (color.empty() or color == " ") {
            cout << "Error!!! Color is empty!" << endl;
            return;
        }
        
		this->color = color;
    }
    string getColor() const {
        return color;
    }
    void print()
    {
		cout << "\n\n ============ " << this->brand << " ============ " << endl;
		cout << "\t\t Color  :: " << this->color << endl;
		cout << "\t\t Power  :: " << this->power << endl;
		cout << "\t\t Volume :: " << this->volume << endl;
		cout << "\t\t Date   :: " << this->date.getDate() << endl;
    }
    void input()
    {
		cout << "Enter brand: "; getline(cin, this->brand);
		cout << "Enter color: "; getline(cin, this->color);
		cout << "Enter power: "; cin >> this->power;
		cout << "Enter volume: "; cin >> this->volume;
		cout << "Enter date (day month year): "; cin >> this->date.day >> this->date.month >> this->date.year;
    }
};

struct PIB {
    string first_name;
    string last_name;
    string middle_name;
    string getFullName() {
        return first_name + " " + middle_name + " " + last_name;
	}
};

class Student {
private:
	PIB name;
	Date birth_date;
	string phone_number;
    string city;
    string country;
	string university;
	string country_university;
	string city_university;
	int number_group;

public:
	Student() = default;
    Student(const PIB& name, const Date& birth_date, const string& phone_number, const string& city, const string& country,
            const string& university, const string& country_university, const string& city_university, int number_group)
        : name(name), birth_date(birth_date), phone_number(phone_number), city(city), country(country),
          university(university), country_university(country_university), city_university(city_university),
          number_group(number_group) {}

    void setName(const PIB& name) {
        this->name = name;
    }
    PIB getName() const {
		return name;
	}
    void setBirthDate(const Date& birth_date) {
		this->birth_date = birth_date;
	}
	Date getBirthDate() const {
		return birth_date;
	}
	void setPhoneNumber(const string& phone_number) {
		this->phone_number = phone_number;
	}
	string getPhoneNumber() const {
		return phone_number;
	}
	void setCity(const string& city) {
		this->city = city;
	}
	string getCity() const {
		return city;
	}
	void setCountry(const string& country) {
		this->country = country;
	}
	string getCountry() const {
		return country;
	}
	void setUniversity(const string& university) {
		this->university = university;
	}
	string getUniversity() const {
		return university;
	}
	void setCountryUniversity(const string& country_university) {
		this->country_university = country_university;
	}
	string getCountryUniversity() const {
		return country_university;
	}
	void setCityUniversity(const string& city_university) {
		this->city_university = city_university;
	}
	string getCityUniversity() const {
		return city_university;
	}
	void setNumberGroup(int number_group) {
		this->number_group = number_group;
	}
	int getNumberGroup() const {
		return number_group;
	}

    void input() {
	cout << "Enter full name (first middle last): ";
	string first, middle, last;
	cin >> first >> middle >> last;
	name = { first, middle, last};
	cout << "Enter birth date (day month year): ";
	cin >> birth_date.day >> birth_date.month >> birth_date.year;
	cout << "Enter phone number: "; cin >> phone_number;
	cout << "Enter city: "; cin >> city;
	cout << "Enter country: "; cin >> country;
	cout << "Enter university: "; cin >> university;
	cout << "Enter country of university: "; cin >> country_university;
	cout << "Enter city of university: "; cin >> city_university;
	cout << "Enter group number: "; cin >> number_group;
	}
	void print() {
		cout << "Full Name: " << name.getFullName() << endl;
		cout << "Birth Date: " << birth_date.getDate() << endl;
		cout << "Phone Number: " << phone_number << endl;
		cout << "City: " << city << endl;
		cout << "Country: " << country << endl;
		cout << "University: " << university << endl;
		cout << "Country of University: " << country_university << endl;
		cout << "City of University: " << city_university << endl;
		cout << "Group Number: " << number_group << endl;
	}
};

int main()
{
    Car audi("Audi", "Red", 150, 2.0, Date{1, 1, 2020});
    Car ford("Ford", "Blue", 120, 1.8, Date{ 15, 5, 2019 });

	Car bmw;
    bmw.input();
    audi.print();
    ford.print();
    bmw.print();
	return 0;

    
}
