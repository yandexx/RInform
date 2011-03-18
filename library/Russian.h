! ===========================================================================
!
!   RUSSIAN: Language Definition File for Inform 6
!   Source encoding: CP1251
!
!   Copyright (C) Grankin Andrey 2002, Gayev Denis 2003-2004
!
!   Based on:
!	English Release 6/11 Serial number 040227
!
! ---------------------------------------------------------------------------

System_file;

! ---------------------------------------------------------------------------
!   ����� I.   ��������
! ---------------------------------------------------------------------------

Constant LanguageVersion = "@<<������@>>: ������� ������ 0.75-mod, ���� 2010";

! �������
Array Alphabet ->
    ! (��������)
    '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�'
    '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�'
    '�' '�' '�'
    ! (���������)
    '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�'
    '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�' '�'
    '�' '�' '�';

Constant MinChr = 155;			! min char to redefine
Constant MaxChr = 251;			! max char to redefine
Constant AlphaCnt = 33;			! # of characters

! All remappables are in range MinChr to MaxChr
Array AlphaXlt -> (MaxChr+1-MinChr);

! Initialise translation table
[ XltInit
  ch rc;

  for (ch = MinChr: ch <= MaxChr: ++ ch) AlphaXlt->(ch-MinChr) = 255;

  for (rc = 0: rc < 2*AlphaCnt: ++ rc) {
	ch = Alphabet->rc;
	if (MinChr <= ch && ch <= MaxChr) AlphaXlt->(ch-MinChr) = rc;
	}
  ];

! Lowercase to Uppercase
[ LtoU ch rc;
  if (MinChr <= ch && ch <= MaxChr) {
  	rc = AlphaXlt->(ch-MinChr);
        if (0 <= rc && rc < AlphaCnt) return Alphabet->(rc+AlphaCnt);
	}

  return ch;
  ];

! Uppercase to Lowercase
[ UtoL ch rc;
  if (MinChr <= ch && ch <= MaxChr) {
  	rc = AlphaXlt->(ch-MinChr);
        if (AlphaCnt <= rc && rc < 2*AlphaCnt) return Alphabet->(rc-AlphaCnt);
	}

  return ch;
  ];

!
! Unluckily, there is no conditional operator in Inform.
! So, we'll use this instead:
!
[ IIF c x y;				! (�)? (x) : (y)

if (c) return x;
return y;
];

