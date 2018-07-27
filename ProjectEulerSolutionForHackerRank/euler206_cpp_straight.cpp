https://www.hackerrank.com/contests/projecteuler/challenges/euler206/problem
// accept sulotion straight forward with array 

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
//key very important
const long ppow[19] = {1l,10l,100l,1000l,10000l,100000l,1000000l,10000000l,(long)1e8,(long)1e9,(long)1e10,(long)1e11,(long)1e12,(long)1e13,(long)1e14,(long)1e15,(long)1e16,(long)1e17,(long)1e18};
string llto_string(const LL &a){
    string res;
    LL i= 1;
    while(i<=a){
        res+=(char)(((a/i)%10)+'0');
        i*=10;
    }
    reverse(res.begin(),res.end());
    return res;
}

LL llsqrt(LL a,int cnt){
    LL l = a/ppow[cnt];
    LL r = a/ppow[cnt-1];
    while(l<r){
        LL m = (l+r)/2;
        if(a>m*m) l = m+1;
        else r=m;
    }
    return l;
}
//key very important
int forcheck[32] = {0};
int getinput(const string &sm,int &n){
    int m = 2*n-2;
    while(sm[m] =='0') m-=2;
    int edge = n-(m+2)/2;    
    n = n-edge;
    for(LL i = 0; i<=m;i+=2 ) forcheck[m-i] = (sm[i]-'0');
    return edge;
}
#define MAX_ARR 5000000
//quit important
inline bool checkwithindex(const LL &a,int indx){
    return ((a/ppow[indx])%10) == forcheck[indx];
}
inline bool checkwithindex17(const LL &a,int indx){
    indx-=17;
    return (((a/ppow[17])/ppow[indx])%10) == forcheck[indx+17];
}
//quit important
bool checkwithmask(LL a,int mask,int n){
    a/=ppow[mask];
    while(mask<n){
        if(a%10 != forcheck[mask]) return false;
        a/=100;
        mask+=2;
    }
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    std::ios::sync_with_stdio(false);
    string sm;
    getline(cin,sm);
    int n = stoi(sm);
    getline(cin,sm);
    for(int i =0;i < 32; i+=2) forcheck[i]= 0;
    int edg0 = getinput(sm,n);
    string tail;
    while(edg0--) tail+='0';
    long *arr = new long [MAX_ARR];
    int stii = 0,endii = 0;
    int end = sm[2*n-2]-'0';
    if(end == 5){
        arr[endii++] = 5;
    }else if(end == 6){
        arr[endii++] = 4;
        arr[endii++] = 6;
    }else if(end == 9){
        arr[endii++] = 3;
        arr[endii++] = 7;
    }else if(end == 4){
        arr[endii++] = 2;
        arr[endii++] = 8;
    }else{
        arr[endii++] = 1;
        arr[endii++] = 9;
    }
    end = sm[0]-'0';
    long ebase=ppow[n-1],est=0,eed=9;
    int mask = 0;
    int i = 2;
    unsigned long base = 10;
    if(n%2){
        mask = n-1;
        if(end <=3){
            if(end ==1) eed= 4;
            else if(end==2) {
                eed = 7;
                est = 4;
            }else{
                est = 7;
            }
        }else if(end <9){
            ebase *= 2;
            if(end ==4) eed= 2;
            else if(end==5) {
                eed = 4;
                est = 2;
            }else if(end==6) {
                eed = 6;
                est = 4;
            }else if(end==7) {
                eed = 8;
                est = 6;
            }else{
                est = 8;
            }
        }else{
            ebase *= 3;
            eed = 1;
        }
        while(i < n-1){
            int cnt = endii;
            for(LL j = 0; j < 50l*base; j+=base){
                for(int k = stii; k < cnt; k++){
                    LL temp2 = j + arr[k];
                    //quit important
                    if(checkwithindex(temp2*temp2,i)){
                        arr[endii++]=temp2;
                        arr[endii++]=base*100-temp2;
                    }
                }
            }
            stii = cnt;
            i+=2;
            base *= 100l;
        }
        base = ppow[n-2];
        long j = ebase+est*base;
        eed -= est;
        while(eed-->=0){
            for(int k = stii; k < endii; k++){
                LL temp = j + arr[k];
                if(checkwithmask(temp*temp,mask,n*2)){
                    cout<<llto_string(temp)<<tail<<endl;
                    delete []arr;
                    return 0;
                }
            }
            j += base;
        }
    }else{
        mask = n;
        ebase *= (long)sqrt(end);
        est = (long)sqrt(end*10000)%100;
        eed = (long)sqrt(end*10000+10000-1)%100;
        while(i < n-1){
            int cnt = endii;
            if(i < n-2){
                for(LL j = 0; j < 50l*base; j+=base){
                    for(int k = stii; k < cnt; k++){
                        LL temp2 = j + arr[k];
                        if(checkwithindex(temp2*temp2,i)){
                            arr[endii++]=temp2;
                            arr[endii++]=base*100-temp2;
                        }
                    }
                }
            }else{
                for(LL j = est*base; j <= eed*base; j+=base){
                    for(int k = stii; k < cnt; k++){
                        LL temp2 = j + arr[k];
                        if(checkwithindex(temp2*temp2,i)) arr[endii++]=temp2;
                    }
                }
            }
            stii = cnt;
            i+=2;
            base *= 100l;
        }
        for(int j = stii; j < endii;j++){
            LL temp = arr[j]+ebase;
            if(checkwithmask(temp*temp,mask,n*2)){
                cout<<llto_string(temp)<<tail<<endl;
                break;
            }
        }
    }
    
    delete []arr;
    return 0;
}
