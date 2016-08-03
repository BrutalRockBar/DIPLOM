//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Global_Form.h"
#include "Settings.h"
#include "INI.h"
#include "Query.h"
#include "History.h"
#include "Report.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
AnsiString Style_name;
extern On;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormShow(TObject *Sender)
{
 Edit1->Text = INI_load("MySQL","IP");
 Edit2->Text = INI_load("MySQL","Port");
 Edit3->Text = INI_load("MySQL","Login");
 Edit4->Text = INI_load("MySQL","Password");
 Edit5->Text = INI_load("Database","DBase1");
 Edit6->Text = INI_load("Database","Table");
 Style_name = INI_load("Styles","Style_name");
 if(INI_load("ReportSendMail","On") == 1) CheckBox1->Checked = true;
 else CheckBox1->Checked = false;
 Edit7->Text = INI_load("ReportSendMail","server");
 Edit9->Text = INI_load("ReportSendMail","port");
 Edit10->Text = INI_load("ReportSendMail","mail");
 Edit11->Text = INI_load("ReportSendMail","pass");
 Edit12->Text = INI_load("ReportSendMail","mail_send");
 if(INI_load("ReportSendMail","RB") == 1) RadioButton1->Checked = true;
 else RadioButton2->Checked = true;
 Edit8->Text = INI_load("ReportSendMail","Time1");
 Label9->Caption = INI_load("ReportSendMail","Time2");
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
 INI_save("MySQL","IP",Edit1->Text);
 INI_save("MySQL","Login",Edit3->Text);
 INI_save("MySQL","Password",Edit4->Text);
 INI_save("MySQL","Port",Edit2->Text);
 INI_save("Database","DBase1",Edit5->Text);
 INI_save("Database","Table",Edit6->Text);
 if(ListBox1->ItemIndex > 0)
 {
  INI_save("Styles","Style_name",ListBox1->Items->Strings[ListBox1->ItemIndex]);
 }

 INI_save("ReportSendMail","server",Edit7->Text);
 INI_save("ReportSendMail","port",Edit9->Text);
 INI_save("ReportSendMail","mail",Edit10->Text);
 INI_save("ReportSendMail","pass",Edit11->Text);
 INI_save("ReportSendMail","mail_send",Edit12->Text);

 if(RadioButton1->Checked == true) INI_save("ReportSendMail","RB","1");
 else INI_save("ReportSendMail","RB","2");


 INI_save("ReportSendMail","Time1",Edit8->Text);
 INI_save("ReportSendMail","Time2",Label9->Caption);

 Form8->Timer1->Interval = StrToInt(INI_load("ReportSendMail","Time1"))*60000;

 if(CheckBox1->Checked == true)
 {
  INI_save("ReportSendMail","On","1");
  if(On == 1)
  {
	  if(INI_load("ReportSendMail","RB") == "1")
	  {
	   Form1->Timer1->Enabled = false;
	   Form8->Timer1->Enabled = true;
	  }
	  else
	  {
	   Form1->Timer1->Enabled = true;
	   Form8->Timer1->Enabled = false;
	  }
  }
 }
 else
 {
  INI_save("ReportSendMail","On","0");
  Form1->Timer1->Enabled = false;
  Form8->Timer1->Enabled = false;
 }
	Form1->IdSMTP1->Host = INI_load("ReportSendMail","server");
	Form1->IdSMTP1->Port = StrToInt(INI_load("ReportSendMail","port"));
	Form1->IdSMTP1->Username = INI_load("ReportSendMail","mail");
	Form1->IdSMTP1->Password = INI_load("ReportSendMail","pass");

 Log("Настройки изменены.");
 Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
 Log("123Создание новой таблицы...");
 if(SQL_Connect() > 0)
 {
 AnsiString query = "CREATE TABLE `"+INI_load("Database","DBase1")+"`.`"
									+INI_load("Database","Table")
											+"` (`NomKlasF` CHAR(8),"
											+"`F` CHAR(50),"
											+"`I` CHAR(50),"
											+"`O` CHAR(50),"
											+"`Year` CHAR(4),"
											+"`Sex` CHAR(1),"
											+"`Dok` CHAR(40),"
											+"`Arxive` CHAR(40),"
											+"`Uchet` CHAR(40),"
											+"`Nkart` CHAR(40),"
											+"`Cod` CHAR(40),"
											+"`ADR` CHAR(60),"
											+"`Set` CHAR(20),"
											+"`remove` CHAR(20),"
											+"`Analizi` CHAR(50),"
											+"`Vipiski` CHAR(50))";

  int count = SQL_Query(query,INI_load("Database","Table"));
  if(count != 0)
  {
	 Log("Таблица `"+Edit6->Text+"` создана");
  }
  else
  {
   Log("Ошибка отправки запроса!");
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

void __fastcall TForm2::TreeView1Change(TObject *Sender, TTreeNode *Node)
{
  if(TreeView1->Selected->Text == "Подключение")
 {
	GroupBox1->Visible = true;
	GroupBox2->Visible = false;
	GroupBox4->Visible = false;
 }

 if(TreeView1->Selected->Text == "Стили")
 {
	GroupBox1->Visible = false;
	GroupBox2->Visible = true;
	GroupBox4->Visible = false;
 }

  if(TreeView1->Selected->Text == "Отчёт почтой")
 {
	GroupBox1->Visible = false;
	GroupBox2->Visible = false;
	GroupBox4->Visible = true;
 }

}
//---------------------------------------------------------------------------
void __fastcall TForm2::ListBox1Click(TObject *Sender)
{
 TStyleManager::TrySetStyle(ListBox1->Items->Strings[ListBox1->ItemIndex]);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
 TStyleManager::TrySetStyle(Style_name);
 Form2->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button4Click(TObject *Sender)
{
 AnsiString text = Label9->Caption;
 AnsiString minutes = text.Delete(1,text.Pos(":")-1);

 int H;
 H = StrToInt( Label9->Caption.Delete( Label9->Caption.Pos(":"),Label9->Caption.Length() ) );

 if(H == 23) H = -1;
 H = H+1;
 Label9->Caption = IntToStr(H).Insert(minutes,IntToStr(H).Length()+1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button5Click(TObject *Sender)
{
 AnsiString text = Label9->Caption;
 AnsiString minutes = text.Delete(1,text.Pos(":")-1);

 int H;
 H = StrToInt( Label9->Caption.Delete( Label9->Caption.Pos(":"),Label9->Caption.Length() ) );

 if(H == 0) H = 24;
 H = H-1;
 Label9->Caption = IntToStr(H).Insert(minutes,IntToStr(H).Length()+1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button6Click(TObject *Sender)
{
 AnsiString text = Label9->Caption;
 AnsiString hours = text.Delete( text.Pos( ":" )+1,text.Length() );
 AnsiString minutes;

 int M;
 M = StrToInt( Label9->Caption.Delete( 1,Label9->Caption.Pos( ":" ) ) );

 if(M == 59) M = -1;
 M = M+1;
 minutes = IntToStr(M);
 if(IntToStr(M).Length() == 1) minutes = IntToStr(M).Insert("0",1);
 Label9->Caption = minutes.Insert(hours,1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button7Click(TObject *Sender)
{
 AnsiString text = Label9->Caption;
 AnsiString hours = text.Delete( text.Pos( ":" )+1,text.Length() );
 AnsiString minutes;

 int M;
 M = StrToInt( Label9->Caption.Delete( 1,Label9->Caption.Pos( ":" ) ) );

 if(M == 0) M = 60;
 M = M-1;
 minutes = IntToStr(M);
 if(IntToStr(M).Length() == 1) minutes = IntToStr(M).Insert("0",1);
 Label9->Caption = minutes.Insert(hours,1);
}
//---------------------------------------------------------------------------

