#include <bits/stdc++.h>
<<<<<<< HEAD

using namespace std;

int main()
{

    return 0;
}
=======
using namespace std ;

int64_t mergeCount(vector<int> &A,vector<int> &Tem , int p , int q, int r) {
    int i = p , j=q+1 , k=p ;
    int64_t count = 0 ;
    while (i<=q && j<=r)
    {
        if(A[i]<=A[j]) Tem[k++]=A[i++];
        else Tem[k++] = A[j++] , count += (q-i+1);
    }
    while (i<=q) Tem[k++] = A[i++];
    while (j<=r) Tem[k++] = A[j++];
    for(int t= p;t<=r;t++) A[t] = Tem[t];

    return count;
}

int64_t mergeSortCount(vector<int> &A, vector<int> &Tem, int p, int r){
    int64_t count = 0 ;
    if(p<r){
        int q = p+(r-p)/2;
        count += mergeSortCount(A,Tem,p,q);
        count += mergeSortCount(A,Tem ,q+1 , r);
        count += mergeCount(A , Tem , p , q , r);
    }
    return count ;
}

int main(){
    int N ;
    cin>>N;
    vector<int> A(N);
    vector<int> Tem(N);
    for(int i =0;i<N;i++) cin>>A[i];
    int64_t ans = mergeSortCount(A,Tem,0,N-1);
    cout<<ans<<"\n";
    return 0 ;
}

>>>>>>> ae85f044fc0cf032bd6398c3016b38956802b457
