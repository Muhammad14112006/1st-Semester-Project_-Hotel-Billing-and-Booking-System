#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// int Global Variables
int choice, option;
int roomPrice;

// string Global Variables
string username, password;

// bool Global Variables
bool running = true;

// void Function Prototypes
void printH(int row);
void printB(int row);
void printS(int row);
void AdminLogin();
void AdminList();
void ViewRoomsStatus();
void ViewAllBookings();
void StaffSignIn();
void GenerateInvoice();
void UpdateRoomPrices();
void RoomPrices();
void LoadRoomPrice();

// int function prototypes
int LoginPage();
int AdminMenu();
int StaffMenu();

// string function prototypes
string AddAdmin();
string RemoveAdmin();
string UpdateAdminPass();
string AddStaff();
string RemoveStaff();
string UpdateStaffPass();
string StaffList();
string AddRooms();
string RemoveRooms();
string ViewAvailableRooms();
string CheckIn();
string CheckOut();
string ViewGuestBookings();
string UpdateGuestBooking();
string CancelBooking();

// bool function prototypes
bool CheckAdmin(string AdminName, string AdminPass);
bool IsStrongPassword(const string& password);
bool NameExists(string name);
bool PasswordExists(string pass);
bool CheckStaff(string StaffName, string StaffPass);

// Colour Code
string reset   = "\033[0m";
string red     = "\033[31m";
string green   = "\033[32m";
string yellow  = "\033[33m";
string blue    = "\033[34m";
string magenta = "\033[35m";
string cyan    = "\033[36m";
string white   = "\033[37m";
string b_red   = "\033[91m"; // Bright Red
string b_green = "\033[92m"; // Bright Green
string b_cyan  = "\033[96m"; // Bright Cyan

// Main Function

int main()
{
    LoadRoomPrice();
 while (running)
 {
    system("cls");
    cout<<cyan<<setfill('#')<<setw(40)<<""<<reset<<endl;
    for(int i = 0; i < 5; i++)
    {
        printH(i);
        cout<<"   ";
        printB(i);
        cout<<"   ";
        printB(i);
        cout<<" ";
        printS(i);
        cout<<endl;
    }
    cout<<cyan<<setfill('#')<<setw(40)<<""<<reset<<endl;
     LoginPage();

     if (choice == 1)
     {
        system ("cls");
        cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
        cout<<green<<"        Admin Login"<<reset<<endl;
        cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;

        AdminLogin();
        bool check = CheckAdmin(username, password);

        if (check)
        {
           cout<<"Login Successful"<<endl;
        
           choice = AdminMenu();

           switch (choice)
           {
               case 1: 
               AddAdmin();
               break;

               case 2: 
               RemoveAdmin();
               break;

               case 3: 
               UpdateAdminPass();
               break;

               case 4:
               AdminList();
               break;

               case 5:
               AddStaff();
               break;

               case 6:
               RemoveStaff();
               break;

               case 7: 
               UpdateStaffPass();
               break;

               case 8:
               StaffList();
               break;

               case 9:
               ViewRoomsStatus();
               break;

               case 10:
               AddRooms();
               break;

               case 11:
               RemoveRooms();
               break;

               case 12:
               ViewAllBookings();
               break;

               case 13:
               RoomPrices();
               break;

               case 14:
               UpdateRoomPrices();
               break;

               case 15:
               cout<<"Logging out of Dashboard..."<<endl;
               running = false;
               break;

               default:
               cout<<"Invalid Choice..."<<endl;
               break;
           }
         }
         else
         {
             cout<<"Login Failed...\nInvalid username or Password. Try Again."<<endl;
         }
    }

    else if (choice == 2)
    {
       
        StaffSignIn();
        bool check = CheckStaff(username, password);
        if (check)
        {
            cout<<"\n"<<green<<"Staff Login Successful"<<reset<<endl;
            system("pause");
            choice = StaffMenu();
            switch (choice)
            {
                case 1:
                ViewAvailableRooms();
                break;

                case 2:
                CheckIn();
                break;

                case 3:
                CheckOut();
                break;

                case 4:
                ViewGuestBookings();
                break;

                case 5:
                UpdateGuestBooking();
                break;

                case 6:
                CancelBooking();
                break;

                case 7:
                GenerateInvoice();
                break;

                case 8:
                RoomPrices();
                break;

                case 9:
                cout<<"Logging out of Dashboard..."<<endl;
                running = false;
                break;

                default:
                cout<<"Invalid Choice..."<<endl;
                break;
            }
        }
        else
        {
            cout<<"Login Failed...\nInvalid username or Password. Try Again."<<endl;
        }
    }
 }
}

// Print H Function

void printH(int row) 
{
    string H[5] = {
        "     #   #",
        "     #   #",
        "     #####",
        "     #   #",
        "     #   #"
    };
    cout <<green<< H[row]<<reset;
}

// Print B Function

void printB(int row) 
{
    string B[5] = 
    {
        "#### ",
        "#   #",
        "#### ",
        "#   #",
        "#### "
    };
    cout <<green<< B[row]<<reset;
}

// Print S Function

void printS(int row) 
{
    string S[5] = 
    {
        " ####",
        "#    ",
        " ### ",
        "    #",
        "#### "
    };
    cout <<green<< S[row]<<reset;
}

// Login Page Function

