#include <iostream>
#include<cstdlib>
#include <vector>
using namespace std;

 
long long max_pair_wise_product(const vector<long>&numbers){
    long long result = 0;
    int n = numbers.size();

    for(int i=0; i<n; ++i){
        for(int j=i+1; j<n; ++j){
            if(((long long) numbers[i]*numbers[j]>result)){
                result = (long long) numbers[i]*numbers[j];
            }
        }

     }
     return result;
    


}
long max_pair_Wise(const vector<long>&numbers){
    int max_index1=-1;
    
    int n = numbers.size();
    
    for(int i=0; i<n; ++i){
        if((max_index1 ==-1)|| (numbers[i]>numbers[max_index1])){
            max_index1=i;
        }
    }

    int max_index2=-1;
    for(int j=0; j<n; ++j){
        if((j!=max_index1)&&(max_index2==-1)||(numbers[j]>numbers[max_index2])){
            max_index2=j;
        }
    }
    return ((long long)numbers[max_index1])*(numbers[max_index2]);  
}


int main() 
{
    while(true){
        int n = rand()%10 +2;
        cout<<n<<endl;
        vector<long> numbers(n);
        for(int i=0; i<n; ++i){
            numbers[i] = rand()%100000;
        }
        for(int i=0; i<n; ++i){
            cout<<numbers[i]<<" ";
        }
        cout<<"\n";
        long long res1 = max_pair_wise_product(numbers);
        long long res2 = max_pair_Wise(numbers);
        if(res1!=res2){
            cout<<"Wrong answer: "<<res1<<" "<<res2<<endl;
            break;
        }
        else{
            cout<<"OK"<<endl;
        }
    }

    int n;
    cin>>n;
    vector<long> numbers(n);
    for(int i=0; i<n; ++i){
        cin>>numbers[i];
    }
    cout<<max_pair_Wise(numbers)<<endl;



    return 0;
}