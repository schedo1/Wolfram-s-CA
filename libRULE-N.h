#pragma once
#include<iostream>
#include<vector>
#include<string>

#define N 200

#if N%2==0
#define M N+1
#endif

#if N%2==1
#define M N
#endif

using namespace std;

void Cout(char str, int colore){
	if(colore<=37 && colore>=30) cout<<"\x1b["<<colore<<"m"<<str<<"\x1b[37m"<<" ";
	else if(colore<=47 && colore>=40) cout<<"\x1b["<<colore<<"m"<<str<<" "<<"\x1b[0m"; //spazio per equiparare 
	//col resto
}
class mappa{
public:
	vector <vector <char> > m;
	vector <vector <int> > m2;
	int dimm;
	int dimmR, dimmC;
	
	mappa(){
		this->dimm = 0;
		dimmR = dimm;
		dimmC = dimm;
		m = vector <vector <char> > (dimm, vector <char> (dimm));
		m2 = vector <vector <int> > (dimm, vector <int> (dimm));
		for(int i=0; i<dimm; i++){
			for(int j=0; j<dimm; j++){
				m[i][j]=' ';
				m2[i][j]=37;
			} 
		}	
	}
	mappa(int dimm){
		this->dimm = dimm;
		dimmR = dimm;
		dimmC = dimm;
		
		m = vector <vector <char> > (dimm, vector <char> (dimm));
		m2 = vector <vector <int> > (dimm, vector <int> (dimm));
		for(int i=0; i<dimm; i++){
			for(int j=0; j<dimm; j++){
				m[i][j]=' ';
				m2[i][j]=37;
			} 
		}
	}
	mappa(int R, int C){
		this->dimm = C;	
		dimmR = R;
		dimmC = C;
		
		m = vector <vector <char> > (R, vector <char> (C));
		m2 = vector <vector <int> > (R, vector <int> (C));
		
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				m[i][j]=' ';
				m2[i][j]=37;
			} 
		}
	}	
	
	void print(){
		cout<<"+";
		for(int i=0; i<dimmC; i++){
			cout<<"--";
		} cout<<"+\n";
		
		for(int i=0; i<m.size(); i++){
			cout<<"|";
			for(int j=0; j<m[i].size(); j++){
				Cout(m[i][j], m2[i][j]);
			} cout<<"|\n";
		}
		
		cout<<"+";
		for(int i=0; i<dimmC; i++){
			cout<<"--";
		} cout<<"+\n";
	}	
	void print(int a){
		if(a==1){
			cout<<"+";
			for(int i=0; i<dimmC; i++){
				cout<<"--";
			} cout<<"+\n";	
		}
		 		
		for(int i=0; i<m.size(); i++){
			if(a==1) cout<<"|";
			for(int j=0; j<m[i].size(); j++){
				Cout(m[i][j], m2[i][j]);
			} if(a==1) cout<<"|"; cout<<"\n";
		}
		
		if(a==1){
			cout<<"+";
			for(int i=0; i<dimmC; i++){
				cout<<"--";
			} cout<<"+\n";	
		} 
	}
		
	void add(int r, int c, char s, int color){
		this->m[r][c] = s;
		this->m2[r][c] = color;
	}
	void add(int r, int c, char s){
		this->m[r][c] = s;
		this->m2[r][c] = 37;
	}
	void sub(int r, int c){
		this->m[r][c] = ' ';	
		
	}
};
class Cell{
public:
	int c, index;
	int value, newvalue;
	int LocalConfig[3];
	
	void NewValue(vector <vector <int> > config, vector <int> rule){
		for(int i=0; i<config.size(); i++){
			if(LocalConfig[0] == config[i][0] 
			&& LocalConfig[1] == config[i][1]
			&& LocalConfig[2] == config[i][2]) newvalue=rule[i];
		}
		
	}	
	void increasingValues(){
		value = newvalue;
	}
	void NewLocalConfig(vector <Cell> cell){
		int molt0, molt2;
		molt0 = (index>0) ? 1:0;
		molt2 = (index<M-1) ? 1:0;
		
		LocalConfig[0] = int(cell[index-1].value)*molt0;
		LocalConfig[1] = value;	
		LocalConfig[2] = int(cell[index+1].value)*molt2;
	}	
	
};
