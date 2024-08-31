#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

int main() { _
	int n,k; cin>>n>>k;
    string s; cin>>s;
	unsigned long int l = 0, r = -1;
	int a = 0;
	unsigned long int m = 0; 
    int b = 0;
    int p = 0;
	while(true) {
		if(a <= k && m < r-l+1) m = r-l+1;
		if(a <= k && r+1 < s.size()){
			if(s[r+1] == 'a') a++;
			r++;	
		}
		else if(k < a){
			if(s[l] == 'a') a--;
			l++; 
		}
		else break;
	}
    l = 0;
    r = -1;
    while(true){
		if(b <= k && p < r-l+1)	p = r-l+1;
		if(b <= k && (r+1) < s.size()){
			if(s[r+1] == 'b') b++;
			r++;	
		}
		else if(k < b){
			if(s[l] == 'b') b--;
			l++; 
		}
		else break;
	}
    if(p>m) m = p; 
	cout << m << '\n';
	return 0; 
}
