#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
using namespace std;
class clsUpdateCurrencyScreen : protected clsScreen
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
	static float _ReadRate()
	{
	    float NewRate = 0 ;
		cout << "Enter New Rate : ";
		NewRate = clsInputValidate::ReadFloatNumber();
		return NewRate;
    }
public:
	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");

		string CurrencyCode = " ";
		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found , choose another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);
		cout << "\n Are You Sure You Want To Update The Rate Of This Currency y/n?";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
		cout << "\nUpdate Currency Rate :\n";
		cout << "--------------------------\n";
		Currency.UpdateRate(_ReadRate()); 
		cout << "\nCurrency Rate Updated Successfully :-) \n";
		_PrintCurrency(Currency);
		}
	}
};