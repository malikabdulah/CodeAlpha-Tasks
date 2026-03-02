#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool dupli_user(string username)//check if username exists
{
    fstream read("credfile.txt", ios::in);
    if (read.is_open())
    {
        string u, p;
        while (read >> u >> p)
        {
            if (u == username)
            {
                read.close();
                return true;
            }
        }
        read.close();
    }
    return false;
}

bool login_check(string username, string password)
{
    fstream read("credfile.txt", ios::in);
    if (read.is_open())
    {
        string u, p;
        while (read >> u >> p)
        {
            if (u == username && p == password)
            {
                read.close();
                return true;
            }
        }
        read.close();
    }
    return false;
}

int main()
{
    string username, password, password1;
    string choice;

    while (true)
    {
        cout << endl << "========== Portal ==========" << endl;
        cout << "1. Registration" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        if (choice == "1")
        {
            cout << endl << "========== Registration ==========" << endl;
            cout << "Enter Username: ";
            cin >> username;

            if (dupli_user(username))
            {
                cout << endl << "Error: This username already exists!" << endl;
            }
            else
            {
                cout << "Enter Password: ";
                cin >> password;
                cout << "Confirm Password: ";
                cin >> password1;

                if (password == password1)
                {
                    fstream write("credfile.txt", ios::app);
                    if (write.is_open())
                    {
                        write << username << " " << password << endl;
                        write.close();
                        cout << endl << "Registration Successful!" << endl;
                    }
                    else
                    {
                        cout << endl << "Error: Could not open file for writing." << endl;
                    }
                }
                else
                {
                    cout << endl << "Error: Passwords do not match." << endl;
                }
            }
        }
        else if (choice == "2")
        {
            cout << endl << "========== Login ==========" << endl;
            cout << "Username: ";
            cin >> username;

            if (!dupli_user(username))
            {
                cout << endl << "Error: Username does not exist. Please Register first." << endl;
                continue;
            }

            int count = 0;
            bool loggedIn = false;

            while (count < 3 && !loggedIn)
            {
                cout << "Password: ";
                cin >> password;

                if (login_check(username, password))
                {
                    cout << endl << "Login Successful! Welcome, " << username << "." << endl;
                    loggedIn = true;
                }
                else
                {
                    count++;
                    cout << endl << "Wrong Password.";
                    if (count < 3)
                        cout << " Try again (" << (3 - count) << " attempts left)." << endl;
                    else
                        cout << endl << "Login Failed. Too many attempts." << endl;
                }
            }
        }
        else if (choice == "3")
        {
            cout << "Exiting..." << endl;
            break;
        }
        else
        {
            cout << "Invalid Choice!" << endl;
        }
    }
    return 0;
}