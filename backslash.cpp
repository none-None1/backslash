#include<cstdio>
#include<map>
#include<ctime>
#include<cstdlib>
#define ll long long
std::map<ll,char> tape;
char query(ll x){
	if(!tape.count(x)) return '\\';
	return tape[x];
}
int main(){
	srand(time(0));
	ll len=0,ip=0,ipd=1,p=0;
	char x=0;
	while(1){
		char c;
		c=getchar();
		if(c=='!') break;
		if(c!='/'&&c!='\\') return puts("Invalid character"),1;
		tape[len]=c;
		len++;
	}
	if(!len) return puts("Nope."),0;
	while(ip<len){
		int cnt=0;
		while(query(ip)!='/'){
			if(ip>=len) return puts("Nope."),0;
			cnt++;
			ip+=ipd;
		}
		ip++;
		switch(cnt){
			case 0:{
				tape[p]=(query(p)=='/'?'\\':'/');
				break;
			}
			case 1:{
				x<<=1;
				break;
			}
			case 2:{
				x<<=1;
				x++;
				break;
			}
			case 3:{
				putchar(x);
				break;
			}
			case 4:{
				x=getchar(),x=(x==EOF?0:x);
				break;
			}
			case 5:{
				tape[p]=((x&1)?'/':'\\');
				x>>=1;
				break;
			}
			case 6:{
				p--;
				break;
			}
			case 7:{
				p++;
				break;
			}
			case 8:{
				if(query(p)=='\\') ip=0;
				else tape[p]='\\';
				break;
			}
			case 9:{
				putchar(query(p));
				break;
			}
			case 10:{
				if(query(p)=='\\') return 0;
				break;
			}
			case 11:{
				if(query(p)=='/') break;
				while(query(ip)!='/'){
					if(ip>=len) return puts("Nope."),0;
					cnt++;
					ip+=ipd;
				}
				break;
			}
			case 12:{
				tape[p]=((rand()&1)?'/':'\\');
				break;
			}
			case 13:{
				if(p<len) ip=0;
				break;
			}
			default:{
				if(cnt&1) x-=(cnt-15)/2;
				else x=(cnt-14)/2;
				break;
			}
		}
	}
	return 0;
}

