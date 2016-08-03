//---------------------------------------------------------------------------

#ifndef PacViewH
#define PacViewH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Graphics.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TGroupBox *GroupBox1;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TMemo *Memo1;
	TGroupBox *GroupBox2;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TComboBox *ComboBox3;
	TEdit *Edit8;
	TGroupBox *GroupBox3;
	TGroupBox *GroupBox4;
	TEdit *Edit4;
	TEdit *Edit11;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TLabel *Label13;
	TLabel *Label14;
	TLabel *Label15;
	TEdit *Edit9;
	TEdit *Edit10;
	TButton *Button5;
	TButton *Button6;
	TComboBoxEx *ComboBoxEx1;
	TMonthCalendar *MonthCalendar1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Edit9KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall MonthCalendar1DblClick(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall ComboBox3Select(TObject *Sender);
	void __fastcall Edit10KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit1KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, System::WideChar &Key);
private:	// User declarations
public:		// User declarations
	__fastcall TForm4(TComponent* Owner);
	void __fastcall ClearEdit(void);
};
AnsiString __fastcall ID_Search(AnsiString Table_Name);
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