!
! ������
!
Class   CompassDirection
  with  number 0,
        description [;
            if (location provides compass_look && location.compass_look(self)) rtrue;
            if (self.compass_look()) rtrue;
            L__M(##Look, 7, self);
        ],
        compass_look false,
  has   scenery male;			! male by default

Object Compass "������/" has concealed male;

IFNDEF WITHOUT_DIRECTIONS;
CompassDirection -> n_obj "�����/"
                    with name 'n//' '�//' '�����',
		    door_dir n_to;
CompassDirection -> s_obj "��/"
                    with name 's//' '�//' '��',
		    door_dir s_to;
CompassDirection -> e_obj "������/"
                    with name 'e//' '�//' '������',
		    door_dir e_to;
CompassDirection -> w_obj "�����/"
                    with name 'w//' '�//' '�����',
		    door_dir w_to;
CompassDirection -> ne_obj "������-������/"
                    with name 'ne' '��' '������������' '������-������',
		    door_dir ne_to;
CompassDirection -> nw_obj "������-�����/"
                    with name 'nw' '��' '�����������' '������-�����',
		    door_dir nw_to;
CompassDirection -> se_obj "���-������/"
                    with name 'se' '��' '���������' '���-������',
		    door_dir se_to;
CompassDirection -> sw_obj "���-�����/"
                    with name 'sw' '��' '��������' '���-�����',
		    door_dir sw_to;
CompassDirection -> u_obj "����/"
                    with name 'u//' '��' '����' '�����' '������' '�������',
		    door_dir u_to;
CompassDirection -> d_obj "���/"
                    with name 'd//' '��' '���' '����' '���' '�����',
		    door_dir d_to;
ENDIF;

CompassDirection -> out_obj "�����/"
                    with name '�����' '������',
		    door_dir out_to;
CompassDirection -> in_obj "����/"
                    with name '����' '������',
		    door_dir in_to;

! �������-����������� �������������
[ LanguageInitialise;

  give thedark female ~male ~neuter;		! (�.�. "�������")

  XltInit ();					! (���������� ���������� �������)
];

! ---------------------------------------------------------------------------
!   ����� II.   �������
! ---------------------------------------------------------------------------

Constant AGAIN1__WD   = 'g//';
Constant AGAIN2__WD   = '�����';
Constant AGAIN3__WD   = '�����';

Constant OOPS1__WD    = 'o//';
Constant OOPS2__WD    = '��';
Constant OOPS3__WD    = '��';

Constant UNDO1__WD    = 'u//';
Constant UNDO2__WD    = '������';
Constant UNDO3__WD    = '�����';

Constant ALL1__WD     = '���';
Constant ALL2__WD     = '���';
Constant ALL3__WD     = '����';
Constant ALL4__WD     = '����';
Constant ALL5__WD     = '���';

Constant AND1__WD     = '�//';
Constant AND2__WD     = '�//';
Constant AND3__WD     = '����';

Constant BUT1__WD     = '�����';
Constant BUT2__WD     = '���';
Constant BUT3__WD     = '�����';

Constant ME1__WD      = '�//';
Constant ME2__WD      = '����';
Constant ME3__WD      = '���';
Constant ME4__WD      = '����';
Constant ME5__WD      = '����';
Constant ME6__WD      = '����';
Constant ME7__WD      = '�����';

Constant OF1__WD      = './/';
Constant OF2__WD      = './/';
Constant OF3__WD      = './/';
Constant OF4__WD      = './/';

Constant OTHER1__WD   = '������';	! NB: ��������� ��������������!
Constant OTHER2__WD   = '����';
Constant OTHER3__WD   = '������';

Constant THEN1__WD    = '�����';
Constant THEN2__WD    = '�����';
Constant THEN3__WD    = '�����';

Constant YES1__WD     = 'y//';
Constant YES2__WD     = '�//';
Constant YES3__WD     = '��';

Constant NO1__WD      = 'n//';
Constant NO2__WD      = '�//';
Constant NO3__WD      = '���';

Constant AMUSING__WD  = '�������';
Constant FULLSCORE1__WD = '����';
Constant FULLSCORE2__WD = '��������';

Constant QUIT1__WD    = 'q//';
Constant QUIT2__WD    = '�����';

Constant RESTART__WD  = '������';
Constant RESTART2__WD  = '����������';
Constant RESTORE__WD  = '����';

! ����������� � �����������
! NB: ������ ������???

Array LanguagePronouns table

   !  word       possible GNAs                   connected
   !             to follow:                      to:
   !                   i
   !             s  p  s  p
   !             mfnmfnmfnmfn                 

      '���'    $$101000101000                   NULL
      '��'     $$010000010000                   NULL
      '��'     $$000111000111                   NULL

      '����'   $$101000101000                   NULL
      '���'    $$010000010000                   NULL
      '���'    $$000111000111                   NULL
 ;

Array LanguageDescriptors table

   !  word       possible GNAs   descriptor      connected
   !             to follow:      type:           to:
   !                   i
   !             s  p  s  p
   !             mfnmfnmfnmfn                 

      '���'    $$100000100000    POSSESS_PK      0
      '���'    $$010000010000    POSSESS_PK      0
      '���'    $$001000001000    POSSESS_PK      0
      '���'    $$000111000111    POSSESS_PK      0

      '�����'  $$100000000000    POSSESS_PK      0
      '����'   $$000111000000    POSSESS_PK      0

      '����'   $$100000100000    POSSESS_PK      0
      '���'    $$010000010000    POSSESS_PK      0
      '���'    $$001000001000    POSSESS_PK      0
      '���'    $$000111000111    POSSESS_PK      0

      '�����'  $$100000000000    POSSESS_PK      0
      '����'   $$000111000000    POSSESS_PK      0

      '���'    $$100000100000    POSSESS_PK      1
      '��'     $$010000010000    POSSESS_PK      1
      '��'     $$001000001000    POSSESS_PK      1
      '��'     $$000111000111    POSSESS_PK      1

      '����'   $$100000000000    POSSESS_PK      1
      '���'    $$000111000000    POSSESS_PK      1

      '���'    $$101000101000    POSSESS_PK      '���'
      '��'     $$010000010000    POSSESS_PK      '��'
      '��'     $$000111000111    POSSESS_PK      '��'
;

! ������������
! NB: ������ ����� (�����, ��������, �������)????
Array LanguageNumbers table
	'����'		1
	'����'		1
	'����'		1
	'���'		2
	'���'		2
	'���'		3
	'������'	4
	'����'		5
	'�����'		6
	'����'		7
	'������'	8
	'������'	9
	'������'	10
	'�����������'	11
	'����������'	12
	'����������'	13
	'������������'	14
	'����������'	15
	'�����������'	16
	'����������'	17
	'������������'	18
	'������������'	19
	'��������'	20
 ;

! ---------------------------------------------------------------------------
!   ����� III.   �������
! ---------------------------------------------------------------------------

[ LanguageToInformese
  i len;

len=2+buffer->1;			! TMP: use WORDSIZE instead????

for (i=2: i~=len: i++) {
	! (��� ��������� -> � ��������)
	buffer->i = UtoL(buffer->i);

	! (��� '�' -> � '�')
	if (buffer->i == '�') buffer->i = '�';
        }

];

! ---------------------------------------------------------------------------
!   ����� IV.   �����
! ---------------------------------------------------------------------------

Include "RusMCE";

! "�����"/"�����"
[ MorM obj;

  !return IIF (obj has pluralname, "�����", "�����");
  if (obj has pluralname) {
	print "�����";
  } else {
	print "�����";
  }
  ];

Constant LanguageAnimateGender   = male;
Constant LanguageInanimateGender = neuter;

! �������.
! ��� ������, ��� � ������� �� ���! :)

Constant LanguageContractionForms = 1;

[ LanguageContraction;
  return 0;
];

Array LanguageArticles -->

!  Cdef	Def	Indef
   ""	""	""
   ""	""	"";

                          !      a           i
                          !      s     p     s     p
                          !      m f n m f n m f n m f n

Array LanguageGNAsToArticles --> 0 0 0 0 0 0 0 0 0 0 0 0;

