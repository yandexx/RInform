! ===========================================================================
!
!   RusMCE.h:
!   ��������� ������ ��� ������� ����������
!   (��������� �������, �������� ��������, ��.)
!   Source encoding: CP1251
!
!   (c) Gayev D.G. 2003
!
! ---------------------------------------------------------------------------

System_file;

Constant Tlimit = 31;			! (�� ������)
Array  Tbuffer	-> 3+TLimit;
Array  Tparse	-> 6;

! DL: ������ ���������������� ������ ��� DictionaryLookup
! (�� "ParserM.h")

[ DL buf len
  i;
  if (len == 0 || len > Tlimit) return 0;

  Tbuffer->1 = len;
  for (i = 0: i ~= len: i ++) Tbuffer->(2+i) = buf->i;
  Tbuffer->(2+len) = 0;
  Tparse->0 = 1;
  @tokenise Tbuffer Tparse;
  return Tparse-->1;
];

! DLx:
! ��� DL, �� ��� ������ ��������� ������� �� 'term'

[ DLx buf len term
  i;
  if (len == 0 || len >= Tlimit) return 0;

  Tbuffer->1 = len+1;
  for (i = 0: i ~= len: i ++) Tbuffer->(2+i) = buf->i;
  Tbuffer->(2+len) = term;
  Tbuffer->(3+len) = 0;
  Tparse->0 = 1;
  @tokenise Tbuffer Tparse;
  return Tparse-->1;
];

Attribute fem_grammar;			! (��� ��������� �������� ����)

Property casegen;			! (�������������� ����������� ��������� ������� �������)

! # ������� (����� �������)
Constant LanguageCases = 6;

! �������������� �������
Constant csOff =	0;	! ��� (��������� ��������� �������)

Constant csNom =	1;	! ������������ �����	(= ���������)
Constant csGen =	2;	! ����������� �����	(= �������)
Constant csDat =	3;	! ��������� �����	(= �����)
Constant csAcc =	4;	! ����������� �����	(= ���������)
Constant csIns =	5;	! ������������ �����	(= ������������)
Constant csPre =	6;	! ���������� �����	(= ����������)

! ����� �� ��������� ��� ������ ShortName
Global csDflt = csNom;

! ��������� �������
Constant ocSM =		1;	! ������������ ����� / ������� ���
Constant ocSF =		2;	! ������������ ����� / ������� ���
Constant ocSN =		3;	! ������������ ����� / ������� ���
Constant ocPL =		4;	! ������������� �����

! ��������� �������
! ���������� ���������
[ objID obj;

if (obj has pluralname)		return ocPL;
else if (obj has neuter)	return ocSN;
else if (obj has female)	return ocSF;
else if (obj has fem_grammar)	return ocSF;
else				return ocSM;
];

! (����� ������� ���������� �������)
Constant DEBUG_CASES = false;

! �������� ������� �������� ���������

Constant ADJ_TOP = 64;

! SM_Req: ������ � ������� ������� (#nreq)
! (��. �����, ������� ���)
[ SM_Req csID nreq;

  switch (nreq) {

  ! II ���������, �� ���������:
  ! (���, ����, �����, ����, ���, �����):
  ! -, -�, -�, -, -��, -�
  0:	switch (csID) {
	csNom:	return 0;
	csGen:	return '�//';
	csDat:	return '�//';
	csAcc:	return 0;
	csIns:	return '��';
	csPre:	return '�//';
	}

  ! II ���������, �� -�:
  ! (�������, ������, ������, �������, ������, �����, �������):
  ! -�, -�, -�, -�, -��, -�
  1:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '�//';
	csDat:	return '�//';
	csAcc:	return '�//';
	csIns:	return '��';
	csPre:	return '�//';
	}

  ! II ���������, �� -�:
  ! (����, �����, ����, ���):
  ! -�, -�, -�, -�, -��, -�
  2:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '�//';
	csDat:	return '�//';
	csAcc:	return '�//';
	csIns:	return '��';
	csPre:	return '�//';
	}

  ! II ���������, �� -��:
  ! (�����, ����������, ����������, �������, �������):
  ! -��, -��, -��, -��, -���, -��
  3:	switch (csID) {
	csNom:	return '��';
	csGen:	return '��';
	csDat:	return '��';
	csAcc:	return '��';
	csIns:	return '���';
	csPre:	return '��';
	}

  ! ��������������, �� -��:
  ! (�������, �����, �������, ��������):
  ! -��, -���, -���, -��, -��, -��
  64:  	switch (csID) {
	csNom:	return '��';
	csGen:	return '���';
	csDat:	return '���';
	csAcc:	return '��';
	csIns:	return '��';
	csPre:	return '��';
  	}

  ! ��������������, �� -��:
  ! (�������, ����, ������, �����, �����):
  ! -��, -���, -���, -��, -��, -��
  65:  	switch (csID) {
	csNom:	return '��';
	csGen:	return '���';
	csDat:	return '���';
	csAcc:	return '��';
	csIns:	return '��';
	csPre:	return '��';
	}

  ! ��������������, �� -��:
  ! (�����, �������, �������):
  ! -��, -���, -���, -��, -��, -��
  66:  	switch (csID) {
	csNom:	return '��';
	csGen:	return '���';
	csDat:	return '���';
	csAcc:	return '��';
	csIns:	return '��';
	csPre:	return '��';
	}

  }	! switch (nreq)

