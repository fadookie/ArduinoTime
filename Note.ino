/*
#include "Note.h"

const int SAMPLE_RATE = 16 * 1024; // ~16KHz
const int SECONDS = 2;
const unsigned int sinArraySize = 32767; //SECONDS * SAMPLE_RATE (-1 for compiler limit)
 //const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062;

double note(enum Note ordinal) {
  if (ordinal > 0) {
      double exp = ((double) ordinal - 1) / (double)12.0;
      double f = (double)440.0 * pow((double)2.0, exp);
      return f;
  }
  return 0;
}

 */

/*
byte * sinArrayFromNote(int ordinal) {
  byte sinArray[sinArraySize]; 
  int n = ordinal;
  if (n > 0) {
      double exp = ((double) n - 1) / (double)12.0;
      double f = (double)440.0 * pow((double)2.0, exp);
      for (int i = 0; i < sinArraySize; i++) {
          double period = (double)SAMPLE_RATE / f;
          double angle = 2.0 * PI * i / period;
          sinArray[i] = (byte)(sin(angle) * 127.0);
      }
  }
  return &sinArray[0];
}
*/
