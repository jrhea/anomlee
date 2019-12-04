
/*extern void eth2_loadPreStateRoot(const unsigned long * offset);
extern unsigned long eth2_blockDataSize();
extern void eth2_blockDataCopy(const unsigned long * outputOffset, const unsigned long offset, const unsigned long length);
extern void eth2_savePostStateRoot(const unsigned long * offset);
*/

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

void main() {
    double input[4] = {5.0,3.4,1.5,0.2};
    double output[3] = { 0 };
    char *output_names[3] = {"setosa","versicolor","virginica"};
    score(input,output);

    //printf("Probabilities: ");
    //for(int i = 0; i < 3; i++) {
    //  printf("%f ", output[i]);
    //}
    //printf("\nModel Predicts: %s\n",output_names[max(output,3)]);
    

}