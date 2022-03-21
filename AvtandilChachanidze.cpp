#include <iostream>
#include <ctime>
#include<vector>
#include <fstream>
using namespace std;


//დავალება 1:

//ofstream-ის გამოყენებას სჭირდება ბიბლიოთეკა fstream.
/*int main() {
	const double pi = 3, 1416; //რიცხვს(1416) არ აქვს ცვლადი რომელზეც განხორციელდება მინიჭება.
	ofstream in("data.out"); 
	int  C;  double R;
	in >> C; //ofstream-ის ოპერაციას სჭირდება "<<" ეს და არა ">>".
	pi *= 2; //pi არის კონსტანტა და ამიტომ არ შეიძლება მისი ცვლილება.
	C = pi * R; //R-ზე გამრავლება ვერ მოხერხდება რადგან R არ არის განსაზღვრული, ასევე ცნობისთვის C-ს არ მიენიჭება სწორი მნიშვნელობა რადგან იგი არის int,ხოლო ნამრავლი შეიძლება იყოს double,თუმცა კომპილერი ამას შეცდომად არ ჩათვლის
	cout << "C = " << C << endl;
}*/


//დავალება 2:

/*int main() {
	int u, z;
	cin >> z;
	while (z > 5) {
		switch (z / 2) {
		case 4:  u = z + 10 % 3; break;
		default: u = z / 2 - 2;  break;
		case 3:  u = 2 * z - 5; 
		}
		cout << "z= " << z << "\t" << "u = " << u << endl;
		--z;
	}
}*/
//7-ის შეტანის შემთხვევაში დაიბეჭდება z= 7	u= 9	 შემდეგ ხაზზე დაბეჭდავს z= 6		u= 7.
//4-ის შეტანის შემთხვევაში პროგრამა არაფერს არ გამოიტანს ეკრანზე.

//კოდის ახსნა:
//7-ის შეტანის დროს მოწმდება while-ის პირობა(7>5).რადგან პირობა სწორია კომპილერი აგრძელებს მუშაობას შემდეგ ხაზზე
//switch-ს გადაეცემა მნიშვნელობა 7/2 რაც არის 3-ის ტოლი რადგან მისი მნიშვნელობა გადაკონვერტირდება int-ად.
//შემდეგ ვეძებთ case 3.რადგან ასეთი case არსებობს შესრულდება მისი პირობა.კერძოდ u = 2 * z - 5 რაც ტოლია 9-ის.(2*7-5)
//შემდეგ ეკრანზე გამოვა z-ის და u-ს მნიშვნელობა ტაბით გამოყოფილი და ბოლოს კურსორი გადავა შემდეგ ხაზზე.
//შემდეგ z შემცირდება 1-ით და გახდება 6-ის ტოლი.
//რადგან 6>5-ზე ისევ შესრდულდება while-ის პირობა და ჩატარდება ანალოგიური ოპერაციები z=6-ისთვის.
//switch იქნება 3,შესრულდება case 3,კერძოდ u = 2 * z - 5.u ტოლი იქნება 7-ის და დაიბეჭდება z=6 და u=7 ერთმანეთისგან ტაბით გამოყოფილი.
//შემდეგ z გახდება 5.რადგანაც 5>5 მცდარია არ შერდულდება while-ის ტანი და პროგრამა დაასრულებს მუშაობას.

//4-ის შეტნის დროს z გახდება 4,რადგანაც 4>5 მცდარია არ შესრულდება while-ის ტანი,პროგრამა დაასრულებს მუშაობას და ამიტომაც იგი არაფერს არ დაბეჭდავს.

//ჩავანაცვლოთ while for-ით:

/*int main() {
	int u, z;
	cin >> z;
	for (z; z > 5; --z) {
		switch (z / 2) {
		case 4:  u = z + 10 % 3; break;
		default: u = z / 2 - 2;  break;
		case 3:  u = 2 * z - 5;
		}
		cout << "z= " << z << "\t" << "u = " << u << endl;
	}
}*/


//დავალება 3:

/*int main()
{
	vector<char> ch;
	vector<int> v;
	int maxch = 0;
	char h;
	srand(time(NULL));
	cout << "shemoitanet 50 simbolo" << endl;
	for (int b = 0; b < 50; b++) {
		v.push_back(rand() % 49 + 1);
		cin >> h;
		ch.push_back(h);
	}
	int min = v[0];
	for (int i = 1; i < ch.size(); i++) {
		if (ch[maxch] < ch[i]) {
			maxch = i;
		}
		if (min > v[i]) {
			min = v[i];
		}
	}
	if (min > maxch)
		cout << "simboloebis veqtorshi udidesi simbolos indeqsi " << maxch << " naklebia ricxvebis veqtoris umcires elementze " << min << endl;
	else if(min=maxch)
		cout<< "simboloebis veqtorshi udidesi simbolos indeqsi " << maxch << " tolia ricxvebis veqtoris umciresi elementis " << min << endl;
	else 
		cout<< "simboloebis veqtorshi udidesi simbolos indeqsi " << maxch << " metia ricxvebis veqtoris umcires elementze " << min << endl;
} */

//დავალება 4:

/*void printvector(vector<double>v);

int main() {
	vector<double>vec;
	int counter = 0, swap;
	double num;
	ifstream ifs("reals.txt");
	ofstream ofs("output.txt");
	while (ifs >> num) {
		vec.push_back(num);
	}
	printvector(vec);
	ofs << "ricxvebi romelebic ar ekutvnis [17.1,32.) shualeds arian:"<<endl;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] < 17.1 || vec[i] >= 32.) {
			counter++;
			ofs << vec[i] << endl;
		}
	}
	ofs << "mati raodenoba aris " << counter;
	cout << endl << endl;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] > 20) {
			swap = vec[i];
			vec[i] = vec[vec.size() - 3];
			vec[vec.size() - 3] = swap;
			break;
		}
	}
	cout << "shecvlis shemdeg axali veqtori aris" << endl;
	printvector(vec);

}
void printvector(vector<double>v) {
	for (auto m : v) {
		cout << m << endl;
	}
}*/















   


	









