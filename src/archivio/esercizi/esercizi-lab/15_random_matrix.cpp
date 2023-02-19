#include <iostream>
#include <cstdlib>
using namespace std;

int ** generate_matrix(int r, int c) {
    srand(time(NULL));

    int** matrix = new int*[r];
    for (int i=0; i<r; i++) 
        matrix[i] = new int[c];

    for (int i=0; i<r; i++) 
        for (int y=0; y<c; y++)
            matrix[i][y] = rand() % 100;

    return matrix;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: TODO";
        exit(1);
    }

    int r = atoi(argv[1]);
    int c = atoi(argv[2]);

    int** matrix = generate_matrix(r, c);

    for (int i=0; i<r; i++) {
        for (int y=0; y<c; y++)
            cout << matrix[i][y] << " ";
        cout << endl;
    }

    for (int i=0; i<r; i++)
        delete[] matrix[i];
    
    delete[] matrix;
        
    cout << endl;
}