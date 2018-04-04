#include<iostream>
using namespace std;
void binarizar(int a){
	for(int i=31;i>=0;i--){
		cout<<((a>>i)&1);
	}cout<<endl;
}
int multiplicacion(int Q,int M){
    if(!Q || !M)return 0;
    int A=0,cont=0,k=31;
    bool acarreo=0,p,r;
    while(!((Q>>k)&1))k--;
    cont=k+1;
    while(cont>0){
	if(Q&1){
            for(int i=0;i<32;i++){
		    r=(acarreo && !((A>>i)&1))||(!acarreo && ((A>>i)&1));
		    p=(r && !((M>>i)&1))||(!r && ((M>>i)&1));
		    acarreo=((acarreo && ((A>>i)&1))||(acarreo && ((M>>i)&1)))||(((A>>i)&1)&&((M>>i)&1));
		    if(p)A=(A|(1<<i));
		    else A=~((~(A))|(1<<i));
            }
        }
	Q=Q>>1;
	if(A&1)Q=(Q|1<<k);
    	A=A>>1;
    	if(acarreo){
    	    acarreo=0;
    	    A=(A|(1<<k));
   	}
    	cont--;
    }
    A=A<<(k+1);
    for(int i=0;i<32;i++){
    	r=(!((A>>i)&1) && ((Q>>i)&1))||(((A>>i)&1) && !((Q>>i)&1));
	if(r)A=(A|(1<<i));
	else A=~(((~A))|(1<<i));
    }
    return A;
}
int main(){
    int a,b;
    cin>>a>>b;
    cout<<multiplicacion(a,b)<<endl;
}
