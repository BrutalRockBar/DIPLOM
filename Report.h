//---------------------------------------------------------------------------

#ifndef ReportH
#define ReportH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include "frxClass.hpp"
#include "frxExportText.hpp"
#include "frxExportRTF.hpp"
//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TCheckBox *CheckBox7;
	TCheckBox *CheckBox8;
	TCheckBox *CheckBox11;
	TCheckBox *CheckBox12;
	TCheckBox *CheckBox14;
	TButton *Button1;
	TMemo *Memo1;
	TCheckBox *CheckBox15;
	TCheckBox *CheckBox16;
	TComboBox *ComboBox1;
	TComboBox *ComboBox2;
	TComboBox *ComboBox3;
	TComboBox *ComboBox4;
	TComboBox *ComboBox6;
	TComboBox *ComboBox5;
	TComboBox *ComboBox7;
	TComboBox *ComboBox8;
	TComboBox *ComboBox11;
	TComboBox *ComboBox12;
	TComboBox *ComboBox14;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TLabel *Label1;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TLabel *Label4;
	TEdit *Edit9;
	TEdit *Edit10;
	TEdit *Edit12;
	TEdit *Edit13;
	TEdit *Edit14;
	TComboBox *ComboBox15;
	TComboBox *ComboBox16;
	TButton *Button6;
	TButton *Button7;
	TTimer *Timer1;
	TfrxRTFExport *frxRTFExport1;
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ComboBox1Select(TObject *Sender);
	void __fastcall Edit1Change(TObject *Sender);
	void __fastcall ComboBox2Select(TObject *Sender);
	void __fastcall Edit2Change(TObject *Sender);
	void __fastcall ComboBox3Select(TObject *Sender);
	void __fastcall Edit3Change(TObject *Sender);
	void __fastcall ComboBox4Select(TObject *Sender);
	void __fastcall Edit4Change(TObject *Sender);
	void __fastcall ComboBox5Select(TObject *Sender);
	void __fastcall Edit5Change(TObject *Sender);
	void __fastcall ComboBox6Select(TObject *Sender);
	void __fastcall Edit6Change(TObject *Sender);
	void __fastcall ComboBox7Select(TObject *Sender);
	void __fastcall Edit7Change(TObject *Sender);
	void __fastcall ComboBox8Select(TObject *Sender);
	void __fastcall Edit8Change(TObject *Sender);
	void __fastcall Edit9Change(TObject *Sender);
	void __fastcall Edit10Change(TObject *Sender);
	void __fastcall ComboBox11Select(TObject *Sender);
	void __fastcall ComboBox12Select(TObject *Sender);
	void __fastcall Edit12Change(TObject *Sender);
	void __fastcall Edit13Change(TObject *Sender);
	void __fastcall ComboBox14Select(TObject *Sender);
	void __fastcall Edit14Change(TObject *Sender);
	void __fastcall ComboBox15Select(TObject *Sender);
	void __fastcall ComboBox16Select(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall SendMail(void);
private:	// User declarations
public:		// User declarations
	__fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
