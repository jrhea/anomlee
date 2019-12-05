void add_vectors(double *v1, double *v2, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] + v2[i];
}
void mul_vector_number(double *v1, double num, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] * num;
}
void score(double * input, double * output) {
    double var0[3];
    double var1[3];
    double var2[3];
    double var3[3];
    double var4[3];
    double var5[3];
    double var6[3];
    double var7[3];
    double var8[3];
    double var9[3];
    double var10[3];
    if ((input[3]) <= (0.7)) {
        memcpy(var10, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if ((input[2]) <= (4.8)) {
            if ((input[3]) <= (1.6500001)) {
                memcpy(var10, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var10, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            if ((input[2]) <= (5.05)) {
                if ((input[0]) <= (6.5)) {
                    memcpy(var10, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var10, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                if ((input[3]) <= (1.7)) {
                    if ((input[1]) <= (2.75)) {
                        memcpy(var10, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var10, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    }
    mul_vector_number(var10, 0.1, 3, var9);
    double var11[3];
    double var12[3];
    if ((input[3]) <= (0.75)) {
        memcpy(var12, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if ((input[3]) <= (1.55)) {
            if ((input[2]) <= (4.9)) {
                memcpy(var12, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var12, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            if ((input[2]) <= (4.65)) {
                memcpy(var12, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                if ((input[3]) <= (1.7)) {
                    if ((input[2]) <= (5.45)) {
                        memcpy(var12, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var12, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    }
    mul_vector_number(var12, 0.1, 3, var11);
    add_vectors(var9, var11, 3, var8);
    double var13[3];
    double var14[3];
    if ((input[0]) <= (5.45)) {
        if ((input[3]) <= (0.75)) {
            memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
        } else {
            memcpy(var14, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        }
    } else {
        if ((input[3]) <= (1.75)) {
            if ((input[3]) <= (0.65)) {
                memcpy(var14, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
            } else {
                if ((input[2]) <= (5.05)) {
                    memcpy(var14, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var14, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        } else {
            memcpy(var14, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    mul_vector_number(var14, 0.1, 3, var13);
    add_vectors(var8, var13, 3, var7);
    double var15[3];
    double var16[3];
    if ((input[0]) <= (5.45)) {
        if ((input[1]) <= (2.75)) {
            if ((input[0]) <= (4.7)) {
                memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
            } else {
                if ((input[1]) <= (2.45)) {
                    memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var16, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        } else {
            if ((input[0]) <= (5.3)) {
                memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
            } else {
                if ((input[3]) <= (0.95)) {
                    memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            }
        }
    } else {
        if ((input[3]) <= (1.75)) {
            if ((input[1]) <= (3.45)) {
                if ((input[3]) <= (1.45)) {
                    if ((input[3]) <= (1.3499999)) {
                        memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    } else {
                        if ((input[1]) <= (2.6999998)) {
                            memcpy(var16, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                        } else {
                            memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                        }
                    }
                } else {
                    if ((input[0]) <= (6.95)) {
                        if ((input[2]) <= (4.75)) {
                            memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                        } else {
                            if ((input[0]) <= (6.5)) {
                                memcpy(var16, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                            } else {
                                memcpy(var16, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                            }
                        }
                    } else {
                        memcpy(var16, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    }
                }
            } else {
                memcpy(var16, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            memcpy(var16, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
        }
    }
    mul_vector_number(var16, 0.1, 3, var15);
    add_vectors(var7, var15, 3, var6);
    double var17[3];
    double var18[3];
    if ((input[3]) <= (0.8)) {
        memcpy(var18, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if ((input[3]) <= (1.6500001)) {
            if ((input[2]) <= (4.9)) {
                memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            } else {
                memcpy(var18, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            if ((input[3]) <= (1.75)) {
                if ((input[2]) <= (4.75)) {
                    memcpy(var18, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var18, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                memcpy(var18, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        }
    }
    mul_vector_number(var18, 0.1, 3, var17);
    add_vectors(var6, var17, 3, var5);
    double var19[3];
    double var20[3];
    if ((input[3]) <= (0.75)) {
        memcpy(var20, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if ((input[2]) <= (4.9)) {
            if ((input[0]) <= (5.05)) {
                memcpy(var20, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                if ((input[3]) <= (1.7)) {
                    memcpy(var20, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var20, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        } else {
            if ((input[2]) <= (5.05)) {
                if ((input[1]) <= (2.75)) {
                    memcpy(var20, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var20, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                if ((input[0]) <= (6.05)) {
                    if ((input[0]) <= (5.9)) {
                        memcpy(var20, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var20, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var20, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    }
    mul_vector_number(var20, 0.1, 3, var19);
    add_vectors(var5, var19, 3, var4);
    double var21[3];
    double var22[3];
    if ((input[3]) <= (0.7)) {
        memcpy(var22, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if ((input[2]) <= (4.75)) {
            if ((input[0]) <= (4.95)) {
                if ((input[3]) <= (1.35)) {
                    memcpy(var22, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var22, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            } else {
                memcpy(var22, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            if ((input[3]) <= (1.45)) {
                if ((input[0]) <= (6.45)) {
                    memcpy(var22, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var22, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                if ((input[3]) <= (1.75)) {
                    if ((input[3]) <= (1.6500001)) {
                        memcpy(var22, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var22, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var22, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    }
    mul_vector_number(var22, 0.1, 3, var21);
    add_vectors(var4, var21, 3, var3);
    double var23[3];
    double var24[3];
    if ((input[2]) <= (2.7)) {
        memcpy(var24, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if ((input[2]) <= (4.8500004)) {
            memcpy(var24, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
        } else {
            if ((input[2]) <= (5.05)) {
                if ((input[3]) <= (1.75)) {
                    memcpy(var24, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var24, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            } else {
                memcpy(var24, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        }
    }
    mul_vector_number(var24, 0.1, 3, var23);
    add_vectors(var3, var23, 3, var2);
    double var25[3];
    double var26[3];
    if ((input[3]) <= (0.8)) {
        memcpy(var26, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if ((input[0]) <= (6.1499996)) {
            if ((input[2]) <= (4.8)) {
                if ((input[0]) <= (4.95)) {
                    memcpy(var26, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                } else {
                    memcpy(var26, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                }
            } else {
                memcpy(var26, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        } else {
            if ((input[0]) <= (6.8500004)) {
                if ((input[2]) <= (4.9)) {
                    if ((input[0]) <= (6.25)) {
                        if ((input[1]) <= (2.85)) {
                            memcpy(var26, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                        } else {
                            memcpy(var26, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                        }
                    } else {
                        memcpy(var26, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var26, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            } else {
                memcpy(var26, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            }
        }
    }
    mul_vector_number(var26, 0.1, 3, var25);
    add_vectors(var2, var25, 3, var1);
    double var27[3];
    double var28[3];
    if ((input[2]) <= (2.6)) {
        memcpy(var28, (double[]){1.0, 0.0, 0.0}, 3 * sizeof(double));
    } else {
        if ((input[2]) <= (4.75)) {
            if ((input[0]) <= (4.95)) {
                if ((input[3]) <= (1.35)) {
                    memcpy(var28, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                } else {
                    memcpy(var28, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            } else {
                memcpy(var28, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
            }
        } else {
            if ((input[0]) <= (6.55)) {
                memcpy(var28, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
            } else {
                if ((input[0]) <= (6.75)) {
                    if ((input[2]) <= (5.1)) {
                        memcpy(var28, (double[]){0.0, 1.0, 0.0}, 3 * sizeof(double));
                    } else {
                        memcpy(var28, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                    }
                } else {
                    memcpy(var28, (double[]){0.0, 0.0, 1.0}, 3 * sizeof(double));
                }
            }
        }
    }
    mul_vector_number(var28, 0.1, 3, var27);
    add_vectors(var1, var27, 3, var0);
    memcpy(output, var0, 3 * sizeof(double));
}

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