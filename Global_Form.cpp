//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Global_Form.h"
#include "History.h"
#include "Settings.h"
#include "INI.h"
#include "Query.h"
#include "Table.h"
#include "PacView.h"
#include "Info.h"
#include "Login.h"
#include "Admin_panel.h"
#include "Report.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxPreview"
#pragma link "frxDBSet"
#pragma link "frxExportCSV"
#pragma link "frxExportHTML"
#pragma link "frxExportImage"
#pragma link "frxExportPDF"
#pragma link "frxExportRTF"
#pragma link "frxExportText"
#pragma resource "*.dfm"
TForm1 *Form1;
TForm *form_shadow = new TForm((TComponent*)NULL); //Затемнение формы
extern Table_Pacient Pacient[100000];
AnsiString mode,F,I,O;
int code = 0;
int On = 0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
	TStyleManager::TrySetStyle(INI_load("Styles","Style_name"));

  //Названия столбцов таблицы.
	StringGrid1->Cells[0][0] = "№ карты";
	StringGrid1->Cells[1][0] = "Фамилия";
	StringGrid1->Cells[2][0] = "Имя";
	StringGrid1->Cells[3][0] = "Отчество";
	StringGrid1->Cells[4][0] = "Год";
	StringGrid1->Cells[5][0] = "Адрес";

	//Ширина столбцов
	StringGrid1->ColWidths[0] = 55;
	StringGrid1->ColWidths[1] = 90;
	StringGrid1->ColWidths[2] = 60;
	StringGrid1->ColWidths[3] = 100;
	StringGrid1->ColWidths[4] = 35;
	StringGrid1->ColWidths[5] = 150;

	if (!FileExists("Config.ini"))
	{
	 TStringList * ConfFile = new TStringList;
	 ConfFile->Add("[MySQL]");
	 ConfFile->Add("IP=localhost");
	 ConfFile->Add("Port=3306");
	 ConfFile->Add("Login=root");
	 ConfFile->Add("Password=root");
	 ConfFile->Add("");
	 ConfFile->Add("[Database]");
	 ConfFile->Add("DBase1=BaseName");
	 ConfFile->Add("Table=TableName");
	 ConfFile->Add("");
	 ConfFile->Add("[Styles]");
	 ConfFile->Add("Style_name=Cyan Night");
	 ConfFile->Add("");
	 ConfFile->Add("[Ico]");
	 ConfFile->SaveToFile("Config.ini");
	 delete ConfFile;
	}

	IdSMTP1->Host = INI_load("ReportSendMail","server");
	IdSMTP1->Port = INI_load("ReportSendMail","port").ToInt();
	IdSMTP1->Username = INI_load("ReportSendMail","mail");
	IdSMTP1->Password = INI_load("ReportSendMail","pass");

	IdSMTP1->MailAgent = Form1->Caption;
	IdSMTP1->AuthType = satDefault;
	IdSMTP1->ConnectTimeout = 10000;


}
//---------------------------------------------------------------------------
//Функция вывода структуры Pacient в таблицу.
void __fastcall TForm1::WriteGrid(AnsiString query)
{
 if(SQL_Connect() > 0)
 {
  int count = SQL_Query(query,INI_load("Database","Table"));
  if(count != 0)
  {
	StringGrid1->RowCount = count+1;
	for(int i = 0;i < count+1; i++)
   {
	 StringGrid1->Cells[0][i+1] = Pacient[i].Nkart;
	 StringGrid1->Cells[1][i+1] = Pacient[i].F;
	 StringGrid1->Cells[2][i+1] = Pacient[i].I;
	 StringGrid1->Cells[3][i+1] = Pacient[i].O;
	 StringGrid1->Cells[4][i+1] = Pacient[i].Year;
	 StringGrid1->Cells[5][i+1] = Pacient[i].ADR;
	 ComboBox1->Items->Add(Pacient[i].Year);
   }
   Log("Отображено "+IntToStr(count)+" записей.");
   StatusBar1->Panels->Items[0]->Text = "Записей: "+IntToStr(count);
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
  Offline();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TabUpdate(AnsiString query)
{
 int SavePage = PageControl1->ActivePageIndex;
 Form4->ComboBox3->Items->Clear();
 for(int i = PageControl1->PageCount; --i>=0;)
 delete PageControl1->Pages[i];         //удаление всех закладок

 TTabSheet *tab = new TTabSheet(Form1);
 tab->PageControl = PageControl1;
 tab->Caption = "Все";
 tab->ImageIndex=22;

 if(CheckBox1->Checked != true)
  {
		query="SELECT * FROM `"	+INI_load("Database","DBase1")+"`.`"
							+INI_load("Database","Table")+"` GROUP BY `Uchet`";
  }
  else
  {
		query = query + " GROUP BY `Uchet`";
  }
 Log("123Создание вкладок:");
  if(SQL_Connect() > 0)
 {
  int count = SQL_Query(query,INI_load("Database","Table"));
  if(count != 0)
  {
	for(int i = 0;i < count; i++)
   {
	TTabSheet *tab = new TTabSheet(Form1);
		tab->PageControl = PageControl1;
		tab->Caption = Pacient[i].Uchet;
		tab->ImageIndex=StrToInt(INI_load("ICO",Pacient[i].Uchet));
		Form4->ComboBox3->Items->Add(Pacient[i].Uchet);
		Form8->ComboBox8->Items->Add(Pacient[i].Uchet);
   }
   Log("Создано "+IntToStr(count)+" вкладок.");
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
  Offline();
 }
 PageControl1->ActivePageIndex = SavePage;
}
//---------------------------------------------------------------------------
//Функция фозвращает 1 если есть подключение к серверу, а также активиурет
//некоторые элементы формы
int __fastcall TForm1::Online(void)
{
Log("123Попытка подключения к серверу:");
 int result;
  if(SQL_Connect() > 0)
 {
  Log("Переход в режим Online.");
  On = 1;
  N1->Enabled = false;
  N2->Enabled = true;
  N7->Enabled = true;
  PageControl1->Enabled = true;
  StringGrid1->Enabled = true;
  GroupBox1->Enabled = true;
  Form8->Timer1->Interval = StrToInt(INI_load("ReportSendMail","Time1"))*60000;
  if(INI_load("ReportSendMail","On") == "1")
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

  SQL_Connect_Close();
  result = 1;
 }
 else
 {
  ShowMessage("Не удалось подключиться к серверу!");
  Log("Подключение с сервером отсутствует!");
  Offline();
  result = 0;
 }
 return(result);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Offline(void)
{
  Log("Переход в режим Offline.");
  On = 0;
  N1->Enabled = true;
  N2->Enabled = false;
  N7->Enabled = false;
  N2->Visible = false;
  N9->Visible = false;
  Form4->Button2->Visible = false;
  Form4->Button4->Visible = false;
  N10->Visible = false;
  PageControl1->Enabled = false;
  StringGrid1->Enabled = false;
  GroupBox1->Enabled = false;
  StringGrid1->RowCount = 0;
  Form8->Timer1->Enabled = false;
  Timer1->Enabled = false;
  for(int i = PageControl1->PageCount; --i>=0;)
 delete PageControl1->Pages[i];
 Form1->Caption = "Солигорский психоневрологический диспансер";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::PageControl1Change(TObject *Sender)
{
 AnsiString query = "SELECT * FROM `"
				+INI_load("Database","DBase1")+"`.`"
				+INI_load("Database","Table")+"`";
 AnsiString query_AND = " AND ";
 AnsiString query_WHERE = " WHERE ";
 AnsiString query_U = "`Uchet` LIKE '"+PageControl1->ActivePage->Caption+"'";
 AnsiString query_F = "`F` LIKE '%"+Edit1->Text+"%'";
 AnsiString query_I = "`I` LIKE '%"+Edit2->Text+"%'";
 AnsiString query_O = "`O` LIKE '%"+Edit3->Text+"%'";
 AnsiString query_BETWEEN = "`Year` BETWEEN  '"	+ComboBox1->Text+"' AND '"
												+ComboBox2->Text+"'";
 AnsiString query_SEX;
 AnsiString SEX;
 int count = 0;
 AnsiString query_TAB = query;

 if(CheckBox1->Checked == true)
  {
   if(Edit1->Text != "")
   {
	if(count > 0)
	{
	 query = query + query_AND;
	 query_TAB = query_TAB + query_AND;
	}
	else
	{
	 query = query + query_WHERE;
	 query_TAB = query_TAB + query_WHERE;
	}
	query = query + query_F;
	query_TAB = query_TAB + query_F;
	count++;
   }

   if(Edit2->Text != "")
   {
	if(count > 0)
	{
	 query = query + query_AND;
	 query_TAB = query_TAB + query_AND;
	}
	else
	{
	 query = query + query_WHERE;
	 query_TAB = query_TAB + query_WHERE;
	}
	query = query + query_I;
	query_TAB = query_TAB + query_I;
	count++;
   }

   if(Edit3->Text != "")
   {
	if(count > 0)
	{
	 query = query + query_AND;
	 query_TAB = query_TAB + query_AND;
	}
	else
	{
	 query = query + query_WHERE;
	 query_TAB = query_TAB + query_WHERE;
	}
	query = query + query_O;
	query_TAB = query_TAB + query_O;
	count++;
   }

	if(RadioButton1->Checked == true)
   {
	if(count > 0)
	{
	 query = query + query_AND;
	 query_TAB = query_TAB + query_AND;
	}
	else
	{
	 query = query + query_WHERE;
	 query_TAB = query_TAB + query_WHERE;
	}
	SEX = "М";
	query_SEX = "`Sex` LIKE '"+SEX+"'";
	query = query + query_SEX;
	query_TAB = query_TAB + query_SEX;
	count++;
   }

   if(RadioButton2->Checked == true)
   {
	if(count > 0)
	{
	 query = query + query_AND;
	 query_TAB = query_TAB + query_AND;
	}
	else
	{
	 query = query + query_WHERE;
	 query_TAB = query_TAB + query_WHERE;
	}
	SEX = "Ж";
	query_SEX = "`Sex` LIKE '"+SEX+"'";
	query = query + query_SEX;
	query_TAB = query_TAB + query_SEX;
	count++;
   }

   if(ComboBox1->Text != "" &&
	  ComboBox2->Text != "" )
   {
	if(count > 0)
	{
	 query = query + query_AND;
	 query_TAB = query_TAB + query_AND;
	}
	else
	{
	 query = query + query_WHERE;
	 query_TAB = query_TAB + query_WHERE;
	}
	query = query + query_BETWEEN;
	query_TAB = query_TAB + query_BETWEEN;
	count++;
   }
  }

   if(PageControl1->ActivePage->TabIndex != 0)
	 {
	  if(count > 0)
		{
		 query = query + query_AND;
		}
	  else
		{
		 query = query + query_WHERE;
		}
	  query = query + query_U;
	 }
 if(code > 0)
 {
  TabUpdate(query_TAB);
  PageControl1->ActivePageIndex = 0;
  WriteGrid(query_TAB);
 }
 else WriteGrid(query);
 code = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N4Click(TObject *Sender)
{
 Log("123");
 Log("Просмотр журнала.");
 Form3->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N5Click(TObject *Sender)
{
 Log("123");
 Log("Просмотр настроек.");
 Form2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
{
 mode = "add";
 Form4->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1DblClick(TObject *Sender)
{
	F = StringGrid1->Cells[1][StringGrid1->Row];
	I = StringGrid1->Cells[2][StringGrid1->Row];
	O = StringGrid1->Cells[3][StringGrid1->Row];
	Form4->Caption = F+" "+I+" "+O;
	mode="edit";
	Form4->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Form_Shadow(int n)
{
	if(n==1)
	{
	form_shadow->BorderStyle = bsNone;
	form_shadow->Width = this->Width;
	form_shadow->Height = this->Height;
	form_shadow->Position= this->Position;
	form_shadow->Left = this->Left;
	form_shadow->Top = this->Top;
	form_shadow->Color=clGray;
	form_shadow->AlphaBlend = true;
	form_shadow->AlphaBlendValue = 150;
	form_shadow->OnClick = Form_shadow_OnClick;
	form_shadow->OnDblClick = Form_shadow_OnClick;
	form_shadow->OnContextPopup = Form_shadow_ContextPopup;
	form_shadow->Show();
	}
	else form_shadow->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Form_shadow_OnClick(TObject *Sender)
{
	Form2->BringToFront();
	Form4->BringToFront();
	Form6->BringToFront();
	Form7->BringToFront();
	Form8->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Form_shadow_ContextPopup(TObject *Sender, TPoint &MousePos,
		  bool &Handled)
{
	   Form2->BringToFront();
	   Form4->BringToFront();
	   Form6->BringToFront();
	   Form7->BringToFront();
	   Form8->BringToFront();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
 Form5->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Change(TObject *Sender)
{
 if(CheckBox1->Checked == true)
 {
  code = 1;
  PageControl1Change(Edit1);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2Change(TObject *Sender)
{
 if(CheckBox1->Checked == true)
 {
  code = 1;
  PageControl1Change(Edit1);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3Change(TObject *Sender)
{
 if(CheckBox1->Checked == true)
 {
  code = 1;
  PageControl1Change(Edit1);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
 code = 1;
 PageControl1Change(Edit1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2DropDown(TObject *Sender)
{
 ComboBox2->Clear();
  if(SQL_Connect() > 0)
 {
  AnsiString query = "SELECT * FROM `"+INI_load("Database","DBase1")+"`.`"
									+INI_load("Database","Table")+"` GROUP BY `Year` ORDER BY `Year`";
  int count = SQL_Query(query,INI_load("Database","Table"));
  if(count != 0)
  {
	for(int i = count-1;i >= 0; i--)
   {
	ComboBox2->Items->Add(Pacient[i].Year);
   }
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
  Offline();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1Select(TObject *Sender)
{
 if(CheckBox1->Checked == true)
 {
  code = 1;
  PageControl1Change(Edit1);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
 if(CheckBox1->Checked == true)
 {
  code = 1;
  PageControl1Change(Edit1);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
 if(CheckBox1->Checked == true)
 {
  code = 1;
  PageControl1Change(Edit1);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RadioButton3Click(TObject *Sender)
{
 if(CheckBox1->Checked == true)
 {
  code = 1;
  PageControl1Change(Edit1);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox2Select(TObject *Sender)
{
 if(CheckBox1->Checked == true)
 {
  code = 1;
  PageControl1Change(Edit1);
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ComboBox1DropDown(TObject *Sender)
{
   ComboBox1->Clear();
  if(SQL_Connect() > 0)
 {
  AnsiString query = "SELECT * FROM `"+INI_load("Database","DBase1")+"`.`"
									+INI_load("Database","Table")+"` GROUP BY `Year` ORDER BY `Year`";
  int count = SQL_Query(query,INI_load("Database","Table"));
  if(count != 0)
  {
	for(int i = 0;i < count; i++)
   {
	ComboBox1->Items->Add(Pacient[i].Year);
   }
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
  Offline();
 }
}
//---------------------------------------------------------------------------



void __fastcall TForm1::N8Click(TObject *Sender)
{
 Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N7Click(TObject *Sender)
{
 Offline();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N1Click(TObject *Sender)
{
 Log("123Попытка подключения к серверу:");
  if(SQL_Connect() > 0)
 {
  Log("Вызов формы авторизации");
  Form6->Show();

  SQL_Connect_Close();
 }
 else
 {
  ShowMessage("Не удалось подключиться к серверу!");
  Log("Подключение с сервером отсутствует!");
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender)
{
  Form7->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N10Click(TObject *Sender)
{
 Form8->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 AnsiString HM = Time().CurrentTime();
 if(HM.Delete(6,HM.Length()) == INI_load("ReportSendMail","Time2"))
 {
  Form8->SendMail();
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::IdMessage1InitializeISO(System::WideChar &VHeaderEncoding,
          UnicodeString &VCharSet)
{
 VHeaderEncoding = 'B';
 VCharSet=L"UTF-8";
}
//---------------------------------------------------------------------------


