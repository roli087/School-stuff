#include<iostream>
#include<fstream>
using namespace std;

int vec[100], matrix[10][10];
int vec_length = 0, matrix_length1 = 0, matrix_length2 = 0;

void matrix_data(){
    fstream mat("matrix.txt");

    mat>>matrix_length1>>matrix_length2;

    for(int i=0; i<matrix_length1; i++){
        for(int j=0; j<matrix_length2; j++){
            mat>>matrix[i][j];
        }
    }

    mat.close();
}

void matrix_to_vector(){
    int n=0;

    for(int i=0; i<matrix_length1; i++){
        for(int j=0; j<matrix_length2; j++){
            vec[n] = matrix[i][j];
            n++;
        }
    }
}

void vector_to_matrix(){
    int n=0;

    for(int i=0; i<matrix_length1; i++){
        for(int j=0; j<matrix_length2; j++){
            matrix[i][j] = vec[n];
            n++;
        }
    }
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

void bubble_sort(int vec_length){
    for(int i=0; i<vec_length-1; i++){
        for(int j=0; j<vec_length-i-1; j++){
            if(vec[j]>vec[j+1]){
                swap(vec[j], vec[j+1]);
            }
        }
    }
}

void bubble_sort_matrix(){
    matrix_to_vector();
    bubble_sort(matrix_length1*matrix_length2);
    vector_to_matrix();
}

void print_vector(){
    for(int i=0; i<vec_length; i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

void print_matrix(){
    for(int i=0; i<matrix_length1; i++){
        for(int j=0; j<matrix_length2; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    vector_data();
    matrix_data();

    cout<<"original vector: ";
    print_vector();

    bubble_sort(vec_length);

    cout<<"bubble sorted vector: ";
    print_vector();

    cout<<"original matrix: "<<endl;
    print_matrix();

    bubble_sort_matrix();

    cout<<"bubble sorted matrix: "<<endl;
    print_matrix();

    return 0;
}
