#include <iostream>
#include <vector>
#include <list>
#include <rpcndr.h>

using namespace std;

int main() {
    int foo [6] = { 15,-17, 20, 5, 40, -10 };
    int n =sizeof(foo)/sizeof(int);
    int max = 0;
    for (int i=0; i<n; i++ ) {
        for ( int j =i; j<n; j++ ) {
            int sum = 0;
            for ( int k=i; k<j; k++ ) {
                sum += foo[k];
                if(sum>max){
                    max=sum;
                }
            }
        }
    }
    cout <<max;
    return 0;
}
void simplify(int*p,int length){
    boolean neg=0;
    boolean pos=1;
    boolean prev=0;
    int sum=0;
    vector<int> bar;
    for(int i=0;i<length;i++){
        if (*(p+i*sizeof(int))<0){
            neg = 1;
            pos = 0;
        }if(*(p+i*sizeof(int))>0){
            neg=0;
            pos=1;
        }
        if(i==0){
            sum =*(p+sizeof(int));
            prev= sum < 0 ? 0 : 1;
        }
        if((!prev)&&neg){
            sum +=*(p+sizeof(i));
        }else if((prev&&pos)){
            sum+=*(p+sizeof(i));
        }else if(prev&&neg){
            prev=0;
            bar.push_back(sum);
            sum =*(p+sizeof(int));
        }else if(!prev&&pos){
            prev=1;
            bar.push_back(sum);
            sum=*(p+sizeof(int));
        }

    }
    bar.push_back(sum);

//return bar;

}