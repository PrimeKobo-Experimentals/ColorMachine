
#import "main.h"
#import "ColorMachineApplication.h"

#include "ColorMachineTranslations.h"

#include "ManderAppAbout.h"
#include "ManderAppTranslations.h"
#include "NAApp.h"

//#include "NAUtility/NAMemory.h"
//#include "NAStruct/NABuffer.h"
//
//int main(int argc, char *argv[]){
//  naStartRuntime();
//  NABuffer* readBuffer = naCreateBufferWithInputPath("/Users/stammt/Desktop/miniascii.raw");
//  NABufferIterator bufIter = naMakeBufferAccessor(readBuffer);
//  NABuffer* outBuffer = naCreateBuffer(NA_FALSE);
//  NABufferIterator outIter = naMakeBufferModifier(outBuffer);
//  
//  int byteCount = 0;
//  int bitCount = 0;
//  char outByte = 0;
//  while(!naIsBufferAtEnd(&bufIter)){
//    uint8 byte = naReadBufferu8(&bufIter);
//    byteCount += 1;
//    naIterateBuffer(&bufIter, 3);
//    byteCount += 3;
//    
//    outByte |= (1 - (byte / 255)) << (7 - bitCount);
//    bitCount++;
//    if(bitCount == 8){
//      naWriteBufferu8(&outIter, outByte);
//      outByte = 0;
//      bitCount = 0;
//    }
//  }
//  
//  int outByteCount = 0;
//  NABufferIterator printIter = naMakeBufferAccessor(outBuffer);
//  while(!naIsBufferAtEnd(&printIter)){
//    uint8 byte = naReadBufferu8(&printIter);
//    printf("0x%02x, ", (int)byte);
//    outByteCount++;
//    if(outByteCount == 10){
//      outByteCount = 0;
//      printf("\n");
//    }
//  }
//  
//  naClearBufferIterator(&printIter);
//  naClearBufferIterator(&outIter);
//  naClearBufferIterator(&bufIter);
//  naRelease(readBuffer);
//  naRelease(outBuffer);
//  naStopRuntime();
//  return 0;
//}

void preStartup(void* arg){
  // here come translations.
  mandInitManderAppTranslations();
  initTranslations();
}

void postStartup(void* arg){
  naLoadNib("ColorMachine", NA_NULL);
  
  // here come UI thingies.
  mandCreateAboutController();
  mandSetAboutDescriptionAndHelpURL(cmTranslate(ColorMachineApplicationDescription), cmTranslate(ColorMachineApplicationHelpURL));
}

int main(int argc, char *argv[]){
  naStartRuntime();
  [ColorMachineApplication sharedApplication];
  naStartApplication(preStartup, postStartup, NA_NULL);
  naStopRuntime();
  return 0;
}
