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
//static const unsigned int bits_per_byte  = CHAR_BIT; //CHAR_BIT value is 8
//maximum number of bits in this hamming implementation is:
//static const unsigned int max_no_bits = bits_per_byte * sizeof(long);
//long  is 4 bytes ; 4 * 8 = 32
/*int getMinBits(long val){
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
D:\nitk\nitkprog\hamming.cppunsigned int  m = 0;
 while(pow(2, m) <= k+ m+ 1) //hamming code condition; refer text book
    m++;
 return m;
} //the above function gives the no of parity bits required
//bin_val_of_idx(int k){}
//int hamming(long val){*/
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

//}
//int main(){
    /*long val;
    long result;
    cout<<"Enter the Data in integer type: ";
    cin>>val;*/
    //result = hamming(val); //data can never be negative in real time
    //cout<<"The hamming encoding is: "<<result<<endl;
    return 0;
//}
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







 //main func  //(7,4 === n, k)
//    int n, k, m;
  //  cout<<"Enter No of parity Bits: "<<endl;
   // cin>>m; // m = n-k; for pairity bits
   //  n  =  pow(2, m) - 1; //codeword length
    // cout<<n<<endl; // n = 7
    // k = pow(2, m) - m -1; //data bits length
    // dmin = 3, t =1 t is err correcting capability
    //encode(n, k, m);
    //cout<<"Max size for data here is:";
    //int maxsize_ = 8 * sizeof(long);
    //cout<<maxsize_<<"  OUTput ";
    //cout<<"Max size for data here is:";
     //maxsize_ = 8 * sizeof(long);
    //cout<<maxsize_<<"  yay ";


/* void encode(int op, int ip, int pp){
        bool G[ip][op];
        bool C[op], D[ip], P[pp];
        int i, j = 2, k = 1;
        int pd = pp + ip;


        cout<<"Enter Data Bits (4 bin nos): "<<endl;
        for(int q = 0; q < ip; q++){
             cin>>D[q];
        }


        for(int p = 0; p< pp; p++){
            P[p] = 0;
        }


        bool parityData[pd];
        parityData[k] = 0;
        k = 2;
        for(i = 2; i<= pd; i++){
            int Y = log2(i);
            if(Y % 2  == 0 || log2(i) == 1 ){
                parityData[k] = P[j];
                j++;
                k++;
            }
            else{
                parityData[k] = D[j];
                j++;
                k++;
            }
        }
        cout<<"data Bits array: "<<endl;
        for(int x = 0; x < ip; x++){
            cout<<D[x]<<" ";
        }

        cout<<"Parity Bits array: "<<endl;
        for(int y = 0; y < pp; y++){
            cout<<P[y]<<" ";
        }
        cout<<"Data Parity array: "<<endl;
        for(int z = 1; z <= pd; z++){
            cout<<parityData[z]<<" ";
        }

}*/
