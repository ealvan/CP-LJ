#include <bits/stdc++.h>
using namespace std;
 
int n; 
int t;
int ct=0;
string s;

void generar(int x){
	if(x == n){
		// terminamos de definir un subconjunot -> imprimirlo
		if(ct == t) cout << s << endl; 
		return; 
	}
	for(int i = 0; i < 2; i++){
		char c = i + '0';
        ct+=i;
		s.push_back(c);
 
		generar(x+1);
        ct-=i;
		s.pop_back();  
	}
}

int main() {

    cin >> n >> t;
    generar(0); 
 
	return 0;
}