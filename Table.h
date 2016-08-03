//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef TableH
#define TableH
#include <SysUtils.hpp>
struct Table_Pacient    //Структура таблицы Pacient
{
	AnsiString NomKlasF;//Идентификатор записи
	AnsiString F;  		//Фамилия(50)
	AnsiString I;    	//Имя(50)
	AnsiString O;    	//Отчество(50)
	AnsiString Year;    //Год рождения(4)
	AnsiString Sex;    	//Пол(1)
	AnsiString Dok;  	//Документ(40)
	AnsiString Arxive;	//Архив(40)
	AnsiString Uchet; 	//Учёт(40)
	AnsiString Nkart;  	//Номер кариы(40)
	AnsiString Cod;    	//Шифр(40)
	AnsiString ADR;    	//Адрес(60)
	AnsiString Set;     //Дата постановки учёта(20)
	AnsiString remove;  //Дата снятия учёта(20)
	AnsiString Analizi; //Анализы(50)
	AnsiString Vipiski; //Выписки(50)
};
struct Users    //Структура таблицы Pacient
{
	AnsiString NomKlasF;         	//8
	AnsiString Login;		//100
	AnsiString Password;	//100
	AnsiString Seans_time;	//50
	AnsiString level;	//1

};
//---------------------------------------------------------------------------
#endif
