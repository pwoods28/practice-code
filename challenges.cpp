#include <iostream>
#include <string>
const float LOW = 0;
const float HIGH = 50000;
const float L_STEP = 0;
const float H_STEP = 10;

using namespace std;
int main(){
	float start_c,end_c,step;
	cout << "Please enter a start temperature (in deg.C)" << endl;
	cin >> start_c;
	cout << "Please enter an end temperature (deg.C)" << endl;
	cin >> end_c;
	cout << "Please enter a step size" << endl;
	cin >> step;

	if(start_c < LOW){
		cout << "Please ensure start temperature is greater than or equal to " << LOW << endl;
		return 1;
	}

	if(end_c > HIGH){
		cout << "Please ensure end temperature is less than or equal to " << HIGH << endl;
		return 1;
	}

	if(HIGH<=LOW){
		cout << "start must be less than end" << endl;
		return 1;
	}

	if(step>(end_c-start_c)||step<L_STEP||step>H_STEP){
		cout << "Invalid step size" << endl;
		return 1;
	}

	// C->F = C*(9/5) + 32
	float F;

	for (float x=start_c;x<end_c;x+=step){
		F = x*(9.0/5.0) + 32;
		cout << x << "(C) | " << F << "(F)\n";
	}

	return 0;

}
