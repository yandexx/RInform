! ----------------------------------------------------------------------------
!
!  RussiaG:  Grammar table entries for the standard verbs library.
!  Russian version
!  Encoding: CP1251
!
!  Supplied for use with Inform 6 Release 6/11
!
!   (C) Grankin Andrey 2002
!   (C) Gayev Denis 2003-2004
!
!  Based on: English grammar Release 6/11 Serial number 040227
!
! ----------------------------------------------------------------------------

System_file;

! ----------------------------------------------------------------------------
!  "����-�������" (��������� ������� ����)
! ----------------------------------------------------------------------------

Verb meta '����!'
                *				-> Score
                * '����'			-> FullScore;

Verb meta '��������!'
                *				-> FullScore;

Verb meta 'q!' '�����!' '�����'
	  '����'
                *				-> Quit;

Verb meta '�����!' '���' '�������' '���������'
	  '����!' '������' '������'
	  'restore'
                *				-> Restore;

Verb meta '������' '��������!'
                *				-> Verify;

Verb meta '����!' '������'
	  'save'
                *				-> Save;

Verb meta '���' '������'
	  '������!'
	  '����������!'
	  '����������' '�������'
                *				-> Restart;

Verb meta '������!'
	  '����������!'
                * '���'				-> ScriptOn
                * '����'			-> ScriptOff;

! ������ ������

Verb meta '������!'
		* '���'				-> CommandsOn
		* '����'			-> CommandsOff;

Verb meta '�����!'
		*				-> CommandsRead;

Verb meta '����!'
                * '����'/'������'		-> LMode1
                * '��'/'����'			-> LMode2
                * '��'/'����'			-> LMode3;

Verb meta '�����!'
                * '���'				-> NotifyOn
                * '����'			-> NotifyOff;

Verb meta '�����!' '�����������!'
                *				-> Pronouns;

Verb meta '������!'
                *				-> Version;

#IFNDEF NO_PLACES;

Verb meta '�����!'
                *				-> Places;

Verb meta '��������!'
                *				-> Objects;

#ENDIF;

! ----------------------------------------------------------------------------
!  ���������� ������� � ��������
! ----------------------------------------------------------------------------

#ifdef DEBUG;

Verb meta '����!'

	! ����������� �������
	* '�����' number			-> TraceLevel
	* '�����' '���'				-> TraceOn
	* '�����' '����'			-> TraceOff

	! ��������� ��������
	* '���' '���'				-> ActionsOn
	* '���' '����'				-> ActionsOff

	! ������ �����������
	* '�����' '���'				-> RoutinesOn
	* '�����' '����'			-> RoutinesOff

	! ���������� ��������/�������
	* '������'/'�����' '���'		-> TimersOn
	* '������'/'�����' '����'		-> TimersOff

	! ���������
	* '�����' '���'				-> ChangesOn
	* '�����' '����'			-> ChangesOff

	! ���������� ������������
	* '������'				-> Predictable

	! ��������� �������� multi
	* '��' multi				-> XPurloin

	! ��������������� noun � noun
	* '���' noun '�' noun			-> XAbstract

	! ����� �������� ��������
	* '������'				-> XTree
	* '������' noun				-> XTree

	! ������������
	* '��' '�' number			-> Goto
	* '��' '�' noun				-> Gonear

	! ����� �������
	* '���'					-> Scope
	* '���' noun				-> Scope

	! ���������� �������
	* '������' special			-> Showverb
	
	! ���������� �������
	* '������'				-> Showobj
	* '������' multi			-> Showobj

	! �������� �����
	* '����' noun				-> Decline
 ;

#Ifdef TARGET_GLULX;
Verb meta '�������'
	*					-> Glklist;
#Endif; ! TARGET_

#ifnot;

[ NoMetaSub;
  "����-������� �������� ������ � ���������� ������!";
  ];

Verb meta '����'
	*					-> NoMeta;

#endif;

! -----------------------------------------
!  ������-������������ ��������
! -----------------------------------------

Object VerbDepot;

! -----------------------------------------
!  ����������� ������� �������
! -----------------------------------------

!! "noun" in nominative
[ cNom_noun;	return c_token (NOUN_TOKEN, csNom);	];

!! "noun" in accusative
[ cAcc_noun;	return c_token (NOUN_TOKEN, csAcc);	];

!! "noun" in genitive
[ cGen_noun;	return c_token (NOUN_TOKEN, csGen);	];

