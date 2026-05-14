#pragma once
#include <iostream>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
using namespace std;
class clsUpdateClientScreen : protected clsScreen
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
	static void ShowUpdateClientScreen()
{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
		{
			return;
		}
		_DrawScreenHeader("\tUpdate Client Screen");

	string AccountNumber = " ";
	cout << "\nPlease Enter client Account Number: ";
	AccountNumber = clsInputValidate::ReadString();
	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "\nAccount Number is not found , choose another one : ";
		AccountNumber = clsInputValidate::ReadString();
	}
	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	_PrintClient(Client1);
	cout << "\n Update Info :\n";
	cout << "--------------------------\n";
	_ReadClientInfo(Client1);
	clsBankClient::enSaveResults SaveResult;
	SaveResult = Client1.Save();
}
};

