// Find an index in an array such that its suffix sum is equal to its prefix sum

// Written by Patrick Woods, 2017

#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> A(5);
	A[0]=1;
	A[1]=4;
	A[2]=-5;
	A[3]=2;
	A[4]=0;
	
	int total=0;
    int LHS = 0;
    if(A.size() == 0){
        cout << "-1" << endl;
        return 0;
    }
    for(unsigned int i =0; i< A.size(); i++){
        total += A[i];
    }
    for(unsigned int i = 1; i< A.size(); i++){
        LHS += A[i-1];
        RHS = total - A[i] - LHS;

        if(LHS == RHS){
        cout << "i = " << i << endl;
        return 0;
        }
    }
        cout << "-1" << endl;
        return 0;
}

