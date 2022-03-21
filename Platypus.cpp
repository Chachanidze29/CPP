#include "Platypus.h"
Platypus::Platypus() {
	alive = false;  //default კონსტრუქტორი რომელიც ქმნის მკვდარ იხვნისკარტას
}
Platypus::Platypus(const float& w, const short& a, const char& n, const char& g, bool al, bool m) {
	weight = w;
	age = a;
	name = n;
	gender = g;			//პარამეტრებიანი კონსტრუქტორი
	alive = al;
	mutant = m;
}
//ცვლადების გეთერები და სეთერები
const float& Platypus::getWeight() const {
	return weight;
}
void Platypus::setWeight(const float& weight) {
	this->weight = weight;
}
const short& Platypus::getAge() const {
	return age;
}
void Platypus::setAge(const short& age) {
	this->age = age;
}
const char& Platypus::getName() const {
	return name;
}
void Platypus::setName(const char& name) {
	this->name = name;
}
const char& Platypus::getGender() const {
	return gender;
}
void Platypus::setGender(const char& gender) {
	this->gender = gender;
}
const bool& Platypus::isMutant() const {
	return mutant;
}
void Platypus::setMutant(const bool& mutant) {
	this->mutant = mutant;
}
const bool& Platypus::isAlive() const {
	return alive;
}
void Platypus::setAlive(const bool& alive) {
	this->alive = alive;
}
//იხვნისკარტას მონაცემების ბეჭდვის ფუნქცია
void Platypus::print()const {
	cout << "Platypus name " << name << ", It's weight(Kg) " << weight << ", Age(Month) " << age
		<< ", Gender " << gender << ", Is Alive ? " << boolalpha << alive << ", Is Mutant ? " << mutant << endl;
}
//ასაკის ზრდის ფუნქცია რომელიც პარამეტრად იღებს short ტიპის ცვლადს
void Platypus::age_me(const short& a) {
	//ვაგენერირებთ შემთხვევით რიცხვებს ერთს (1;100) და მეორეს (1;10) შუალედში
	default_random_engine dre(time(NULL));
	uniform_int_distribution<int> rdis(1, 100);
	uniform_int_distribution<int> urdis(1, 10);
	if (!this->alive) {
		cout << "Platypus is dead " << endl; return; //ვამოწმებთ არის თუარა იხვნისკარტა ცოცხალი,თუ არ არის ვბეჭდავთ შესაბამის გზავნილს და ვწყვეტთ ფუნქციის მუშაობას
	}
	//თუ ცოცხალია გაგრძელდება ფუნქცია
	if (rdis(dre) == 1 || rdis(dre) == 2) { //თუ random რიცხვი (1;100) შუალედში უდრის 1ს ან 2ს მაშინ იხვნისკარტა ხდება მუტანტი.ამის შანსი არის 2/100 ანუ 2%
		mutant = true;
	}
	if (weight >= urdis(dre)) { //თუ იხვნისკარტას წონა მეტია (1;10) შუალედში random რიცხვის მაშინ იხვნისკარტა კვდება
		alive = false;
	}
	if (a >= 0) { //თუ პარამეტრი რომელსაც ვიღებთ არის დადებითი ან 0ის ტოლი ასაკს ვზრდით ამ რიცხვით
		age += a;
	}
	else
		cout << "We can't rejuvenate " << endl; return; //სხვა შემთხვევაში ვბეჭდავთ რომ პლატიპუსს ვერ გავაახალგაზრდავებთ და ვწყვეტთ ფუნქციის მუშაობას
}
//შებრძოლების ფუნქცია რომელიც პარამეტრად იღებს სხვა პლატიპუსს
void Platypus::fight( Platypus& p) {
	default_random_engine dre(time(NULL));
	uniform_int_distribution<int> rdis(1, 100); //(1;100) შუალედში ვაგენერირებთ random რიცხვებს
	if (!this->alive || !p.alive) {		//ვამოწმებთ ჩვენი პლატიპუსები არიან თუარა ცოცხლები.თუ ერთერთი მაინც მკვდარია ფუნქცია წყვეტს მუშაობას
		cout << "Even one platypus is dead " << endl; return;
		
	}
	if ((this->weight / p.weight) * 50 > rdis(dre)) { //ვადარებთ არის თუარა წონათა შეფარდება*50ზე მეტი დაგენერირებულ random რიცხვებზე
		cout << "Winner is first platypus, name  " << this->name << endl; //თუ მეტია იმარჯვებს პირველი,ვბეჭდავთ შესაბამის გზავნილს და კვდება მეორე
		p.alive = false;
	}
	else {
		cout << "Winner is second platypus, name " << p.name << endl; //თუ ნაკლებია ან ტოლია იმარჯვებს მეორე,ვბეჭდავთ შესაბამის გზავნილს და კვდება პირველი
		this->alive = false;
	}
}
//წონის ზრდის,ანუ ჭამის ფუნქცია
void Platypus::eat() {

	if (!this->alive) {
		cout << "platypus is dead " << endl; return; //ვამოწმებთ არის თუარა იხვნისკარტა ცოცხალი.თუ არ არის ვბეჭდავთ შესაბამის გზავნილს ვწყვეტთ ფუნქციის მუშაობას
	}
	//თუ ცოცხალია ფუნქცია აგრძელებს მუშაობას და ვაგენერირებთ შემთხვევით float ტიპის რიცხვებს (0;5) შუალედში
	default_random_engine dre(time(NULL));
	uniform_real_distribution<float> rdis(0., 5.);
	weight += weight * rdis(dre) / 100; //current წონას ვუმატებთ წონა გამრავლებული random რიცხვების მეასედზე ანუ %-ზე
}
//ახალშობილის ცვლადების ინიციალიზაციის ფუნქცია
void Platypus::hatch() {
	srand(time(NULL));
	default_random_engine dre(time(NULL));
	uniform_real_distribution<float> rdis(0., 1); //ვაგენერირებთ (0;1) შუალედში შემთხვევით float ტიპის რიცხვებს
	cout << "Enter name(initial) of newborn platypus " << endl; //ვთხოვთ მომხმრებელს კლავიატურიდან იხვნისკარტას სახელის შემოტანას
	cin >> name; //შემოგქვავქს სახელი
	alive = true; //იხვნისკარტა ცოცხალია
	mutant = false; //არ არის მუტანტი
	age = 0; //ასაკი 0 თვე
	//თუ რანდომ რიცხვის 2 ზე გაყოფისას ნაშთი არის 1 მაშინ იხვნისკარტა არის მამრი,თუარადა მდედრი.შანსი არის 50/50-ზე
	if (rand() % 2 == 1) {
		gender = 'M';
	}
	else
		gender = 'F';
	weight = rdis(dre); //წონას ვანიჭებთ დაგენერირებულ float ტიპის random რიცხვს (0;1) შუალედში
}