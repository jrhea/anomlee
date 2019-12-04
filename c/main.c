
/*extern void eth2_loadPreStateRoot(const unsigned long * offset);
extern unsigned long eth2_blockDataSize();
extern void eth2_blockDataCopy(const unsigned long * outputOffset, const unsigned long offset, const unsigned long length);
extern void eth2_savePostStateRoot(const unsigned long * offset);
*/

void print(const unsigned int * output, unsigned int outputLength);

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
    char *prob_str = "\nProbabilities: \n";
    //print((const unsigned int *)prob_str,(unsigned int)strlen(prob_str));
    //for(int i = 0; i < 3; i++) {
    //  printf("%f ", output[i]);
    //}
    
    char *model_pred_str = "\nModel Predicts: ";
    int model_pred_len = strlen(model_pred_str);
    char *predicted_name = output_names[max(output,3)];
    int predicted_name_len = 6;//strlen(predicted_name);
    print((const unsigned int *)model_pred_str,(unsigned int)model_pred_len);
    print((const unsigned int *)predicted_name,(unsigned int)predicted_name_len);
    print((const unsigned int *)"\n\n",(unsigned int)4);
    

}