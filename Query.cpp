//---------------------------------------------------------------------------

#pragma hdrstop

#include "Global_Form.h"
#include "INI.h"
#include "Query.h"
#include "Table.h"
#include "History.h"
#include <vcl.h>
#define __LCC__
#include <mysql.h>
#pragma package(smart_init)
MYSQL *Connect;
MYSQL_RES *Res;
MYSQL_ROW Row;
MYSQL_FIELD *Fiel;
AnsiString query;
int Row_Count;
extern Table_Pacient Pacient[100000];
extern Users Users[100000];

//---------------------------------------------------------------------------
//Функция подключения к серверу:
//Функция возвращает 0 если возникла ошибка и 1 при удачном подключении.
int __fastcall SQL_Connect(void)
{
 Log("Подключение к серверу: "	+INI_load("MySQL","IP")
								+":"
								+INI_load("MySQL","Port")
								+"@"
								+INI_load("MySQL","Login"));
 int result = 1; 
 Connect = mysql_init(Connect);
 if(!mysql_real_connect(Connect,
						INI_load("MySQL","IP").c_str(),
						INI_load("MySQL","Login").c_str(),
						INI_load("MySQL","Password").c_str(),
						"",
						INI_load("MySQL","Port").ToInt(),
						NULL,
						0))
   {
	result = 0;
	AnsiString err = mysql_error(Connect);
	Log("Ошибка: "+err);
   }
 return(result);
}
//---------------------------------------------------------------------------
//Функция отправки запроса:
//query - текст запроса.
//Table_name - имя таблицы в которую будет выполнен запрос.
//Функция возвращает 0 если возникла ошибка и 1 либо количество строк при удачном выполнении.
int __fastcall SQL_Query(AnsiString query, AnsiString Table_name)
{
 int result = 1;
  if (mysql_real_query(Connect,query.c_str(),query.Length()) > 0)
   {
	result = 0;

	AnsiString err = mysql_error(Connect);
	Log("Ошибка: "+err);
   }

   Res = mysql_store_result(Connect);
			if(Res > 0)
			{
			   if(Table_name == INI_load("Database","Table"))
				{
					int i = 0;
					while (Row = mysql_fetch_row(Res))
					{
						Pacient[i].NomKlasF = Row[0];
						Pacient[i].F = Row[1];
						Pacient[i].I = Row[2];
						Pacient[i].O = Row[3];
						Pacient[i].Year = Row[4];
						Pacient[i].Sex = Row[5];
						Pacient[i].Dok = Row[6];
						Pacient[i].Arxive = Row[7];
						Pacient[i].Uchet = Row[8];
						Pacient[i].Nkart = Row[9];
						Pacient[i].Cod = Row[10];
						Pacient[i].ADR = Row[11];
						Pacient[i].Set = Row[12];
						Pacient[i].remove = Row[13];
						Pacient[i].Analizi = Row[14];
						Pacient[i].Vipiski = Row[15];

						i++;
					}
				}
				if(Table_name == "Users")
				{
					int i = 0;
					while (Row = mysql_fetch_row(Res))
					{
						Users[i].NomKlasF = Row[0];
						Users[i].Login = Row[1];
						Users[i].Password = Row[2];
						Users[i].Seans_time = Row[3];
						Users[i].level = Row[4];

						i++;
					}
				}

				if(Table_name == "Report")
				{

					Form1->ADOQuery1->ExecSQL();
					int i = 0;
					while (Row = mysql_fetch_row(Res))
					{
						Form1->ADOTable1->Insert();
						Form1->ADOTable1->FieldByName("NomKlasF")->AsString = i+1;
						Form1->ADOTable1->FieldByName("F")->AsString = Row[1];
						Form1->ADOTable1->FieldByName("I")->AsString = Row[2];
						Form1->ADOTable1->FieldByName("O")->AsString = Row[3];
						Form1->ADOTable1->FieldByName("Year")->AsString = Row[4];
						Form1->ADOTable1->FieldByName("Sex")->AsString = Row[5];
						Form1->ADOTable1->FieldByName("Dok")->AsString = Row[6];
						Form1->ADOTable1->FieldByName("Arxive")->AsString = Row[7];
						Form1->ADOTable1->FieldByName("Uchet")->AsString = Row[8];
						Form1->ADOTable1->FieldByName("Nkart")->AsString = Row[9];
						Form1->ADOTable1->FieldByName("Cod")->AsString = Row[10];
						Form1->ADOTable1->FieldByName("ADR")->AsString = Row[11];
						Form1->ADOTable1->FieldByName("Set")->AsString = Row[12];
						Form1->ADOTable1->FieldByName("remove")->AsString = Row[13];
						Form1->ADOTable1->FieldByName("Analizi")->AsString = Row[14];
						Form1->ADOTable1->FieldByName("Vipiski")->AsString = Row[15];
						Form1->ADOTable1->Post();

						i++;
					}
				 Form1->ADOTable1->First();
				}
				result = Res->row_count;
			}
  return (result);
}
//---------------------------------------------------------------------------
int __fastcall SQL_Connect_Close(void)
{
 Log("Конец сессии.");
 mysql_close(Connect);
}
//---------------------------------------------------------------------------
