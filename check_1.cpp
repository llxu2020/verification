#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

#define bsize 16      //The number of base codewords.
#define subsize 5
#define vector_n  bsize
#define opsize 150     //The number of codewords. 
#define vector_m  40  //The length of code. 
#define charc 10000

int cycle[vector_m] = {
	 4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,
	 30,31,32,33,34,35,36,37,38,39,0,1,2,3
};//Group action or automorphism cycle[i].

void check(int array[][subsize], int n, int m); 

int main(){
	
	FILE *f = fopen ("40check.txt","r");	//File path. 
	char tmp[charc];
	vector<int>  number;	
	int array[bsize][subsize];
		

	int count1=0,count2=0;
	for (int i=0;i<charc;i++){
		fscanf(f,"%c",&tmp[i]);
		if(tmp[i]>='0'&&tmp[i]<='9'){
			number.push_back(tmp[i]-'0');	 
		}
		
		if ((tmp[i]==','||tmp[i]=='}')&&number.size()>0){
			int s=0;
			for(int j=0;j<number.size();j++){
				s+=number[j]*pow(10,(number.size()-j-1));
			}
		
			if(count2<subsize){
				array[count1][count2++]=s;
				number.clear();
			}else{
				count1++;count2=0;
				array[count1][count2]=s;
				count2++;
				number.clear();
			}		
		}
		
	}
	for(int i=0;i<bsize;i++){
		for (int j=0;j<subsize;j++){
			cout<<array[i][j]<<ends;
		}
		cout<<endl;
	}
	fclose(f);
	
	
	
	check(array,opsize,subsize);
	
	
	return 0;
} 

void check(int array[][subsize], int n, int m){
	int i,j,k,p,q,c,d;
	int flag=0,s=0;

	int array_fin[opsize][vector_m]={0};
	for(int i1=0;i1<bsize;i1++){
		int t;
		if (array[i1][m-1]==1){
			p=array[i1][0];q=array[i1][1];c=array[i1][2];
			do{
				p=cycle[p];q=cycle[q];c=cycle[c];
				array_fin[s][p]=array_fin[s][q]=1;
				array_fin[s][c]=2;
				t=0;
				for(int a=0;a<3;a++){
					if(p==array[i1][a]||q==array[i1][a]||c==array[i1][a])
					t++;
					if(t==2) break;
				}
				s++; 
			}while(t<2);
		}else if(array[i1][m-1]==0){
			p=array[i1][0];q=array[i1][1];c=array[i1][2];d=array[i1][3];
			do{
				p=cycle[p];q=cycle[q];c=cycle[c];d=cycle[d];
				array_fin[s][p]=array_fin[s][q]=array_fin[s][c]=array_fin[s][d]=1; 
				t=0;
				for(int a=0;a<4;a++){
					if(p==array[i1][a]||q==array[i1][a]||c==array[i1][a]||d==array[i1][a])
					t++;
					if(t==2) break;
				}
				s++;
			}while(t<2);
		}else{
			p=array[i1][0];q=array[i1][1];
			do{
				p=cycle[p];q=cycle[q];
				array_fin[s][p]=array_fin[s][q]=2;
				t=0;
				for(int a=0;a<2;a++){
					if(p==array[i1][a]||q==array[i1][a])
					t++;
					if(t==2) break;
				}
				s++;
			}while(t<2);	
		}
	}
	
	for(int i1=0;i1<opsize;i1++){
		for(int i2=0;i2<vector_m;i2++){
			cout<<array_fin[i1][i2]<<ends;
		}
		cout<<endl;
	}
	
	
	for (i=0;i<n-1;i++){
		
		for(j=i+1;j<n;j++){
			int sum =0;
			for (k=0;k<vector_m;k++){
				sum+=abs(array_fin[i][k]-array_fin[j][k]);
			}
			if(sum<6){
				flag=1;
				break;
			}
		}
		if(flag==1) break;
	}
		if(flag==1){
			cout<<"failed!!!"<<endl;
			cout<<"i="<<i+1<<endl<<"j="<<j+1<<endl;
			for(int k=0;k<vector_m;k++){
				cout<<array_fin[i][k]<<ends;
			}
			cout<<endl;
			for(int k=0;k<vector_m;k++){
				cout<<array_fin[j][k]<<ends;
			}
			cout<<endl;
		}else{
			cout<<"success!!!"<<endl;
		}
		
			
}
