//---------------------------------------------------------------------------

#pragma hdrstop

#include "INI.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)


AnsiString __fastcall INI_load(	AnsiString Section,
								AnsiString Name)
{
 AnsiString result;
 TIniFile *ini = new TIniFile(GetCurrentDir() + "\\Config.ini");

  result = ini->ReadString(Section,Name,0);

  delete ini;
  return(result);
}


AnsiString __fastcall INI_save(	AnsiString Section,
								AnsiString Name,
								AnsiString Value)
{
 TIniFile *ini = new TIniFile(GetCurrentDir() + "\\Config.ini");

 ini->WriteString(Section,Name,Value);

 delete ini;
}