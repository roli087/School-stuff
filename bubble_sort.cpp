#include<iostream>
#include<fstream>
using namespace std;

int vek[100];
int vek_length = 0;

void bubble_sort(int vek[], int vek_length){
    for(int i=0; i<vek_length-1; i++){
        for(int j=0; j<vek_length-i-1; j++){
            if(vek[j]>vek[j+1]){
                swap(vek[j], vek[j+1]);
            }
        }
    }
}
void print_vek(int vek[], int vek_length){
    for(int i=0; i<vek_length; i++)
        cout<<vek[i]<<" ";
    cout<<endl;
}
void matrix_data(){
    fstream vektor("vek.txt");
    int tmp,i=0;
    while(vektor>>tmp){
        vek[i]=tmp;
        i++;
    }
    vek_length = i;
    vektor.close();
}
int main(){
    matrix_data();

    cout<<"original: ";
    print_vek(vek, vek_length);

    bubble_sort(vek, vek_length);

    cout<<"modified: ";
    print_vek(vek, vek_length);
    return 0;
}
