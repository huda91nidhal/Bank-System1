#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std;
class clsAddNewUserScreen : protected clsScreen
{
private:
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter first name : ";
		User.FirstName = clsInputValidate::ReadString();
		cout << "\nEnter Last name : ";
		User.LastName = clsInputValidate::ReadString();
		cout << "\nEnter Email : ";
		User.Email = clsInputValidate::ReadString();
		cout << "\nEnter Phone : ";
		User.Phone = clsInputValidate::ReadString();
		cout << "\nEnter Password : ";
		User.Password = clsInputValidate::ReadString();
		cout << "\nEnter Permissions: ";
		User.Permissions = _ReadPermissionsToSet();
	}
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
	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		char Answer = 'n';


		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{


			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nLogin Register? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}

		return Permissions;


	}
public:
	static void ShowAddNewUserScreen()
	{
		_DrawScreenHeader("\t Add New User Screen");
		string UserName = "";
		cout << "\nPlease Enter User Name : ";
		UserName = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(UserName))
		{
			cout << "\n User Name Already in used , Choose Another one : ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);
		_ReadUserInfo(NewUser);
		clsUser::enSaveResults SaveResult;
		SaveResult = NewUser.Save();
		switch (SaveResult)
		{
		case clsUser::enSaveResults::svSucceeded:
		{
			cout << "\nUser Added Successfully :-)\n";
			_PrintUser(NewUser);
			break;
		}
		case clsUser::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError User was not saved because its empty\n";
			break;
		}
		case clsUser::enSaveResults::svFaildUserExists:
		{
			cout << "\nError , User was not saved because UserName is used\n";
			break;
		}
		}
	}
};