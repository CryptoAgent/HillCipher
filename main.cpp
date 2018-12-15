#include <iostream>
#include <string>
using namespace std;
#include "H.h"

int M[2][2]={15,4,11,3};
int iM[2][2]{3,-4,-11,15};

int main(){
cout<<"Please enter message\r\n>";
string mess = GetStr();
int mlen = GetLen(mess);
if(mlen%2!=0){
    mess+='z';
    mlen++;
}
string encr;
for(int i = 0;i<mlen;i+=2){
    char ch1 = mess[i];
    char ch2 = mess[i+1];
    ch1-=97;
    ch2-=97;
    int res1 = M[0][0]*ch1+M[0][1]*ch2;
    int res2 = M[1][0]*ch1+M[1][1]*ch2;
    res1%=26;
    res2%=26;
    encr+=res1+97;
    encr+=res2+97;
}
cout<<encr<<endl;
//decryption
string decr;
for(int i = 0;i<mlen;i+=2){
    char ch1 = encr[i];
    char ch2 = encr[i+1];
    ch1-=97;
    ch2-=97;
    int res1 = iM[0][0]*ch1+iM[0][1]*ch2;
    int res2 = iM[1][0]*ch1+iM[1][1]*ch2;
    while(res1<0){
        res1+=26;
    }
    while(res2<0){
        res2+=26;
    }
    res1%=26;
    res2%=26;
    decr+=res1+97;
    decr+=res2+97;
}
cout<<decr;
return 0;
}