return -1;
];	! SM_Req

! SF_Req: ������ � ������� ������� (#nreq)
! (��. �����, ������� ���)
[ SF_Req csID nreq;

  switch (nreq) {

  ! I ���������, �� -�:
  ! (����, ������, ����, �������):
  ! -�, -�, -�, -�, -��, -�
  0:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '�//';
	csDat:	return '�//';
	csAcc:	return '�//';
	csIns:	return '��';
	csPre:	return '�//';
	}

  ! I ���������, �� -�:
  ! (�����, �����):
  ! -�, -�, -�, -�, -��, -�
  1:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '�//';
	csDat:	return '�//';
	csAcc:	return '�//';
	csIns:	return '��';
	csPre:	return '�//';
  	}

  ! III ���������, �� -�:
  ! (������, ����, ����, �����):
  ! -�, -�, -�, -�, -��, -�
  2:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '�//';
	csDat:	return '�//';
	csAcc:	return '�//';
	csIns:	return '��';
	csPre:	return '�//';
  	}

  ! I ���������, �� -��:
  ! (������, ������, �������, ������):
  ! -��, -��, -��, -��, -���, -��
  3:	switch (csID) {
	csNom:	return '��';
	csGen:	return '��';
	csDat:	return '��';
	csAcc:	return '��';
	csIns:	return '���';
	csPre:	return '��';
  	}

  ! ��������������, �� -��:
  ! (�������, �������, ��������):
  ! -��, -��, -��, -��, -��, -��
  64:	switch (csID) {
	csNom:	return '��';
	csGen:	return '��';
	csDat:	return '��';
	csAcc:	return '��';
	csIns:	return '��';
	csPre:	return '��';
  	}

  ! ��������������, �� -��:
  ! (�����, �������):
  ! -��, -��, -��, -��, -��, -��
  65:	switch (csID) {
	csNom:	return '��';
	csGen:	return '��';
	csDat:	return '��';
	csAcc:	return '��';
	csIns:	return '��';
	csPre:	return '��';
  	}

  }	! switch (nreq)

return -1;
];	! SF_Req

! SN_Req: ������ � ������� ������� (#nreq)
! (��. �����, ������� ���)
[ SN_Req csID nreq;

  switch (nreq) {

  ! II ���������, �� -�:
  ! (������, �����, ����, �����, �������):
  ! -�, -�, -�, -�, -��, -�
  0:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '�//';
	csDat:	return '�//';
	csAcc:	return '�//';
	csIns:	return '��';
	csPre:	return '�//';
  	}

  ! II ���������, �� -�:
  ! (����, ����):
  ! -�, -�, -�, -�, -��, -�
  1:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '�//';
	csDat:	return '�//';
	csAcc:	return '�//';
	csIns:	return '��';
	csPre:	return '�//';
  	}

  ! II ���������, �� -��:
  ! (��������, �������, �����������, ��������):
  ! -��, -��, -��, -��, -���, -��
  2:	switch (csID) {
	csNom:	return '��';
	csGen:	return '��';
	csDat:	return '��';
	csAcc:	return '��';
	csIns:	return '���';
	csPre:	return '��';
  	}

  ! ���������������, �� -�:
  ! (�����, �����, ���, �����):
  ! -�, -���, -���, -�, -����, -���
  3:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '���';
	csDat:	return '���';
	csAcc:	return '�//';
	csIns:	return '����';
	csPre:	return '���';
  	}

  ! ��������������, �� -��:
  ! (�������, �����, �������):
  ! -��, -���, -���, -��, -��, -��
  64:	switch (csID) {
	csNom:	return '��';
	csGen:	return '���';
	csDat:	return '���';
	csAcc:	return '��';
	csIns:	return '��';
	csPre:	return '��';
  	}

  ! ��������������, �� -��:
  ! (�����, �������):
  ! -��, -���, -���, -��, -��, -��
  65:	switch (csID) {
	csNom:	return '��';
	csGen:	return '���';
	csDat:	return '���';
	csAcc:	return '��';
	csIns:	return '��';
	csPre:	return '��';
  	}

  }	! switch (nreq)

