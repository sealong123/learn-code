#include <iostream>
#include <string>
using namespace std;
int length(char*s){
    int i;
    for(i = 0;s[i] != '\0';i++);
    return i;
}
int main (void){
    char p[100000],s[100000];
    cin.getline(s,100000);
    cin.getline(p,100000);
    int lengths = length(s);
    int lengthp = length(p);
    int f[lengthp];
    f[0] = -1;
    int i,j;
    for(j = 1;j < lengthp;j++){
        i = f[j-1];
        while(p[j] != p[i+1] && i > -1){
            i = f[i];
        }
        if(p[j] == p[i+1])f[j] = i + 1;
        else f[j] = -1;
    }
    for(i = 0;i < lengthp;i++){
        cout<<f[i]<<' ';
    }
    cout<<endl;
    for(i = 0,j = 0;i < lengthp && j < lengths;){
        if(p[i] == s[j]){
            i++;
            j++;
            continue;
        }
        else if(i == 0){
            j++;
            continue;
        }
        else{
            i = f[i-1] +1;
        }
    }
    if(i < lengthp)cout<<-1;
    else cout<<j-lengthp;
    return 0;
}
