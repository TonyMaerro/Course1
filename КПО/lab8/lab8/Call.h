#pragma once

//cdevl ����� : _cdecl
//��������� : ��� �� ��������, ��� ���������(int)
//������� : ����� �������� ���� ����������(int).
// 
//cstd ����� : _stdcall
//��������� : 1 �� ������, 2 �� ��������(int)
//������� : ������������ �������� ���� ����������(int).
// 
//cfst ����� : _fastcall
//��������� : ��� �� ��������, ������ ���������(int)
//������� : ����� �������� ���� ����������(int).

namespace Call {
	int _cdecl cdevl(int, int, int);
	int _stdcall cstd(int, int, int);
	int _fastcall cfst(int, int, int);
};

