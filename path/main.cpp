#include <iostream>
#include <fstream>
#define border -2
using namespace std;
char **floor;
int **fdata;
int row=0,col=0,battery=0,halfB=0,dust=0;
int power=0,cha=0;
void ripple(int x1,int x2,int n);
void clearfloor(void);
void action(int y1,int y2,int m);
void actionback(int y1,int y2,int m);
void domore(int z1,int z2,int o);
ifstream fin;
ofstream fout("floor.txt");
int main()
{

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
    clearfloor();
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
    cout<<"clearfloor";

    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++){
                power=0;
            if(floor[i][j]=='0'){
                    action(i,j,fdata[i][j]);
                    power=halfB-fdata[i][j];
                    domore(i,j,fdata[i][j]);
                    cha=1;
                    actionback(i,j,fdata[i][j]);
            }
        }
    }
}

void actionback(int y1,int y2,int m){
    if(1){
        cout<<"action m:"<<m<<endl;
        bool f=0;
        floor[y1][y2]='c';
        if(cha==0)fout<<y1<<" "<<y2<<"back"<<endl;
        else cha=0;
        if(y1+1<row&&f==0){
            if(fdata[y1+1][y2]==m-1&&floor[y1+1][y2]!='c'){
                f=1;
                actionback(y1+1,y2,m-1);
            }
        }
        if(y1-1>0&&f==0){
            if(fdata[y1-1][y2]==m-1&&floor[y1-1][y2]!='c'){
                f=1;
                actionback(y1-1,y2,m-1);
            }
        }
        if(y2+1<col&&f==0){
            if(fdata[y1][y2+1]==m-1&&floor[y1][y2+1]!='c'){
                f=1;
                actionback(y1,y2+1,m-1);
            }
        }
        if(y2-1>0&&f==0){
            if(fdata[y1][y2-1]==m-1&&floor[y1][y2-1]!='c'){
                f=1;
                actionback(y1,y2-1,m-1);
            }
        }
        if(y1+1<row&&f==0){
            if(fdata[y1+1][y2]==m-1){
                f=1;
                actionback(y1+1,y2,m-1);
            }
        }
        if(y1-1>0&&f==0){
            if(fdata[y1-1][y2]==m-1){
                f=1;
                actionback(y1-1,y2,m-1);
            }
        }
        if(y2+1<col&&f==0){
            if(fdata[y1][y2+1]==m-1){
                f=1;
                actionback(y1,y2+1,m-1);
            }
        }
        if(y2-1>0&&f==0){
            if(fdata[y1][y2-1]==m-1){
                f=1;
                actionback(y1,y2-1,m-1);
            }
        }

    }
}

void action(int y1,int y2,int m){
    if(1){
        cout<<"action m:"<<m<<endl;
        bool f=0;
        floor[y1][y2]='c';

        if(y1+1<row&&f==0){
            if(fdata[y1+1][y2]==m-1&&floor[y1+1][y2]!='c'){
                f=1;
                action(y1+1,y2,m-1);
            }
        }
        if(y1-1>0&&f==0){
            if(fdata[y1-1][y2]==m-1&&floor[y1-1][y2]!='c'){
                f=1;
                action(y1-1,y2,m-1);
            }
        }
        if(y2+1<col&&f==0){
            if(fdata[y1][y2+1]==m-1&&floor[y1][y2+1]!='c'){
                f=1;
                action(y1,y2+1,m-1);
            }
        }
        if(y2-1>0&&f==0){
            if(fdata[y1][y2-1]==m-1&&floor[y1][y2-1]!='c'){
                f=1;
                action(y1,y2-1,m-1);
            }
        }
        if(y1+1<row&&f==0){
            if(fdata[y1+1][y2]==m-1){
                f=1;
                action(y1+1,y2,m-1);
            }
        }
        if(y1-1>0&&f==0){
            if(fdata[y1-1][y2]==m-1){
                f=1;
                action(y1-1,y2,m-1);
            }
        }
        if(y2+1<col&&f==0){
            if(fdata[y1][y2+1]==m-1){
                f=1;
                action(y1,y2+1,m-1);
            }
        }
        if(y2-1>0&&f==0){
            if(fdata[y1][y2-1]==m-1){
                f=1;
                action(y1,y2-1,m-1);
            }
        }
        fout<<y1<<" "<<y2<<"go"<<endl;

    }
}