return -1;
];	! SN_Req

! PL_Req: ������ � ������� ������� (#nreq)
! (��. �����)
[ PL_Req csID nreq;

  switch (nreq) {

  ! TMP: �������������� Gen Pl

  ! �������������, �� -�:
  ! (������, ����, ������):
  ! -�, -��/-��/-, -��/-��, -�, -���/-���, -��/-��
  0:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '��';			! TMP: �� ������! - ��, 
	csDat:	return '��';
	csAcc:	return '�//';
	csIns:	return '���';
	csPre:	return '��';
  	}

  ! �������������, �� -�:
  ! (������, �������, ������, ������):
  ! -�, -��/-��/-, -��/-��, -�, -���/-���, -��/-��
  1:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '��';			! TMP: �� ������!
	csDat:	return '��';
	csAcc:	return '�//';
	csIns:	return '���';
	csPre:	return '��';
  	}

  ! �������������, �� -�:
  ! (������, ����, ������):
  ! -�, -��, -��, -�, -���, -��
  2:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '��';
	csDat:	return '��';
	csAcc:	return '�//';
	csIns:	return '���';
	csPre:	return '��';
  	}

  ! �������������, �� -�:
  ! (����, ����, �����):
  ! -�, -��, -��, -�, -���, -��
  3:	switch (csID) {
	csNom:	return '�//';
	csGen:	return '��';
	csDat:	return '��';
	csAcc:	return '�//';
	csIns:	return '���';
	csPre:	return '��';
  	}

  ! �������������, �� -��:
  ! (������, �������, �������, ������, �����):
  ! -��, -���, -���, -��, -����, -���
  4:	switch (csID) {
	csNom:	return '��';
	csGen:	return '���';
	csDat:	return '���';
	csAcc:	return '��';
	csIns:	return '����';
	csPre:	return '���';
  	}

  ! �������������, �� -��:
  ! (�������, �������, ����������, �������):
  ! -��, -��, -���, -��, -����, -���
  5:	switch (csID) {
	csNom:	return '��';
	csGen:	return '��';
	csDat:	return '���';
	csAcc:	return '��';
	csIns:	return '����';
	csPre:	return '���';
  	}

  ! �������������, �� -��:
  ! (�������, �������, ������):
  ! -��, -��, -���, -��, -����, -���
  6:	switch (csID) {
	csNom:	return '��';
	csGen:	return '��';
	csDat:	return '���';
	csAcc:	return '��';
	csIns:	return '����';
	csPre:	return '���';
  	}

  ! ��������������, �� -��:
  ! (�������, �������, �������):
  ! -��, -��, -��, -��, -���, -��
  64:	switch (csID) {
	csNom:	return '��';
	csGen:	return '��';
	csDat:	return '��';
	csAcc:	return '��';
	csIns:	return '���';
	csPre:	return '��';
  	}

  ! ��������������, �� -��:
  ! (�����, ������, �������):
  ! -��, -��, -��, -��, -���, -��
  65:	switch (csID) {
	csNom:	return '��';
	csGen:	return '��';
	csDat:	return '��';
	csAcc:	return '��';
	csIns:	return '���';
	csPre:	return '��';
	}

  }	! switch (nreq)

return -1;
];	! PL_Req

! Ending PostProcess (as after 'prch')
[ EndingPost u prch;
  if (u) {
	! ����������� ����� '�'/'�'/'�'/'�'/'�'/'�'/'�':
	! ����� -> ������, ������ -> ������, ������ -> �������
	if (prch == '�' or '�' or '�' or '�' or '�' or '�' or '�')
		switch (u) {
		'�//':		return '�//';
		'��':		return '��';
		'��':		return '��';
		'��':		return '��';
		'���':		return '���';
		'��':		return '��';
		}

	! TMP: ������ ���������!

	! ����� �: ��, �� -> ��, �� (���� ��������� ����������)
	! ����� �, �: � -> �, � -> �
	}

  return u;
  ];

