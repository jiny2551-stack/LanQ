#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int f[5][5]={
{0,0,1,1,0},
{1,0,0,1,0},
{0,1,0,0,1},
{0,0,1,0,1},
{1,1,0,0,0},
};
int n,na,nb;
int a[205];
int b[205];
int main()
{
    cin>>n>>na>>nb;
    for(int i=0;i<na;i++){
        cin>>a[i];
    }
    for(int i=0;i<nb;i++){
        cin>>b[i];
    }
    int sa=0,sb=0;
    for(int i=0;i<n;i++){
        if(f[a[i%na]][b[i%nb]]==1){
            sa++;
        }
        if(f[b[i%nb]][a[i%na]]==1){
            sb++;
        }
    }
    cout <<sa<<" "<<sb;
    return 0;
}