object Form6: TForm6
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1040#1074#1090#1086#1088#1080#1079#1072#1094#1080#1103
  ClientHeight = 138
  ClientWidth = 250
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnClose = FormClose
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 241
    Height = 137
    Caption = #1059#1082#1072#1078#1080#1090#1077' '#1089#1074#1086#1080' '#1076#1072#1085#1085#1099#1077':'
    TabOrder = 0
    object Label1: TLabel
      Left = 194
      Top = 19
      Width = 30
      Height = 13
      Caption = #1051#1086#1075#1080#1085
      Color = clBtnFace
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBtnText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
      StyleElements = [seClient, seBorder]
    end
    object Label2: TLabel
      Left = 194
      Top = 46
      Width = 37
      Height = 13
      Caption = #1055#1072#1088#1086#1083#1100
      StyleElements = [seClient, seBorder]
    end
    object Edit1: TEdit
      Left = 3
      Top = 16
      Width = 185
      Height = 21
      TabOrder = 0
      OnChange = Edit1Change
    end
    object Edit2: TEdit
      Left = 3
      Top = 43
      Width = 185
      Height = 21
      PasswordChar = '*'
      TabOrder = 1
      OnChange = Edit2Change
      OnKeyPress = Edit2KeyPress
    end
    object CheckBox1: TCheckBox
      Left = 3
      Top = 70
      Width = 134
      Height = 17
      Caption = #1054#1090#1086#1073#1088#1072#1078#1072#1090#1100' '#1089#1080#1084#1074#1086#1083#1099
      TabOrder = 2
      OnClick = CheckBox1Click
    end
    object Button1: TButton
      Left = 74
      Top = 101
      Width = 77
      Height = 25
      Caption = #1042#1086#1081#1090#1080
      TabOrder = 3
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 157
      Top = 101
      Width = 75
      Height = 25
      Caption = #1054#1090#1084#1077#1085#1072
      TabOrder = 4
      OnClick = Button2Click
    end
  end
end
