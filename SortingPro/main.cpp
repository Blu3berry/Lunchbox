

#include <iostream>
#include <vector>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>

using namespace std;

int realShit(vector<int> vec,int max){
    int supermax=max;
    int sum=0;
    for(int i=1; i<vec.size();i++){
        sum+=vec.at(i);
        if(sum>0){
            vec.front()+=sum;
            vec.erase(vec.begin()+1,vec.begin()+i+1);
            i=0;
            sum=0;
        }else if(sum+vec.front()<0){
            if(vec.front()>supermax){
                supermax=vec.front();
            }
            vec.erase(vec.begin(),vec.begin()+i+1);
            i=0;
            sum=0;
        }
    }
    if(vec.front()>supermax){
        supermax=vec.front();
    }
    return supermax;

}

vector<int> simplify(int *p,int length){
    bool neg=0;
    bool pos=1;
    bool prev=0;
    int sum=0;
    vector<int> bar;
    for(int i=0;i<length;i++){
        if (*(p+i)<0){
            neg = 1;
            pos = 0;
        }if(*(p+i)>0){
            neg=0;
            pos=1;
        }
        if(i==0){
                sum = *(p);

            prev= sum < 0 ? 0 : 1;
        }
        if((!prev)&&neg){
            sum +=*(p+i);
        }else if((prev&&pos && i!=0)){
            sum+=*(p+i);
        }else if(prev&&neg&& i!=0){
            prev=0;
            bar.push_back(sum);
            sum =*(p+i);
        }else if(!prev&&pos&& i!=0){
            prev=1;
            bar.push_back(sum);
            sum=*(p+i);
        }


    }
    bar.push_back(sum);
    if (bar.at(0)<=0){
        bar.erase(bar.begin()+0);
    }
    if(bar.back()<=0){
        bar.pop_back();

    }

    return bar;
}

vector<int> kickEnds(vector <int> bar,int *maxi) {

     int max = 0;

    //kick from front
    while (bar.size() > 1) {
        int first = bar.at(0);
        int second = bar.at(1);
        if (second + first <= 0) {
            if (first > max) max = first;
            bar.erase(bar.begin() + 0);
            bar.erase(bar.begin() + 0);

        } else break;

    }
    //kick from back
    while (bar.size() > 1) {
        int last = bar.back();
        int secondlast = bar.at(bar.size() - 2);
        if (secondlast + last <= 0) {
            if (last > max) max = last;
            bar.pop_back();
            bar.pop_back();
        } else break;

    }
    *maxi = max;
    return bar;
}

vector <int>genRndList(int length, int range, int start){
    vector <int> randomList;
    for(int i=0; i<length; i++){
        randomList.push_back(rand() % (range) + start);
    }

    return randomList;
}

int nCube (vector<int> bar){
    int n = bar.size();
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += bar.at(k);
                if (sum > max) {
                    max = sum;
                }
            }
        }
    }
    return max;
}

    int main() {
    clock_t now = clock();
        int foo[] = {-2, 15, 3, -17, -24, -3, 20, 5, 40, -10};
       for(int j =0;j<100;j++) {
           int max = 0;

           srand(time(NULL));
           auto rndList = genRndList(1000, 1000, -500);
           int rndArr[rndList.size()];

           for (int i = 0; i < rndList.size(); i++) {
               rndArr[i] = rndList.at(i);
           }
          // for (int i = 0; i < sizeof(rndArr) / 4; i++) {
           //    cout << rndArr[i] << " ";
          // }
          // cout << endl;
          // auto simple = simplify(&rndArr[0], sizeof(rndArr) / 4);
           //auto pilot = kickEnds(simple, &max);
           //auto lol = realShit(pilot,max);
            auto lol2 = nCube(rndList);


           //if(realShit(pilot,max) != nCube(simple)){
               //cout<<"Das war wohl nix"<<realShit(pilot,max)<<nCube(simple)<<endl;
               //break;
           //}else{
               cout<<"NOICE"<<j;
          // }

           //cout<< "NACH SIMPLIFIZIERUNG" << endl;
           //for (int i = 0;i<simple.size(); i++){
           //  cout << simple.at(i) << " ";
           //}
           //cout << endl << "NACH KICKUNG" << endl;
           // for (int i = 0;i<pilot.size(); i++){
           //    cout << pilot.at(i) << " ";
           // }
           //cout<<endl<< "MEIN ALGO";
           //cout<< endl<<realShit(pilot,max)<<endl;
           //cout<<"N3"<<endl;
           // cout<<nCube(simple)<<endl;
       }
       clock_t after = clock();
       cout<<endl<< after -now;
        cout <<endl;

        return 0;

    }

