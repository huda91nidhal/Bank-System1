#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
using namespace std;
class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n___________________\n";
		cout << "Country             :" << Currency.Country() << endl;
		cout << "Currency Code       :" << Currency.CurrencyCode() << endl;
		cout << "Currency Name       :" << Currency.CurrencyName() << endl;
		cout << "Rate                :" << Currency.Rate() << endl;
		cout << "----------------------------------------------------\n";
	}
	 
	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was not Found :-(\n";
		}

	}
public:
	static void FindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");
		cout << "\nFind By: [1] Code or [2] Country ?";
		short Answer;
		cin >> Answer;
		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease enter Currency Code :";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}
		else if (Answer == 2)
		{
			string Country;
			cout << "\nPlease enter Country :";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);

		}
	
	}
};

