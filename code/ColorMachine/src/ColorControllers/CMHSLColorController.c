//
//#include "CMColorController.h"
//
//#include "../CMColorMachineApplication.h"
//#include "../CMDesign.h"
//#include "../CMTranslations.h"
//#include "Displays/CMColorWell1D.h"
//#include "Displays/CMColorWell2D.h"
//#include "CMHSLColorController.h"
//
//#include "NAApp.h"
//
//struct CMHSLColorController{
//  CMColorController baseController;
//  
//  CMColorWell2D* colorWell2D;
//  
//  NASpace* channelSpace;
//  NALabel* labelH;
//  NALabel* labelS;
//  NALabel* labelL;
//  NATextField* textFieldH;
//  NATextField* textFieldS;
//  NATextField* textFieldL;
//  CMColorWell1D* colorWell1DH;
//  CMColorWell1D* colorWell1DS;
//  CMColorWell1D* colorWell1DL;
//
//  CMLVec3 hslColor;
//};
//
//
//
//NABool cmHSLValueEdited(NAReaction reaction){
//  CMHSLColorController* con = (CMHSLColorController*)reaction.controller;
//  
//  if(reaction.uiElement == con->textFieldH){
//    con->hslColor[0] = (float)naGetTextFieldDouble(con->textFieldH);
//  }else if(reaction.uiElement == con->textFieldS){
//    con->hslColor[1] = (float)naGetTextFieldDouble(con->textFieldS);
//  }else if(reaction.uiElement == con->textFieldL){
//    con->hslColor[2] = (float)naGetTextFieldDouble(con->textFieldL);
//  }
//  
//  cmSetCurrentColorController(&(con->baseController));
//  cmUpdateColor();
//  
//  return NA_TRUE;
//}
//
//
//CMHSLColorController* cmAllocHSLColorController(void){
//  CMHSLColorController* con = naAlloc(CMHSLColorController);
//  
//  cmInitColorController(&(con->baseController), CML_COLOR_HSL);
//  
//  con->colorWell2D = cmAllocColorWell2D(&(con->baseController), 2);
//  
//  con->channelSpace = naNewSpace(naMakeSize(1, 1));
//  con->labelH = cmNewColorComponentLabel(cmTranslate(CMHSLColorChannelH));
//  con->labelS = cmNewColorComponentLabel(cmTranslate(CMHSLColorChannelS));
//  con->labelL = cmNewColorComponentLabel(cmTranslate(CMHSLColorChannelL));
//  con->textFieldH = cmNewValueTextField(cmHSLValueEdited, con);
//  con->textFieldS = cmNewValueTextField(cmHSLValueEdited, con);
//  con->textFieldL = cmNewValueTextField(cmHSLValueEdited, con);
//  con->colorWell1DH = cmAllocColorWell1D(&(con->baseController), con->hslColor, 0);
//  con->colorWell1DS = cmAllocColorWell1D(&(con->baseController), con->hslColor, 1);
//  con->colorWell1DL = cmAllocColorWell1D(&(con->baseController), con->hslColor, 2);
//  
//  naSetUIElementNextTabElement(con->textFieldH, con->textFieldS);
//  naSetUIElementNextTabElement(con->textFieldS, con->textFieldL);
//  naSetUIElementNextTabElement(con->textFieldL, con->textFieldH);
//
//  cmBeginUILayout(con->channelSpace, naMakeBezel4Zero());
//  cmAddUIPos(0, (int)((colorWell2DSize - (3 * 25.)) / 2.)); // center the channels
//  cmAddUIRow(con->labelH, colorValueCondensedRowHeight);
//  cmAddUICol(con->textFieldH, colorComponentMarginH);
//  cmAddUIColV(cmGetColorWell1DUIElement(con->colorWell1DH), 10, colorWell1DOffset);
//  cmAddUIRow(con->labelS, colorValueCondensedRowHeight);
//  cmAddUICol(con->textFieldS, colorComponentMarginH);
//  cmAddUIColV(cmGetColorWell1DUIElement(con->colorWell1DS), 10, colorWell1DOffset);
//  cmAddUIRow(con->labelL, colorValueCondensedRowHeight);
//  cmAddUICol(con->textFieldL, colorComponentMarginH);
//  cmAddUIColV(cmGetColorWell1DUIElement(con->colorWell1DL), 10, colorWell1DOffset);
//  cmAddUIPos(0, colorValueCondensedRowHeight);
//  cmEndUILayout();
//  
//  cmBeginUILayout(con->baseController.space, colorWellBezel);
//  cmAddUIRow(cmGetColorWell2DUIElement(con->colorWell2D), 0);
//  cmAddUICol(con->channelSpace, 10);
//  cmEndUILayout();
//
//  return con;
//}
//
//
//
//void cmDeallocHSLColorController(CMHSLColorController* con){
//  cmDeallocColorWell2D(con->colorWell2D);
//  cmDeallocColorWell1D(con->colorWell1DH);
//  cmDeallocColorWell1D(con->colorWell1DS);
//  cmDeallocColorWell1D(con->colorWell1DL);
//  cmClearColorController(&(con->baseController));
//  naFree(con);
//}
//
//
//
//const void* cmGetHSLColorControllerColorData(const CMHSLColorController* con){
//  return &(con->hslColor);
//}
//
//
//
//void cmSetHSLColorControllerColorData(CMHSLColorController* con, const void* data){
//  cmlCpy3(con->hslColor, data);
//}
//
//
//
//void cmUpdateHSLColorController(CMHSLColorController* con){
//  cmUpdateColorController(&(con->baseController));
//  
//  CMLColorMachine* cm = cmGetCurrentColorMachine();
//  CMLColorType currentColorType = cmGetCurrentColorType();
//  const float* currentColorData = cmGetCurrentColorData();
//  CMLColorConverter converter = cmlGetColorConverter(CML_COLOR_HSL, currentColorType);
//  converter(cm, con->hslColor, currentColorData, 1);
//  
//  cmUpdateColorWell2D(con->colorWell2D);
//  
//  naSetTextFieldText(
//    con->textFieldH,
//    naAllocSprintf(NA_TRUE, "%3.03f", con->hslColor[0]));
//  naSetTextFieldText(
//    con->textFieldS,
//    naAllocSprintf(NA_TRUE, "%1.05f", con->hslColor[1]));
//  naSetTextFieldText(
//    con->textFieldL,
//    naAllocSprintf(NA_TRUE, "%1.05f", con->hslColor[2]));
//
//  cmUpdateColorWell1D(con->colorWell1DH);
//  cmUpdateColorWell1D(con->colorWell1DS);
//  cmUpdateColorWell1D(con->colorWell1DL);
//}
