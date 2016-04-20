#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
	int m, n;
	cin >> m >> n;
	vector< vector< float > > sys;
	sys.resize(m, vector< float >(n));
	for(int i=0; i<m; i++)
		for(int j=0; j<n; j++)
			cin>>sys[i][j];
	vector<float> ans(m, 0);
	bool pass = true;
	while(pass){
		pass = false;
		for(int i=0; i<m; i++){
			float val = sys[i][n-1];
			for(int j=0; j<m; j++)
				if(i != j)	val -= sys[i][j]*ans[j];
			val /= sys[i][i];
			if(abs(val - ans[i]) > 0.000001)		pass = true;
			ans[i] = val;
		}
	}
	for(int i=0; i<3; i++)
		cout<<"\nX"<<i+1<<":"<<ans[i];
	return 0;
}
			
