//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Global_Form.h"
#include "PacView.h"
#include "INI.h"
#include "Query.h"
#include "History.h"
#include "Table.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
extern AnsiString mode,F,I,O;
AnsiString id;
int cal;
extern Table_Pacient Pacient[100000];
extern Users Users[100000];
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
 ClearEdit();
 Form1->Form_Shadow(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::FormShow(TObject *Sender)
{
   Form1->Form_Shadow(1);
	//Заполнение годами начиная с текущего
	for (int i = Date().DateTimeString().Delete(1,6).ToInt(); i > 1900; i--)
	  ComboBox1->Items->Add(i);
	//Заполнение иконок
	for(int i = 0;i < Form1->ImageList1->Count; i++)
	  ComboBoxEx1->ItemsEx->AddItem("",i,i,-1,-1,0);

	if(mode=="add")
	{
	  Log("123Создание новой записи:");
	  this->Caption = "Новый пациент";
	  Button1->Show();
	  Button2->Hide();
	  Button4->Hide();
	}

	if(mode=="edit")
	{
	  Log("123Редактирование записи '"+Form4->Caption+"':");
	  Button1->Hide();
	  if(Users[0].level > 1)
	  {
	   Button2->Show();
	   Button4->Show();
	  }
	  else
	  {
	   Button2->Hide();
	   Button4->Hide();
      }

		if(SQL_Connect() > 0)
		 {
		  Log("Заполнение полей данными.");
		  AnsiString query =
			"SELECT * FROM `"
			+INI_load("Database","DBase1")+"`.`"
			+INI_load("Database","Table")+"` WHERE `F` LIKE '"
			+F+"' AND `I` LIKE '"+I+"' AND `O` LIKE '"+O+"'";

		  int count = SQL_Query(query,INI_load("Database","Table"));
		  if(count != 0)
		  {
			  id = Pacient[0].NomKlasF;
			  Edit1->Text = Pacient[0].F;
			  Edit2->Text = Pacient[0].I;
			  Edit3->Text = Pacient[0].O;
			  Edit4->Text = Pacient[0].Analizi;
			  Edit5->Text = Pacient[0].Nkart;
			  Edit6->Text = Pacient[0].Dok;
			  Edit7->Text = Pacient[0].Arxive;
			  Edit8->Text = Pacient[0].Cod;
			  Edit9->Text = Pacient[0].Set;
			  Edit10->Text = Pacient[0].remove;
			  Edit11->Text = Pacient[0].Vipiski;
			  ComboBox1->Text = Pacient[0].Year;
			  ComboBox2->Text = Pacient[0].Sex;
			  ComboBox3->Text = Pacient[0].Uchet;
			  Memo1->Text = Pacient[0].ADR;
			  ComboBoxEx1->ItemIndex = INI_load("ICO",ComboBox3->Text).ToInt();

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
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button1Click(TObject *Sender)
{
if(SQL_Connect() > 0)
		 {
		AnsiString query = "INSERT INTO `"+INI_load("Database","DBase1")+"`.`"
										  +INI_load("Database","Table")+"` (`NomKlasF`,"
													+"`F`,"
													+"`I`,"
													+"`O`,"
													+"`Year`,"
													+"`Sex`,"
													+"`Dok`,"
													+"`Arxive`,"
													+"`Uchet`,"
													+"`Nkart`,"
													+"`Cod`,"
													+"`ADR`,"
													+"`Set`,"
													+"`remove`,"
													+"`Analizi`,"
													+"`Vipiski`)"
											+"VALUES ('"+ID_Search(INI_load("Database","Table"))
														+"', '"+
														Edit1->Text+"', '"+
														Edit2->Text+"', '"+
														Edit3->Text+"', '"+
														ComboBox1->Text+"', '"+
														ComboBox2->Text+"', '"+
														Edit6->Text+"', '"+
														Edit7->Text+"', '"+
														ComboBox3->Text+"', '"+
														Edit5->Text+"', '"+
														Edit8->Text+"', '"+
														Memo1->Text+"', '"+
														Edit9->Text+"', '"+
														Edit10->Text+"', '"+
														Edit4->Text+"', '"+
														Edit11->Text+"')";

		  int count = SQL_Query(query,INI_load("Database","Table"));
		  if(count != 0)
		  {
		   Log("Пациент '"+Edit1->Text+" "+Edit2->Text+" "+Edit3->Text+"' добавлен в базу.");
		   INI_save("ICO",ComboBox3->Text,IntToStr(ComboBoxEx1->ItemIndex));
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

  ClearEdit();
  Form1->TabUpdate("");
  Form1->PageControl1Change(Edit1);
  this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender)
{
 if(SQL_Connect() > 0)
		 {
		AnsiString query = "UPDATE `"+INI_load("Database","DBase1")+"`.`"
									 +INI_load("Database","Table")+"` SET `NomKlasF` = '" + id +
											"',`F` = '" + Edit1->Text +
											"',`I` = '" + Edit2->Text +
											"',`O` = '" + Edit3->Text +
											"',`Year` = '" + ComboBox1->Text +
											"',`Sex` = '" + ComboBox2->Text +
											"',`Dok` = '" + Edit6->Text +
											"',`Arxive` = '" + Edit7->Text +
											"',`Uchet` = '" + ComboBox3->Text +
											"',`Nkart` = '" + Edit5->Text +
											"',`Cod` = '" + Edit8->Text +
											"',`ADR` = '" + Memo1->Text +
											"',`Set` = '" + Edit9->Text +
											"',`remove` = '" + Edit10->Text +
											"',`Analizi` = '" + Edit4->Text +
											"',`Vipiski` = '" + Edit11->Text +
											"'WHERE `NomKlasF` = '"+ id +"'";

		  int count = SQL_Query(query,INI_load("Database","Table"));
		  if(count != 0)
		  {
		   Log("Изменение данных для '"+Edit1->Text+" "+Edit2->Text+" "+Edit3->Text+"'.");
           INI_save("ICO",ComboBox3->Text,IntToStr(ComboBoxEx1->ItemIndex));
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

  ClearEdit();
  Form1->TabUpdate("");
  Form1->PageControl1Change(Edit1);
  this->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button3Click(TObject *Sender)
{
 Log("Отменено пользователем.");
 ClearEdit();
 Form4->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit9KeyPress(TObject *Sender, System::WideChar &Key)
{
 if(IsCharAlpha(Key))Key = 0;
 if  (Key == VK_BACK) Edit9->Text="";
 if(Edit9->Text.Length()==2 || Edit9->Text.Length()==5) Edit9->Text=Edit9->Text.Insert(".",Edit9->Text.Length()+1);
 Edit9->SelStart=Edit9->Text.Length();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button5Click(TObject *Sender)
{
 MonthCalendar1->Visible = true;
 cal=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button6Click(TObject *Sender)
{
 MonthCalendar1->Visible = true;
 cal=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm4::MonthCalendar1DblClick(TObject *Sender)
{
 if(cal==0)
 {
	Edit9->Text = MonthCalendar1->Date.FormatString(MonthCalendar1->Date).Delete(7,2);
	MonthCalendar1->Visible = false;
 }
 if(cal==1)
 {
	Edit10->Text = MonthCalendar1->Date.FormatString(MonthCalendar1->Date).Delete(7,2);
	MonthCalendar1->Visible = false;
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm4::ClearEdit(void)
{
   for(int i = 0; i < ComponentCount; i++)
	{
		TEdit* edit;
		edit = dynamic_cast<TEdit*>(Components[i]);
		if(edit)
		edit->Text = "";
	}
	ComboBox1->Clear();
	ComboBox2->ItemIndex = 0;
	ComboBoxEx1->Clear();
	Memo1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Button4Click(TObject *Sender)
{
 if(Application->MessageBox(L"Вы действительно хотите удалить эту запись? ",
						 L"Очистка истории",
						 MB_YESNO) < 7)
 {
 Log("123Удаление записи...");

  if(SQL_Connect() > 0)
		 {
		AnsiString query = "DELETE FROM `"	+INI_load("Database","DBase1")+"`.`"
											+INI_load("Database","Table")+"` WHERE `NomKlasF` = '"+id+"'";

		  int count = SQL_Query(query,INI_load("Database","Table"));
		  if(count != 0)
		  {
		   Log("Запись '"+Edit1->Text+" "+Edit2->Text+" "+Edit3->Text+"' удалена.");
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

  ClearEdit();
  Form1->TabUpdate("");
  Form1->PageControl1Change(Edit1);
  this->Close();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::ComboBox3Select(TObject *Sender)
{
 ComboBoxEx1->ItemIndex = StrToInt(INI_load("ICO",ComboBox3->Text));
}
//---------------------------------------------------------------------------

AnsiString __fastcall ID_Search(AnsiString Table_Name)
{
 int r,count,i = 0;

  AnsiString query="SELECT * FROM `"+INI_load("Database","DBase1")+"`.`"+
								Table_Name+"` GROUP BY `NomKlasF`";
  count = SQL_Query(query,Table_Name);
  if(count != 0)
  {
   for(i = 0;i <= count; i++)
   {
	r = 0;
	for(int j = 0;j <= count; j++)
	{
	 if(Table_Name == INI_load("Database","Table") && Pacient[j].NomKlasF == i)
	 {
	  r = 1;
	  break;
	 }
	 if(Table_Name == "Users" && Users[j].NomKlasF == i)
	 {
	  r = 1;
	  break;
	 }
	}
	if(r == 0) break;
   }
  }
  else
  {
   Log("Ошибка отправки запроса!");
  }

  return(i);
}
//---------------------------------------------------------------------------
void __fastcall TForm4::Edit10KeyPress(TObject *Sender, System::WideChar &Key)
{
 if(IsCharAlpha(Key))Key = 0;
 if  (Key == VK_BACK) Edit10->Text="";
 if(Edit10->Text.Length()==2 || Edit10->Text.Length()==5) Edit10->Text=Edit10->Text.Insert(".",Edit10->Text.Length()+1);
 Edit10->SelStart=Edit10->Text.Length();
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Edit1KeyPress(TObject *Sender, System::WideChar &Key)
{
 if  (Key == VK_BACK) Edit1->Clear();
 AnsiString ForbiddenChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
 if(!ForbiddenChars.Pos(Key)) Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Edit2KeyPress(TObject *Sender, System::WideChar &Key)
{
 if  (Key == VK_BACK) Edit2->Clear();
 AnsiString ForbiddenChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
 if(!ForbiddenChars.Pos(Key)) Key = 0;
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Edit3KeyPress(TObject *Sender, System::WideChar &Key)
{
if  (Key == VK_BACK) Edit3->Clear();
 AnsiString ForbiddenChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя";
 if(!ForbiddenChars.Pos(Key)) Key = 0;
}
//---------------------------------------------------------------------------

