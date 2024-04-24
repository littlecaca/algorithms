#include<iostream>
#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{
	if(b==0)return a;
	return gcd(b,a%b);
}
ll multiply(ll x, ll y,ll p)
{
	ll re=0;
	while(y)
	{
		if(y&1)re=(re+x)%p;
		x=(x+x)%p;y>>=1;
	}
	return re;
}
ll power(ll x, ll y,ll p)
{
	ll re=1;
	while(y)
	{
		if(y&1)re=multiply(re,x,p)%p;
		x=multiply(x,x,p)%p;y>>=1;
	}
	return re;
}
ll getphi(ll n)
{
	ll re=n;
	for(ll i=2;i*i<=n;++i)
	{
		if(n%i==0)re=re/i*(i-1);
		while(n%i==0)n/=i;
	}
	if(n!=1)re=re/n*(n-1);
	return re;
}
int main()
{
	ll L,T=0;
	while(scanf("%lld",&L)&&L!=0)
	{
		
		++T;
		ll n=9*L/gcd(1ll*8,1ll*9*L);ll x=getphi(n);
		if(gcd(10,n)!=1){printf("Case %d: 0\n",T);continue;}
		for(ll i=1;i*i<=x;i++)
			if(x%i==0&&power(10,i,n)==1)
			{
				printf("Case %lld: %lld\n",T,i);
				goto end;
			}
		for(ll i=sqrt(1.0*x);i>=1;i--)
			if(x%i==0&&power(10,x/i,n)==1)
			{
				printf("Case %lld: %lld\n",T,x/i);
				break;
			}
		end: ;
	}
	return 0;
}