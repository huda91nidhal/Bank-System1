#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsUser.h"
using namespace std;
class clsFindUserScreen : protected clsScreen
{
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nInfo:";
		cout << "\n___________________\n";
		cout << "First Name      :" << User.FirstName << endl;
		cout << "Last Name       :" << User.LastName << endl;
		cout << "Full Name       :" << User.FullName() << endl;
		cout << "Email           :" << User.Email << endl;
		cout << "Phone           :" << User.Phone << endl;
		cout << "UserName        :" << User.UserName << endl;
		cout << "Password        :" << User.Password << endl;
		cout << "Permissions     :" << User.Permissions << endl;
		cout << "----------------------------------------------------\n";
	}
public:
	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("\tFind User Screen");

		string UserName = " ";
		cout << "\nPlease Enter User Name: ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found , choose another one : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User1 = clsUser::Find(UserName);
		if (!User1.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser Was not Found :-(\n";
		}

		_PrintUser(User1);
	}
};