int LoginPage()
{
    cout<<"\nEnter Login Type: \n"<<endl;
    cout<<"1. Admin"<<endl;
    cout<<"2. Staff"<<endl;
    cout<<"\n"<<yellow<<"Choose your preference (1/2): "<<reset;
    string input;
    getline(cin, input);
    try
    {
        choice = stoi(input);
    }
    catch(invalid_argument &e)
    {
        choice = 0;
    }   

    return choice;
}

// Admin Login Function

void AdminLogin()
{
    cout<<"Enter username: ";
    getline(cin,username);

    cout<<"Enter password: ";
    getline(cin, password);
}

// Check Admin Credentials Function

bool CheckAdmin(string AdminName, string AdminPass)
{
    fstream file("Admin.txt", ios::in);
    if (!file.is_open()) 
    {
        return false;
    }

    string a_name, a_pass, blank;

    while (true)
    {
        if (!getline(file, a_name)) break;
        if (!getline(file, a_pass)) break;
        getline(file, blank);

        if (a_name == AdminName && a_pass == AdminPass)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Admin Menu Function

int AdminMenu()
{
    system("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"        Admin Menu"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<"\n1. Add New Admin"<<endl;
    cout<<"2. Remove Admin"<<endl;
    cout<<"3. Update Admin Password"<<endl;
    cout<<"4. View Admin List"<<endl;
    cout<<"5. Add Staff"<<endl;
    cout<<"6. Remove Staff"<<endl;
    cout<<"7. Update Staff Password"<<endl;
    cout<<"8. View Staff List"<<endl;
    cout<<"9. View Rooms Status"<<endl;
    cout<<"10. Add Rooms"<<endl;
    cout<<"11. Remove Rooms"<<endl;
    cout<<"12. View All Bookings"<<endl;
    cout<<"13. View Room Prices"<<endl;
    cout<<"14. Update Room Prices"<<endl;
    cout<<"15. Exit"<<endl;
   while (true)
   {
       cout << yellow<<"\nEnter your choice: "<<reset;
       string option;
       getline(cin, option);

       try 
       {
           choice = stoi(option);
           break;
       }
        catch (...) 
       {
           cout << "Invalid input! Please enter a number only.\n";
       }
   }
       return choice;
}

// Add Admin Function   

string AddAdmin()
{
    system("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"        Add New Admin"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    string name, pass, c_pass;

    fstream file("Admin.txt", ios::app);
    if (!file.is_open())
    {
        return "Error opening file. Try again.";
    }

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter new Admin's Name: ";
        getline(cin, name);

        if (name.empty())
        {
            system("cls");
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout<<green<<"        Add New Admin"<<reset<<endl;
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout <<red<< "Name cannot be empty. Try Again..." <<reset<< endl;
            continue;
        }

        if (NameExists(name))
        {
            system ("cls");
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout<<green<<"        Add New Admin"<<reset<<endl;
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout <<red<< "Admin name already exists. Try Again..." <<reset<< endl;
            continue;
        }

        cout << "Enter Admin's Password: ";
        getline(cin, pass);

        if (!IsStrongPassword(pass))
        {
            system ("cls");
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout<<green<<"        Add New Admin"<<reset<<endl;
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout <<red<< "Password must be 6 to 15 chars and include upper, lower, digit, special. Try Again..." <<reset<< endl;
            continue;
        }

        cout << "Confirm Password: ";
        getline(cin, c_pass);

        if (pass != c_pass)
        {
            system ("cls");
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout<<green<<"        Add New Admin"<<reset<<endl;
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout <<red<< "Passwords do not match. Try Again..." <<reset<< endl;
            continue;
        }

        if (PasswordExists(pass))
        {
            system ("cls");
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout<<green<<"        Add New Admin"<<reset<<endl;
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout <<red<< "Password already in use. Try Again..." <<reset<< endl;
            continue;
        }

        file << name << "\n" << pass << "\n\n";

        file.close();
        return "Success";
    }

    file.close();
    return "Failed";
}

// Remove Admin Function

string RemoveAdmin()
{
    system("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"        Remove Admin"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    string d_name, a_name, a_pass, blank;

    cout << "Enter the Name of the admin to delete: ";
    getline(cin, d_name);

    fstream file("Admin.txt", ios::in);

    if (!file.is_open())
    {
        return "Error! File could not be opened.";
    }

    fstream temp("temp.txt", ios::out);
    if (!temp.is_open())
    {
        file.close();
        return "Error! Temp file could not be opened.";
    }

    bool found = false;

    while (true)
    {
        if (!getline(file, a_name)) break;
        if (!getline(file, a_pass)) break;
        getline(file, blank); // skip blank line

        if (a_name == d_name)
        {
            found = true;
            continue;
        }

        temp << a_name << "\n" << a_pass << "\n\n";
    }

    file.close();
    temp.close();

    remove("Admin.txt");
    rename("temp.txt", "Admin.txt");

    if (found)
    {
        return "Admin Removed Successfully.";
    }
    else
    {
        return "The Given Admin name doesn't exist.";
    }

}

// Update Admin Password Function   

string UpdateAdminPass()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"        Update Admin Password"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    string username, CurrentPass, NewPass, c_NewPass;
    string a_name, a_pass, blank;

    cout << "Enter Admin Username: ";
    getline(cin, username);

    cout << "Enter Current Password: ";
    getline(cin, CurrentPass);

    fstream file("Admin.txt", ios::in);
    if (!file.is_open())
    {
        return "Error Opening the File.";
    }

    fstream temp("temp.txt", ios::out);
    if (!temp.is_open())
    {
        file.close();
        return "Error: Temp file couldn't be opened.";
    }

    bool found = false, updated = false;

    while (true)
    {
        if (!getline(file, a_name)) break;
        if (!getline(file, a_pass)) break;
        getline(file, blank);

        if (a_name == username && a_pass == CurrentPass)
        {
            found = true;

            for (int i = 0; i < 10 && !updated; i++)
            {
                cout << "Enter New Password: ";
                getline(cin, NewPass);
                if(!IsStrongPassword(NewPass))
                {
                    system ("cls");
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout<<green<<"        Update Admin Password"<<reset<<endl;
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout<<red<< "Password is not strong enough. It must be 6-15 characters long and include uppercase, lowercase, digit, and special character. Try Again..." <<reset<<endl;
                    continue;
                }

                cout << "Confirm New Password: ";
                getline(cin, c_NewPass);

                if (NewPass != c_NewPass)
                {
                    system ("cls");
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout<<green<<"        Update Admin Password"<<reset<<endl;
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout<<red<< "Passwords do not match. Try again (" << 9 - i << " attempts left)" <<reset<<endl;
                    continue;
                }

                if (PasswordExists(NewPass))
                {
                    system ("cls");
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout<<green<<"        Update Admin Password"<<reset<<endl;
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout<<red<< "Password already in use. Try Again..." <<reset<<endl;
                    continue;
                }

                temp << a_name << "\n" << NewPass << "\n\n";
                updated = true;
                break;
            }

            if (!updated)
                temp << a_name << "\n" << a_pass << "\n\n";
        }
        else
        {
            temp << a_name << "\n" << a_pass << "\n\n";
        }
    }

    file.close();
    temp.close();

    remove("Admin.txt");
    rename("temp.txt", "Admin.txt");

    if (found && updated)
    {
        return "Password Updated Successfully.";
    }
    else if (found && !updated) 
    {
        return "Failed: Password not updated after attempts.";
    }
    else 
    {
        return "The user couldn't be found.";
    }
}

// Admin List Function

void AdminList()
{
    string a_name, a_pass, blank;
    system("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout <<green<< "       Admin List:\n"<<reset;
    cout <<cyan << setfill('-') << setw(30) << "" <<reset<< endl;

    fstream file("Admin.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Error opening Admin file." << endl;
        return;
    }

    while (true)
    {
        if (!getline(file, a_name)) break;
        if (!getline(file, a_pass)) break;
        getline(file, blank); // skip empty line

        cout << "Username: " << a_name << ", Password: " << a_pass << endl;
    }

    file.close();

    cout<<"\n" <<yellow<< "Enter any key to go back to the main menu: "<<reset<<endl;
    system("pause");
}

// Add Staff Function

string AddStaff()
{
    system("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"        Add New Staff"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    string name, pass, c_pass;
    fstream file("Staff.txt", ios::app);

    if (!file.is_open())
        return "Error.";

    for (int i = 0; i < 10; i++)
    {
        cout << "Enter new Staff's Name: ";
        getline(cin, name);

        cout << "Enter Staff's Password: ";
        getline(cin, pass);

        cout << "Confirm Password: ";
        getline(cin, c_pass);

        if (pass != c_pass)
        {
            system("cls");
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout<<green<<"        Add New Staff"<<reset<<endl;
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout <<red<< "Passwords do not match. Try Again..." <<reset<< endl<<endl;
            continue;
        }

        if(!IsStrongPassword(pass))
        {
            system("cls");
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout<<green<<"        Add New Staff"<<reset<<endl;
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout <<red<< "Password is not strong enough. It must be 6-15 characters long and include uppercase, lowercase, digit, and special character. Try Again..." <<reset<< endl<<endl;
            continue;
        }

        if (CheckStaff(name, pass))
        {
            system("cls");
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout<<green<<"        Add New Staff"<<reset<<endl;
            cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
            cout <<red<< "Staff with this name and password already exists. Try Again..." <<reset<< endl<<endl;
            continue;
        }

        else
        {
            file << name << "\n" << pass << "\n\n";
            file.close();
            return "Success";
        }
    }
    file.close();
    return "Failed";
}

// Remove Staff Function

string RemoveStaff()
{
    system("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"        Remove Staff"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    string d_name, s_name, s_pass, blank;

    cout << "Enter the Name of the staff to delete: ";
    getline(cin, d_name);

    fstream file("Staff.txt", ios::in);
    fstream temp("temp.txt", ios::out);

    if (!file.is_open())
    {
        return "Error! File could not be opened.";
    }

    if (!temp.is_open())
    {
        file.close();
        return "Error! Temp file could not be opened.";
    }

    bool found = false;

    while (true)
    {
        if (!getline(file, s_name)) break;
        if (!getline(file, s_pass)) break;
        getline(file, blank); // skip blank line

        if (s_name == d_name)
        {
            found = true;
            continue;
        }

        temp << s_name << "\n" << s_pass << "\n\n";
    }

    file.close();
    temp.close();

    remove("Staff.txt");
    rename("temp.txt", "Staff.txt");

    if (found)
    {
        cout<<"\n"<<green<< "Staff Removed Successfully." <<reset<<endl<<endl;
        system("pause");
        return "Staff Removed Successfully.";
    }
    else
    {
        cout<<"\n"<<red<< "The Given Staff name doesn't exist." <<reset<<endl<<endl;
        system("pause");
        return "The Given Staff name doesn't exist.";
    }

}

// Update Staff Password Function   

string UpdateStaffPass()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"    Update Staff Password"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;

    string username, CurrentPass, NewPass, c_NewPass;
    string s_name, s_pass, blank;

    cout << "Enter Staff Username: ";
    getline(cin, username);

    cout << "Enter Current Password: ";
    getline(cin, CurrentPass);

    fstream file("Staff.txt", ios::in);
    if (!file.is_open())
    {
        return "Error Opening the File.";
    }

    fstream temp("temp.txt", ios::out);
    if (!temp.is_open())
    {
        file.close();
        return "Error: Temp file couldn't be opened.";
    }

    bool found = false, updated = false;

    while (true)
    {
        if (!getline(file, s_name)) break;
        if (!getline(file, s_pass)) break;
        getline(file, blank);

        if (s_name == username && s_pass == CurrentPass)
        {
            found = true;

            for (int i = 0; i < 10 && !updated; i++)
            {
                cout << "Enter New Password: ";
                getline(cin, NewPass);

                cout << "Confirm New Password: ";
                getline(cin, c_NewPass);

                if (NewPass != c_NewPass)
                {
                    system ("cls");
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout<<green<<"    Update Staff Password"<<reset<<endl;
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout << "Passwords do not match. Try again (" << 9 - i << " attempts left)" << endl<<endl;
                    continue;
                }

                if(!IsStrongPassword(NewPass))
                {
                    system ("cls");
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout<<green<<"    Update Staff Password"<<reset<<endl;
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout << "Password is not strong enough. It must be 6-15 characters long and include uppercase, lowercase, digit, and special character. Try Again..." << endl<<endl;
                    continue;
                }

                if (CheckStaff(s_name, NewPass))
                {
                    system ("cls");
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout<<green<<"    Update Staff Password"<<reset<<endl;
                    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
                    cout << "Password already in use. Try Again..." << endl<<endl;
                    continue;
                }

                else
                {
                    temp << s_name << "\n" << NewPass << "\n\n";
                    updated = true;
                }
            }
            if (!updated)
                {
                    temp << s_name << "\n" << s_pass << "\n\n";
                }
        }
        else    
        {
            temp << s_name << "\n" << s_pass << "\n\n";
        }   
    }       
    file.close();
    temp.close();
    remove("Staff.txt");
    rename("temp.txt", "Staff.txt");
    if (found && updated)
    {
        cout<<"\n"<<green<<"Password Updated Successfully." <<reset<<endl<<endl;
        system("pause");
        return "Password Updated Successfully.";
    }
    else if (found && !updated) 
    {
        cout<<"\n"<<red<< "Failed: Password not updated after attempts." <<reset<<endl<<endl;
        system("pause");
        return "Failed: Password not updated after attempts.";
    }
    else 
    {
        cout<<"\n"<<red<< "The user couldn't be found." <<reset<<endl<<endl;
        system("pause");
        return "The user couldn't be found.";
    } 
}

// Staff List Function

string StaffList()
{
    system ("cls");
    string s_name, s_pass, blank;

    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"      Staff List:"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;

    fstream file("Staff.txt", ios::in);
    if (!file.is_open())
    {
        return "Error opening Staff file.";
    }

    while (true)
    {
        if (!getline(file, s_name)) break;
        if (!getline(file, s_pass)) break;
        getline(file, blank); // skip empty line

        cout << "Username: " << s_name << ", Password: " << s_pass << endl;
    }

    file.close();
    cout<<endl;
    system("pause");
    return "Success";
}

// View Rooms Status Function

void ViewRoomsStatus()
{
    system ("cls");
    fstream file("Rooms.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Error opening Rooms Status file." << endl;
        return;
    }

    cout<<cyan<<setfill('-')<<setw(40)<<""<<reset<<endl;
    cout<<green<<"      Rooms Status:"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(40)<<""<<reset<<endl;

    string RoomNum, Status, guest;

    while(getline(file, RoomNum,' '))
    {
        getline (file, Status,' ');

        if (Status == "Booked")
        {
            getline(file, guest);
        }     
        else
        {
            guest = "-";
            string skip;
            getline(file, skip);
        }   
    

        cout<<RoomNum<<"\t"<<Status<<"\t"<<guest<<endl;
    }
    file.close();
    cout<<endl;
    system("pause");
}

// Add Rooms function

string AddRooms()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"      Add New Room"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl<<endl;
    string roomNum, status, guest;

    fstream file("Rooms.txt", ios::app);
    if (!file.is_open())
    {
        return "Error opening Rooms file.";
    }

    cout << "Enter Room Number to add: ";
    getline(cin, roomNum);

    status = "Available";
    guest = "-";

    file << roomNum << " " << status << " " << guest << "\n";
    file.close();

    cout<<green<< "Room Added Successfully." <<reset<<endl<<endl;
    system("pause");
    return "Room Added Successfully.";
}
// Remove Rooms function

string RemoveRooms()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"      Remove Room"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl<<endl;

    string r_num, RoomNum, Status, guest;

    cout << "Enter Room Number to remove: ";
    getline(cin, r_num);

    fstream file("Rooms.txt", ios::in);
    if (!file.is_open())
    {
        return "Error opening Rooms file.";
    }

    fstream temp("temp.txt", ios::out);
    if (!temp.is_open())
    {
        file.close();
        return "Error opening temp file.";
    }

    bool found = false;

    while (true)
    {
        if (!getline(file, RoomNum,' ')) break;
        getline (file, Status,' ');

        if (Status == "Booked")
        {
            getline(file, guest);
        }     
        else
        {
            guest = "-";
            string skip;
            getline(file, skip);
        }   

        if (RoomNum == r_num)
        {
            found = true;
            continue;
        }

        temp << RoomNum << " " << Status << " " << guest << "\n";
    }

    file.close();
    temp.close();

    remove("Rooms.txt");
    rename("temp.txt", "Rooms.txt");

    if (found)
    {
        cout<<green<< "Room Removed Successfully." <<reset<<endl<<endl;
        system("pause");
        return "Room Removed Successfully.";
    }
    else
    {
        cout<<red<< "The Given Room number doesn't exist." <<reset<<endl<<endl;
        system("pause");
        return "The Given Room number doesn't exist.";
    }
}

// View All Bookings Function

void ViewAllBookings()
{
    fstream file("Bookings.txt", ios::in);
    if (!file.is_open())
    {
        cout << "Error opening Bookings file." << endl;
        return;
    }

    cout<<cyan<<setfill('-') << setw(30) << "" <<reset<< endl;
    cout<<green<<"      All Bookings\n"<<reset;
    cout<<cyan<<setfill('-') << setw(30) << "" <<reset<< endl;

    string bookingID, guestName, roomNum, checkIn, checkOut;

    while (true)
    {
        if (!getline(file, bookingID)) break;
        if (!getline(file, guestName)) break;
        if (!getline(file, roomNum)) break;
        if (!getline(file, checkIn)) break;
        if (!getline(file, checkOut)) break;
        string blank;
        getline(file, blank); 

        cout << "Booking ID: " << bookingID << ", Guest Name: " << guestName<< ", Room Number: " << roomNum << ", Check-In: " << checkIn<< ", Check-Out: " << checkOut << endl;
    }
    cout<<endl;
    system("pause");
    file.close();
}

// Name Exists Function

bool NameExists(string name) 
{
    fstream file("Admin.txt", ios::in);
    if (!file.is_open()) 
    {
        return false;
    }

    string line, existingName, pass;
    while (getline(file, existingName)) 
    {       
        if (!getline(file, pass)) break; 
        getline(file, line);

        if (existingName == name) 
        {
            return true; 
        }
    }
    file.close();
    return false;
}

// Password Exists Function

bool PasswordExists(string pass) 
{
    fstream file("Admin.txt", ios::in);
    if (!file.is_open()) 
    {
        return false;
    }

    string line, name, existingPass;
    while (getline(file, name)) 
    {       
        if (!getline(file, existingPass)) break; 
        getline(file, line);

        if (existingPass == pass) 
        {
            return true; 
        }
    }
    file.close();
    return false;
}

// Password Strength Function

bool IsStrongPassword(const string& password) 
{
    if (password.length() < 6 && password.length() > 15)
    {
        return false; 
    }

    bool hasUpper = false, hasLower = false, hasDigit = false, hasSpecial = false;

    for (char ch : password) 
    {
        if (isupper(ch)) 
        {
            hasUpper = true;
        }
        else if (islower(ch)) 
        {
            hasLower = true;
        }
        else if (isdigit(ch)) 
        {
            hasDigit = true;
        }
        else if (ispunct(ch)) 
        {
            hasSpecial = true;
        }
    }

    return hasUpper && hasLower && hasDigit && hasSpecial;
}

// Staff Login Page Function

int StaffLogin()
{
    cout<<setfill('-')<<setw(30)<<""<<endl;
    cout<<"Sign In"<<endl;
    cout<<setfill('-')<<setw(30)<<""<<endl;
    cout<<"1. Sign In"<<endl;
    cout<<"Choose your preference (1/2): ";
    string input;
    getline(cin, input);
    try
    {
        option = stoi(input);
    }
    catch(invalid_argument &e)
    {
        choice = 0;
    }
    return option;
}

// Staff Sign In Function

void StaffSignIn()
{
    system("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"Staff Sign In"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;

    cout<<"Enter username: ";
    getline(cin, username);

    cout<<"Enter password: ";
    getline(cin, password);
}

// Check Staff Function

bool CheckStaff(string StaffName, string StaffPass)
{
    fstream file("Staff.txt", ios::in);
    if (!file.is_open()) 
    {
        return false;
    }

    string s_name, s_pass, blank;

    while (true)
    {
        if (!getline(file, s_name)) break;
        if (!getline(file, s_pass)) break;
        getline(file, blank);

        if (s_name == StaffName && s_pass == StaffPass)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Staff Menu Function

int StaffMenu()
{
    system("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"      Staff Dashboard"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<"1. View Available Rooms"<<endl;
    cout<<"2. Check In Customers"<<endl;
    cout<<"3. Check Out Customers"<<endl;
    cout<<"4. View Bookings"<<endl;
    cout<<"5. Update Guest Booking"<<endl;
    cout<<"6. Cancel Booking"<<endl;
    cout<<"7. Generate Invoice"<<endl;
    cout<<"8. View Room Prices"<<endl;
    cout<<"9. Exit"<<endl;
   while (true)
   {
       cout<<yellow<<"\nEnter your choice: "<<reset;
       string option;
       getline(cin, option);

       try 
       {
           choice = stoi(option);
           break;
       }
       catch (...) 
       {
           cout << "Invalid input! Please enter a number only.\n";
       }
   }
    return choice;
}

// View Available Rooms Function

string ViewAvailableRooms()
{
    fstream file("Rooms.txt", ios::in);
    if (!file.is_open())
    {
        return "Error opening Rooms Status file.";
    }

    system ("cls");
    cout<<cyan<< setfill('-') << setw(40) << "" <<reset<< endl;
    cout<< green << "        Available Rooms:\n" << reset;
    cout<<cyan<< setfill('-') << setw(40) << "" <<reset<< endl;

    string RoomNum, Status, guest;

    while(getline(file, RoomNum,' '))
    {
        getline (file, Status,' ');

        if (Status == "Booked")
        {
            getline(file, guest);
        }     
        else
        {
            guest = "-";
            string skip;
            getline(file, skip);
        }   

        if (Status == "Available")
        {
            cout<<RoomNum<<"\t"<<Status<<"\t"<<guest<<endl;
        }
    }

    file.close();

    cout<<endl;
    system("pause");
    return "Success";
}

// Check In Function    
string CheckIn()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(40)<<""<<reset<<endl;
    cout<<green<<"        Check-In Customers"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(40)<<""<<reset<<endl;

    string guestName, roomNum, checkIn, checkOut;

    // 1. Get booking details
    cout << "Enter Guest Name: ";
    getline(cin, guestName);

    cout << "Enter Room Number: ";
    getline(cin, roomNum);

    cout << "Enter Check-In Date (DD/MM/YYYY): ";
    getline(cin, checkIn);

    cout << "Enter Check-Out Date (DD/MM/YYYY): ";
    getline(cin, checkOut);

    // 2. Check if room is available
    fstream roomsFile("Rooms.txt", ios::in);
    if (!roomsFile.is_open())
    {
        return "Error opening Rooms file.";
    }

    string line, rNum, status, guest;
    bool roomFound = false;
    string fileContent = "";

    while (getline(roomsFile, line))
    {
        // isstringstream seperates the room number, status and guest
        istringstream iss(line);
        iss >> rNum >> status >> guest;

        if (rNum == roomNum)
        {
            roomFound = true;
            if (status == "Available")
            {
                status = "Booked";
                guest = guestName;
            }
            else
            {
                roomsFile.close();
                return "Room is already booked!";
            }
        }

        fileContent += rNum + " " + status + " " + guest + "\n";
    }

    roomsFile.close();

    if (!roomFound)
        return "Room number not found!";

    // 3. Update Rooms.txt
    fstream roomsOut("Rooms.txt", ios::out);
    roomsOut << fileContent;
    roomsOut.close();

    // 4. Generate Booking ID (FIXED PART)
    fstream bookingsFile("Bookings.txt", ios::in);
    string lastID = "B0000";

    if (bookingsFile.is_open())
    {
        while (getline(bookingsFile, line))
        {
            // Check if line is a booking ID
            if (line.size() == 5 && line[0] == 'B' && isdigit(line[1]))
            {
                lastID = line;
            }
        }
        bookingsFile.close();
    }

    // Convert lastID to number and increment
    int num = stoi(lastID.substr(1)); // substr removes 'B' then remains 0001 or the only numerical part of the bookingID, which is converted into a number i.e 1
    num++;

    char newID[6];
    sprintf(newID, "B%04d", num); // we took a value from num, then specified the format to rewrite it as B0001, B0002, B0003 etc, (B%04d means B followed by a 4 digit number with leading zeros, 0 means that empty spaces before the number should be filled with zeros to make it 4 digits long), and %d is a placeholder for the integer value.
    string bookingID = newID;

    // 5. Append booking data
    fstream bookingsOut("Bookings.txt", ios::app);
    bookingsOut << bookingID << "\n"
                << guestName << "\n"
                << roomNum << "\n"
                << checkIn << "\n"
                << checkOut << "\n\n";
    bookingsOut.close();

    cout<<green<<"\nCheck-In Successful! Booking ID: "<<bookingID<<reset<<endl<<endl;
    system("pause");
    return "Check-In Successful! Booking ID: " + bookingID;
}

// Check-Out Function

string CheckOut()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(40)<<""<<reset<<endl;
    cout<<green<<"        Check-Out Customers"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(40)<<""<<reset<<endl;
    string roomNum;

    // 1. Ask staff for room number
    cout << "Enter Room Number to Check-Out: ";
    getline(cin, roomNum);

    // 2. Open Rooms.txt and read all lines
    fstream roomsFile("Rooms.txt", ios::in);
    if (!roomsFile.is_open())
    {
        return "Error opening Rooms file.";
    }

    string line, rNum, status, guest;
    bool roomFound = false, isBooked = false;
    string fileContent = "";

    while (getline(roomsFile, line))
    {
        // Each line: RoomNum Status Guest
        istringstream iss(line); //isstring stream used to seperate roomnumber, status and guest
        iss >> rNum >> status >> guest;

        if (rNum == roomNum)
        {
            roomFound = true;
            if (status == "Booked")
            {
                isBooked = true;
                status = "Available"; // mark room as available
                guest = "-";          // remove guest
            }
            else
            {
                roomsFile.close();
                return "Room is not currently booked!";
            }
        }

        fileContent += rNum + " " + status + " " + guest + "\n";
    }

    roomsFile.close();

    if (!roomFound)
        return "Room number not found!";

    // 3. Write updated Rooms.txt
    fstream roomsOut("Rooms.txt", ios::out);
    roomsOut << fileContent;
    roomsOut.close();

    cout<<green<<"\nCheck-Out Successful! Room "<<roomNum<<" is now available."<<reset<<endl<<endl;
    system("pause");
    return "Check-Out Successful! Room " + roomNum + " is now available.";
}

// View Guest Bookings Function

string ViewGuestBookings()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(50)<<""<<reset<<endl;
    cout<<green<<"        View Guest Bookings"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(50)<<""<<reset<<endl;

    string guestName;
    cout << "Enter Guest Name to search: ";
    getline(cin, guestName);

    fstream file("Bookings.txt", ios::in);
    if (!file.is_open())
    {
        return "Error opening Bookings file.";
    }

    bool found = false;
    string bookingID, roomNum, checkIn, checkOut, line;

    while (true)
    {
        if (!getline(file, bookingID)) break;
        string bName;
        if (!getline(file, bName)) break;
        if (!getline(file, roomNum)) break;
        if (!getline(file, checkIn)) break;
        if (!getline(file, checkOut)) break;
        getline(file, line); // blank line

        if (bName == guestName)
        {
            found = true;
            cout << "Booking ID: " << bookingID  << ", Room Number: " << roomNum  << ", Check-In: " << checkIn  << ", Check-Out: " << checkOut << endl;
        }
    }

    file.close();

    if (!found)
    {
        cout<<red<<"\nNo bookings found for guest: "<<guestName<<reset<<endl<<endl;
        system("pause");
        return "No bookings found for guest: " + guestName;
    }

    cout<<endl;
    system("pause");
    return "End of bookings for " + guestName;
}

// Update Guest Booking Function

string UpdateGuestBooking()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(50)<<""<<reset<<endl;
    cout<<green<<"        Update Guest Booking"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(50)<<""<<reset<<endl;

    const int MaxBookings = 100;

    string bookings[MaxBookings][5];
    string bookingID;
   
    fstream file("Bookings.txt", ios::in);
    if (!file.is_open())
    {
        return "Error opening Bookings file.";
    }

    string line;
    int bookingCount = 0;
    while(getline(file, line) && bookingCount < MaxBookings)
    {
        bookings[bookingCount][0] = line; // Booking ID
        getline(file, bookings[bookingCount][1]); // Guest Name
        getline(file, bookings[bookingCount][2]); // Room Number
        getline(file, bookings[bookingCount][3]); // Check-In Date
        getline(file, bookings[bookingCount][4]); // Check-Out Date
        getline(file, line); // blank line
        bookingCount++;
    }
    file.close();

    string newbookingID;
    cout << "Enter Booking ID to update: ";
    getline(cin, newbookingID);

    bool found = false;

    for (int i = 0; i < bookingCount; i++)
    {
        if(bookings[i][0] == newbookingID)
        {
            found = true;

            cout<<"\nCurrent Guest Name: "<<bookings[i][1]<<"\nEnter new Guest Name (or press Enter to keep current): ";
            string newGuestName;
            getline(cin, newGuestName);
            if(!newGuestName.empty())
            {
                bookings[i][1] = newGuestName;
            }

            cout<<"\nCurrent Room Number: "<<bookings[i][2]<<"\nEnter new Room Number (or press Enter to keep current): ";
            string newRoomNum;
            getline(cin, newRoomNum);
            if(!newRoomNum.empty())
            {
                bookings[i][2] = newRoomNum;
            }

            cout<<"\nCurrent Check-In Date: "<<bookings[i][3]<<"\nEnter new Check-In Date (or press Enter to keep current): ";
            string newCheckIn;
            getline(cin, newCheckIn);
            if(!newCheckIn.empty())
            {
                bookings[i][3] = newCheckIn;
            }

            cout<<"\nCurrent Check-Out Date: "<<bookings[i][4]<<"\nEnter new Check-Out Date (or press Enter to keep current): ";
            string newCheckOut;
            getline(cin, newCheckOut);
            if(!newCheckOut.empty())
            {
                bookings[i][4] = newCheckOut;
            }
            break;
        }
    }

    if (!found)
    {
        cout<<red<<"\nBooking ID "<<newbookingID<<" not found."<<reset<<endl<<endl;
        system("pause");
        return "Booking ID not found.";
    }

    fstream outFile("Bookings.txt", ios::out);
    for (int i = 0; i < bookingCount; i++)
    {
        outFile << bookings[i][0] << "\n"
                << bookings[i][1] << "\n"
                << bookings[i][2] << "\n"
                << bookings[i][3] << "\n"
                << bookings[i][4] << "\n\n";
    }

    outFile.close();

    cout<<green<<"\nBooking updated successfully."<<reset<<endl<<endl;
    system("pause");
    return "Booking updated successfully.";
}

// Cancel Booking Function

string CancelBooking()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(40)<<""<<reset<<endl;
    cout<<green<<"        Cancel Booking"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(40)<<""<<reset<<endl;

    const int MAX_BOOKINGS = 100;
    string bookings[MAX_BOOKINGS][5];
    int totalBookings = 0;

    // Read all bookings
    fstream file("Bookings.txt", ios::in);
    if (!file.is_open()) return "Error opening Bookings file.";

    string line;
    while (true)
    {
        if (totalBookings >= MAX_BOOKINGS) break;
        if (!getline(file, line)) break;

        bookings[totalBookings][0] = line; // Booking ID
        if (!getline(file, bookings[totalBookings][1])) break; // Guest Name
        if (!getline(file, bookings[totalBookings][2])) break; // Room Number
        if (!getline(file, bookings[totalBookings][3])) break; // Check-In
        if (!getline(file, bookings[totalBookings][4])) break; // Check-Out
        getline(file, line); // skip blank line

        totalBookings++;
    }
    file.close();

    // Ask which booking to cancel
    string bookingID;
    cout << "Enter Booking ID to cancel: ";
    getline(cin, bookingID);

    bool found = false;
    string canceledRoom = "";

    // Remove booking from memory
    for (int i = 0; i < totalBookings; i++)
    {
        if (bookings[i][0] == bookingID)
        {
            found = true;
            canceledRoom = bookings[i][2]; // save room number to free it later

            // Shift all following bookings up to remove this one
            for (int j = i; j < totalBookings - 1; j++)
            {
                for (int k = 0; k < 5; k++)
                {
                    bookings[j][k] = bookings[j + 1][k];
                }
            }
            totalBookings--; // reduce count
            break;
        }
    }

    if (!found)
    {
        cout<<red<<"\nBooking ID "<<bookingID<<" not found."<<reset<<endl<<endl;
        system("pause");
        return "Booking ID not found.";
    }
    // Update Bookings.txt
    fstream outFile("Bookings.txt", ios::out);
    for (int i = 0; i < totalBookings; i++)
    {
        outFile << bookings[i][0] << "\n" // Booking ID
                << bookings[i][1] << "\n" // Guest Name
                << bookings[i][2] << "\n" // Room Number
                << bookings[i][3] << "\n" // Check-In
                << bookings[i][4] << "\n\n"; // Check-Out
    }
    outFile.close();

    // Update Rooms.txt to free the canceled room
    fstream roomsFile("Rooms.txt", ios::in);
    if (!roomsFile.is_open()) return "Booking canceled, but error updating room status.";

    string roomNum, status, guest;
    string roomData = "";
    while (getline(roomsFile, roomNum, ' '))
    {
        getline(roomsFile, status, ' ');

        if (status == "Booked")
        {
            getline(roomsFile, guest);
        }
        else
        {
            guest = "-";
            string skip;
            getline(roomsFile, skip);
        }

        if (roomNum == canceledRoom)
        {
            status = "Available";
            guest = "-";
        }

        roomData += roomNum + " " + status + " " + guest + "\n";
    }
    roomsFile.close();

    fstream roomsOut("Rooms.txt", ios::out);
    roomsOut << roomData;
    roomsOut.close();

    cout<<green<<"\nBooking canceled successfully! Room "<<canceledRoom<<" is now available."<<reset<<endl<<endl;
    system("pause");
    return "Booking canceled successfully! Room " + canceledRoom + " is now available.";
}

// Generate Invoice Function

void GenerateInvoice()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(40)<<""<<reset<<endl;
    cout<<green<<"      Generate Invoice"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(40)<<""<<reset<<endl;

    string guestName, roomNum, checkIn, checkOut, bookingID;
    
    cout<<"Enter Booking ID: ";
    getline(cin, bookingID);

    cout << "Enter Guest Name: ";
    getline(cin, guestName);

    cout << "Enter Room Number: ";
    getline(cin, roomNum);

    cout << "Enter Check-In Date (DD/MM/YYYY): ";
    getline(cin, checkIn);

    cout << "Enter Check-Out Date (DD/MM/YYYY): ";
    getline(cin, checkOut);

    // Extract day, month, year from check-in
    int inDay = stoi(checkIn.substr(0, 2)); // Substr from index zero and has length 2
    int inMonth = stoi(checkIn.substr(3, 2)); // Same as above but starts from index 3
    int inYear = stoi(checkIn.substr(6, 4)); // Same as above but since length of year is yyyy so that y its 4

    // Extract day, month, year from check-out
    int outDay = stoi(checkOut.substr(0, 2)); 
    int outMonth = stoi(checkOut.substr(3, 2));
    int outYear = stoi(checkOut.substr(6, 4));

    // Display Invoice
    system ("cls");
    cout<<cyan<<"\n----- Invoice -----\n"<<reset;
    cout << "Booking ID: " << bookingID << endl;
    cout << "Guest: " << guestName << endl;
    cout << "Room Number: " << roomNum << endl;
    cout << "Check-In: " << inDay << "/" << inMonth << "/" << inYear << endl;
    cout << "Check-Out: " << outDay << "/" << outMonth << "/" << outYear << endl;

    // Calculate total days
    int totalDays = outDay - inDay + 1;
    cout << "Total Stay: " << totalDays << " day(s)" << endl;

    int ratePerDay = roomPrice; 
    cout << "Total Amount: Rs. " << totalDays * ratePerDay << endl;
    cout<<cyan<<"--------------------\n"<<reset;
    cout<<endl;
    system("pause");
}

// Update Room Prices Function

void UpdateRoomPrices()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"      Update Room Prices"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl<<endl;

    int newPrice;
    cout << "Enter new room price per day: Rs. ";
    cin >> newPrice;
    cin.ignore(); 

    roomPrice = newPrice;

    // Save to file by overwriting the previous price
    fstream file("RoomPrices.txt", ios::out);
    if (file.is_open()) 
    {
        file << roomPrice;
        file.close();
    }

    cout<<green<< "Room price updated to Rs. " << roomPrice << " per day." <<reset<< endl<<endl;
    system("pause");
}

// See Room Prices Function

void RoomPrices()
{
    system ("cls");
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl;
    cout<<green<<"      Room Prices"<<reset<<endl;
    cout<<cyan<<setfill('-')<<setw(30)<<""<<reset<<endl<<endl;

    cout << "Current room price per day: Rs. " << roomPrice <<" for all rooms." << endl<<endl;
    system("pause");
}

// Load Room Price Function

void LoadRoomPrice()
{
    fstream file("RoomPrices.txt", ios::in);  // open for reading
    if (file.is_open())
    {
        file >> roomPrice;   // read the saved price
        file.close();        // close the file
    }
    else
    {
        roomPrice = 1000;    // incase the file somehow doesn't exist
    }
}
