#include <iostream>
using namespace std;
#define byte win_byte_override
#include <mysql.h>
class bank_management_system
{
private:
    MYSQL *conn;

public:
    bank_management_system()
    {
        conn = mysql_init(0);
        conn = mysql_real_connect(conn, "localhost", "root", "12345", "bank", 3306, NULL, 0);
        if (!conn)
        {
            cout << "ERROR " << mysql_error(conn) << endl;
        }
    }

    void sign_up()
    {
        system("cls");
        string username, password;
        cout << "------ SIGN UP -------" << endl;
        cin.ignore();
        cout << "ENTER USERNAME  " << endl;
        getline(cin, username);
        cout << "ENTER PASSWORD  " << endl;
        cin >> password;

        char query[512];
        sprintf(query, "insert into manager (username,password) values ('%s','%s')", username.c_str(), password.c_str());

        if (mysql_query(conn, query) == 0)
        {
            if (mysql_affected_rows(conn) > 0)
            {
                system("cls");
                cout << "========================================" << endl;
                cout << "---------- SIGN UP SUCCESSFULLY -------- " << endl;
                cout << "========================================" << endl
                     << endl;
            }
            else
            {
                system("cls");
                cout << "========================================" << endl;
                cout << " ----- SIGN UP IS NOT SUCCESSFULLY ----- " << endl;
                cout << "========================================" << endl
                     << endl;
            }
        }
        else
        {
            cout << "ERROR " << mysql_error(conn) << endl;
        }
    }
    void login()
    {
        system("cls");
        string username, password;
        cout << "========================================" << endl;
        cout << "         ------ LOGIN ------" << endl;
        cout << "========================================" << endl
             << endl;
        cin.ignore();
        cout << "ENTER USERNAME  " << endl;
        getline(cin, username);
        cout << "ENTER PASSWORD  " << endl;
        cin >> password;

        char query[512];
        sprintf(query, "select * from manager where username='%s' and password='%s'", username.c_str(), password.c_str());

        if (mysql_query(conn, query) == 0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if (mysql_num_rows(res) > 0)
            {
                system("cls");
                cout << "========================================" << endl;
                cout << "---------- LOGIN SUCESSFULLY ----------- " << endl;
                cout << "========================================" << endl
                     << endl;
                int choice;
                while (true)
                {
                    cout << "========================================" << endl;
                    cout << "1. CREATE ACCOUNT" << endl;
                    cout << "2. SHOW ALL ACCOUNT" << endl;
                    cout << "3. SEARCH ACCOUNT" << endl;
                    cout << "4. EXIT ACCOUNT " << endl;
                    cout << "========================================" << endl
                         << endl;
                    cout << "CHOICE ANY ONE ";
                    cin >> choice;
                    switch (choice)
                    {

                    case 1:
                        this->create_account();
                        break;

                    case 2:
                        this->show_all_account();
                        break;

                    case 3:
                        this->search_account();
                        break;
                    case 4:
                        cout << "EXIT " << endl;
                        return;

                    default:
                        cout << "This value is not available " << endl;
                        break;
                    }
                }
            }
            else
            {
                cout << "========================================" << endl;
                cout << "------------ LOGIN FAILED --------------- " << endl;
                cout << "========================================" << endl
                     << endl;
            }
            mysql_free_result(res);
        }
        else
        {
            cout << "ERROR " << mysql_error(conn) << endl;
        }
    }
    void create_account()
    {
        system("cls");
        string username;
        int pin;
        float balance;

        cout << "========================================" << endl;
        cout << "      ------ CREATE ACCOUNT ------" << endl;
        cout << "========================================" << endl
             << endl;
        cin.ignore();
        cout << "ENTER NAME: " << endl;
        getline(cin, username);
        cout << "ENTER PIN: " << endl;
        cin >> pin;
        cout << "ENTER BALANCE: " << endl;
        cin >> balance;

        char query[512];
        sprintf(query, "insert into employee1 (username,pin,balance) values ('%s',%d,%f)", username.c_str(), pin, balance);
        if (mysql_query(conn, query) == 0)
        {
            if (mysql_affected_rows(conn) > 0)
            {
                system("cls");
                cout << "========================================" << endl;
                cout << "----- CREATE ACCOUNT SUCCESSFULLY ------ " << endl;
                cout << "========================================" << endl
                     << endl;
            }
            else
            {
                system("cls");
                cout << "========================================" << endl;
                cout << "--- CREATE ACCOUNT IS NOT SUCCESSFULLY --- " << endl;
                cout << "========================================" << endl
                     << endl;
            }
        }
        else
        {
            cout << "ERROR " << mysql_error(conn) << endl;
        }
    }

