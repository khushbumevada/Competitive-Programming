#include <iostream>
using namespace std;

long permute(int n, int r) {
    return (n*(n-1)*(n-2))/6;
}

int main() {
	//code
	int T, N;
	char arr[201][201];
	int i, j;
	string inp;
	
	cin >> T;
	while(T--) {
	    cin >> N;
	    for(i = 0; i < N; i++) {
	        cin >> inp;
	        for (j = 0; j < inp.size(); j++) {
	            if(inp[j] != '.') {
	                arr[i][j] = inp[j];
	            } else {
	                arr[i][j] = '0';
	            }
	        }
	    }
	    int count_H[10000] = {0};
	    for (i = 0; i < N; i++) {
	        for (j = 0; j < N; j++) {
	            if(arr[i][j] != '0'){
	                count_H[i]++;
	            }
	        }
	    }
	    int count_V[10000] = {0};
	    for (i = 0; i < N; i++) {
	        for (j = 0; j < N; j++) {
	            if(arr[i][j] != '0'){
	                count_V[j]++;
	            }
	        }
	    }
	    int count1[1000][1000] = {0};
	    int count2[1000][1000] = {0};
	    for(i = 0; i < N; i++) {
	        for (j = 0; j < N; j++) {
	            if (i == 0 || j == 0) {
    	            int m = i, n = j;
    	            while(m != N && n != N) {
    	                if(arr[m][n] != '0') {
    	                    count1[i][j]++;
    	                }
    	                m++;
    	                n++;
    	            }
	            }
	        }
	    }
	    char temp;
	    for (i = 0; i < N; i++){
	        for (j = 0; j < N/2; j++) {
	            temp = arr[i][j];
	            arr[i][j] = arr[i][N-j-1];
	            arr[i][N-j-1] = temp;
	        }
	    }
        for(i = 0; i < N; i++) {
	        for (j = 0; j < N; j++) {
	            if (i == 0 || j == 0) {
    	            int m = i, n = j;
    	            while(m != N && n != N) {
    	                if(arr[m][n] != '0') {
    	                    count2[i][j]++;
    	                }
    	                m++;
    	                n++;
    	            }
	            }
	        }
	    }	    
	    long chances = 0;
	    for(i = 0; i < N; i++) {
	        if (count_H[i] >= 3) {
	            chances += permute( count_H[i],3);
	        }
	        if (count_V[i] >= 3) {
	            chances += permute( count_V[i],3);
	        }
	    }
	    
	    for(i = 0; i < N; i++) {
	        for(j = 0; j < N; j++) {
	            if (count1[i][j] >= 3) {
	                chances += permute( count1[i][j],3);
    	        }
    	        if (count2[i][j] >= 3) {
    	            chances += permute( count2[i][j],3);
    	        }
	        } 
	    }
	    
	    cout << chances << endl;
	}
	return 0;
}
