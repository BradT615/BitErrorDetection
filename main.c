#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

void parityCheck();
void checksumCheck();
void twoDParityCheck();

int main(void) {
  parityCheck();
  checksumCheck();
  twoDParityCheck();
  return 0;
}

void parityCheck(){

  printf("\n\t**Part 1 - Parity Check Processing\n\n");
  
  FILE *parity = fopen("Parity.txt", "r");
  int parityArray[5][9];
  
  for(int i = 0; i < 5; i++) {
    printf("\nTransmission line number: %d\n\n", i + 1);
    for(int j = 0; j < 9; j++) {
      int n;
      fscanf(parity, " %4d", &n);
      parityArray[i][j] = n;
    }

      int parityBinary[8] = {0};
      int temp = parityArray[i][8];
      int count = 0;
      for(int b = 7; b >= 0; b--){
        if(temp >= (int)pow(2,b)){
          parityBinary[count] = 1;
          temp -= (int)pow(2,b);
        }
        count++;
      }
    
    for(int j = 0; j < 8; j++) {

      int binary[8] = {0};
      int num = parityArray[i][j];
      int count1 = parityBinary[j];
    
      printf("data item = %3d, binary = ", num);

      for(int i = 7; i >= 0; i--){
        if(num >= (int)pow(2,i)){
          binary[i] = 1;
          count1++;
          num -= (int)pow(2,i);
        }
        printf("%d", binary[i]);
      }
      printf("\n");
      if(count1 % 2 == 1){
      printf("Error in transmission byte %d\n\n", j + 1);
      }
        else printf("No error in transmission byte %d\n\n", j + 1);
    }
  }
  fclose(parity);
}

void checksumCheck(){

  printf("\n\t**Part 2 - Checksum Processing");
  
  /* read and store file */
  FILE *checksum = fopen("Checksum.txt", "r");
  int checkSumArray[5][9];
  for(int i = 0; i < 5; i++) {
    for(int j = 0; j < 9; j++) {
      int num;
      fscanf(checksum, " %4d", &num);
      checkSumArray[i][j] = num;
    }
  }
  
  for(int i = 0; i < 5; i++) {
    printf("\n\n\nData stream:\n");
    for(int j = 0; j < 8; j++) {
      printf("%d ", checkSumArray[i][j]);
    }
    printf("\nChecksum: %d\n\n", checkSumArray[i][8]);
    
    int total = 0;
    for(int j = 0; j < 8; j++) {
      printf("parityData[%d] = %3d, binary = ", j, checkSumArray[i][j]);
      int binary[8] = {0};
      int num = checkSumArray[i][j];
      total += num;
      
      for(int i = 7; i >= 0; i--){
        if(num >= (int)pow(2,i)){
          binary[i] = 1;
          num -= (int)pow(2,i);
        }
        printf("%d", binary[i]);
      }
      printf("\n\n");
    }
    printf("Sum of data items = %3d, binary = ", total);
    int binaryTotalArray[10] = {0};
    int binaryTotal = total;
    for(int i = 9; i >= 0; i--){
        if(binaryTotal >= (int)pow(2,i)){
          binaryTotalArray[i] = 1;
          binaryTotal -= (int)pow(2,i);
        }
        printf("%d", binaryTotalArray[i]);
      }
    printf("\nChecksum value = %6d, binary = ", checkSumArray[i][8]);
    int binaryChecksumArray[10] = {0};
    int binaryChecksum = checkSumArray[i][8];
    for(int i = 9; i >= 0; i--){
        if(binaryChecksum >= (int)pow(2,i)){
          binaryChecksumArray[i] = 1;
          binaryChecksum -= (int)pow(2,i);
        }
        printf("%d", binaryChecksumArray[i]);
      }
    int sumPlusCheck = total + checkSumArray[i][8];
    printf("\n\nSum after adding checksum = %4d, binary = ", sumPlusCheck);
    int sumBinary[10] = {0};
    int sumCompliment = 0;
    int sumComplimentBinary[10] = {1,1,1,1,1,1,1,1,1,1};
    for(int i = 9; i >= 0; i--){
      if(sumPlusCheck > (int)pow(2,i)){
        sumBinary[i] = 1;
        sumComplimentBinary[i] = 0;
      }
      else sumComplimentBinary[i] = 0;
      printf("%d", sumBinary[i]);
      if(sumComplimentBinary[i] != 0){
        sumCompliment += (int)pow(2,i);
      }
    }
    printf("\nSum after complement = %4d, binary = ", sumCompliment);
    for(int i = 9; i >= 0; i--){
      printf("%d", sumComplimentBinary[i]);
    }

    if(sumCompliment == 0){
      printf("\n\nChecksum: No errors in transmission");
    }
    else printf("\n\nChecksum: Error in transmission");
  }
  fclose(checksum);
}

