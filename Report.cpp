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
#include "IdAttachmentFile.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "frxClass"
#pragma link "frxExportText"
#pragma link "frxExportRTF"
#pragma resource "*.dfm"
TForm8 *Form8;
int mail = 0;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormClose(TObject *Sender, TCloseAction &Action)
{
 Form1->Form_Shadow(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::FormShow(TObject *Sender)
{
 Form1->Form_Shadow(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
 Memo1->Clear();
 int count = 0, okay = 0;
 AnsiString query = "SELECT * FROM `"
				+INI_load("Database","DBase1")+"`.`"
				+INI_load("Database","Table")+"`";
 AnsiString query_Text;
 AnsiString query_AND = " AND ";
 AnsiString query_WHERE = " WHERE ";
 AnsiString Y = Date();
 Y = Y.Delete(1,6);

//Фамилия
 if(CheckBox1->Checked == true)
 {
	if(ComboBox1->Text != "")
	{
		if(Edit1->Text != "")
		{
			if(ComboBox1->Text == "Точное совпадение")
			{
			 query_Text = "`F` LIKE '"+Edit1->Text+"'";
			}

			if(ComboBox1->Text == "Частичное совпадение")
			{
			 query_Text = "`F` LIKE '%"+Edit1->Text+"%'";
			}

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
			Memo1->Lines->Add("-Фамилия : "+Edit1->Text);
		}
		else
		{
			Edit1->Color = clRed;
			okay++;
		}
	}
	else
	{
		ComboBox1->Color = clRed;
		okay++;
	}
 }

 //Имя
 if(CheckBox2->Checked == true)
 {
	if(ComboBox2->Text != "")
	{
		if(Edit2->Text != "")
		{
			if(ComboBox2->Text == "Точное совпадение")
			{
			 query_Text = "`I` LIKE '"+Edit2->Text+"'";
			}

			if(ComboBox2->Text == "Частичное совпадение")
			{
			 query_Text = "`I` LIKE '%"+Edit2->Text+"%'";
			}

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
			Memo1->Lines->Add("-Имя : "+Edit2->Text);
		}
		else
		{
			Edit2->Color = clRed;
			okay++;
		}
	}
	else
	{
		ComboBox2->Color = clRed;
		okay++;
	}
 }

 //Отчество
 if(CheckBox3->Checked == true)
 {
	if(ComboBox3->Text != "")
	{
		if(Edit3->Text != "")
		{
			if(ComboBox3->Text == "Точное совпадение")
			{
			 query_Text = "`O` LIKE '"+Edit3->Text+"'";
			}

			if(ComboBox3->Text == "Частичное совпадение")
			{
			 query_Text = "`O` LIKE '%"+Edit3->Text+"%'";
			}

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
			Memo1->Lines->Add("-Отчество : "+Edit3->Text);
		}
		else
		{
			Edit3->Color = clRed;
			okay++;
		}
	}
	else
	{
		ComboBox3->Color = clRed;
		okay++;
	}
 }

 //Год рождения
 if(CheckBox4->Checked == true)
 {
	if(ComboBox4->Text != "")
	{
			if(ComboBox4->Text == "До")
			{
			 query_Text = "`Year` BETWEEN  '0' AND '"
											 +Edit5->Text+"'";
			 Memo1->Lines->Add("-Год рождения : до "+Edit5->Text);
			}

			if(ComboBox4->Text == "После")
			{
			 query_Text = "`Year` BETWEEN  '"+Edit4->Text+"'AND '"
											 +Y+"'";
			 Memo1->Lines->Add("-Год рождения : после "+Edit4->Text);
			}

			if(ComboBox4->Text == "Период")
			{
			 query_Text = "`Year` BETWEEN  '"+Edit4->Text+"'AND '"
											 +Edit5->Text+"'";
			 Memo1->Lines->Add("-Год рождения : от "+Edit4->Text+" до "+Edit5->Text);
			}

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
	}
	else
	{
		ComboBox4->Color = clRed;
		okay++;
	}
 }

 //Пол
 if(CheckBox5->Checked == true)
 {
	if(ComboBox5->Text != "")
	{
			query_Text = "`Sex` LIKE '"+ComboBox5->Text+"'";


			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
			Memo1->Lines->Add("-Пол : "+ComboBox5->Text);
	}
	else
	{
		ComboBox5->Color = clRed;
		okay++;
	}
 }

 //Документ
 if(CheckBox6->Checked == true)
 {
	if(ComboBox6->Text != "")
	{
		if(Edit6->Text != "")
		{
			if(ComboBox6->Text == "Точное совпадение")
			{
			 query_Text = "`Dok` LIKE '"+Edit6->Text+"'";
			}

			if(ComboBox6->Text == "Частичное совпадение")
			{
			 query_Text = "`Dok` LIKE '%"+Edit6->Text+"%'";
			}

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
			Memo1->Lines->Add("-Документ : "+ComboBox6->Text);
		}
		else
		{
			Edit6->Color = clRed;
			okay++;
		}
	}
	else
	{
		ComboBox6->Color = clRed;
		okay++;
	}
 }

 //Архив
 if(CheckBox7->Checked == true)
 {
	if(ComboBox7->Text != "")
	{
		if(Edit7->Text != "")
		{
			if(ComboBox7->Text == "Точное совпадение")
			{
			 query_Text = "`Arxive` LIKE '"+Edit7->Text+"'";
			}

			if(ComboBox7->Text == "Частичное совпадение")
			{
			 query_Text = "`Arxive` LIKE '%"+Edit7->Text+"%'";
			}

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
			Memo1->Lines->Add("-Архив : "+ComboBox7->Text);
		}
		else
		{
			Edit7->Color = clRed;
			okay++;
		}
	}
	else
	{
		ComboBox7->Color = clRed;
		okay++;
	}
 }

 //Учёт
 if(CheckBox8->Checked == true)
 {
	if(ComboBox8->Text != "")
	{
			query_Text = "`Uchet` LIKE '"+ComboBox8->Text+"'";

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
			Memo1->Lines->Add("-Учёт : "+ComboBox8->Text);
	}
	else
	{
		ComboBox8->Color = clRed;
		okay++;
	}
 }

 //Номер карты
 if(CheckBox11->Checked == true)
 {
	if(ComboBox11->Text != "")
	{
			if(ComboBox11->Text == "До")
			{
			 query_Text = "`Nkart` BETWEEN  '0'AND '"
											 +Edit9->Text+"'";
			 Memo1->Lines->Add("-Номер карты : до "+Edit9->Text);
			}

			if(ComboBox11->Text == "После")
			{
			 query_Text = "`Nkart` BETWEEN  '"+Edit8->Text+"'AND '"
											 +Y+"'";
			 Memo1->Lines->Add("-Номер карты : после "+Edit8->Text);
			}

			if(ComboBox11->Text == "Период")
			{
			 query_Text = "`Nkart` BETWEEN  '"+Edit8->Text+"'AND '"
											 +Edit9->Text+"'";
			 Memo1->Lines->Add("-Номер карты : от "+Edit8->Text+" до "+Edit9->Text);

			}

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
	}
	else
	{
		ComboBox11->Color = clRed;
		okay++;
	}
 }

 //Шифр
 if(CheckBox12->Checked == true)
 {
	if(ComboBox12->Text != "")
	{
		if(Edit10->Text != "")
		{
			if(ComboBox12->Text == "Точное совпадение")
			{
			 query_Text = "`Cod` LIKE '"+Edit10->Text+"'";
			}

			if(ComboBox12->Text == "Частичное совпадение")
			{
			 query_Text = "`Cod` LIKE '%"+Edit10->Text+"%'";
			}

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
			Memo1->Lines->Add("-Шифр : "+Edit10->Text);
		}
		else
		{
			Edit10->Color = clRed;
			okay++;
		}
	}
	else
	{
		ComboBox12->Color = clRed;
		okay++;
	}
 }

 //Адрес
 if(CheckBox14->Checked == true)
 {
	if(ComboBox14->Text != "")
	{
		if(Edit12->Text != "")
		{
			if(ComboBox14->Text == "Точное совпадение")
			{
			 query_Text = "`ADR` LIKE '"+Edit12->Text+"'";
			}

			if(ComboBox14->Text == "Частичное совпадение")
			{
			 query_Text = "`ADR` LIKE '%"+Edit12->Text+"%'";
			}

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
			Memo1->Lines->Add("-Адрес : "+Edit12->Text);
		}
		else
		{
			Edit12->Color = clRed;
			okay++;
		}
	}
	else
	{
		ComboBox14->Color = clRed;
		okay++;
	}
 }

 //Анализы
 if(CheckBox15->Checked == true)
 {
	if(ComboBox15->Text != "")
	{
		if(Edit13->Text != "")
		{
			if(ComboBox15->Text == "Точное совпадение")
			{
			 query_Text = "`Analizi` LIKE '"+Edit13->Text+"'";
			}

			if(ComboBox15->Text == "Частичное совпадение")
			{
			 query_Text = "`Analizi` LIKE '%"+Edit13->Text+"%'";
			}

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
			Memo1->Lines->Add("-Анализы : "+Edit13->Text);
		}
		else
		{
			Edit13->Color = clRed;
			okay++;
		}
	}
	else
	{
		ComboBox15->Color = clRed;
		okay++;
	}
 }

 //Выписки
 if(CheckBox16->Checked == true)
 {
	if(ComboBox16->Text != "")
	{
		if(Edit14->Text != "")
		{
			if(ComboBox16->Text == "Точное совпадение")
			{
			 query_Text = "`Vipiski` LIKE '"+Edit14->Text+"'";
			}

			if(ComboBox16->Text == "Частичное совпадение")
			{
			 query_Text = "`Vipiski` LIKE '%"+Edit14->Text+"%'";
			}

			if(count > 0) query = query + query_AND;
			else query = query + query_WHERE;

			query = query + query_Text;

			count++;
			Memo1->Lines->Add("-Выписки : "+Edit14->Text);
		}
		else
		{
			Edit14->Color = clRed;
			okay++;
		}
	}
	else
	{
		ComboBox16->Color = clRed;
		okay++;
	}
 }
if(count == 0) Memo1->Lines->Add("-Все записи");

if(okay == 0)
{
 Log("123Отчёт:");
 if(SQL_Connect() > 0)
 {
  Log("Формирование отчёта.");
  int count = SQL_Query(query,"Report");
  if(count != 0)
  {
	Memo1->Lines->Add("");
	Memo1->Lines->Add("Количество записей : "+IntToStr(count));


	Form1->ADOTable2->Open();
	Form1->ADOTable2->Edit();
	Form1->ADOTable2->FieldByName("str")->AsString = Memo1->Text;
	Form1->ADOTable2->Post();
	Form1->ADOTable2->Close();


	Form1->frxReport1->LoadFromFile("reports\\Report.fr3");

	if(mail != 1)
	{
	 Form1->frxReport1->ShowReport();
	 Form1->ADOQuery1->ExecSQL();
	}
	else
	{
		mail = 0;

	}
  }
  else
  {
   Log("Ошибка отправки запроса!");
   ShowMessage("Записи не найдены.");
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
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox1Select(TObject *Sender)
{
 ComboBox1->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit1Change(TObject *Sender)
{
 Edit1->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox2Select(TObject *Sender)
{
 ComboBox2->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit2Change(TObject *Sender)
{
 Edit2->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox3Select(TObject *Sender)
{
 ComboBox3->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit3Change(TObject *Sender)
{
 Edit3->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox4Select(TObject *Sender)
{
 ComboBox4->Color = clWindow;
 if(ComboBox4->Text == "До")
			{
			 Edit4->Enabled = false;
			 Edit5->Enabled = true;
			}

			if(ComboBox4->Text == "После")
			{
			 Edit4->Enabled = true;
			 Edit5->Enabled = false;
			}

			if(ComboBox4->Text == "Период")
			{
			 Edit4->Enabled = true;
			 Edit5->Enabled = true;
			}
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit4Change(TObject *Sender)
{
 Edit4->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit5Change(TObject *Sender)
{
 Edit5->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox5Select(TObject *Sender)
{
 ComboBox5->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox6Select(TObject *Sender)
{
 ComboBox6->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit6Change(TObject *Sender)
{
 Edit6->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox7Select(TObject *Sender)
{
 ComboBox7->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit7Change(TObject *Sender)
{
 Edit7->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox8Select(TObject *Sender)
{
 ComboBox8->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit8Change(TObject *Sender)
{
 Edit8->Color = clWindow;
}
//---------------------------------------------------------------------------


void __fastcall TForm8::Edit9Change(TObject *Sender)
{
 Edit9->Color = clWindow;
}
//---------------------------------------------------------------------------


void __fastcall TForm8::Edit10Change(TObject *Sender)
{
 Edit10->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox11Select(TObject *Sender)
{
 ComboBox11->Color = clWindow;
 if(ComboBox11->Text == "До")
			{
			 Edit8->Enabled = false;
			 Edit9->Enabled = true;
			}

			if(ComboBox11->Text == "После")
			{
			 Edit8->Enabled = true;
			 Edit9->Enabled = false;
			}

			if(ComboBox11->Text == "Период")
			{
			 Edit8->Enabled = true;
			 Edit9->Enabled = true;
			}
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox12Select(TObject *Sender)
{
 ComboBox12->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit12Change(TObject *Sender)
{
 Edit12->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit13Change(TObject *Sender)
{
 Edit13->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox14Select(TObject *Sender)
{
 ComboBox14->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Edit14Change(TObject *Sender)
{
 Edit14->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox15Select(TObject *Sender)
{
 ComboBox15->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::ComboBox16Select(TObject *Sender)
{
 ComboBox16->Color = clWindow;
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button6Click(TObject *Sender)
{
 AnsiString result;

 if(CheckBox1->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","F",result);

 if(CheckBox2->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","I",result);

 if(CheckBox3->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","O",result);

 if(CheckBox4->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","Year",result);

 if(CheckBox5->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","Sex",result);

 if(CheckBox6->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","Dok",result);

 if(CheckBox7->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","Arxive",result);

 if(CheckBox8->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","Uchet",result);

 if(CheckBox11->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","Nkart",result);

 if(CheckBox12->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","Cod",result);

 if(CheckBox14->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","ADR",result);

 if(CheckBox15->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","Analizi",result);

 if(CheckBox16->Checked == true) result = "1";
 else result = "0";
 INI_save("Report_Save","Vipiski",result);

 INI_save("Report_Save","CB_F",ComboBox1->Text);
 INI_save("Report_Save","CB_I",ComboBox2->Text);
 INI_save("Report_Save","CB_O",ComboBox3->Text);
 INI_save("Report_Save","CB_Year",ComboBox4->Text);
 INI_save("Report_Save","CB_Sex",ComboBox5->Text);
 INI_save("Report_Save","CB_Dok",ComboBox6->Text);
 INI_save("Report_Save","CB_Arxive",ComboBox7->Text);
 INI_save("Report_Save","CB_Uchet",ComboBox8->Text);
 INI_save("Report_Save","CB_Nkart",ComboBox11->Text);
 INI_save("Report_Save","CB_Cod",ComboBox12->Text);
 INI_save("Report_Save","CB_ADR",ComboBox14->Text);
 INI_save("Report_Save","CB_Analizi",ComboBox15->Text);
 INI_save("Report_Save","CB_Vipiski",ComboBox16->Text);

 INI_save("Report_Save","Ed_F",Edit1->Text);
 INI_save("Report_Save","Ed_I",Edit2->Text);
 INI_save("Report_Save","Ed_O",Edit3->Text);
 INI_save("Report_Save","Ed1_Year",Edit4->Text);
 INI_save("Report_Save","Ed2_Year",Edit5->Text);
 INI_save("Report_Save","Ed_Dok",Edit6->Text);
 INI_save("Report_Save","Ed_Arxive",Edit7->Text);
 INI_save("Report_Save","Ed1_Nkart",Edit8->Text);
 INI_save("Report_Save","Ed2_Nkart",Edit9->Text);
 INI_save("Report_Save","Ed_Cod",Edit10->Text);
 INI_save("Report_Save","Ed_ADR",Edit12->Text);
 INI_save("Report_Save","Ed_Analizi",Edit13->Text);
 INI_save("Report_Save","Ed_Vipiski",Edit14->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm8::Button7Click(TObject *Sender)
{
 if(INI_load("Report_Save","F") == "1") CheckBox1->Checked = true;
 else CheckBox1->Checked = false;

 if(INI_load("Report_Save","I") == "1") CheckBox2->Checked = true;
 else CheckBox2->Checked = false;

 if(INI_load("Report_Save","O") == "1") CheckBox3->Checked = true;
 else CheckBox3->Checked = false;

 if(INI_load("Report_Save","Year") == "1") CheckBox4->Checked = true;
 else CheckBox4->Checked = false;

 if(INI_load("Report_Save","Sex") == "1") CheckBox5->Checked = true;
 else CheckBox5->Checked = false;

 if(INI_load("Report_Save","Dok") == "1") CheckBox6->Checked = true;
 else CheckBox6->Checked = false;

 if(INI_load("Report_Save","Arxive") == "1") CheckBox7->Checked = true;
 else CheckBox7->Checked = false;

 if(INI_load("Report_Save","Uchet") == "1") CheckBox8->Checked = true;
 else CheckBox8->Checked = false;

 if(INI_load("Report_Save","Nkart") == "1") CheckBox11->Checked = true;
 else CheckBox11->Checked = false;

 if(INI_load("Report_Save","Cod") == "1") CheckBox12->Checked = true;
 else CheckBox12->Checked = false;

 if(INI_load("Report_Save","ADR") == "1") CheckBox14->Checked = true;
 else CheckBox14->Checked = false;

 if(INI_load("Report_Save","Analizi") == "1") CheckBox15->Checked = true;
 else CheckBox15->Checked = false;

 if(INI_load("Report_Save","Vipiski") == "1") CheckBox16->Checked = true;
 else CheckBox16->Checked = false;

 ComboBox1->Text = INI_load("Report_Save","CB_F");
 ComboBox2->Text = INI_load("Report_Save","CB_I");
 ComboBox3->Text = INI_load("Report_Save","CB_O");
 ComboBox4->Text = INI_load("Report_Save","CB_Year");
 ComboBox5->Text = INI_load("Report_Save","CB_Sex");
 ComboBox6->Text = INI_load("Report_Save","CB_Dok");
 ComboBox7->Text = INI_load("Report_Save","CB_Arxive");
 ComboBox8->Text = INI_load("Report_Save","CB_Uchet");
 ComboBox11->Text = INI_load("Report_Save","CB_Nkart");
 ComboBox12->Text = INI_load("Report_Save","CB_Cod");
 ComboBox14->Text = INI_load("Report_Save","CB_ADR");
 ComboBox15->Text = INI_load("Report_Save","CB_Analizi");
 ComboBox16->Text = INI_load("Report_Save","CB_Vipiski");

 Edit1->Text = INI_load("Report_Save","Ed_F");
 Edit2->Text = INI_load("Report_Save","Ed_I");
 Edit3->Text = INI_load("Report_Save","Ed_O");
 Edit4->Text = INI_load("Report_Save","Ed1_Year");
 Edit5->Text = INI_load("Report_Save","Ed2_Year");
 Edit6->Text = INI_load("Report_Save","Ed_Dok");
 Edit7->Text = INI_load("Report_Save","Ed_Arxive");
 Edit8->Text = INI_load("Report_Save","Ed1_Nkart");
 Edit9->Text = INI_load("Report_Save","Ed2_Nkart");
 Edit10->Text = INI_load("Report_Save","Ed_Cod");
 Edit12->Text = INI_load("Report_Save","Ed_ADR");
 Edit13->Text = INI_load("Report_Save","Ed_Analizi");
 Edit14->Text = INI_load("Report_Save","Ed_Vipiski");
}
//---------------------------------------------------------------------------
void __fastcall TForm8::SendMail(void)
{
 Log("123Отправка письма:");
 //загрузка настроек
 Button7Click(Button7);

 //создание отчёта и сохранение в файл
 mail = 1;
 Button1Click(Button1);
 Form1->frxReport1->PrepareReport();
 Form1->frxReport1->Export(frxRTFExport1);

 //формирование письма
 Form1->IdMessage1->Clear();
 Form1->IdMessage1->Recipients->EMailAddresses = INI_load("ReportSendMail","mail_send");
 Form1->IdMessage1->Subject = "СолПсихДисп. Отчёт.";
 Form1->IdMessage1->From->Text = INI_load("ReportSendMail","mail");

 //смена режима и кодировки письма
 Form1->IdMessage1->ContentType = L"multipart/mixed; charset=UTF-8";
 Form1->IdMessage1->ContentTransferEncoding = L"base64";

 //текст и вложенный файл
 Form1->IdMessage1->Body->Text = "Письмо с вложением отчёта в формате RTF. Это письмо создано автоматически программой СолПсихДисп, отвечать на него не нужно.";
 TIdAttachmentFile *attachment = new TIdAttachmentFile(Form1->IdMessage1->MessageParts, "Reports\\Report.rtf");

 //подключение и отправка
 Form1->IdSMTP1->Disconnect();
 Form1->IdSMTP1->Connect();
 Form1->IdSMTP1->Send(Form1->IdMessage1);
 Form1->IdSMTP1->Disconnect();

  //очистка всех полей формы
  for(int i = 0; i < ComponentCount; i++)
	{
		TEdit* edit;
		edit = dynamic_cast<TEdit*>(Components[i]);
		if(edit)
		edit->Clear();

		TCheckBox* check;
		check = dynamic_cast<TCheckBox*>(Components[i]);
		if(check)
		check->Checked = false;

		TComboBox* combo;
		combo = dynamic_cast<TComboBox*>(Components[i]);
		if(combo)
		combo->Text = "";
	}
 Log("Отчёт успешно отправлен на почту "+INI_load("ReportSendMail","mail_send"));
}

void __fastcall TForm8::Timer1Timer(TObject *Sender)
{
 SendMail();
}
//---------------------------------------------------------------------------

