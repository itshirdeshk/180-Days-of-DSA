#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    ifstream fin;
    fin.open("sort.txt");

    vector<int> arr;

    int c;
    
    while(fin>>c){
        arr.push_back(c);
    }

    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }

    fin.close();

    ofstream fout;
    fout.open("sort.txt");

    for(int i = 0; i < arr.size(); i++){
        fout<<arr[i]<<" ";
    }

    sort(arr.begin(), arr.end());

    fout<<endl;

    for(int i = 0; i < arr.size(); i++){
        fout<<arr[i]<<" ";
    }
    
    fout.close();
}