#include <iostream>
using namespace std;

int main() {
	//code
	int T, N;
	int A[100001];
	int i = 0;
	int flag = 0;
	cin >> T;
	while(T--) {
	    cin >> N;
	    flag = 0;
	    for (i = 0; i < N; i++) {
	        cin >> A[i];
	    }
	    i = 0;
	    if (N == 1) {
	        cout << N << endl;
	        continue;
	    }
	    while (flag == 0) {
	        if(A[(i % N)] - i <= 0) {
	            flag = 1;
	            break;
	        }
	        i++;
	    }
	    
	    cout << (i+1) % N << endl;
	}
	return 0;
}