void domore(int z1,int z2,int o){
    bool g=0;
    if(power>0){
            // o+1
        if(z1+1<row&&g==0){
            if(fdata[z1+1][z2]==o+1&&floor[z1+1][z2]!='c'){
                g=1;
                power--;
                floor[z1+1][z2]='c';
                fout<<z1+1<<" "<<z2<<"do more"<<endl;
                domore(z1+1,z2,o+1);
            }
        }
        if(z1-1>0&&g==0){
            if(fdata[z1-1][z2]==o+1&&floor[z1-1][z2]!='c'){
                g=1;
                power--;
                floor[z1-1][z2]='c';
                fout<<z1-1<<" "<<z2<<"do more"<<endl;
                domore(z1-1,z2,o+1);
            }
        }
        if(z2+1<row&&g==0){
            if(fdata[z1][z2+1]==o+1&&floor[z1][z2+1]!='c'){
                g=1;
                power--;
                floor[z1][z2+1]='c';
                fout<<z1<<" "<<z2+1<<"do more"<<endl;
                domore(z1,z2+1,o+1);
            }
        }
        if(z2-1>0&&g==0){
            if(fdata[z1][z2-1]==o+1&&floor[z1][z2-1]!='c'){
                g=1;
                power--;
                floor[z1][z2-1]='c';
                fout<<z1<<" "<<z2-1<<"do more"<<endl;
                domore(z1,z2-1,o+1);
            }
        }
        // o
        if(z1+1<row&&g==0){
            if(fdata[z1+1][z2]==o&&floor[z1+1][z2]!='c'){
                g=1;
                power--;
                floor[z1+1][z2]='c';
                fout<<z1+1<<" "<<z2<<"do more"<<endl;
                domore(z1+1,z2,o);
            }
        }
        if(z1-1>0&&g==0){
            if(fdata[z1-1][z2]==o&&floor[z1-1][z2]!='c'){
                g=1;
                power--;
                floor[z1-1][z2]='c';
                fout<<z1-1<<" "<<z2<<"do more"<<endl;
                domore(z1-1,z2,o);
            }
        }
        if(z2+1<row&&g==0){
            if(fdata[z1][z2+1]==o&&floor[z1][z2+1]!='c'){
                g=1;
                power--;
                floor[z1][z2+1]='c';
                fout<<z1<<" "<<z2+1<<"do more"<<endl;
                domore(z1,z2+1,o);
            }
        }
        if(z2-1>0&&g==0){
            if(fdata[z1][z2-1]==o&&floor[z1][z2-1]!='c'){
                g=1;
                power--;
                floor[z1][z2-1]='c';
                fout<<z1<<" "<<z2-1<<"do more"<<endl;
                domore(z1,z2-1,o);
            }
        }
        // o-1
        if(z1+1<row&&g==0){
            if(fdata[z1+1][z2]==o-1&&floor[z1+1][z2]!='c'){
                g=1;
                power--;
                floor[z1+1][z2]='c';
                fout<<z1+1<<" "<<z2<<"do more"<<endl;
                domore(z1+1,z2,o-1);
            }
        }
        if(z1-1>0&&g==0){
            if(fdata[z1-1][z2]==o-1&&floor[z1-1][z2]!='c'){
                g=1;
                power--;
                floor[z1-1][z2]='c';
                fout<<z1-1<<" "<<z2<<"do more"<<endl;
                domore(z1-1,z2,o-1);
            }
        }
        if(z2+1<row&&g==0){
            if(fdata[z1][z2+1]==o-1&&floor[z1][z2+1]!='c'){
                g=1;
                power--;
                floor[z1][z2+1]='c';
                fout<<z1<<" "<<z2+1<<"do more"<<endl;
                domore(z1,z2+1,o-1);
            }
        }
        if(z2-1>0&&g==0){
            if(fdata[z1][z2-1]==o-1&&floor[z1][z2-1]!='c'){
                g=1;
                power--;
                floor[z1][z2-1]='c';
                fout<<z1<<" "<<z2-1<<"do more"<<endl;
                domore(z1,z2-1,o-1);
            }
        }
        if(g==1)fout<<z1<<" "<<z2<<"do more back"<<endl;
    }
}
