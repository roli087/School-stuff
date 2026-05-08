#include<iostream>
#include<fstream>
using namespace std;

int vec[100], matrix[100][100];
int vec_length = 0, matrix_length1 = 0, matrix_length2 = 0;

void matrix_data(){
    fstream mat("matrix.txt");
    mat>>matrix_length1>>matrix_length2;
    for(int i=0; i<matrix_length1; i++){
        for(int j=0; j<matrix_length2; j++){
            mat>>matrix[i][j]<<" ";
        }
    }
    mat.close();
}



void vector_data(){
    fstream vek("vek.txt");
    int tmp,i=0;
    while(vek>>tmp){
        vec[i]=tmp;
        i++;
    }
    vec_length = i;
    vek.close();
}

void bubble_sort(){
    for(int i=0; i<vec_length-1; i++){
        for(int j=0; j<vec_length-i-1; j++){
            if(vec[j]>vec[j+1]){
                swap(vec[j], vec[j+1]);
            }
        }
    }
}

void print_vector(){
    for(int i=0; i<vec_length; i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

void print_matrix(){
    for(int i=0; i<matrix_length1; i++){
        for(int j=0; j<matrix_length2; j++){
            cout<<matrix[i][j];
        }
        cout<<endl;
    }
}

int main(){
    vector_data();
    matrix_data();

    cout<<"original: ";
    print_vector();

    bubble_sort();

    cout<<"modified: ";
    print_vek();

    print_matrix();
    return 0;
}