    void show_all_account()
    {
        system("cls");
        char query[512];
        sprintf(query, "select * from employee1 ");

        if (mysql_query(conn, query) == 0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if (mysql_num_rows(res) > 0)
            {
                MYSQL_ROW row;
                while ((row = mysql_fetch_row(res)) != NULL)
                {
                    cout << "========================================" << endl;
                    cout << "ACCOUNT NO " << row[0] << endl;
                    cout << "USERNAME " << row[1] << endl;
                    cout << "PIN " << row[2] << endl;
                    cout << "BALANCE " << row[3] << endl;
                    cout << "========================================" << endl
                         << endl;
                }
            }
            else
            {
                system("cls");
                cout << "========================================" << endl;
                cout << "---------- RECORD NOT FOUND ------------- " << endl;
                cout << "========================================" << endl
                     << endl;
            }

            mysql_free_result(res);
        }
        else
        {
            cout << "ERROR" << mysql_error(conn) << endl;
        }
    }

    void search_account()
    {
        system("cls");
        string username;
        int pin;
        cout << "========================================" << endl;
        cout << "----------- SEARCH ACCOUNT ------------- " << endl;
        cout << "========================================" << endl
             << endl;
        cin.ignore();
        cout << "ENTER USERNAME: " << endl;
        getline(cin, username);
        cout << "ENTER PIN: " << endl;
        cin >> pin;

        char query[512];
        sprintf(query, "select * from employee1 where username='%s' and pin=%d", username.c_str(), pin);
        if (mysql_query(conn, query) == 0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if (mysql_num_rows(res) > 0)
            {
                MYSQL_ROW row = mysql_fetch_row(res);
                system("cls");
                cout << "========================================" << endl;
                cout << "------- SEARCH DATA SUCCESSFULLY ------- " << endl;
                cout << "========================================" << endl
                     << endl;
                cout << "ACCOUNT NO  " << row[0] << endl;
                cout << "USERNAME " << row[1] << endl;
                cout << "PIN " << row[2] << endl;
                cout << "BALANCE " << row[3] << endl;
                cout << "========================================" << endl
                     << endl;
            }
            else
            {
                cout << "========================================" << endl;
                cout << "----------- RECORD NOT FOUND ! ---------- " << endl;
                cout << "========================================" << endl
                     << endl;
            }

            mysql_free_result(res);
        }
        else
        {
            cout << "ERROR " << mysql_error(conn) << endl;
        }
    }

