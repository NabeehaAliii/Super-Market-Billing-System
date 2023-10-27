#include <iostream>
#include <fstream>
using namespace std;

class shopping
{
private:
    int pcode;
    float price;
    float dis;
    string p_name;

public:
    // Declare Functions
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void receipt();
};

void shopping ::menu()
{
m: // goto label after switch
    int choice;
    string email, password;

    // Display
    cout << "\t\t\t\t__________________________\n";
    cout << "\t\t\t\t                           \n";
    cout << "\t\t\t\t    SUPER MARKET MENU      \n";
    cout << "\t\t\t\t                           \n";
    cout << "\t\t\t\t___________________________\n";

    cout << "\t\t\t 1)  Administrator" << endl;
    cout << "\t\t\t\t                           \n";
    cout << "\t\t\t 2)  Buyer" << endl;
    cout << "\t\t\t\t                           \n";
    cout << "\t\t\t 3)  Exit" << endl;
    cout << "Please Select" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please Login" << endl;
        cout << "\t\t\t\t                           \n";
        cout << "\t\t\t\t                           \n";
        cout << "\t\t\t Enter Email" << endl;
        cin >> email;
        cout << "\t\t\t\t                           \n";
        cout << "\t\t\t\t                           \n";
        cout << "\t\t\t Enter Password" << endl;
        cin >> password;

        if (email == "alinabeeha44@gmail.com" && password == "123456")
        {
            administrator();
        }
        else
        {
            cout << "Invalid Email/Password" << endl;
        }

        break;
    case 2:
    {
        buyer();
        break;
    }
    case 3:
    {
        exit(0);
        break;
    }

    default:
    {
        cout << "Please Select from the given options." << endl;
        break;
    }
    }
    goto m;
}

void shopping::administrator()
{
m: // goto label
    int choice;
    cout << "\t\t\t Administrator Menu " << endl;
    cout << "\t\t\t\t_____1) Add the Product______ \n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t_____2) Modify the Product_____\n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t_____3) Delete the Product______\n";
    cout << "\t\t\t\t                              \n";
    cout << "\t\t\t\t_____3) Back to Main Menu______\n";

    cout << "Please Enter your choice" << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        add();
        break;
    case 2:
        edit();
        break;
    case 3:
        rem();
        break;
    case 4:
        menu();
        break;
    default:
        cout << "Invalid Choice" << endl;
        break;
    }
    goto m;
}

void shopping::buyer()
{
m:
    int choice;
    cout << "\t\t\t  Buyer " << endl;
    cout << "\t\t\t\t                    \n";
    cout << "\t\t\t 1) Buy Product " << endl;
    cout << "\t\t\t\t                    \n";
    cout << "\t\t\t 2) Go Back " << endl;

    cout << "Enter your choice" << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        receipt();
        break;
    case 2:
        menu();
        break;

    default:
        cout << "Invalid Choice";
        break;
    }
    goto m; // Jump Statement
}

void shopping ::add()
{
m:
    fstream data;
    int c, token = 0;
    float p, d; // c: product_code , p: product name , d: discount , n: name
    string n;

    cout << "\n\n\t\t\tAdd New Product";
    cout << "\n\n\t\t\tProduct code of the Product";
    cin >> pcode;
    cout << "\n\n\t\t\tName of the Product";
    cin >> p_name;
    cout << "\n\n\t\t\tPrice of the Product";
    cin >> price;
    cout << "\n\n\t\t\tDiscount on the Product";
    cin >> dis;

    data.open("database.txt", ios::in);
    if (!data) // If the file doesn't exist
    {
        data.open("database.txt", ios::app | ios::out);
        {
            data << pcode << "  " << p_name << "  " << price << "  " << dis << endl;
            data.close();
        }
    }
    else
    {
        data >> c >> n >> p >> d; // Initializing the index of file

        while (!data.eof())
        { // eof() >> End of file Function
            if (c == pcode)
            {
                token++;
            }
            data >> c >> n >> p >> d; // Initializing the index of file
        }
        data.close();
        // Check flag: token is initially 0 if it is incremented then it means there are two procducts with the same code.
        if (token == 1)
            goto m;
        else
        {
            data.open("database.txt", ios::app | ios::out);
            {
                data << pcode << "  " << p_name << "  " << price << "  " << dis << endl;
                data.close();
            }
        }
    }
    cout << "\n\n\t\t\tRecord Inserted" << endl;
}

