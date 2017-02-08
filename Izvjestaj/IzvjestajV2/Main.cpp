#include "Izvjestaj.h"

int main() {
	map<string, vector<double>> mjesecni_podaci_financije;
	map<string, vector<double>> mjesecni_podaci_skladiste;
	// svaki podatak odgovara jednom mjesecu, pocevsi od sijecnja
	mjesecni_podaci_financije["TROSKOVI"] = { 000.00, 120.66, 450.95, 200.00, 325.12, 2323, 233.66, 500.21, 552.3, 656.4, 3324.66, 2675.33, 232.00 };
	mjesecni_podaci_financije["IZVOZ"] = { 000.00, 1902.17, 850.00, 625.55, 424.22, 552.12, 120, 334.54, 1235.67, 980, 992.55, 123.55, 223.55, 112.55 };

	mjesecni_podaci_skladiste["TROSKOVI"] = { 000.00, 190.17, 850.00, 625.55, 424.22, 552.12, 120, 334.54, 1235.67, 980, 992.55, 123.55, 223.55, 112.55 };
	mjesecni_podaci_skladiste["IZVOZ"] = { 000.00, 150.66, 640.95, 200.23, 235.12, 323, 283.66, 670.21, 982.3, 356.4, 324.66, 475.33, 132.00 };


	Izvjestaji::FinancijskiIzvjestaj* mi = new MjesecniIzvjestaj("1.1.2016.","1.9.2016.", mjesecni_podaci_financije);
	Izvjestaji::FinancijskiIzvjestaj* gi = new GodisnjiIzvjestaj("1.1.2016.", "1.1.2017.", mjesecni_podaci_financije);

	Izvjestaji::Troskovi* tm = new MjesecniIzvjestaj("1.5.2016", "1.10.2016", mjesecni_podaci_skladiste);
	Izvjestaji::Troskovi* tg = new GodisnjiIzvjestaj("1.5.2016", "1.10.2016", mjesecni_podaci_skladiste);
	
	cout << "######### Financijsi izvjestaj ########" << endl;
	mi->prikazi();
	gi->prikazi();
	cout << "######### Troskovni izvjestaj ########" << endl;
	tm->prikazi();
	tg->prikazi();

	delete mi;
	delete gi;
	
	system("pause");
	return 0;
}
