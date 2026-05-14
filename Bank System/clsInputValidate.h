#pragma once
#include<iostream>
#include"clsDate.h"
using namespace std;
class clsInputValidate
{
public:
	static bool IsNumberBetween(short Num, short From, short To)
	{
		if ((Num >= From) && (Num <= To))
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(int Num, int From, int To)
	{
		if ((Num >= From) && (Num <= To))
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(double Num, double From, double To)
	{
		if ((Num >= From) && (Num <= To))
			return true;
		else
			return false;
	}
	static bool IsNumberBetween(float Num, float From, float To)
	{
		if ((Num >= From) && (Num <= To))
			return true;
		else
			return false;
	}
	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		// Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From))
			&&
			(clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
		{
			return true;
		}
		//Date>=To && Date<=From
		else
			if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To))
				&&
				(clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
			{
				return true;
			}

		return false;
	}
	static int ReadIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		int Number = 0;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Number;
	}
	static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within Range :\n")
	{
		int Number = ReadIntNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadIntNumber();
		}

		return Number;
	}
	static short ReadShortNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		short Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage = "Number is not within Range :\n")
	{
		short Number = ReadShortNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadShortNumber();
		}

		return Number;
	}
	static double ReadDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		double Number = 0;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}

		return Number;
	}
	static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within Range :\n")
	{
		double Number = ReadDblNumber();
		while (!IsNumberBetween(Number, From, To))
		{
			cout << ErrorMessage;
			Number = ReadDblNumber();
		}

		return Number;
	}
	static bool IsValideDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}
	static double ReadFloatNumber(string ErrorMessage = "Invalid Number, Enter again\n")
	{
		float Number;
		while (!(cin >> Number)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		}
		return Number;
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

};

