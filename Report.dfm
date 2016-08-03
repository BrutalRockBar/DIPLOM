object Form8: TForm8
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1052#1072#1089#1090#1077#1088' '#1086#1090#1095#1105#1090#1086#1074
  ClientHeight = 370
  ClientWidth = 388
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
    Top = 3
    Width = 380
    Height = 366
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1086#1090#1095#1105#1090#1072':'
    TabOrder = 0
    object Label1: TLabel
      Left = 298
      Top = 96
      Width = 16
      Height = 13
      Caption = '<>'
    end
    object Label4: TLabel
      Left = 299
      Top = 211
      Width = 16
      Height = 13
      Caption = '<>'
    end
    object CheckBox1: TCheckBox
      Left = 3
      Top = 25
      Width = 97
      Height = 17
      Caption = #1060#1072#1084#1080#1083#1080#1103
      TabOrder = 0
    end
    object CheckBox2: TCheckBox
      Left = 3
      Top = 48
      Width = 97
      Height = 17
      Caption = #1048#1084#1103
      TabOrder = 1
    end
    object CheckBox3: TCheckBox
      Left = 3
      Top = 71
      Width = 97
      Height = 17
      Caption = #1054#1090#1095#1077#1089#1090#1074#1086
      TabOrder = 2
    end
    object CheckBox4: TCheckBox
      Left = 3
      Top = 94
      Width = 97
      Height = 17
      Caption = #1043#1086#1076' '#1088#1086#1078#1076#1077#1085#1080#1103
      TabOrder = 3
    end
    object CheckBox5: TCheckBox
      Left = 3
      Top = 117
      Width = 97
      Height = 17
      Caption = #1055#1086#1083
      TabOrder = 4
    end
    object CheckBox6: TCheckBox
      Left = 3
      Top = 140
      Width = 97
      Height = 17
      Caption = #1044#1086#1082#1091#1084#1077#1085#1090
      TabOrder = 5
    end
    object CheckBox7: TCheckBox
      Left = 3
      Top = 163
      Width = 97
      Height = 17
      Caption = #1040#1088#1093#1080#1074
      TabOrder = 6
    end
    object CheckBox8: TCheckBox
      Left = 3
      Top = 186
      Width = 97
      Height = 17
      Caption = #1059#1095#1105#1090
      TabOrder = 7
    end
    object CheckBox11: TCheckBox
      Left = 3
      Top = 209
      Width = 97
      Height = 17
      Caption = #1053#1086#1084#1077#1088' '#1082#1072#1088#1090#1099
      TabOrder = 8
    end
    object CheckBox12: TCheckBox
      Left = 3
      Top = 232
      Width = 97
      Height = 17
      Caption = #1064#1080#1092#1088
      TabOrder = 9
    end
    object CheckBox14: TCheckBox
      Left = 3
      Top = 255
      Width = 97
      Height = 17
      Caption = #1040#1076#1088#1077#1089
      TabOrder = 10
    end
    object Button1: TButton
      Left = 286
      Top = 332
      Width = 82
      Height = 25
      Caption = #1057#1086#1079#1076#1072#1090#1100
      TabOrder = 11
      OnClick = Button1Click
    end
    object Memo1: TMemo
      Left = 106
      Top = 3
      Width = 361
      Height = 17
      TabOrder = 12
      Visible = False
    end
    object CheckBox15: TCheckBox
      Left = 3
      Top = 278
      Width = 97
      Height = 17
      Caption = #1040#1085#1072#1083#1080#1079#1099
      TabOrder = 13
    end
    object CheckBox16: TCheckBox
      Left = 3
      Top = 301
      Width = 97
      Height = 17
      Caption = #1042#1099#1087#1080#1089#1082#1080
      TabOrder = 14
    end
    object ComboBox1: TComboBox
      Left = 96
      Top = 23
      Width = 145
      Height = 21
      TabOrder = 15
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox1Select
      Items.Strings = (
        #1058#1086#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077
        #1063#1072#1089#1090#1080#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077)
    end
    object ComboBox2: TComboBox
      Left = 96
      Top = 46
      Width = 145
      Height = 21
      TabOrder = 16
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox2Select
      Items.Strings = (
        #1058#1086#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077
        #1063#1072#1089#1090#1080#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077)
    end
    object Edit1: TEdit
      Left = 247
      Top = 23
      Width = 121
      Height = 21
      TabOrder = 17
      StyleElements = [seFont, seBorder]
      OnChange = Edit1Change
    end
    object Edit2: TEdit
      Left = 247
      Top = 46
      Width = 121
      Height = 21
      TabOrder = 18
      StyleElements = [seFont, seBorder]
      OnChange = Edit2Change
    end
    object Edit3: TEdit
      Left = 247
      Top = 69
      Width = 121
      Height = 21
      TabOrder = 19
      StyleElements = [seFont, seBorder]
      OnChange = Edit3Change
    end
    object Edit4: TEdit
      Left = 247
      Top = 92
      Width = 43
      Height = 21
      TabOrder = 20
      StyleElements = [seFont, seBorder]
      OnChange = Edit4Change
    end
    object Edit5: TEdit
      Left = 325
      Top = 92
      Width = 43
      Height = 21
      TabOrder = 21
      StyleElements = [seFont, seBorder]
      OnChange = Edit5Change
    end
    object Edit6: TEdit
      Left = 247
      Top = 138
      Width = 121
      Height = 21
      TabOrder = 22
      StyleElements = [seFont, seBorder]
      OnChange = Edit6Change
    end
    object Edit7: TEdit
      Left = 247
      Top = 161
      Width = 121
      Height = 21
      TabOrder = 23
      StyleElements = [seFont, seBorder]
      OnChange = Edit7Change
    end
    object Edit10: TEdit
      Left = 247
      Top = 230
      Width = 121
      Height = 21
      TabOrder = 24
      StyleElements = [seFont, seBorder]
      OnChange = Edit10Change
    end
    object Edit12: TEdit
      Left = 247
      Top = 253
      Width = 121
      Height = 21
      TabOrder = 25
      StyleElements = [seFont, seBorder]
      OnChange = Edit12Change
    end
    object Edit13: TEdit
      Left = 247
      Top = 276
      Width = 121
      Height = 21
      TabOrder = 26
      StyleElements = [seFont, seBorder]
      OnChange = Edit13Change
    end
    object Edit14: TEdit
      Left = 247
      Top = 299
      Width = 121
      Height = 21
      TabOrder = 27
      StyleElements = [seFont, seBorder]
      OnChange = Edit14Change
    end
    object ComboBox11: TComboBox
      Left = 96
      Top = 207
      Width = 145
      Height = 21
      TabOrder = 28
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox11Select
      Items.Strings = (
        #1044#1086
        #1055#1086#1089#1083#1077
        #1055#1077#1088#1080#1086#1076)
    end
    object ComboBox12: TComboBox
      Left = 96
      Top = 230
      Width = 145
      Height = 21
      TabOrder = 29
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox12Select
      Items.Strings = (
        #1058#1086#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077
        #1063#1072#1089#1090#1080#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077)
    end
    object ComboBox14: TComboBox
      Left = 96
      Top = 253
      Width = 145
      Height = 21
      TabOrder = 30
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox14Select
      Items.Strings = (
        #1059#1083#1080#1094#1072)
    end
    object ComboBox15: TComboBox
      Left = 96
      Top = 276
      Width = 145
      Height = 21
      TabOrder = 31
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox15Select
      Items.Strings = (
        #1058#1086#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077
        #1063#1072#1089#1090#1080#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077)
    end
    object ComboBox16: TComboBox
      Left = 96
      Top = 299
      Width = 145
      Height = 21
      TabOrder = 32
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox16Select
      Items.Strings = (
        #1058#1086#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077
        #1063#1072#1089#1090#1080#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077)
    end
    object ComboBox3: TComboBox
      Left = 96
      Top = 69
      Width = 145
      Height = 21
      TabOrder = 33
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox3Select
      Items.Strings = (
        #1058#1086#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077
        #1063#1072#1089#1090#1080#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077)
    end
    object ComboBox4: TComboBox
      Left = 96
      Top = 92
      Width = 145
      Height = 21
      TabOrder = 34
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox4Select
      Items.Strings = (
        #1044#1086
        #1055#1086#1089#1083#1077
        #1055#1077#1088#1080#1086#1076)
    end
    object ComboBox5: TComboBox
      Left = 96
      Top = 115
      Width = 145
      Height = 21
      TabOrder = 35
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox5Select
      Items.Strings = (
        #1052
        #1046)
    end
    object ComboBox6: TComboBox
      Left = 96
      Top = 138
      Width = 145
      Height = 21
      TabOrder = 36
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox6Select
      Items.Strings = (
        #1058#1086#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077
        #1063#1072#1089#1090#1080#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077)
    end
    object ComboBox7: TComboBox
      Left = 96
      Top = 161
      Width = 145
      Height = 21
      TabOrder = 37
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox7Select
      Items.Strings = (
        #1058#1086#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077
        #1063#1072#1089#1090#1080#1095#1085#1086#1077' '#1089#1086#1074#1087#1072#1076#1077#1085#1080#1077)
    end
    object ComboBox8: TComboBox
      Left = 96
      Top = 184
      Width = 145
      Height = 21
      TabOrder = 38
      StyleElements = [seFont, seBorder]
      OnSelect = ComboBox8Select
    end
    object Edit8: TEdit
      Left = 247
      Top = 207
      Width = 43
      Height = 21
      TabOrder = 39
      StyleElements = [seFont, seBorder]
      OnChange = Edit8Change
    end
    object Edit9: TEdit
      Left = 325
      Top = 207
      Width = 43
      Height = 21
      TabOrder = 40
      StyleElements = [seFont, seBorder]
      OnChange = Edit9Change
    end
    object Button6: TButton
      Left = 3
      Top = 332
      Width = 75
      Height = 25
      Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
      TabOrder = 41
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 96
      Top = 332
      Width = 75
      Height = 25
      Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 42
      OnClick = Button7Click
    end
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 208
    Top = 328
  end
  object frxRTFExport1: TfrxRTFExport
    ShowDialog = False
    FileName = 'Reports\Report.rtf'
    UseFileCache = True
    ShowProgress = False
    OverwritePrompt = False
    DataOnly = False
    PictureType = gpPNG
    Wysiwyg = True
    Creator = 'FastReport'
    SuppressPageHeadersFooters = False
    HeaderFooterMode = hfText
    AutoSize = False
    Left = 256
    Top = 328
  end
end
