
#include "CMColorController.h"
#include "CMGrayColorController.h"
#include "CMHSLColorController.h"
#include "CMHSVHSLColorController.h"
#include "CMLabColorController.h"
#include "CMLuvUVWColorController.h"
#include "CMRGBColorController.h"
#include "CMSpectralColorController.h"
#include "CMUVWColorController.h"
#include "CMXYZColorController.h"
#include "CMYCbCrColorController.h"
#include "CMYcdColorController.h"
#include "CMYuvColorController.h"
#include "CMYxyColorController.h"
#include "NAApp.h"



NABool cmColorControllerMouseDown(NAReaction reaction){
  CMColorController* con = reaction.controller;
  
  cmSetCurrentColorController(con);
  
  return NA_TRUE;
}



void cmInitColorController(CMColorController* con, CMLColorType colorType){
  con->space = naNewSpace(naMakeSize(300, 100));
  //naAddUIReaction(con->space, NA_UI_COMMAND_MOUSE_DOWN, cmColorControllerMouseDown, con);
  
  con->active = NA_FALSE;
  con->colorType = colorType;
}



void cmClearColorController(CMColorController* con){
}



void cmSetColorControllerColorType(CMColorController* con, CMLColorType colorType){
  con->colorType = colorType;
}



void cmSetColorControllerActive(CMColorController* con, NABool active){
  con->active = active;
}



CMLColorType cmGetColorControllerColorType(const CMColorController* con){
  return con->colorType;
}



const void* cmGetColorControllerColorData(const CMColorController* con){
  switch(con->colorType){
  case CML_COLOR_Gray: return cmGetGrayColorControllerColorData((const CMGrayColorController*)con); 
  case CML_COLOR_HSL: return cmGetHSVHSLColorControllerColorData((const CMHSVHSLColorController*)con); 
  case CML_COLOR_HSV: return cmGetHSVHSLColorControllerColorData((const CMHSVHSLColorController*)con);
  case CML_COLOR_Lab: return cmGetLabColorControllerColorData((const CMLabColorController*)con);
  case CML_COLOR_Luv: return cmGetLuvUVWColorControllerColorData((const CMLuvUVWColorController*)con);
  case CML_COLOR_RGB: return cmGetRGBColorControllerColorData((const CMRGBColorController*)con);
  case CML_COLOR_SPECTRUM_ILLUMINATION: return cmGetSpectralColorControllerColorData((const CMSpectralColorController*)con);
  case CML_COLOR_UVW: return cmGetLuvUVWColorControllerColorData((const CMLuvUVWColorController*)con);
  case CML_COLOR_XYZ: return cmGetXYZColorControllerColorData((const CMXYZColorController*)con);
  case CML_COLOR_YCbCr: return cmGetYCbCrColorControllerColorData((const CMYCbCrColorController*)con);
  case CML_COLOR_Ycd: return cmGetYcdColorControllerColorData((const CMYcdColorController*)con);
  case CML_COLOR_Yupvp: return cmGetYuvColorControllerColorData((const CMYuvColorController*)con);
  case CML_COLOR_Yxy: return cmGetYxyColorControllerColorData((const CMYxyColorController*)con);
  default: return NA_NULL;
  }
}



void cmSetColorControllerColorData(CMColorController* con, const void* data){
  switch(con->colorType){
  case CML_COLOR_Gray: cmSetGrayColorControllerColorData((CMGrayColorController*)con, data); break; 
  case CML_COLOR_HSL: cmSetHSVHSLColorControllerColorData((CMHSVHSLColorController*)con, data); break; 
  case CML_COLOR_HSV: cmSetHSVHSLColorControllerColorData((CMHSVHSLColorController*)con, data); break;
  case CML_COLOR_Lab: cmSetLabColorControllerColorData((CMLabColorController*)con, data); break;
  case CML_COLOR_Luv: cmSetLuvUVWColorControllerColorData((CMLuvUVWColorController*)con, data); break;
  case CML_COLOR_RGB: cmSetRGBColorControllerColorData((CMRGBColorController*)con, data); break;
  case CML_COLOR_SPECTRUM_ILLUMINATION: cmSetSpectralColorControllerColorData((CMSpectralColorController*)con, data); break;
  case CML_COLOR_UVW: cmSetLuvUVWColorControllerColorData((CMLuvUVWColorController*)con, data); break;
  case CML_COLOR_XYZ: cmSetXYZColorControllerColorData((CMXYZColorController*)con, data); break;
  case CML_COLOR_YCbCr: cmSetYCbCrColorControllerColorData((CMYCbCrColorController*)con, data); break;
  case CML_COLOR_Ycd: cmSetYcdColorControllerColorData((CMYcdColorController*)con, data); break;
  case CML_COLOR_Yupvp: cmSetYuvColorControllerColorData((CMYuvColorController*)con, data); break;
  case CML_COLOR_Yxy: cmSetYxyColorControllerColorData((CMYxyColorController*)con, data); break;
  default: break;
  }
}



NASpace* cmGetColorControllerUIElement(CMColorController* con){
  return con->space;
}



void cmUpdateColorController(CMColorController* con){
  naSetSpaceAlternateBackground(con->space, con->active);
}
