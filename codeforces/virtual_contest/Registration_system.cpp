// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main(){
//     ll n;
//     cin>>n;
//     int count;
//     vector<string> initial;
//     while(n>0){
//         bool flag = false;
//         string c;
//         cin>>c;
//         for(int i=0; i<initial.size(); i++){
//             if(c==initial[i]){
//                 count++;
//                 cout<<c+char(count)<<"\n";
//                 flag = true;
//             }
//         }
//         if(flag) break;
//         initial.push_back(c); 
//         cout<<"OK\n";       
//         n--;
//     }
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, int> database;

    while (n--) {
        string name;
        cin >> name;

        if (database.find(name) == database.end()) {
            database[name] = 0;
            cout << "OK\n";
        } else {
            database[name]++;
            cout << name << database[name] << "\n";
        }
    }

    return 0;
}
INCLUDE Irvine32.inc
.data
    string BYTE " This is a string ",0 
    stringNOSpaces BYTE 50 DUP(?)
.code
main PROC
    mov esi,offset string
    mov edi,offset stringNospaces mov ecx,lengthof string-1
    cld

    start:
        lodsb  
        cmp al,' '
        je skipingspace 
        stosb
    skipingspace:
        loop start

;Storing null terminator:
    mov al,0
    stosb

    mov edx,offset stringNospaces 
    call writestring


exit 
main ENDP 
END main