! ������� ������ �������� ��� ���������� �����������
! (��� �������!)
[ LanguageDirection d;
   switch (d)
   {   n_to:	print "�� �����";
       s_to:	print "�� ��";
       e_to:	print "�� ������";
       w_to:	print "�� �����";
       ne_to:	print "�� ������-������";
       nw_to:	print "�� ������-�����";
       se_to:	print "�� ���-������";
       sw_to:	print "�� ���-�����";
       u_to:	print "�����";
       d_to:	print "����";
       in_to:	print "������";
       out_to:	print "������";

       default: return RunTimeError(9,d);
   }
];

! ������� ������ �������� ������������� �����
[ LanguageNumber n;
  ! (����)
  if (n==0)    { print "����"; rfalse; }

  ! (�������������)
  if (n<0)     { print "����� "; n=-n; }

  if (n>=1000) { print (LanguageNumber) n/1000, " �����";
		 NEnd (n/1000, '�//', '�//', 0);
  		 n=n%1000; if (n ~= 0) print " "; }

  if (n==0) rfalse;

  switch(n)
  {   1:  print "����";				! NB: ����, ����...
      2:  print "���";				! NB: ���...
      3:  print "���";
      4:  print "������";
      5:  print "����";
      6:  print "�����";
      7:  print "����";
      8:  print "������";
      9:  print "������";
      10: print "������";
      11: print "�����������";
      12: print "����������";
      13: print "����������";
      14: print "������������";
      15: print "����������";
      16: print "�����������";
      17: print "����������";
      18: print "������������";
      19: print "������������";

      20 to 99:
          switch(n/10)
          {  2: print "��������";
             3: print "��������";
             4: print "�����";
             5: print "���������";
             6: print "����������";
             7: print "���������";
             8: print "�����������";
             9: print "���������";
          }
          if (n%10 ~= 0) print " ", (LanguageNumber) n%10;

      100 to 999:
          switch(n/100)
          {  1: print "���";
             2: print "������";
             3: print "������";
             4: print "���������";
             5: print "�������";
             6: print "��������";
             7: print "�������";
             8: print "���������";
             9: print "���������";
          }
          if (n%100 ~= 0) print " ", (LanguageNumber) n%100;
  }
];

! ��������� ������������ (������������� � 'val')
[ NEnd val eI eII eV;

  switch (val % 100) {
	11 to 19:	if (eV) print (address) eV; return;
  	}

  switch (val % 10) {
	1:		if (eI) print (address) eI;
	2 to 4:		if (eII) print (address) eII;
	default:	if (eV) print (address) eV;
	}

];

! ����� ���
[ LanguageTimeOfDay hours mins i;
   i=hours;
   if (i<10) print " ";
   print i, ":", mins/10, mins%10;
];

#ifdef DEBUG;

[ LanguageVerbIsDebugging w;
    return w == '����!';
];

#Endif;

[ LanguageVerbLikesAdverb w;
    w = w;
    rfalse;				! NB ???
];

[ LanguageVerbMayBeName w;
    w = w;
    rfalse;				! NB ??????
];

Constant NKEY__TX     = "N = ����";
Constant PKEY__TX     = "P = �����";
Constant QKEY1__TX    = "   Q = �������";
Constant QKEY2__TX    = "Q = �������";
Constant RKEY__TX     = "ENTER = �����";

Constant NKEY1__KY    = 'n';
Constant NKEY2__KY    = '�';
Constant PKEY1__KY    = 'p';
Constant PKEY2__KY    = '�';
Constant QKEY1__KY    = 'q';
Constant QKEY2__KY    = '�';

Constant SCORE__TX    = "����: ";
Constant MOVES__TX    = "����: ";
Constant TIME__TX     = "�����: ";
Constant CANTGO__TX   = "�� �� ������ ����� ����.";
Constant YOURSELF__TX = "��";
Constant YOU__TX      = "��";
Constant FORMER__TX   = "�� (�������)";
Constant DARKNESS__TX = "� �������";

Constant THOSET__TX   = "��� �������";
Constant THAT__TX     = "���� ������";
Constant OR__TX       = " ��� ";
Constant NOTHING__TX  = "������";
Constant IS__TX       = " ���������";
Constant ARE__TX      = " ���������";
Constant IS2__TX      = "��������� ";
Constant ARE2__TX     = "��������� ";
Constant AND__TX      = " � ";
Constant WHOM__TX     = "��� ";
Constant WHICH__TX    = "��� ";
Constant COMMA__TX      = ", ";

! C��������� ������������� ��� �������������� ���������
[ ocLabel ocID;
switch (ocID) {
	ocSM:	print "��.�./�.�.";
	ocSF:	print "��.�./�.�.";
	ocSN:	print "��.�./�.�.";
	ocPL:	print "��.�.";
	};
];

! C��������� ������������� ��� ������
[ csLabel csID;
switch (csID) {
	csNom:	print "�.�.";		! (������������ �����)
	csGen:	print "�.�.";		! (����������� �����)
	csDat:	print "�.�.";		! (��������� �����)
	csAcc:	print "�.�.";		! (����������� �����)
	csIns:	print "�.�.";		! (������������ �����)
	csPre:	print "�.�.";		! (���������� �����)
	};
];

! - ������������ �����
[ cNom obj;	CCase (obj, csNom, false); ];

! - ����������� �����
[ cGen obj;	CCase (obj, csGen, false); ];

! - ��������� �����
[ cDat obj;	CCase (obj, csDat, false); ];

! - ����������� �����
[ cAcc obj;	CCase (obj, csAcc, false); ];

