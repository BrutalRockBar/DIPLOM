object Form2: TForm2
  Left = 0
  Top = 0
  BorderStyle = bsDialog
  Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
  ClientHeight = 329
  ClientWidth = 573
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poMainFormCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object TreeView1: TTreeView
    Left = 0
    Top = 0
    Width = 137
    Height = 289
    Indent = 19
    TabOrder = 0
    OnChange = TreeView1Change
    Items.NodeData = {
      0303000000340000000000000000000000FFFFFFFFFFFFFFFF00000000000000
      0000000000010B1F043E0434043A043B044E04470435043D0438043504280000
      000000000000000000FFFFFFFFFFFFFFFF000000000000000000000000010521
      04420438043B043804360000000000000000000000FFFFFFFFFFFFFFFF000000
      000000000000000000010C1E04420447045104420420003F043E04470442043E
      043904}
  end
  object GroupBox1: TGroupBox
    Left = 143
    Top = 0
    Width = 422
    Height = 137
    Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080' '#1087#1086#1076#1082#1083#1102#1095#1077#1085#1080#1103
    TabOrder = 1
    object Label1: TLabel
      Left = 138
      Top = 26
      Width = 31
      Height = 13
      Caption = #1040#1076#1088#1077#1089
    end
    object Label2: TLabel
      Left = 138
      Top = 53
      Width = 25
      Height = 13
      Caption = #1055#1086#1088#1090
    end
    object Label3: TLabel
      Left = 138
      Top = 80
      Width = 30
      Height = 13
      Caption = #1051#1086#1075#1080#1085
    end
    object Label4: TLabel
      Left = 138
      Top = 107
      Width = 37
      Height = 13
      Caption = #1055#1072#1088#1086#1083#1100
    end
    object Edit1: TEdit
      Left = 11
      Top = 23
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 11
      Top = 50
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 11
      Top = 77
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 11
      Top = 104
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object GroupBox3: TGroupBox
      Left = 181
      Top = 15
      Width = 234
      Height = 105
      Caption = #1041#1072#1079#1072' '#1076#1072#1085#1085#1099#1093
      TabOrder = 4
      object Label6: TLabel
        Left = 132
        Top = 45
        Width = 66
        Height = 13
        Caption = #1048#1084#1103' '#1090#1072#1073#1083#1080#1094#1099
      end
      object Label5: TLabel
        Left = 132
        Top = 18
        Width = 23
        Height = 13
        Caption = #1041#1072#1079#1072
      end
      object Button2: TButton
        Left = 132
        Top = 69
        Width = 99
        Height = 25
        Caption = #1057#1086#1079#1076#1072#1090#1100' '#1095#1080#1089#1090#1091#1102
        TabOrder = 0
        OnClick = Button2Click
      end
      object Edit6: TEdit
        Left = 5
        Top = 42
        Width = 121
        Height = 21
        TabOrder = 1
      end
      object Edit5: TEdit
        Left = 5
        Top = 15
        Width = 121
        Height = 21
        TabOrder = 2
      end
    end
  end
  object GroupBox2: TGroupBox
    Left = 143
    Top = 0
    Width = 422
    Height = 137
    Caption = #1057#1090#1080#1083#1080
    TabOrder = 2
    Visible = False
    object ListBox1: TListBox
      Left = 11
      Top = 12
      Width = 406
      Height = 113
      ItemHeight = 13
      Items.Strings = (
        'Amakrits'
        'Amethyst Kamri'
        'Aqua Graphite'
        'Aqua Light Slate'
        'Auric'
        'Carbon'
        'Charcoal Dark Slate'
        'Cobalt XEMedia'
        'Cyan Dusk'
        'Cyan Night'
        'Emerald Light Slate'
        'Golden Graphite'
        'Iceberg Classico'
        'Lavender Classico'
        'Light'
        'Luna'
        'Metropolis UI Black'
        'Metropolis UI Blue'
        'Metropolis UI Dark'
        'Metropolis UI Green'
        'Obsidian'
        'Ruby Graphite'
        'Sapphire Kamri'
        'Silver'
        'Slate Classico'
        'Smokey Quartz Kamri'
        'Turquoise Gray')
      TabOrder = 0
      OnClick = ListBox1Click
    end
  end
  object Button3: TButton
    Left = 490
    Top = 291
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button1: TButton
    Left = 409
    Top = 291
    Width = 75
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 4
    OnClick = Button1Click
  end
  object GroupBox4: TGroupBox
    Left = 143
    Top = 0
    Width = 422
    Height = 285
    Caption = #1054#1090#1095#1105#1090' '#1087#1086#1095#1090#1086#1081
    TabOrder = 5
    Visible = False
    object Label7: TLabel
      AlignWithMargins = True
      Left = 11
      Top = 14
      Width = 405
      Height = 13
      Caption = 
        #1044#1072#1085#1085#1072#1103' '#1086#1087#1094#1080#1103' '#1087#1086#1079#1074#1086#1083#1103#1077#1090' '#1086#1090#1089#1099#1083#1072#1090#1100' '#1089#1086#1093#1088#1072#1085#1105#1085#1085#1099#1081' '#1086#1090#1095#1105#1090' '#1085#1072' e-mail '#1087#1086#1083#1100 +
        #1079#1086#1074#1072#1090#1077#1083#1103' '
      WordWrap = True
    end
    object Label8: TLabel
      Left = 215
      Top = 60
      Width = 75
      Height = 13
      Caption = #1040#1076#1088#1077#1089' '#1089#1077#1088#1074#1077#1088#1072
    end
    object Label10: TLabel
      Left = 175
      Top = 207
      Width = 30
      Height = 13
      Caption = #1084#1080#1085#1091#1090
    end
    object Label9: TLabel
      Left = 155
      Top = 239
      Width = 42
      Height = 19
      Caption = '12:59'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label11: TLabel
      Left = 215
      Top = 87
      Width = 25
      Height = 13
      Caption = #1055#1086#1088#1090
    end
    object Label12: TLabel
      Left = 215
      Top = 114
      Width = 153
      Height = 13
      Caption = #1051#1086#1075#1080#1085' '#1086#1090' '#1103#1097#1080#1082#1072' (test@mail.ru)'
    end
    object Label13: TLabel
      Left = 215
      Top = 141
      Width = 88
      Height = 13
      Caption = #1055#1072#1088#1086#1083#1100' '#1086#1090' '#1103#1097#1080#1082#1072
    end
    object Label14: TLabel
      Left = 215
      Top = 168
      Width = 132
      Height = 13
      Caption = #1040#1076#1088#1077#1089#1072#1090' (mail@yandex.ru)'
    end
    object Edit7: TEdit
      Left = 11
      Top = 57
      Width = 198
      Height = 21
      TabOrder = 0
    end
    object CheckBox1: TCheckBox
      Left = 11
      Top = 33
      Width = 318
      Height = 17
      Caption = #1040#1074#1090#1086#1084#1072#1090#1080#1095#1077#1089#1082#1080' '#1092#1086#1088#1084#1080#1088#1086#1074#1072#1090#1100' '#1086#1090#1095#1105#1090' '#1080' '#1086#1090#1089#1099#1083#1072#1090#1100' '#1085#1072' e-mail'
      TabOrder = 1
    end
    object Edit8: TEdit
      Left = 132
      Top = 204
      Width = 37
      Height = 21
      TabOrder = 2
    end
    object RadioButton1: TRadioButton
      Left = 13
      Top = 206
      Width = 113
      Height = 17
      Caption = #1054#1090#1089#1099#1083#1072#1090#1100' '#1082#1072#1078#1076#1099#1077
      TabOrder = 3
    end
    object RadioButton2: TRadioButton
      Left = 13
      Top = 237
      Width = 119
      Height = 17
      Caption = #1056#1072#1079' '#1074' '#1076#1077#1085#1100'.   '#1042#1088#1077#1084#1103':'
      Checked = True
      TabOrder = 4
      TabStop = True
    end
    object Button4: TButton
      Left = 132
      Top = 234
      Width = 17
      Height = 15
      Caption = '+'
      TabOrder = 5
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 132
      Top = 248
      Width = 17
      Height = 14
      Caption = '-'
      TabOrder = 6
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 203
      Top = 234
      Width = 17
      Height = 15
      Caption = '+'
      TabOrder = 7
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 203
      Top = 248
      Width = 17
      Height = 14
      Caption = '-'
      TabOrder = 8
      OnClick = Button7Click
    end
    object Edit9: TEdit
      Left = 11
      Top = 84
      Width = 198
      Height = 21
      TabOrder = 9
    end
    object Edit10: TEdit
      Left = 11
      Top = 111
      Width = 198
      Height = 21
      TabOrder = 10
    end
    object Edit11: TEdit
      Left = 11
      Top = 138
      Width = 198
      Height = 21
      PasswordChar = '*'
      TabOrder = 11
    end
    object Edit12: TEdit
      Left = 11
      Top = 165
      Width = 198
      Height = 21
      TabOrder = 12
    end
  end
end