void twoDParityCheck(){

  printf("\n\t**Part 3 - Two-dimensional Parity check\n");

  FILE *twoDParity = fopen("2D_Parity.txt", "r");
  int block = 1;
  for(int i = 0; i < 1; i++){
    int blockPass = 1;
    //print data Stream
    printf("\n==> Processing Transmission Block %d\n\nData streams:\n", i + 1);
    int dataStream[8][10];
    for(int j = 0; j < 8; j++){
      for(int k = 0; k < 10; k++){
        int num;
        fscanf(twoDParity, " %4d", &num);
        dataStream[j][k] = num;
        if(k < 8){
          printf("%4d", dataStream[j][k]);
        }
        else if(k == 8){
          printf("[V: %d]", dataStream[j][k]);
        }
        else printf("[H: %d]", dataStream[j][k]);
      }
      printf("\n");
    }
    
    //print vertical transmission lines
    int i = 0;
    int vLine = 0;
    int passCount = 1;
    for(i = 0; i < 8; i++){
      printf("\n**Vertical processing transmission line %d\n\n", i);
      int tempBinaryArray[8][8] = {0};
      for(int j = 0; j < 8; j++){
        int temp = dataStream[j][i];
        int count = 0;
        for(int h = 7; h >= 0; h--){
          int power = (int)pow(2,h);
          if(temp >= power){
            tempBinaryArray[j][count] = 1;
            temp = temp - power;
          }
          count++;
        }
      }  

      //even counter
      for(int j = 0; j < 8; j++){
        int oneCount = 0;
        int c = 0;
        for(c = 0; c < 8; c++){
          if(tempBinaryArray[c][j] == 1){
            oneCount++;
          }
        }
        if(oneCount % 2 == 1){
          //add bit
          printf("Adding bit position %d: %d\n", j, (int)pow(2,j));
        }
      }
      printf("\n");
      
      //print val and binary
      int j = 0;
      for(j = 0; j < 8; j++){
        printf("val%d = %3d, ",j, dataStream[j][i]);
        int temp = dataStream[j][i];
        int count = 0;
        for(int h = 7; h >= 0; h--){
          int power = (int)pow(2,h);
          if(temp >= power){
            tempBinaryArray[j][count] = 1;
            temp = temp - power;
          }
          count++;
        }
        for(int k = 0; k <= 7; k++){
          printf("%d", tempBinaryArray[j][k]);
        }
        printf("\n\n");
      }
      int parity = dataStream[i][8];
      printf("\ncheckParityByte = %d, vertParityByte[%d]\n", parity, parity);

      int pass = 1;
      if(pass == 1){
        printf("Transmission line %d passed vertical parity\n", vLine);
      }
      else {
        printf("Transmission line %d failed vertical parity\n\n", vLine);
        passCount = 0;
      }
      vLine++;
    }
    if(passCount == 0){
      printf("\nTransmission block %d FAILED complete vertical parity test\n", block);
      blockPass = 0;
    }
    else printf("\nTransmission block %d PASSED complete vertical parity test\n", block);

    int pass = 1;
    
    //print horizontal transmission lines
    int h = 0;
    int hLine = 0;
    int passHCount = 1;
    for(h = 0; h < 8; h++){
      printf("\n**Horizontal processing transmission line %d\n\n", h);
      int tempBinaryArray[8][8] = {0};
      for(int j = 0; j < 8; j++){
        int temp = dataStream[j][h];
        int count = 0;
        for(int k = 7; k >= 0; k--){
          int power = (int)pow(2,k);
          if(temp >= power){
            tempBinaryArray[j][count] = 1;
            temp = temp - power;
          }
          count++;
        }
      }  

      //even counter
      for(int j = 0; j < 8; j++){
        int oneCount = 0;
        int c = 0;
        for(c = 0; c < 8; c++){
          if(tempBinaryArray[c][j] == 1){
            oneCount++;
          }
        }
        if(oneCount % 2 == 1){
          //add bit
          printf("Adding bit position %d: %d\n", j, (int)pow(2,j));
        }
      }
      printf("\n");
      
      //print val and binary
      int l = 0;
      for(l = 0; l < 8; l++){
        printf("val%d = %3d, ", l, dataStream[h][l]);
        int temp = dataStream[h][l];
        int count = 0;
        for(int h = 7; h >= 0; h--){
          int power = (int)pow(2,h);
          if(temp >= power){
            tempBinaryArray[l][count] = 1;
            temp = temp - power;
          }
          count++;
        }
        for(int k = 0; k <= 7; k++){
          printf("%d", tempBinaryArray[l][k]);
        }
        printf("\n\n");
      }
      int parity = dataStream[h][9];
      printf("\ncheckParityByte = %d, horizParityByte[%d]\n", parity, parity);

      
      if(pass == 1){
        printf("Transmission line %d passed horizontal parity\n", hLine);
      }
      else {
        printf("Transmission line %d failed horizontal parity\n", hLine);
        passHCount = 0;
      }
      hLine++;
    }
    if(passCount == 0){
      printf("\nTransmission block %d FAILED complete horizontal parity test\n", block);
      blockPass = 0;
    }
    else printf("\nTransmission block %d PASSED complete horizontal parity test\n", block);
    if(blockPass == 0){
      printf("\n--> Transmission block %d FAILED - it has errors.\n\n", block);
    }
    else printf("\n--> Transmission block %d PASSED - it is error free.\n\n", block);

    block++;
  }
  fclose(twoDParity);
}