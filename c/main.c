int max(double arr[], int n) 
{ 
    int i; 
    double max = arr[0]; 
    for (i = 1; i < n; i++){
        if (arr[i] > max) {
            max = i; 
        }
    }
    return max; 
} 

int main(int argc, char *argv[]) {

    double input[4] = {5.0,3.4,1.5,0.2};
    double output[3] = { 0 };
    char *output_names[3] = {"setosa","versicolor","virginica"};
    score(input,output);

    printf("Probabilities: ");
    for(int i = 0; i < 3; i++) {
      printf("%f ", output[i]);
    }
    printf("\nModel Predicts: %s\n",output_names[max(output,3)]);

}