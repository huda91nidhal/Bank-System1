#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
using namespace std;
class clsAddNewClientScreen : protected clsScreen
{
private:
	static void _ReadClientInfo(clsBankClient& Client)
	{
		cout << "\nEnter first name : ";
		Client.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last name : ";
		Client.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email : ";
		Client.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone : ";
		Client.Phone = clsInputValidate::ReadString();
		cout << "\nEnter PinCode : ";
		Client.PinCode = clsInputValidate::ReadString();
		cout << "\nEnter Account Balance: ";
		Client.AccountBalance = clsInputValidate::ReadFloatNumber();
	}
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
	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}
		_DrawScreenHeader("\t Add New Client Screen");
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n Account Number Already in used , Choose Another one : ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);
		_ReadClientInfo(NewClient);
		clsBankClient::enSaveResults SaveResult;
		SaveResult = NewClient.Save();
		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Added Successfully :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError Account was not saved because its empty\n";
			break;
		}
		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
		{
			cout << "\nError Account was not saved because Account Number is used\n";
			break;
		}
		}
	}
};

