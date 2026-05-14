#pragma once
#include<iostream>
#include"clsScreen.h"
#include"Global.h"
class clsTransferLogScreen : protected clsScreen
{
private:
    static void PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(10) << left << TransferLogRecord.SourceAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.DestinationAccountNumber;
        cout << "| " << setw(10) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.SrcBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.DestBalanceAfter;
        cout << "| " << setw(10) << left << TransferLogRecord.UserName;
    }

public:

    static void ShowTransferLogScreen()
    {
       /* if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
        {
            return;
        }*/

        vector <clsBankClient::stTransferLogRecord> vTransfferLogRecord = clsBankClient::GetTransferLogList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransfferLogRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(10) << "S.Acc";
        cout << "| " << left << setw(10) << "D.Acc";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "S.Balance";
        cout << "| " << left << setw(10) << "D.Balance";
        cout << "| " << left << setw(10) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTransfferLogRecord.size() == 0)
            cout << "\t\t\t\tNo Transfer Available In the System!";
        else

            for (clsBankClient::stTransferLogRecord Record : vTransfferLogRecord)
            {

                PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

