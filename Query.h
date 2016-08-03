//---------------------------------------------------------------------------

#ifndef QueryH
#define QueryH
int __fastcall SQL_Connect(void);
int __fastcall SQL_Query(AnsiString query, AnsiString Table_name);
int __fastcall SQL_Connect_Close(void);
//---------------------------------------------------------------------------
#endif
