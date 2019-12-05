#define EXPORT __attribute__((used))

void print(const unsigned int * output, unsigned int outputLength);

// Reverses a string 'str' of length 'len' 
static void reverse(char* str, int len) 
{ 
    int i = 0, j = len - 1, temp; 
    while (i < j) { 
        temp = str[i]; 
        str[i] = str[j]; 
        str[j] = temp; 
        i++; 
        j--; 
    } 
} 

static double power(double x, double y)
{
    double result = x;
    while(y > 0) {
        result *= y;
        y--;
    }
    return result;
}

// Converts a given integer x to char[]
static int i2s(int x, char str[], int d) 
{ 
    int i = 0; 
    while (x) { 
        str[i++] = (x % 10) + '0'; 
        x = x / 10; 
    } 
    while (i < d) 
        str[i++] = '0'; 

    reverse(str, i); 
    str[i] = '\0'; 
    return i; 
} 

// Converts a float/double to a char[] 
static void f2s(float n, char* res, int afterpoint) 
{ 
    int ipart = (int)n; 
    float fpart = n - (float)ipart; 
    int i = i2s(ipart, res, 0); 

    if (afterpoint != 0) { 
        res[i] = '.';
        fpart = fpart * power(10, afterpoint); 
        i2s((int)fpart, res + i + 1, afterpoint); 
    } 
} 

static int max(double arr[], int n) 
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

EXPORT void main() {
    double input[4] = {5.0,3.4,1.5,0.2};
    double output[3] = { 0 };
    const char *output_names[3] = {"setosa    ","versicolor","virginica "};
    score(input,output);
    const char prob_str[19] = "\nProbabilities: \n";
    print((const unsigned int *)prob_str,(unsigned int)19);
    for(int i = 0; i < 3; i++) {
      const char output_str[6];
      f2s(output[i],output_str,4);
      print((const unsigned int *)output_str,(unsigned int)6);
      print((const unsigned int *)" ",(unsigned int)1);
    }
    print((const unsigned int *)"\n\n",(unsigned int)4);
    const char model_pred_str[22] = "Model Predicts: \n";
    const char *predicted_name = output_names[max(output,3)];
    print((const unsigned int *)model_pred_str,(unsigned int)22);
    print((const unsigned int *)predicted_name,(unsigned int)10);
    print((const unsigned int *)"\n\n",(unsigned int)4);
    

}