! - ������������ �����
[ cIns obj;	CCase (obj, csIns, false); ];

! - ���������� �����
[ cPre obj;	CCase (obj, csPre, false); ];

! (�� ��, �� � ��������� �����)
[ CCNom obj;	CCase (obj, csNom, true); ];
[ CCGen obj;	CCase (obj, csGen, true); ];
[ CCDat obj;	CCase (obj, csDat, true); ];
[ CCAcc obj;	CCase (obj, csAcc, true); ];
[ CCIns obj;	CCase (obj, csIns, true); ];
[ CCPre obj;	CCase (obj, csPre, true); ];

! DeclineSub: ������������� �������� 'noun' �� ���� �������
[ DeclineSub
	csID;

print "������ @<<";
CCase (noun, csOff, false);			! (��� ������)
print "@>> (";
style bold; ocLabel (objID (noun)); style roman;
print "):^^";

for (csID = csNom: csID <= csPre: ++ csID) {
	style bold; csLabel (csID); style roman;
	print ": ";
	CCase (noun, csID, true);
	print "^";
	}
];

! ������� ������� ����
[ PScore val;
  print val, " ���";
  NEnd (val, '�//', '�//', '��');
];

! ������� ������� ���������� �����
[ PTurns val;
  print val, " ���";
  NEnd (val, 0, '�//', '��');
];

