//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Admin_panel.h"
#include "PacView.h"
#include "Global_Form.h"
#include "Table.h"
#include "INI.h"
#include "Query.h"
#include "History.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
extern Users Users[100000];
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm7::FormShow(TObject *Sender)
{
  Form1->Form_Shadow(1);
 //Названия столбцов таблицы.
	StringGrid1->Cells[0][0] = "id";
	StringGrid1->Cells[1][0] = "Login";
	StringGrid1->Cells[2][0] = "Password";
	StringGrid1->Cells[3][0] = "Time";
	StringGrid1->Cells[4][0] = "l";


	//Ширина столбцов
	StringGrid1->ColWidths[0] = 50;
	StringGrid1->ColWidths[1] = 200;
	StringGrid1->ColWidths[2] = 200;
	StringGrid1->ColWidths[3] = 200;
	StringGrid1->ColWidths[4] = 16;
	WriteGrid2("SELECT * FROM `"+INI_load("Database","DBase1")+"`.`Users`");
}
//---------------------------------------------------------------------------
void __fastcall TForm7::FormClose(TObject *Sender, TCloseAction &Action)
{
  Form1->Form_Shadow(0);
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
 if(SQL_Connect() > 0)
		 {
		AnsiString query = "INSERT INTO `"	+INI_load("Database","DBase1")
											+"`.`Users` (`NomKlasF`,"
													+"`Login`,"
													+"`Password`,"
													+"`Seans_time`,"
													+"`level`)"
											+"VALUES ('"+ID_Search("Users")
														+"', '', '', '', '1')";

		  int count = SQL_Query(query,"Users");
		  if(count == 0)
		  {
		   Log("Ошибка отправки запроса!");
		  }
		  SQL_Connect_Close();
		  WriteGrid2("SELECT * FROM `"+INI_load("Database","DBase1")+"`.`Users`");
		 }
		 else
		 {
		  ShowMessage("Не удалось подключиться к серверу!");
		  Log("Подключение с сервером отсутствует!");
		  Form1->Offline();
		 }
}
//---------------------------------------------------------------------------
 //Функция вывода структуры Pacient в таблицу.
void __fastcall TForm7::WriteGrid2(AnsiString query)
{
 if(SQL_Connect() > 0)
 {
  int count = SQL_Query(query,"Users");
  if(count != 0)
  {
	StringGrid1->RowCount = count+1;
	for(int i = 0;i < count+1; i++)
   {
	 StringGrid1->Cells[0][i+1] = Users[i].NomKlasF ;
	 StringGrid1->Cells[1][i+1] = Users[i].Login;
	 StringGrid1->Cells[2][i+1] = Users[i].Password;
	 StringGrid1->Cells[3][i+1] = Users[i].Seans_time;
	 StringGrid1->Cells[4][i+1] = Users[i].level;
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
  Form1->Offline();
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button2Click(TObject *Sender)
{
 if(Application->MessageBox(L"Вы действительно хотите удалить эту запись? ",
						 L"Очистка истории",
						 MB_YESNO) < 7)
 {
	if(SQL_Connect() > 0)
	{
		AnsiString query = "DELETE FROM `"	+INI_load("Database","DBase1")
											+"`.`Users` WHERE `NomKlasF` = '"
											+StringGrid1->Cells[0][StringGrid1->Row]+"'";

		int count = SQL_Query(query,"Users");
		if(count == 0)
		{
		   Log("Ошибка отправки запроса!");
		}
		SQL_Connect_Close();
		WriteGrid2("SELECT * FROM `"+INI_load("Database","DBase1")+"`.`Users`");
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
void __fastcall TForm7::Button3Click(TObject *Sender)
{
 if(SQL_Connect() > 0)
		 {
		 for(int i = 1; i <= SQL_Query("SELECT * FROM `"+INI_load("Database","DBase1")+"`.`Users`","Users"); i++)
		 {
			AnsiString query = "UPDATE `"+INI_load("Database","DBase1")
								+"`.`Users` SET `NomKlasF` = '" + StringGrid1->Cells[0][i] +
											"',`Login` = '" + StringGrid1->Cells[1][i]+
											"',`Password` = '" + StringGrid1->Cells[2][i] +
											"',`Seans_time` = '" + StringGrid1->Cells[3][i] +
											"',`level` = '" + StringGrid1->Cells[4][i] +
											"'WHERE `NomKlasF` = '"+ StringGrid1->Cells[0][i] +"'";

			int count = SQL_Query(query,"Users");
			if(count == 0)
			{
				Log("Ошибка отправки запроса!");
				break;
			}
		  }
		  SQL_Connect_Close();
		  WriteGrid2("SELECT * FROM `"+INI_load("Database","DBase1")+"`.`Users`");
          Label1->Visible = true;
		  Timer1->Enabled = true;
		 }
		 else
		 {
		  ShowMessage("Не удалось подключиться к серверу!");
		  Log("Подключение с сервером отсутствует!");
		  Form1->Offline();
		 }

}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button4Click(TObject *Sender)
{
 WriteGrid2("SELECT * FROM `"+INI_load("Database","DBase1")+"`.`Users`");
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Timer1Timer(TObject *Sender)
{
 Timer1->Enabled = false;
 Label1->Visible = false;
}
//---------------------------------------------------------------------------
