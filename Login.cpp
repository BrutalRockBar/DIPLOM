//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login.h"
#include "Query.h"
#include "INI.h"
#include "History.h"
#include "Global_Form.h"
#include "Table.h"
#include "PacView.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
extern Users Users[100000];
int good = 0;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm6::CheckBox1Click(TObject *Sender)
{
 if(CheckBox1->Checked == true)Edit2->PasswordChar = 0;
 else Edit2->PasswordChar = '*';
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Edit1Change(TObject *Sender)
{
Log("123Проверка Login");
 if(SQL_Connect() > 0)
 {
  AnsiString query = "SELECT * FROM `"	+INI_load("Database","DBase1")
										+"`.`Users`WHERE `Login` LIKE '"
										+Edit1->Text+"'";
  int count = SQL_Query(query,"Users");
  if(count != 0)
  {
   Label1->Font->Color = clGreen;
   Log("ОК!");
  }
  else
  {
   Label1->Font->Color = clRed;
   Log("Не верный логин");
  }
  SQL_Connect_Close();
 }
 else
 {
  ShowMessage("Не удалось подключиться к серверу!");
  Log("Подключение с сервером отсутствует!");
  Form1->Offline();
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Edit2Change(TObject *Sender)
{
Log("123Проверка пароля");
if(SQL_Connect() > 0)
 {
  AnsiString query = "SELECT * FROM `"	+INI_load("Database","DBase1")
										+"`.`Users`WHERE `Login` LIKE '"
										+Edit1->Text+"' AND `Password` LIKE '"
										+Edit2->Text+"'";
  int count = SQL_Query(query,"Users");
  if(count != 0)
  {
   Label2->Font->Color = clGreen;
   good = 1;
   Log("ОК!");
  }
  else
  {
   Label2->Font->Color = clRed;
   good = 0;
   Log("Не верный пароль");
  }
  SQL_Connect_Close();
 }
 else
 {
  ShowMessage("Не удалось подключиться к серверу!");
  Log("Подключение с сервером отсутствует!");
  Form1->Offline();
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button2Click(TObject *Sender)
{
 Edit1->Clear();
 Edit2->Clear();
 Form6->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Button1Click(TObject *Sender)
{
 if(good > 0 && Form1->Online() > 0)
 {
  Form1->TabUpdate("");
  Form1->PageControl1->SelectNextPage(1,1);
  Form1->Caption = "Солигорский психоневрологический диспансер("+Edit1->Text+")";
  //Admin config
  if(Users[0].level > 1)
  {
	Form1->N2->Visible = true;
	Form1->N9->Visible = true;
	Form1->N10->Visible = true;
	Form4->Button2->Visible = true;
	Form4->Button4->Visible = true;
  }
  else
  {
	Form1->N2->Visible = false;
	Form1->N9->Visible = false;
	Form4->Button2->Visible = false;
	Form4->Button4->Visible = false;
	Form1->N10->Visible = true;
  }

  Form1->Focused();
  Form6->Close();
 }
 else ShowMessage("Не верно указаны данные!");
}
//---------------------------------------------------------------------------

void __fastcall TForm6::FormShow(TObject *Sender)
{
 Form1->Form_Shadow(1);
 if(Edit1->Text !="" || Edit2->Text !="" )
 {
  Edit1->Clear(); Label1->Font->Color = clBtnText;
  Edit2->Clear(); Label2->Font->Color = clBtnText;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm6::FormClose(TObject *Sender, TCloseAction &Action)
{
 Form1->Form_Shadow(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm6::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
 if(Key == VK_RETURN) Button1Click(Button1);
}
//---------------------------------------------------------------------------
