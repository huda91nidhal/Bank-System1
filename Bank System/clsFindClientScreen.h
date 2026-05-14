#pragma once
#include<iostream>
#include"clsScreen.h"
using namespace std;
class clsFindClientScreen : protected clsScreen
{
private:
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nInfo:";
		cout << "\n___________________\n";
		cout << "First Name      :" << Client.FirstName << endl;
		cout << "Last Name       :" << Client.LastName << endl;
		cout << "Full Name       :" << Client.FullName() << endl;
		cout << "Email           :" << Client.Email << endl;
		cout << "Phone           :" << Client.Phone << endl;
		cout << "Account Number  :" << Client.AccountNumber() << endl;
		cout << "Pin Code        :" << Client.PinCode << endl;
		cout << "Account Balance :" << Client.AccountBalance << endl;
		cout << "----------------------------------------------------\n";
	}
public:
	static void ShowFindClientScreen()
    {
		if(!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return;
		}
        _DrawScreenHeader("\tFind Client Screen");

		string AccountNumber = " ";
		cout << "\nPlease Enter client Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found , choose another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		if (!Client1.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was not Found :-(\n";
		}

		_PrintClient(Client1);
	}
};