void shopping ::edit()
{

    fstream data, data1;
    int pkey, token = 0, c;
    float p, d;
    string n;

    cout << "\n\n\t\t\t Modify the Record" << endl;
    cout << "\n\n\t\t\t Product Code" << endl;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n File Does not exist" << endl;
    }
    else
    {
        data.open("database1.txt", ios::app | ios::out);

        data >> pcode >> p_name >> price >> dis;
        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\n\n Product New Code : " << endl;
                cin >> c;
                cout << "\n\n Name of the Product : " << endl;
                cin >> n;
                cout << "\n\n Price of the Product : " << endl;
                cin >> p;
                cout << "\n\n Discount on the Product : " << endl;
                cin >> d;

                data1 << "  " << c << "  " << n << "  " << p << "  " << d << endl; // Write all data in data1
                cout << "\n\n\t\t\t Record Edited" << endl;
            }
            else
            {
                data1 << "  " << pcode << "  " << p_name << "  " << price << "  " << dis << endl;
            }
            data >> pcode >> p_name >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n\t Sorry, Record Not Found" << endl;
        }
    }
}

void shopping ::rem()
{
    fstream data, data1;
    int pkey, token = 0;
    cout << "\n\n\t Delete Product";
    cout << "\n\n\t Product Code";
    cin >> pkey;

    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "File Does not Exist";
    }

    else
    {
        data1.open("database.txt", ios ::app | ios ::out);
        data >> pcode >> p_name >> price >> dis;

        while (data.eof())
        {
            if (pcode == pkey)
            {
                cout << "\n\n\t Product Deleted Succesfully" << endl;
                token++;
            }
            else
            {
                data1 << "  " << pcode << "  " << p_name << "  " << price << "  " << dis << endl;
            }
            data >> pcode >> p_name >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n\t Sorry, Record Not Found" << endl;
        }
    }
}

void shopping ::list()
{
    fstream data;
    data.open("database.txt", ios::in); // Read Mode
    cout << "\t\t\t___________________________________" << endl;
    cout << "\tProduct No. \t\t  Name  \t\t Price" << endl;
    cout << "\t\t\t___________________________________" << endl;
    data >> pcode >> p_name >> price >> dis;

    while (!data.eof())
    {
        cout << "\t" << pcode << " \t\t " << p_name << " \t\t " << price << endl;
        data >> pcode >> p_name >> price >> dis;
    }
    data.close();
}

void shopping ::receipt()
{
    fstream data;
    int c;
    int arrc[100]; // Array of codes
    int arrq[100]; // Array of quantity
    char choice;
    float amount, dis = 0, total = 0;

    cout << "\n\n\t\t\t Receipt" << endl;
    data.open("databse.txt", ios::in);
    if (!data)
    {
        cout << "\n\n Empty Data Base" << endl;
    }
    else
    {
        data.close();

        list();
        cout << "\n__________________________" << endl;
        cout << "\n                          " << endl;
        cout << "\n  Plaese Place the Order  " << endl;
        cout << "\n                          " << endl;
        cout << "\n__________________________" << endl;

        do
        {
            cout << "\n\nEnter Product Code: " << endl;
            cin >> arrc[c];
            cout << "\n\nEnter Product Quantity: " << endl;
            cin >> arrq[c];

            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i])
                {
                    cout << "\n Duplicate Product Code. Please Try Again!" << endl;
                    // goto m;
                }
            }
            c++;
            cout << "Do you want to buy another product? if yes then press y else n" << endl;
            cin >> choice;
        } while (choice == 'y');

        cout << "\n\n\t\t\t _______________RECEIPT_______________" << endl;
        cout << "                                                " << endl;
        cout << "\tProduct No. \t  Name  \t Price \t Amount \t Amount with discount" << endl;
        cout << "                                                " << endl;
        cout << "\t\t\t__________________________________________" << endl;

        for (int i = 0; i < c; i++)
        {
            data.open("database.txt", ios::in);
            data >> pcode >> p_name >> price >> dis;

            while (!data.eof())
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total = total + dis;
                    cout << "\n"
                         << pcode << "\t\t" << p_name << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> p_name >> price >> dis;
            }
        }
        data.close();
    }
    cout << "\n\t\t _______________________________" << endl;
    cout << "Total Amount: " << total;
}

int main()
{
    shopping s;
    s.menu();
}