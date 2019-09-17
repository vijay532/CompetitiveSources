#include <bits/stdc++.h>
using namespace std;
 
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define LL long long
#define M1 1000000007
#define M2 1000000009
#define INF LLONG_MAX
#define N 100010
#define ll long long
//Print array
void pr(LL i,LL *x,LL n)
{
    for(LL j=i;j<i+n;j++)
    cout<<x[j]<<" ";
    cout<<endl;
}
 
//Input array
void ip(LL i,LL *x,LL n)
{
    for(LL j=i;j<i+n;j++)
    cin>>x[j];   
}
 
//print vals
void db(LL a,LL b=-1,LL c=-1)
{
    cout<<a<<" "<<b<<" "<<c<<" "<<endl;
}
 
//pref Sum
void prefs(LL i,LL *a,LL *b,LL n)
{
    b[i]=a[i];
    for(LL j=i+1;j<i+n;j++)
    b[j]=a[j]+b[j-1];
}
 
//reverse array
void revarr(LL i, LL *a,LL *b,LL n)
{
    LL j,k;
    for(j=i,k=n-1;j<i+n;j++)
    b[i+k--]=a[i];
}
 
//Modular power
LL Mpow(LL x, unsigned LL y, LL m)
{
    LL res = 1;
    x = x % m;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % m;
        y = y>>1; // y = y/2
        x = (x*x) % m;  
    }
    return res;
}
 
//Construct segment tree
LL construct(LL *a,LL *st,LL ss,LL se,LL si)
{
    if(ss==se)
    {
        st[si]=a[ss];
        return st[si];
    }
    LL mid=ss+(se-ss)/2;
    st[si]=(construct(a,st,ss,mid,si*2+1)+construct(a,st,mid+1,se,si*2+2));
    return st[si];
}
 
//Query Segment tree
LL gs(LL *st,LL l,LL r,LL ss,LL se,LL si)
{
    if(l<=ss&&r>=se)
    {
    //cout<<ss<<" "<<se<<endl;
    return st[si];
    }
    if(ss>r||se<l)
    return 0;
    LL mid=ss+(se-ss)/2;
    return (gs(st,l,r,ss,mid,si*2+1)+gs(st,l,r,mid+1,se,si*2+2));
}
 
//point udate segment tree
void update(LL *st,LL ss,LL se,LL i,LL diff,LL si)
{
    if(i<ss||i>se)
    {
    //cout<<i<<" "<<ss<<" "<<se<<" "<<diff<<endl;
    return;
    }
    //cout<<i<<" "<<ss<<" "<<se<<" "<<diff<<endl;
    st[si]=(st[si]+diff);
    if(ss!=se)
    {
        LL mid=ss+(se-ss)/2;
        update(st,ss,mid,i,diff,si*2+1);
        update(st,mid+1,se,i,diff,si*2+2);
    }
}
 
//construct lazy segment tree
LL lconstruct(LL *a,LL *st,LL ss,LL se,LL si)
{
    
    if(ss==se)
    {
        st[si]=a[ss];
        return st[si];
    }
    LL mid=ss+(se-ss)/2;
    st[si]=(lconstruct(a,st,ss,mid,si*2+1)+lconstruct(a,st,mid+1,se,si*2+2));
    return st[si];
}
 
//Query lazy Segment tree
LL lgs(LL *st,LL l,LL r,LL ss,LL se,LL si,LL *lazy)
{
    if(lazy[si])
    {
        st[si]=(st[si]+(se-ss+1)*lazy[si]);
        if(ss!=se)
        {
            lazy[si*2+1]=(lazy[si*2+1]+lazy[si]);
            lazy[si*2+2]=(lazy[si*2+2]+lazy[si]);
        }
        lazy[si]=0;
    }
    if(ss>r||se<l||ss>se)
    return 0;
    if(l<=ss&&r>=se)
    {
    return st[si];
    }
    LL mid=ss+(se-ss)/2;
    return (lgs(st,l,r,ss,mid,si*2+1,lazy)+lgs(st,l,r,mid+1,se,si*2+2,lazy));
}
 
//Udate Lazy Segtree
void lupdate(LL *st,LL ss,LL se,LL ql,LL qr,LL diff,LL si,LL *lazy)
{
    if(lazy[si])
    {
        st[si]=(st[si]+(se-ss+1)*lazy[si]);
        if(ss!=se)
        {
            lazy[si*2+1]=(lazy[si*2+1]+lazy[si]);
            lazy[si*2+2]=(lazy[si*2+2]+lazy[si]);
        }
        lazy[si]=0;
    }
    if(ss>se||qr<ss||ql>se)
    return;
    if(ss>=ql&&se<=qr)
    {
        st[si]=(st[si]+(se-ss+1)*diff);
        if(ss!=se)
        {
            lazy[si*2+1]=(lazy[si*2+1]+diff);
            lazy[si*2+2]=(lazy[si*2+2]+diff);
        }
        return;
    }
    if(ss!=se)
    {
        LL mid=ss+(se-ss)/2;
        lupdate(st,ss,mid,ql,qr,diff,si*2+1,lazy);
        lupdate(st,mid+1,se,ql,qr,diff,si*2+2,lazy);
    }
    st[si]=(st[2*si+1]+st[2*si+2]);
}
 
