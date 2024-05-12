#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct OrderCheck
{
    string surname;
    int cost;
    int period ;
    int number = 0;
};

bool load_file(int n, OrderCheck* p, const string& file_name)
{
    fstream file;
    file.open(file_name, ios_base::in);

    if (file.is_open())
        for (int i = 0; i < n; ++i)
            file >> p[i].surname >> p[i].number >> p[i].cost >> p[i].period;
    else
    {
        cout << "file " << file_name << " isn't found" << endl;
        return false;
    }

    file.close();
    return true;
}

void output_info(int n, OrderCheck* p)
{
    cout << " " << endl;

    for (int i = 0; i < n; ++i)
        cout << i + 1 << ") " << p[i].surname << ' ' << p[i].number << ' ' << p[i].cost << ' ' << p[i].period << endl;

    cout << endl;
}

bool edit_info(int n, OrderCheck* p)
{
    float x;
    cout<<"Do you want to change anything"<<endl;
    cout<<"0 - no"<<endl;
    cout<<"1 - yes"<<endl;
    scanf("%f",&x);
    while (x!=0){
        if (x == 1){
            int i = 0;
            cout << "What do you want to change (1 - " << n << "): ";
            cin >> i;

            if (1 <= i and i <= n)
            {
                cout << "Surname: ";
                cin >> p[i].surname;
                cout << "Contract number: ";
                cin >> p[i].number;
                cout << "Order price: ";
                cin >> p[i].cost;
                cout << "Period of execution: ";
                cin >> p[i].period;
                cout << endl;
                return true;
            }
            else
            {
                cout << "No changes" << endl << endl;
                return false;
            }
        }
    }
    if (x==0) {
        cout << "No changes" << endl << endl;
        return false;
    }
}

void Order (int n, OrderCheck* p)
{

    int countt = int(p[0].cost);
    for (int i = 1; i < n; ++i)
        countt += int(p[i].cost);

    cout << "The result of multiplying: " << countt << endl;
    cout << "And the average price is:  " << countt/n << endl;
}

void save_file(int n, OrderCheck* p)
{
    fstream file;
    string file_name;

    cout << "file with name changes saved - ";
    cin >> file_name;

    file.open(file_name, ios_base::out);

    for (int i = 0; i < n; ++i)
        file << p[i].surname << ' ' << p[i].number << ' ' << p[i].cost << ' ' << p[i].period << endl;

    cout << "file " << file_name << " saving success" << endl << endl;
    file.close();
}

int main()
{

    const int n = 3;

    OrderCheck* info_list = new OrderCheck[n];
    const string file_name = "f1.txt";

    if (load_file(n, info_list, file_name))
    {
        output_info(n, info_list);

        if (edit_info(n, info_list))
        {
            Order(n, info_list);
            save_file(n, info_list);
        }
        else
            Order(n, info_list);
    }

    delete[] info_list;

    return 0;
}

