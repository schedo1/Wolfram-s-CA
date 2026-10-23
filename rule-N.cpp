#include<algorithm>
#include "libRULE-N.h"	

#define N 200

#if N%2==0
#define M N+1
#endif

#if N%2==1
#define M N
#endif

using namespace std;

void FromIntToBin(vector <int> &rule, int &RULE){
	if(RULE!=0){
		if(RULE%2==0){RULE/=2; rule.push_back(0);}
		else{RULE = (RULE-1)/2; rule.push_back(1);}
		
		FromIntToBin(rule, RULE);
	}
	else{ while(rule.size()!=8) rule.push_back(0); reverse(rule.begin(), rule.end());} 
}

int main(){
	//section 1: -------------------------------------------------------------------------
	int RULE, steps;
	vector <int> rule(0);
	
	cout<<"rule: ";
	cin>>RULE; RULE = (RULE<0) ? 0 : (RULE>255) ? 255 : RULE;	
	cout<<"Number of steps: ";
	cin>>steps; if(steps<0) steps = 1;
	
	FromIntToBin(rule, RULE); //transform the rule in bin
	
	vector <vector <int> > config(8, vector <int> (3));
	config = {{1,1,1},{1,1,0},{1,0,1},{1,0,0},{0,1,1},{0,1,0},{0,0,1},{0,0,0}};
	
	//section 2: -------------------------------------------------------------------------
	vector <Cell> cells(M);
	for(int i=0; i<cells.size(); i++){//values at 0
		cells[i].c = i;
		cells[i].value = 0;
		cells[i].index=i;
	} cells[(M-1)/2].value=1;
	for(int i=0; i<cells.size(); i++){//configs at 0
		cells[i].NewLocalConfig(cells);
	}
	
	mappa m1(steps, M);
	for(int i=0; i<cells.size(); i++){
		if(cells[i].value==1) m1.add(0, i, ' ', 47);
	}
	for(int i=1; i<steps; i++){
		for(int j=0; j<cells.size(); j++) cells[j].NewValue(config, rule);
		for(int j=0; j<cells.size(); j++) cells[j].increasingValues();
		for(int j=0; j<cells.size(); j++) cells[j].NewLocalConfig(cells);
		
		for(int j=0; j<cells.size(); j++){
			if(cells[j].value == 1) m1.add(i, j, ' ', 47);
		}
	}
	m1.print();
	
	
//	//section 3: -------------------------------------------------------------------------
//	for(int i=0; i<cells.size(); i++){
//		cells[i].NewValue(config, rule);
//	}
	
	
	return 0;}
