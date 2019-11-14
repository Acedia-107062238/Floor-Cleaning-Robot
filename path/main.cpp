#include <iostream>

using namespace std;

int main()
{
    int row=0,col=0,battery=0;
    int s1=0,s2=0;
    //initialize
    cin>>row>>col>>battery;
    char **floor;
    floor = new char* [row];
    for(int i=0; i<row; i++) {
        floor[i]=new char[col];
    }
    //read map
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++){
            cin>>floor[i][j];
            if(floor[i][j]=='R'){s1=i;s2=j;}
        }
    }
    //start

    cout << "look map" << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++){
            cout<<floor[i][j];
        }cout<<endl;
    }
    cout<<s1<<s2;
    for(int i=0; i<row; i++) {
        delete [] floor[i];
    }
    delete [] floor;
    return 0;
}
