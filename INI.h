//---------------------------------------------------------------------------

#ifndef INIH
#define INIH
#include <Classes.hpp>
AnsiString __fastcall INI_load(AnsiString Section,
						AnsiString Name);
AnsiString __fastcall INI_save(AnsiString Section,
						AnsiString Name,
						AnsiString Value);
//---------------------------------------------------------------------------
#endif
