#include <bits/stdc++.h>
using namespace std;

char n1[1000000];
char n2[1000000];
char m1[1000000];
char m2[1000000];

int main(int argc, char const *argv[])
{
	
	scanf("%s %s", &n1, &n2);
	int len1=strlen(n1);
	int len2=strlen(n2);
	
	bool overzero;
	
	int index=0;
	
	overzero=false;
	for(int i=0; i<len1; ++i){
		if(n1[i]=='0' && overzero==false){}
		else{
			m1[index++]=n1[i];//not ok
			m1[index]='\0';
			overzero=true;
		}
	}
	
	index=0;
	overzero=false;
	for(int i=0; i<len2; ++i){
		if(n2[i]=='0' && overzero==false){}
		else{
			m2[index++]=n2[i];//not ok
			m2[index]='\0';
			overzero=true;
		}
	}	
	

	if(strlen(m1)<strlen(m2)){printf("<\n"); return 0;}
	else if(strlen(m1)>strlen(m2)){printf(">\n"); return 0;}
	else if(strlen(m1)==strlen(m2)){
		for(int i=0; i<strlen(m1); ++i){
			if(m1[i]>m2[i]){
				printf(">\n");
				return 0;
			}
			else if(m1[i]<m2[i]){
				printf("<\n");
				return 0;
			}
			else if(i==strlen(m1)-1){
				printf("=\n");
				return 0;
			}
		}
	}
}
