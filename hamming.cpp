#include<bits/stdc++.h>
using namespace std;
int getMinBits(long val);
int getMinParityBits(unsigned int k);
//bits size is taken  as 8
static const unsigned int bits_per_byte  = CHAR_BIT;
static const unsigned int max_no_bits = bits_per_byte * sizeof(long);
int main(){
    long val;
    long result;
    cout<<"Enter the Data in integer type: ";
    cin>>val;

    unsigned int num_of_data_bits = getMinBits(val);
    unsigned int num_of_pairity_bits = getMinParityBits(num_of_data_bits);

    int total_bits = num_of_data_bits + num_of_pairity_bits;
    int hamming_arr[total_bits];
    for(int i = 0; i < total_bits; i++)
            hamming_arr[i] =0;
    for(int i = 0; i < num_of_pairity_bits; i++){
        int parity_indx = pow(2,i) - 1;
        hamming_arr[parity_indx]  = -1;
    }
    //place data bits into the hamming code
    int i = 0;
    int val_i = 0;
    while(i < total_bits){
        if(hamming_arr[i] != -1){
            int bitval = (val >> (num_of_data_bits - val_i -1)) & 1;
            hamming_arr[i] = bitval;
            val_i++;
        }
        i++;
    }

    for(int p = 0; p < num_of_pairity_bits; p++ ){
        int curbit = pow(2,p);
        int p_sum = 0;
        for(int i = curbit; i<= total_bits; i++){
            if(((i >> p) & 1) && i != curbit){
                    p_sum += hamming_arr[i - 1];
            }
        }
        hamming_arr[curbit - 1] = (p_sum % 2 == 0)? 0 : 1;
    }
for(int i = 0; i<total_bits; i++){
    cout<<hamming_arr[i]<<"  ";
}


    return 0;

}
int getMinBits(long val){
    if(val == 0){
        return 1;
        }
    else
    for(int i = max_no_bits - 1; i>=0; i--){
        if((val>>i) & 1){  //finding the Index of MSB; exact no of bits required is obtained
            return i + 1;
        }
    }
}
int getMinParityBits(unsigned int k){
 //k is no of data bits
unsigned int  m = 0;
 while(pow(2, m) <= k+ m+ 1) //hamming code condition; refer text book
    m++;
 return m;

}






