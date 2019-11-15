#include <iostream>
#include <fstream>
#define border -2
using namespace std;
char **floor;
int **fdata;
int row=0,col=0,battery=0,halfB=0,dust=0;
void ripple(int x1,int x2,int n);
void clearfloor(void);
int main()
{
    ifstream fin;
    ofstream fout("floor.txt");
    fin.open("floor.data");

    int s1=0,s2=0;

    //initialize
    if(fin.is_open()){
      fin>>row>>col>>battery;
      halfB=battery/2;
      dust=halfB+1;
      floor = new char* [row];
      fdata = new int* [row];
      for(int i=0; i<row; i++) {
          floor[i]=new char[col];
          fdata[i]=new int[col];
      }
      //read map

        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++){
                fin>>floor[i][j];
                if(floor[i][j]=='1'){fdata[i][j]=border;}
                if(floor[i][j]=='0'){fdata[i][j]=dust;}
                if(floor[i][j]=='R'){s1=i;s2=j;fdata[i][j]=0;}
            }
        }

      fin.close();
    }
    //start

    cout << "look map" << endl;
    ripple(s1,s2,0);
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++){
            fout<<floor[i][j];
        }fout<<endl;
    }
    cout<<s1<<s2<<endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++){
            cout<<fdata[i][j];
        }cout<<endl;
    }
    for(int i=0; i<row; i++) {
        delete [] floor[i];
        delete [] fdata[i];
    }
    fout.close();
    delete [] floor;
    delete [] fdata;
    return 0;
}

void ripple(int x1,int x2,int n){
    if(fdata[x1][x2]!=border&&fdata[x1][x2]>=n&&n<halfB+1){
        fdata[x1][x2]=n;
        //cout<<"ripple"<<n<<endl;
        if(x1+1<row){ripple(x1+1,x2,n+1);}
        if(x1-1>0){ripple(x1-1,x2,n+1);}
        if(x2+1<col){ripple(x1,x2+1,n+1);}
        if(x2-1>0){ripple(x1,x2-1,n+1);}
    }
}

void clearfloor(void){

}
