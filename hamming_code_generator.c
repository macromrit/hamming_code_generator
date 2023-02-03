#include <stdio.h>

// hamming code generator -> its duty is to generate a seven bit code using a 4-bit message ensuring the rest 3 bits makes the final code unpredictable
// parity - tally of 1 bit registers in a given code
// parity bits are those which fill up 3-null-spaces which constructs the hamming code, user has to fill whether he want's an odd parity or wants' to settle with even(O-odd | E-even)
//
// intriguing fact is that, message bits and parity bits are not sequenced, they reside at different locations(reason traces roots to subjects of EEE.)

int main(){

    //final hamming code
    int generated_code[7];  
    //E-even | O-odd
    char parity_switch; 
    //parity indices in hamming code's array
    int parity_bit[] = {0, 1, 3};   
    //parity bit signifying indices
    int parity_bit_signifiers[][3] = {{2, 4, 6}, 
                                      {2, 5, 6}, 
                                      {4, 5, 6}};
    //me ssage indices in hamming code's array
    int message_bit[] = {2,4,5,6};

    //let user input whether he wants odd parity or the even one
    printf("Input the parity type you chose[odd/even](O/E)-> ");
    scanf("%c", &parity_switch);

    //aesthetic purposed stuff
    printf("\n");

    //traverse thru message indices' array for filling up message aisles/bits in the 7-bit hamming code
    printf("Input message bits as directed below->\n");
    for(int i=0; i<sizeof(message_bit)/sizeof(message_bit[0]); i++){
        //obtain input to fill i'th message bit
        printf("Enter message-bit(%i): ", i+1);
        scanf("%i", &generated_code[message_bit[i]]);
    }

    //aesthetic purposed stuff
    printf("\n");

    //considering the parity switch's input, gotta figure out parity bits p1|p2|p4
    for(int r=0; r<sizeof(parity_bit_signifiers)/sizeof(parity_bit_signifiers[0]); ++r){
        int total_val = 0;
        for(int c=0; c<sizeof(parity_bit_signifiers[0])/sizeof(parity_bit_signifiers[0][0]); ++c){
                total_val+=generated_code[parity_bit_signifiers[r][c]];
        }
        
        //matching bits to obtain user's preference and filling up then checking out p1 p2 p3 in hamming code
        if((parity_switch=='O' && !(total_val%2))||(parity_switch=='E' && (total_val%2))){
            generated_code[parity_bit[r]] = 1;
        }
        else{
            generated_code[parity_bit[r]] = 0;
        }
    }

    //printing out the final hamming code
    printf("The hamming code for given message input is: [");
    for(int k=0; k<sizeof(generated_code)/sizeof(generated_code[0]); ++k){
        if(k==sizeof(generated_code)/sizeof(generated_code[0])-1){
            printf("%i]", generated_code[k]);
        }
        else
            printf("%i | ", generated_code[k]);
        }   
}
