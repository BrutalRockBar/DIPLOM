//---------------------------------------------------------------------------
#include <vcl.h>
#ifndef TableH
#define TableH
#include <SysUtils.hpp>
struct Table_Pacient    //��������� ������� Pacient
{
	AnsiString NomKlasF;//������������� ������
	AnsiString F;  		//�������(50)
	AnsiString I;    	//���(50)
	AnsiString O;    	//��������(50)
	AnsiString Year;    //��� ��������(4)
	AnsiString Sex;    	//���(1)
	AnsiString Dok;  	//��������(40)
	AnsiString Arxive;	//�����(40)
	AnsiString Uchet; 	//����(40)
	AnsiString Nkart;  	//����� �����(40)
	AnsiString Cod;    	//����(40)
	AnsiString ADR;    	//�����(60)
	AnsiString Set;     //���� ���������� �����(20)
	AnsiString remove;  //���� ������ �����(20)
	AnsiString Analizi; //�������(50)
	AnsiString Vipiski; //�������(50)
};
struct Users    //��������� ������� Pacient
{
	AnsiString NomKlasF;         	//8
	AnsiString Login;		//100
	AnsiString Password;	//100
	AnsiString Seans_time;	//50
	AnsiString level;	//1

};
//---------------------------------------------------------------------------
#endif
