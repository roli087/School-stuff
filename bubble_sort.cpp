#include<iostream>
using namespace std;
void bubble_sort(int vek[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(vek[j]>vek[j+1]){
                swap(vek[j], vek[j+1]);
            }
        }
    }
}
void print(int vek[], int n){
    for(int i=0; i<n; i++)
        cout<<vek[i]<<" ";
    cout<<endl;
}
int main(){
    int vek[] = {30, 555, 2, 1, 8, 7};
    int n=sizeof(vek) / sizeof(vek[0]);

    cout<<"original: ";
    print(vek, n);

    cout<<"modified: ";
    bubble_sort(vek, n);
    print(vek, n);
    return 0;
}