    void close_account()
    {
        system("cls");
        string username;
        int pin;
        cout << "========================================" << endl;
        cout << "----------- DELETE ACCOUNT -------------" << endl;
        cout << "========================================" << endl
             << endl;
        cin.ignore();
        cout << "ENTER USERNAME " << endl;
        getline(cin, username);
        cout << "ENTER PIN" << endl;
        cin >> pin;

        char query[512];
        sprintf(query, "delete from employee1 where username='%s' and pin=%d", username.c_str(), pin);

        if (mysql_query(conn, query) == 0)
        {
            if (mysql_affected_rows(conn) > 0)
            {
                cout << "========================================" << endl;
                cout << "----------- Delete Succesfully --------- " << endl;
                cout << "========================================" << endl
                     << endl;
            }
            else
            {
                cout << "========================================" << endl;
                cout << "-------- Delete Not Succesfully -------- " << endl;
                cout << "========================================" << endl
                     << endl;
            }
        }
        else
        {
            cout << "ERROR " << mysql_error(conn) << endl;
        }
    }
    void Bank_Manager_Panel()
    {
        system("cls");
        cout << "========================================" << endl;
        cout << "  --------- BANK MANAGER PANEL ---------" << endl;
        cout << "========================================" << endl
             << endl;

        int choice;
        system("cls");
        while (true)
        {
            cout << "========================================" << endl;
            cout << "1. Sign up " << endl;
            cout << "2. Login " << endl;
            cout << "3. EXIT " << endl;
            cout << "========================================" << endl
                 << endl;
            cout << "CHOICE ANY ONE ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                this->sign_up();
                break;
            case 2:
                this->login();
                break;
            case 3:
                system("cls");
                cout << "Exit ";
                return;
                break;

            default:
                cout << "THIS VALUE IS NOT AVILABLE " << endl;
                break;
            }
        }
    }

    void ATM_Machine()
    {
        system("cls");
        string username;
        int pin;
        int account_no;
        cout << "========================================" << endl;
        cout << "------------- ATM MACHINE -------------- " << endl;
        cout << "========================================" << endl
             << endl;
        cin.ignore();
        cout << "ENTER USERNAME " << endl;
        getline(cin, username);

        cout << "ENTER PIN: " << endl;
        cin >> pin;

        char query[512];
        sprintf(query, "select * from employee1 where username='%s' and pin=%d", username.c_str(), pin);
        system("cls");
        if (mysql_query(conn, query) == 0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            int choice;
            if (mysql_num_rows(res) == 0)
            {
                cout << "INVALID USERNAME OR PIN ❌" << endl;
                mysql_free_result(res);
                return;
            }
            else
            {
                while (true)
                {
                    cout << "------  ATM DASHBOARD ------" << endl;
                    cout << "1. Check Balance " << endl;
                    cout << "2. Deposit Money " << endl;
                    cout << "3. Withdraw Money " << endl;
                    cout << "4. Take Card Out / Logout " << endl;
                    cout << "------------------------------" << endl;
                    cout << "CHOICE ANY ONE ";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        this->Check_Balance(username, pin);
                        break;

                    case 2:
                        this->deposit_money(username, pin);
                        break;

                    case 3:
                        this->withdraw_money(username, pin);
                        break;
                    case 4:
                        system("cls");
                        cout << "LOGOUT " << endl;
                        return;
                        break;

                    default:
                        cout << "THIS VALUE IS NOT AVILABLE " << endl;
                        break;
                    }
                }
            }
        }
    }

    void Check_Balance(string username, int pin)
    {
        system("cls");

        cout << "========================================" << endl;
        cout << "------------- BALANCE CHECK ------------ " << endl;
        cout << "========================================" << endl
             << endl;

        char query[512];
        sprintf(query, "select balance from employee1 where username='%s'  and pin=%d", username.c_str(), pin);
        if (mysql_query(conn, query) == 0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if (mysql_num_rows(res) > 0)
            {
                MYSQL_ROW row = mysql_fetch_row(res);
                system("cls");
                cout << "========================================" << endl;
                cout << "     CURRENT BALANCE RS. " << row[0] << endl;
                cout << "========================================" << endl
                     << endl;
            }
            else
            {
                system("cls");
                cout << "========================================" << endl;
                cout << "------------ RECORD NOT FOUND ----------- " << endl;
                cout << "========================================" << endl
                     << endl;
            }
            mysql_free_result(res);
        }
        else
        {
            cout << "ERROR " << mysql_error(conn) << endl;
        }
    }

    void deposit_money(string username, int pin)
    {
        system("cls");
        float amount;

        cout << "========================================" << endl;
        cout << "----------- DEPOSIST MONEY ------------- " << endl;
        cout << "========================================" << endl
             << endl;

        cout << "ENTER DEPOSIT AMOUNT : ";
        cin >> amount;
        char query[512];
        sprintf(query, "update employee1 set balance=balance+%f where username='%s' and pin=%d", amount, username.c_str(), pin);
        if (mysql_query(conn, query) == 0)
        {
            system("cls");
            cout << "========================================" << endl;
            cout << "------ BALNACE ADD SUCCESFULLY -------- " << endl;
            cout << "========================================" << endl
                 << endl;
        }
        else
        {
            system("cls");
            cout << "Error " << mysql_error(conn) << endl;
        }
    }

    void withdraw_money(string username, int pin)
    {
        system("cls");
        float amount;
        cout << "========================================" << endl;
        cout << "------------ WITHDRAW MONEY ------------ " << endl;
        cout << "========================================" << endl
             << endl;

        cout << "ENTER WITHDRAW AMOUNT: ";
        cin >> amount;

        char query[512];
        sprintf(query, "select balance from employee1 where  username='%s' and pin= %d ", username.c_str(), pin);

        if (mysql_query(conn, query) == 0)
        {
            MYSQL_RES *res = mysql_store_result(conn);
            if (mysql_num_rows(res) > 0)
            {
                MYSQL_ROW row = mysql_fetch_row(res);

                float balance = 0;

                if (row[0] != NULL)
                {
                    balance = atof(row[0]);
                }
                if (amount <= balance)
                {
                    char query[512];

                    sprintf(query, "update employee1 set balance=balance-%f where username = '%s' and pin = %d", amount, username.c_str(), pin);
                    if (mysql_query(conn, query) == 0)
                    {
                        system("cls");
                        cout << "========================================" << endl;
                        cout << "-------- WITHDRAW SUCCESSFULL--------- " << endl;
                        cout << "========================================" << endl
                             << endl;
                    }
                    else
                    {
                        system("cls");
                        cout << "========================================" << endl;
                        cout << "------ WITHDRAW NOT SUCCESSFULLY ------- " << endl;
                        cout << "========================================" << endl
                             << endl;
                    }
                }
                else
                {
                    system("cls");
                    cout << "========================================" << endl;
                    cout << "--------- INSUFFICENT BALANCE ---------- " << endl;
                    cout << "========================================" << endl;
                }
            }
            else
            {
                system("cls");
                cout << "========================================" << endl;
                cout << "------------ RECORD NOT FOUND ----------- " << endl;
                cout << "========================================" << endl
                     << endl;
            }
            mysql_free_result(res);
        }
        else
        {
            system("cls");
            cout << "ERROR " << mysql_error(conn) << endl;
        }
    }
};

int main()
{

    bank_management_system obj;
    int choice;
    system("cls");
    while (true)
    {
        cout << "========================================" << endl;
        cout << "---- WELCOME TO OWAIS ISLAMIC BANK -----" << endl;
        cout << "========================================" << endl;
        cout << "1. Bank Manager Panel (Admin)" << endl;
        cout << "2. ATM Machine (Customer)" << endl;
        cout << "3. Exit Bank" << endl;
        cout << "----------------------------------------" << endl;
        cout << "ENTER YOUR CHOICE: _";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.Bank_Manager_Panel();
            break;

        case 2:
            obj.ATM_Machine();
            break;

        case 3:
            system("cls");
            cout << "========================================" << endl;
            cout << "---------------- Exit ------------------ " << endl;
            cout << "========================================" << endl;
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}