! Ending PreProcess (as after 'prch')
[ EndingPre u prch;
  if (u) {
	if (prch == '�' or '�' or '�' or '�' or '�' or '�' or '�')
		switch (u) {
		'�//':		return '�//';
		'��':		return '��';
		'��':		return '��';
		'��':		return '��';
		'���':		return '���';
		'��':		return '��';
		}
	}

  return u;
  ];

! CCaseEnd:
! ��������� �������� ��������� (start..end) � ��������������� ����� (csID)
! ocFN - ��������� ���������; disc - �������������; prch - ������ ����� ����������
[ CCaseEnd start end csID ocFN disc prch
	i u v;

v = EndingPre (DL (start, end-start), prch);

! ��������� ����� �� ��������...
for (i = 0: : ++ i) {
   u = indirect (ocFN, csNom, i);

   if (u == -1) { 
   	if (i >= ADJ_TOP)	! (������ ��� ���������)
   		{ print "?"; return; }
   	else			! (��������������)
   		{ i = ADJ_TOP - 1; }
	}

   else if (u == v) {

	if (disc) { -- disc; continue; }

	if (csID ~= csNom) u = EndingPost (indirect (ocFN, csID, i), prch);
	else u = EndingPost (u, prch);

  	if (u) print (address) u;
 	return;
 	}
 }

];

! ����������� ������ ��� 'LanguageRefers'

[ EndingLookup addr len csID
  v u ocFN i;

  if (csID == 0) rtrue;			!! (����� ����� ��������)

  if (len ~= 0) {
    v = DL (addr, len);
    if (v == 0) rfalse;
    }
  else v = 0;

ocFN = SM_Req;

for (::) {

for (i = 0: : ++ i) {
   u = indirect (ocFN, csID, i);

   if (u == -1) { 
   	if (i >= ADJ_TOP) break;	! (������ ��� ���������)
   	else i = ADJ_TOP - 1;		! (��������������)
	}
   else if (u == v) rtrue;
   }

switch (ocFN) {
	SM_Req:	ocFN = SF_Req;
	SF_Req:	ocFN = SN_Req;
	SN_Req: ocFN = PL_Req;
	PL_Req: rfalse;			! (������ ��� ���������)
	}
}

rfalse;
];

!
! ��������� ������������ ����������� ��������
!
[ IsVerbSuffix start len;

  ! ("-��|-��": ������)
  if (len >= 2 && start->(len-2) == '�' && start->(len-1) == '�' or '�')
	len = len-2;

  if (len == 1 && start->0 == '�' or '�') rtrue;

  ! "[��������]([���]|��)"
  if (start->0 == '�' or '�' or '�' or '�' or '�' or '�' or '�' or '�') {
	++ start; -- len;

  if (len == 1 && start->0 == '�') rtrue;
  }

  ! "��|��"
  if (len == 2 && start->0 == '�' && start->1 == '�' or '�') rtrue;

  ! "��|��|����"
  if (start->0 == '�' &&
     ((len == 2 && start->1 == '�' or '�') ||
      (len == 4 && start->1 == '�' && start->2 == '�' && start->3 == '�')))
	rtrue;

  rfalse;
  ];

!
! ��������� ������������ ����������� ��������
!
[ IsVerbPrefix start len
  w;

  w = DL (start, len);
  if (w == 0) return false;

  return w ==
	'�//' or '��' or '��' or '��' or
	'��' or
	'��' or
	'��' or '��' or
	'��' or
	'�//' or '��' or '���' or '��' or '���' or
	'��' or '���' or '����' or '���' or '���' or '���' or '����' or
	'���' or '���' or
	'�//' or '��' or '��' or '�//';
  ];