!! "noun" in dative
[ cDat_noun;	return c_token (NOUN_TOKEN, csDat);	];

!! "noun" in instrumental
[ cIns_noun;	return c_token (NOUN_TOKEN, csIns);	];

!! "noun" in prepositive
[ cPre_noun;	return c_token (NOUN_TOKEN, csPre);	];

!! "held" in instrumental
[ cIns_held;	return c_token (HELD_TOKEN, csIns);	];

!! "held" in accusative
[ cAcc_held;	return c_token (HELD_TOKEN, csAcc);	];

!! "held" in genitive ! y4n
[ cGen_held;	return c_token (HELD_TOKEN, csGen); ];

!! "worn" in accusative
!! (note: there's no 'worn' token)
[ cAcc_worn;	return c_token (HELD_TOKEN, csAcc);	];

!! "creature" in accusative
[ cAcc_creat;	return c_token (CREATURE_TOKEN, csAcc);	];

!! "creature" in genitive
[ cGen_creat;	return c_token (CREATURE_TOKEN, csGen);	];

!! "creature" in dative
[ cDat_creat;	return c_token (CREATURE_TOKEN, csDat);	];

!! "multi" in accusative
[ cAcc_multi;	return c_token (MULTI_TOKEN, csAcc);	];

!! "multiheld" in accusative
[ cAcc_multiheld;	return c_token (MULTIHELD_TOKEN, csAcc);	];

!! "multiexcept" in accusative
[ cAcc_multiexcept;	return c_token (MULTIEXCEPT_TOKEN, csAcc);	];

!! "multiinside" in accusative
[ cAcc_multiinside;	return c_token (MULTIINSIDE_TOKEN, csAcc);	];

! ----------------------------------------------------------------------------
!  � ���������� ������� �������
! ----------------------------------------------------------------------------

Verb '��!' '��'
                *				-> Yes;

Verb '���!' '���'
                *				-> No;

Verb '���' '���' '������' '����' '�����' '�����' '����'
                *                                -> Strong
                * topic                          -> Strong;
Verb '����' '����'
                *                                -> Mild
                * topic                          -> Mild; 

!
!	���������
!

Verb	'�//' 'i!'
	'���!' '������!' '���������!'
                *					-> Inv
                * '�����'/'���'				-> InvTall
                * '�����'/'���'				-> InvWide;

Object "���������" VerbDepot
	with name '�//' 'i!' '���!' '������!';

!
!	������ � �����
!

! "��������"/"�������"
Verb	'l!' 'x!'
	'�!'
	'�����' '��' '�//'
	'��' '���' '����'
                *					-> Look
                * cNom_noun				-> Examine
                * cAcc_noun				-> Examine
                * '��' cAcc_noun		-> Examine
				* '�'/'��' cAcc_noun	-> Search
                * '������' cGen_noun		-> Search
                * '���' cIns_noun			-> LookUnder
                * '���' cAcc_noun			-> LookUnder
                * '�'/'��'/'���' topic '�'/'��' cPre_noun		-> Consult
                * '�'/'��' cPre_noun '�'/'��'/'���' topic		-> Consult;

Object "��������" VerbDepot
	with name 'l!' 'x!' '�!' '�����' '��' '�//' '��' '���' '����';

Verb '����' '��������'
                * cNom_noun -> Search
                * cAcc_noun -> Search;

Object "�������" VerbDepot
	with name '����' '��������';

! "������"
Verb	'���' '��������'
                * cAcc_noun				-> Examine
                * '�'/'��' cPre_noun '�'/'��'/'���' topic		-> Consult
                * '�'/'��'/'���' topic '�'/'��' cPre_noun		-> Consult;

Object "������" VerbDepot
	with name '���' '��������';

! "������"
Verb	'���' '��'
	'���' '��'
                * cAcc_noun				-> Search
                * '�'/'��' cPre_noun			-> Search
                * '�'/'��' cPre_noun '�'/'��'/'���' topic		-> Consult
                * '�'/'��'/'���' topic '�'/'��' cPre_noun		-> Consult
                * topic '�'/'��' cPre_noun		-> Consult
                * '�'/'��' cPre_noun topic		-> Consult;

Object "������" VerbDepot
	with name '���' '��' '���' '��';

!
!	������������ (����; ����� �/����� ��)
!

! ��������, ����������� �����������
[ ADirection; if (noun in compass) rtrue; rfalse; ];

! "����"/"������"/"�����"
Verb	'��'
	'���' '���'
	'��' '���' '�����'
                *					-> VagueGo
                * noun=ADirection			-> Go
                * '�'/'��'/'��' noun=ADirection		-> Go
                * cAcc_noun				-> Enter
                * '�'/'��'/'��' cAcc_noun		-> Enter
		* '�' cDat_noun				-> Enter;

Object "����" VerbDepot
	with name '��' '���' '���' '��' '���' '�����';

! "�����"
Verb	'���' '����'
                *					-> GoIn
                * '�'/'��'/'��' cAcc_noun		-> Enter;

Object "�����" VerbDepot
	with name '���' '����';

! "�����"
Verb	'���' '����'
	'��' '���'
		*					-> Exit
        * '������' -> Exit
		* '��'/'�'/'��' cGen_noun		-> Exit;

Object "�����" VerbDepot
	with name '���' '����' '��' '���';

! "������"
Verb	'���' '����'
                *					-> Exit
                * '��'/'�'/'��' cGen_noun		-> Exit
                * '��'/'�'/'��' cAcc_noun		-> Enter;

Object "������" VerbDepot
	with name '���' '����';

! "�����"/"����"
Verb	'���' '���' '���'
	'���' '���'
                * '��'/'�'/'��' cAcc_noun		-> Enter;

Object "�����" VerbDepot
	with name '���' '���' '���';

Object "����" VerbDepot
	with name '���' '���';

!
!	(�����/��������; ������/��������; �������)
!

! "�����"/"�����"/"������"/"�������"/"�������"
Verb	'��' '�����'
	'��' '���'
	'���'
	'������' '������'
	'����' '�����' '������'
                * cAcc_multi					-> Take
                * multiinside '��'/'�'/'��' noun	-> Remove
                * '��'/'�'/'��' noun multiinside	-> Remove reverse
                * cAcc_multiinside '��'/'�'/'��' cGen_noun	-> Remove
                * '��'/'�'/'��' cGen_noun cAcc_multiinside	-> Remove reverse;

Object "�����" VerbDepot
	with name '��' '�����' '��' '���' '���'
	'������' '������' '����' '�����' '������';

! "������"/"�����"/"������"/"���������"/"������"
Verb	'���'
	'�����' '����'
	'����'
	'����' '���'
	'���' '��'
                * cAcc_multiheld			-> Drop
                * cAcc_multiexcept '�'/'��' cAcc_noun	-> Insert
                * '�'/'��' cAcc_noun cAcc_multiexcept	-> Insert reverse
                * cAcc_multiexcept '������' cGen_noun	-> Insert
                * '������' cGen_noun cAcc_multiexcept	-> Insert reverse
                * cAcc_multiexcept '��' cAcc_noun	-> PutOn
                * '��' cAcc_noun cAcc_multiexcept	-> PutOn reverse;

Object "��������" VerbDepot
	with name '���' '�����' '����' '����' '����' '���' '���' '��';

! "�������"/"��������"/"�������"/"������"
Verb	'����'
	'����'
	'���'
	'��' '���'
                * cAcc_multiheld			-> Drop
                * held '�'/'��'/'��' cAcc_noun		-> ThrowAt
                * '�'/'��'/'��' cAcc_noun held		-> ThrowAt reverse
                * held cDat_creat			-> ThrowAt
                * cDat_creat held			-> ThrowAt reverse;

Object "�������" VerbDepot
	with name '����' '����' '���' '��' '���';

! "[�]���������"/"������"/"��������"
Verb	'������'
	'���'
	'�����'
                * cAcc_noun				-> Empty
                * cAcc_noun '�'/'��'/'��' cAcc_noun	-> EmptyT
                * '�'/'��'/'��' cAcc_noun cAcc_noun	-> EmptyT reverse;

Object "����������" VerbDepot
	with name '������' '���' '�����';

!
!	(������/�����)
!

! "������"/"�����"
Verb	'���' '��' '����' '���'
                * cAcc_held				-> Wear;

! "�������"/"�����"
Verb	'����' '��' '�����' '����'
		* cAcc_worn				-> Disrobe;

Object "������" VerbDepot
	with name '���' '��' '����' '���';

Object "�������" VerbDepot
	with name '����' '��' '�����' '����';

!
!	(�������/�������; ��������/��������; ��������/���������)
!

! "�������"
Verb	'����'
                * cAcc_noun			-> Open
                * cAcc_noun cIns_held		-> Unlock
                * cIns_held cAcc_noun		-> Unlock reverse;

! "�������"
Verb	'����'
                * cAcc_noun			-> Close
                * cAcc_noun cIns_held		-> Lock
                * cIns_held cAcc_noun		-> Lock reverse;

Object "�������" VerbDepot
	with name '����';

Object "�������" VerbDepot
	with name '����';

! "��������"
Verb	'�����' '�����' '�����'
                * cAcc_noun cIns_held		-> Unlock
                * cIns_held cAcc_noun		-> Unlock reverse;

! "��������"
Verb	'�����' '�����' '����'
                * cAcc_noun cIns_held		-> Lock
                * cIns_held cAcc_noun		-> Lock reverse;

Object "��������" VerbDepot
	with name '�����' '�����' '�����';

Object "��������" VerbDepot
	with name '�����' '�����' '����';

! "��������"
Verb	'�����' '���'
                * cAcc_noun			-> SwitchOn;

! "���������"
Verb	'������' '����'
                * cAcc_noun			-> SwitchOff;

Object "��������" VerbDepot
	with name '�����' '���';

Object "���������" VerbDepot
	with name '������' '����';

!
!	������� � NPC
!	(����; ��������; �������; ��������; ��������)
!

! "����"/"����������"
Verb	'���'
	'�������' '�������'
                * cAcc_held cDat_creat		-> Give
                * cDat_creat cAcc_held		-> Give reverse;

Object "����������" VerbDepot
	with name '���' '�������' '�������';

! "��������"
Verb '�����' '�����'
                * cAcc_held cDat_creat		-> Show
                * cDat_creat cAcc_held		-> Show reverse;

Object "��������" VerbDepot
	with name '�����' '�����';

! "��������"
Verb '�����' '�����'
			* cDat_creat topic		-> Answer reverse
			* topic '���' cGen_creat	-> Answer;

Object "��������" VerbDepot
	with name '�����' '�����';

! "[���]�������"/"��������"
Verb	'����' '����'
	'�����'
                * cDat_creat '�'/'��'/'���'/'���' topic	-> Tell
                * cDat_creat topic		-> AskTo;

Object "�������" VerbDepot
	with name '����' '����' '�����';

! "[���]��������"
Verb	'�����'
                * cAcc_creat '�'/'��'/'���'/'���' topic		-> Ask
                * '�' cAcc_creat '�'/'��'/'���'/'���' topic	-> Ask
                * '�'/'��'/'���'/'���' topic '�' cAcc_creat	-> Ask reverse;

Object "��������" VerbDepot
	with name '�����';

! "[��/��]�������"
Verb	'����'
                * topic '�' cAcc_creat		-> AskFor
                * '�' cAcc_creat topic		-> AskFor reverse
                * cAcc_creat topic		-> AskTo;

Object "�������" VerbDepot
	with name '����';

!
!	������ ��������
!

! "����������"/"��������"
Verb	'�����'
	'�����' '����'
                *				-> Sorry;

Object "��������" VerbDepot
	with name '�����' '�����' '����';

! "[��]������"
Verb	'���' '���'
                *				-> WaveHands
                * cIns_noun			-> Wave;

Object "������" VerbDepot
	with name '���' '���';

! "����������"/"���������"
Verb	'�������'
	'������'
                * cAcc_noun			-> Set
                * cAcc_noun '��' special	-> SetTo
                * '��' special cAcc_noun	-> SetTo reverse;

Object "���������" VerbDepot
	with name '�������' '�����';

! "[����]�������"
Verb	'���' '����'
		* cAcc_noun				-> Push
                * cAcc_noun '��'/'�'/'��' cAcc_noun	-> Transfer
                * '��'/'�'/'��' cAcc_noun cAcc_noun	-> Transfer reverse;

Object "�������" VerbDepot
	with name '���' '����';

! "������"/"������"/"������"
Verb	'��' '���'
	'���' 
	'�����' '�����'
	'����' '����'
                * cAcc_noun				-> Pull
                * '��' cAcc_noun			-> Pull
                * cAcc_noun '��'/'�'/'��' cAcc_noun	-> Transfer
                * '��'/'�'/'��' cAcc_noun cAcc_noun	-> Transfer reverse;

Object "������" VerbDepot
	with name '��' '���' '���' '�����' '�����' '����' '����';

! "�������"/"������"/"������"
Verb	'����'
	'���'
	'���' '����' '�����'
                * cAcc_noun				-> Push
				* '��' cAcc_noun		-> Push
                * cAcc_noun '��'/'�'/'��' cAcc_noun	-> Transfer
                * '��'/'�'/'��' cAcc_noun cAcc_noun	-> Transfer reverse;

Object "�������" VerbDepot
	with name '����' '���' '���' '����' '�����';

! "�������"/"[��]�������"/"�������"
Verb	'���' '����'
	'����'
                * cAcc_noun			-> Turn;

Object "�������" VerbDepot
	with name '���' '����' '����';

! "�������"/"[�]����"/"���������"/"[�]������"/"[���]������"
Verb	'��' '��'
	'���'
	'����'
	'���'
	'����' '������'
                * cAcc_noun			-> Attack;

Object "���������" VerbDepot
	with name '��' '��' '���' '����' '���' '����' '������';

! "�������"
Verb	'�����' '�����'
                * '��' cAcc_noun		-> Attack;

Object "�������" VerbDepot
	with name '�����' '�����';

! "[�]�[�]����"
Verb	'z!'
	'�!'
	'��' '���'
                *				-> Wait;

Object "�����" VerbDepot
	with name 'z!' '�!' '��' '���';

! "[��]����"/"[��]�����"/"[�]������"
Verb	'��' '��'
	'��'
	'���'
                * cAcc_held			-> Eat;

Object "����" VerbDepot
	with name '��' '��' '��';

! "[��]����"
Verb	'��'
                * cAcc_noun			-> Drink;

Object "����" VerbDepot
	with name '��';

! "�����"/"�������"
Verb	'���'
	'����'
                *				-> Sleep;

Object "�����" VerbDepot
	with name '���' '����';

! "[���]������"
Verb	'���'
                *				-> Wake
                * cAcc_creat			-> WakeOther;

Object "������" VerbDepot
	with name '���';

! "����"
Verb	'��' '��'
                *				-> Sing;

Object "����" VerbDepot
	with name '��' '��';

! "[��]�����"
Verb	'���' '���'
                * '��' cAcc_noun	-> Climb
                * '��' cDat_noun    -> Climb
				* '�'/'��' cAcc_noun -> Enter;

Object "�����" VerbDepot
	with name '���' '���';

! "[��]���(�/�)��"
Verb	'���'
                * cAcc_noun			-> Buy;

Object "������" VerbDepot
	with name '���';

! "�����"/"[�/���]������"
Verb	'c��' '��' '���'
	'���'
                * cAcc_noun			-> Squeeze;

Object "�����" VerbDepot
	with name 'c��' '��' '���' '���';

! "�������"/"������"
Verb	'����' '����' '��'
	'���'
                *				-> Swim;

Object "�������" VerbDepot
	with name '����' '����'	'���' '��';

! "������[��]"
Verb	'���'
                * cAcc_noun			-> Swing
                * '��' cPre_noun		-> Swing;	! "��������"

Object "������" VerbDepot
	with name '���';

! "����"
Verb	'��'
                * '�'/'��' cAcc_held		-> Blow
                * cAcc_held			-> Blow;	! "������"

Object "����" VerbDepot
	with name '��';

! "������[��]"
Verb	'���'
                *				-> Pray;

Object "������" VerbDepot
	with name '���';

! "��������"/"��������"
Verb	'�����' '���'
	'�����'
                * cAcc_creat			-> Kiss;

Object "��������" VerbDepot
	with name '�����' '���'	'�����';

! "[��]������[��]"/"�������"
Verb	'���'
	'����' '����'
                *				-> Think;

Object "������" VerbDepot
	with name '���'	'����' '����';

! "������"/"�������"
Verb	'���'
                *				-> Smell
                * cAcc_noun			-> Smell;

Object "������" VerbDepot
	with name '���';

! "�������"
Verb	'����' '����' '����'
                *				-> Listen
                * cAcc_noun			-> Listen
                * '�' cDat_noun			-> Listen;	! "������������"

Object "�������" VerbDepot
	with name '����' '����' '����';

! "���[����/����]"/"������"/"������"
Verb	'����' '����'
	'���'
	'���'
                * cAcc_noun			-> Taste;

Object "�������" VerbDepot
	with name '����' '����' '���';

! "�������"/"�������"
Verb	'���' '����'
	'���'
                * cAcc_noun			-> Touch
                * '��' cGen_noun		-> Touch;	! "�����������"

Object "�������" VerbDepot
	with name '���' '����' '���';

! "�������[��]"/"������[��]"
Verb	'���' '���'
                * cGen_noun			-> Touch
                * '�' cDat_noun			-> Touch;	! "������������"

Object "���������" VerbDepot
	with name '���' '���';

! "������"
Verb	'���' '���' '��'
                * cAcc_noun			-> Rub;

Object "������" VerbDepot
	with name '���' '���' '��';

! "������"
Verb	'���' '���'
                * cAcc_noun			-> Tie
                * cAcc_noun '�' cDat_noun	-> Tie		! "���������"
                * '�' cDat_noun cAcc_noun	-> Tie reverse
                * cAcc_noun '�'/'��' cIns_noun	-> Tie		! "�������"
                * '�'/'��' cIns_noun cAcc_noun	-> Tie reverse;

Object "������" VerbDepot
	with name '���' '���';

! "����"/"���"
Verb	'���' '��'
                * cAcc_noun			-> Burn
                * cAcc_noun cIns_held		-> Burn
                * cIns_held cAcc_noun		-> Burn reverse;

Object "����" VerbDepot
	with name '���' '��';

! "���������"
Verb	'����'
                * cAcc_noun			-> Fill;

Object "���������" VerbDepot
	with name '����';

! "������"
Verb	'���' '���'
                * cAcc_noun			-> Cut;

Object "������" VerbDepot
	with name '���' '���';

! "�������"/"�������"
Verb	'����'
	'����' '����' '����'
                *				-> Jump
                * '�����' cAcc_noun		-> JumpOver;

Object "�������" VerbDepot
	with name '����' '����' '����' '����';

! "������"/"����"
Verb	'���'
	'��' '��'
                * cAcc_noun			-> Dig
                * cAcc_noun cIns_held		-> Dig
                * cIns_held cAcc_noun		-> Dig reverse;

Object "������" VerbDepot
	with name '���' '��' '��';

! ----------------------------------------------------------------------------

Global w_sense;

[ c_sense;

  w_sense = NextWord ();

  if (w_sense == '����' or '����' or '���' or '�����' or '�����')
	return GPR_PREPOSITION;

  return GPR_FAIL;
];

[ SenseSub;

  switch (w_sense) {
	'����':		<<Listen noun>>;
	'����':		<<Taste noun>>;
	'���', '�����':	<<Smell noun>>;
	'�����':	<<Touch noun>>;
	}

  "���������, ��� �� ������ ����������� ", (cAcc) noun, ".";
  ];

! "���������"
Verb	'����' '������'
		* cAcc_noun '��' c_sense	-> Sense
		* '��' c_sense cAcc_noun	-> Sense;

Object "���������" VerbDepot
	with name '����' '������';

! ----------------------------------------------------------------------------
!  � ���������� ����������� ������ (���� ��� �� ������ �������������)
! ----------------------------------------------------------------------------

#Stub AfterLife         0;
#Stub AfterPrompt       0;
#Stub Amusing           0;
#Stub BeforeParsing     0;
#Stub ChooseObjects     2;
#Stub DarkToDark        0;
#Stub DeathMessage      0;
#Stub GamePostRoutine   0;
#Stub GamePreRoutine    0;
#Stub InScope           1;
#Stub LookRoutine       0;
#Stub NewRoom           0;
#Stub ParseNumber       2;
#Stub ParserError       1;
#Stub PrintTaskName     1;
#Stub PrintVerb         1;
#Stub TimePasses        0;
#Stub UnknownVerb       1;

#Ifdef TARGET_GLULX;
#Stub HandleGlkEvent    2;
#Stub IdentifyGlkObject 4;
#Stub InitGlkWindow     1;
#Endif; ! TARGET_GLULX

#Ifndef PrintRank;
! Constant Make__PR;
! #Endif;
! #Ifdef Make__PR;
[ PrintRank; "."; ];
#Endif;

#Ifndef ParseNoun;
! Constant Make__PN;
! #Endif;
! #Ifdef Make__PN;
[ ParseNoun obj; obj = obj; return -1; ];
#Endif;

#Default Story 0;
#Default Headline 0;

#Ifdef INFIX;
#Include "infix";
#Endif;

! ==============================================================================

Constant LIBRARY_RUSSIAG;

! ==============================================================================
