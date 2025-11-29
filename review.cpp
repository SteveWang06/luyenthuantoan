//B2-Sequence

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main(){

  	ios::sync_with_stdio(false);
  	cin.tie(nullptr);
  
  	int n, Case = 1;
  	while(cin >> n){
  		
  		bool flag = true;
  		vector<int> b(n);
  		for(int i = 0; i < n; ++i){
  			cin >> b[i];
  		}
  		
  		if(n <= 0) flag = false;
  		for(int i = 0; i < n && flag; ++i){
  			if(b[i] < 1) flag = false;
  			if(i > 0 && b[i] <= b[i-1]) flag = false;
  		
  		}
  		
  		if(flag){
  		
  			unordered_set<int> seen;
  			seen.reserve(n*(n + 1) / 2 * 2);
  			for(int i = 0; i < n && flag; ++i){
  				for(int j = i; j < n; ++j){
  					int sum = b[i] + b[j];
  					if(seen.find(sum) != seen.end()){
  						flag = false;
  						break;
  					
  					} 
  					seen.insert(sum);
  				
  				}
  			
  			}
  		
  		}
  		
  		
  	    if(flag){
  			cout << "Case #" << Case++ << ": It is a B2-Sequence." << "\n\n";
  			
  		}else{
  			cout << "Case #" << Case++ << ": It is not a B2-Sequence." << "\n\n";
  		}
  	
  	}

    return 0;


}