!
! ��������� ������������ ������� (#wnum)
!
[ LanguageIsVerb buffer parse wnum
  adr beg len end w;

  ! ��� ����� �� �����!
  buffer = 0; parse = 0;		! (����� ������ ��������� �� �������)

  adr = WordAddress(wnum); len = WordLength(wnum);

  w = DLx (adr, len, '!');
  if (w) return w;

  for (end = len: end ~= 0: -- end) {
    if (end == len || IsVerbSuffix (adr+end, len-end))
      for (beg = 0: beg ~= end: ++ beg)
	if (beg == 0 || IsVerbPrefix (adr, beg)) {
	    w = DL (adr+beg, end-beg);
	    if (w ~= 0 && (w->#dict_par1 & 1) ~= 0)
		return w;				! (verb entry found)
	    }
    }

  return 0;
];

! ����������� �������� (LanguageVerb):
! ����������� ������� � VerbDepot

[ LanguageVerb word
  obj;

  objectloop (obj in VerbDepot) {
	if (WordInProperty (word, obj, name))
		{ print (object) obj; rtrue; }
	}

  rfalse;
];

! ����� �� ��������� ��� ������ LanguageRefers
Global csLR = 0;

! ���������� ���������������� ������� �������
[ c_token idtok csID
  retval;

  csLR = csID;

  retval = ParseToken (ELEMENTARY_TT, idtok);

  csLR = 0;

  return retval;
];

! LanguageRefers
! ������ �� �������:
! ����� �� ����� #wnum � ������ ��������� ���������� � ������� obj?

[ LanguageRefers obj wnum
  adr len end w csID;

  adr = WordAddress(wnum); len = WordLength(wnum);

  ! ��� ��������� ����������� -- ���������� ���������
  if (parent (obj) == Compass) {
  	w = DL (adr, len);
	if (w ~= 0 && WordInProperty (w, obj, name)) rtrue;
	rfalse;
	}

  ! ��� ������� ������������ ��������� Acc -> Gen
  csID = csLR;
  if (csID == csAcc &&
      obj has animate && obj has male && obj hasnt fem_grammar)
	csID = csGen;

  for (end = len: end ~= 0: -- end) {
  	w = DL (adr, end);
	if (w ~= 0 && WordInProperty (w, obj, name) && EndingLookup (adr+end, len-end, csID))
		rtrue;
  	}

  rfalse;
];

Constant ScrLen = 200;
Array Scratch --> ScrLen;

! CCase:
! ��������� ��� ������� (obj) � ��������������� ����� (csID)

[ CCase obj csID ucase
  i dlm limit ocFN;

#iftrue DEBUG_CASES;

! (���������� �����)
csLabel (csID);
print " (", (object) obj, ")";

#ifnot;

switch (objID (obj)) {
    ocSM:	ocFN = SM_Req;
    ocSF:	ocFN = SF_Req;
    ocSN:	ocFN = SN_Req;
    ocPL:	ocFN = PL_Req;

    default:	return;
    }

! ��� ������� ������������ ��������� Acc -> Gen
if (csID == csAcc &&
    obj has animate && obj has male && obj hasnt fem_grammar) csID = csGen;

if (csID ~= 0) {

Scratch-->0 = ScrLen-1;

@output_stream 3 Scratch;
print (object) obj;
@output_stream -3;

if (ucase) Scratch->2 = LtoU (Scratch->2);	! (� ������� �������)

dlm = 0;
limit = (Scratch-->0) + 2;
for (i = 2: i ~= limit: ++ i) {
    if (Scratch->i == '/') {
	if (dlm == 0) { dlm = Scratch+i; }
	else {	CCaseF (obj, ocFN, csID, dlm+1, Scratch+i);
		dlm = 0;
		}
	}
    else {	if (dlm ~= 0 && Scratch->i == ' ') {
    	   		CCaseF (obj, ocFN, csID, dlm+1, Scratch+i);
    	   		dlm = 0;
    	   		}

		if (dlm == 0) print (char) (Scratch->i);
    	   	}
    }	! for

if (dlm ~= 0) { CCaseF (obj, ocFN, csID, dlm+1, Scratch+i); }
}

else print (object) obj;

#endif;
];

[ CCaseF obj ocFN csID beg end disc;

disc = 0;

! (discriminator present?)
while (end->(-1) == '!') { -- end; ++ disc; }

if (obj provides casegen && obj.casegen (beg, end, csID));
else CCaseEnd (beg, end, csID, ocFN, disc, beg->(-2));

];

! ����� �������� ����� ������� (����� CCase)
[ LanguagePrintShortName obj
  sn;

   sn = short_name;

   if (obj provides sn && PrintOrRun(obj, sn, 1) ~= 0) rtrue;

   CCase (obj, csDflt, false);

  rtrue;
];

! ����� ������ � ������ csID
[ WriteListFromCase obj flag csID
  rval csSV;

  csSV = csDflt; csDflt = csID;

  rval = WriteListFrom (obj, flag);
  
  csDflt = csSV;
  return rval;
];

! ���������� ����������� ��� 'obj'
[ Pronoun obj;
  print (string) (
  	IIF (obj == player, "��", IIF (obj has pluralname, "���",
  	IIF (obj has female, "���", IIF (obj has neuter, "���", "��")))));
];

[ PronounS obj;
  print (string) (
  	IIF (obj == player, "��", IIF (obj has pluralname, "���",
  	IIF (obj has female, "���", IIF (obj has neuter, "���", "��")))));
];

! ��������� ������� ����� ��������������/���������, ������������� � 'obj'
! ("������[�|�|�]", "����[�|�|�]")
[ SAEnd obj;

switch (objID (obj)) {
    ocSM:	;
    ocSF:	print (address) '�//';
    ocSN:	print (address) '�//';
    ocPL:	print (address) '�//';
    }

];

! ��������� ��������, ������������� � 'obj':
! (f1 ? 1-�� : 2-��) ���������;
!  f2 ? '��'/'��' : '��'/'��'
[ VEnd obj f1 f2;

  print (address) IIF (obj has pluralname,
    IIF (f1,
	IIF (f2, '��', '��'),
	IIF (f2, '��', '��')),
    IIF (f1, '��', '��'));

];

! ��������� ��������: '-��'/'-��'
[ V1aEnd x; VEnd (x,  true,  false); ];

! ��������� ��������: '-��'/'-��'
[ V1bEnd x; VEnd (x,  true, true); ];

! ��������� ��������: '-��'/'-��'
[ V2aEnd x; VEnd (x, false,  false); ];

! ��������� ��������: '-��'/'-��'
[ V2bEnd x; VEnd (x, false, true); ];

! ��������� �������� � ��������� �������
[ VPEnd noun;
  if (noun has pluralname)	{print "�"; rtrue;}
  else if (noun has neuter)	{print "�"; rtrue;}
  else if (noun has female)	{print "�"; rtrue;}
  else 				{print ""; rtrue;}
];

!
! ���������� ������ �������
! (���������� true ���� ����������)
!
[ ICVowel csID beg end ch0 ch1;

  if ((beg == end && ch0 == 0) ||
      (beg+1 == end && beg->0 == ch0)) {
	if (csID == csNom || csID == csAcc)
		{ if (ch0) print (char) ch0; }
	else	{ if (ch1) print (char) ch1; }
	rtrue;
	}

  rfalse;
  ];

[ AEnd noun;
  if (noun has pluralname)	{print "��"; rtrue;}
  else if (noun has neuter)	{print "��"; rtrue;}
  else if (noun has female)	{print "��"; rtrue;}
  else 				{print "��"; rtrue;}
  ]; 
[ AEnd2 noun;
  if (noun has pluralname)	{print "��"; rtrue;}
  else if (noun has neuter)	{print "��"; rtrue;}
  else if (noun has female)	{print "��"; rtrue;}
  else 				{print "��"; rtrue;}
  ]; 
[ AEnd3 noun;
  if (noun has pluralname)	{print "��"; rtrue;}
  else if (noun has neuter)	{print "��"; rtrue;}
  else if (noun has female)	{print "��"; rtrue;}
  else 				{print "��"; rtrue;}
  ]; 
[ PEnding1 n;
	if (n has pluralname) {print "���"; rtrue;}
	if (n has female) {print "��"; rtrue;}
	print "��"; rtrue;
];
[ PEnding2 n;
	if (n has pluralname) {print "���"; rtrue;}
	if (n has female) {print "��"; rtrue;}
	print "��"; rtrue;
];
[ GenIt n;
	if (n has female) {print "�"; rtrue;}
	if (n has pluralname) {print "��"; rtrue;}
	print "���"; rtrue;
];
[ GenIt2 n;
	print "�";
	if (n has female) {print "�"; rtrue;}
	if (n has pluralname) {print "��"; rtrue;}
	print "���"; rtrue;
];
[ DatIt n;
	if (n has female) {print "��"; rtrue;}
	if (n has pluralname) {print "��"; rtrue;}
	print "���"; rtrue;
]; 
[ DatIt2 n;
	print "�";
	if (n has female) {print "��"; rtrue;}
	if (n has pluralname) {print "��"; rtrue;}
	print "���"; rtrue;
]; 

[ InsIt n;
	if (n has female) {print "��"; rtrue;}
	if (n has pluralname) {print "���"; rtrue;}
	print "��"; rtrue;
]; 
[ InsIt2 n;
	print "�";
	if (n has female) {print "��"; rtrue;}
	if (n has pluralname) {print "���"; rtrue;}
	print "��"; rtrue;
]; 
