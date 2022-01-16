/**
 * @file task1.c
 * @author Mehmet Samet HAKUT (msamet.hakut@protonmail.com)
 * @brief This program reads a file named document.txt and writes the characters
 * and their occurance number in a file named output.dat
 * @version 0.1
 * @date 2021-12-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <stdio.h>


int main()
{
    FILE *file,*output; //  Create file pointer
    int character_count[25] = {0};  //  Initialize the number of characters

    /**
     * @brief Open file in read mode if couldn't open print file couldn't be opened
     * Otherwise, read the characters until the end of file and increase the character number
     * 
     */
    if((file = fopen("document.txt","r")) == NULL){
        puts("File couldn't be opened");
    }
    else{
        while(!feof(file)){
            //  fgetc() function reads the character and according to ascii table a starts from integer value 97
            //  Since we only have 25 elements in the array and only those are required we subtract 97 from the int value
            //  and increase the value of 0th indice element
            character_count[fgetc(file) - 97]++;
        }
    }
    /**
     * @brief We open the other file in write mode and if it could be opened
     * we write the output to the file
     * 
     */
    if((output = fopen("output.dat","w")) == NULL){
        puts("Couldn't create file");
    }
    else{
        fprintf(output,"Character\tCount\n");
        //  For all array elements we first print the char. Since we subtract 97 from every element we add it to the indice
        //  to print the correct char value and then we print the char count by printing that indice element
        for(int i = 0 ; i <= 25 ; i++){
            fprintf(output,"%c\t\t%d\n", i+97 ,character_count[i]);
        }
    }
    return 0;

}
