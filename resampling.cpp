#include <iostream>

using namespace std;

double w[] = { 0.6, 1.2, 2.4, 0.6, 1.2 };//You can also change this to a vector

//TODO: Define a  ComputeProb function and compute the Probabilities

void ComputeProb() {
    double sum_w = 0;
    int size = sizeof(w)/sizeof(w[0]);
    for(int i=0; i<size; i++) {
        sum_w += w[i];
    }
    for(int i=0; i<size; i++) {
        w[i] = w[i]/sum_w;
        cout << "P"<< (i+1) << "=" << w[i] << endl;
    }
}

int main()
{
    //TODO: Print Probabilites each on a single line:
    //P1=Value
    //:
    //P5=Value
    ComputeProb();
    return 0;
}


// Suggested solution
double w[] = { 0.6, 1.2, 2.4, 0.6, 1.2 };
double sum = 0;

void ComputeProb(double w[], int n)
{
    for (int i = 0; i < n; i++) {
        sum = sum + w[i];
    }
    for (int j = 0; j < n; j++) {
        w[j] = w[j] / sum;
        cout << "P" << j + 1 << "=" << w[j] << endl;
    }
}

int main()
{
    ComputeProb(w, sizeof(w) / sizeof(w[0]));
    return 0;
}
