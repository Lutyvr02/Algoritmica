#include "bits/stdc++.h"
using namespace std;
long long dp[20][180][2];
long long getdigito(long long x, vector <int> &digito){
    while (x){
        digito.push_back(x%10);
        x /= 10;
    }
}

long long digitSuma(int indexado, int suma, int peso, vector <int> &digito){
    if (indexado == -1)
       return suma;
    if (dp[indexado][suma][peso] != -1 and peso != 1)
        return dp[indexado][suma][peso];
 
    long long ret = 0;
    int k = (peso)? digito[indexado] : 9;
 
    for (int i = 0; i <= k ; i++){
        int newpeso = (digito[indexado] == i)? peso : 0;
        ret += digitSuma(indexado-1, suma+i, newpeso, digito);
    }
 
    if (!peso)
      dp[indexado][suma][peso] = ret;
 
    return ret;
}
int sumarango(int a, int b){
    memset(dp, -1, sizeof(dp));
    vector<int> digito2;
    getdigito(a-1, digito2);
    long long respu1 = digitSuma(digito2.size()-1, 0, 1, digito2);
    vector<int> digitB;
    getdigito(b, digitB);
    long long respu2 = digitSuma(digitB.size()-1, 0, 1, digitB);
    return (respu2 - respu1);
}
 
int main(){
    long long a = 123, b = 1024;
    cout << "La suma para el rango:  : "
         << sumarango(a, b) << endl;
    return 0;
}
