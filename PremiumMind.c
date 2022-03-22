#include <stdlib.h>
#include <stdio.h>

unsigned char string [100000001];
void CompareString(char letter,int *k);
void Read();

int main(){
    Read();
    return 0;
}

void CompareString(char letter,int *k){
    if((string[(*k) - 1] - letter == 17) || (string[(*k) - 1] - letter == -17)){
        string[(*k)--] = '\0';
        return;
    }
    if((string[(*k) - 1] - letter == 4) || (string[(*k) - 1] - letter == -4)){
        string[(*k)--] = '\0';
        return;
    }
    string[(*k)++] = letter;
}

void Read(){
    int number_of_letters;
    char letter;
    int aux = 0;
    int i = 0;
    int k = 0;
    char number[9];
    while (letter != '\n'){
        letter = getc(stdin);
        if(aux == 0){
            if(letter != '\n' && letter != 'A' && letter != 'F' && letter != 'W' && letter !='E'){
                number[i] = letter;
            }else{
                number_of_letters = atoi(number);
                if(number_of_letters == 0){
                    exit(0);
                }
                aux = 1;
                string[k++] = letter;
            }
        }else{
            if(number_of_letters >= 0){
                if(k == 0){
                    string[k++] = letter;
                }else
                    CompareString(letter,&k);
                number_of_letters--;
            }
        }
        i++;
    }
    printf("%s",string);
}