[ LanguageLM n x1;

  Prompt:  print "^>";

  Miscellany:
           switch (n)
           {   1: "(������������� ������� 16 ���������)^";
               2: "�� ������ ������ �� ����!";
               3: print " �� ��������� ";
               4: print " �� �������� ";
               5: print "^�� ������ ��������� � ������ ����, ��������� ���������� ����";
                  #IFDEF DEATH_MENTION_UNDO;
                  print ", ������� ����� ���������� ����, ";
                  #ENDIF;
                  if (TASKS_PROVIDED==0)
                      print ", �������� ������ �ר� �� ����";
                  if (deadflag==2 && AMUSING_PROVIDED==0)
                      print ", �������� ��������� ���������� ���������";
                  " ��� ��������� (�����) ����?";
               6: "[������������� �� ������������ ������ ����.]";
               7: "[�������� ��� �� �������.]";
               8: "����� ���� �� ������������� �������.";
               9: "^������ ����� ������������ ����!";
              10: "��������?";
              11: "[������ �������� ��, ��� �� �������!]";
              12: "[������ �������� ��� ���� ������!]";
              13: "[���������� ��� ������.]";
              14: "��� ���������� ���������.";
              15: "��������� ��� ������.";
              16: "������� @<<��@>> ���������� ������ ���� �����.";
              17: "��������� ���� -- �� ����� �� ���!";
              18: print "��";
              19: "�� ��������� ��� ������.";
              20: "����� ��������� ������� @<<����, ����@>>,
                   ������� @<<�����@>> (�� �� @<<����, �����@>>).";
              21: "��� ���� �� ����� ���������.";
              22: "������� �� ����� ���������� � �������.";
              23: "�� �������, � ���� �� �����������.";
              24: "������������ �������� � ", (cIns) x1, ".";
              25: "����� ���������� � �����������,
                   ������� @<<����������, ������@>>.";
              26: print "(������� ���� ";
				if(not_holding == player) "����)";
				print (cAcc) not_holding; ")";
              27: "��� ������� ���������.";
              28: print "�� ������� ������� ������: ";
              29: "��� ����� ���������.";
              30: "����� �������� ����� ���.";
              31: "�� ������ ������� ����!";
              32: "����� �������� � ���� ���.";
              33: "� ���� ��������� �� ����������� ����� ��������.";
              34: "������������� ������� ��������� ������ ���� ���.";
              35: "���������, � ���� ��������� @<<", (address) pronoun_word, "@>>.";
              36: "�� ��������� ����� �� ����������!";
              37: "�������� ��������� ������ � ����������� ��������.";
              38: "���� ������ ���������.";
              39: "��������� ��� � ���� ��� �������������.";
              40: "� ������ ������ ����������� @<<",
                  (address) pronoun_word, "@>> (", (cNom) pronoun_obj, ").";
              41: "����� ������� ���������.";
              42: if (x1==0) print "�� ������ �� ��� ���";
                  else print "������ ", (number) x1, " �� ��� ����";
                  " � �������.";
              43: "�������� ���!";
              44: "�� ����� ������ ���!";
              45: print "��� ������� � ����: ";
              46: print "��� ������� � ����: ";
              47: "�� ����� �������� ������ ���� �������. ����� ������?";
              48: print "� ���� �� ������ ��������� ������� ";
                  if (actor~=player) print " ",  actor;
                  PrintCommand(); print "?^";
              49: print "� ���� �� ������ ��������� ������� ";
                  if (actor~=player) print " ",  actor;
                  PrintCommand(); print "?^";
              50: print "��� ���� ";
                  if (x1 > 0) print "����������";
                  else { x1 = -x1; print "����������"; }
                  print " �� ", (PScore) x1;
              51: "(��������� ���-��, ��� ��������� ��� ������ ������.)";
              52: "^������� ����� �� 1 �� ", x1,
                  ", 0 ��� ���������� ��� ������� ENTER.";
              53: "^[������� ������.]";
              54: "[����������� �������.]";
              55: "[����������� �� �������.]";
              56: print ".^";
              57: print "?^";
           }

  ListMiscellany:
           switch(n)
           {   1: print " (����", (V2bEnd) x1, ")";
               2: print " (������", (SAEnd) x1, ")";
               3: print " (����", (V2bEnd) x1, " � ������", (SAEnd) x1, ")";
               4: print " (����", (SAEnd) x1, ")";
               5: print " (����", (V2bEnd) x1, " � ����", (SAEnd) x1, ")";
               6: print " (������", (SAEnd) x1, " � ����", (SAEnd) x1, ")";
               7: print " (����", (V2bEnd) x1, ", ������", (SAEnd) x1, " � ����", (SAEnd) x1, ")";
               8: print " (����", (V2bEnd) x1, " � �����", (SAEnd) x1;
               9: print " (����", (V2bEnd) x1;
              10: print " (�����", (SAEnd) x1;
              11: print " (";
              12: print "������", (SAEnd) x1;
              13: print "������", (SAEnd) x1, " � ����", (SAEnd) x1;
              14: print "������", (SAEnd) x1;
              15: print "������", (SAEnd) x1, " � ������", (SAEnd) x1;
              16: print " � ����", (SAEnd) x1;
              17: print " (����", (SAEnd) x1, ")";
              18: print " ������", (V2aEnd) x1, " ";
              19: print " (�� ";
              20: print ", ��� ";
              21: print " (";
              22: print ", ������ ";
           }

  Pronouns: switch(n)
           {   1: print "� ������ ������: ";
               2: print "�������� ";
               3: print "�����������";
               4: "����������� �� ����������.";
               5:  ".";
           }

  Order:   print_ret (CCNom) x1, " ���� �� ������", (V1bEnd) x1, "�� ���� �������.";

  Quit:    switch (n)
           {   1: print "�������� @<<��@>> ��� @<<���@>>.";
               2: print "�� ������ �������� ����? ";
           }

  Restart: switch(n)
           {   1: print "�� ������ ������������� ����? ";
               2: "������������� ���� �� �������.";
           }

  Restore: switch(n)
           {   1: "������������ ���� �� �������.";
               2: "���� �������������.";
           }

  Save:    switch(n)
           {   1: "��������� ���� �� �������.";
               2: "���� ���������.";
           }

  Verify:  switch(n)
           {   1: "���� ���� �������� �������.";
               2: "���� ���� �� ������ ��������, � ����� ���� ��������.";
           }

  ScriptOn: switch(n)
           {   1: "����� ����������� ��� �������.";
               2: "��������� �����������:";
               3: "�������� ���������� �� �������.";
           }

  ScriptOff: switch(n)
           {   1: "����� ����������� ��� ��������.";
               2: "^���������� �����������.";
               3: "��������� ���������� �� �������.";
           }

  NotifyOn:     "��������� � ����� ��������.";

  NotifyOff:    "��������� � ����� ���������.";

  Places:    switch (n) {
        1:  print "���������� �����: ";
        2:  print ".^";
	}

  Objects: switch(n)
           {   1: "��������� ��������:^";
               2: "�����������.";
               3: print " (�� ����)";
               4: print " (� ����)";
               5: print " (� ����-�� ���)";
               6: print " (� @<<", (cNom) x1, "@>>)";
               7: print " (� ", (cPre) x1, ")";
               8: print " (������ ", (cGen) x1, ")";
               9: print " (�� ", (cPre) x1, ")";
              10: print " (����� ���)";
           }

  Score:   switch (n) {
        1:  print (string) IIF (deadflag, "� ��� �������", "� ����� �������"),
                  " �� ������� ", (PScore) score,
                  " (�� ", MAX_SCORE, " ���������) �� ", (PTurns) turns;
        2:  "� ���� ���� ���� �� ������������.";
    }

  FullScore: switch(n)
           {   1: "������ ���� �����", (string) IIF (deadflag, "��", "��"), " ��:^";
               2: "�� ��������� ��������";
               3: "�� ���������� �����";
               4: "����� (�� ", MAX_SCORE, " ���������)";
           }

  Inv:     switch(n)
           {   1: "� ���� � ����� ������ ���.";
               2: print "� ���� � ����� ����";
               3:  print ":^";
               4:  print ".^";
           }

  Take:    switch(n)
           {   1: print "�� ����� ", (cAcc) noun ; 
                !if (noun has female) print "�";
                !else if (noun has pluralname) print "��";
                !else print "���"; 
				".";
               2: "�� ������ ���� ��� � ����.";
               3: print_ret (CCDat) x1, " ��� ���� �� ����������.";
               4: "������� ���� ���������� �������� ", (cAcc) x1, ".";
               5: print_ret (CCNom) x1, " � ���� ��� ����.";
               6: print_ret (CCNom) noun, " ���� ���������", (V2aEnd) noun, " ",
               		(cDat) x1, ".";
               7: print_ret (CCNom) noun, " ���� ����", (V1bEnd) noun, "�� ������ ",
               		(cGen) x1, ".";
               8: print_ret (CCNom) x1, " ����������", (SAEnd) x1, ".";
               9: print_ret (CCNom) x1, " ������", (SAEnd) x1, ".";
              10: print_ret (CCAcc) x1, " ���������� �����.";
              11: print_ret (CCNom) x1, " ����� ��������", (SAEnd) x1, ".";
              12: "� ���� � ����� ������� ����� �����.";
              13: "(��������� ", (cAcc) x1, " ������ ", (cGen) SACK_OBJECT,
                  ", ����� ���������� �����)";
           }

  Drop:    switch(n)
           {   1: print_ret "� ���� ��� ", (cAcc) x1, ".";
               2: print_ret (CCNom) x1, " �� � ����.";
               3: "(������� ���� ", (cAcc) x1, " � ����)";
               4: print_ret "������", (SAEnd) x1, ".";
           }

  Remove:  switch(n)
           {   1: print_ret (CCNom) x1, " ������", (SAEnd) x1, ".";
               2: print_ret (CCNom) x1, " �� �����", (V2bEnd) x1, "�� ",
               	(string) IIF (second has supporter, "�� ", "� "), (cPre) second, ".";
               3: print_ret (CCNom) x1, (string) IIF (second has supporter, " ������", " ��������"), (SAEnd) x1,
               		(string) IIF (second has supporter, " c ", " �� "), (cGen) second, ".";
           }

  PutOn:   switch(n)
           {   1: "������� ���� ����� ����� ", (cAcc) x1, " � ����.";
               2: "���������� �������� ���-���� �� ����.";
               3: "������ ���-���� �� ", (cAcc) x1, " ������������.";
               4: "� ���� �� ������ ��������.";
               5: "(������� ���� ", (cAcc) x1, " � ����)^";
               6: "������ ��� ����� �� ", (cPre) x1, ".";
               7: "�� ������ �� �� ", (cAcc) second, ".";
               8: "�� ������ ", (cAcc) x1, " �� ", (cAcc) second, ".";
           }

  Insert:  switch(n)
           {   1: "������� ���� ����� ����� ", (cAcc) x1, " � ����.";
               2: print_ret (CCNom) x1, " �� ", (MorM) x1, " ���-���� ���������.";
               3: print_ret (CCNom) x1, " ������", (SAEnd) x1, ".";
               4: "������ �� ������ ����� ", (cAcc) x1, " � ����.";
               5: "���������� ������� ���-���� ������ ����.";
               6: "(������� ���� ", (cAcc) x1, " � ����)^";
               7: "������ ��� ����� � ", (cPre) x1, ".";
               8: "�� ������ �� � ", (cAcc) second, ".";
               9: "�� ������ ", (cAcc) x1, " � ", (cAcc) second, ".";
           }

  EmptyT:  switch(n)
           {   1: print_ret (CCNom) x1, " �� ", (MorM) x1, " ���-���� ���������.";
               2: print_ret (CCNom) x1, " ������", (SAEnd) x1, ".";
               3: print_ret (CCNom) x1, " ��� ����", (SAEnd) x1, ".";
               4: "�� ���� �������� ��� ��� ����?";
           }

  Give:    switch(n)
           {   1: "� ���� ��� ", (cGen) x1, " � �����.";
               2: print_ret (CCNom) x1, " � ��� � ���� ����.";
               3: print_ret (CCGen) x1, " ��� �� ��������������.";
           }

  Show:    switch(n)
           {   1: "� ���� ��� ", (cGen) x1, " � �����.";
               2: print_ret (CCGen) x1, " ��� �� ����������.";
           }

  Enter:   switch(n)
           {   1: "�� �� ��� ", (string) IIF (x1 has supporter, "�� ", "� "),
           	(cPre) x1, ".";
               2: "�� ��/� ", (cAcc) x1,
                  " ���������� �����, ������, ����� ��� ����.";
               3: print_ret (CCNom) x1, " ������", (SAEnd) x1,
               	", � �� �� ������ ����� ����.";
               4: "�� �� ������ ����� � ��, ��� � ���� � �����.";
               5: "�� ", (string) IIF (x1 has supporter, "���� �� ", "����� � "),
               		(cAcc) x1, ".";
               6: "(", (string) IIF (x1 has supporter, "������ � ",
               	       IIF (x1 has container, "������� �� ", "������ �� ")),
               		  (cGen) x1, ")^";
               7: "(", (string) IIF (x1 has supporter, "������� �� ",
               	       IIF (x1 has container, "������ � ", "����� � ")),
               		  (cAcc) x1, ")^";
           }

  GetOff:  "�� �� �� ���������� ", (string) IIF (x1 has supporter, "�� ", "� "), (cPre) x1, ".";

  Exit:    switch(n)
           {   1: "�� �� ������ �� ���������� �/�� ���-����.";
               2: print_ret (CCNom) x1, " ������", (SAEnd) x1,
                  ", � �� �� ������ �����.";
               3: "�� ", (string) IIF (x1 has supporter, "���� � ", " ����� �� "),
               		(cGen) x1, ".";
               4:  "�� �� ������ �� ", (string) IIF (x1 has supporter, "�� ", "� "),
               		(cPre) x1, ".";
           }

  VagueGo:       "���� ����� ������ � ��������� �����������.";

  Go:      switch(n)
           {   1: "������ �� ������ ",
           	   (string) IIF (x1 has supporter, "������ � ", "����� �� "),
           	   (cGen) x1, ".";
               2: "���� ���� ����������.";
               3: "�� �� ������ ��������� �� ", (cDat) x1, ".";
               4: "�� �� ������ ���������� �� ", (cDat) x1, ".";
               5: print_ret (CCNom) x1, " ����", (V1bEnd) x1, " ���� ������.";
               6: print_ret (CCNom) x1, " ������ �� ���", (V1aEnd) x1, ".";
           }

  LMode1:         " ������ � @<<����������@>> ������^
  		   (������� �������� ��� ����� ����, ������� ��� ������).";

  LMode2:         " ������ � @<<�������@>> ������^(������ ������� �������� ����).";

  LMode3:         " ������ � @<<�������@>> ������^(������ ������� �������� ����).";

  Look:    switch(n)
           {   1: print " (�� ", (cPre) x1, ")";
               2: print " (� ", (cPre) x1, ")";
               3: print " (��� ", (cNom) x1, ")";
               4: print "^�� ", (cPre) x1;
                  WriteListFromCase (child(x1),
                      ENGLISH_BIT + RECURSE_BIT + PARTINV_BIT
                      + TERSE_BIT + ISARE_BIT + CONCEAL_BIT, csNom);
                  ".";
               5, 6:
                  if (x1~=location)
                     print (string) IIF (x1 has supporter, "^�� ", "^� "), (cPre) x1, " ";
                  else print "^�����";
                  if (n==5) print " �����";
                  WriteListFromCase (child(x1),
                      ENGLISH_BIT + WORKFLAG_BIT + RECURSE_BIT + ISARE_BIT
                      + PARTINV_BIT + TERSE_BIT + CONCEAL_BIT, csNom);
                  ".";
               7: "� ���� ����������� �� ����� ������ ���������������.";
           }

  Examine: switch(n)
           {   1: "������� (���., �.�.): ������ ���������� �����.";
               2: "������ ���������� � ", (cPre) x1, " �� �� ������.";
               3: print_ret (CCNom) x1, " ������ ",
               	(string) IIF (x1 has on, "�", "��"), "������", (SAEnd) x1, ".";
           }

  LookUnder: switch(n)
           {   1: "����� ������� ����� ��� �������.";
               2: "�� �� �������� ��� ", (cIns) noun, " ������ �����������.";
           }

  Search:  switch(n)
           {   1: "����� ������� ����� ��� �������.";
               2: "�� ", (cPre) x1, " ������ ���.";
               3: print "�� ", (cPre) x1;
                  WriteListFromCase (child(x1),
                      TERSE_BIT + ENGLISH_BIT + ISARE_BIT + CONCEAL_BIT, csNom);
                  ".";
               4: "�� �� �������� � ", (cPre) noun, " ������ �����������.";
               5: print_ret (CCNom) x1, " ������", (SAEnd) x1,
               	  ", � �� �� ������ ��������� ������.";
               6: "� ", (cPre) x1, " ������ ���.";
               7: print "� ", (cPre) x1;
                  WriteListFromCase (child(x1),
                      TERSE_BIT + ENGLISH_BIT + ISARE_BIT + CONCEAL_BIT, csNom);
                  ".";
           }

  Lock:    switch(n)
           {   1: print_ret (CCAcc) x1, " ���������� ��������.";
               2: print_ret (CCNom) x1, " ��� ������", (SAEnd) x1, ".";
               3: "������� ���������� ������� ", (cAcc) x1, ".";
               4: print_ret (CCNom) x1, " �� ������", (V2bEnd) x1, " � �����.";
               5: "�� ��������� ", (cAcc) x1, ".";
           }

  Unlock:  switch(n)
           {   1: print_ret (CCAcc) x1, " ���������� ��������.";
               2: print_ret (CCNom) x1, " �� ������", (SAEnd) x1, ".";
               3: print_ret (CCNom) x1, " �� ������", (V2bEnd) x1, " � �����.";
               4: "�� ��������� ", (cAcc) x1, ".";
           }

  SwitchOn: switch(n)
           {   1: print_ret (CCAcc) x1, " ���������� ��������.";
               2: print_ret (CCNom) x1, " ��� �������", (SAEnd) x1, ".";
               3: "�� ��������� ", (cAcc) x1, ".";
           }

  SwitchOff: switch(n)
           {   1: print_ret (CCAcc) x1, " ���������� ���������.";
               2: print_ret (CCNom) x1, " ��� ��������", (SAEnd) x1, ".";
               3: "�� ���������� ", (cAcc) x1, ".";
           }

  Open:    switch(n)
           {   1: print_ret (CCAcc) x1, " ���������� �������.";
               2: "������, ��� ", (cNom) x1, " ������", (SAEnd) x1, ".";
               3: print_ret (CCNom) x1, " ��� ������", (SAEnd) x1, ".";
               4: print "�� ���������� ", (cAcc) x1, ". ������";
                  if (WriteListFromCase (child(x1),
                      ISARE_BIT+ ENGLISH_BIT + TERSE_BIT + CONCEAL_BIT, csNom) == 0)
                      	"... �������.";
                  ".";
               5: "�� ���������� ", (cAcc) x1, ".";
           }

  Close:   switch(n)
           {   1: print_ret (CCAcc) x1, " ���������� �������.";
               2: print_ret (CCNom) x1, " ��� ������", (SAEnd) x1, ".";
               3: "�� ���������� ", (cAcc) x1, ".";
           }

  Wear:    switch(n)
           {   1: "������ ", (cAcc) x1, " �� ���� ����������.";
               2: "� ���� ��� ", (cGen) x1, " � �����.";
               3: print_ret (CCNom) x1, " ��� �� ����.";
               4: "�� ��������� ", (cAcc) x1, " �� ����.";
           }

  Disrobe: switch(n)
           {   1: print_ret (CCNom) x1, " �� �� ����.";
               2: "�� �������� ", (cAcc) x1, " � ����.";
           }

  Eat:     switch(n)
           {   1: print_ret (CCNom) x1, " ���� �� ���", (V2bEnd) x1, "�� � ����.";
               2: "�� �������� ", (cAcc) x1, ". ������ ��������.";
           }

  Yes, No:        "������ ��� ������������.";

  Burn:           print "��������� ", (cAcc) x1;
		  if (second ~= 0) print " ", (cIns) second;
		  " ������������.";

  Pray:           "�� �� ���� ���, �� �� �� �� ������� ���� �������.";

  Wake:           "������, ��� �� ���, � ���.";

  WakeOther:      "������ ", (cAcc) x1, " �� �����.";

  Kiss:           "����� ����� ��������������� �� ����.";

  Think:          "�������� ����.";

  Smell:          "�������� ���������� ������ ���.";

  Listen:         "������� ��������� ������ ���.";

  Taste:          "�������� ���������� ����� ���.";

  Touch:   switch(n)
           {   1: "�� ����� ������ ���� �����.";
               2: "������� ��������� �������� ���.";
               3: "���� ���� ����� �������.";
           }

  Dig:            print "������ ", (cAcc) x1;
		  if (second ~= 0) print " ", (cIns) second;
		  " ������������.";

  Cut:            "������ ", (cAcc) x1, " ������������.";

  Jump:           "�� ����� ������������� �� �����.";

  JumpOver:	  "������� ����� ", (cAcc) x1, " ������������.";

  Tie:  	  print "����������� ", (cAcc) x1;
		  if (second ~= 0) print " � ", (cDat) second;
		  " ������������.";

  Drink:          "������ ", (cAcc) x1, " ����������.";

  Fill:           "��������� ", (cAcc) x1, " ������������.";

  Sorry:          "�, �� ����� ���������.";

  Strong:        "��������� �������� ��� �� ����������."; 
  Mild:           "�����.";

    Attack:         "���� ���� -- ��� �� ����?";

  Swim:           "��� ����� ����� ������������ ����.";

  Swing:          "������ ", (cAcc) x1, " ������������.";

  Blow:           "���� � ", (cAcc) x1, " ������������.";

  Rub:            "������ ", (cAcc) x1, " ������������.";

  Set:            "���������� ���������� ", (cAcc) x1, ".";

  SetTo:          "���������� ���������� ", (cAcc) x1, " �� ���-����.";

  WaveHands:      "�� ����� ������ ������.";

  Wave:    switch(n)
           {   1: "������ ���� ����� ", (cAcc) x1, ".";
               2: "�� ����� ������ ", (cIns) x1, ".";
           }

  Pull, Push, Turn:
           switch(n)
           {   1: print_ret (CCAcc) x1, " ������ �������� � �����.";
               2: print_ret (CCAcc) x1, " ������� ����������.";
               3: "������ �� ���������.";
               4: print_ret (CCDat) x1, " ��� ���� �� ����������.";
           }

  PushDir: switch(n)
           {   1: "����������� ��� ��� ������.";
               2: "������� ����� ������ � ����������� �����������.";
               3: "������� � ���� ����������� ����������.";
           }

  Squeeze: switch(n)
           {   1: "�� ����� ������ ���� �����.";
               2: "������� ", (cAcc) x1, " ������������.";
           }

  ThrowAt: switch(n)
           {   1: "������� ", (cAcc) noun, " � ", (cAcc) second, " ����������.";
               2: "� ���� �� ������� ��������� ������� ", (cAcc) noun, " � ", (cAcc) second,
               ".";
           }

  Tell:    switch(n)
           {   1: "������ � ����� ����� -- ������� ����������.";
               2: "���� ���������� ����� �� ������������.";
           }

  Answer, Ask:    "������ �� �����������.";

  Buy:            print_ret (CCNom) x1, " �� �����", (V1bEnd) x1, "��.";

  Sing:           "� ����� ������ � ������� ����� ����� �� ������.";

  Climb:          "���������� �� ", (cAcc) x1, " ������������.";
  
  Wait:           "�������� ������� �������.";

  Sleep:          "������ ���� �� ������ �� ���.";

  Consult:        "�� �� �������� � ", (cPre) x1, " ������ �����������.";

  CommandsOff: switch (n) {
        1: "[������ ������ ���������.]";
        #Ifdef TARGET_GLULX;
        2: "[������ ������ ��� ���������.]";
        #Endif; ! TARGET_
    }
  CommandsOn: switch (n) {
        1: "[������ ������ ��������.]";
        #Ifdef TARGET_GLULX;
        2: "[��������������� ������.]";
        3: "[������ ������ ��� ��������.]";
        4: "[������ ������ ����������!]";
        #Endif; ! TARGET_
    }
  CommandsRead: switch (n) {
        1: "[��������������� ������.]";
        #Ifdef TARGET_GLULX;
        2: "[��������������� ��� ��������.]";
        3: "[��������������� ����������. �������� ������.]";
        4: "[��������������� ����������.]";
        5: "[��������������� ���������.]";
        #Endif; ! TARGET_
    }

];

! ==============================================================================

Constant LIBRARY_RUSSIAN;

! ==============================================================================