//ncr Lucas
LL ncrp(LL n, LL r, LL p)
{
    LL C[r+1];
    memset(C, 0, sizeof(C));
    C[0] = 1; 
    for (LL i = 1; i <= n; i++)
    {
        for ( LL j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%p;
    }
    return C[r];
}
LL ncrpl(LL n,LL r, LL p)
{
   if (r==0)
      return 1;
   int ni = n%p, ri = r%p;
   return (ncrpl(n/p, r/p, p) * 
           ncrp(ni, ri, p)) % p; 
}
 
//extended euclid GCD
LL gcde(LL a,LL b,LL *x,LL *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
    LL x1, y1; 
    LL gcd = gcde(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}
 
//Sum of gp
long long gp(LL r, LL p,LL m){
//cout << a << " " << r << " " << p << endl;
if(p==0)
return 1;
if(p==1)
return 1;
LL ans=0;
if(p%2==1){
ans=Mpow(r,p-1,m);
ans=(ans+((1+r)*gp(Mpow(r,2,m),(p-1)/2,m))%m)%m;
}
else{
    ans=((1+r)*gp(Mpow(r,2,m),p/2,m))%m;
}
return ans;
}
 
const ll MAX_N = 3e5 + 5;
 
 
ll trie[MAX_N * 30][3], nxt;
void trie_init(ll n) {
    ll nn = (n+2)*30;
    for(ll i=0; i<nn; i++)
        trie[i][0] = trie[i][1] = trie[i][2] = -1;
    nxt = 1;
}

void trie_insert(ll v, ll x) {
    ll cur = 0;
    for(ll i=29; i>=0; i--) {
        ll bit = v>>i & 1;
        if(trie[cur][bit]==-1)
            trie[cur][bit] = nxt++;
        cur = trie[cur][bit];
        trie[cur][2] = max(trie[cur][2], x);
    }
}
 
ll trie_getmax(ll v, ll m) {
    ll cur = 0, mx = -1;
    for(ll i=29; i>=0; i--) {
        ll bit = v>>i & 1;
        if(trie[cur][bit]!=-1)
        {
            cur=trie[cur][bit];
            mx=max(mx,trie[cur][2]);
        }
        else {
            cur=trie[cur][!bit];
            if(cur==-1)
            break;
            mx=max(mx,trie[cur][2]);
        }
        if(cur==-1) break;
    }
    return mx;
}
 
//Dijkstra 
void Shortpath(LL src,LL V)
{
    set< pair<LL, LL> > setds;
    vector<LL> dist(V, INF);
    setds.insert(make_pair(0, src));
    dist[src] = 0;
    while (!setds.empty())
    {
        pair<int, int> tmp = *(setds.begin());
        setds.erase(setds.begin());
        int u = tmp.second;
        list< pair<int, int> >::iterator i;
        /*for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if (dist[v] > dist[u] + weight)
            {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v], v)));
                dist[v] = dist[u] + weight;
                setds.insert(make_pair(dist[v], v));
            }
        }*/
    }
}
 
//Chinese Remainder theorm
LL crt(LL num[], LL rem[], LL k)
{
    LL prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];
    LL result = 0;
    for (int i = 0; i < k; i++)
    {
        LL pp = prod / num[i];
        LL inv,y;
        gcde(pp,num[i],&inv,&y);
        result += rem[i] * inv * pp;
    }
    return result % prod;
}
 LL p;
//Matrix Exp
void multiply(LL F[2][2], LL M[2][2])
{
  LL x =  ((F[0][0]*M[0][0])%p + (F[0][1]*M[1][0])%p +p)%p;
  LL y =  ((F[0][0]*M[0][1])%p + (F[0][1]*M[1][1])%p +p)%p;
  LL z =  ((F[1][0]*M[0][0])%p + (F[1][1]*M[1][0])%p +p)%p;
  LL w =  ((F[1][0]*M[0][1])%p + (F[1][1]*M[1][1])%p +p)%p;
 
  F[0][0] = x;
  F[0][1] = y;
  F[1][0] = z;
  F[1][1] = w;
}
void power(LL F[2][2], LL n,LL a,LL d)
{
  if( n <= 0 || n == 1)
      return;
  LL M[2][2] = {{1,1},{1,0}};
 
  power(F, n/2,a,d);
  multiply(F, F);
 
  if (n%2 != 0)
     multiply(F, M);
}
 
//Seive for primes
void sieve(LL limit, vector<LL> &prime)
{
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));
    for (LL p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (LL i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }
    for (LL p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
            //cout << p << "  ";
        }
    }
}
 
// Segmented Sieve for primes
void segsieve(LL l,LL r)
{
    LL limit = floor(sqrt(r))+1;
    vector<LL> prime;  
    sieve(limit, prime); 
        limit=r-l+1;
        bool mark[limit+1];
        memset(mark, true, sizeof(mark));
 
        for (int i = 0; i < prime.size(); i++)
        {
            int loLim = floor(l/prime[i]) * prime[i];
            if (loLim < l)
                loLim += prime[i];
                
            for (int j=loLim; j<=r; j+=prime[i])
                mark[j-l] = false;
        }
 
        for (int i = 0; i<limit; i++)
            if (mark[i] == true)
                cout << i+l << "  ";
}

// o(k) for computing nCk
ll binomialCoeff(ll n, ll k)  
{  
    ll res = 1;  
  
    // Since C(n, k) = C(n, n-k)  
    if ( k > n - k )  
        k = n - k;  
  
    // Calculate value of  
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]  
    for (ll i = 0; i < k; ++i)  
    {  
        res *= (n - i);  
        res /= (i + 1);  
    }  
  
    return res;  
} 
ll expo(ll n, ll k)
{
    if(k==0)
    {
        return 1;
    }
    else if(k==1)
    {
        return n;
    }
    ll res=expo(n,k/2);
    if(k%2)
    {
        return res*res*n;
    }
    else
    {
        return res*res;
    }
}