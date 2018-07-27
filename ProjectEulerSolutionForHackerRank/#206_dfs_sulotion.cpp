https://www.hackerrank.com/contests/projecteuler/challenges/euler206

//dfs clean solution for HackerRank Euler 206

#include <cmath>
#include <cstdio>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

#define LL __int128
//key very important to save 10 pow n and result checker
int forcheck[32] = {0};
const long ppow[19] = {1l,10l,100l,1000l,10000l,100000l,1000000l,(long)1e7,(long)1e8,(long)1e9,(long)1e10,(long)1e11,(long)1e12,(long)1e13,(long)1e14,(long)1e15,(long)1e16,(long)1e17,(long)1e18};
int getinput(const string &sm,int &n){
    int m = 2*n-2;
    while(sm[m] =='0') m-=2;
    int edge = n-(m+2)/2;    
    n = n-edge;
    for(LL i = 0; i<=m;i+=2 ) forcheck[m-i] = (sm[i]-'0');
    return edge;
}
//for check forward
inline bool checkwithindex(long a,int indx){
    LL tp = (LL)a*a;
    return ((tp/ppow[indx])%10) == forcheck[indx];
}
//for check result
inline bool checkres(long a,int indx,int len){
    LL tp = ((LL)a*a)/ppow[indx];
    while(indx<len){
        if((tp%10) != forcheck[indx]) return false;
        tp/=100;
        indx+=2;
    }
    return tp==0;
}
long est,eed,res;
//dfs
bool dfs(int nextcheck, long curv,int n){
    long base = ppow[nextcheck-1];
    if(nextcheck==(n-2)||nextcheck==(n-1)){
        for(long st = est; st <=eed; st+=base){
            long temp = st+curv;
            if(checkres(temp,nextcheck,n*2)){
                res = temp;
                return true;
            }
        }
    }else{
        for(long st = curv; st <50*base; st+=base){
            if(checkwithindex(st,nextcheck)){
                if(dfs(nextcheck+2,st,n)) return true;
                if(dfs(nextcheck+2,100*base-st,n)) return true;
            }
        }
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    ios::sync_with_stdio(false);
    string sm;
    getline(cin,sm);
    int n = stoi(sm);
    getline(cin,sm);
    for(int i =0;i < 32; i+=2) forcheck[i]= 0;
    int edg0 = getinput(sm,n);
    string tail;
    while(edg0--) tail+='0';
    int end = (sm[0]-'0')*10000;
    long ebase=ppow[n-3];
    est = ((long)sqrt(end/100))*ebase*10;   //make sure no confict with 
    eed = ((long)sqrt(end+10000))*ebase;    //maks sure visit enough
    res = 0;
    end = sm[2*n-2]-'0';
    if(end == 5){
        if(dfs(2, 5, n));
    }else if(end == 6){
        if(dfs(2, 4, n));
        else if(dfs(2, 6, n));
    }else{
        end = sqrt(end);
        if(dfs(2, end, n));
        else if(dfs(2, 10-end, n));
    } 
    cout<<res<<tail<<endl;
    return 0;
}
