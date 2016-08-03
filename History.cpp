//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "History.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int __fastcall Log(AnsiString text)
{
 AnsiString DateTime = Date().CurrentDateTime();

 if (!FileExists("Log.txt"))
 {
  TStringList * LogFile = new TStringList;
  LogFile->Add(DateTime+": Создание Log.txt");
  LogFile->SaveToFile("Log.txt");
  delete LogFile;
 }

 Form3->Memo1->Lines->LoadFromFile("Log.txt");

 AnsiString text_code = text;
 if(text_code.Delete(4,text_code.Length())=="123")
 {
	text = text.Delete(1,3);
	Form3->Memo1->Lines->Add("");
	Form3->Memo1->Lines->Add(text);
 }
 else
 {

	Form3->Memo1->Lines->Add(DateTime+": "+text);
 }
 Form3->Memo1->Lines->SaveToFile("Log.txt");
}
//---------------------------------------------------------------------------
void __fastcall TForm3::Button1Click(TObject *Sender)
{
 if(Application->MessageBox(L"Вы действительно хотите очистить всю историю?",
						 L"Очистка истории",
						 MB_YESNO) < 7)
 {
  Memo1->Clear();
  Memo1->Lines->SaveToFile("Log.txt");
 }
}
//---------------------------------------------------------------------------

