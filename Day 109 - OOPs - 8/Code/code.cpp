#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Opening the file
    ofstream fout;

    // If file is not found then it will create a new file with the same name and will open it after creating the file.
    fout.open("zoom.txt");

    // Writing into the file
    fout<<"Hello India"<<endl;

    fout.close();

    // Reading the file
    ifstream fin;
    fin.open("zoom.txt");

    char c;
    // fin>>c;
    c = fin.get();

    while (!fin.eof())
    {
        cout << c;
        // fin>>c;
        c = fin.get();
    }
    fin.close();

    // Another Example - 1

    vector<int> arr(5);
    cout << "Enter the input: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    // Opening or creating a file
    ofstream fout;
    fout.open("zero.txt");

    fout << "Original Data: " << endl;

    for (int i = 0; i < 5; i++)
    {
        fout << arr[i] << " ";
    }

    fout << "\nSorted Data: \n";

    sort(arr.begin(), arr.end());

    for (int i = 0; i < 5; i++)
    {
        fout << arr[i] << " ";
    }

    fout.close();

    // Another Example - 2

    ofstream fout;
    fout.open("z1.txt");
    fout<<"Hello Hirdesh\n";
    fout<<"Hello India\n";
    fout<<"Hello World\n";

    fout.close();

    ifstream fin;
    fin.open("z1.txt");

    string line;

    while(getline(fin, line)){
        cout<<line<<endl;
    }

    fin.close();

}