/****************************************  
* checkwriter.h
*
* These functions print out the words for various amounts through 100
*
****************************************/

/**************************************
*  Function prototypes                *
**************************************/
void writeOnes( int oner);
void writeTens( int tener);
void Teens( int number);

/**************************************  
*  Function definitions               *
**************************************/

/*
*  writeOnes takes an integer between one and ten and prints out,
*      without spaces, the English word for that number.         
*/

void
writeOnes( int oner) {
  switch (oner) {
    case 0: printf("zero"); break;
    case 1: printf("one"); break;
    case 2: printf("two"); break;
    case 3: printf("three"); break;
    case 4: printf("four"); break;
    case 5: printf("five"); break;
    case 6: printf("six"); break;
    case 7: printf("seven"); break;
    case 8: printf("eight"); break;
    case 9: printf("nine"); break;
    default: printf(" Bad input to funtion writeOnes, try again\n");
  }
}

/*
*  writeTens takes in a number between 1 and 99 and prints out the
*    English word for the number without spaces.
*/

void
writeTens( int tener) {
  int tplace, oplace; 

  if(( tener >= 100 ) || ( tener < 0)) {
    printf(" Bad input to function writeTens, try again\n");
    return;
  }
  if( tener < 10) {
    writeOnes( tener);
    return;
  }
  if( tener < 20) {
    Teens( tener);
    return;
  }
  tplace = tener / 10;
  switch (tplace) {
    case 2: printf("twenty"); break;
    case 3: printf("thirty"); break;
    case 4: printf("fourty"); break;
    case 5: printf("fifty"); break;
    case 6: printf("sixty"); break;
    case 7: printf("seventy"); break;
    case 8: printf("eighty"); break;
    case 9: printf("ninety"); break;
  } 
  oplace = tener % 10;
  if( oplace) {
    printf(" ");
    writeOnes( oplace);
  }
  return;
}

void Teens( int number) {
  switch (number) {
    case 10: printf("ten"); break;
    case 11: printf("eleven"); break;
    case 12: printf("twelve"); break;
    case 13: printf("thirteen"); break;
    case 14: printf("fourteen"); break;
    case 15: printf("fifteen"); break;
    case 16: printf("sixteen"); break;
    case 17: printf("seventeen"); break;
    case 18: printf("eighteen"); break;
    case 19: printf("nineteen"); break;
  }
}


  
