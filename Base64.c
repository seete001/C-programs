#include<string.h>
#include<stdio.h>



int main(){



    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; //remove newline if present
    int mem = 0;
    char* mapping = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int counter  =0;

    for(int i = 0;i < strlen(input); i++){
    
        char c = input[i];
        for(int j = 0;j < 8; j++){
        
            int this_bit = (c & 128)>>7;
            mem = mem << 1;
            mem = mem | this_bit;
            counter++;
            c = c << 1;
            if(counter == 6){
                printf("%c", mapping[mem]);
                mem = 0;
                counter = 0;    
            } 
        }
    } 
    mem = mem << (6 - counter);
    switch (strlen(input) % 3){
    
        case 1:
            printf("%c==", mapping[mem]);
            break;
        case 2:
            printf("%c=", mapping[mem]);
            break;
    }






printf("\n");
return 0;
}
