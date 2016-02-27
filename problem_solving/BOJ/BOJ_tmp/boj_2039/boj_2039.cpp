#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int l, n;
vector<char> charVector;
char c;

void printPassword(string& password){
    int size = password.size();
    int i,cnt=0;;
    for(i=0;i<size;i++){
        if(password[i] == 'a' ||
           password[i] == 'e' ||
           password[i] == 'i' ||
           password[i] == 'o' ||
           password[i] == 'u')
            ++cnt;
    }
    if(cnt<1 || size-cnt<2) return;
    printf("%s\n",password.c_str());
}

void make(string& password, int smallest){
    if(password.size()==l){printPassword(password);return;}

    for(int next = smallest;next<n;next++){
        password.push_back(charVector[next]);
        make(password,next+1);
        password.pop_back();
    }
}

int main(){
    scanf("%d%d",&l,&n);
    for(int i=0;i<n;i++){
       scanf(" %c",&c);
       charVector.push_back(c);
    }
    sort(charVector.begin(),charVector.end());
    string password;
    make(password,0);
    return 0;
}
